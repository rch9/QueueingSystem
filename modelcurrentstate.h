#ifndef MODELCURRENTSTATE_H
#define MODELCURRENTSTATE_H

#include <QDialog>

namespace Ui {
class ModelCurrentState;
}

class ModelCurrentState : public QDialog
{
    Q_OBJECT

public:
    explicit ModelCurrentState(QWidget *parent = 0);
    ~ModelCurrentState();

private:
    Ui::ModelCurrentState *ui;
};

#endif // MODELCURRENTSTATE_H
