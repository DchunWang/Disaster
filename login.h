#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>

/**
 * 登录界面
 * */

class Login : public QWidget
{
    Q_OBJECT
public:
    explicit Login(QWidget *parent = 0, Qt::WindowFlags flags = 0);
    ~Login();
private:
    //初始化登录界面
    void init();

signals:
    //通知主窗体，让主窗体显示出来
    void ToShowWidget();

    //通知主窗体，让主窗体也退出
    void quitAllSignal();

public slots:
    //点击取消按钮，退出登录窗体
    void quitLogin();
    //点击登录按钮，退出登录窗体，并发送信号ToShowWidget()通知主窗体显示出来
    void login();

private:
    QLabel *nameLabel;
    QLabel *pwdLabel;
    QLineEdit *nameLineEdit;
    QLineEdit *pwdLineEdit;
    QPushButton *loginBtn;
    QPushButton *cancelBtn;

//    QHBoxLayout *nameLayout;
//    QHBoxLayout *pwdLayout;

    QGridLayout *npLayout;

    QHBoxLayout *loginLayout;

    QVBoxLayout *wholeLayout;


};

#endif // LOGIN_H
