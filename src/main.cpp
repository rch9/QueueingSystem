#include "layer.h"
#include "gtest/gtest.h"
#include <random>
#include <chrono>
#include <iostream>
#include <QApplication>
#include <QtWidgets>
#include "QStandardItemModel"
#include "QStandardItem"

int main(int argc, char *argv[]) {
    //    ::testing::InitGoogleTest(&argc, argv);

//    Layer layer(3, 3, 3, 2.f);
//    layer.run();

    QApplication app(argc, argv);

    QTabWidget tab;

    QPalette Pal;

    // устанавливаем цвет фона
    Pal.setColor(QPalette::Background, Qt::black);


    QWidget window1, window2;

    tab.resize(600, 600);
    window1.resize(600, 400);
    window2.resize(600, 400);

    window1.setAutoFillBackground(true);
    window1.setPalette(Pal);
    window1.setFixedHeight(400);
    window2.setAutoFillBackground(true);
    window2.setPalette(Pal);
    window2.setFixedHeight(400);


    tab.addTab(&window1, "first");
    tab.addTab(&window2, "second");

    tab.show();
    return app.exec();
    //    return RUN_ALL_TESTS();
}
