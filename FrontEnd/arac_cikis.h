#ifndef ARACCIKIS_H
#define ARACCIKIS_H

#include <QDialog>

namespace Ui {
class araccikis;
}

class araccikis : public QDialog
{
    Q_OBJECT

public:
    explicit araccikis(QWidget *parent = 0);
    ~araccikis();

private:
    Ui::araccikis *ui;
};

#endif // ARACCIKIS_H
