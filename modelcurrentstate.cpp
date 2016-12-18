#include "modelcurrentstate.h"
#include "ui_modelcurrentstate.h"
#include <QTableWidgetItem>
#include <iostream>

#include "layer.h"

ModelCurrentState::ModelCurrentState(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ModelCurrentState),
    _layer(new Layer)
{
    ui->setupUi(this);

    connect(ui->soursesSpinBox, SIGNAL(valueChanged(int)), this, SLOT(changeSoursesSpinBox()));
    connect(ui->bufferSpinBox, SIGNAL(valueChanged(int)), this, SLOT(changeBufferSpinBox()));
    connect(ui->devucesSpinBox, SIGNAL(valueChanged(int)), this, SLOT(changeDevisesSpinBox()));
    connect(ui->startButton, SIGNAL(pressed()), this, SLOT(pressStart()));
    connect(ui->stepButton, SIGNAL(pressed()), this, SLOT(pressStep()));
    connect(ui->backButton, SIGNAL(pressed()), this, SLOT(pressBack()));
}

ModelCurrentState::~ModelCurrentState()
{
    delete ui;
    delete _layer;
}

// SLOTS
void ModelCurrentState::changeSoursesSpinBox() {
    updateTableRows(ui->soursesTable, ui->soursesSpinBox);
}

void ModelCurrentState::changeBufferSpinBox() {
    updateTableRows(ui->bufferTable, ui->bufferSpinBox);
}

void ModelCurrentState::changeDevisesSpinBox() {
    updateTableRows(ui->devicesTable, ui->devucesSpinBox);
}

void ModelCurrentState::pressStart() {
    std::vector<std::pair<float, float>> vectPair;
    auto vect1 = getColumnFromTable(ui->soursesTable, 2);
    auto vect2 = getColumnFromTable(ui->soursesTable, 3);


    for(size_t i = 0; i < vect1.size(); ++i) {
        vectPair.push_back(std::make_pair(vect1.at(i), vect2.at(i)));
    }

    _layer->setSMOAdgs(vectPair, ui->bufferSpinBox->text().toInt(), getColumnFromTable(ui->devicesTable, 3), 10.f);
    _layer->run();
    fillTables();
}

void ModelCurrentState::pressStep() {
//    _layer->run();
    _layer->step();
    fillTables();
}

void ModelCurrentState::pressBack() {

}

// pivate methods
void ModelCurrentState::fillTables() {

    auto context = StatisticsInfoManager::getInstance();

    auto sourcesStat = context->getSourcesStatistic();
    auto bufferStat  = context->getBufferStatistic();
    auto devicesStat = context->getDevicesStatistic();

    for (int i = 0; i < sourcesStat.size(); ++i) {
        ui->soursesTable->setItem(i, 0, new QTableWidgetItem(sourcesStat.at(i).at(0).c_str()));
        ui->soursesTable->setItem(i, 1, new QTableWidgetItem(sourcesStat.at(i).at(1).c_str()));
    }

    for (int i = 0; i < bufferStat.size(); ++i) {
        ui->bufferTable->setItem(i, 0, new QTableWidgetItem(bufferStat.at(i).at(0).c_str()));
        ui->bufferTable->setItem(i, 1, new QTableWidgetItem(bufferStat.at(i).at(1).c_str()));
    }

    for (int i = 0; i < devicesStat.size(); ++i) {
        ui->devicesTable->setItem(i, 0, new QTableWidgetItem(devicesStat.at(i).at(0).c_str()));
        ui->devicesTable->setItem(i, 1, new QTableWidgetItem(devicesStat.at(i).at(1).c_str()));
        ui->devicesTable->setItem(i, 2, new QTableWidgetItem(devicesStat.at(i).at(2).c_str()));
    }
}

// PRIVATE METHODS
void ModelCurrentState::updateTableRows(QTableWidget *table, QSpinBox *spinBox) {
    table->setRowCount(0);

    for (int i = 0; i < spinBox->value(); ++i) {
        table->insertRow(i);
    }
}

std::vector<float> ModelCurrentState::getColumnFromTable(QTableWidget *table, int n) const {
    std::vector<float> resultVect;

    for(int i = 0; i < table->rowCount(); ++i) {
        resultVect.push_back(table->item(i, n)->text().toFloat());
    }

    return resultVect;
}
