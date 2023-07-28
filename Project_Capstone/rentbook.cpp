#include "rentbook.h"
#include "ui_rentbook.h"

RentBook::RentBook(QWidget *parent) : QWidget(parent), ui(new Ui::RentBook) {
  ui->setupUi(this);
  ui->availableBookTable->horizontalHeader()->setSectionResizeMode(
      QHeaderView::Stretch);
  ui->availableBookTable->setSelectionBehavior(QAbstractItemView::SelectRows);
}

RentBook::~RentBook() { delete ui; }

void RentBook::setDatabase(std::unique_ptr<QSqlDatabase> db) {
  _db = std::move(db);
  _query = new QSqlQuery(*_db);
}

void RentBook::displayAvailableBook() {
  if (!_db->isOpen()) {
    QMessageBox::critical(this, "Error", "Database connection is not open.");
    return;
  }
  _customModel = new CustomQueryModel;
  QString queryStr = "SELECT Title, Author, PublicationDate, Genre, ISBN, "
                     "Price, Description FROM BookList WHERE "
                     " isRented = FALSE";
  if (_query->exec(queryStr)) {
    _customModel->setQuery(*_query);
    ui->availableBookTable->setModel(_customModel);
  } else {
    QMessageBox::information(this, "Error",
                             "Could not execute database for display");
  }
}

void RentBook::getCurrentUser(std::unique_ptr<AccountInformation> account) {
  _account = std::move(account);
}

void RentBook::on_rentBtn_clicked() {
  QItemSelectionModel *selectionModel =
      ui->availableBookTable->selectionModel();

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
        "UPDATE BookList SET IsRented = TRUE, AccountID = :accountID "
        "WHERE Title = :title ";
    // qDebug() << _account->getAccountID();
    _query->prepare(queryStr);
    _query->bindValue(":accountID", _account->getAccountID());
    _query->bindValue(":title", data.toString());
    if (!_query->exec()) {
      qDebug() << "Can not rent the book: " << _query->lastError().text();
    } else {
      displayAvailableBook();
    }
  }
}

void RentBook::on_cancelBtn_clicked() { this->close(); }
