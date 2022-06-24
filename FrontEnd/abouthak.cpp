#include "abouthak.h"
#include "ui_abouthak.h"

aboutHak::aboutHak(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::aboutHak)
{
    ui->setupUi(this);
}

aboutHak::~aboutHak()
{
    delete ui;
}
