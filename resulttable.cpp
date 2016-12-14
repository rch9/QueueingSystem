#include "resulttable.h"
#include "ui_resulttable.h"

ResultTable::ResultTable(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ResultTable)
{
    ui->setupUi(this);
}

ResultTable::~ResultTable()
{
    delete ui;
}
