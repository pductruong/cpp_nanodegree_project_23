/********************************************************************************
** Form generated from reading UI file 'rentbook.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RENTBOOK_H
#define UI_RENTBOOK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RentBook
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTableView *availableBookTable;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *cancelBtn;
    QPushButton *rentBtn;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QWidget *RentBook)
    {
        if (RentBook->objectName().isEmpty())
            RentBook->setObjectName(QString::fromUtf8("RentBook"));
        RentBook->resize(1000, 700);
        RentBook->setMinimumSize(QSize(1000, 700));
        QFont font;
        font.setBold(true);
        RentBook->setFont(font);
        verticalLayout = new QVBoxLayout(RentBook);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(RentBook);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font1;
        font1.setPointSize(18);
        font1.setBold(true);
        label->setFont(font1);

        verticalLayout->addWidget(label);

        availableBookTable = new QTableView(RentBook);
        availableBookTable->setObjectName(QString::fromUtf8("availableBookTable"));
        QFont font2;
        font2.setBold(false);
        availableBookTable->setFont(font2);
        availableBookTable->setSelectionMode(QAbstractItemView::ExtendedSelection);

        verticalLayout->addWidget(availableBookTable);

        widget = new QWidget(RentBook);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(230, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        cancelBtn = new QPushButton(widget);
        cancelBtn->setObjectName(QString::fromUtf8("cancelBtn"));
        cancelBtn->setMinimumSize(QSize(100, 30));
        cancelBtn->setMaximumSize(QSize(100, 30));

        horizontalLayout->addWidget(cancelBtn);

        rentBtn = new QPushButton(widget);
        rentBtn->setObjectName(QString::fromUtf8("rentBtn"));
        rentBtn->setMinimumSize(QSize(100, 30));
        rentBtn->setMaximumSize(QSize(100, 30));

        horizontalLayout->addWidget(rentBtn);

        horizontalSpacer_3 = new QSpacerItem(230, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        verticalLayout->addWidget(widget);


        retranslateUi(RentBook);

        QMetaObject::connectSlotsByName(RentBook);
    } // setupUi

    void retranslateUi(QWidget *RentBook)
    {
        RentBook->setWindowTitle(QCoreApplication::translate("RentBook", "Form", nullptr));
        label->setText(QCoreApplication::translate("RentBook", "List book can be rented", nullptr));
        cancelBtn->setText(QCoreApplication::translate("RentBook", "Canel", nullptr));
        rentBtn->setText(QCoreApplication::translate("RentBook", "Rent", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RentBook: public Ui_RentBook {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RENTBOOK_H
