/********************************************************************************
** Form generated from reading UI file 'pausewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAUSEWIDGET_H
#define UI_PAUSEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PauseWidget
{
public:
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *PauseWidget)
    {
        if (PauseWidget->objectName().isEmpty())
            PauseWidget->setObjectName(QString::fromUtf8("PauseWidget"));
        PauseWidget->resize(960, 880);
        label = new QLabel(PauseWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(430, 270, 81, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("Agency FB"));
        font.setPointSize(22);
        label->setFont(font);
        pushButton = new QPushButton(PauseWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(420, 350, 93, 28));
        pushButton_2 = new QPushButton(PauseWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(420, 410, 93, 28));

        retranslateUi(PauseWidget);

        QMetaObject::connectSlotsByName(PauseWidget);
    } // setupUi

    void retranslateUi(QWidget *PauseWidget)
    {
        PauseWidget->setWindowTitle(QCoreApplication::translate("PauseWidget", "Form", nullptr));
        label->setText(QCoreApplication::translate("PauseWidget", "\346\232\202\345\201\234", nullptr));
        pushButton->setText(QCoreApplication::translate("PauseWidget", "\344\277\235\345\255\230", nullptr));
        pushButton_2->setText(QCoreApplication::translate("PauseWidget", "\350\275\275\345\205\245", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PauseWidget: public Ui_PauseWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAUSEWIDGET_H
