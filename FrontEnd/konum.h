#ifndef KONUM_H
#define KONUM_H

#include <QDialog>
#include<QValidator>
#include<QMessageBox>
#include<QDateTime>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QDebug>

namespace Ui {
class Konum;
}

class Konum : public QDialog
{
    Q_OBJECT

public:
    explicit Konum(QWidget *parent = 0);
    ~Konum();

public slots:
    void show();

private:
    Ui::Konum *ui;
};

#endif // KONUM_H
