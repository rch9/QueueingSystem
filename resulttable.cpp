#include "resulttable.h"
#include "ui_resulttable.h"
#include "layer.h"

ResultTable::ResultTable(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ResultTable)
{
    ui->setupUi(this);

    connect(ui->startButton, SIGNAL(pressed()), this, SLOT(pressStart()));
    connect(ui->soursesSpinBox, SIGNAL(valueChanged(int)), this, SLOT(changeSoursesSpinBox()));
    connect(ui->bufferSpinBox, SIGNAL(valueChanged(int)), this, SLOT(changeBufferSpinBox()));
    connect(ui->devisesSpinBox, SIGNAL(valueChanged(int)), this, SLOT(changeDevisesSpinBox()));
}

ResultTable::~ResultTable()
{
    delete ui;
}

void ResultTable::FillTable() {
    auto manager = StatisticsInfoManager::getInstance();
    auto nbids = manager->getNBidsTable();
    auto fbids = manager->getFBidsTable();
    auto tsys = manager->getTSysTable();
    auto tbuf = manager->getTBufTable();
    auto tdev = manager->getTDevTable();


    auto resTable = ui->resultTable;
    ui->resultTable->setRowCount(nbids.size());

    for (int i = 0; i < nbids.size(); ++i) {
        resTable->setItem(i, 0, new QTableWidgetItem(std::to_string(nbids.at(i)).c_str()));
        resTable->setItem(i, 1, new QTableWidgetItem(std::to_string(fbids.at(i)).c_str()));
        resTable->setItem(i, 2, new QTableWidgetItem(std::to_string(tsys.at(i)).c_str()));
        resTable->setItem(i, 3, new QTableWidgetItem(std::to_string(tbuf.at(i)).c_str()));
        resTable->setItem(i, 4, new QTableWidgetItem(std::to_string(tdev.at(i)).c_str()));
    }

}

void ResultTable::changeSoursesSpinBox() {
    updateTableColumns(ui->sourcesTable, ui->soursesSpinBox);
    updateTableRows(ui->resultTable, ui->soursesSpinBox);
}

void ResultTable::changeBufferSpinBox() {

}

void ResultTable::changeDevisesSpinBox() {
    updateTableColumns(ui->devicesTable, ui->devisesSpinBox);
}

void ResultTable::pressStart() {

}

void ResultTable::pressStep() {

}

void ResultTable::pressBack() {

}

std::vector<float> ResultTable::getColumnFromTable(QTableWidget *table, int n) const {
    std::vector<float> resultVect;

    for(int i = 0; i < table->columnCount(); ++i) {
        resultVect.push_back(table->item(i, n)->text().toFloat());
    }

    return resultVect;
}

void ResultTable::updateTableRows(QTableWidget *table, QSpinBox *spinBox) {
    table->setRowCount(0);

    for (int i = 0; i < spinBox->value(); ++i) {
        table->insertRow(i);
    }
}

void ResultTable::updateTableColumns(QTableWidget *table, QSpinBox *spinBox) {
    table->setColumnCount(0);

    for (int i = 0; i < spinBox->value(); ++i) {
        table->insertColumn(i);
    }
}
