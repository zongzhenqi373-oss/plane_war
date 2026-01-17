/********************************************************************************
** Form generated from reading UI file 'mainwdiget.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWDIGET_H
#define UI_MAINWDIGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mainwdiget
{
public:
    QPushButton *pb_img;
    QLabel *l_nick;
    QLineEdit *le_feeling;
    QTabWidget *tabWidget;
    QWidget *tab_space;
    QWidget *tab_friend;
    QListWidget *lw_friendlist;
    QWidget *tab_massage;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pb_menu;
    QPushButton *pb_func1;
    QPushButton *pb_func2;
    QPushButton *pb_func3;

    void setupUi(QWidget *mainwdiget)
    {
        if (mainwdiget->objectName().isEmpty())
            mainwdiget->setObjectName("mainwdiget");
        mainwdiget->resize(348, 635);
        pb_img = new QPushButton(mainwdiget);
        pb_img->setObjectName("pb_img");
        pb_img->setGeometry(QRect(10, 10, 60, 60));
        pb_img->setMinimumSize(QSize(60, 60));
        pb_img->setMaximumSize(QSize(60, 60));
        pb_img->setStyleSheet(QString::fromUtf8(""));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/tx/30.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pb_img->setIcon(icon);
        pb_img->setIconSize(QSize(60, 60));
        l_nick = new QLabel(mainwdiget);
        l_nick->setObjectName("l_nick");
        l_nick->setGeometry(QRect(80, 10, 71, 16));
        le_feeling = new QLineEdit(mainwdiget);
        le_feeling->setObjectName("le_feeling");
        le_feeling->setEnabled(false);
        le_feeling->setGeometry(QRect(80, 40, 141, 21));
        tabWidget = new QTabWidget(mainwdiget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(10, 90, 331, 471));
        QFont font;
        font.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        font.setPointSize(10);
        font.setBold(true);
        tabWidget->setFont(font);
        tab_space = new QWidget();
        tab_space->setObjectName("tab_space");
        tabWidget->addTab(tab_space, QString());
        tab_friend = new QWidget();
        tab_friend->setObjectName("tab_friend");
        lw_friendlist = new QListWidget(tab_friend);
        lw_friendlist->setObjectName("lw_friendlist");
        lw_friendlist->setGeometry(QRect(0, 0, 331, 441));
        tabWidget->addTab(tab_friend, QString());
        tab_massage = new QWidget();
        tab_massage->setObjectName("tab_massage");
        tabWidget->addTab(tab_massage, QString());
        layoutWidget = new QWidget(mainwdiget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 580, 323, 31));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pb_menu = new QPushButton(layoutWidget);
        pb_menu->setObjectName("pb_menu");

        horizontalLayout->addWidget(pb_menu);

        pb_func1 = new QPushButton(layoutWidget);
        pb_func1->setObjectName("pb_func1");

        horizontalLayout->addWidget(pb_func1);

        pb_func2 = new QPushButton(layoutWidget);
        pb_func2->setObjectName("pb_func2");

        horizontalLayout->addWidget(pb_func2);

        pb_func3 = new QPushButton(layoutWidget);
        pb_func3->setObjectName("pb_func3");

        horizontalLayout->addWidget(pb_func3);


        retranslateUi(mainwdiget);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(mainwdiget);
    } // setupUi

    void retranslateUi(QWidget *mainwdiget)
    {
        mainwdiget->setWindowTitle(QCoreApplication::translate("mainwdiget", "QQ\350\201\212\345\244\251", nullptr));
        pb_img->setText(QString());
        l_nick->setText(QCoreApplication::translate("mainwdiget", "\346\230\265\347\247\260", nullptr));
        le_feeling->setText(QCoreApplication::translate("mainwdiget", "\344\270\252\344\272\272\347\255\276\345\220\215", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_space), QCoreApplication::translate("mainwdiget", "\347\251\272\351\227\264", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_friend), QCoreApplication::translate("mainwdiget", "\346\234\213\345\217\213", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_massage), QCoreApplication::translate("mainwdiget", "\346\266\210\346\201\257", nullptr));
        pb_menu->setText(QCoreApplication::translate("mainwdiget", " \350\217\234\345\215\225", nullptr));
        pb_func1->setText(QCoreApplication::translate("mainwdiget", " \345\212\237\350\203\2751", nullptr));
        pb_func2->setText(QCoreApplication::translate("mainwdiget", "\345\212\237\350\203\2752", nullptr));
        pb_func3->setText(QCoreApplication::translate("mainwdiget", " \345\212\237\350\203\2753", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mainwdiget: public Ui_mainwdiget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWDIGET_H
