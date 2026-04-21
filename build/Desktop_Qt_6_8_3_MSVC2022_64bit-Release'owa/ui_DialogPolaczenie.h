/********************************************************************************
** Form generated from reading UI file 'DialogPolaczenie.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGPOLACZENIE_H
#define UI_DIALOGPOLACZENIE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_DialogPolaczenie
{
public:
    QComboBox *comboBoxRola;
    QLineEdit *lineEditIP;
    QPushButton *pushButtonOk;
    QPushButton *pushButtonAnuluj;
    QLabel *lblRola;
    QLabel *lblAdres;
    QLabel *lblAdres_2;
    QLineEdit *lineEditPort;

    void setupUi(QDialog *DialogPolaczenie)
    {
        if (DialogPolaczenie->objectName().isEmpty())
            DialogPolaczenie->setObjectName("DialogPolaczenie");
        DialogPolaczenie->resize(400, 300);
        comboBoxRola = new QComboBox(DialogPolaczenie);
        comboBoxRola->addItem(QString());
        comboBoxRola->addItem(QString());
        comboBoxRola->setObjectName("comboBoxRola");
        comboBoxRola->setGeometry(QRect(190, 40, 141, 24));
        lineEditIP = new QLineEdit(DialogPolaczenie);
        lineEditIP->setObjectName("lineEditIP");
        lineEditIP->setGeometry(QRect(200, 100, 141, 24));
        pushButtonOk = new QPushButton(DialogPolaczenie);
        pushButtonOk->setObjectName("pushButtonOk");
        pushButtonOk->setGeometry(QRect(140, 230, 80, 24));
        pushButtonAnuluj = new QPushButton(DialogPolaczenie);
        pushButtonAnuluj->setObjectName("pushButtonAnuluj");
        pushButtonAnuluj->setGeometry(QRect(280, 230, 80, 24));
        lblRola = new QLabel(DialogPolaczenie);
        lblRola->setObjectName("lblRola");
        lblRola->setGeometry(QRect(60, 40, 49, 16));
        lblAdres = new QLabel(DialogPolaczenie);
        lblAdres->setObjectName("lblAdres");
        lblAdres->setGeometry(QRect(50, 110, 101, 16));
        lblAdres_2 = new QLabel(DialogPolaczenie);
        lblAdres_2->setObjectName("lblAdres_2");
        lblAdres_2->setGeometry(QRect(50, 140, 101, 16));
        lineEditPort = new QLineEdit(DialogPolaczenie);
        lineEditPort->setObjectName("lineEditPort");
        lineEditPort->setGeometry(QRect(200, 140, 141, 24));

        retranslateUi(DialogPolaczenie);

        QMetaObject::connectSlotsByName(DialogPolaczenie);
    } // setupUi

    void retranslateUi(QDialog *DialogPolaczenie)
    {
        DialogPolaczenie->setWindowTitle(QCoreApplication::translate("DialogPolaczenie", "Dialog", nullptr));
        comboBoxRola->setItemText(0, QCoreApplication::translate("DialogPolaczenie", "Regulator (serwer)", nullptr));
        comboBoxRola->setItemText(1, QCoreApplication::translate("DialogPolaczenie", "Obiekt (klient)", nullptr));

        pushButtonOk->setText(QCoreApplication::translate("DialogPolaczenie", "Po\305\202\304\205cz", nullptr));
        pushButtonAnuluj->setText(QCoreApplication::translate("DialogPolaczenie", "Anuluj", nullptr));
        lblRola->setText(QCoreApplication::translate("DialogPolaczenie", "Rola:", nullptr));
        lblAdres->setText(QCoreApplication::translate("DialogPolaczenie", "Adres IP:", nullptr));
        lblAdres_2->setText(QCoreApplication::translate("DialogPolaczenie", "Port:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogPolaczenie: public Ui_DialogPolaczenie {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGPOLACZENIE_H
