#include "widget.h"
#include <QApplication>
//#include "login.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;

    //测试用，看是否初次显示时，只显示登录界面而隐藏主窗体界面
    //w.show();
    //w.hide();
    //关联整个程序的关闭事件
    QObject::connect(&w, SIGNAL(quitWidget()), &a, SLOT(quit()));

//    Login *loginInterface = new Login();
//    loginInterface->show();
//    QObject::connect(loginInterface, SIGNAL(ToShowWidget()), w, SLOT(showWidget()));

    return a.exec();
}
