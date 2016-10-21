#include "gtest/gtest.h"
//#include <QtCore>
#include <QApplication>
#include <QtWidgets>
//#include <QLabel>
//#include <Qt  Gui>

int main(int argc, char *argv[]) {
//    ::testing::InitGoogleTest(&argc, argv);


    QApplication app(argc, argv);
    QDialog *dialog = new QDialog;
    QLabel *label = new QLabel(dialog);
    label->setText("<font color=red>Hello, World!</font>");
    dialog->show();
    return app.exec();



//    return RUN_ALL_TESTS();
}
