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
How to run:
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


