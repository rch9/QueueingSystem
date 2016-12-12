#ifndef TABSMOWIDGET_H
#define TABSMOWIDGET_H
#include <QWidget>
#include <QLabel>
#include <iostream>
#include <vector>
#include <string>

//FIXME! need rename
class TabSMOWidget : public QWidget {
public:
    TabSMOWidget();
    void initSMO();

    void setSourceValue(const int &sourceNum,     const float &value);
    void setBufferValue(const int &bufferSlotNum, const float &value);
    void setDeviceValue(const int &deviceNum,     const float &value);

private:
    const char *convertFloatToString(const float &value) const;
private:
    // тут будут храниться все устройства(буфер, источники и приборы)
    std::vector<QLabel*> _labels;
};

#endif // TABSMOWIDGET_H
