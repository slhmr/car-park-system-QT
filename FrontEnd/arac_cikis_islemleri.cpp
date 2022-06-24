#include "arac_cikis_islemleri.h"
#include "ui_arac_cikis_islemleri.h"
#include"FrontEnd/dbconnection.h"
#include <QDateTime>
#include <QDebug>
#include <QPrinter>
#include <QPrintDialog>
#include <QPainter>
#include <QMessageBox>

arac_cikis_islemleri::arac_cikis_islemleri(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::arac_cikis_islemleri){
    ui->setupUi(this);
    foreach(QLineEdit *widget, this->findChildren<QLineEdit*>()) {widget->clear();}
    ui->arac_ciki_fisi_yazdir->setEnabled(false);
    ui->arac_ciki_fisi_yazdir->setVisible(false);
    ui->arac_cikisini_yap->setEnabled(false);
    ui->arac_cikisini_yap->setVisible(false);
    ui->cikanaraccikissaati->setVisible(false);
    ui->cikanarackonum->setVisible(false);
    ui->cikanaracucret->setVisible(false);
    ui->cikanaracplaka->setText("");
}

arac_cikis_islemleri::~arac_cikis_islemleri(){
    delete ui;
}


void arac_cikis_islemleri::on_arac_bilgileri_clicked(){
    QString id,kimlik,adi,soyadi,tel,girilenplaka,gelenplaka,markamodel,konumu,ucret;
    int abonedakika;
    girilenplaka=ui->plakano->text();
    QString musteridurum="GRSYPT";

    girilenplaka=girilenplaka.toUpper();
    QSqlQuery sorgu;
    sorgu.prepare("SELECT * FROM customers WHERE ccplate='"+girilenplaka+"' and cstatus='"+musteridurum+"'");
    if(sorgu.exec()){
        int say=0;
        while(sorgu.next()) {
            say++;
        }
        if(say>=1){
            QSqlQuery sorgu;
            sorgu.prepare("SELECT * FROM customers WHERE ccplate='"+girilenplaka+"' and cstatus='"+musteridurum+"'");
            if(sorgu.exec()){
                while(sorgu.next()){
                    id=sorgu.value(0).toString();
                    kimlik=sorgu.value(1).toString();
                    adi=sorgu.value(2).toString();
                    soyadi=sorgu.value(3).toString();
                    tel=sorgu.value(4).toString();
                    gelenplaka=sorgu.value(5).toString();
                    markamodel=sorgu.value(6).toString();
                    konumu=sorgu.value(8).toString();
                    ui->cikanarackonum->setText(konumu);
                    QString time_format = "dd-MM-yyyy HH:mm:ss";
                    QDateTime b=sorgu.value(10).toDateTime();
                    QString girissaati=b.toString(time_format);
                    QDateTime a = QDateTime::currentDateTime();
                    QString simdi = a.toString(time_format);
                    QDateTime girisZaman = sorgu.value(10).toDateTime();
                    ui->cikanaracplaka->setText(girilenplaka);
                    ui->aracbilgileri->append("      MAVROSOFT OTOPARK YAZILIMI");
                    ui->aracbilgileri->append("\t ARAÇ ÇIKIŞ FİŞİ\n\n");
                    ui->aracbilgileri->append("Adı Soyadı : "+adi+" "+soyadi+"");
                    ui->aracbilgileri->append("Araç Plakası: "+gelenplaka+"");
                    ui->aracbilgileri->append("Giriş Saati : "+girissaati+"");
                    ui->aracbilgileri->append("Çıkış Saati : "+simdi+"");
                    ui->aracbilgileri->append("\nAlınan Hizmetler");
                    ui->aracbilgileri->append("-Hizmet Bulunmamaktadır....");
                    ui->aracbilgileri->append("\nAbone Bilgisi");
                    ui->cikanaraccikissaati->setText(simdi);

                    int musteridakika = (QDateTime::currentDateTime().toSecsSinceEpoch() - girisZaman.toSecsSinceEpoch())/60;
                    qDebug() << musteridakika << "dakika";
                    QSqlQuery sorguabone;
                    sorguabone.prepare("SELECT * FROM subscriber WHERE sidno='"+kimlik+"'");
                    if(sorguabone.exec()){
                        int say=0;
                        while(sorguabone.next()) {
                            say++;
                        }
                        if(say>=1){
                          QDateTime abonesure = sorguabone.value(11).toDateTime();
                          QString abone_sure=sorguabone.value(9).toString();
                          int abone_sure_dakika = (QDateTime::currentDateTime().toSecsSinceEpoch() - abonesure.toSecsSinceEpoch())/60;
                          qDebug() << abone_sure_dakika << "dakika";
                          if(abone_sure=="7 Gün"){
                           abonedakika=10080;
                           }
                          else if(abone_sure=="15 Gün"){
                            abonedakika=121600;
                           }
                          else if(abone_sure=="30 Gün"){
                             abonedakika=43200;
                           }
                          else if(abone_sure=="90 Gün"){
                             abonedakika=129600;
                           }
                          else if(abone_sure=="180 Gün"){
                             abonedakika=259200;
                           }
                          else if(abone_sure=="270 Gün"){
                             abonedakika=388800;
                           }
                          else{
                            abonedakika=518400;
                          }
                          if((abonedakika-abone_sure_dakika)<=0){
                              ui->aracbilgileri->append("Abonelik Süreniz Bitmiştir\n");
                              if(musteridakika<=60){
                                 ucret="3.00TL";
                                 ui->aracbilgileri->append("Ödenecek Tutar :  "+ucret+"");
                              }
                              else if(musteridakika>60 && musteridakika<=180 ){
                                  ucret="6.00TL";
                                  ui->aracbilgileri->append("Ödenecek Tutar :  "+ucret+"");
                              }
                              else if(musteridakika>180 && musteridakika<=360 ){
                                  ucret="9.00TL";
                                  ui->aracbilgileri->append("Ödenecek Tutar :  "+ucret+"");
                              }
                              else if(musteridakika>360 && musteridakika<=720 ){
                                  ucret="12.00TL";
                                 ui->aracbilgileri->append("Ödenecek Tutar :  "+ucret+"");
                              }
                              else if(musteridakika>720 && musteridakika<=1440 ){
                                  ucret="20.00TL";
                                  ui->aracbilgileri->append("Ödenecek Tutar :  "+ucret+"");
                              }
                              else if(musteridakika>1440 && musteridakika<=5760 ){
                                  ucret="30.00TL";
                                  ui->aracbilgileri->append("Ödenecek Tutar :  "+ucret+"");
                              }
                              else if(musteridakika>5760 && musteridakika<=10080 ){
                                  ucret="50.00TL";
                                  ui->aracbilgileri->append("Ödenecek Tutar :  "+ucret+"");
                              }
                              else if(musteridakika>10080 && musteridakika<=21600 ){
                                  ucret="75.00TL";
                                  ui->aracbilgileri->append("Ödenecek Tutar :  "+ucret+"");
                              }
                              else{
                                  ucret="100.00TL";
                                  ui->aracbilgileri->append("Ödenecek Tutar :  "+ucret+"");
                              }
                          }
                          else{
                            ucret="Abone Olduğunuz İçin Teşekkürler";
                            ui->aracbilgileri->append("\t"+ucret+"");
                            ui->aracbilgileri->append("İyi Günler");
                          }
                        }
                        else{
                            ui->aracbilgileri->append("Abone Bilgisi Bulunmamaktadır\n");
                            if(musteridakika<=60){
                               ucret="3.00TL";
                               ui->aracbilgileri->append("Ödenecek Tutar :  "+ucret+"");
                            }
                            else if(musteridakika>60 && musteridakika<=180 ){
                                ucret="6.00TL";
                                ui->aracbilgileri->append("Ödenecek Tutar :  "+ucret+"");
                            }
                            else if(musteridakika>180 && musteridakika<=360 ){
                                ucret="9.00TL";
                                ui->aracbilgileri->append("Ödenecek Tutar :  "+ucret+"");
                            }
                            else if(musteridakika>360 && musteridakika<=720 ){
                                ucret="12.00TL";
                                ui->aracbilgileri->append("Ödenecek Tutar :  "+ucret+"");
                            }
                            else if(musteridakika>720 && musteridakika<=1440 ){
                                ucret="20.00TL";
                                ui->aracbilgileri->append("Ödenecek Tutar :  "+ucret+"");
                            }
                            else if(musteridakika>1440 && musteridakika<=5760 ){
                                ucret="30.00TL";
                                ui->aracbilgileri->append("Ödenecek Tutar :  "+ucret+"");
                            }
                            else if(musteridakika>5760 && musteridakika<=10080 ){
                                ucret="50.00TL";
                                ui->aracbilgileri->append("Ödenecek Tutar :  "+ucret+"");
                            }
                            else if(musteridakika>10080 && musteridakika<=21600 ){
                                ucret="75.00TL";
                                ui->aracbilgileri->append("Ödenecek Tutar :  "+ucret+"");
                            }
                            else{
                                ucret="100.00TL";
                                ui->aracbilgileri->append("Ödenecek Tutar :  "+ucret+"");
                            }
                        }
                    }//abone sorgu sonu
                    else{
                        qDebug()<<(sorgu.lastError().text());
                    }
                    ui->cikanaracucret->setText(ucret);
                    ui->aracbilgileri->append("\n\n\tİyi Günler Dileriz...");
                }
            }//müşteri sorgu sonu
            else{

                qDebug()<<(sorgu.lastError().text());
            }
        }
        else{
            ui->plakano->setText("Kayıt Yok");
            ui->arac_ciki_fisi_yazdir->setEnabled(false);
            ui->arac_ciki_fisi_yazdir->setVisible(false);
            ui->arac_cikisini_yap->setEnabled(false);
            ui->arac_cikisini_yap->setVisible(false);
            ui->cikanaraccikissaati->setVisible(false);
            ui->cikanarackonum->setVisible(false);
            ui->cikanaracucret->setVisible(false);
        }
        ui->arac_ciki_fisi_yazdir->setVisible(true);
        ui->arac_ciki_fisi_yazdir->setEnabled(true);
    }


}

