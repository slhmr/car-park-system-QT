#ifndef YENI_ARAC_GIRIS_H
#define YENI_ARAC_GIRIS_H

#include <QDialog>

namespace Ui {
class yeni_arac_giris;
}

class yeni_arac_giris : public QDialog
{
    Q_OBJECT
public:

    explicit yeni_arac_giris(QWidget *parent = 0);
    ~yeni_arac_giris();
public slots:
    void show();
signals:
    void loadDataS();

private slots:
    void on_yeni_arac_iptal_clicked();

    void on_yeni_arac_kaydet_clicked();

    void on_yeni_arac_yenile_clicked();
private:
    Ui::yeni_arac_giris *ui;
};

#endif // YENI_ARAC_GIRIS_H
