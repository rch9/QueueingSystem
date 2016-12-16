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
    connect(ui->startButton, SIGNAL(pressed()), this, SLOT(pressStart()));
    connect(ui->stepButton, SIGNAL(pressed()), this, SLOT(pressStep()));
    connect(ui->backButton, SIGNAL(pressed()), this, SLOT(pressBack()));

    auto statisticsManager = StatisticsInfoManager::getInstance();

//    statisticsManager->getDevicesInfo()

    ui->soursesTable->setItem(0, 1, new QTableWidgetItem(statisticsManager->getSourcesInfo().at(1).at(1).c_str()));

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
}

void ModelCurrentState::pressStep() {
    _layer->run();
}

void ModelCurrentState::pressBack() {

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
