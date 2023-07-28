#ifndef SIGNIN_H
#define SIGNIN_H

#include <QContextMenuEvent>
#include <QDebug>
#include <QMenu>
#include <QMessageBox>
#include <QPainter>
#include <QSqlTableModel>
#include <QWidget>
#include <QtSql>
#include <memory>
#include <vector>

QT_BEGIN_NAMESPACE
namespace Ui {
class SignIn;
}
QT_END_NAMESPACE

class SignIn : public QWidget {
  Q_OBJECT

public:
  explicit SignIn(QWidget *parent = nullptr);
  ~SignIn();

  void setDatabase(std::unique_ptr<QSqlDatabase> db);
  void cleanLineEdit();

signals:
  void backToLogIn();
private slots:
  void on_signUpBtn_clicked();

private:
  Ui::SignIn *ui;
  std::unique_ptr<QSqlDatabase> _db;
  std::unique_ptr<QSqlQuery> _query;

  bool checkAccountFeild(const QString &firstName, const QString &lastName,
                         const QString &email, const QString &userName,
                         const QString &password, const QString &address,
                         const QString &phoneNumber);
  void messageBox(const QString text);

  /**
   * @brief Check valid name.
   * The full name only contain alphabet characters and spaces.
   * @param QString fullname
   * @return bool
   */
  bool isValidName(const QString &name);

  /**
   * @brief Check valid email.
   * @param QString email
   * @return bool
   */
  bool isValidEmail(const QString &email);

  /**
   * @brief Check valid user name.
   * @param QString user name
   * @return bool
   */
  bool isValidUserName(const QString &userName);

  /**
   * @brief Check valid password.
   * Password must contain more than 8 character.
   * And have as least upper case, lower case and digit.
   * @param QString password
   * @return bool
   */
  bool isValidPassword(const QString &password);

  /**
   * @brief Check valid address.
   * @param QString address.
   * @return bool
   */
  bool isValidAddress(const QString &address);

  /**
   * @brief Check valid phone number.
   * Phone number has format: xxx-xxx-xxxx.
   * @param QString phoneNumber
   * @return bool
   */
  bool isValidPhoneNumber(const QString &phoneNumber);

  void insertUserData(const QString &firstName, const QString &lastName,
                         const QString &email, const QString &userName,
                         const QString &password, const QString &address,
                         const QString &phoneNumber);
};

#endif // SIGNIN_H
