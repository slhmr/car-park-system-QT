#ifndef ARAC_CIKIS_ISLEMLERI_H
#define ARAC_CIKIS_ISLEMLERI_H

#include <QDialog>

namespace Ui {
class arac_cikis_islemleri;
}

class arac_cikis_islemleri : public QDialog
{
    Q_OBJECT

public:
    explicit arac_cikis_islemleri(QWidget *parent = 0);
    ~arac_cikis_islemleri();
signals:
    void loadDataS();
private slots:
    void on_arac_bilgileri_clicked();

    void on_temizle_clicked();

    void on_arac_ciki_fisi_yazdir_clicked();

    void on_arac_cikisini_yap_clicked();

private:
    Ui::arac_cikis_islemleri *ui;
};

#endif // ARAC_CIKIS_ISLEMLERI_H
