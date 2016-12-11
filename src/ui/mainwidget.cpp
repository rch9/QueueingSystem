#include "mainwidget.h"
#include <QApplication>
#include <QFont>
#include <QPushButton>
#include <iostream>


MainWidget::MainWidget():
    QWidget(),
    table(new TabTableWidget()),
    smo(new TabSMOWidget()),
    tabs(new QTabWidget()),
    restart(new QPushButton(tr("restart"))){

    initMainWidget();

    connect(restart, SIGNAL(clicked()), this, SLOT(clickRestart()));

    QPalette Pal;
    Pal.setColor(QPalette::Background, Qt::black);
    setPalette(Pal);    
}

// НУ ТУТ СРЕМНО, ДА
MainWidget::~MainWidget() {
    delete table;
    delete smo;
    delete tabs;
    delete restart;
}

void MainWidget::initMainWidget() {
    tabs->setParent(this);
    tabs->setFixedSize(600, 400);

    restart->setParent(this);
    restart->move(300, 500);


    setFixedSize(600, 600);

    tabs->addTab(table, "first");
    tabs->addTab(smo, "second");
}

void MainWidget::clickRestart() {
    std::cout << "EDAAA";
    close();
}