void arac_cikis_islemleri::on_temizle_clicked(){
    foreach(QLineEdit *widget, this->findChildren<QLineEdit*>()) {widget->clear();}
    foreach(QTextEdit *widget, this->findChildren<QTextEdit*>()) {widget->clear();}
     ui->arac_ciki_fisi_yazdir->setEnabled(false);
     ui->arac_ciki_fisi_yazdir->setVisible(false);
     ui->cikanaracplaka->setText("");
}

void arac_cikis_islemleri::on_arac_ciki_fisi_yazdir_clicked(){
    QPrinter printer;
    QPrintDialog printDialog(&printer, this);
    if (printDialog.exec() == QDialog::Accepted) {
       ui->aracbilgileri->print(&printer);
     }
    ui->arac_cikisini_yap->setVisible(true);
    ui->arac_cikisini_yap->setEnabled(true);

}


void arac_cikis_islemleri::on_arac_cikisini_yap_clicked(){
    QString plakabilgi,odenenucret,cikissaati,arackonumu,durumu;
    durumu="CKSYPT";
    plakabilgi=ui->cikanaracplaka->text();
    plakabilgi=plakabilgi.toUpper();
    odenenucret=ui->cikanaracucret->text();
    cikissaati=ui->cikanaraccikissaati->text();
    arackonumu=ui->cikanarackonum->text();

    QSqlQuery query;
    query.prepare("UPDATE customers SET cexit=:cikissaati, cfee=:ucret, cstatus=:musteridurum WHERE ccplate=:plaka ");
    query.bindValue(":cikissaati", ui->cikanaraccikissaati->text());
    query.bindValue(":ucret", ui->cikanaracucret->text());
    query.bindValue(":musteridurum", durumu);
    query.bindValue(":plaka", plakabilgi);
    if (query.exec()){
        QSqlQuery sorgu;
        QString bos="Bos";
        sorgu.prepare( "UPDATE otopark SET ostatus =:konumu WHERE oname =:konumadi");
        sorgu.bindValue(":konumu",bos);
        sorgu.bindValue(":konumadi", arackonumu);
        if (!sorgu.exec()){
             qDebug()<<(sorgu.lastError().text());
        }
        else{
            emit loadDataS();
        }
    }
    else{
        qDebug()<<(query.lastError().text());
    }
    ui->arac_cikisini_yap->setVisible(false);
    ui->arac_cikisini_yap->setEnabled(false);
    foreach(QLineEdit *widget, this->findChildren<QLineEdit*>()) {widget->clear();}
    foreach(QTextEdit *widget, this->findChildren<QTextEdit*>()) {widget->clear();}
    ui->arac_ciki_fisi_yazdir->setEnabled(false);
    ui->arac_ciki_fisi_yazdir->setVisible(false);
    ui->cikanaracplaka->setText("");
    this->close();

}
