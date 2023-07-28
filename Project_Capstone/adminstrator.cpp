#include "adminstrator.h"
#include "ui_adminstrator.h"

std::vector<QString> contextMenuOption{"Delete account", "Change information"};

Adminstrator::Adminstrator(QWidget *parent)
    : QWidget{parent}, ui(new Ui::Adminstrator) {
  ui->setupUi(this);
  _model = new QSqlQueryModel;
  _customModel = new CustomQueryModel;
  _addBook = new AddBook;
  setupTable();
  connect(ui->searchAccountBox, SIGNAL(textChanged(QString)), this,
          SLOT(searchAccount()));
  connect(ui->searchBookBox, SIGNAL(textChanged(QString)), this,
          SLOT(searchBook()));
  connect(_addBook, &AddBook::buttonPressed, this,
          &Adminstrator::handleAddBookButtonPress);
  _contextMenu = new QMenu(this);
}

void Adminstrator::setDatabase(std::unique_ptr<QSqlDatabase> db) {
  _db = std::move(db);
  _query = new QSqlQuery(*_db);
}

void Adminstrator::setupTable() {
  _tableModel = new QSqlTableModel;
  _tableModel->setTable("user");
  _tableModel->select();
  ui->usersTableView->horizontalHeader()->setSectionResizeMode(
      QHeaderView::Stretch);
  ui->usersTableView->setModel(_tableModel);
  ui->usersTableView->setContextMenuPolicy(Qt::CustomContextMenu);
  connect(ui->usersTableView, &QTableView::customContextMenuRequested, this,
          &Adminstrator::showContextMenu);
  ui->bookTableView->horizontalHeader()->setSectionResizeMode(
      QHeaderView::Stretch);
  ui->bookTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
}

void Adminstrator::displayAccountData() {
  QString queryString =
      "SELECT FirstName, LastName, Email, UserName, Password, Address, "
      "PhoneNumber FROM AccountInformation";
  if (_query->exec(queryString)) {
    _model->setQuery(*_query);
    ui->usersTableView->setModel(_model);
  } else {
    QMessageBox::information(this, "Error",
                             "Could not execute database for display");
  }
  createContextMenu();
}

void Adminstrator::displayBookData() {
  if (!_db->isOpen()) {
    QMessageBox::critical(this, "Error", "Database connection is not open.");
    return;
  }
  QString queryStr =
      "SELECT Title, Author, PublicationDate, Genre, ISBN, Price, Description, "
      "AccountID, IsRented FROM BookList";
  if (_query->exec(queryStr)) {
    _customModel->setQuery(*_query);
    ui->bookTableView->setModel(_customModel);
  } else {
    QMessageBox::information(this, "Error",
                             "Could not execute database for display");
  }
}

void Adminstrator::searchBook() {
  //   qDebug() << "Searching" << _db->open();
  QString search, data;
  search = ui->searchBookBox->text();
  //   qDebug() << search;
  if (search.isEmpty()) {
    // qDebug() << "Debug 1";
    // data = "SELECT UserName FROM AccountInformation";
    displayBookData();
    return;
  } else {
    // qDebug() << "Debug 2";
    data = "SELECT * FROM BookList WHERE Title LIKE '%" + search +
           "%'";
  }
  if (_query->exec(data)) {
    _model->setQuery(*_query);
    ui->usersTableView->setModel(_model);
  } else {
    QMessageBox::information(this, "Error",
                             "Could not execute database for search");
  }
}

void Adminstrator::searchAccount() {
  //   qDebug() << "Searching" << _db->open();
  QString search, data;
  search = ui->searchAccountBox->text();
  //   qDebug() << search;
  if (search.isEmpty()) {
    // qDebug() << "Debug 1";
    // data = "SELECT UserName FROM AccountInformation";
    displayAccountData();
    return;
  } else {
    // qDebug() << "Debug 2";
    data = "SELECT * FROM AccountInformation WHERE UserName LIKE '%" + search +
           "%'";
  }
  if (_query->exec(data)) {
    _model->setQuery(*_query);
    ui->usersTableView->setModel(_model);
  } else {
    QMessageBox::information(this, "Error",
                             "Could not execute database for search");
  }
}
Adminstrator::~Adminstrator() { delete ui; }

