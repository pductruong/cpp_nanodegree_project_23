#include "login.h"
#include "./ui_login.h"

LogIn::LogIn(QWidget *parent) : QWidget(parent), ui(new Ui::LogIn) {
  ui->setupUi(this);
  ui->userNameLineEdit->setFocus();
  _driverType = "QSQLITE";
  mainScreen = new MainScreen;
  _adminstrator = new Adminstrator;
  _signIn = new SignIn;
  ui->passwordLineEdit->setEchoMode(QLineEdit::Password);
  connectDatabase();
  defineSignal();
}

void LogIn::defineSignal() {
  connect(ui->signInBtn, &clickableLabel::clicked, [=]() {
    _signIn->setDatabase(std::make_unique<QSqlDatabase>(*_db));
    _signIn->show();
    this->close();
  });

  connect(_signIn, &SignIn::backToLogIn, [=]() {
    cleanLineEdit();
    _signIn->hide();
    this->show();
  });

  connect(mainScreen, &MainScreen::backToLogIn, [=]() {
    QTimer::singleShot(500, this, [=]() {
      mainScreen->hide();
      this->show();
    });
  });
  connect(_adminstrator, &Adminstrator::backToLogIn, [=]() {
    _adminstrator->hide();
    this->show();
  });
}

void LogIn::on_logInBtn_clicked() {
  checkUserData();
  cleanLineEdit();
}

void LogIn::cleanLineEdit() {
  ui->userNameLineEdit->clear();
  ui->passwordLineEdit->clear();
}

void LogIn::connectDatabase() {
  _db = std::make_unique<QSqlDatabase>();
  QString driverType;
  if (QSqlDatabase::contains("qt_sql_default_connection")) {
    driverType = "qt_sql_default_connection";
  } else {
    driverType = "QSQLITE";
  }
  *_db = QSqlDatabase::addDatabase(driverType);
  _db->setHostName("localhost");
  _db->setUserName("Root");
  _db->setPassword("");
  // TODO: Add path to directory of database
  // _db->setDatabaseName("../testDB.db");
  _db->setDatabaseName("./database.db");
  if (_db->open()) {
    // qDebug() << "Open Success";
  }
}

void LogIn::checkUserData() {
  QString userName = ui->userNameLineEdit->text();
  QString passWord = ui->passwordLineEdit->text();
  // qDebug() << "From Text" << userName << passWord;
  _query = new QSqlQuery(*_db);
  QString retrieveDataQuery =
      "Select * from AccountInformation Where UserName = :userName "
      "And Password = :password";
  _query->prepare(retrieveDataQuery);
  _query->bindValue(":userName", userName);
  _query->bindValue(":password", passWord);

  if (!_query->exec()) {
    qDebug() << _query->lastError();
    QMessageBox::information(this, "Error", "Fail to execute database");
  } else {
    if (_query->next()) {
      QString userNameFromDB = _query->value(4).toString();
      QString passWordFromDB = _query->value(5).toString();

      // qDebug() << "From DB" << userNameFromDB << passWordFromDB;
      if (userNameFromDB == "admin" && passWordFromDB == "admin") {
        _adminstrator->setDatabase(std::make_unique<QSqlDatabase>(*_db));
        _adminstrator->displayAccountData();
        _adminstrator->displayBookData();
        _adminstrator->show();
        this->hide();
      } else if (userNameFromDB == userName && passWordFromDB == passWord) {
        showMainScreen();
      }
    } else {
      QMessageBox::information(
          this, "Login Failed",
          "Login failed. Please enter correct user name or password");
    }
  }
}

void LogIn::showMainScreen() {
  QString userName = ui->userNameLineEdit->text();
  QTimer::singleShot(500, this, [=]() {
    QMessageBox::information(this, "Login", "Login is successfully");
  });
  QTimer::singleShot(500, this, [=]() {
    this->hide();
    mainScreen->setDatabase(std::make_unique<QSqlDatabase>(*_db));
    mainScreen->init(userName);
    mainScreen->show();
  });
}

LogIn::~LogIn() { delete ui; }
