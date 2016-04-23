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
    //添加数据库驱动
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
    db.setDatabaseName("mydata");

    db.open();
    //打开数据库
    bool openDB = db.open();


    //之后修改
    if(openDB)
    {
        QMessageBox::information(0, tr("信息"), tr("已打开数据库"));

    }

    //创建数据库后，再创建数据库表，并进行插入数据
    QSqlQuery query(db);
    //新建数据库表
    query.exec("create table disa(id INT PRIMARY KEY UNIQUE AUTO_INCREMENT,"
               "name VARCHAR(20),"
               "hw INT);");
    //向表中插入数据
    query.exec("insert into disa VALUE(1, 'shadi',55);");
    query.exec("insert into disa VALUE(2, 'tiandi', 22);");
    query.exec("insert into disa VLAUE(3, 'wang', 33);");
    query.exec("insert into disa VALUE(4, 'dechun', 44);");




    query.exec("select * from disa;");
    QString total = "M";
    //query.next()指向查找到的第一条记录，然后每次后移一个记录
    while(query.next())
    {
        //query.value(0)是id的值，将其转换为int
        int idInt = query.value(0).toInt();
        QString nameStr = query.value(1).toString();
        QString hwStr = query.value(2).toString();
        total += "++" + nameStr + "++" + hwStr + "++" + QString::number(idInt);
    }
    //测试用
    QMessageBox::information(0, tr("姓名"), total);

    if(query.isActive())
    {
        QMessageBox::information(0, tr("执行情况"), tr("执行了语句"));
    }






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
