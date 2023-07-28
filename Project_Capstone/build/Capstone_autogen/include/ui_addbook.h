/********************************************************************************
** Form generated from reading UI file 'addbook.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDBOOK_H
#define UI_ADDBOOK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddBook
{
public:
    QVBoxLayout *verticalLayout_8;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *titleLineEdit;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QLineEdit *authorLineEdit;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QLineEdit *publicDateLineEdit;
    QWidget *widget_5;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_5;
    QLineEdit *genreLineEdit;
    QWidget *widget_4;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_4;
    QLineEdit *isbnLineEdit;
    QWidget *widget_6;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_6;
    QLineEdit *priceLineEdit;
    QWidget *widget_7;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_7;
    QLineEdit *descriptionLineEdit;
    QWidget *widget_8;
    QHBoxLayout *horizontalLayout;
    QPushButton *cancelAddBook;
    QPushButton *confirmAddBook;

    void setupUi(QWidget *AddBook)
    {
        if (AddBook->objectName().isEmpty())
            AddBook->setObjectName(QString::fromUtf8("AddBook"));
        AddBook->resize(450, 780);
        AddBook->setMinimumSize(QSize(450, 780));
        AddBook->setMaximumSize(QSize(450, 780));
        verticalLayout_8 = new QVBoxLayout(AddBook);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        widget = new QWidget(AddBook);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        titleLineEdit = new QLineEdit(widget);
        titleLineEdit->setObjectName(QString::fromUtf8("titleLineEdit"));

        verticalLayout->addWidget(titleLineEdit);


        verticalLayout_8->addWidget(widget);

        widget_2 = new QWidget(AddBook);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        verticalLayout_2 = new QVBoxLayout(widget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_2 = new QLabel(widget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_2->addWidget(label_2);

        authorLineEdit = new QLineEdit(widget_2);
        authorLineEdit->setObjectName(QString::fromUtf8("authorLineEdit"));

        verticalLayout_2->addWidget(authorLineEdit);


        verticalLayout_8->addWidget(widget_2);

        widget_3 = new QWidget(AddBook);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        verticalLayout_3 = new QVBoxLayout(widget_3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_3 = new QLabel(widget_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_3->addWidget(label_3);

        publicDateLineEdit = new QLineEdit(widget_3);
        publicDateLineEdit->setObjectName(QString::fromUtf8("publicDateLineEdit"));

        verticalLayout_3->addWidget(publicDateLineEdit);


        verticalLayout_8->addWidget(widget_3);

        widget_5 = new QWidget(AddBook);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        verticalLayout_5 = new QVBoxLayout(widget_5);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label_5 = new QLabel(widget_5);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_5->addWidget(label_5);

        genreLineEdit = new QLineEdit(widget_5);
        genreLineEdit->setObjectName(QString::fromUtf8("genreLineEdit"));

        verticalLayout_5->addWidget(genreLineEdit);


        verticalLayout_8->addWidget(widget_5);

        widget_4 = new QWidget(AddBook);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        verticalLayout_4 = new QVBoxLayout(widget_4);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_4 = new QLabel(widget_4);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_4->addWidget(label_4);

        isbnLineEdit = new QLineEdit(widget_4);
        isbnLineEdit->setObjectName(QString::fromUtf8("isbnLineEdit"));

        verticalLayout_4->addWidget(isbnLineEdit);


        verticalLayout_8->addWidget(widget_4);

        widget_6 = new QWidget(AddBook);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        verticalLayout_6 = new QVBoxLayout(widget_6);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        label_6 = new QLabel(widget_6);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout_6->addWidget(label_6);

        priceLineEdit = new QLineEdit(widget_6);
        priceLineEdit->setObjectName(QString::fromUtf8("priceLineEdit"));

        verticalLayout_6->addWidget(priceLineEdit);


        verticalLayout_8->addWidget(widget_6);

        widget_7 = new QWidget(AddBook);
        widget_7->setObjectName(QString::fromUtf8("widget_7"));
        verticalLayout_7 = new QVBoxLayout(widget_7);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        label_7 = new QLabel(widget_7);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        verticalLayout_7->addWidget(label_7);

        descriptionLineEdit = new QLineEdit(widget_7);
        descriptionLineEdit->setObjectName(QString::fromUtf8("descriptionLineEdit"));

        verticalLayout_7->addWidget(descriptionLineEdit);


        verticalLayout_8->addWidget(widget_7);

        widget_8 = new QWidget(AddBook);
        widget_8->setObjectName(QString::fromUtf8("widget_8"));
        horizontalLayout = new QHBoxLayout(widget_8);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        cancelAddBook = new QPushButton(widget_8);
        cancelAddBook->setObjectName(QString::fromUtf8("cancelAddBook"));
        cancelAddBook->setMinimumSize(QSize(100, 30));
        cancelAddBook->setMaximumSize(QSize(100, 30));

        horizontalLayout->addWidget(cancelAddBook);

        confirmAddBook = new QPushButton(widget_8);
        confirmAddBook->setObjectName(QString::fromUtf8("confirmAddBook"));
        confirmAddBook->setMinimumSize(QSize(100, 30));
        confirmAddBook->setMaximumSize(QSize(100, 30));

        horizontalLayout->addWidget(confirmAddBook);


        verticalLayout_8->addWidget(widget_8);


        retranslateUi(AddBook);

        QMetaObject::connectSlotsByName(AddBook);
    } // setupUi

    void retranslateUi(QWidget *AddBook)
    {
        AddBook->setWindowTitle(QCoreApplication::translate("AddBook", "Form", nullptr));
        label->setText(QCoreApplication::translate("AddBook", "Book Title", nullptr));
        label_2->setText(QCoreApplication::translate("AddBook", "Author", nullptr));
        label_3->setText(QCoreApplication::translate("AddBook", "Publication Date", nullptr));
        label_5->setText(QCoreApplication::translate("AddBook", "Genre", nullptr));
        label_4->setText(QCoreApplication::translate("AddBook", "ISBN", nullptr));
        label_6->setText(QCoreApplication::translate("AddBook", "Price", nullptr));
        label_7->setText(QCoreApplication::translate("AddBook", "Description", nullptr));
        cancelAddBook->setText(QCoreApplication::translate("AddBook", "Cancel", nullptr));
        confirmAddBook->setText(QCoreApplication::translate("AddBook", "Add", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddBook: public Ui_AddBook {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDBOOK_H
