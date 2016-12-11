#include "tabtablewidget.h"
//#include <QApplication>
#include <iostream>

TabTableWidget::TabTableWidget():
    QWidget() {

    QPalette Pal;
    Pal.setColor(QPalette::Background, Qt::black);
    setPalette(Pal);

    resize(600, 400);
    setAutoFillBackground(true);
    setFixedSize(600, 400);
}
