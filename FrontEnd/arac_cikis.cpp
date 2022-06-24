#include "arac_cikis.h"
#include "ui_araccikis.h"

araccikis::araccikis(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::araccikis)
{
    ui->setupUi(this);
}

araccikis::~araccikis()
{
    delete ui;
}
