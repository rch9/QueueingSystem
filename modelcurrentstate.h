#ifndef MODELCURRENTSTATE_H
#define MODELCURRENTSTATE_H

#include "layer.h"
#include <QDialog>
#include <QSpinBox>
#include <QTableWidget>
#include <vector>
//#include <string>

namespace Ui {
class ModelCurrentState;
}

class ModelCurrentState : public QDialog
{
    Q_OBJECT

public:
    explicit ModelCurrentState(QWidget *parent = 0);
    ~ModelCurrentState();

private slots:
    void changeSoursesSpinBox();
    void changeBufferSpinBox();
    void changeDevisesSpinBox();
    void pressStart();
    void pressStep();
    void pressClean();    

private:
    Ui::ModelCurrentState *ui;
    Layer* _layer;

    void fillTables();

private:
    void updateTableRows(QTableWidget *table, QSpinBox *spinBox);
    std::vector<float> getColumnFromTable(QTableWidget *table, int n) const;
};

#endif // MODELCURRENTSTATE_H
