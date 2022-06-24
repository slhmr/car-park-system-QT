#ifndef ULGNPNLFORMU_H
#define ULGNPNLFORMU_H

#include <QDialog>
#include"otoparku.h"

#include <QString>
#include <QStandardPaths>
#include <QMessageBox>

#include <QDebug>
#include <QDir>

#include <QtSql>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QSqlQuery>


namespace Ui {
class ULgnPnlFormu;
}

class ULgnPnlFormu : public QDialog
{
    Q_OBJECT

public:
    explicit ULgnPnlFormu(QWidget *parent = 0);
    ~ULgnPnlFormu();

private slots:


    void on_giris_yap_clicked();

    void on_cikis_yap_clicked();

private:
    Ui::ULgnPnlFormu *ui;
    OtoparkU *Otopark;

};

#endif // ULGNPNLFORMU_H
