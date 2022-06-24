#include "yeni_arac_giris.h"
#include "ui_yeni_arac_giris.h"
#include "FrontEnd/dbconnection.h"
#include <QValidator>
#include <QMessageBox>
#include <QDateTime>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QSqlQuery>
yeni_arac_giris::yeni_arac_giris(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::yeni_arac_giris)
{

    dbconnection conn;
    ui->setupUi(this);
    ui->musteri_tc_no->setInputMask("00000000000");//sadece 11 haneli rakam girilmesi için
    ui->musteri_cep_no->setInputMask("+00 000 000 00 00");//telefon numarası için
    ui->aracformudurum->setVisible(false);


}

yeni_arac_giris::~yeni_arac_giris(){

    delete ui;
}
void yeni_arac_giris::show(){
     dbconnection conn;
    /*veritabanında kayıtlı bulunan konumların boş
     * olanlarını yeni araç kayıt formunda bulunan
     * combobax a aktardık*/
    QSqlQueryModel *modal= new QSqlQueryModel();
    QSqlQuery* sorgu = new QSqlQuery(conn.db);
    sorgu->prepare("SELECT oname FROM otopark WHERE ostatus='Bos'");
    sorgu->exec();
    modal->setQuery(*sorgu);
    ui->arac_konumu->setModel(modal);

    QSqlQueryModel *mod= new QSqlQueryModel();
    QSqlQuery* srg = new QSqlQuery(conn.db);
    srg->prepare("SELECT tsure FROM otoparktime");
    srg->exec();
    mod->setQuery(*srg);
    ui->arac_sure->setModel(mod);
 QDialog::show();
}
void yeni_arac_giris::on_yeni_arac_iptal_clicked(){
    foreach(QLineEdit *widget, this->findChildren<QLineEdit*>()) {
            widget->clear();
    }
    this->close();
}
void yeni_arac_giris::on_yeni_arac_yenile_clicked(){

foreach(QLineEdit *widget, this->findChildren<QLineEdit*>()) {
        widget->clear();
}

}
void yeni_arac_giris::on_yeni_arac_kaydet_clicked(){
    QString musterikimlikno,musteriadi,musterisoyadi,musterisure,musteritel,musteriaracplaka,musteriaracmarkamodel,musteriaracrenk,musteriarackonum;
    musterikimlikno=ui->musteri_tc_no->text();
    musteriadi=ui->musteri_adi->text();
    musterisoyadi=ui->musteri_soyadi->text();
    musteritel=ui->musteri_cep_no->text();
    musteriaracplaka=ui->arac_plaka_no->text();
    musteriaracmarkamodel=ui->arac_marka_model->text();
    musteriaracrenk=ui->arac_renk->text();
    musterisure=ui->arac_sure->currentText();
    musteriarackonum=ui->arac_konumu->currentText();
    QDateTime eklenmezamani(QDateTime::currentDateTime());
    if(musterikimlikno==""){
        ui->aracformudurum->setVisible(true);
        ui->aracformudurum->setText("Tc No Boş Bırakılamaz");
    }
    else if(musteriaracplaka==""){
        ui->aracformudurum->setVisible(true);
        ui->aracformudurum->setText("Plaka No Boş Bırakılamaz..");
    }
    else if(musteritel==""){
        ui->aracformudurum->setVisible(true);
        ui->aracformudurum ->setText("Cep Telefonu boş Bırakılamz...");
    }
    else if(musteriarackonum==""){
        ui->aracformudurum->setVisible(true);
        ui->aracformudurum->setText("Araç Konumu Şeçilmedi...");
    }
    else if(musterisure==""){
        ui->aracformudurum->setVisible(true);
        ui->aracformudurum->setText("Araç Park Süresi Şeçilmedi...");
    }
    else{
        ui->aracformudurum->setVisible(false);
        QString musteridurum;
        musteridurum="GRSYPT";
        QSqlQuery sorgu;
//      sorgu.prepare("INSERT INTO customers (cidno,cname,csurname,cphone,ccplate,ccbrandmodel,cccolor,cclocation,ctime,caddtime,cstatus) values"
//                      " ('"+musterikimlikno+"', '"+musteriadi+"', '"+musterisoyadi+"', '"+musteritel+"', '"+musteriaracplaka+"', '"+musteriaracmarkamodel+"', "+musteriaracrenk+"', '"+musteriarackonum+"','"+musterisure+"','"+eklenmezamani.toString()+"')");

        sorgu.prepare("INSERT INTO customers (cidno,cname,csurname,cphone,ccplate,ccbrandmodel,cccolor,cclocation,ctime,caddtime,cstatus) values"
                      "(?,?,?,?,?,?,?,?,?,?,?)");
        //burda ise teker teker ekledi.
        sorgu.addBindValue(musterikimlikno);
        sorgu.addBindValue(musteriadi.toUpper());
        sorgu.addBindValue(musterisoyadi.toUpper());
        sorgu.addBindValue(musteritel);
        sorgu.addBindValue(musteriaracplaka.toUpper());
        sorgu.addBindValue(musteriaracmarkamodel.toUpper());
        sorgu.addBindValue(musteriaracrenk.toUpper());
        sorgu.addBindValue(musteriarackonum);
        sorgu.addBindValue(musterisure);
        sorgu.addBindValue(eklenmezamani);
        sorgu.addBindValue(musteridurum);

        if(sorgu.exec()){
          qDebug()<<("Veri Kaydedildi");
          sorgu.prepare( "UPDATE otopark SET ostatus = 'dolu' WHERE oname = '"+musteriarackonum+"'" );sorgu.exec();
          emit loadDataS();

          foreach(QLineEdit *widget, this->findChildren<QLineEdit*>()) {
                  widget->clear();
          }
          this->close();

        }else{
          qDebug()<<(sorgu.lastError().text());
        }
    }

}
