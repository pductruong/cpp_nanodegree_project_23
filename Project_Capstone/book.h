#include <QDate>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QString>

// Book class representing a single book record
class Book {
public:
    // Default Constructor
    Book() : _bookID(0), _price(0.0), _accountID(0), _isRented(false) {}

    // Constructor with parameters
    Book(int id, const QString& title, const QString& author, const QString& publicationDate,
         const QString& genre, const QString& ISBN, double price,
         const QString& description, int accountID, bool isRented = false)
        : _bookID(id), _title(title), _author(author), _publicationDate(publicationDate),
          _genre(genre), _ISBN(ISBN), _price(price), _description(description),
          _accountID(accountID), _isRented(isRented) {}

    // Copy Constructor
    Book(const Book& other)
        : _bookID(other._bookID), _title(other._title), _author(other._author),
          _publicationDate(other._publicationDate), _genre(other._genre),
          _ISBN(other._ISBN), _price(other._price), _description(other._description),
          _accountID(other._accountID), _isRented(other._isRented) {}

    // Copy Assignment Operator
    Book& operator=(const Book& other) {
        if (this != &other) {
            _bookID = other._bookID;
            _title = other._title;
            _author = other._author;
            _publicationDate = other._publicationDate;
            _genre = other._genre;
            _ISBN = other._ISBN;
            _price = other._price;
            _description = other._description;
            _accountID = other._accountID;
            _isRented = other._isRented;
        }
        return *this;
    }

    // Move Constructor
    Book(Book&& other)
        : _bookID(other._bookID), _title(std::move(other._title)),
          _author(std::move(other._author)), _publicationDate(std::move(other._publicationDate)),
          _genre(std::move(other._genre)), _ISBN(std::move(other._ISBN)),
          _price(other._price), _description(std::move(other._description)),
          _accountID(other._accountID), _isRented(other._isRented) {}

    // Move Assignment Operator
    Book& operator=(Book&& other) {
        if (this != &other) {
            _bookID = other._bookID;
            _title = std::move(other._title);
            _author = std::move(other._author);
            _publicationDate = std::move(other._publicationDate);
            _genre = std::move(other._genre);
            _ISBN = std::move(other._ISBN);
            _price = other._price;
            _description = std::move(other._description);
            _accountID = other._accountID;
            _isRented = other._isRented;
        }
        return *this;
    }

    // Destructor
    ~Book() {}

  // Setters
  void setBookID(int id) { _bookID = id; }
  void setTitle(const QString &t) { _title = t; }
  void setAuthor(const QString &a) { _author = a; }
  void setPublicationDate(const QString &date) { _publicationDate = date; }
  void setGenre(const QString &g) { _genre = g; }
  void setISBN(const QString &isbn) { _ISBN = isbn; }
  void setPrice(double p) { _price = p; }
  void setDescription(const QString &desc) { _description = desc; }
  void setAccountID(int id) { _accountID = id; }
  void setIsRented(bool rented) { _isRented = rented; }

  // Getters
  int getBookID() const { return _bookID; }
  QString getTitle() const { return _title; }
  QString getAuthor() const { return _author; }
  QString getPublicationDate() const { return _publicationDate; }
  QString getGenre() const { return _genre; }
  QString getISBN() const { return _ISBN; }
  double getPrice() const { return _price; }
  QString getDescription() const { return _description; }
  int getAccountID() const { return _accountID; }
  bool getIsRented() const { return _isRented; }

private:
  QString databaseName;
  int _bookID;
  QString _title;
  QString _author;
  QString _publicationDate;
  QString _genre;
  QString _ISBN;
  double _price;
  QString _description;
  int _accountID;
  bool _isRented;
};

// BookManager class for managing book records
// class BookManager {
// public:
//   BookManager(const QString &dbName) : databaseName(dbName) {}

