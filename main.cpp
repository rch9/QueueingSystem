//#include "mainwindow.h"
#include "resulttable.h"
#include "modelcurrentstate.h"
#include "layer.h"
#include "devicescontroller.h"
#include <QApplication>
#include "source.h"
#include <iostream>
#include "director.h"
#include "randomhelper.h"
#include <ctime>

int main(int argc, char *argv[]) {    

    srand(static_cast<unsigned>(time(0)));

//    std::cout << RandomHelper::rand_exponential(0.5) << std::endl;
//    std::cout << RandomHelper::rand_uniform(1, 2) << std::endl;
//    return 0;

    QApplication a(argc, argv);
    ResultTable r;
    ModelCurrentState m;

    r.show();
    m.show();


    m.exec();
    return r.exec();
}

