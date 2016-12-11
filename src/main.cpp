#include "layer.h"
#include "gtest/gtest.h"
#include <random>
#include <chrono>
#include <iostream>
#include <QApplication>
#include <QtWidgets>
#include <QtUiTools/QtUiTools>
#include "ui/mainwidget.h"

int main(int argc, char *argv[]) {
    //    ::testing::InitGoogleTest(&argc, argv);

//    Layer layer(3, 3, 3, 2.f);
//    layer.run();

    QApplication app(argc, argv);
    MainWidget widget;
    widget.show();




    return app.exec();
    //    return RUN_ALL_TESTS();
}