//   // Insert a new book record into the BookList table
//   bool insertBook(const Book &book) {
//     QSqlDatabase db = QSqlDatabase::database(databaseName);
//     if (!db.isOpen()) {
//       qDebug() << "Database is not open.";
//       return false;
//     }

//     QSqlQuery query(db);
//     query.prepare("INSERT INTO BookList (Title, Author, PublicationDate, "
//                   "Genre, ISBN, Price, "
//                   "Description, AccountID, IsRented) "
//                   "VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?)");
//     query.addBindValue(book.title);
//     query.addBindValue(book.author);
//     query.addBindValue(book.publicationDate);
//     query.addBindValue(book.genre);
//     query.addBindValue(book.ISBN);
//     query.addBindValue(book.price);
//     query.addBindValue(book.description);
//     query.addBindValue(book.accountID);
//     query.addBindValue(book.isRented);

//     if (!query.exec()) {
//       qDebug() << "Insert error:" << query.lastError().text();
//       return false;
//     }

//     return true;
//   }

//   // Delete a book record from the BookList table based on the book ID
//   bool deleteBook(int bookID) {
//     QSqlDatabase db = QSqlDatabase::database(databaseName);
//     if (!db.isOpen()) {
//       qDebug() << "Database is not open.";
//       return false;
//     }

//     QSqlQuery query(db);
//     query.prepare("DELETE FROM BookList WHERE BookID = ?");
//     query.addBindValue(bookID);

//     if (!query.exec()) {
//       qDebug() << "Delete error:" << query.lastError().text();
//       return false;
//     }

//     return true;
//   }

//   // Update a book record in the BookList table
//   bool updateBook(const Book &book) {
//     QSqlDatabase db = QSqlDatabase::database(databaseName);
//     if (!db.isOpen()) {
//       qDebug() << "Database is not open.";
//       return false;
//     }

//     QSqlQuery query(db);
//     query.prepare(
//         "UPDATE BookList SET Title = ?, Author = ?, PublicationDate = ?, "
//         "Genre = ?, ISBN = ?, Price = ?, Description = ?, "
//         "AccountID = ?, IsRented = ? WHERE BookID = ?");
//     query.addBindValue(book.title);
//     query.addBindValue(book.author);
//     query.addBindValue(book.publicationDate);
//     query.addBindValue(book.genre);
//     query.addBindValue(book.ISBN);
//     query.addBindValue(book.price);
//     query.addBindValue(book.description);
//     query.addBindValue(book.accountID);
//     query.addBindValue(book.isRented);
//     query.addBindValue(book.bookID);

//     if (!query.exec()) {
//       qDebug() << "Update error:" << query.lastError().text();
//       return false;
//     }

//     return true;
//   }

//   // Query and retrieve all book records from the BookList table
//   QVector<Book> getAllBooks() {
//     QVector<Book> books;

//     QSqlDatabase db = QSqlDatabase::database(databaseName);
//     if (!db.isOpen()) {
//       qDebug() << "Database is not open.";
//       return books;
//     }

//     QSqlQuery query(db);
//     if (!query.exec("SELECT * FROM BookList")) {
//       qDebug() << "Select error:" << query.lastError().text();
//       return books;
//     }

//     while (query.next()) {
//       int bookID = query.value("BookID").toInt();
//       QString title = query.value("Title").toString();
//       QString author = query.value("Author").toString();
//       QDate publicationDate = query.value("PublicationDate").toDate();
//       QString genre = query.value("Genre").toString();
//       QString ISBN = query.value("ISBN").toString();
//       double price = query.value("Price").toDouble();
//       QString description = query.value("Description").toString();
//       int accountID = query.value("AccountID").toInt();
//       bool isRented = query.value("IsRented").toBool();

//       books.push_back(Book(bookID, title, author, publicationDate, genre,
//       ISBN,
//                            price, description, accountID, isRented));
//     }

//     return books;
//   }

// private:
//   QString databaseName;
// };