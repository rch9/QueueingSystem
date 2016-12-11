#ifndef MAINWIDGET_H
#define MAINWIDGET_H
#include <QTabWidget>
#include <QWidget>
#include "tabtablewidget.h"
#include "tabsmowidget.h"

class MainWidget : public QWidget {
public:
    MainWidget();
    void initMainWidget();

private:
    TabTableWidget table;
    TabSMOWidget smo;
    QTabWidget tabs;
};

#endif // MAINWIDGET_H
