#include "basereader1.h"
#include "ui_basereader1.h"
#include <QDebug>
#include <QSqlQuery>
#include <QSqlRecord>

BaseReader1::BaseReader1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BaseReader1)
{
    ui->setupUi(this);

    createConnection();

    view = new QTableView(this);
    ui->setupUi(view);
    model = new QSqlTableModel(this);
    model->setTable("tasks");
    model->select();
    model->setEditStrategy(QSqlTableModel::EditStrategy::OnFieldChange);
    view->setModel(model);
}

BaseReader1::~BaseReader1()
{
    delete ui;
}

bool BaseReader1::createConnection()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("tasks.db");
    if(!db.open()) {
        qDebug() << "Cannot open database";
        return false;
    }
    return true;
}
