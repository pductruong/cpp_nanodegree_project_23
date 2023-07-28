/********************************************************************************
** Form generated from reading UI file 'adminstrator.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINSTRATOR_H
#define UI_ADMINSTRATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Adminstrator
{
public:
    QVBoxLayout *verticalLayout_4;
    QStackedWidget *stackedWidget;
    QWidget *accountView;
    QVBoxLayout *verticalLayout_2;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout_2;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *searchAccountBox;
    QLabel *label;
    QTableView *usersTableView;
    QWidget *bookView;
    QHBoxLayout *horizontalLayout_6;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_3;
    QFrame *frame_4;
    QHBoxLayout *horizontalLayout_4;
    QFrame *frame_5;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_3;
    QLineEdit *searchBookBox;
    QLabel *label_4;
    QTableView *bookTableView;
    QWidget *buttonWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *addBookBtn;
    QPushButton *deleteBookBtn;
    QFrame *frame_3;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *accountManagementBtn;
    QPushButton *bookManagementBtn;
    QPushButton *backToLoginBtn;

    void setupUi(QWidget *Adminstrator)
    {
        if (Adminstrator->objectName().isEmpty())
            Adminstrator->setObjectName(QString::fromUtf8("Adminstrator"));
        Adminstrator->resize(1295, 848);
        Adminstrator->setMinimumSize(QSize(800, 600));
        Adminstrator->setMaximumSize(QSize(16777215, 16777215));
        verticalLayout_4 = new QVBoxLayout(Adminstrator);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        stackedWidget = new QStackedWidget(Adminstrator);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        accountView = new QWidget();
        accountView->setObjectName(QString::fromUtf8("accountView"));
        verticalLayout_2 = new QVBoxLayout(accountView);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        frame_2 = new QFrame(accountView);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::NoFrame);
        frame_2->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        frame = new QFrame(frame_2);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        searchAccountBox = new QLineEdit(frame);
        searchAccountBox->setObjectName(QString::fromUtf8("searchAccountBox"));

        horizontalLayout->addWidget(searchAccountBox);


        horizontalLayout_2->addWidget(frame, 0, Qt::AlignLeft);

        label = new QLabel(frame_2);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);

        horizontalLayout_2->addWidget(label, 0, Qt::AlignRight);


        verticalLayout_2->addWidget(frame_2);

        usersTableView = new QTableView(accountView);
        usersTableView->setObjectName(QString::fromUtf8("usersTableView"));
        usersTableView->setStyleSheet(QString::fromUtf8("QTableView {\n"
"border: 1px solid rgba(118, 122, 142, 153);\n"
"background: rgba(224, 222, 225, 51);\n"
"selection-background-color: rgba(136, 132, 159, 204);\n"
"selection-color: rgb(248, 246, 250);\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"border-radius: 30px;\n"
"height: 30px;\n"
"color: rgb(239, 238, 241);\n"
"background: rgb(108, 104, 124);\n"
"}\n"
""));
        usersTableView->setEditTriggers(QAbstractItemView::CurrentChanged);
        usersTableView->setDragEnabled(true);

        verticalLayout_2->addWidget(usersTableView);

        stackedWidget->addWidget(accountView);
        bookView = new QWidget();
        bookView->setObjectName(QString::fromUtf8("bookView"));
        horizontalLayout_6 = new QHBoxLayout(bookView);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        widget_2 = new QWidget(bookView);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        verticalLayout_3 = new QVBoxLayout(widget_2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        frame_4 = new QFrame(widget_2);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setFrameShape(QFrame::NoFrame);
        frame_4->setFrameShadow(QFrame::Raised);
        horizontalLayout_4 = new QHBoxLayout(frame_4);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        frame_5 = new QFrame(frame_4);
        frame_5->setObjectName(QString::fromUtf8("frame_5"));
        frame_5->setFrameShape(QFrame::NoFrame);
        frame_5->setFrameShadow(QFrame::Raised);
        horizontalLayout_5 = new QHBoxLayout(frame_5);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_3 = new QLabel(frame_5);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_5->addWidget(label_3);

        searchBookBox = new QLineEdit(frame_5);
        searchBookBox->setObjectName(QString::fromUtf8("searchBookBox"));

        horizontalLayout_5->addWidget(searchBookBox);


        horizontalLayout_4->addWidget(frame_5, 0, Qt::AlignLeft);

        label_4 = new QLabel(frame_4);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);

        horizontalLayout_4->addWidget(label_4, 0, Qt::AlignLeft);


        verticalLayout_3->addWidget(frame_4);

        bookTableView = new QTableView(widget_2);
        bookTableView->setObjectName(QString::fromUtf8("bookTableView"));

        verticalLayout_3->addWidget(bookTableView);


        horizontalLayout_6->addWidget(widget_2);

        buttonWidget = new QWidget(bookView);
        buttonWidget->setObjectName(QString::fromUtf8("buttonWidget"));
        verticalLayout = new QVBoxLayout(buttonWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        addBookBtn = new QPushButton(buttonWidget);
        addBookBtn->setObjectName(QString::fromUtf8("addBookBtn"));
        addBookBtn->setMinimumSize(QSize(90, 60));
        addBookBtn->setMaximumSize(QSize(90, 60));

        verticalLayout->addWidget(addBookBtn, 0, Qt::AlignHCenter);

        deleteBookBtn = new QPushButton(buttonWidget);
        deleteBookBtn->setObjectName(QString::fromUtf8("deleteBookBtn"));
        deleteBookBtn->setMinimumSize(QSize(90, 60));
        deleteBookBtn->setMaximumSize(QSize(90, 60));

        verticalLayout->addWidget(deleteBookBtn, 0, Qt::AlignHCenter);


        horizontalLayout_6->addWidget(buttonWidget);

        stackedWidget->addWidget(bookView);

        verticalLayout_4->addWidget(stackedWidget);

        frame_3 = new QFrame(Adminstrator);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setFrameShape(QFrame::NoFrame);
        frame_3->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(frame_3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        accountManagementBtn = new QPushButton(frame_3);
        accountManagementBtn->setObjectName(QString::fromUtf8("accountManagementBtn"));

        horizontalLayout_3->addWidget(accountManagementBtn);

        bookManagementBtn = new QPushButton(frame_3);
        bookManagementBtn->setObjectName(QString::fromUtf8("bookManagementBtn"));

        horizontalLayout_3->addWidget(bookManagementBtn);

        backToLoginBtn = new QPushButton(frame_3);
        backToLoginBtn->setObjectName(QString::fromUtf8("backToLoginBtn"));

        horizontalLayout_3->addWidget(backToLoginBtn);


        verticalLayout_4->addWidget(frame_3, 0, Qt::AlignRight);


        retranslateUi(Adminstrator);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Adminstrator);
    } // setupUi

    void retranslateUi(QWidget *Adminstrator)
    {
        Adminstrator->setWindowTitle(QCoreApplication::translate("Adminstrator", "Form", nullptr));
        label_2->setText(QCoreApplication::translate("Adminstrator", "Search account", nullptr));
        label->setText(QCoreApplication::translate("Adminstrator", "* Please right click at row to change the account informations", nullptr));
        label_3->setText(QCoreApplication::translate("Adminstrator", "Search book", nullptr));
        label_4->setText(QCoreApplication::translate("Adminstrator", "Library management", nullptr));
        addBookBtn->setText(QCoreApplication::translate("Adminstrator", "Add Book", nullptr));
        deleteBookBtn->setText(QCoreApplication::translate("Adminstrator", "Delete Book", nullptr));
        accountManagementBtn->setText(QCoreApplication::translate("Adminstrator", "Account Management", nullptr));
        bookManagementBtn->setText(QCoreApplication::translate("Adminstrator", "Book Management", nullptr));
        backToLoginBtn->setText(QCoreApplication::translate("Adminstrator", "Back to Log In", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Adminstrator: public Ui_Adminstrator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINSTRATOR_H
