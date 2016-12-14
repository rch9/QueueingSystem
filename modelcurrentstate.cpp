#include "modelcurrentstate.h"
#include "ui_modelcurrentstate.h"

ModelCurrentState::ModelCurrentState(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ModelCurrentState)
{
    ui->setupUi(this);
}

ModelCurrentState::~ModelCurrentState()
{
    delete ui;
}
