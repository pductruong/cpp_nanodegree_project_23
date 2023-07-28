#include "signin.h"
#include "ui_signin.h"

SignIn::SignIn(QWidget *parent) : QWidget(parent), ui(new Ui::SignIn) {
  ui->setupUi(this);
  connect(ui->backToLogInBtn, &clickableLabel::clicked, [=]() {
    cleanLineEdit();
    emit this->backToLogIn();
  });
}

void SignIn::setDatabase(std::unique_ptr<QSqlDatabase> db) {
  _db = std::move(db);
  _query = std::make_unique<QSqlQuery>(*_db);
}

void SignIn::on_signUpBtn_clicked() {
  std::vector<QString> accountFeild;
  QString firstName = ui->firstNameLineEdit->text();
  accountFeild.push_back(firstName);
  QString lastName = ui->lastNameLineEdit->text();
  accountFeild.push_back(lastName);
  QString email = ui->eMailLineEdit->text();
  accountFeild.push_back(email);
  QString userName = ui->userNameLineEdit->text();
  accountFeild.push_back(userName);
  QString password = ui->passwordLineEdit->text();
  accountFeild.push_back(password);
  QString address = ui->addressLineEdit->text();
  accountFeild.push_back(address);
  QString phoneNumber = ui->phoneNumberLineEdit->text();
  accountFeild.push_back(phoneNumber);
  if (checkAccountFeild(firstName, lastName, email, userName, password, address,
                        phoneNumber)) {
    insertUserData(firstName, lastName, email, userName, password, address,
                   phoneNumber);
  }
}

bool SignIn::checkAccountFeild(const QString &firstName,
                               const QString &lastName, const QString &email,
                               const QString &userName, const QString &password,
                               const QString &address,
                               const QString &phoneNumber) {
  if (firstName.isEmpty() || !isValidName(firstName)) {
    messageBox("First name");
    this->activateWindow();
    ui->firstNameLineEdit->setFocus();
    return false;
  }
  if (lastName.isEmpty() || !isValidName(lastName)) {
    messageBox("Last name");
    this->activateWindow();
    ui->lastNameLineEdit->setFocus();
    return false;
  }
  if (userName.isEmpty() || !isValidUserName(userName)) {
    messageBox("User name");
    this->activateWindow();
    ui->userNameLineEdit->setFocus();
    return false;
  }
  if (email.isEmpty() || !isValidEmail(email)) {
    messageBox("Email");
    this->activateWindow();
    ui->eMailLineEdit->setFocus();
    return false;
  }
  if (password.isEmpty() || !isValidPassword(password)) {
    messageBox("Password");
    this->activateWindow();
    ui->passwordLineEdit->setFocus();
    return false;
  }
  if (address.isEmpty() || !isValidAddress(address)) {
    messageBox("Address");
    this->activateWindow();
    ui->addressLineEdit->setFocus();
    return false;
  }
  return true;
  if (phoneNumber.isEmpty() || !isValidPhoneNumber(phoneNumber)) {
    messageBox("Phone number");
    this->activateWindow();
    ui->phoneNumberLineEdit->setFocus();
    return false;
  }
  return true;
}

bool SignIn::isValidName(const QString &name) {
  // Regular expression pattern to match full name with alphabet characters
  QRegularExpression regex("^[A-Za-z\\s]+$");

  // Perform the regular expression matching on the input string
  QRegularExpressionMatch match = regex.match(name);

  // If there is a match, it means the input contains only alphabet characters
  // and spaces
  return match.hasMatch();
}

bool SignIn::isValidEmail(const QString &email) {
  // Regular expression pattern for a valid email address
  QRegularExpression regex(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})");

  // Match the email against the regular expression pattern
  QRegularExpressionMatch match = regex.match(email);

  // Return true if the email is valid (fully matched), otherwise false
  return match.hasMatch();
}

bool SignIn::isValidUserName(const QString &userName) {
  // Define the allowed characters for the username (letters, digits,
  // underscores)
  QRegularExpression allowedChars("^[a-zA-Z0-9_]+$");

  // Check if the username length is within the specified range (e.g., 3 to 20
  // characters)
  if (userName.length() < 3 || userName.length() > 20) {
    return false;
  }

  // Check if the username contains only allowed characters
  QRegularExpressionMatch match = allowedChars.match(userName);
  if (!match.hasMatch()) {
    return false;
  }

  return true;
}

