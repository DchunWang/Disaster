#ifndef TESTDB_H
#define TESTDB_H

/**
 * 这个类只是用来做学习数据库的测试用例的
 * 为之后具体的数据库做一个样例，最后要删除
 * */

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>

class TestDB : public QObject
{
    Q_OBJECT
public:
    explicit TestDB(QObject *parent = 0);

    //初测试用函数
    void initTest();

signals:

public slots:

public:
    //测试用，传递给其他窗体以显示具体的结果

};

#endif // TESTDB_H
