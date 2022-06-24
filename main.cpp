#include "otoparku.h"
#include "FrontEnd/ulgnpnlformu.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ULgnPnlFormu w;
    w.show();

    return a.exec();
}
