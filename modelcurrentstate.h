#ifndef MODELCURRENTSTATE_H
#define MODELCURRENTSTATE_H

#include <QDialog>
#include <QSpinBox>
#include <QTableWidget>

namespace Ui {
class ModelCurrentState;
}

class ModelCurrentState : public QDialog
{
    Q_OBJECT

public:
    explicit ModelCurrentState(QWidget *parent = 0);
    ~ModelCurrentState();

public slots:
    void changeSoursesSpinBox();
    void changeBufferSpinBox();
    void changeDevisesSpinBox();

private:
    Ui::ModelCurrentState *ui;

private:
    void updateTableRows(QTableWidget *table, QSpinBox *spinBox);
};

#endif // MODELCURRENTSTATE_H