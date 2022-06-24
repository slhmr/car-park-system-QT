#ifndef YENI_ABONE_KAYIT_H
#define YENI_ABONE_KAYIT_H

#include <QWidget>

namespace Ui {
class yeni_abone_kayit;
}

class yeni_abone_kayit : public QWidget
{
    Q_OBJECT

public:
    explicit yeni_abone_kayit(QWidget *parent = 0);
    ~yeni_abone_kayit();

private:
    Ui::yeni_abone_kayit *ui;
};

#endif // YENI_ABONE_KAYIT_H
