#include "tabtablewidget.h"
//#include <QApplication>
#include <iostream>

TabTableWidget::TabTableWidget():
    QWidget(),
    _tableWidget(new QTableWidget()) {

    QPalette Pal;
    Pal.setColor(QPalette::Background, Qt::white);
    setPalette(Pal);

    resize(600, 400);
//    setAutoFillBackground(true);
    setFixedSize(600, 400);

    initTabTableWidget();
}

void TabTableWidget::initTabTableWidget() {
    _tableWidget->setParent(this);
    QStringList list;

        _tableWidget->setColumnCount(5);
        _tableWidget->setRowCount(6);

    list.push_back("row1");
    list.push_back("row2");
    list.push_back("row3");
    list.push_back("row4");
    list.push_back("row5");
    _tableWidget->setHorizontalHeaderLabels(list);

    _tableWidget->setFixedSize(600, 400);
}
