#include "layer.h"
#include "gtest/gtest.h"
//#include <QApplication>
//#include <QtWidgets>
#include <random>
#include <chrono>
#include <iostream>

int main(int argc, char *argv[]) {
//    ::testing::InitGoogleTest(&argc, argv);


//    QApplication app(argc, argv);
//    QDialog *dialog = new QDialog;
//    QLabel *label = new QLabel(dialog);
//    label->setText("<font color=red>Hello, World!</font>");
//    dialog->show();
//    app.exec();


    Layer layer(3, 3, 3, 1.f);
    layer.run();

    return 0;
//    return RUN_ALL_TESTS();
}







