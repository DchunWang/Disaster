#include "login.h"
#include <QPalette>

Login::Login(QWidget *parent, Qt::WindowFlags flags)
    : QWidget(parent, flags)
{
    //设置登录窗体的固定大小
    setFixedSize(300, 200);
    //设置无边框、无法移动的登录窗体
    flags = Qt::CustomizeWindowHint;
    flags |= Qt::FramelessWindowHint;
    setWindowFlags(flags);
    //设置登录界面的颜色
    QPalette p;
    p.setColor(QPalette::Background, QColor(255, 255, 255, 255));
    setAutoFillBackground(true);
    setPalette(p);

    //初始化登录界面
    init();

}

void Login::init()
{
    nameLabel = new QLabel(tr("账号:"));
    nameLineEdit = new QLineEdit;
    pwdLabel = new QLabel(tr("密码:"));
    pwdLineEdit = new QLineEdit;
    loginBtn = new QPushButton(tr("登录"));
    cancelBtn = new QPushButton(tr("取消"));
    connect(cancelBtn, SIGNAL(clicked()), this, SLOT(quitLogin()));
    connect(loginBtn, SIGNAL(clicked()), this, SLOT(login()));

    npLayout = new QGridLayout;
    npLayout->addWidget(nameLabel, 0, 0);
    npLayout->addWidget(nameLineEdit, 0, 1);
    npLayout->addWidget(pwdLabel, 1, 0);
    npLayout->addWidget(pwdLineEdit, 1, 1);

    loginLayout = new QHBoxLayout;
    loginLayout->addStretch();
    loginLayout->addWidget(loginBtn);
    loginLayout->addWidget(cancelBtn);

    wholeLayout = new QVBoxLayout(this);
    wholeLayout->addLayout(npLayout);
    wholeLayout->addLayout(loginLayout);

}

//点击取消按钮，退出登录窗体，同时主窗体也退出
void Login::quitLogin()
{

    //测试用，只是隐藏了窗体，
    //this->hide();
    //this->quit();
    this->close();
    //发出信号，通知主窗体去关闭整个程序
    emit quitAllSignal();


}

//点击登录按钮，退出登录窗体，发送信号通知主窗体显示出来
void Login::login()
{
    this->close();

    emit ToShowWidget();
}

//析构函数
Login::~Login()
{
}
