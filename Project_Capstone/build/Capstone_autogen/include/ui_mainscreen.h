/********************************************************************************
** Form generated from reading UI file 'mainscreen.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINSCREEN_H
#define UI_MAINSCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <clickableLabel.h>

QT_BEGIN_NAMESPACE

class Ui_MainScreen
{
public:
    QVBoxLayout *verticalLayout_2;
    QWidget *widgetTitle;
    QHBoxLayout *horizontalLayout_2;
    QLabel *welcomeLabel;
    QLineEdit *userNameTitle;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QTableView *bookTableView;
    QWidget *buttonWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *addBookBtn;
    QPushButton *returnBookBtn;
    clickableLabel *goBack;

    void setupUi(QWidget *MainScreen)
    {
        if (MainScreen->objectName().isEmpty())
            MainScreen->setObjectName(QString::fromUtf8("MainScreen"));
        MainScreen->resize(1151, 707);
        MainScreen->setMinimumSize(QSize(800, 540));
        MainScreen->setMaximumSize(QSize(16777215, 16777215));
        verticalLayout_2 = new QVBoxLayout(MainScreen);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        widgetTitle = new QWidget(MainScreen);
        widgetTitle->setObjectName(QString::fromUtf8("widgetTitle"));
        horizontalLayout_2 = new QHBoxLayout(widgetTitle);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        welcomeLabel = new QLabel(widgetTitle);
        welcomeLabel->setObjectName(QString::fromUtf8("welcomeLabel"));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        welcomeLabel->setFont(font);

        horizontalLayout_2->addWidget(welcomeLabel);

        userNameTitle = new QLineEdit(widgetTitle);
        userNameTitle->setObjectName(QString::fromUtf8("userNameTitle"));

        horizontalLayout_2->addWidget(userNameTitle);


        verticalLayout_2->addWidget(widgetTitle);

        widget = new QWidget(MainScreen);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        widget_2 = new QWidget(widget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        verticalLayout_3 = new QVBoxLayout(widget_2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label = new QLabel(widget_2);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font1;
        font1.setPointSize(15);
        label->setFont(font1);

        verticalLayout_3->addWidget(label);

        bookTableView = new QTableView(widget_2);
        bookTableView->setObjectName(QString::fromUtf8("bookTableView"));

        verticalLayout_3->addWidget(bookTableView);


        horizontalLayout->addWidget(widget_2);

        buttonWidget = new QWidget(widget);
        buttonWidget->setObjectName(QString::fromUtf8("buttonWidget"));
        verticalLayout = new QVBoxLayout(buttonWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        addBookBtn = new QPushButton(buttonWidget);
        addBookBtn->setObjectName(QString::fromUtf8("addBookBtn"));
        addBookBtn->setMinimumSize(QSize(90, 60));
        addBookBtn->setMaximumSize(QSize(90, 60));

        verticalLayout->addWidget(addBookBtn, 0, Qt::AlignHCenter);

        returnBookBtn = new QPushButton(buttonWidget);
        returnBookBtn->setObjectName(QString::fromUtf8("returnBookBtn"));
        returnBookBtn->setMinimumSize(QSize(90, 60));
        returnBookBtn->setMaximumSize(QSize(90, 60));

        verticalLayout->addWidget(returnBookBtn, 0, Qt::AlignHCenter);


        horizontalLayout->addWidget(buttonWidget);


        verticalLayout_2->addWidget(widget);

        goBack = new clickableLabel(MainScreen);
        goBack->setObjectName(QString::fromUtf8("goBack"));
        QFont font2;
        font2.setPointSize(13);
        goBack->setFont(font2);
        goBack->setFrameShape(QFrame::Panel);

        verticalLayout_2->addWidget(goBack, 0, Qt::AlignRight);


        retranslateUi(MainScreen);

        QMetaObject::connectSlotsByName(MainScreen);
    } // setupUi

    void retranslateUi(QWidget *MainScreen)
    {
        MainScreen->setWindowTitle(QCoreApplication::translate("MainScreen", "Form", nullptr));
        welcomeLabel->setText(QCoreApplication::translate("MainScreen", "Welcome", nullptr));
        label->setText(QCoreApplication::translate("MainScreen", "List rented book:", nullptr));
        addBookBtn->setText(QCoreApplication::translate("MainScreen", "Rent Book", nullptr));
        returnBookBtn->setText(QCoreApplication::translate("MainScreen", "Return Book", nullptr));
        goBack->setText(QCoreApplication::translate("MainScreen", "Go back to Log In", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainScreen: public Ui_MainScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINSCREEN_H
