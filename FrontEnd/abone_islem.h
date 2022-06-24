#ifndef ABONE_ISLEM_H
#define ABONE_ISLEM_H

#include <QDialog>

#include "FrontEnd/dbconnection.h"
#include <QValidator>
#include <QDateTime>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QSqlQuery>

namespace Ui {
class abone_islem;
}

class abone_islem : public QDialog
{
    Q_OBJECT

public:
    explicit abone_islem(QWidget *parent = 0);
    ~abone_islem();

    void loadData(dbconnection conn);

signals:
    void loadDataSet();

private slots:
    void on_yeniabone_clicked();

    void on_cikis_clicked();

    void on_aboneduzenle_clicked();


    void on_abonetablosu_activated(const QModelIndex &index);

    void on_abonesil_clicked();

    void loadData();
private:
    Ui::abone_islem *ui;
    QSqlQueryModel *modal;

    dbconnection conn;
};

#endif // ABONE_ISLEM_H
