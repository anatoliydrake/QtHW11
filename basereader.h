#ifndef BASEREADER_H
#define BASEREADER_H

#include <QObject>
#include <QFile>
#include "basereader1.h"
#include <QDebug>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlDatabase>
#include <QSqlTableModel>

class BaseReader : public QObject
{
    Q_OBJECT
public:
    explicit BaseReader();
    virtual ~BaseReader();
    Q_INVOKABLE
    void runTable();
    Q_INVOKABLE
    bool insertRecord(QString taskname = "", QString deadline = "", QString progress = "");
    Q_INVOKABLE
    bool createConnection();
private:
    BaseReader1* base;
    QSqlDatabase db;
    QSqlTableModel* model;

signals:
    void initEnd(bool succed);
    void loadTask(QString task, QString deadline, QString progress);

private slots:

private:
    void createTable();
};

#endif // BASEREADER_H
