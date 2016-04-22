#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtSql>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>

#include "login.h"
#include "database/testdb.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

    //初始化
    void initWidget();

signals:
//    //隐藏本窗体信号，发送给main.cpp，
//    void hideWidget();

    //通知main.cpp要退出主窗体，也即把整个程序都退出
    void quitWidget();

public slots:
    //显示主窗体
    void showWidget();

    //退出主窗体,不是隐藏主窗体
    void quitAll();


    //测试用，数据库没有成功打开，在QLineEdit显示“未打开数据库”信息
    void failOpenDB(QString);
    //测试用，新建一个数据库相关的对象
    void createTestDB();


public:
    //登录窗体，作为主窗体的子窗体
    Login *loginInterface;

    //主窗体的总体布局
    QVBoxLayout *mainLayout;




    /********************************以下成员变量做测试用，之后删除*****************/
    //测试用，显示是否打开了数据库
    QLineEdit *W_testLineEdit;
    //测试用，看数据库是否打开了
    QString W_testDBOpen;
    //测试用，点击按钮后就新建一个数据库相关的对象
    QPushButton *W_testBtn1;


    //测试用，看数据库要怎样与主窗体关联起来
    TestDB *W_testDB;





};

#endif // WIDGET_H
