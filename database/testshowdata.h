#ifndef TESTSHOWDATA_H
#define TESTSHOWDATA_H

/**
 * 用于展示数据库中的数据，暂时只是做测试用，熟练之后再
 * 重新创建一个新的展示用窗体。
 * */

#include <QWidget>
#include <QTableView>
#include <QSqlQueryModel>
#include <QSplitter>
#include <QVBoxLayout>


//#include "testdb.h"

class TestShowData : public QWidget
{
    Q_OBJECT
public:
    explicit TestShowData(QWidget *parent = 0);

    //void showDataWidget();

signals:

public slots:



public:
    QTableView *showDataView;
    QSplitter *splitterWidget;
    QVBoxLayout *mainLayout;

    //接收model，给以QTableView;
    void setModel(QSqlQueryModel*);

    //TestDB *viewDB;



};

#endif // TESTSHOWDATA_H
