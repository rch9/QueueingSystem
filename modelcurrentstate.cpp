#include "modelcurrentstate.h"
#include "ui_modelcurrentstate.h"
#include <QTableWidgetItem>
#include <iostream>


ModelCurrentState::ModelCurrentState(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ModelCurrentState)
{
    ui->setupUi(this);

    auto rows = ui->soursesTable->rowCount();
    ui->soursesTable->insertRow(rows);
    ui->soursesTable->setItem(rows, 0, new QTableWidgetItem("ddddd"));
    ui->soursesTable->setItem(rows, 1, new QTableWidgetItem("aaaaa"));
    ui->soursesTable->setItem(rows, 2, new QTableWidgetItem("bbbbb"));
    ui->soursesTable->setEnabled(false);
//    ui->tableWidget->selectRow(0);


}

ModelCurrentState::~ModelCurrentState()
{
    delete ui;
}
