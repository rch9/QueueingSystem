#ifndef MAINWIDGET_H
#define MAINWIDGET_H
#include <QTabWidget>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
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
    QLabel* label;

public slots:
    void clickRestart();

};

#endif // MAINWIDGET_H
