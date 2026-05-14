#include "ParametryARX.h"
#include "ui_ParametryARX.h"
#include <QMessageBox>
#include <QStringList>

ParametryARX::ParametryARX(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ParametryARX)
{
    ui->setupUi(this);

    // --- ARX ---
    ui->spinOpoznienie->setRange(1, 20);      ui->spinOpoznienie->setSingleStep(1);
    ui->spinZaklocenie->setRange(0.0, 0.1);   ui->spinZaklocenie->setSingleStep(0.01);


    ui->spinMinU->setRange(-100.0, 100.0);    ui->spinMinU->setSingleStep(1.0);
    ui->spinMaxU->setRange(-100.0, 100.0);    ui->spinMaxU->setSingleStep(1.0);
    ui->spinMinY->setRange(-100.0, 100.0);    ui->spinMinY->setSingleStep(1.0);
    ui->spinMaxY->setRange(-100.0, 100.0);    ui->spinMaxY->setSingleStep(1.0);
}

ParametryARX::~ParametryARX()
{
    delete ui;
}

void ParametryARX::ustawDane(const std::vector<double>& a, const std::vector<double>& b,
                             int opoznienie, double szum,
                             double umin, double umax, double ymin, double ymax)
{
    QString strA = vectorToString(a);
    QString strB = vectorToString(b);

    ui->editA->setText(strA);
    ui->editB->setText(strB);
    ui->spinOpoznienie->setValue(opoznienie);

    if (ui->spinZaklocenie) {
        ui->spinZaklocenie->setValue(szum);
    }

    //
    if (umin <= std::numeric_limits<double>::min() && ymin <= std::numeric_limits<double>::min() && umax >= std::numeric_limits<double>::max() && ymax <= std::numeric_limits<double>::max())   {
        ui->checkOgraniczenia->setChecked(false);
    }
    else ui->checkOgraniczenia->setChecked(true);
    //

    ui->spinMinU->setValue(umin);
    ui->spinMaxU->setValue(umax);
    ui->spinMinY->setValue(ymin);
    ui->spinMaxY->setValue(ymax);

    if (ui->labelCurrentSummary) {
        QString info = QString("Obecne: A:[%1] B:[%2] k:%3 Szum:%4")
        .arg(strA).arg(strB).arg(opoznienie).arg(szum);
        ui->labelCurrentSummary->setText(info);
    }

    //ui->checkOgraniczenia->
}

void ParametryARX::on_pushZapisz_clicked()
{
    std::vector<double> tempA = stringToVector(ui->editA->text());
    std::vector<double> tempB = stringToVector(ui->editB->text());

    while (tempA.size() < 3) tempA.push_back(0.0);
    while (tempB.size() < 3) tempB.push_back(0.0);

    int opoznienie = ui->spinOpoznienie->value();
    double szum = (ui->spinZaklocenie) ? ui->spinZaklocenie->value() : 0.0;
    double uMin;// = ui->spinMinU->value();
    double uMax;// = ui->spinMaxU->value();
    double yMin;// = ui->spinMinY->value();
    double yMax;// = ui->spinMaxY->value();

    // wartości min < wartości max


    if (ui->checkOgraniczenia->isChecked()) {
        uMin = ui->spinMinU->value();
        uMax = ui->spinMaxU->value();
        yMin = ui->spinMinY->value();
        yMax = ui->spinMaxY->value();
    } else {
        // Symulacja braku ograniczeń (ogromne limity)
        uMin = std::numeric_limits<double>::min(); uMax = std::numeric_limits<double>::max();
        yMin = std::numeric_limits<double>::min(); yMax = std::numeric_limits<double>::max();
    }

    if (uMin >= uMax) {
        QMessageBox::warning(this, "Błąd", "Nasycenie wejścia: Min U musi być mniejsze od Max U!");
        return;
    }
    if (yMin >= yMax) {
        QMessageBox::warning(this, "Błąd", "Nasycenie wyjścia: Min Y musi być mniejsze od Max Y!");
        return;
    }


    emit zglosNoweParametry(tempA, tempB, opoznienie, szum, uMin, uMax, yMin, yMax);
    this->accept();
}

void ParametryARX::on_pushAnuluj_clicked()
{
    this->reject();
}

std::vector<double> ParametryARX::stringToVector(const QString& str) const
{
    std::vector<double> vec;
    QStringList list = str.split(' ', Qt::SkipEmptyParts);

    for(const QString& s : list) {
        QString tempS = s;
        tempS.replace(",", ".");
        bool ok;
        double val = tempS.toDouble(&ok);
        if(ok) {
            // zakres: <-2.0, 2.0>
            val = std::clamp(val, -2.0, 2.0);
            vec.push_back(val);
        }
    }
    return vec;
}

QString ParametryARX::vectorToString(const std::vector<double>& vec) const
{
    QStringList list;
    for(double d : vec) list << QString::number(d);
    return list.join(' ');
}
