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
    connect(ui->soursesSpinBox, SIGNAL(valueChanged(int)), this, SLOT(clickRestart()));

}

ModelCurrentState::~ModelCurrentState()
{
    delete ui;
}

void ModelCurrentState::clickRestart() {

    auto table = ui->soursesTable;
    table->setRowCount(0);


    for (int i = 0; i < ui->soursesSpinBox->value(); ++i) {
        table->insertRow(i);
//        table->selectRow(i);
    }
}
