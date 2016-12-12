#ifndef TABTABLEWIDGET_H
#define TABTABLEWIDGET_H
#include <QWidget>
#include <QTableWidget>

//FIXME
class TabTableWidget : public QWidget {
public:
    TabTableWidget();

private:
    void initTabTableWidget();
private:
    QTableWidget *_tableWidget;
};

#endif // TABTABLEWIDGET_H
