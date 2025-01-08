/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *titre;
    QLabel *num_carte;
    QLabel *date_fin;
    QLabel *Crypto;
    QLineEdit *lineEdit_numCarte;
    QLineEdit *lineEdit_Crypto;
    QPushButton *pushButton_annuler;
    QPushButton *pushButton_valider;
    QPushButton *pushButton_Retour;
    QComboBox *comboBox_mois;
    QComboBox *comboBox_annee;
    QLabel *amount;
    QLineEdit *lineEdit_amount;
    QLabel *line;
    QLabel *nomPrenom;
    QLineEdit *lineEdit_nomPrenom;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        titre = new QLabel(centralwidget);
        titre->setObjectName("titre");
        titre->setGeometry(QRect(340, 0, 101, 16));
        num_carte = new QLabel(centralwidget);
        num_carte->setObjectName("num_carte");
        num_carte->setGeometry(QRect(77, 170, 201, 20));
        date_fin = new QLabel(centralwidget);
        date_fin->setObjectName("date_fin");
        date_fin->setGeometry(QRect(67, 220, 211, 20));
        Crypto = new QLabel(centralwidget);
        Crypto->setObjectName("Crypto");
        Crypto->setGeometry(QRect(77, 270, 201, 20));
        lineEdit_numCarte = new QLineEdit(centralwidget);
        lineEdit_numCarte->setObjectName("lineEdit_numCarte");
        lineEdit_numCarte->setGeometry(QRect(320, 170, 113, 21));
        lineEdit_Crypto = new QLineEdit(centralwidget);
        lineEdit_Crypto->setObjectName("lineEdit_Crypto");
        lineEdit_Crypto->setGeometry(QRect(310, 270, 113, 21));
        pushButton_annuler = new QPushButton(centralwidget);
        pushButton_annuler->setObjectName("pushButton_annuler");
        pushButton_annuler->setGeometry(QRect(250, 400, 100, 32));
        pushButton_valider = new QPushButton(centralwidget);
        pushButton_valider->setObjectName("pushButton_valider");
        pushButton_valider->setGeometry(QRect(400, 400, 100, 32));
        pushButton_Retour = new QPushButton(centralwidget);
        pushButton_Retour->setObjectName("pushButton_Retour");
        pushButton_Retour->setGeometry(QRect(260, 470, 241, 32));
        comboBox_mois = new QComboBox(centralwidget);
        comboBox_mois->setObjectName("comboBox_mois");
        comboBox_mois->setGeometry(QRect(310, 220, 61, 32));
        comboBox_annee = new QComboBox(centralwidget);
        comboBox_annee->setObjectName("comboBox_annee");
        comboBox_annee->setGeometry(QRect(380, 220, 91, 32));
        amount = new QLabel(centralwidget);
        amount->setObjectName("amount");
        amount->setGeometry(QRect(80, 40, 111, 16));
        lineEdit_amount = new QLineEdit(centralwidget);
        lineEdit_amount->setObjectName("lineEdit_amount");
        lineEdit_amount->setGeometry(QRect(300, 40, 113, 21));
        line = new QLabel(centralwidget);
        line->setObjectName("line");
        line->setGeometry(QRect(70, 110, 631, 16));
        nomPrenom = new QLabel(centralwidget);
        nomPrenom->setObjectName("nomPrenom");
        nomPrenom->setGeometry(QRect(80, 80, 101, 16));
        lineEdit_nomPrenom = new QLineEdit(centralwidget);
        lineEdit_nomPrenom->setObjectName("lineEdit_nomPrenom");
        lineEdit_nomPrenom->setGeometry(QRect(300, 80, 113, 21));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 24));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        titre->setText(QCoreApplication::translate("MainWindow", "Paiement", nullptr));
        num_carte->setText(QCoreApplication::translate("MainWindow", "Numero de carte", nullptr));
        date_fin->setText(QCoreApplication::translate("MainWindow", "date de fin validit\303\251 (MM/AA)", nullptr));
        Crypto->setText(QCoreApplication::translate("MainWindow", "Cryptogramme visuel ", nullptr));
        pushButton_annuler->setText(QCoreApplication::translate("MainWindow", "Annuler", nullptr));
        pushButton_valider->setText(QCoreApplication::translate("MainWindow", "Valider", nullptr));
        pushButton_Retour->setText(QCoreApplication::translate("MainWindow", "Retour moyens de paiement", nullptr));
        amount->setText(QCoreApplication::translate("MainWindow", "Montant a payer", nullptr));
        line->setText(QCoreApplication::translate("MainWindow", "=============================================================================", nullptr));
        nomPrenom->setText(QCoreApplication::translate("MainWindow", "Nom et Prenom", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
