/********************************************************************************
** Form generated from reading UI file 'logindia.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIA_H
#define UI_LOGINDIA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginDia
{
public:
    QLabel *l_background;
    QTabWidget *tabWidget;
    QWidget *tab_login;
    QWidget *layoutWidget_2;
    QGridLayout *gridLayout;
    QLabel *l_tel;
    QLineEdit *le_tel;
    QLabel *l_pass;
    QLineEdit *le_pass;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pb_login;
    QSpacerItem *horizontalSpacer;
    QPushButton *pb_clear;
    QWidget *tab_register;
    QWidget *layoutWidget_3;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pb_register;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pb_register_clear;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout_2;
    QLabel *l_nick;
    QLineEdit *le_nick;
    QLabel *l_register_tel;
    QLineEdit *le_register_tel;
    QLabel *l_register_pass;
    QLineEdit *le_register_pass;
    QLabel *l_pass_again;
    QLineEdit *le_pass_again;

    void setupUi(QWidget *LoginDia)
    {
        if (LoginDia->objectName().isEmpty())
            LoginDia->setObjectName("LoginDia");
        LoginDia->resize(660, 522);
        l_background = new QLabel(LoginDia);
        l_background->setObjectName("l_background");
        l_background->setGeometry(QRect(0, 0, 301, 521));
        l_background->setStyleSheet(QString::fromUtf8("\n"
"image: url(:/images/images/login.png);"));
        l_background->setPixmap(QPixmap(QString::fromUtf8(":/images/images/login.png")));
        l_background->setScaledContents(true);
        tabWidget = new QTabWidget(LoginDia);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(300, 0, 361, 521));
        QFont font;
        font.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        font.setPointSize(10);
        font.setBold(true);
        tabWidget->setFont(font);
        tabWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 255, 255);"));
        tab_login = new QWidget();
        tab_login->setObjectName("tab_login");
        layoutWidget_2 = new QWidget(tab_login);
        layoutWidget_2->setObjectName("layoutWidget_2");
        layoutWidget_2->setGeometry(QRect(20, 70, 301, 101));
        gridLayout = new QGridLayout(layoutWidget_2);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        l_tel = new QLabel(layoutWidget_2);
        l_tel->setObjectName("l_tel");
        l_tel->setMinimumSize(QSize(0, 25));
        l_tel->setMaximumSize(QSize(16777215, 25));
        l_tel->setFont(font);

        gridLayout->addWidget(l_tel, 0, 0, 1, 1);

        le_tel = new QLineEdit(layoutWidget_2);
        le_tel->setObjectName("le_tel");
        le_tel->setMinimumSize(QSize(0, 25));
        le_tel->setMaximumSize(QSize(16777215, 25));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        font1.setPointSize(10);
        le_tel->setFont(font1);

        gridLayout->addWidget(le_tel, 0, 1, 1, 1);

        l_pass = new QLabel(layoutWidget_2);
        l_pass->setObjectName("l_pass");
        l_pass->setMinimumSize(QSize(0, 25));
        l_pass->setMaximumSize(QSize(16777215, 25));
        l_pass->setFont(font);
        l_pass->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(l_pass, 1, 0, 1, 1);

        le_pass = new QLineEdit(layoutWidget_2);
        le_pass->setObjectName("le_pass");
        le_pass->setMinimumSize(QSize(0, 25));
        le_pass->setMaximumSize(QSize(16777215, 25));
        le_pass->setFont(font1);
        le_pass->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(le_pass, 1, 1, 1, 1);

        layoutWidget = new QWidget(tab_login);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(50, 220, 266, 41));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pb_login = new QPushButton(layoutWidget);
        pb_login->setObjectName("pb_login");
        pb_login->setMaximumSize(QSize(100, 30));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("\345\256\213\344\275\223")});
        font2.setPointSize(11);
        font2.setBold(true);
        pb_login->setFont(font2);
        pb_login->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(pb_login);

        horizontalSpacer = new QSpacerItem(100, 25, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pb_clear = new QPushButton(layoutWidget);
        pb_clear->setObjectName("pb_clear");
        pb_clear->setMaximumSize(QSize(100, 30));
        pb_clear->setFont(font2);
        pb_clear->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(pb_clear);

        tabWidget->addTab(tab_login, QString());
        tab_register = new QWidget();
        tab_register->setObjectName("tab_register");
        layoutWidget_3 = new QWidget(tab_register);
        layoutWidget_3->setObjectName("layoutWidget_3");
        layoutWidget_3->setGeometry(QRect(40, 260, 274, 41));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget_3);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        pb_register = new QPushButton(layoutWidget_3);
        pb_register->setObjectName("pb_register");
        pb_register->setMaximumSize(QSize(100, 30));
        pb_register->setFont(font2);
        pb_register->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_2->addWidget(pb_register);

        horizontalSpacer_2 = new QSpacerItem(100, 25, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        pb_register_clear = new QPushButton(layoutWidget_3);
        pb_register_clear->setObjectName("pb_register_clear");
        pb_register_clear->setMaximumSize(QSize(100, 30));
        pb_register_clear->setFont(font2);
        pb_register_clear->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_2->addWidget(pb_register_clear);

        layoutWidget1 = new QWidget(tab_register);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(30, 60, 291, 161));
        gridLayout_2 = new QGridLayout(layoutWidget1);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        l_nick = new QLabel(layoutWidget1);
        l_nick->setObjectName("l_nick");
        l_nick->setMinimumSize(QSize(0, 25));
        l_nick->setMaximumSize(QSize(16777215, 25));
        l_nick->setFont(font);
        l_nick->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(l_nick, 0, 0, 1, 1);

        le_nick = new QLineEdit(layoutWidget1);
        le_nick->setObjectName("le_nick");
        le_nick->setMinimumSize(QSize(0, 25));
        le_nick->setMaximumSize(QSize(16777215, 25));
        le_nick->setFont(font1);

        gridLayout_2->addWidget(le_nick, 0, 1, 1, 1);

        l_register_tel = new QLabel(layoutWidget1);
        l_register_tel->setObjectName("l_register_tel");
        l_register_tel->setMinimumSize(QSize(0, 25));
        l_register_tel->setMaximumSize(QSize(16777215, 25));
        l_register_tel->setFont(font);
        l_register_tel->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(l_register_tel, 1, 0, 1, 1);

        le_register_tel = new QLineEdit(layoutWidget1);
        le_register_tel->setObjectName("le_register_tel");
        le_register_tel->setMinimumSize(QSize(0, 25));
        le_register_tel->setMaximumSize(QSize(16777215, 25));
        le_register_tel->setFont(font1);

        gridLayout_2->addWidget(le_register_tel, 1, 1, 1, 1);

        l_register_pass = new QLabel(layoutWidget1);
        l_register_pass->setObjectName("l_register_pass");
        l_register_pass->setMinimumSize(QSize(0, 25));
        l_register_pass->setMaximumSize(QSize(16777215, 25));
        l_register_pass->setFont(font);
        l_register_pass->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(l_register_pass, 2, 0, 1, 1);

        le_register_pass = new QLineEdit(layoutWidget1);
        le_register_pass->setObjectName("le_register_pass");
        le_register_pass->setMinimumSize(QSize(0, 25));
        le_register_pass->setMaximumSize(QSize(16777215, 25));
        le_register_pass->setFont(font1);
        le_register_pass->setEchoMode(QLineEdit::Password);

        gridLayout_2->addWidget(le_register_pass, 2, 1, 1, 1);

        l_pass_again = new QLabel(layoutWidget1);
        l_pass_again->setObjectName("l_pass_again");
        l_pass_again->setMinimumSize(QSize(0, 25));
        l_pass_again->setMaximumSize(QSize(16777215, 25));
        l_pass_again->setFont(font);
        l_pass_again->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(l_pass_again, 3, 0, 1, 1);

        le_pass_again = new QLineEdit(layoutWidget1);
        le_pass_again->setObjectName("le_pass_again");
        le_pass_again->setMinimumSize(QSize(0, 25));
        le_pass_again->setMaximumSize(QSize(16777215, 25));
        le_pass_again->setFont(font1);
        le_pass_again->setEchoMode(QLineEdit::Password);

        gridLayout_2->addWidget(le_pass_again, 3, 1, 1, 1);

        tabWidget->addTab(tab_register, QString());

        retranslateUi(LoginDia);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(LoginDia);
    } // setupUi

    void retranslateUi(QWidget *LoginDia)
    {
        LoginDia->setWindowTitle(QCoreApplication::translate("LoginDia", "\347\231\273\345\275\225/\346\263\250\345\206\214", nullptr));
        l_background->setText(QString());
        l_tel->setText(QCoreApplication::translate("LoginDia", " \346\211\213\346\234\272\345\217\267\357\274\232", nullptr));
        le_tel->setText(QCoreApplication::translate("LoginDia", "18846101240", nullptr));
        l_pass->setText(QCoreApplication::translate("LoginDia", "\345\257\206   \347\240\201\357\274\232", nullptr));
        le_pass->setText(QCoreApplication::translate("LoginDia", "123456", nullptr));
        pb_login->setText(QCoreApplication::translate("LoginDia", "\347\231\273   \345\275\225", nullptr));
        pb_clear->setText(QCoreApplication::translate("LoginDia", "\346\270\205   \347\251\272", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_login), QCoreApplication::translate("LoginDia", "\347\231\273\345\275\225", nullptr));
        pb_register->setText(QCoreApplication::translate("LoginDia", "\346\263\250    \345\206\214", nullptr));
        pb_register_clear->setText(QCoreApplication::translate("LoginDia", "\346\270\205   \347\251\272", nullptr));
        l_nick->setText(QCoreApplication::translate("LoginDia", "\346\230\265  \347\247\260\357\274\232", nullptr));
        le_nick->setText(QCoreApplication::translate("LoginDia", "111222", nullptr));
        l_register_tel->setText(QCoreApplication::translate("LoginDia", "\346\211\213\346\234\272\345\217\267\357\274\232", nullptr));
        le_register_tel->setText(QCoreApplication::translate("LoginDia", "18846101240", nullptr));
        l_register_pass->setText(QCoreApplication::translate("LoginDia", "\345\257\206   \347\240\201\357\274\232", nullptr));
        le_register_pass->setText(QCoreApplication::translate("LoginDia", "123456", nullptr));
        l_pass_again->setText(QCoreApplication::translate("LoginDia", "\347\241\256\350\256\244\345\257\206\347\240\201\357\274\232", nullptr));
        le_pass_again->setText(QCoreApplication::translate("LoginDia", "123456", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_register), QCoreApplication::translate("LoginDia", "\346\263\250\345\206\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginDia: public Ui_LoginDia {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIA_H
