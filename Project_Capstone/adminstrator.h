#ifndef ADMINSTRATOR_H
#define ADMINSTRATOR_H

#include <QContextMenuEvent>
#include <QDebug>
#include <QMenu>
#include <QMessageBox>
#include <QPainter>
#include <QSqlTableModel>
#include <QWidget>
#include <QtSql>
#include <vector>

#include "customquerytable.h"
#include "addbook.h"

extern std::vector<QString> contextMenuOption;

QT_BEGIN_NAMESPACE
namespace Ui {
class Adminstrator;
}
QT_END_NAMESPACE

class Adminstrator : public QWidget {
  Q_OBJECT
public:
  Adminstrator(QWidget *parent = nullptr);
  ~Adminstrator();

  void setDatabase(std::unique_ptr<QSqlDatabase> db);

  // void paintEvent(QPaintEvent *);
  void setupTable();
  void displayAccountData();
  void displayBookData();
  void createContextMenu();
private slots:
  void searchAccount();
  void searchBook();
  void on_backToLoginBtn_clicked();
  void on_accountManagementBtn_clicked();

  void on_bookManagementBtn_clicked();

  void on_addBookBtn_clicked();

  void on_deleteBookBtn_clicked();
  void handleAddBookButtonPress(int button);
  signals:
  void backToLogIn();

private:
  Ui::Adminstrator *ui;
  AddBook *_addBook;
  QSqlTableModel *_tableModel;
  std::unique_ptr<QSqlDatabase> _db;
  QSqlQueryModel *_model;
  CustomQueryModel *_customModel;
  QSqlQuery *_query;
  QMenu *_contextMenu;
  std::unique_ptr<Book> _book;

  void deleteAcc(int row, int column);
  void changeInfoAcc(int row, int column);
  void addBookToLibrary();
protected:
  // Override the context menu event handler
  void showContextMenu(const QPoint &pos);
};

#endif // ADMINSTRATOR_H
