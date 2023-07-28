#ifndef ADDBOOK_H
#define ADDBOOK_H

#include "book.h"
#include <QString>
#include <QWidget>
#include <memory>

namespace Ui {
class AddBook;
}

class AddBook : public QWidget {
  Q_OBJECT

public:
  explicit AddBook(QWidget *parent = nullptr);
  ~AddBook();
  void createBookObj();
  void clearLineEdit();
  std::unique_ptr<Book> getAddedBook();

private slots:
  void on_confirmAddBook_clicked();

  void on_cancelAddBook_clicked();
signals:
  void buttonPressed(int button);

private:
  Ui::AddBook *ui;

  std::unique_ptr<Book> _book;
};

#endif // ADDBOOK_H
