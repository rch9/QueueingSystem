//#include "mainwindow.h"
#include "resulttable.h"
//#include "modelcurrentstate.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ResultTable w;
    w.show();

    return a.exec();
}
