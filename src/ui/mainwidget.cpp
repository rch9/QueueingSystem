#include "mainwidget.h"
#include <QApplication>
#include <QFont>
#include <QPushButton>
#include <iostream>


MainWidget::MainWidget():
    QWidget(),
    table(new TabTableWidget()),
    smo(new TabSMOWidget()),
    tabs(new QTabWidget()) {

    QPalette Pal;
    Pal.setColor(QPalette::Background, Qt::black);
    setPalette(Pal);

    initMainWidget();
}

// НУ ТУТ СРЕМНО, ДА
MainWidget::~MainWidget() {
    delete table;
    delete smo;
    delete tabs;
}

void MainWidget::initMainWidget() {
    tabs->setParent(this);
    tabs->setFixedSize(600, 400);



//    setFixedSize(600, 600);
    resize(600, 600);

    tabs->addTab(table, "first");
    tabs->addTab(smo, "second");
}
