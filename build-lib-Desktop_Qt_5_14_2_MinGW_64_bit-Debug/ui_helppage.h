/********************************************************************************
** Form generated from reading UI file 'helppage.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELPPAGE_H
#define UI_HELPPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HelpPage
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QWidget *HelpPage)
    {
        if (HelpPage->objectName().isEmpty())
            HelpPage->setObjectName(QString::fromUtf8("HelpPage"));
        HelpPage->resize(400, 300);
        label = new QLabel(HelpPage);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 50, 300, 31));
        label_2 = new QLabel(HelpPage);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(50, 90, 300, 31));
        label_3 = new QLabel(HelpPage);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(50, 130, 300, 31));

        retranslateUi(HelpPage);

        QMetaObject::connectSlotsByName(HelpPage);
    } // setupUi

    void retranslateUi(QWidget *HelpPage)
    {
        HelpPage->setWindowTitle(QCoreApplication::translate("HelpPage", "Form", nullptr));
        label->setText(QCoreApplication::translate("HelpPage", "\347\216\251\345\256\2661\346\216\247\345\210\266\357\274\232UP\344\270\212\345\215\207DOWN\344\270\213\351\231\215LEFT\345\267\246RIGHT\345\217\263", nullptr));
        label_2->setText(QCoreApplication::translate("HelpPage", "\347\216\251\345\256\2662\346\216\247\345\210\266\357\274\232W\344\270\212\345\215\207S\344\270\213\351\231\215A\345\267\246D\345\217\263", nullptr));
        label_3->setText(QCoreApplication::translate("HelpPage", "\351\200\232\347\224\250\346\216\247\345\210\266\357\274\232ESC\351\200\200\345\207\272 P\346\232\202\345\201\234", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HelpPage: public Ui_HelpPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELPPAGE_H
