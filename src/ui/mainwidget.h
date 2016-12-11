#ifndef MAINWIDGET_H
#define MAINWIDGET_H
#include <QTabWidget>
#include <QWidget>
#include <QPushButton>
#include "tabtablewidget.h"
#include "tabsmowidget.h"

class MainWidget : public QWidget {
Q_OBJECT
public:
    MainWidget();
    ~MainWidget();
    void initMainWidget();

private:
    TabTableWidget* table;
    TabSMOWidget* smo;
    QTabWidget* tabs;
    QPushButton* restart;

public slots:
    void clickRestart();

};

#endif // MAINWIDGET_H
