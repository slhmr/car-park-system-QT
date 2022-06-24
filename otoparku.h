#ifndef OTOPARKU_H
#define OTOPARKU_H

#include <QtSql>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QMainWindow>
#include "FrontEnd/yeni_arac_giris.h"
#include "FrontEnd/konum.h"
#include "FrontEnd/abone_islem.h"
#include "FrontEnd/arac_cikis_islemleri.h"
#include "FrontEnd/dbconnection.h"
#include "FrontEnd/abouthak.h"

namespace Ui {
class OtoparkU;
}

class OtoparkU : public QMainWindow
{
    Q_OBJECT
public:
    bool otoparkkonumyukle(){
        QSqlQuery sorgu;
        sorgu.prepare( "CREATE TABLE IF NOT EXISTS otopark ("
                       "oid INTEGER UNIQUE PRIMARY KEY AUTOINCREMENT,"
                       "oname VARCHAR(60),"
                       "ostatus VARCHAR(60))" );
        if( !sorgu.exec() ){
            qDebug() <<sorgu.lastError();
            return false;
        }
        else{
            qDebug() <<"Otopark Konumlar Tablosu oluşturuldu...";
            int rows = 0;
            QSqlQuery sorgu("SELECT COUNT(*) FROM otopark");
            if (sorgu.next()) {
                rows = sorgu.value(0).toInt();
                if(rows<=0){
                    sorgu.prepare( "INSERT INTO otopark (oid, oname, ostatus) VALUES (1, 'A1', 'Bos')" );sorgu.exec();
                    sorgu.prepare( "INSERT INTO otopark (oid, oname, ostatus) VALUES (2, 'A2' , 'Bos')" );sorgu.exec();
                    sorgu.prepare( "INSERT INTO otopark (oid, oname, ostatus) VALUES (3, 'A3' , 'Bos')" );sorgu.exec();
                    sorgu.prepare( "INSERT INTO otopark (oid, oname, ostatus) VALUES (4, 'A4' , 'Bos')" );sorgu.exec();
                    sorgu.prepare( "INSERT INTO otopark (oid, oname, ostatus) VALUES (5, 'A5' , 'Bos')" );sorgu.exec();
                    sorgu.prepare( "INSERT INTO otopark (oid, oname, ostatus) VALUES (6, 'A6' , 'Bos')" );sorgu.exec();
                    sorgu.prepare( "INSERT INTO otopark (oid, oname, ostatus) VALUES (7, 'B1' , 'Bos')" );sorgu.exec();
                    sorgu.prepare( "INSERT INTO otopark (oid, oname, ostatus) VALUES (8, 'B2' , 'Bos')" );sorgu.exec();
                    sorgu.prepare( "INSERT INTO otopark (oid, oname, ostatus) VALUES (9, 'B3' , 'Bos')" );sorgu.exec();
                    sorgu.prepare( "INSERT INTO otopark (oid, oname, ostatus) VALUES (10, 'B4' , 'Bos')" );sorgu.exec();
                    sorgu.prepare( "INSERT INTO otopark (oid, oname, ostatus) VALUES (11, 'B5' , 'Bos')" );sorgu.exec();
                    sorgu.prepare( "INSERT INTO otopark (oid, oname, ostatus) VALUES (12, 'B6' , 'Bos')" );sorgu.exec();
                    }
                 }
           return true;
        }
    }
    bool otoparksureyukle(){
            QSqlQuery sorgu;
            sorgu.prepare( "CREATE TABLE IF NOT EXISTS otoparktime ("
                           "tid INTEGER UNIQUE PRIMARY KEY AUTOINCREMENT,"
                           "tsure VARCHAR(60),"
                           "tucret VARCHAR(60))" );
            if( !sorgu.exec() ){
                qDebug() <<sorgu.lastError();
                return false;
            }
            else{
                qDebug() <<"Otopark park süre Tablosu oluşturuldu...";
                int rows = 0;
                QSqlQuery sorgu("SELECT COUNT(*) FROM otoparktime");
                if (sorgu.next()) {
                    rows = sorgu.value(0).toInt();
                    if(rows<=0){
                        sorgu.prepare( "INSERT INTO otoparktime (tid, tsure, tucret) VALUES (1, '0-1 Saat', '6.00')" );sorgu.exec();
                        sorgu.prepare( "INSERT INTO otoparktime (tid, tsure, tucret) VALUES (2, '1-3 Saat' , '7.50')" );sorgu.exec();
                        sorgu.prepare( "INSERT INTO otoparktime (tid, tsure, tucret) VALUES (3, '3-6 Saat' , '10.00')" );sorgu.exec();
                        sorgu.prepare( "INSERT INTO otoparktime (tid, tsure, tucret) VALUES (4, '6-12 Saat' , '12.50')" );sorgu.exec();
                        sorgu.prepare( "INSERT INTO otoparktime (tid, tsure, tucret) VALUES (5, '12-24 Saat' , '15.00')" );sorgu.exec();
                        sorgu.prepare( "INSERT INTO otoparktime (tid, tsure, tucret) VALUES (6, '4 Gün' , '50.00')" );sorgu.exec();
                        sorgu.prepare( "INSERT INTO otoparktime (tid, tsure, tucret) VALUES (7, '7 Gün' , '85.00')" );sorgu.exec();
                        sorgu.prepare( "INSERT INTO otoparktime (tid, tsure, tucret) VALUES (8, '15 Gün' , '150.00')" );sorgu.exec();
                        sorgu.prepare( "INSERT INTO otoparktime (tid, tsure, tucret) VALUES (9, '1 Ay' , '200.00')" );sorgu.exec();

                        }
                     }
               return true;
            }
        }
    bool veritabani_kul_kontrol(){
            QSqlQuery sorgu;
            sorgu.prepare( "CREATE TABLE IF NOT EXISTS user (uid INTEGER UNIQUE PRIMARY KEY AUTOINCREMENT, uname VARCHAR(60), upass VARCHAR(60),umail VARCHAR(60))" );
            if( !sorgu.exec() ){
                qDebug() <<sorgu.lastError();
                return false;
            }
            else{
                qDebug() <<"Kullanıcılar Tablosu oluşturuldu...";
                int rows = 0;
                QSqlQuery sorgu("SELECT COUNT(*) FROM user");
                if (sorgu.next()) {
                    rows = sorgu.value(0).toInt();
                    if(rows<=0){
                        sorgu.prepare( "INSERT INTO user (uid, uname, upass, umail) VALUES (1, '1', '1', '2@2.2')" );
                        if( !sorgu.exec() )
                            qDebug() <<sorgu.lastError();
                        else
                            qDebug() <<"Veri Eklendi...";
                        }
                     }
               return true;
            }
        }
    void veritabani_tablo_kontrol(){
            QSqlQuery sorgu;
            sorgu.prepare( "CREATE TABLE IF NOT EXISTS customers ("
                           "cid INTEGER UNIQUE PRIMARY KEY AUTOINCREMENT, "
                           "cidno VARCHAR(60),"
                           "cname VARCHAR(60), "
                           "csurname VARCHAR(60),"
                           "cphone VARCHAR(60),"
                           "ccplate VARCHAR(60),"
                           "ccbrandmodel VARCHAR(60),"
                           "cccolor VARCHAR(60),"
                           "cclocation VARCHAR(60),"
                           "ctime VARCHAR(60),"
                           "caddtime TIMESTAMP,"
                           "cexit TIMESTAMP,"
                           "cfee VARCHAR(80),"
                           "cstatus VARCHAR(20))" );
            if( !sorgu.exec() )
                qDebug() <<sorgu.lastError();
            else
                qDebug() <<"Müşteri Tablosu oluşturuldu...";

            sorgu.prepare( "CREATE TABLE IF NOT EXISTS subscriber ("
                           "sid INTEGER UNIQUE PRIMARY KEY AUTOINCREMENT, "
                           "sidno VARCHAR(60),"
                           "sname VARCHAR(60), "
                           "ssurname VARCHAR(60),"
                           "sphone VARCHAR(60),"
                           "scplate VARCHAR(60),"
                           "scbrand VARCHAR(60),"
                           "scmodel VARCHAR(60),"
                           "sccolor VARCHAR(60),"
                           "stime VARCHAR(60),"
                           "sminute VARCHAR(60),"
                           "saddtime TIMESTAMP,"
                           "sexit TIMESTAMP,"
                           "sfee VARCHAR(80))");
            if( !sorgu.exec() )
                qDebug() <<sorgu.lastError();
            else
                qDebug() <<"Aboneler Tablosu oluşturuldu...";
            }
public:
    explicit OtoparkU(QWidget *parent = 0);
    ~OtoparkU();

public slots:
    void loadData();
    void aboneyukle();
private slots:
    void on_yeniaracgiris_clicked();
    void saati_goster();
    void on_konum_clicked();
    void on_abone_islemleri_clicked();   
    void on_arac_cikis_clicked();
    void on_hakkimizda_clicked();
    void on_hizmetler_clicked();
    void on_fiyat_tarifesi_clicked();
    void on_FormCikis_clicked();

private:
    Ui::OtoparkU *ui;
    QSqlQueryModel *modal;
    QSqlQueryModel *mdl;
    yeni_arac_giris *yeniarac;
    Konum *katlar;
    aboutHak *bilgi;
    abone_islem *aboneislem;
    arac_cikis_islemleri *araccikis;
    dbconnection conn;


};

#endif // OTOPARKU_H
