/********************************************************************************
** Form generated from reading UI file 'signin.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNIN_H
#define UI_SIGNIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <clickableLabel.h>

QT_BEGIN_NAMESPACE

class Ui_SignIn
{
public:
    QVBoxLayout *verticalLayout_7;
    QWidget *titleFrame;
    QVBoxLayout *verticalLayout;
    QLabel *titleSignUp1;
    QLabel *titleSignUp2;
    QWidget *mainFrame;
    QVBoxLayout *verticalLayout_6;
    QWidget *firstNameFrame;
    QVBoxLayout *verticalLayout_2;
    QLabel *firstNameLabel;
    QLineEdit *firstNameLineEdit;
    QWidget *lastNameFrame;
    QVBoxLayout *verticalLayout_3;
    QLabel *lastNameLabel;
    QLineEdit *lastNameLineEdit;
    QWidget *eMailFrame;
    QVBoxLayout *verticalLayout_4;
    QLabel *eMailLabel;
    QLineEdit *eMailLineEdit;
    QWidget *userNameFrame;
    QVBoxLayout *verticalLayout_5;
    QLabel *userNameLabel;
    QLineEdit *userNameLineEdit;
    QWidget *passwordFrame;
    QVBoxLayout *verticalLayout_9;
    QLabel *passwordLabel;
    QLineEdit *passwordLineEdit;
    QWidget *addressFrame;
    QVBoxLayout *verticalLayout_8;
    QLabel *addressLabel;
    QLineEdit *addressLineEdit;
    QWidget *phoneNumberFrame;
    QVBoxLayout *verticalLayout_10;
    QLabel *phoneNumberLabel;
    QLineEdit *phoneNumberLineEdit;
    QPushButton *signUpBtn;
    clickableLabel *backToLogInBtn;

    void setupUi(QWidget *SignIn)
    {
        if (SignIn->objectName().isEmpty())
            SignIn->setObjectName(QString::fromUtf8("SignIn"));
        SignIn->resize(600, 890);
        SignIn->setMinimumSize(QSize(600, 890));
        SignIn->setMaximumSize(QSize(600, 890));
        verticalLayout_7 = new QVBoxLayout(SignIn);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        titleFrame = new QWidget(SignIn);
        titleFrame->setObjectName(QString::fromUtf8("titleFrame"));
        verticalLayout = new QVBoxLayout(titleFrame);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        titleSignUp1 = new QLabel(titleFrame);
        titleSignUp1->setObjectName(QString::fromUtf8("titleSignUp1"));
        QFont font;
        font.setPointSize(40);
        font.setBold(true);
        titleSignUp1->setFont(font);

        verticalLayout->addWidget(titleSignUp1);

        titleSignUp2 = new QLabel(titleFrame);
        titleSignUp2->setObjectName(QString::fromUtf8("titleSignUp2"));
        QFont font1;
        font1.setPointSize(15);
        titleSignUp2->setFont(font1);

        verticalLayout->addWidget(titleSignUp2);


        verticalLayout_7->addWidget(titleFrame, 0, Qt::AlignHCenter);

        mainFrame = new QWidget(SignIn);
        mainFrame->setObjectName(QString::fromUtf8("mainFrame"));
        verticalLayout_6 = new QVBoxLayout(mainFrame);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        firstNameFrame = new QWidget(mainFrame);
        firstNameFrame->setObjectName(QString::fromUtf8("firstNameFrame"));
        firstNameFrame->setMinimumSize(QSize(330, 90));
        firstNameFrame->setMaximumSize(QSize(330, 90));
        verticalLayout_2 = new QVBoxLayout(firstNameFrame);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        firstNameLabel = new QLabel(firstNameFrame);
        firstNameLabel->setObjectName(QString::fromUtf8("firstNameLabel"));
        firstNameLabel->setMinimumSize(QSize(250, 30));
        firstNameLabel->setMaximumSize(QSize(250, 30));
        QFont font2;
        font2.setPointSize(13);
        firstNameLabel->setFont(font2);

        verticalLayout_2->addWidget(firstNameLabel, 0, Qt::AlignLeft|Qt::AlignTop);

        firstNameLineEdit = new QLineEdit(firstNameFrame);
        firstNameLineEdit->setObjectName(QString::fromUtf8("firstNameLineEdit"));
        firstNameLineEdit->setMinimumSize(QSize(310, 35));
        firstNameLineEdit->setMaximumSize(QSize(310, 35));

        verticalLayout_2->addWidget(firstNameLineEdit);


        verticalLayout_6->addWidget(firstNameFrame);

        lastNameFrame = new QWidget(mainFrame);
        lastNameFrame->setObjectName(QString::fromUtf8("lastNameFrame"));
        lastNameFrame->setMinimumSize(QSize(330, 90));
        lastNameFrame->setMaximumSize(QSize(330, 90));
        verticalLayout_3 = new QVBoxLayout(lastNameFrame);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        lastNameLabel = new QLabel(lastNameFrame);
        lastNameLabel->setObjectName(QString::fromUtf8("lastNameLabel"));
        lastNameLabel->setMinimumSize(QSize(250, 30));
        lastNameLabel->setMaximumSize(QSize(250, 30));
        lastNameLabel->setFont(font2);

        verticalLayout_3->addWidget(lastNameLabel, 0, Qt::AlignLeft|Qt::AlignTop);

        lastNameLineEdit = new QLineEdit(lastNameFrame);
        lastNameLineEdit->setObjectName(QString::fromUtf8("lastNameLineEdit"));
        lastNameLineEdit->setMinimumSize(QSize(310, 35));
        lastNameLineEdit->setMaximumSize(QSize(310, 35));

        verticalLayout_3->addWidget(lastNameLineEdit);


        verticalLayout_6->addWidget(lastNameFrame);

        eMailFrame = new QWidget(mainFrame);
        eMailFrame->setObjectName(QString::fromUtf8("eMailFrame"));
        eMailFrame->setMinimumSize(QSize(330, 90));
        eMailFrame->setMaximumSize(QSize(330, 90));
        verticalLayout_4 = new QVBoxLayout(eMailFrame);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        eMailLabel = new QLabel(eMailFrame);
        eMailLabel->setObjectName(QString::fromUtf8("eMailLabel"));
        eMailLabel->setMinimumSize(QSize(250, 30));
        eMailLabel->setMaximumSize(QSize(250, 30));
        eMailLabel->setFont(font2);

        verticalLayout_4->addWidget(eMailLabel, 0, Qt::AlignLeft|Qt::AlignTop);

        eMailLineEdit = new QLineEdit(eMailFrame);
        eMailLineEdit->setObjectName(QString::fromUtf8("eMailLineEdit"));
        eMailLineEdit->setMinimumSize(QSize(310, 35));
        eMailLineEdit->setMaximumSize(QSize(310, 35));

        verticalLayout_4->addWidget(eMailLineEdit);


        verticalLayout_6->addWidget(eMailFrame);

        userNameFrame = new QWidget(mainFrame);
        userNameFrame->setObjectName(QString::fromUtf8("userNameFrame"));
        userNameFrame->setMinimumSize(QSize(330, 90));
        userNameFrame->setMaximumSize(QSize(330, 90));
        verticalLayout_5 = new QVBoxLayout(userNameFrame);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        userNameLabel = new QLabel(userNameFrame);
        userNameLabel->setObjectName(QString::fromUtf8("userNameLabel"));
        userNameLabel->setMinimumSize(QSize(250, 30));
        userNameLabel->setMaximumSize(QSize(250, 30));
        userNameLabel->setFont(font2);

        verticalLayout_5->addWidget(userNameLabel, 0, Qt::AlignLeft|Qt::AlignTop);

        userNameLineEdit = new QLineEdit(userNameFrame);
        userNameLineEdit->setObjectName(QString::fromUtf8("userNameLineEdit"));
        userNameLineEdit->setMinimumSize(QSize(310, 35));
        userNameLineEdit->setMaximumSize(QSize(310, 35));

        verticalLayout_5->addWidget(userNameLineEdit);


        verticalLayout_6->addWidget(userNameFrame);

        passwordFrame = new QWidget(mainFrame);
        passwordFrame->setObjectName(QString::fromUtf8("passwordFrame"));
        passwordFrame->setMinimumSize(QSize(330, 90));
        passwordFrame->setMaximumSize(QSize(330, 90));
        verticalLayout_9 = new QVBoxLayout(passwordFrame);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        passwordLabel = new QLabel(passwordFrame);
        passwordLabel->setObjectName(QString::fromUtf8("passwordLabel"));
        passwordLabel->setMinimumSize(QSize(250, 30));
        passwordLabel->setMaximumSize(QSize(250, 30));
        passwordLabel->setFont(font2);

        verticalLayout_9->addWidget(passwordLabel, 0, Qt::AlignLeft|Qt::AlignTop);

        passwordLineEdit = new QLineEdit(passwordFrame);
        passwordLineEdit->setObjectName(QString::fromUtf8("passwordLineEdit"));
        passwordLineEdit->setMinimumSize(QSize(310, 35));
        passwordLineEdit->setMaximumSize(QSize(310, 35));

        verticalLayout_9->addWidget(passwordLineEdit);


        verticalLayout_6->addWidget(passwordFrame);

        addressFrame = new QWidget(mainFrame);
        addressFrame->setObjectName(QString::fromUtf8("addressFrame"));
        addressFrame->setMinimumSize(QSize(330, 90));
        addressFrame->setMaximumSize(QSize(330, 90));
        verticalLayout_8 = new QVBoxLayout(addressFrame);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        addressLabel = new QLabel(addressFrame);
        addressLabel->setObjectName(QString::fromUtf8("addressLabel"));
        addressLabel->setMinimumSize(QSize(250, 30));
        addressLabel->setMaximumSize(QSize(250, 30));
        addressLabel->setFont(font2);

        verticalLayout_8->addWidget(addressLabel, 0, Qt::AlignLeft|Qt::AlignTop);

        addressLineEdit = new QLineEdit(addressFrame);
        addressLineEdit->setObjectName(QString::fromUtf8("addressLineEdit"));
        addressLineEdit->setMinimumSize(QSize(310, 35));
        addressLineEdit->setMaximumSize(QSize(310, 35));

        verticalLayout_8->addWidget(addressLineEdit);


        verticalLayout_6->addWidget(addressFrame);

        phoneNumberFrame = new QWidget(mainFrame);
        phoneNumberFrame->setObjectName(QString::fromUtf8("phoneNumberFrame"));
        phoneNumberFrame->setMinimumSize(QSize(330, 90));
        phoneNumberFrame->setMaximumSize(QSize(330, 90));
        verticalLayout_10 = new QVBoxLayout(phoneNumberFrame);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        phoneNumberLabel = new QLabel(phoneNumberFrame);
        phoneNumberLabel->setObjectName(QString::fromUtf8("phoneNumberLabel"));
        phoneNumberLabel->setMinimumSize(QSize(250, 30));
        phoneNumberLabel->setMaximumSize(QSize(250, 30));
        phoneNumberLabel->setFont(font2);

        verticalLayout_10->addWidget(phoneNumberLabel, 0, Qt::AlignLeft|Qt::AlignTop);

        phoneNumberLineEdit = new QLineEdit(phoneNumberFrame);
        phoneNumberLineEdit->setObjectName(QString::fromUtf8("phoneNumberLineEdit"));
        phoneNumberLineEdit->setMinimumSize(QSize(310, 35));
        phoneNumberLineEdit->setMaximumSize(QSize(310, 35));

        verticalLayout_10->addWidget(phoneNumberLineEdit);


        verticalLayout_6->addWidget(phoneNumberFrame);

        signUpBtn = new QPushButton(mainFrame);
        signUpBtn->setObjectName(QString::fromUtf8("signUpBtn"));
        signUpBtn->setFont(font1);

        verticalLayout_6->addWidget(signUpBtn, 0, Qt::AlignHCenter|Qt::AlignVCenter);


        verticalLayout_7->addWidget(mainFrame, 0, Qt::AlignHCenter);

        backToLogInBtn = new clickableLabel(SignIn);
        backToLogInBtn->setObjectName(QString::fromUtf8("backToLogInBtn"));

        verticalLayout_7->addWidget(backToLogInBtn, 0, Qt::AlignRight);


        retranslateUi(SignIn);

        QMetaObject::connectSlotsByName(SignIn);
    } // setupUi

    void retranslateUi(QWidget *SignIn)
    {
        SignIn->setWindowTitle(QCoreApplication::translate("SignIn", "Form", nullptr));
        titleSignUp1->setText(QCoreApplication::translate("SignIn", "Sign Up", nullptr));
        titleSignUp2->setText(QCoreApplication::translate("SignIn", "It's quick and easy.", nullptr));
        firstNameLabel->setText(QCoreApplication::translate("SignIn", "First Name", nullptr));
        lastNameLabel->setText(QCoreApplication::translate("SignIn", "Last Name", nullptr));
        eMailLabel->setText(QCoreApplication::translate("SignIn", "E-mail", nullptr));
        userNameLabel->setText(QCoreApplication::translate("SignIn", "User Name", nullptr));
        passwordLabel->setText(QCoreApplication::translate("SignIn", "Password", nullptr));
        addressLabel->setText(QCoreApplication::translate("SignIn", "Address", nullptr));
        phoneNumberLabel->setText(QCoreApplication::translate("SignIn", "Phone Number", nullptr));
        signUpBtn->setText(QCoreApplication::translate("SignIn", "Sign Up", nullptr));
        backToLogInBtn->setText(QCoreApplication::translate("SignIn", "Back to Log In", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SignIn: public Ui_SignIn {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNIN_H
