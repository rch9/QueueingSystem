#ifndef RESULTTABLE_H
#define RESULTTABLE_H

#include <QDialog>
#include <QTableWidget>
#include <QSpinBox>

namespace Ui {
class ResultTable;
}

class ResultTable : public QDialog
{
    Q_OBJECT

public:
    explicit ResultTable(QWidget *parent = 0);
    ~ResultTable();

    void FillTable();

private slots:
    void changeSoursesSpinBox();
    void changeBufferSpinBox();
    void changeDevisesSpinBox();
    void pressStart();
    void pressStep();
    void pressBack();

private:
    Ui::ResultTable *ui;
    std::vector<float> getColumnFromTable(QTableWidget *table, int n) const;
    void updateTableRows(QTableWidget *table, QSpinBox *spinBox);
    void updateTableColumns(QTableWidget *table, QSpinBox *spinBox);
};

#endif // RESULTTABLE_H
