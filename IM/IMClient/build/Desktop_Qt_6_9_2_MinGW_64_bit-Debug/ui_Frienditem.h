/********************************************************************************
** Form generated from reading UI file 'Frienditem.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRIENDITEM_H
#define UI_FRIENDITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FriendItem
{
public:
    QPushButton *pb_img;
    QLabel *l_nick;
    QLabel *l_feeling;

    void setupUi(QWidget *FriendItem)
    {
        if (FriendItem->objectName().isEmpty())
            FriendItem->setObjectName("FriendItem");
        FriendItem->resize(272, 72);
        pb_img = new QPushButton(FriendItem);
        pb_img->setObjectName("pb_img");
        pb_img->setGeometry(QRect(10, 10, 50, 50));
        pb_img->setStyleSheet(QString::fromUtf8(""));
        pb_img->setIconSize(QSize(50, 50));
        l_nick = new QLabel(FriendItem);
        l_nick->setObjectName("l_nick");
        l_nick->setGeometry(QRect(70, 10, 72, 15));
        QFont font;
        font.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        l_nick->setFont(font);
        l_feeling = new QLabel(FriendItem);
        l_feeling->setObjectName("l_feeling");
        l_feeling->setGeometry(QRect(70, 40, 191, 16));
        l_feeling->setFont(font);

        retranslateUi(FriendItem);

        QMetaObject::connectSlotsByName(FriendItem);
    } // setupUi

    void retranslateUi(QWidget *FriendItem)
    {
        FriendItem->setWindowTitle(QCoreApplication::translate("FriendItem", "Form", nullptr));
        pb_img->setText(QString());
        l_nick->setText(QCoreApplication::translate("FriendItem", "TextLabel", nullptr));
        l_feeling->setText(QCoreApplication::translate("FriendItem", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FriendItem: public Ui_FriendItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRIENDITEM_H
