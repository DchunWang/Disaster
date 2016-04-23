#include "widget.h"
#include <QMessageBox>
#include <QDesktopWidget>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    //setMinimumSize(600, 500);
    setFixedSize(800, 600);

    createBool = false;

    initWidget();

}

Widget::~Widget()
{

}

void Widget::initWidget()
{

    /*********************************登录界面设置*************************************/
    loginInterface = new Login();

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



    //测试用
    W_testTextEdit = new QTextEdit;
    W_testBtn2 = new QPushButton(tr("显示学生名字"));
    connect(W_testBtn2, SIGNAL(clicked()), this, SLOT(showNameOnTextEdit()));



    mainLayout->addWidget(W_testLineEdit);
    mainLayout->addWidget(W_testBtn1);
    mainLayout->addWidget(W_testBtn2);
    mainLayout->addWidget(W_testTextEdit);
    mainLayout->addStretch();

    /*****************************数据库设置？？？？***************************************/


//    //测试用，看数据库要怎样与主窗体关联起来
    W_testDB = new TestDB(this);
    connect(W_testDB, SIGNAL(giveString(QString)), this, SLOT(receiveString(QString)));




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


//测试用，新建一个testdb对象
void Widget::createTestDB()
{
    //W_testDB = new TestDB(this);
    //createBool = true;
    //connect(W_testDB, SIGNAL(giveString(QString)), this, SLOT(receiveString(QString)));


}

//发出信号，通知testdb新建一个，从而将同学名字可以显示出来
void Widget::showNameOnTextEdit()
{
    //if(!createBool)
        //createTestDB();
    W_testDB->createWaterResource();
    connect(W_testDB, SIGNAL(giveString(QString)), this, SLOT(receiveString(QString)));

    //W_testTextEdit->setText(tempStr);
}

void Widget::receiveString(QString ms)
{
    W_testTextEdit->setText(ms);
}
