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
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");

    /** 问题一：
     * “数据库”与“数据库连接”有什么区别？？？
     * */

    /****************************设置,这些设置都起什么作用？？？*****************/
    //设置数据库主机名
//    db.setHostName("localhost");
//    //设置端口号
//    db.setPort(8080);
//    //设置数据库登录用户名
//    db.setUserName("root");
//    //设置数据库登录密码
//    db.setPassword("47592kbtd@#Google");
//    //设置数据库名
//    db.setDatabaseName("DB_name");

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
    query.exec("create table disa(id INTEGER,"
               "name nvarchar(20),"
               "hw INTEGER");
    //向表中插入数据
    query.exec("insert into disa(88,'shadi',55)");
    query.exec("insert into disa(77, 'tiandi', 22)");


    //查询数据库表中的数据
    //QSqlQuery queryS;
    query.exec("select soilType from disa");

    int qsss = query.value(1).toInt();
    QString qsi = query.value(2).toString();
    //QString teStr = query.first().value(2).toString();

    QMessageBox::information(0, tr("查询数据库表数据"), qsi);










}
