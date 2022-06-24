#include "abone_islem.h"
#include "ui_abone_islem.h"

abone_islem::abone_islem(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::abone_islem),
    modal(new QSqlQueryModel)
{
    ui->setupUi(this);
    foreach(QLineEdit *widget, this->findChildren<QLineEdit*>()) {
            widget->clear();
    }
    ui->abone_kimlik_no->setInputMask("00000000000");//sadece 11 haneli rakam girilmesi için
    ui->abone_cep_no->setInputMask("+00 000 000 00 00");//telefon numarası için
    ui->abone_durum->setVisible(false);
    ui->id->setVisible(false);
    ui->yeniabone->setEnabled(true);
    loadData();
}


void abone_islem::loadData()
{
    QSqlQuery* sorgu = new QSqlQuery(conn.db);
    sorgu->prepare("SELECT * FROM subscriber");
    sorgu->exec();
    modal->setQuery(*sorgu);
    modal->setHeaderData(0, Qt::Horizontal, tr("ID"));
    modal->setHeaderData(1, Qt::Horizontal, tr("KİMLİK NO"));
    modal->setHeaderData(2, Qt::Horizontal, tr("ADI"));
    modal->setHeaderData(3, Qt::Horizontal, tr("SOYADI"));
    modal->setHeaderData(4, Qt::Horizontal, tr("İLETİŞİM"));
    modal->setHeaderData(5, Qt::Horizontal, tr("PLAKA NO"));
    modal->setHeaderData(6, Qt::Horizontal, tr("MARKA"));
    modal->setHeaderData(7, Qt::Horizontal, tr("MODEL"));
    modal->setHeaderData(8, Qt::Horizontal, tr("RENK"));
    modal->setHeaderData(9, Qt::Horizontal, tr("SÜRE"));
    modal->setHeaderData(11, Qt::Horizontal, tr("ABONELİK BAŞLANGIÇ"));
    modal->setHeaderData(12, Qt::Horizontal, tr("ABONELİK BİTİŞ"));
    modal->setHeaderData(13, Qt::Horizontal, tr("ÜCRET"));
    ui->abonetablosu->setModel(modal);
}

