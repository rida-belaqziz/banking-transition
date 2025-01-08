#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDate>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    // Initialiser les listes déroulantes pour la date de validité
    initializeExpiryDate();

    // Connecter les boutons aux actions
    connect(ui->pushButton_valider, &QPushButton::clicked, this, &MainWindow::on_validateButton_clicked);
    connect(ui->pushButton_annuler, &QPushButton::clicked, this, &MainWindow::on_cancelButton_clicked);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::initializeExpiryDate() {
    // Ajouter les mois (01 à 12)
    for (int i = 1; i <= 12; ++i) {
        ui->comboBox_mois->addItem(QString("%1").arg(i, 2, 10, QChar('0'))); // Format "01", "02", ...
    }

    // Ajouter les années (2023 à 2035, par exemple)
    int currentYear = QDate::currentDate().year();
    for (int i = currentYear; i <= currentYear + 12; ++i) {
        ui->comboBox_annee->addItem(QString::number(i));
    }
}

void MainWindow::on_validateButton_clicked() {
    QString cardNumber = ui->lineEdit_numCarte->text();
    QString cvv = ui->lineEdit_Crypto->text();
    QString amount = ui->lineEdit_amount->text();
    QString nom= ui->lineEdit_nomPrenom->text();

    // Récupérer la date de validité à partir des listes déroulantes
    QString expiryDate = ui->comboBox_mois->currentText() + "/" + ui->comboBox_annee->currentText();


    //ajouter des condition par rapport le size
    int maxNumcard = 17;
    int maxccv= 3;

    //Verifier le champ cardNumber et ccv est bien un chiffre
    bool isNumber = true;
    for (QChar c : cardNumber){
        if(!c.isDigit()){
            isNumber= false;
            break;
        }
    }
    for (QChar c : cvv){
        if(!c.isDigit()){
            isNumber= false;
            break;
        }

    }

    //ajouter des condition par rapport le size

    if (cardNumber.isEmpty() || cvv.isEmpty() || amount.isEmpty()) {
            QMessageBox::warning(this, "Erreur", "Veuillez remplir tous les champs !");
    }else if(!isNumber && cardNumber.length() !=maxNumcard && cvv.length() != maxccv) {
            QMessageBox::warning(this, "Erreur", "Veuillez remplir tous les champs !");
    }else {
            QMessageBox::information(this, "Succès",
            QString("Paiement validé pour un montant de %1 EUR.\nDate de validité : %2.\n Sous le nom : %3").arg(amount ,expiryDate, nom));
        }

}

void MainWindow::on_cancelButton_clicked() {
    // Réinitialiser les champs de texte et les listes déroulantes
    ui->lineEdit_numCarte->clear();
    ui->lineEdit_Crypto->clear();
    ui->lineEdit_amount->clear();

    ui->comboBox_mois->setCurrentIndex(0);
    ui->comboBox_annee->setCurrentIndex(0);
}
