#ifndef DBCONNECTION_H
#define DBCONNECTION_H

#include <QApplication>
#include <QSqlDatabase>
#include <QSql>
#include <QSqlError>
#include <QDir>
#include <QFile>
#include <QDebug>
#include <QSqlQuery>
#include <QString>
#include <QStringList>
#include <QSqlError>

class dbconnection
{
public:
    veritabanina_baglan();
    baglanti_kapa();
    int veri_gir(QString table, QStringList data, QStringList values);
    int veri_cek(QString select, QString table, QString where);
    int veri_guncelle(QString table, QStringList data, QStringList values, QString where);
    int veri_sil(QString table, QString where);
    QSqlQuery sql_getResults();
    QSqlError sql_getLastError();
    QSqlQuery query;
    QSqlDatabase db;
 private:
};

#endif // DBCONNECTION_H

