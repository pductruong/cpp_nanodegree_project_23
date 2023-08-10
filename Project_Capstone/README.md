# Capstone project - Book Rental Application
The project is constructed by C++ and Qt5/6 framwork

## Features
 - Adminstrator with admin account:
 -- Using admin account to change or delte account informations in database.
 -- Add the book into database
 -- Delete book from database
 - Sign in a new account
 - User function:
  --Display all books which is rented by current user
  -- Rent a new book from libary
  -- Return book

## Project structure
The prject have 10 class
- Class Acount: Using to store the account information which is get from database: Account ID, first name, last name, email, user name, password, address and phone number
-- And it also have getters or setters and apply the rule of five
-- Class Book: Similar with class Accout, and it have properties: Book ID, title, author, publication date, genre, ISBN, price, description, account ID, isRented
- Class AddBook: The QWidget using to admin add a new book into database
- Class Adminstrator: 
    - The QWidget have using to list all account in database and provide funtion to delete account, or change account information.
    - Also list all book in the library, which is rented, and rent by what account
    - Process database when adminstrator process with book or account information
- Class clickableLabel: The class using back to Login screen
- Class CustomQueryModel: Using override the default method display data. Purpose to display the book in the table
- Class LogIn: The QWidget use to open database, display Login interface, calling main screen or Sign up interface
- Class MainScreen: Main screen interface when user log in with the account is not admin. Provide user rent book and return book
- Class SignUp: SignUp a new accounct


## Installation
Requirements:
```sh
Qt5
sudo apt-get install build-essential perl python3 git
sudo apt-get install '^libxcb.*-dev' libx11-xcb-dev libglu1-mesa-dev libxrender-dev libxi-dev libxkbcommon-dev libxkbcommon-x11-dev
git clone git://code.qt.io/qt/qt5.git
cd qt5
git checkout 5.12
perl init-repository
mkdir qt5-build && cd qt5-build
../configure -developer-build -opensource -nomake examples -nomake tests
make -j2
make install
```
## How to run:
```sh
1. Clone the project
2. cd Project_Capstone
3. mkdir build && cd build
4. Complie
cmake .. && cmake --build . 
5. Run project
./Capstone
6. Using username: admin and password: admin to login with adminstrator account
7. Using username: truongpd and password: Truongpd1998 to login normal user
Or you can sign up new account with Sign up feature
```

## Rubric Points
Below are the rubric points that are addressed/implemented in this project.

### Loop, Functions, I/O
- The project demonstrates an understanding of C++ functions and control structures.
- The project reads data from database file and process the data, and write data to database file using SQLite. Method `connectDatabase()` using to open database, `checkUserData()` is used to read user data from database and many methods are used to write like `deleteAcc()` (use to delete account in database), `changeInfoAcc()` (use change account information).
- The project accepts user input and processes the input.User input by enter data on GUI interfaces.

### Object Oriented Programming
- The project uses Object Oriented Programming techniques.
- Classes use appropriate access specifiers for class members. (see `account.h`, `addbook.h`, `adminstrator.h`, `book`, `clickableLabel.h`, `customquerytable.h`, `login.h`, `mainscreen.h`, `rentbook.h`, `sigin.h`)
- Class constructors utilize member initialization lists. All class GUI interfaces is have own initialization with `QWidget(parent)`, `ui(new Ui::RentBook)`. For `account.h` and `book.h` have initialization for some of properties of these class like `_accountID(0)` or `_price(0)` or `_isRented(false)`.
- Classes abstract implementation details from their interfaces.
- Classes encapsulate behavior. Each class define a behaviour of GUI interfaces.
- Classes follow an appropriate inheritance hierarchy, Derived class functions override virtual base class functions.(see `customquerytable.h` and `customquerytable.cpp`. The class inheritance core class and override function on that).
- 
### Memory Management
- The project makes use of references in function declarations.
- The project uses destructors appropriately.
- The project uses move semantics to move data, instead of copying it, where possible.(see line 26 `mainscreen.h`)
- The project uses smart pointers instead of raw pointers.(see line 52 `login.h`)

### Concurrency
- Project using signal and slots for concurrency
