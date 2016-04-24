#ifndef TESTDB_H
#define TESTDB_H

/**
 * 这个类只是用来做学习数据库的测试用例的
 * 为之后具体的数据库做一个样例，最后要删除
 * */

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QVariant>
#include "testshowdata.h"

class TestDB : public QObject
{
    Q_OBJECT
public:
    explicit TestDB(QObject *parent = 0);

    //初测试用函数
    void initTest();
    //创建水资源班数据库及表
    void createWaterResource();
    //将传递过来的字符串原样返回
    QString delegateString(QString);
    QString transQString();



signals:
    //传递字符串给其他窗体
    void giveString(QString);
    void givemodel(QSqlQueryModel*);

public slots:

public:
    //测试用，传递给其他窗体以显示具体的结果
    QString totalClassmate;
    //传递给数据显示窗体View的model
    QSqlQueryModel *secondWaterModel;
    TestShowData *showDataWidget;

};

#endif // TESTDB_H
