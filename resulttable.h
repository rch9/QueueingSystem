#ifndef RESULTTABLE_H
#define RESULTTABLE_H

#include <QDialog>

namespace Ui {
class ResultTable;
}

class ResultTable : public QDialog
{
    Q_OBJECT

public:
    explicit ResultTable(QWidget *parent = 0);
    ~ResultTable();

private:
    Ui::ResultTable *ui;
};

#endif // RESULTTABLE_H
