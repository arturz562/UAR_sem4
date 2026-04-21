#include "DialogPolaczenie.h"
#include "ui_DialogPolaczenie.h"

DialogPolaczenie::DialogPolaczenie(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogPolaczenie)
{
    ui->setupUi(this);

    // Inicjalne ustawienie dostępności pola IP (zależnie od tego co jest wybrane domyślnie w .ui)
    ui->lineEditIP->setEnabled(ui->comboBoxRola->currentIndex() != 0);
}

DialogPolaczenie::~DialogPolaczenie()
{
    delete ui;
}

bool DialogPolaczenie::czySerwer() const
{
    // Zakładamy, że index 0 w ComboBox to "Regulator (Serwer)", a index 1 to "Obiekt (Klient)"
    return ui->comboBoxRola->currentIndex() == 0;
}

QString DialogPolaczenie::getIP() const
{
    return ui->lineEditIP->text();
}

int DialogPolaczenie::getPort() const
{
    return ui->lineEditPort->text().toInt();
}

void DialogPolaczenie::on_comboBoxRola_currentIndexChanged(int index)
{
    // Jeśli wybrano Serwer (index == 0), pole IP jest niepotrzebne (nasłuchujemy na wszystkich)
    ui->lineEditIP->setEnabled(index != 0);
}

void DialogPolaczenie::on_pushButtonOk_clicked()
{
    this->accept();
}

void DialogPolaczenie::on_pushButtonAnuluj_clicked()
{
    this->reject();
}