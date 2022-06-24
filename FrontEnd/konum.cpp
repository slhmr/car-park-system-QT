#include "konum.h"
#include "ui_konum.h"
#include "FrontEnd/dbconnection.h"
Konum::Konum(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Konum)
{
    ui->setupUi(this);

}


Konum::~Konum()
{
    delete ui;
}

void Konum::show(){
    QSqlQuery query;
    ui->a1_resim->setVisible(false);
    ui->a1_plaka->setText("BOŞ");
    ui->a1_sure->setVisible(false);
    ui->a1_giris_saati->setVisible(false);
    query.prepare("SELECT ccplate,ctime,caddtime FROM customers WHERE cclocation='A1' AND cstatus='GRSYPT'");
    if(query.exec()){
        int say=0;
        while(query.next()) {
            say++;
            if(say>0){
                ui->a1_resim->setVisible(true);
                ui->a1_sure->setVisible(true);
                ui->a1_giris_saati->setVisible(true);
               ui->a1_plaka->setText(query.value(0).toString());
               ui->a1_sure->setText(query.value(1).toString());
               ui->a1_giris_saati->setText(query.value(2).toString());
            }

        }
    }
    ui->a2_resim->setVisible(false);
    ui->a2_plaka->setText("BOŞ");
    ui->a2_sure->setVisible(false);
    ui->a2_giris_saati->setVisible(false);
    query.prepare("SELECT ccplate,ctime,caddtime FROM customers WHERE cclocation='A2' AND cstatus='GRSYPT'");
    if(query.exec()){
        int say=0;
        while(query.next()) {
            qDebug() << "çalıştı";
            say++;
            if(say>0){
                ui->a2_resim->setVisible(true);
                ui->a2_sure->setVisible(true);
                ui->a2_giris_saati->setVisible(true);
                ui->a2_plaka->setText(query.value(0).toString());
                ui->a2_sure->setText(query.value(1).toString());
                ui->a2_giris_saati->setText(query.value(2).toString());
            }
        }
    }
    ui->a3_resim->setVisible(false);
    ui->a3_plaka->setText("BOŞ");
    ui->a3_sure->setVisible(false);
    ui->a3_giris_saati->setVisible(false);
    query.prepare("SELECT ccplate,ctime,caddtime FROM customers WHERE cclocation='A3' AND cstatus='GRSYPT'");
    if(query.exec()){
        int say=0;
        while(query.next()) {
            say++;
            if(say>0){
                ui->a3_resim->setVisible(true);
                ui->a3_sure->setVisible(true);
                ui->a3_giris_saati->setVisible(true);
                ui->a3_plaka->setText(query.value(0).toString());
                ui->a3_sure->setText(query.value(1).toString());
                ui->a3_giris_saati->setText(query.value(2).toString());
            }
        }
    }
    ui->a4_resim->setVisible(false);
    ui->a4_plaka->setText("BOŞ");
    ui->a4_sure->setVisible(false);
    ui->a4_giris_saati->setVisible(false);
    query.prepare("SELECT ccplate,ctime,caddtime FROM customers WHERE cclocation='A4' AND cstatus='GRSYPT'");
    if(query.exec()){
        int say=0;
        while(query.next()) {
            say++;
            if(say>0){
                ui->a4_resim->setVisible(true);
                ui->a4_sure->setVisible(true);
                ui->a4_giris_saati->setVisible(true);
                ui->a4_plaka->setText(query.value(0).toString());
                ui->a4_sure->setText(query.value(1).toString());
                ui->a4_giris_saati->setText(query.value(2).toString());
            }
        }
    }
    ui->a5_resim->setVisible(false);
    ui->a5_plaka->setText("BOŞ");
    ui->a5_sure->setVisible(false);
    ui->a5_giris_saati->setVisible(false);
    query.prepare("SELECT ccplate,ctime,caddtime FROM customers WHERE cclocation='A5' AND cstatus='GRSYPT'");
    if(query.exec()){
        int say=0;
        while(query.next()) {
            say++;
            if(say>0){
                ui->a5_resim->setVisible(true);
                ui->a5_sure->setVisible(true);
                ui->a5_giris_saati->setVisible(true);
                ui->a5_plaka->setText(query.value(0).toString());
                ui->a5_sure->setText(query.value(1).toString());
                ui->a5_giris_saati->setText(query.value(2).toString());
            }
        }
    }
    ui->a6_resim->setVisible(false);
    ui->a6_plaka->setText("BOŞ");
    ui->a6_sure->setVisible(false);
    ui->a6_giris_saati->setVisible(false);
    query.prepare("SELECT ccplate,ctime,caddtime FROM customers WHERE cclocation='A6' AND cstatus='GRSYPT'");
    if(query.exec()){
        int say=0;
        if(query.next()) {
            say++;
            if(say>0){
                ui->a6_resim->setVisible(true);
                ui->a6_sure->setVisible(true);
                ui->a6_giris_saati->setVisible(true);
                ui->a6_plaka->setText(query.value(0).toString());
                ui->a6_sure->setText(query.value(1).toString());
                ui->a6_giris_saati->setText(query.value(2).toString());
            }
        }
    }
    ui->b1_resim->setVisible(false);
    ui->b1_plaka->setText("BOŞ");
    ui->b1_sure->setVisible(false);
    ui->b1_giris_saati->setVisible(false);
    query.prepare("SELECT ccplate,ctime,caddtime FROM customers WHERE cclocation='B1' AND cstatus='GRSYPT'");
    if(query.exec()){
        int say=0;
        if(query.next()) {
            say++;
            if(say>0){
                ui->b1_resim->setVisible(true);
                ui->b1_sure->setVisible(true);
                ui->b1_giris_saati->setVisible(true);
                ui->b1_plaka->setText(query.value(0).toString());
                ui->b1_sure->setText(query.value(1).toString());
                ui->b1_giris_saati->setText(query.value(2).toString());
            }
        }
    }
    ui->b2_resim->setVisible(false);
    ui->b2_plaka->setText("BOŞ");
    ui->b2_sure->setVisible(false);
    ui->b2_giris_saati->setVisible(false);
    query.prepare("SELECT ccplate,ctime,caddtime FROM customers WHERE cclocation='B2' AND cstatus='GRSYPT'");
    if(query.exec()){
        int say=0;
        if(query.next()) {
            say++;
            if(say>0){
                ui->b2_resim->setVisible(true);
                ui->b2_sure->setVisible(true);
                ui->b2_giris_saati->setVisible(true);
                ui->b2_plaka->setText(query.value(0).toString());
                ui->b2_sure->setText(query.value(1).toString());
                ui->b2_giris_saati->setText(query.value(2).toString());
            }
        }
    }
    ui->b3_resim->setVisible(false);
    ui->b3_plaka->setText("BOŞ");
    ui->b3_sure->setVisible(false);
    ui->b3_giris_saati->setVisible(false);
    query.prepare("SELECT ccplate,ctime,caddtime FROM customers WHERE cclocation='B3' AND cstatus='GRSYPT'");
    if(query.exec()){
        int say=0;
        if(query.next()) {
            say++;
            if(say>0){
                ui->b3_resim->setVisible(true);
                ui->b3_sure->setVisible(true);
                ui->b3_giris_saati->setVisible(true);
                ui->b3_plaka->setText(query.value(0).toString());
                ui->b3_sure->setText(query.value(1).toString());
                ui->b3_giris_saati->setText(query.value(2).toString());
            }
        }
    }
    ui->b4_resim->setVisible(false);
    ui->b4_plaka->setText("BOŞ");
    ui->b4_sure->setVisible(false);
    ui->b4_giris_saati->setVisible(false);
    query.prepare("SELECT ccplate,ctime,caddtime FROM customers WHERE cclocation='B4' AND cstatus='GRSYPT'");
    if(query.exec()){
        int say=0;
        if(query.next()) {
            say++;
            if(say>0){
                ui->b4_resim->setVisible(true);
                ui->b4_sure->setVisible(true);
                ui->b4_giris_saati->setVisible(true);
                ui->b4_plaka->setText(query.value(0).toString());
                ui->b4_sure->setText(query.value(1).toString());
                ui->b4_giris_saati->setText(query.value(2).toString());
            }
        }
    }
    ui->b5_resim->setVisible(false);
    ui->b5_plaka->setText("BOŞ");
    ui->b5_sure->setVisible(false);
    ui->b5_giris_saati->setVisible(false);
    query.prepare("SELECT ccplate,ctime,caddtime FROM customers WHERE cclocation='B5' AND cstatus='GRSYPT'");
    if(query.exec()){
        int say=0;
        if(query.next()) {
            say++;
            if(say>0){
                ui->b5_resim->setVisible(true);
                ui->b5_sure->setVisible(true);
                ui->b5_giris_saati->setVisible(true);
                ui->b5_plaka->setText(query.value(0).toString());
                ui->b5_sure->setText(query.value(1).toString());
                ui->b5_giris_saati->setText(query.value(2).toString());
            }
        }
    }
    ui->b6_resim->setVisible(false);
    ui->b6_plaka->setText("BOŞ");
    ui->b6_sure->setVisible(false);
    ui->b6_giris_saati->setVisible(false);
    query.prepare("SELECT ccplate,ctime,caddtime FROM customers WHERE cclocation='B6' AND cstatus='GRSYPT'");
    if(query.exec()){
        int say=0;
        while(query.next()) {
            say++;
            if(say>0){
                ui->b6_resim->setVisible(true);
                ui->b6_sure->setVisible(true);
                ui->b6_giris_saati->setVisible(true);
                ui->b6_plaka->setText(query.value(0).toString());
                ui->b6_sure->setText(query.value(1).toString());
                ui->b6_giris_saati->setText(query.value(2).toString());
            }
        }
    }

    QDialog::show();
}
