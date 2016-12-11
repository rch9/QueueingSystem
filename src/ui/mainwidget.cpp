#include "mainwidget.h"
#include <QApplication>
#include <QFont>
#include <QPushButton>
#include <iostream>


MainWidget::MainWidget():
    QWidget() {

    QPalette Pal;
    Pal.setColor(QPalette::Background, Qt::green);
    setPalette(Pal);

    initMainWidget();
}

void MainWidget::initMainWidget() {
    tabs.setParent(this);
    tabs.setFixedSize(600, 400);

//    setFixedSize(600, 600);
    resize(600, 600);

    tabs.addTab(&table, "first");
    tabs.addTab(&smo, "second");
}
