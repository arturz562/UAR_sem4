#ifndef DIALOGPOLACZENIE_H
#define DIALOGPOLACZENIE_H

#include <QDialog>

namespace Ui {
class DialogPolaczenie;
}

class DialogPolaczenie : public QDialog
{
    Q_OBJECT

public:
    explicit DialogPolaczenie(QWidget *parent = nullptr);
    ~DialogPolaczenie();

    bool czySerwer() const;
    QString getIP() const;
    int getPort() const;

private slots:
    void on_comboBoxRola_currentIndexChanged(int index);
    void on_pushButtonOk_clicked();
    void on_pushButtonAnuluj_clicked();

private:
    Ui::DialogPolaczenie *ui;
};

#endif // DIALOGPOLACZENIE_H
