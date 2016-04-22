#ifndef TESTDB_H
#define TESTDB_H

/**
 * 这个类只是用来做学习数据库的测试用例的
 * 为之后具体的数据库做一个样例，最后要删除
 * */

#include <QObject>
#include <QSqlDatabase>

class TestDB : public QObject
{
    Q_OBJECT
public:
    explicit TestDB(QObject *parent = 0);

    //初测试用函数
    void initTest();

signals:
    //测试用，看数据库是否打开,(把字符串传递给主窗体
    void testFailOpenSignal(QString);

public slots:

public:
    //测试用，传递给其他窗体以显示具体的结果
    //是否打开了数据库提示
    QString openDBStr;

};

#endif // TESTDB_H
