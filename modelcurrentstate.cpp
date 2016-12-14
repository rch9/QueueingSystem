#include "modelcurrentstate.h"
#include "ui_modelcurrentstate.h"
#include <QTableWidgetItem>
#include <iostream>


ModelCurrentState::ModelCurrentState(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ModelCurrentState)
{
    ui->setupUi(this);

//    auto rows = ui->soursesTable->rowCount();
//    ui->soursesTable->insertRow(rows);
//    ui->soursesTable->setItem(rows, 0, new QTableWidgetItem("ddddd"));
//    ui->soursesTable->setItem(rows, 1, new QTableWidgetItem("aaaaa"));
//    ui->soursesTable->setItem(rows, 2, new QTableWidgetItem("bbbbb"));
//    ui->soursesTable->setEnabled(false);
    //    ui->tableWidget->selectRow(0);
    connect(ui->soursesSpinBox, SIGNAL(valueChanged(int)), this, SLOT(changeSoursesSpinBox()));
    connect(ui->bufferSpinBox, SIGNAL(valueChanged(int)), this, SLOT(changeBufferSpinBox()));
    connect(ui->devucesSpinBox, SIGNAL(valueChanged(int)), this, SLOT(changeDevisesSpinBox()));

}

ModelCurrentState::~ModelCurrentState()
{
    delete ui;
}

void ModelCurrentState::changeSoursesSpinBox() {
    updateTableRows(ui->soursesTable, ui->soursesSpinBox);
}

void ModelCurrentState::changeBufferSpinBox() {
    updateTableRows(ui->bufferTable, ui->bufferSpinBox);
}

void ModelCurrentState::changeDevisesSpinBox() {
    updateTableRows(ui->devicesTable, ui->devucesSpinBox);
}

void ModelCurrentState::updateTableRows(QTableWidget *table, QSpinBox *spinBox) {
    table->setRowCount(0);

    for (int i = 0; i < spinBox->value(); ++i) {
        table->insertRow(i);
    }
}
