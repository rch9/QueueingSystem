#include "layer.h"
#include "gtest/gtest.h"
#include <random>
#include <chrono>
#include <iostream>
#include <QApplication>
#include <QtWidgets>
#include <QtUiTools/QtUiTools>
#include "ui/mainwidget.h"
#include <QLabel>

int main(int argc, char *argv[]) {
    //    ::testing::InitGoogleTest(&argc, argv);

    //    Layer layer(3, 3, 3, 2.f);
    //    layer.run();

    QApplication app(argc, argv);
    MainWidget widget;
    widget.show();

    //    QLabel *label = new QLabel();
    ////    label->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    //    label->setText("first line\nsecond line");
    //    label->move(200, 300);
    ////    label->setAlignment(Qt::AlignBottom | Qt::AlignRight);
    //    label->show();

    return app.exec();
    //    return RUN_ALL_TESTS();
}
