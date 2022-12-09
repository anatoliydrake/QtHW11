#ifndef BASEREADER1_H
#define BASEREADER1_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QTableView>

namespace Ui {
class BaseReader1;
}

class BaseReader1 : public QWidget
{
    Q_OBJECT

public:
    explicit BaseReader1(QWidget *parent = nullptr);
    ~BaseReader1();

private:
    Ui::BaseReader1 *ui;
    QSqlDatabase db;
    QSqlTableModel* model;
    QTableView* view;

private:
    bool createConnection();
};

#endif // BASEREADER1_H
