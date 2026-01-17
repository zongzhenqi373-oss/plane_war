/********************************************************************************
** Form generated from reading UI file 'chatdig.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATDIG_H
#define UI_CHATDIG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_chatdig
{
public:
    QTextBrowser *tB_rs;
    QTextEdit *te_inword;
    QPushButton *pb_fiie;
    QPushButton *pb_emo;
    QPushButton *pb_vedio;
    QPushButton *pb_send;
    QPushButton *pb_clear;

    void setupUi(QWidget *chatdig)
    {
        if (chatdig->objectName().isEmpty())
            chatdig->setObjectName("chatdig");
        chatdig->resize(739, 478);
        tB_rs = new QTextBrowser(chatdig);
        tB_rs->setObjectName("tB_rs");
        tB_rs->setGeometry(QRect(10, 10, 721, 231));
        te_inword = new QTextEdit(chatdig);
        te_inword->setObjectName("te_inword");
        te_inword->setGeometry(QRect(10, 300, 721, 131));
        pb_fiie = new QPushButton(chatdig);
        pb_fiie->setObjectName("pb_fiie");
        pb_fiie->setGeometry(QRect(20, 260, 93, 28));
        QFont font;
        font.setFamilies({QString::fromUtf8("\345\215\216\346\226\207\346\245\267\344\275\223")});
        font.setPointSize(12);
        pb_fiie->setFont(font);
        pb_emo = new QPushButton(chatdig);
        pb_emo->setObjectName("pb_emo");
        pb_emo->setGeometry(QRect(150, 260, 93, 28));
        pb_emo->setFont(font);
        pb_vedio = new QPushButton(chatdig);
        pb_vedio->setObjectName("pb_vedio");
        pb_vedio->setGeometry(QRect(280, 260, 93, 28));
        pb_vedio->setFont(font);
        pb_send = new QPushButton(chatdig);
        pb_send->setObjectName("pb_send");
        pb_send->setGeometry(QRect(510, 440, 93, 28));
        pb_send->setFont(font);
        pb_clear = new QPushButton(chatdig);
        pb_clear->setObjectName("pb_clear");
        pb_clear->setGeometry(QRect(620, 440, 93, 28));
        pb_clear->setFont(font);

        retranslateUi(chatdig);

        QMetaObject::connectSlotsByName(chatdig);
    } // setupUi

    void retranslateUi(QWidget *chatdig)
    {
        chatdig->setWindowTitle(QCoreApplication::translate("chatdig", "Form", nullptr));
        pb_fiie->setText(QCoreApplication::translate("chatdig", "\346\226\207\344\273\266\344\274\240\350\276\223", nullptr));
        pb_emo->setText(QCoreApplication::translate("chatdig", "\350\241\250\346\203\205", nullptr));
        pb_vedio->setText(QCoreApplication::translate("chatdig", "\350\247\206\351\242\221\350\201\212\345\244\251", nullptr));
        pb_send->setText(QCoreApplication::translate("chatdig", "\345\217\221    \351\200\201", nullptr));
        pb_clear->setText(QCoreApplication::translate("chatdig", "\346\270\205    \347\251\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class chatdig: public Ui_chatdig {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATDIG_H
