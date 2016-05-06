#include "widget.h"
#include <QMessageBox>
#include <QDesktopWidget>

Widget::Widget(QWidget *parent)
    : QMainWindow(parent)
{
    //setMinimumSize(600, 500);
    //setFixedSize(800, 600);

    setStyle(QStyleFactory::create("Fusion"));

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

    /***********************************************************************************/
    createMenu();

    /*************************创建最底下的最小置信度和最小支持度设置**************************/
    minFrame = new QFrame;
    minLayout = new QHBoxLayout(minFrame);
    itemChooseLabel = new QLabel(tr("挖掘因子："));
    itemChoose = new QComboBox;
    itemChoose->addItem(tr("组合因子"));
    itemChoose->addItem(tr("暴雨强度"));
    itemChoose->addItem(tr("坡度"));
    itemChoose->addItem(tr("高程"));
    itemChoose->addItem(tr("植被覆盖率"));

    minsupLabel = new QLabel(tr("最小支持度："));
    minsupLineEdit = new QLineEdit;
    minconfLabel = new QLabel(tr("最小置信度："));
    minconfLineEdit = new QLineEdit;
    dataMineBtn = new QPushButton;
    dataMineBtn->setText(tr("关联挖掘"));

    minLayout->addStretch();
    minLayout->addWidget(itemChooseLabel);
    minLayout->addWidget(itemChoose);
    minLayout->addStretch();
    minLayout->addWidget(minsupLabel);
    minLayout->addWidget(minsupLineEdit);
    minLayout->addStretch();
    minLayout->addWidget(minconfLabel);
    minLayout->addWidget(minconfLineEdit);
    minLayout->addStretch();
    minLayout->addWidget(dataMineBtn);
    minLayout->addStretch();




    /*********************************主窗体界面布局**************************************/
    mainLayout = new QVBoxLayout(this);

    splitter = new QSplitter;
    splitter->setOrientation(Qt::Vertical);
    createModel();
    createView();
    splitter->addWidget(minFrame);
    setCentralWidget(splitter);
//    mainLayout->addWidget(splitter);
//    mainLayout->addLayout(minLayout);

    /***************************************添加主窗体的具体内容**************************/



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

void Widget::createMenu()
{
    fileMenu = menuBar()->addMenu(tr("文件"));
    newAct = new QAction(tr("新建"),this);
    openAct = new QAction(tr("打开"),this);
    importAct =new QAction(tr("导入"),this);
    outputAct = new QAction(tr("导出"),this);
    exitAct = new QAction(tr("退出"),this);
    fileMenu->addAction(newAct);
    fileMenu->addAction(openAct);
    fileMenu->addAction(importAct);
    fileMenu->addAction(outputAct);
    fileMenu->addAction(exitAct);

    dataMenu = menuBar()->addMenu(tr("数据管理"));
    redoAct = new QAction(tr("撤销"),this);
    undoAct = new QAction(tr("恢复"),this);

    //handAct = new QAction(tr("数据表"),this);
    dataMenu->addAction(redoAct);
    dataMenu->addAction(undoAct);

    subDataMenu = dataMenu->addMenu(tr("数据表"));
    disAct1 = new QAction(tr("灾害信息表"), this);
    disAct2 = new QAction(tr("暴雨信息表"), this);
    //disAct3 = new QAction(tr("高程信息表"), this);
    disAct4 = new QAction(tr("坡度信息表"), this);
    disAct5 = new QAction(tr("植被覆盖率表"), this);
    subDataMenu->addAction(disAct1);
    subDataMenu->addAction(disAct2);
    //subDataMenu->addAction(disAct3);
    subDataMenu->addAction(disAct4);
    subDataMenu->addAction(disAct5);
    //dataMenu->addAction(handAct);

    mineMenu = menuBar()->addMenu(tr("数据挖掘"));
    mineAct = new QAction(tr("关联挖掘"),this);
    otherAct = new QAction(tr("预处理"), this);
    mineMenu->addAction(otherAct);
    mineMenu->addAction(mineAct);
}

//创建模型
void Widget::createModel()
{
    //表视图的模型
    model = new QStandardItemModel(20, 6, this);
    model->setHeaderData(0, Qt::Horizontal, tr("区域"));
    model->setHeaderData(1, Qt::Horizontal, tr("暴雨强度"));
    model->setHeaderData(2, Qt::Horizontal, tr("坡度"));
    model->setHeaderData(3, Qt::Horizontal, tr("高程"));
    model->setHeaderData(4, Qt::Horizontal, tr("植被覆盖率"));
    model->setHeaderData(5, Qt::Horizontal, tr("山洪灾害"));

    //频繁项集的模型
    freModel = new QStandardItemModel(20, 2, this);
    freModel->setHeaderData(0, Qt::Horizontal, tr("频繁项集"));
    freModel->setHeaderData(1, Qt::Horizontal, tr("支持度"));

    //关联规则的模型
    ruleModel = new QStandardItemModel(20, 3, this);
    ruleModel->setHeaderData(0, Qt::Horizontal, tr("强规则"));
    ruleModel->setHeaderData(1, Qt::Horizontal, tr("支持度"));
    ruleModel->setHeaderData(2, Qt::Horizontal, tr("置信度"));

    //暴雨信息的模型
    ruinModel = new QStandardItemModel(20, 4, this);
    ruinModel->setHeaderData(0, Qt::Horizontal, tr("序号"));
    ruinModel->setHeaderData(1, Qt::Horizontal, tr("站名"));
    ruinModel->setHeaderData(2, Qt::Horizontal, tr("高程"));
    ruinModel->setHeaderData(3, Qt::Horizontal, tr("年均降雨量"));



}

//创建视图
void Widget::createView()
{
    //数据表视图
    table = new QTableView;
    table->setModel(model);
    QItemSelectionModel *itemModel = new QItemSelectionModel(model);
    table->setSelectionModel(itemModel);

    //频繁项集视图
    freView = new QTableView;
    freView->setModel(freModel);

    //关联规则视图
    ruleView = new QTableView;
    ruleView->setModel(ruleModel);

    //暴雨信息视图
    ruinView = new QTableView;
    ruinView->setModel(ruinModel);

    splitter->addWidget(ruinView);
    splitter->addWidget(table);
    splitter->addWidget(freView);
    splitter->addWidget(ruleView);
}
