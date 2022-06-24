#include "dbconnection.h"

dbconnection::veritabanina_baglan(){

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./otopark.db");
    bool ok=db.open();
    if(!ok){
         qDebug() << "Veritabanı baglantı basarısız..."<<db.lastError();
         return false;
    }
    else{
        qDebug() << "Veritabanına bağlantı BAŞARILI...";
        return true;
    }
    QSqlQuery qry;
    query = qry;
}

int dbconnection::veri_cek(QString select, QString table, QString where){
    QString sql = QString("SELECT ") + select + QString(" FROM ") + table + QString(" WHERE ") + where ;
    qDebug() << sql;
    return query.exec(sql);
}

int dbconnection::veri_gir(QString table, QStringList data, QStringList values){

    QString sql = QString("INSERT INTO ") + table + QString(" ( ")  ;
    QString   dt = "";
    QString vl = "";
    for(int i = 0; i < data.size(); i++){

        dt = dt + QString("`") + data.at(i) + QString("`") + QString(",");
        vl = vl + QString("'") + values.at(i) + QString("'") + QString(",");
    }

    dt.chop(1);
    vl.chop(1);


    sql = sql + dt + QString(") ") + QString("VALUES(") + vl + QString(")");

    query.exec(sql);
    qDebug() << db.lastError();
    return query.numRowsAffected();
}

int dbconnection::veri_guncelle(QString table, QStringList data, QStringList values, QString where){

    QString sql = QString("UPDATE `") + table + QString("` SET ")  ;
    QString   dt = "";
    QString vl = "";
    QString temp = "";
    for(int i = 0; i < data.size(); i++){

        temp = temp + QString("`") + data.at(i) + QString("`") + QString("=") + QString("'") + values.at(i) + QString("'") + QString(",");
    }

    temp.chop(1);
    sql = sql + temp + QString(" WHERE ") + where;
    qDebug() << sql;


    query.exec(sql);
    qDebug() << db.lastError();
    return query.numRowsAffected();
}



QSqlError dbconnection::sql_getLastError(){
    return db.lastError();
}

int dbconnection::veri_sil(QString table, QString where){
    QString sql = QString("DELETE ") + QString("FROM ") + table + QString(" WHERE ") + where ;
    qDebug() << sql;
    QSqlQuery qry;
    qry.exec(sql);
    query = qry;
    return 0;

}
dbconnection::baglanti_kapa(){
        db.close();
        db.removeDatabase(QSqlDatabase::defaultConnection);
        return 0;
    }
QSqlQuery dbconnection::sql_getResults(){
    return query;
}
