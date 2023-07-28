#ifndef ACCOUNTINFORMATION_H
#define ACCOUNTINFORMATION_H

#include <QString>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

class AccountInformation {
public:
    // Default Constructor
    AccountInformation() : _accountID(0) {}

   // Setters and Getters
    void setAccountID(int accountID) { _accountID = accountID; }
    int getAccountID() const { return _accountID; }

    void setFirstName(const QString& firstName) { _firstName = firstName; }
    const QString& getFirstName() const { return _firstName; }

    void setLastName(const QString& lastName) { _lastName = lastName; }
    const QString& getLastName() const { return _lastName; }

    void setEmail(const QString& email) { _email = email; }
    const QString& getEmail() const { return _email; }

    void setUserName(const QString& userName) { _userName = userName; }
    const QString& getUserName() const { return _userName; }

    void setPassword(const QString& password) { _password = password; }
    const QString& getPassword() const { return _password; }

    void setAddress(const QString& address) { _address = address; }
    const QString& getAddress() const { return _address; }

    void setPhoneNumber(const QString& phoneNumber) { _phoneNumber = phoneNumber; }
    const QString& getPhoneNumber() const { return _phoneNumber; }
    // Destructor
    ~AccountInformation() {}

    // Copy Constructor
    AccountInformation(const AccountInformation& other) {
        *this = other;
    }

    // Copy Assignment Operator
    AccountInformation& operator=(const AccountInformation& other) {
        if (this != &other) {
            _accountID = other._accountID;
            _firstName = other._firstName;
            _lastName = other._lastName;
            _email = other._email;
            _userName = other._userName;
            _password = other._password;
            _address = other._address;
            _phoneNumber = other._phoneNumber;
        }
        return *this;
    }

    // Move Constructor
    AccountInformation(AccountInformation&& other) {
        *this = std::move(other);
    }

    // Move Assignment Operator
    AccountInformation& operator=(AccountInformation&& other) {
        if (this != &other) {
            _accountID = other._accountID;
            _firstName = std::move(other._firstName);
            _lastName = std::move(other._lastName);
            _email = std::move(other._email);
            _userName = std::move(other._userName);
            _password = std::move(other._password);
            _address = std::move(other._address);
            _phoneNumber = std::move(other._phoneNumber);
        }
        return *this;
    }

    // Save the account information to the database
    // bool save() const {
    //     QSqlQuery query;
    //     query.prepare("INSERT INTO AccountInformation (FirstName, LastName, Email, UserName, Password, Address, PhoneNumber) "
    //                   "VALUES (:firstName, :lastName, :email, :userName, :password, :address, :phoneNumber)");
    //     query.bindValue(":firstName", _firstName);
    //     query.bindValue(":lastName", _lastName);
    //     query.bindValue(":email", _email);
    //     query.bindValue(":userName", _userName);
    //     query.bindValue(":password", _password);
    //     query.bindValue(":address", _address);
    //     query.bindValue(":phoneNumber", _phoneNumber);

    //     if (query.exec()) {
    //         _accountID = query.lastInsertId().toInt();
    //         return true;
    //     } else {
    //         qDebug() << "Error saving account information:" << query.lastError().text();
    //         return false;
    //     }
    // }

private:
    int _accountID;
    QString _firstName;
    QString _lastName;
    QString _email;
    QString _userName;
    QString _password;
    QString _address;
    QString _phoneNumber;
};

#endif // ACCOUNTINFORMATION_H