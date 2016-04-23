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
    query.exec("insert into disa VALUE(3, 'wang', 33);");
    query.exec("insert into disa VALUE(4, 'dechun', 44);");

    //测试在SQL语句中使用变量
    //int inpId = 5;
    //QString inpName = "huang";
    //int inpHw = 89;
    //query.exec(QString("insert into disa VALUE(5, %1, 89);").arg(inpName));

    query.prepare("insert into disa VALUE(:id, :name, :hw);");
    query.bindValue(0, 5);
    query.bindValue(1, "huang");
    query.bindValue(2, 68);
    query.exec();



    query.exec("select * from disa;");
    QString total = "M";
    //query.next()指向查找到的第一条记录，然后每次后移一个记录
//    while(query.next())
//    {
//        //query.value(0)是id的值，将其转换为int
//        int idInt = query.value(0).toInt();
//        QString nameStr = query.value(1).toString();
//        int hwStr = query.value(2).toInt();
//        total += "++" + QString::number(idInt) + "++" +nameStr + "++" + QString::number(hwStr);
//    }
    //测试用
    //QMessageBox::information(0, tr("姓名"), total);

    if(query.isActive())
    {
        QMessageBox::information(0, tr("执行情况"), tr("执行了语句"));
    }



    //query.exec("select * from disa where name = 'huang';");
    while(query.next())
    {
        QString huangNameStr = query.value(1).toString();
        //QMessageBox::information(0, tr("变量测试"), huangNameStr);
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

void TestDB::createWaterResource()
{
    QSqlDatabase waterRDB = QSqlDatabase::addDatabase("QMYSQL", "secondCon");
    //这样会创建一个新的数据库吗？？？
    waterRDB.setDatabaseName("mydata");
    waterRDB.setHostName("localhost");
    waterRDB.setPort(3306);
    waterRDB.setUserName("root");
    waterRDB.setPassword("47592kbtd@#Google");
    //要打开数据库？？？
    waterRDB.open();

    QSqlQuery wrQuery(waterRDB);
    //先创建一个数据库的表
    wrQuery.exec("create table waterclass"
                 "(id INT PRIMARY KEY,"
                 "number VARCHAR(20),"
                 "name VARCHAR(100),"
                 "sex VARCHAR(20),"
                 "phone VARCHAR(20));");

    //批量插入数据
    wrQuery.prepare("INSERT INTO waterclass(id,number, name, sex, phone) VALUES(?, ?, ?, ?, ?)");
    //对id列插入数据
    QVariantList idList;
    idList<< 1 << 2 << 3 << 4 << 5 << 6 << 7 << 8<< 9 << 10 << 11 << 12 << 13 << 14 << 15;
//    foreach(QVariant d, idList)
//        wrQuery.bindValue(0, d);
    wrQuery.addBindValue(idList);
    //对number列插入数据
    QVariantList numberList;
    numberList<<"3033" << "3036" << "3043" << "3060" << "3066" <<
                "3104" << "3113" << "3115" << "3116" << "3128"<<
                "3130" << "3133" << "3134" << "3135" << "3137";
//    foreach(QVariant nb, numberList)
//        wrQuery.bindValue(1,nb);
    wrQuery.addBindValue(numberList);
    //对name列插入数据
    QVariantList nameList;
    nameList<<"杜屹笑" << "范丹丹" << "冯玉静" << "黄远征" << "赖斯麒" <<
              "龙悦敏" <<"欧阳子健" <<"彭思涵"<<"皮成名"<<"孙文丹"<<
              "谭铭欣" <<"田迪" <<"田珮力" <<"汪炜林" << "王德椿";
//    foreach(QVariant n, nameList)
//        wrQuery.bindValue(2, n);
    wrQuery.addBindValue(nameList);
    //对sex列插入数据
    QVariantList sexList;
    sexList<<"male" << "female" << "female" << "female" << "male" <<
             "female" << "male" << "female" << "male" << "female"<<
             "female" << "female" << "female" << "male" << "male";
//    foreach(QVariant v, sexList)
//        wrQuery.bindValue(3, v);
    wrQuery.addBindValue(sexList);
    //对phone列插入数据
    QVariantList phoneList;
    phoneList<<"613409" << "627855" << "613265" << "699142" << "629701" <<
               "627920" << "622704" << "625753" << "615613" << "617537" <<
               "616673" << "625930" << "625590" << "620381" << "628275";
//    foreach(QVariant ph, phoneList)
//        wrQuery.bindValue(4, ph);
    wrQuery.addBindValue(phoneList);

    wrQuery.finish();

    totalClassmate = "只有开头吗";

    if(!wrQuery.execBatch())
    {
        QMessageBox::critical(0, tr("警告"), tr("数据批处理错误！"));
    }
//    else
//    {
//        QSqlQuery otherQuery(waterRDB);
//        otherQuery.exec("select * from waterclass;");
        wrQuery.exec("select * from waterclass;");

        while(wrQuery.next())
        {
            QString classmateName = wrQuery.value(2).toString();
            totalClassmate +=  "\n" + classmateName ;

            //delegateString(totalClassmate);
        }

        emit giveString(totalClassmate);
//    }






}

QString TestDB::delegateString(QString s)
{
    return s;
}

QString TestDB::transQString()
{
    createWaterResource();
    return delegateString(totalClassmate);
}
