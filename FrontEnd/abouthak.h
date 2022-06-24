#ifndef ABOUTHAK_H
#define ABOUTHAK_H

#include <QDialog>

namespace Ui {
class aboutHak;
}

class aboutHak : public QDialog
{
    Q_OBJECT

public:
    explicit aboutHak(QWidget *parent = 0);
    ~aboutHak();

private:
    Ui::aboutHak *ui;
};

#endif // ABOUTHAK_H
