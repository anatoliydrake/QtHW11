#include "basereader1.h"
#include "ui_basereader1.h"
#include <QDebug>
#include <QSqlQuery>
#include <QSqlRecord>

BaseReader1::BaseReader1(QSqlTableModel *mdl) : model(mdl)
{
    ui->setupUi(this);
    view = new QTableView(this);
    ui->setupUi(view);
    view->setModel(model);
}

BaseReader1::~BaseReader1()
{
    delete ui;
}
