#include "customquerytable.h"

CustomQueryModel::CustomQueryModel(QObject *parent) : QSqlQueryModel(parent) {}

QVariant CustomQueryModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
        // Customize the column headers based on their index (section)
        switch (section) {
            case 0:
                return "Title";
            case 1:
                return "Author";
            case 2:
                return "Publication Date";
            case 3:
                return "Genre";
            case 4:
                return "ISBN";
            case 5:
                return "Price";
            case 6:
                return "Description";
            case 7:
                return "Account Name"; 
            case 8:
                return "Rent Status";
            default:
                return QVariant();
        }
    }
    return QVariant();
}

QVariant CustomQueryModel::data(const QModelIndex &index, int role) const {
    if (role == Qt::DisplayRole) {
        // For the "Rent Status" column (index 8)
        if (index.column() == 8) {
            // Get the value from the "IsRented" column (index 8) and return the appropriate text
            bool isRented = QSqlQueryModel::data(index, role).toBool();
            return isRented ? "Rented" : "Available";
        }
        // For the "Account Name" column (index 9)
        else if (index.column() == 7) {
            // Get the value from the "AccountID" column (index 7)
            int accountID = QSqlQueryModel::data(this->index(index.row(), 7), role).toInt();

            // Fetch the account's FirstName and LastName from the "AccountInformation" table based on the AccountID
            QSqlQuery query;
            query.prepare("SELECT FirstName, LastName FROM AccountInformation WHERE AccountID = :accountID");
            query.bindValue(":accountID", accountID);
            if (!query.exec() || !query.next()) {
                // Error occurred or no record found in "AccountInformation" table for the given AccountID
                return "N/A";
            }

            // Construct and return the full name of the account (FirstName LastName)
            QString firstName = query.value("FirstName").toString();
            QString lastName = query.value("LastName").toString();
            return firstName + " " + lastName;
        }
    }
    return QSqlQueryModel::data(index, role);
}