abone_islem::~abone_islem()
{
    delete ui;
}
void abone_islem::on_yeniabone_clicked(){
QString abonekimlikno,
           aboneadi,
           abonesoyadi,
           abonesure,
           abonetel,
           abonearacplaka,
           abonearacmarka,
           abonearacmodel,
           aboneucret,
           abonearacrenk,
           abonedakika;

   abonekimlikno=ui->abone_kimlik_no->text();
   aboneadi=ui->abone_adi->text();
   abonesoyadi=ui->abone_soyadi->text();
   abonetel=ui->abone_cep_no->text();
   abonearacplaka=ui->abone_arac_plaka->text();
   abonearacmarka=ui->abone_arac_marka->text();
   abonearacmodel=ui->abone_arac_model->text();
   abonearacrenk=ui->abone_arac_renk->text();
   abonesure=ui->abone_sure->currentText();
   QSqlQuery sorguabonevarmi;
   sorguabonevarmi.prepare("SELECT * FROM subscriber WHERE sidno='"+abonekimlikno+"'");
   if(sorguabonevarmi.exec()){
       int say=0;
       while(sorguabonevarmi.next()) {
           say++;
       }
       if(say>=1){
           ui->abone_durum->setVisible(true);
           ui->abone_durum->setText("Abone Kaydı Mevcut Eklenme Yapılamaz");
           ui->yeniabone->setEnabled(false);

       }
       else{
           if(abonesure=="7 Gün"){
             aboneucret="10 Tl";
             abonedakika="10080";
           }
          else if(abonesure=="15 Gün"){
             aboneucret="20 Tl";
             abonedakika="121600";
           }
           else if(abonesure=="30 Gün"){
              aboneucret="30 Tl";
              abonedakika="43200";
            }
           else if(abonesure=="90 Gün"){
              aboneucret="45 Tl";
              abonedakika="129600";
            }
           else if(abonesure=="180 Gün"){
              aboneucret="80 Tl";
              abonedakika="259200";
            }
           else if(abonesure=="270 Gün"){
              aboneucret="150 Tl";
              abonedakika="388800";
            }
           else{
             aboneucret="200 Tl";
             abonedakika="518400";
           }
           QDateTime eklenmezamani(QDateTime::currentDateTime());
           if(abonekimlikno==""){
               ui->abone_durum->setVisible(true);
               ui->abone_durum->setText("Abone Tc No Boş Bırakılamaz");
           }
           else if(aboneadi==""){
               ui->abone_durum->setVisible(true);
               ui->abone_durum->setText("Abone Adı Boş Bırakılamaz");
           }
           else if(abonesoyadi==""){
               ui->abone_durum->setVisible(true);
               ui->abone_durum->setText("Abone Soyadı Boş Bırakılamaz");
           }
           else if(abonetel==""){
               ui->abone_durum->setVisible(true);
               ui->abone_durum->setText("Abone Telefon Numarası Boş Bırakılamaz");
           }
           else if(abonearacplaka==""){
               ui->abone_durum->setVisible(true);
               ui->abone_durum->setText("Abone Araç Plaka No Boş Bırakılamaz");
           }
           else if(abonearacmarka==""){
               ui->abone_durum->setVisible(true);
               ui->abone_durum->setText("Abone Araç Araç Markası Boş Bırakılamaz");
           }
           else {
               QSqlQuery sorgu;
               sorgu.prepare("INSERT INTO subscriber (sidno,sname,ssurname,sphone,scplate,scbrand,scmodel,sccolor,stime,sminute,saddtime,sfee) values"
                             "(?,?,?,?,?,?,?,?,?,?,?,?)");
               sorgu.addBindValue(abonekimlikno);
               sorgu.addBindValue(aboneadi.toUpper());
               sorgu.addBindValue(abonesoyadi.toUpper());
               sorgu.addBindValue(abonetel);
               sorgu.addBindValue(abonearacplaka.toUpper());
               sorgu.addBindValue(abonearacmarka.toUpper());
               sorgu.addBindValue(abonearacmodel.toUpper());
               sorgu.addBindValue(abonearacrenk.toUpper());
               sorgu.addBindValue(abonesure);
               sorgu.addBindValue(abonedakika);
               sorgu.addBindValue(eklenmezamani);
               sorgu.addBindValue(aboneucret);
               if(sorgu.exec()){
                 qDebug()<<("Veri Kaydedildi");
                 loadData();
                 emit loadDataSet();
                 foreach(QLineEdit *widget, this->findChildren<QLineEdit*>()) {
                         widget->clear();
                 }

               }
               else{
                 qDebug()<<(sorgu.lastError().text());
               }
           }
       }

   }
   else{
        qDebug()<<(sorguabonevarmi.lastError().text());
   }

}

void abone_islem::on_cikis_clicked(){
    this->close();
}

