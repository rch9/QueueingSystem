#ifndef RESULTTABLE_H
#define RESULTTABLE_H

#include <QDialog>
#include <QTableWidget>
#include <QSpinBox>
#include "layer.h"
namespace Ui {
class ResultTable;
}

class ResultTable : public QDialog
{
    Q_OBJECT

public:
    explicit ResultTable(QWidget *parent = 0);
    ~ResultTable();

    void FillTable();

    std::vector<float> getRowFromTable(QTableWidget *table, int n) const;

private slots:
    void changeSoursesSpinBox();
    void changeBufferSpinBox();
    void changeDevisesSpinBox();
    void pressStart();
    void pressClean();    

private:
    Ui::ResultTable *ui;
    std::vector<float> getColumnFromTable(QTableWidget *table, int n) const;
    void updateTableRows(QTableWidget *table, QSpinBox *spinBox);
    void updateTableColumns(QTableWidget *table, QSpinBox *spinBox);

private:
    Layer *_layer;
};

#endif // RESULTTABLE_H
