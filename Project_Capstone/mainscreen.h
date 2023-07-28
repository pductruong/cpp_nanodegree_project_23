#ifndef MAINSCREEN_H
#define MAINSCREEN_H

#include <QMessageBox>
#include <QObject>
#include <QSqlTableModel>
#include <QString>
#include <QWidget>

#include "account.h"
#include "clickableLabel.h"
#include "customquerytable.h"
#include "rentbook.h"

namespace Ui {
class MainScreen;
}
class MainScreen : public QWidget {
  Q_OBJECT
public:
  explicit MainScreen(QWidget *parent = nullptr);
  ~MainScreen();
  void init(const QString &name);

  void setUserTitle(const QString &name);
  void setDatabase(std::unique_ptr<QSqlDatabase> db);
  void getAccountID();
  void displayBookData();

  void createAccountObj();

signals:
  void backToLogIn();

private slots:
    void on_addBookBtn_clicked();
    void on_returnBookBtn_clicked();
    void on_closeRentBook();


private:
  Ui::MainScreen *ui;
  RentBook *_rentbook;
  std::unique_ptr<QSqlDatabase> _db;
  QSqlQueryModel *_model;
  QSqlQuery *_query;
  CustomQueryModel *_customModel;
  // void displayRentedBook();
  std::unique_ptr<AccountInformation> _account;

};

#endif // MAINSCREEN_H
