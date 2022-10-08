/********************************************************************************
** Form generated from reading UI file 'endpage.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENDPAGE_H
#define UI_ENDPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EndPage
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QWidget *EndPage)
    {
        if (EndPage->objectName().isEmpty())
            EndPage->setObjectName(QString::fromUtf8("EndPage"));
        EndPage->resize(400, 300);
        label = new QLabel(EndPage);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(140, 50, 121, 61));
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(EndPage);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(150, 120, 141, 31));
        label_3 = new QLabel(EndPage);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(150, 170, 141, 41));

        retranslateUi(EndPage);

        QMetaObject::connectSlotsByName(EndPage);
    } // setupUi

    void retranslateUi(QWidget *EndPage)
    {
        EndPage->setWindowTitle(QCoreApplication::translate("EndPage", "Form", nullptr));
        label->setText(QCoreApplication::translate("EndPage", "\346\270\270\346\210\217\347\273\223\346\235\237\357\274\201", nullptr));
        label_2->setText(QString());
        label_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class EndPage: public Ui_EndPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENDPAGE_H
