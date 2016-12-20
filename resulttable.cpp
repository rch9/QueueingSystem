#include "resulttable.h"
#include "ui_resulttable.h"
#include "modelcurrentstate.h"
#include "layer.h"
#include "director.h"
#include <iostream>

ResultTable::ResultTable(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ResultTable),
    _layer(new Layer)
{
    ui->setupUi(this);

    connect(ui->startButton, SIGNAL(pressed()), this, SLOT(pressStart()));
    connect(ui->soursesSpinBox, SIGNAL(valueChanged(int)), this, SLOT(changeSoursesSpinBox()));
    connect(ui->bufferSpinBox, SIGNAL(valueChanged(int)), this, SLOT(changeBufferSpinBox()));
    connect(ui->devisesSpinBox, SIGNAL(valueChanged(int)), this, SLOT(changeDevisesSpinBox()));
//    connect(ui->backButton, SIGNAL(pressed()), this, SLOT(pressBack()));
    connect(ui->cleanButton, SIGNAL(pressed()), this, SLOT(pressClean()));    
}

ResultTable::~ResultTable()
{
    delete ui;
    delete _layer;
}

void ResultTable::FillTable() {
    auto manager = StatisticsInfoManager::getInstance();
    auto nbids = manager->getNBidsTable();
    auto fbids = manager->getFBidsTable();
    auto tsys = manager->getTSysTable();
    auto tbuf = manager->getTBufTable();
    auto tdev = manager->getTDevTable();
    auto kdev = manager->getKTable();


    auto resTable = ui->resultTable;
    ui->resultTable->setRowCount(nbids.size());

    for (int i = 0; i < nbids.size(); ++i) {

        float p = static_cast<float>(fbids.at(i)) / static_cast<float>(nbids.at(i));

        resTable->setItem(i, 0, new QTableWidgetItem(std::to_string(nbids.at(i)).c_str()));
        resTable->setItem(i, 1, new QTableWidgetItem(std::to_string(fbids.at(i)).c_str()));
        resTable->setItem(i, 2, new QTableWidgetItem(std::to_string(p).c_str()));
        resTable->setItem(i, 3, new QTableWidgetItem(std::to_string(tsys.at(i)).c_str()));
        resTable->setItem(i, 4, new QTableWidgetItem(std::to_string(tbuf.at(i)).c_str()));
        resTable->setItem(i, 5, new QTableWidgetItem(std::to_string(tdev.at(i)).c_str()));
    }
    resTable->insertRow(resTable->rowCount());
    resTable->setItem(nbids.size(), 2, new QTableWidgetItem(std::to_string(manager->getAllP()).c_str()));

    ui->devKTable->setRowCount(kdev.size());

//    std::cout << "\n\nDIRECTOR: " << Director::getInstance()->getTime() <<  "\n";
    for (int i = 0; i < kdev.size(); ++i) {
        ui->devKTable->setItem(i, 0, new QTableWidgetItem(std::to_string(kdev.at(i) / Director::getInstance()->getTime()).c_str()));
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
    updateTableRows(ui->devKTable, ui->devisesSpinBox);
}

void ResultTable::pressStart() {

//    pressClean();

    std::vector<std::pair<float, float>> vectPair;
    auto vect1 = getRowFromTable(ui->sourcesTable, 0);
    auto vect2 = getRowFromTable(ui->sourcesTable, 1);


    for(size_t i = 0; i < vect1.size(); ++i) {
        vectPair.push_back(std::make_pair(vect1.at(i), vect2.at(i)));
    }

    _layer->setSMOAdgs(vectPair, ui->bufferSpinBox->text().toInt(), getRowFromTable(ui->devicesTable, 0), 10.f);

    for (int i = 0; i < ui->tickSpinBox->value(); ++i) {
        _layer->step();
    }


    FillTable();
}

void ResultTable::pressClean() {
    ui->tickSpinBox->setValue(1000);
    ui->soursesSpinBox->setValue(1);
    ui->devisesSpinBox->setValue(1);
    ui->bufferSpinBox->setValue(1);
    Director::getInstance()->cleanAll();
    StatisticsInfoManager::getInstance()->cleanAll();
    delete _layer;
    _layer = new Layer();
}


std::vector<float> ResultTable::getRowFromTable(QTableWidget *table, int n) const {
    std::vector<float> resultVect;

    for(int i = 0; i < table->columnCount(); ++i) {
        resultVect.push_back(table->item(n, i)->text().toFloat());
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
