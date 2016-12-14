#include "modelcurrentstate.h"
#include "ui_modelcurrentstate.h"
#include <QTableWidgetItem>
#include <iostream>


ModelCurrentState::ModelCurrentState(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ModelCurrentState)
{
    ui->setupUi(this);

    auto rows = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(rows);
    ui->tableWidget->setItem(rows, 0, new QTableWidgetItem("ddddd"));
    ui->tableWidget->setItem(rows, 1, new QTableWidgetItem("aaaaa"));
    ui->tableWidget->setItem(rows, 2, new QTableWidgetItem("bbbbb"));
    ui->tableWidget->setEnabled(false);
//    ui->tableWidget->selectRow(0);


//    ui->mytable->selectRow(row);//Где row - число строк
//        model1->insertRow(row);
//        model1->setData(model1->index(row, 0), "");//Пустая строка
//        ui->mytable->setFocus();//Так как вызываю ф-ию из меню

}

ModelCurrentState::~ModelCurrentState()
{
    delete ui;
}
