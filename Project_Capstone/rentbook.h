#ifndef RENTBOOK_H
#define RENTBOOK_H

#include <QMessageBox>
#include <QObject>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QString>
#include <QWidget>
#include <QCloseEvent>
#include <memory>

#include "account.h"
#include "customquerytable.h"

namespace Ui {
class RentBook;
}

class RentBook : public QWidget {
  Q_OBJECT

public:
  explicit RentBook(QWidget *parent = nullptr);
  ~RentBook();
  void setDatabase(std::unique_ptr<QSqlDatabase> db);
  void displayAvailableBook();
  void getCurrentUser(std::unique_ptr<AccountInformation> account);

private slots:
  void on_rentBtn_clicked();

  void on_cancelBtn_clicked();

private:
  Ui::RentBook *ui;
  std::unique_ptr<QSqlDatabase> _db;
  CustomQueryModel *_customModel;
  QSqlQueryModel *_model;
  QSqlQuery *_query;
  std::unique_ptr<AccountInformation> _account;

protected:
  void closeEvent(QCloseEvent *event) override {
    // Emit the destroyed signal
    emit widgetClosed();
    // Accept the close event to actually close the widget
    event->accept();
  }

signals:
  void widgetClosed();
};

#endif // RENTBOOK_H
