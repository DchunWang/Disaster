#include "testdb.h"
#include <QMessageBox>

TestDB::TestDB(QObject *parent) : QObject(parent)
{
    //初测试用
    initTest();


}

//作为初测试用
void TestDB::initTest()
{

    //采用MySQl数据库，建立一个数据库连接对象？？？
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");

    /** 问题一：
     * “数据库”与“数据库连接”有什么区别？？？
     * */

    /****************************设置,这些设置都起什么作用？？？*****************/
    //设置数据库主机名
    db.setHostName("localhost");
    //设置端口号
    //db.setPort(8080);
    //设置数据库登录用户名
    db.setUserName("root");
    //设置数据库登录密码
    db.setPassword("47592kbtd@#Google");
    //设置数据库名
    db.setDatabaseName("index_test");

    db.open();
    //打开数据库
    bool openDB = db.open();


    //之后修改
    if(openDB)
    {
        QMessageBox::information(0, tr("信息"), tr("已打开数据库"));

    }

    //创建数据库后，再创建数据库表，并进行插入数据
    QSqlQuery query;
    //新建数据库表
    query.exec("create table disa(id INT PRIMARY KEY UNIQUE AUTO_INCREMENT,"
               "name VARCHAR(20),"
               "hw INT");
    //向表中插入数据
    query.exec("insert into disa(name, hw) VALUE('shadi',55)");
    query.exec("insert into disa(name, hw) VALUE('tiandi', 22)");
    query.exec("insert into disa(name, hw) VLAUE('wang', 33)");
    query.exec("insert into disa(name, hw) VALUE('dechun', 44)");
    if(query.isActive())
    {
        QMessageBox::information(0, tr("执行情况"), tr("执行了语句"));
    }

    //查询数据库表中的数据
//    //QSqlQuery queryS;
//    query.exec("select name from disa");
//    //query.first();
//    QString tempStr = "T";

//    while(query.next())
//    {
//        //int qsss = query.value(1).toInt();
//        QString qsi = query.value(0).toString();
//        //QString teStr = query.first().value(2).toString();
//        tempStr += "+" + qsi;
//    }

//    //int qsss = query.value(1).toInt();
//    //QString qsi = query.value(0).toString();
//    //QString teStr = query.first().value(2).toString();
//    QMessageBox::information(0, tr("查询数据库表数据"), tempStr);









    //返回所有可用的数据库驱动清单
    QStringList DB_driverList = QSqlDatabase::drivers();
    //将上述的数据库驱动清单显示出来
    QString totalDriver;
    foreach(QString dStr, DB_driverList)
    {
        totalDriver += dStr + "--";
    }
    //QMessageBox::information(0, tr("所有可用的数据库驱动"), totalDriver);









}
