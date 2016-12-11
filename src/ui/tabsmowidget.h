#ifndef TABSMOWIDGET_H
#define TABSMOWIDGET_H
#include <QWidget>
#include <QLabel>
#include <iostream>

class TabSMOWidget : public QWidget {
public:
    TabSMOWidget();
    void initSMO();

    QLabel* label;
};

#endif // TABSMOWIDGET_H
