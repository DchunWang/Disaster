#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMainWindow>
#include <QtSql>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QTextEdit>
#include <QTableView>
#include <QStyleFactory>
#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QStandardItemModel>
#include <QSplitter>
#include <QFrame>





#include "login.h"
//#include "database/testdb.h"

class Widget : public QMainWindow
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

    //初始化
    void initWidget();
    //创建菜单栏
    void createMenu();
    //创建模型
    void createModel();
    //创建视图
    void createView();



signals:

    //通知main.cpp要退出主窗体，也即把整个程序都退出
    void quitWidget();

public slots:
    //显示主窗体
    void showWidget();

    //退出主窗体,不是隐藏主窗体
    void quitAll();



public:
    //登录窗体，作为主窗体的子窗体
    Login *loginInterface;

    //主窗体的总体布局
    QVBoxLayout *mainLayout;
    QSplitter *splitter;
    QHBoxLayout *minLayout;


    //菜单栏上的菜单及其中的命令
    QMenu *fileMenu;
    QAction *newAct;
    QAction *openAct;
    QAction *importAct;
    QAction *outputAct;
    QAction *exitAct;

    QMenu *dataMenu;
    QAction *redoAct;
    QAction *undoAct;
    QAction *handAct;

    QMenu *mineMenu;
    QAction *mineAct;

    //模型视图———— 只针对数据库表的
    QStandardItemModel *model;
    QTableView *table;
    //频繁项集的模型和视图
    QStandardItemModel *freModel;
    QTableView *freView;
    //关联规则的模型和视图
    QStandardItemModel *ruleModel;
    QTableView *ruleView;

    //最底下的最小支持度和最小置信度设置
    QLabel *minsupLabel;
    QLineEdit *minsupLineEdit;
    QLabel *minconfLabel;
    QLineEdit *minconfLineEdit;
    QPushButton *dataMineBtn;
    QFrame *minFrame;











};

#endif // WIDGET_H
