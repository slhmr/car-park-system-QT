#include "ulgnpnlformu.h"
#include "ui_ulgnpnlformu.h"
#include "FrontEnd/dbconnection.h"

ULgnPnlFormu::ULgnPnlFormu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ULgnPnlFormu)
{
    ui->setupUi(this);
    dbconnection mydb;
    mydb.veritabanina_baglan();
    OtoparkU knt;
    knt.veritabani_kul_kontrol();
    knt.veritabani_tablo_kontrol();
    ui->durum->setVisible(false);
    ui->password->setEchoMode(QLineEdit::Password);
}

ULgnPnlFormu::~ULgnPnlFormu()
{
    delete ui;
}

void ULgnPnlFormu::on_giris_yap_clicked()
{
    QString username,userpass;
    username=ui->username->text();
    userpass=ui->password->text();
    if(username==""){
        ui->durum->setVisible(true);
        ui->durum->setText("HATA!!!  Kullanıcı Adı Boş Bırakılamaz..!");
    }
    else if(userpass==""){
        ui->durum->setVisible(true);
        ui->durum->setText("HATA!!!  Şifre Boş Bırakılamaz..!");
    }
    else{
        QSqlQuery query;
        query.prepare("select * from user where uname='"+username+"' and upass='"+userpass+"'");
        if(query.exec()){
            int say=0;
            while(query.next()) {
                say++;
            }
            if(say==1){
                ui->durum->setText("Giriş işlemi Başarılı...");
                ui->durum->setVisible(true);
                close();
                Otopark=new OtoparkU;
                Otopark->show();
            }
            else if(say>>1){
                ui->durum->setVisible(true);
                 ui->durum->setText("HATA!!  Çift Kullanıcı Hatası");
            }
            else{
                ui->durum->setVisible(true);
                ui->durum->setText("HATA!!  Kullanıcı Adı ve Şifre Hatalı");
            }

        }

    }
}

void ULgnPnlFormu::on_cikis_yap_clicked(){
   this->close();
}
