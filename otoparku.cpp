#include "otoparku.h"
#include "ui_otoparku.h"
#include<QMessageBox>
#include<QTimer>
#include<QDateTime>
#include<qapplication.h>
#include <QDebug>

OtoparkU::OtoparkU(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::OtoparkU),
    modal(new QSqlQueryModel),
    mdl(new QSqlQueryModel),
    yeniarac(new yeni_arac_giris(this)),
    katlar(new Konum(this)),
    araccikis(new arac_cikis_islemleri(this)),
    aboneislem(new abone_islem(this)),
    bilgi(new aboutHak(this))
{
    OtoparkU::otoparkkonumyukle();
    OtoparkU::otoparksureyukle();
    ui->setupUi(this);
    QTimer *timer=new QTimer(this);
    connect (timer, SIGNAL(timeout()),this,SLOT(saati_goster()));
    timer->start();
    loadData();
    aboneyukle();
    ui->musteritablosu->setModel(modal);
    connect(yeniarac, &yeni_arac_giris::loadDataS, this, &OtoparkU::loadData);
    ui->abonetablosu->setModel(mdl);
    connect(aboneislem, &abone_islem::loadDataSet, this, &OtoparkU::aboneyukle);
    connect(araccikis, &arac_cikis_islemleri::loadDataS, this, &OtoparkU::loadData);

}
void OtoparkU::loadData(){
    QSqlQuery* sorgu = new QSqlQuery(conn.db);
    sorgu->prepare("SELECT cid,cname,csurname,ccplate,ccbrandmodel,cclocation,caddtime,cexit,cfee FROM customers as c, otopark as o WHERE c.cstatus='GRSYPT' and c.cclocation=o.oname and o.ostatus='dolu'");
    sorgu->exec();
    modal->setQuery(*sorgu);
    modal->setHeaderData(0, Qt::Horizontal, tr("ID"));
    modal->setHeaderData(1, Qt::Horizontal, tr("ADI"));
    modal->setHeaderData(2, Qt::Horizontal, tr("SOYADI"));
    modal->setHeaderData(3, Qt::Horizontal, tr("PLAKA NO"));
    modal->setHeaderData(4, Qt::Horizontal, tr("MARKA"));
    modal->setHeaderData(5, Qt::Horizontal, tr("KONUMU"));
    modal->setHeaderData(6, Qt::Horizontal, tr("GİRİŞ SAATİ"));
    modal->setHeaderData(7, Qt::Horizontal, tr("ÇIKIŞ SAATİ"));
    modal->setHeaderData(8, Qt::Horizontal, tr("ÜCRET"));

}
void OtoparkU::aboneyukle(){
    QSqlQuery* sorgu = new QSqlQuery(conn.db);
    sorgu->prepare("SELECT sid,sname,ssurname,scplate,scbrand,scmodel,saddtime,sexit,sfee FROM subscriber");
    sorgu->exec();
    mdl->setQuery(*sorgu);
    mdl->setHeaderData(0, Qt::Horizontal, tr("ID"));
    mdl->setHeaderData(1, Qt::Horizontal, tr("ADI"));
    mdl->setHeaderData(2, Qt::Horizontal, tr("SOYADI"));
    mdl->setHeaderData(3, Qt::Horizontal, tr("PLAKA NO"));
    mdl->setHeaderData(4, Qt::Horizontal, tr("MARKA"));
    mdl->setHeaderData(5, Qt::Horizontal, tr("MODEL"));
    mdl->setHeaderData(6, Qt::Horizontal, tr("ABONE BAŞLANGIÇ"));
    mdl->setHeaderData(7, Qt::Horizontal, tr("ABONE BİTİŞ"));
    mdl->setHeaderData(8, Qt::Horizontal, tr("ÜCRET"));

}
void OtoparkU::saati_goster(){
    QTime zaman = QTime::currentTime();
    ui->saat->display(zaman.toString());


}
OtoparkU::~OtoparkU(){
    delete ui;
}

void OtoparkU::on_yeniaracgiris_clicked(){
     yeniarac->setModal(true);
     yeniarac->show();
}

void OtoparkU::on_konum_clicked(){
    katlar->setModal(true);
    katlar->show();
}

void OtoparkU::on_abone_islemleri_clicked(){
    aboneislem->setModal(true);
    aboneislem->show();
}


void OtoparkU::on_arac_cikis_clicked(){


    araccikis->setModal(true);
    araccikis->show();
}

void OtoparkU::on_hakkimizda_clicked()
{
    bilgi->setModal(true);
    bilgi->show();
}

void OtoparkU::on_hizmetler_clicked()
{

    QMessageBox::information(this,"Hizmetler","Hizmetler Bölümümüz Versiyon Güncellemesi ile v 2.0 Eklenecektir.");
}

void OtoparkU::on_fiyat_tarifesi_clicked()
{
     QMessageBox::information(this,"Fiyat Tarifesi","Fiyat Tarifesi Bölümümüz Versiyon Güncellemesi ile v 2.0 Eklenecektir.");
}

void OtoparkU::on_FormCikis_clicked()
{
    qApp->exit(0);
}