void Adminstrator::on_backToLoginBtn_clicked() { emit this->backToLogIn(); }

void Adminstrator::createContextMenu() {
  _contextMenu->clear();
  for (const QString &option : contextMenuOption) {
    QAction *action = new QAction(option, this);
    connect(action, &QAction::triggered, [option, this]() {
      // Get the selected cell index
      QModelIndexList selectedIndexes =
          ui->usersTableView->selectionModel()->selectedIndexes();

      // Check if only one cell is selected (to avoid ambiguity in printing)
      if (selectedIndexes.size() == 1) {
        QModelIndex selectedIndex = selectedIndexes.at(0);
        int row = selectedIndex.row();
        int column = selectedIndex.column();
        // qDebug() << "Selected cell index: row =" << row
        //          << ", column =" << column;

        // Handle the context menu option here
        if (option == contextMenuOption[0]) {
          // Implement code to delete the selected account
          deleteAcc(row, column);
        } else if (option == contextMenuOption[1]) {
          // Implement code to change user information
          changeInfoAcc(row, column);
        }
        // Add more cases for other options if needed
      } else {
        qDebug() << "Multiple cells selected or no cell selected!";
      }
    });
    _contextMenu->addAction(action);
  }
}

void Adminstrator::showContextMenu(const QPoint &pos) {
  // Get the index of the cell at the clicked position
  QModelIndex index = ui->usersTableView->indexAt(pos);

  // Show the context menu only if the clicked position is within a valid cell
  if (index.isValid()) {
    _contextMenu->exec(ui->usersTableView->mapToGlobal(pos));
  }
}

void Adminstrator::deleteAcc(int row, int column) {
  qDebug() << "Delete account completed";
  std::vector<QVariant> cellDatas;
  // Check if the row is valid before proceeding
  if (row < 0 || row >= _model->rowCount()) {
    qDebug() << "Invalid row number";
  }

  // Make sure the index is valid
  QModelIndex index = _model->index(row, 0);
  if (!index.isValid()) {
    qDebug() << "Invalid index";
  }
  // Retrieve cell data for each column in the row
  for (int i = 0; i < _model->columnCount(); i++) {
    QVariant cellData = _model->data(_model->index(row, i));
    cellDatas.push_back(cellData);
    // qDebug() << cellData.toString();
  }

  QString userName = cellDatas[0].toString();
  QString password = cellDatas[1].toString();
  QString email = cellDatas[2].toString();
  // QString phoneNumber = cellDatas[3].toString();
  QString queryString =
      "DELETE FROM AccountInformation WHERE UserName LIKE '%" + userName + "%'";

  if (!_query->exec(queryString)) {
    qDebug() << "Error executing query:" << _query->lastError().text();
  }
  qDebug() << "Deleted successful";
  displayAccountData();
}

