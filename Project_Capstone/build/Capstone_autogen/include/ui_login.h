/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <clickableLabel.h>

QT_BEGIN_NAMESPACE

class Ui_LogIn
{
public:
    QVBoxLayout *verticalLayout_2;
    QFrame *titleFrame;
    QHBoxLayout *horizontalLayout_2;
    QLabel *appTitle;
    QFrame *frame_4;
    QHBoxLayout *horizontalLayout_3;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_4;
    QFrame *frame_2;
    QGridLayout *gridLayout;
    QLabel *passWordLabel;
    QLabel *userNameLabel;
    QLineEdit *userNameLineEdit;
    QLineEdit *passwordLineEdit;
    QPushButton *logInBtn;
    QFrame *signInFrame;
    QHBoxLayout *horizontalLayout;
    clickableLabel *signInBtn;

    void setupUi(QWidget *LogIn)
    {
        if (LogIn->objectName().isEmpty())
            LogIn->setObjectName(QString::fromUtf8("LogIn"));
        LogIn->resize(800, 600);
        LogIn->setMinimumSize(QSize(800, 600));
        LogIn->setMaximumSize(QSize(800, 600));
        verticalLayout_2 = new QVBoxLayout(LogIn);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        titleFrame = new QFrame(LogIn);
        titleFrame->setObjectName(QString::fromUtf8("titleFrame"));
        titleFrame->setFrameShape(QFrame::NoFrame);
        titleFrame->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(titleFrame);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        appTitle = new QLabel(titleFrame);
        appTitle->setObjectName(QString::fromUtf8("appTitle"));
        QFont font;
        font.setPointSize(30);
        appTitle->setFont(font);
        appTitle->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(appTitle);


        verticalLayout_2->addWidget(titleFrame);

        frame_4 = new QFrame(LogIn);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setFrameShape(QFrame::NoFrame);
        frame_4->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(frame_4);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        frame = new QFrame(frame_4);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_4 = new QHBoxLayout(frame);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        frame_2 = new QFrame(frame);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame_2->sizePolicy().hasHeightForWidth());
        frame_2->setSizePolicy(sizePolicy);
        frame_2->setMinimumSize(QSize(430, 220));
        frame_2->setMaximumSize(QSize(430, 220));
        frame_2->setFrameShape(QFrame::NoFrame);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame_2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        passWordLabel = new QLabel(frame_2);
        passWordLabel->setObjectName(QString::fromUtf8("passWordLabel"));
        QFont font1;
        font1.setPointSize(15);
        passWordLabel->setFont(font1);

        gridLayout->addWidget(passWordLabel, 3, 0, 1, 1);

        userNameLabel = new QLabel(frame_2);
        userNameLabel->setObjectName(QString::fromUtf8("userNameLabel"));
        userNameLabel->setFont(font1);

        gridLayout->addWidget(userNameLabel, 0, 0, 1, 1);

        userNameLineEdit = new QLineEdit(frame_2);
        userNameLineEdit->setObjectName(QString::fromUtf8("userNameLineEdit"));
        userNameLineEdit->setEnabled(true);

        gridLayout->addWidget(userNameLineEdit, 0, 2, 1, 1);

        passwordLineEdit = new QLineEdit(frame_2);
        passwordLineEdit->setObjectName(QString::fromUtf8("passwordLineEdit"));

        gridLayout->addWidget(passwordLineEdit, 3, 2, 1, 1);

        logInBtn = new QPushButton(frame_2);
        logInBtn->setObjectName(QString::fromUtf8("logInBtn"));
        logInBtn->setMinimumSize(QSize(80, 30));
        logInBtn->setMaximumSize(QSize(80, 30));
        logInBtn->setFont(font1);

        gridLayout->addWidget(logInBtn, 4, 2, 1, 1);


        horizontalLayout_4->addWidget(frame_2);


        horizontalLayout_3->addWidget(frame);


        verticalLayout_2->addWidget(frame_4);

        signInFrame = new QFrame(LogIn);
        signInFrame->setObjectName(QString::fromUtf8("signInFrame"));
        signInFrame->setMinimumSize(QSize(100, 50));
        signInFrame->setMaximumSize(QSize(100, 50));
        signInFrame->setFrameShape(QFrame::NoFrame);
        signInFrame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(signInFrame);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        signInBtn = new clickableLabel(signInFrame);
        signInBtn->setObjectName(QString::fromUtf8("signInBtn"));
        signInBtn->setFont(font1);

        horizontalLayout->addWidget(signInBtn, 0, Qt::AlignHCenter);


        verticalLayout_2->addWidget(signInFrame, 0, Qt::AlignRight);


        retranslateUi(LogIn);

        QMetaObject::connectSlotsByName(LogIn);
    } // setupUi

    void retranslateUi(QWidget *LogIn)
    {
        LogIn->setWindowTitle(QCoreApplication::translate("LogIn", "LogIn", nullptr));
        appTitle->setText(QCoreApplication::translate("LogIn", "Book Rental Application", nullptr));
        passWordLabel->setText(QCoreApplication::translate("LogIn", "Password", nullptr));
        userNameLabel->setText(QCoreApplication::translate("LogIn", "User Name", nullptr));
        logInBtn->setText(QCoreApplication::translate("LogIn", "Login", nullptr));
        signInBtn->setText(QCoreApplication::translate("LogIn", "Sign In", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LogIn: public Ui_LogIn {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
