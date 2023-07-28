#ifndef LOGIN_H
#define LOGIN_H

#include <QMessageBox>
#include <QPainter>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QString>
#include <QWidget>
#include <QTimer>
#include <QDebug>
#include <QSqlError>

#include "mainscreen.h"
#include "adminstrator.h"
#include "signin.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class LogIn;
}
QT_END_NAMESPACE

class LogIn : public QWidget {
  Q_OBJECT

public:
  LogIn(QWidget *parent = nullptr);
  ~LogIn();

  // Clear user and password line edit after sign in
  void cleanLineEdit();
  // Connect database
  void connectDatabase();
  // Check entered user data in database or not
  void checkUserData();
  // Define signal method
  void defineSignal();
  // Show main screen
  void showMainScreen();

  MainScreen* mainScreen;

private slots:
  void on_logInBtn_clicked();

private:
  Ui::LogIn *ui;
  bool _loadedDB;
  QSqlQuery* _query;
  QString _driverType;
  std::unique_ptr<QSqlDatabase> _db;
  Adminstrator* _adminstrator;
  SignIn* _signIn;

};
#endif // LOGIN_H
