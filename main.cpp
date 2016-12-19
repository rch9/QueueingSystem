//#include "mainwindow.h"
#include "resulttable.h"
#include "modelcurrentstate.h"
#include "layer.h"
#include "devicescontroller.h"
#include <QApplication>
#include "source.h"
#include <iostream>
#include "director.h"

int main(int argc, char *argv[]) {    

    Layer layer;

    std::vector<std::pair<float, float> > soursesArgs = {std::make_pair(1.f, 3.f), std::make_pair(1.f, 3.f), std::make_pair(1.f, 3.f)};
    size_t bufferSize = 3;
    std::vector<float> devisesArgs = {1.f, 1.f, 1.f};
    float worktime = 10;

    layer.setSMOAdgs(soursesArgs, bufferSize, devisesArgs, worktime);

    for (int i = 0; i  < 10; ++i) {
        std::cout << "====loop N: " << i << "=====\n\n";
        layer.step();
    }


    //    QApplication a(argc, argv);
    //    ModelCurrentState w;

    //    w.show();

    return 0;
    //    return a.exec();
}

