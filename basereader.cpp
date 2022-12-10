#include "basereader.h"
#include <QDataStream>

BaseReader::BaseReader() // : file(nullptr)
{
    createConnection();
    createTable();
}
BaseReader::~BaseReader()
{
    db.close();
}

bool BaseReader::createConnection()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("tasks.db");
    if(!db.open()) {
        qDebug() << "Cannot open database";
        return false;
    }
    return true;
}

void BaseReader::createTable()
{
    QSqlQuery query;
    QString s = "CREATE TABLE tasks (id INTEGER PRIMARY KEY NOT NULL, taskname VARCHAR(128), deadline VARCHAR(20), progress VARCHAR(5));";
    query.exec(s);
}

bool BaseReader::insertRecord(QString taskname, QString deadline, QString progress)
{
    QSqlQuery query;
    QString s = "INSERT INTO tasks (taskname, deadline, progress) VALUES('%1', '%2', '%3');";
    QString q = s.arg(taskname).arg(deadline).arg(progress);
    if (!query.exec(q)){
        qDebug() << "Unable to insert a record";
        return false;
    }
    return true;
}

void BaseReader::runTable()
{
    model = new QSqlTableModel(this);
    model->setTable("tasks");
    model->select();
    model->setEditStrategy(QSqlTableModel::EditStrategy::OnFieldChange);
    base = new BaseReader1(model);
    base->show();
}
