#include "testdb.h"
#include <QMessageBox>

TestDB::TestDB(QObject *parent) : QObject(parent)
{
    //初测试用
    initTest();

    //测试用，之后删除
    openDBStr = "测试位置";
    emit testFailOpenSignal(openDBStr);



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
    //bool openDB = db.open();



    if(db.open())
    {
        //处理数据库没有打开时的情况
        //openDBStr = "未打开数据库";
        //发送信号给主窗体，显示出上面这句“未打开数据库"
        //emit testFailOpenSignal(openDBStr);
        QMessageBox::critical(0, tr("Error"), tr("未打开数据库"));

    }









}
