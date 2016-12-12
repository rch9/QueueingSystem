#include "tabsmowidget.h"
//#include <QApplication>

TabSMOWidget::TabSMOWidget():
    QWidget() {

    QPalette Pal;
    Pal.setColor(QPalette::Background, Qt::white);
    setPalette(Pal);

    resize(600, 400);
    setAutoFillBackground(true);
    setFixedSize(600, 400);

    initSMO();

}

void TabSMOWidget::initSMO() {
    for(int i = 0; i < 12; ++i) {
        _labels.push_back(new QLabel());
    }

    auto myfunc = [&](QLabel* label, int counter, int offsetX){
        label->setParent(this);
        label->setText("MY TEXT");
        label->move(offsetX, 20 + 20*counter);
    };

    for(int i = 0; i < 4; ++i) {
        myfunc(_labels.at(i + 0), i, 100);
        myfunc(_labels.at(i + 4), i, 200);
        myfunc(_labels.at(i + 8), i, 300);
    }
}

void TabSMOWidget::setSourceValue(const int &sourceNum, const float &value) {
    _labels.at(sourceNum)->setText(convertFloatToString(value));
}

void TabSMOWidget::setBufferValue(const int &bufferSlotNum, const float &value) {
    _labels.at(bufferSlotNum + 4)->setText(convertFloatToString(value));
}

void TabSMOWidget::setDeviceValue(const int &deviceNum, const float &value) {
    _labels.at(deviceNum + 8)->setText(convertFloatToString(value));
}

const char* TabSMOWidget::convertFloatToString(const float &value) const {
    return std::to_string(value).c_str();
}

