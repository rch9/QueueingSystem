//#include "mainwindow.h"
#include "resulttable.h"
#include "modelcurrentstate.h"
#include "layer.h"
#include <QApplication>
#include "source.h"

int main(int argc, char *argv[]) {
//    QApplication a(argc, argv);
//    ModelCurrentState w;

//    w.show();

    Layer layer;

    std::vector<std::pair<float, float> > soursesArgs = {std::make_pair(0.f, 2.f), std::make_pair(0.f, 2.f), std::make_pair(0.f, 2.f)};
    size_t bufferSize = 4;
    std::vector<float> devisesArgs = {1.f, 0.1f, 2.f};
    float worktime = 10;

    layer.setSMOAdgs(soursesArgs, bufferSize, devisesArgs, worktime);
    layer.run();

    return 0;
//    return a.exec();
}

