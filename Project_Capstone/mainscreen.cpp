#include "mainscreen.h"
#include "ui_mainscreen.h"

MainScreen::MainScreen(QWidget *parent)
    : QWidget{parent}, ui(new Ui::MainScreen) {
  ui->setupUi(this);
  _account = std::make_unique<AccountInformation>();
  _rentbook = new RentBook;
  _customModel = new CustomQueryModel;
  connect(ui->goBack, &clickableLabel::clicked, [=]() {
    emit this->backToLogIn();
    // emit reminds it is signal
  });
  connect(_rentbook, &RentBook::widgetClosed, this, &MainScreen::on_closeRentBook);
  ui->userNameTitle->setReadOnly(true);
  ui->bookTableView->horizontalHeader()->setSectionResizeMode(
      QHeaderView::Stretch);
  ui->bookTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
}

void MainScreen::setUserTitle(const QString &name) {
  ui->userNameTitle->setText(name);
}

void MainScreen::setDatabase(std::unique_ptr<QSqlDatabase> db) {
  _db = std::move(db);
  _query = new QSqlQuery(*_db);
}

void MainScreen::displayBookData() {
  if (!_db->isOpen()) {
    QMessageBox::critical(this, "Error", "Database connection is not open.");
    return;
  }
  QString queryStr = "SELECT Title, Author, PublicationDate, Genre, ISBN, "
                     "Price, Description FROM BookList WHERE "
                     "AccountID = :accountID AND isRented = TRUE";
  _query->prepare(queryStr);
  // qDebug() << "ID: " << _account->getAccountID();
  _query->bindValue(":accountID", _account->getAccountID());
  if (_query->exec()) {
    _customModel->setQuery(*_query);
    ui->bookTableView->setModel(_customModel);
  } else {
    QMessageBox::information(this, "Error",
                             "Could not execute database for display");
  }
}

void MainScreen::createAccountObj() {
  QString retrieveDataQuery =
      "SELECT * FROM AccountInformation WHERE Username = :userName";
  _query->prepare(retrieveDataQuery);
  _query->bindValue(":userName", ui->userNameTitle->text());
  if (!_query->exec()) {
    qDebug() << "Get data for account failed";
  } else {
    if (_query->next()) {
      int accountID = _query->value(0).toInt();
      QString firstName = _query->value(1).toString();
      QString lastName = _query->value(2).toString();
      QString email = _query->value(3).toString();
      QString userName = _query->value(4).toString();
      QString password = _query->value(5).toString();
      QString address = _query->value(6).toString();
      QString phoneNumber = _query->value(7).toString();
      _account->setAccountID(accountID);
      _account->setFirstName(firstName);
      _account->setLastName(lastName);
      _account->setEmail(email);
      _account->setUserName(userName);
      _account->setPassword(password);
      _account->setAddress(address);
      _account->setPhoneNumber(phoneNumber);
    }
  }
}

void MainScreen::init(const QString &name) {
  setUserTitle(name);
  createAccountObj();
  displayBookData();
}

MainScreen::~MainScreen() { delete ui; }

void MainScreen::on_addBookBtn_clicked() {
  _rentbook->setDatabase(std::make_unique<QSqlDatabase>(*_db));
  _rentbook->displayAvailableBook();
  _rentbook->getCurrentUser(std::make_unique<AccountInformation>(*_account));
  _rentbook->show();
}

void MainScreen::on_returnBookBtn_clicked()
{
  QItemSelectionModel *selectionModel =
      ui->bookTableView->selectionModel();

  // Get the selected indexes (rows)
  QModelIndexList selectedRows = selectionModel->selectedRows();

  // Check if any row is selected
  if (!selectedRows.isEmpty()) {
    // Get the first selected row
    QModelIndex selectedIndex = selectedRows.first();
    int selectedRow = selectedIndex.row();

    // Retrieve the data of the first column for the selected row
    QVariant data = selectedIndex.sibling(selectedRow, 0).data();

    // Print the data of the first column
    qDebug() << "Data of the first column in selected row:" << data.toString();
    QString queryStr =
        "UPDATE BookList SET IsRented = FALSE, AccountID = NULL "
        "WHERE Title = :title AND AccountID = :accountID";
    _query->prepare(queryStr);
    _query->bindValue(":title", data.toString());
    _query->bindValue(":accountID", _account->getAccountID());
    if (!_query->exec()) {
      qDebug() << "Can not return the book: " << _query->lastError().text();
    } else {
      displayBookData();
    }
  }
}

void MainScreen::on_closeRentBook() { displayBookData(); }
