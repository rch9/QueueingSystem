#include "gtest/gtest.h"
#include <QApplication>
#include <QtWidgets>
#include "random"
#include <chrono>
#include "iostream"

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);


    QApplication app(argc, argv);
    QDialog *dialog = new QDialog;
    QLabel *label = new QLabel(dialog);
    label->setText("<font color=red>Hello, World!</font>");
    dialog->show();
    app.exec();


    return RUN_ALL_TESTS();
}







