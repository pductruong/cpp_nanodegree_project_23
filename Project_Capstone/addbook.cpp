#include "addbook.h"
#include "ui_addbook.h"

AddBook::AddBook(QWidget *parent) : QWidget(parent), ui(new Ui::AddBook) {
  ui->setupUi(this);
}

AddBook::~AddBook() { delete ui; }

void AddBook::on_cancelAddBook_clicked() {
  clearLineEdit();
  emit buttonPressed(0); // 0 for Cancel
  hide();
}

void AddBook::on_confirmAddBook_clicked() {
  createBookObj();
  clearLineEdit();
  emit buttonPressed(1); // 1 for Add
  hide();
}

void AddBook::createBookObj() {
  QString title = ui->titleLineEdit->text();
  QString author = ui->authorLineEdit->text();
  QString publicDate = ui->publicDateLineEdit->text();
  QString genre = ui->genreLineEdit->text();
  QString isbn = ui->isbnLineEdit->text();
  double price = ui->priceLineEdit->text().toDouble();
  QString description = ui->descriptionLineEdit->text();
  _book = std::make_unique<Book>();
  _book->setTitle(title);
  _book->setAuthor(author);
  _book->setPublicationDate(publicDate);
  _book->setGenre(genre);
  _book->setISBN(isbn);
  _book->setPrice(price);
  _book->setDescription(description);

}

std::unique_ptr<Book> AddBook::getAddedBook() {
    return std::move(_book);
}

void AddBook::clearLineEdit() {
  ui->titleLineEdit->clear();
  ui->authorLineEdit->clear();
  ui->publicDateLineEdit->clear();
  ui->genreLineEdit->clear();
  ui->isbnLineEdit->clear();
  ui->priceLineEdit->clear();
  ui->descriptionLineEdit->clear();

}