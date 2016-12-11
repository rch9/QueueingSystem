#include "tabsmowidget.h"
//#include <QApplication>

TabSMOWidget::TabSMOWidget():
    QWidget() {

    QPalette Pal;
    Pal.setColor(QPalette::Background, Qt::white);
    setPalette(Pal);

    resize(600, 400);
    setAutoFillBackground(true);
    setFixedSize(600, 400);
}