void Adminstrator::changeInfoAcc(int row, int column) {
  QString placeHolder = (column == 0)   ? "FirstName"
                        : (column == 1) ? "LastName"
                        : (column == 2) ? "Email"
                        : (column == 3) ? "UserName"
                        : (column == 4) ? "Password"
                        : (column == 5) ? "Address"
                        : (column == 6) ? "PhoneNumber"
                                        : "";
  QDialog dialog;
  dialog.setWindowTitle("Change Information " + placeHolder);

  // Create widgets for the dialog
  QLabel *label = new QLabel("Enter new information:");
  QLineEdit *lineEdit = new QLineEdit;
  QPushButton *okButton = new QPushButton("OK");
  QPushButton *cancelButton = new QPushButton("Cancel");

  // Set up layout for the dialog
  QVBoxLayout *mainLayout = new QVBoxLayout;
  QHBoxLayout *buttonLayout = new QHBoxLayout;
  buttonLayout->addWidget(okButton);
  buttonLayout->addWidget(cancelButton);
  mainLayout->addWidget(label);
  mainLayout->addWidget(lineEdit);
  mainLayout->addLayout(buttonLayout);

  // Connect slots for the buttons
  connect(okButton, &QPushButton::clicked, &dialog, &QDialog::accept);
  connect(cancelButton, &QPushButton::clicked, &dialog, &QDialog::reject);

  // Set the main layout for the dialog
  dialog.setLayout(mainLayout);

  // Execute the dialog and get the result
  int result = dialog.exec();
  QVariant cellData_oldData = _model->data(_model->index(row, column));
  QString oldData = cellData_oldData.toString();
  QVariant cellData_userName = _model->data(_model->index(row, 4));
  QString userName = cellData_userName.toString();
  // Check which button was clicked
  if (result == QDialog::Accepted) {
    // "OK" button was clicked
    QString newData = lineEdit->text();
    qDebug() << "Entered text:" << newData;
    QString queryString;
    if (column == 0) {
      queryString = "UPDATE AccountInformation SET FirstName = :newFirstName "
                    "WHERE UserName = "
                    ":userName";
    } else if (column == 1) {
      queryString = "UPDATE AccountInformation SET LastName = :newLastName "
                    "WHERE UserName = "
                    ":userName";
    } else if (column == 2) {
      queryString =
          "UPDATE AccountInformation SET Email = :newEmail WHERE UserName = "
          ":userName";
    } else if (column == 3) {
      queryString = "UPDATE AccountInformation SET UserName = :newUserName "
                    "WHERE UserName = "
                    ":userName";
    } else if (column == 4) {
      queryString = "UPDATE AccountInformation SET Password = :newPassword "
                    "WHERE UserName = "
                    ":userName";
    } else if (column == 5) {
      queryString = "UPDATE AccountInformation SET Address = :newAddress WHERE "
                    "UserName = "
                    ":userName";
    } else if (column == 6) {
      queryString = "UPDATE AccountInformation SET PhoneNumber = "
                    ":newPhoneNumber WHERE UserName = "
                    ":userName";
    }
    _query->prepare(queryString);

    _query->bindValue(":userName",
                      userName); // Bind old value
    _query->bindValue(":new" + placeHolder,
                      newData); // Bind new value
    if (!_query->exec()) {
      qDebug() << "Error executing the query: " << _query->lastError().text();
    } else {
      qDebug() << "Update successful!";
      displayAccountData();
    }
  } else if (result == QDialog::Rejected) {
    // "Cancel" button was clicked
    qDebug() << "Canceled";
  }
}

void Adminstrator::on_accountManagementBtn_clicked() {
  ui->stackedWidget->setCurrentIndex(0);
}

void Adminstrator::on_bookManagementBtn_clicked() {
  ui->stackedWidget->setCurrentIndex(1);
}

void Adminstrator::on_addBookBtn_clicked() { _addBook->show(); }

void Adminstrator::on_deleteBookBtn_clicked() {
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
    QString queryStr = "DELETE FROM BookList WHERE Title = :title";;
    _query->prepare(queryStr);
    _query->bindValue(":title", data.toString());
    if (!_query->exec()) {
      qDebug() << "Can not return the book: " << _query->lastError().text();
    } else {
      displayBookData();
    }
  }

}

void Adminstrator::handleAddBookButtonPress(int button) {
  if (button == 1) {
    qDebug() << "Add book";
    _book = _addBook->getAddedBook();
    addBookToLibrary();
    // Perform actions for "Add book" button press
  } else {
    qDebug() << "Cancel button pressed";
    // Perform actions for "Cancel" button press or return;
  }
}

void Adminstrator::addBookToLibrary() {
  if (!_db->open()) {
    qDebug() << "Error: Failed to connect to the database.";
    return;
  }
  QString queryString = "INSERT INTO BookList (Title, Author, PublicationDate, "
                        "Genre, ISBN, Price, Description) "
                        "VALUES (:title, :author, :publicationDate, :genre, "
                        ":isbn, :price, :description)";
  _query->prepare(queryString);
  _query->bindValue(":title", _book->getTitle());
  _query->bindValue(":author", _book->getAuthor());
  _query->bindValue(":publicationDate", _book->getPublicationDate());
  _query->bindValue(":genre", _book->getGenre());
  _query->bindValue(":isbn", _book->getISBN());
  _query->bindValue(":price", _book->getPrice());
  _query->bindValue(":description", _book->getDescription());

  // Execute the query
  if (_query->exec()) {
    // Book added successfully to the database
    qDebug() << "Add book successful";
    displayBookData();
  } else {
    qDebug() << "Error executing the query:" << _query->lastError().text();
    qDebug() << "Erro Add book";
  }
}