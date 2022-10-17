/********************************************************************************
** Form generated from reading UI file 'startpage.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTPAGE_H
#define UI_STARTPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StartPage
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;

    void setupUi(QWidget *StartPage)
    {
        if (StartPage->objectName().isEmpty())
            StartPage->setObjectName(QString::fromUtf8("StartPage"));
        StartPage->resize(960, 880);
        pushButton = new QPushButton(StartPage);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(410, 350, 93, 28));
        pushButton_2 = new QPushButton(StartPage);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(410, 390, 93, 28));
        label = new QLabel(StartPage);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(410, 260, 111, 81));
        QFont font;
        font.setFamily(QString::fromUtf8("\350\213\271\346\226\271-\347\256\200"));
        font.setPointSize(22);
        label->setFont(font);
        pushButton_3 = new QPushButton(StartPage);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(410, 510, 93, 28));
        pushButton_4 = new QPushButton(StartPage);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(410, 430, 93, 28));
        pushButton_5 = new QPushButton(StartPage);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(410, 470, 93, 28));

        retranslateUi(StartPage);

        QMetaObject::connectSlotsByName(StartPage);
    } // setupUi

    void retranslateUi(QWidget *StartPage)
    {
        StartPage->setWindowTitle(QCoreApplication::translate("StartPage", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("StartPage", "\345\215\225\344\272\272\346\250\241\345\274\217", nullptr));
        pushButton_2->setText(QCoreApplication::translate("StartPage", "\345\217\214\344\272\272\346\250\241\345\274\217", nullptr));
        label->setText(QCoreApplication::translate("StartPage", "QLink", nullptr));
        pushButton_3->setText(QCoreApplication::translate("StartPage", "\351\200\200\345\207\272\346\270\270\346\210\217", nullptr));
        pushButton_4->setText(QCoreApplication::translate("StartPage", "\350\275\275\345\205\245\346\270\270\346\210\217", nullptr));
        pushButton_5->setText(QCoreApplication::translate("StartPage", "\345\270\256\345\212\251", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StartPage: public Ui_StartPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTPAGE_H
