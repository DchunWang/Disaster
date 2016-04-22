#include "widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setMinimumSize(600, 500);



    initWidget();

//    //测试用，看数据库要怎样与主窗体关联起来
//    W_testDB = new TestDB(this);
//    //接收数据库未打开信号，在QLineEdit显示”未打开数据库”字符串
//    connect(W_testDB, SIGNAL(testFailOpenSignal(QString)), this, SLOT(failOpenDB(QString)));
}

Widget::~Widget()
{

}

void Widget::initWidget()
{

    /*********************************登录界面设置*************************************/
    loginInterface = new Login();

    //测试用，之后删除
    //this->show();

//    loginInterface->move((/*this->geometry().x()+*/this->geometry().width()/2),
//                         (/*this->geometry().y()+*/this->geometry().height()/2));

    //该怎样设置登录界面的位置呢？？？？
    loginInterface->move(this->geometry().x()+this->geometry().width()/2,
                                this->geometry().y()+this->geometry().height()/2);
    //测试用，让登录界面显示出来
    loginInterface->show();

    //点击登录按钮后就把主窗体显示出来
    connect(loginInterface, SIGNAL(ToShowWidget()), this, SLOT(showWidget()));
    //点击取消按钮后就把整个程序退出
    connect(loginInterface, SIGNAL(quitAllSignal()), this, SLOT(quitAll()));






    /*********************************主窗体界面布局**************************************/
    mainLayout = new QVBoxLayout(this);


    //测试用
    W_testLineEdit = new QLineEdit;
    W_testBtn1 = new QPushButton;
    connect(W_testBtn1, SIGNAL(clicked()), this, SLOT(createTestDB()));


    mainLayout->addWidget(W_testLineEdit);
    mainLayout->addWidget(W_testBtn1);
    mainLayout->addStretch();

    /*****************************数据库设置？？？？***************************************/


//    //测试用，看数据库要怎样与主窗体关联起来
//    W_testDB = new TestDB(this);

//    //接收数据库未打开信号，在QLineEdit显示”未打开数据库”字符串
//    connect(W_testDB, SIGNAL(testFailOpenSignal(QString)), this, SLOT(failOpenDB(QString)));






}

//显示主窗体
void Widget::showWidget()
{
    this->show();

}

//退出主窗体，不是隐藏主窗体
void Widget::quitAll()
{
    //发出信号，让main.cpp关闭整个程序
    emit quitWidget();
}


//测试用，数据库为成功打开，在QLineEdit中显示传递过来的信息（“未打开数据”）
void Widget::failOpenDB(QString failStr)
{
    //QMessageBox::critical(0, tr("Error"), tr("未打开数据库"));
    W_testLineEdit->setText("初始测试");
}
//测试用，新建一个testdb对象
void Widget::createTestDB()
{
    //QMessageBox::critical(0, tr("Error"), tr("未打开数据库"));
    W_testDB = new TestDB(this);
    connect(W_testDB, SIGNAL(testFailOpenSignal(QString)), this, SLOT(failOpenDB(QString)));
}
