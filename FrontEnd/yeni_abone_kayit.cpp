#include "yeni_abone_kayit.h"
#include "ui_yeni_abone_kayit.h"

yeni_abone_kayit::yeni_abone_kayit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::yeni_abone_kayit)
{
    ui->setupUi(this);
}

yeni_abone_kayit::~yeni_abone_kayit()
{
    delete ui;
}