bool SignIn::isValidPassword(const QString &password) {
  // Check the length of the password
  if (password.length() < 8) {
    return false;
  }

  // Check if the password contains at least one uppercase letter, one lowercase
  // letter, and one digit
  bool hasUppercase = false;
  bool hasLowercase = false;
  bool hasDigit = false;

  for (const QChar &ch : password) {
    if (ch.isUpper()) {
      hasUppercase = true;
    } else if (ch.isLower()) {
      hasLowercase = true;
    } else if (ch.isDigit()) {
      hasDigit = true;
    }

    // If all required criteria are met, break the loop early
    if (hasUppercase && hasLowercase && hasDigit) {
      break;
    }
  }

  // Return true if all criteria are met, otherwise false
  return (hasUppercase && hasLowercase && hasDigit);
}

bool SignIn::isValidAddress(const QString &address) {
  // Define the minimum and maximum length of a valid address
  const int minLength = 5;
  const int maxLength = 100;

  // Check if the address length is within the specified range
  if (address.length() < minLength || address.length() > maxLength) {
    return false;
  }
  return true;
}

bool SignIn::isValidPhoneNumber(const QString &phoneNumber) {
  // Regular expression pattern for a valid phone number
  QRegularExpression regex(R"(\d{3}-\d{3}-\d{4})");

  // Match the phone number against the regular expression pattern
  QRegularExpressionMatch match = regex.match(phoneNumber);

  // Return true if the phone number is valid (fully matched), otherwise false
  return match.hasMatch();
}

void SignIn::messageBox(const QString text) {
  QString infoText;
  if (text == "full name") {
    infoText = "Full name must only contain alphabet characters and space";
  }

  QMessageBox msgBox;
  msgBox.setWindowTitle("Account information invalid");
  msgBox.setText("Invalid " + text);
  msgBox.setInformativeText(infoText);
  msgBox.setStandardButtons(QMessageBox::Ok);
  msgBox.setDefaultButton(QMessageBox::Ok);
  int ret = msgBox.exec();
}

void SignIn::insertUserData(const QString &firstName, const QString &lastName,
                            const QString &email, const QString &userName,
                            const QString &password, const QString &address,
                            const QString &phoneNumber) {
  // Check if the data already exists in the database
  QString checkQueryStr =
      "SELECT * FROM AccountInformation WHERE UserName = :userName OR "
      "Email = :email OR PhoneNumber = :phoneNumber";
  _query->prepare(checkQueryStr);
  _query->bindValue(":email", email);
  _query->bindValue(":userName", userName);
  _query->bindValue(":phoneNumber", phoneNumber);

  if (_query->exec()) {
    if (_query->next()) {
      // Data already exists in the database, show an error message.
      QString message =
          "The following data already exists in the database:\n\n";
      if (_query->value("UserName").toString() == userName) {
        message += "Username: " + userName + "\n";
      }
      if (_query->value("Email").toString() == email) {
        message += "Email: " + email + "\n";
      }
      if (_query->value("PhoneNumber").toString() == phoneNumber) {
        message += "Phone Number: " + phoneNumber + "\n";
      }

      QMessageBox::information(this, "Error", message);
    } else {
      // Data does not exist, insert the new record into the database
      QString insertQueryStr =
          "INSERT INTO AccountInformation (FirstName, LastName, "
          "Email, UserName, Password, Address, PhoneNumber) "
          "VALUES (:firstName, :lastName, :email, :userName, "
          ":hashedPassword, :address, :phoneNumber)";
      QSqlQuery insertQuery(*_db);
      insertQuery.prepare(insertQueryStr);
      insertQuery.bindValue(":firstName", firstName);
      insertQuery.bindValue(":lastName", lastName);
      insertQuery.bindValue(":email", email);
      insertQuery.bindValue(":userName", userName);
      insertQuery.bindValue(":hashedPassword", password);
      insertQuery.bindValue(":address", address);
      insertQuery.bindValue(":phoneNumber", phoneNumber);

      if (insertQuery.exec()) {
        // Insertion successful, show a success message or handle it
        // accordingly.
        QMessageBox::information(this, "Success",
                                 "User data inserted successfully.");
      } else {
        // Insertion failed, show an error message or handle it accordingly.
        QMessageBox::information(
            this, "Error", "Failed to insert user data into the database.");
      }
    }
  } else {
    // Failed to execute the check query, show an error message or handle it
    // accordingly.
    QMessageBox::information(this, "Error",
                             "Failed to execute the check query.");
  }
}

void SignIn::cleanLineEdit() {
  ui->firstNameLineEdit->clear();
  ui->lastNameLineEdit->clear();
  ui->eMailLineEdit->clear();
  ui->userNameLineEdit->clear();
  ui->passwordLineEdit->clear();
  ui->addressLineEdit->clear();
  ui->phoneNumberLineEdit->clear();
}
SignIn::~SignIn() { delete ui; }