void abone_islem::on_aboneduzenle_clicked(){

    QString abonekimlikno,
               aboneadi,
               abonesoyadi,
               abonesure,
               abonetel,
               abonearacplaka,
               abonearacmarka,
               abonearacmodel,
               aboneucret,
               abonedakika,
               abonearacrenk;
       QString s=ui->id->text();
       abonekimlikno=ui->abone_kimlik_no->text();
       aboneadi=ui->abone_adi->text();
       abonesoyadi=ui->abone_soyadi->text();
       abonetel=ui->abone_cep_no->text();
       abonearacplaka=ui->abone_arac_plaka->text();
       abonearacmarka=ui->abone_arac_marka->text();
       abonearacmodel=ui->abone_arac_model->text();
       abonearacrenk=ui->abone_arac_renk->text();
       abonesure=ui->abone_sure->currentText();
       if(abonesure=="7 Gün"){
         aboneucret="10 Tl";
         abonedakika="10080";
       }
      else if(abonesure=="15 Gün"){
         aboneucret="20 Tl";
         abonedakika="121600";
       }
       else if(abonesure=="30 Gün"){
          aboneucret="30 Tl";
          abonedakika="43200";
        }
       else if(abonesure=="90 Gün"){
          aboneucret="45 Tl";
          abonedakika="129600";
        }
       else if(abonesure=="180 Gün"){
          aboneucret="80 Tl";
          abonedakika="259200";
        }
       else if(abonesure=="270 Gün"){
          aboneucret="150 Tl";
          abonedakika="388800";
        }
       else{
         aboneucret="200 Tl";
         abonedakika="518400";
       }
       quint64 eklenmezamani = QDateTime::currentMSecsSinceEpoch();
       if(abonekimlikno==""){
           ui->abone_durum->setVisible(true);
           ui->abone_durum->setText("Tc No Boş Bırakılamaz");
       }
       else if(aboneadi==""){
           ui->abone_durum->setVisible(true);
           ui->abone_durum->setText("Adı Boş Bırakılamaz");
       }
       else if(abonesoyadi==""){
           ui->abone_durum->setVisible(true);
           ui->abone_durum->setText("Soyadı Boş Bırakılamaz");
       }
       else if(abonetel==""){
           ui->abone_durum->setVisible(true);
           ui->abone_durum->setText("Telefon Numarası Boş Bırakılamaz");
       }
       else if(abonearacplaka==""){
           ui->abone_durum->setVisible(true);
           ui->abone_durum->setText("Plaka No Boş Bırakılamaz");
       }
       else if(abonearacmarka==""){
           ui->abone_durum->setVisible(true);
           ui->abone_durum->setText("Araç Markası Boş Bırakılamaz");
       }
       else {
           QSqlQuery sorgu;
           sorgu.prepare("UPDATE subscriber SET "
                         "sidno = :kimlikno,"
                         "sname = :adi,"
                         "ssurname = :soyadi,"
                         "sphone = :tel,"
                         "scplate = :plaka,"
                         "scbrand = :marka,"
                         "scmodel = :model,"
                         "sccolor = :renk,"
                         "stime = :zaman,"
                         "sminute = :dakika,"
                         "saddtime = :guncellenme,"
                         "sfee = :ucret"
                         " WHERE sid='"+s+"'");
           sorgu.bindValue(":kimlikno", abonekimlikno);
           sorgu.bindValue(":adi", aboneadi.toUpper());
           sorgu.bindValue(":soyadi", abonesoyadi.toUpper());
           sorgu.bindValue(":tel", abonetel);
           sorgu.bindValue(":plaka", abonearacplaka.toUpper());
           sorgu.bindValue(":marka", abonearacmarka.toUpper());
           sorgu.bindValue(":model", abonearacmodel.toUpper());
           sorgu.bindValue(":renk", abonearacrenk.toUpper());
           sorgu.bindValue(":zaman", abonesure);
           sorgu.bindValue(":dakika", abonedakika);
           sorgu.bindValue(":guncellenme", eklenmezamani);
           sorgu.bindValue(":ucret", aboneucret);
           if(sorgu.exec()){
             qDebug()<<("Veri Kaydedildi");
             loadData();
             emit loadDataSet();
             foreach(QLineEdit *widget, this->findChildren<QLineEdit*>()) {
                     widget->clear();
             }

           }
           else{
             qDebug()<<(sorgu.lastError().text());
           }
       }
       ui->yeniabone->setEnabled(true);
}

void abone_islem::on_abonetablosu_activated(const QModelIndex &index)
{
    QString val=ui->abonetablosu->model()->data(index).toString();
    QSqlQuery sorgu;
    sorgu.prepare("SELECT * FROM subscriber WHERE sid='"+val+"'");
    if(sorgu.exec()){
        while(sorgu.next()){
            ui->id->setText(sorgu.value(0).toString());
            ui->abone_kimlik_no->setText(sorgu.value(1).toString());
            ui->abone_adi->setText(sorgu.value(2).toString());
            ui->abone_soyadi->setText(sorgu.value(3).toString());
            ui->abone_cep_no->setText(sorgu.value(4).toString());
            ui->abone_arac_plaka->setText(sorgu.value(5).toString());
            ui->abone_arac_marka->setText(sorgu.value(6).toString());
            ui->abone_arac_model->setText(sorgu.value(7).toString());
            ui->abone_arac_renk->setText(sorgu.value(8).toString());
        }
    }
    else{
        qDebug()<<(sorgu.lastError().text());
    }
}

void abone_islem::on_abonesil_clicked(){
      QString s=ui->id->text();
      QSqlQuery sorgu;
      sorgu.prepare( "DELETE FROM subscriber WHERE sid='"+s+"'");
      if(sorgu.exec()){
        qDebug()<<("Silme İşlemi Başarılı");
        loadData();
        emit loadDataSet();
        foreach(QLineEdit *widget, this->findChildren<QLineEdit*>()) {
                widget->clear();
        }

      }
      else{
        qDebug()<<(sorgu.lastError().text());
      }
      ui->yeniabone->setEnabled(true);
  }

