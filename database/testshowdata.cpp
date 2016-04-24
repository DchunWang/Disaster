#include "testshowdata.h"

TestShowData::TestShowData(QWidget *parent) : QWidget(parent)
{
//    viewDB = new TestDB(this);
//    connect(viewDB, SIGNAL(givemodel(QSqlQueryModel*)), this, SLOT(setModel(QSqlQueryModel*)));

    showDataView = new QTableView();

    splitterWidget = new QSplitter(Qt::Vertical,this);
    splitterWidget->addWidget(showDataView);

    mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(splitterWidget);


}

void TestShowData::setModel(QSqlQueryModel *mod)
{
    showDataView->setModel(mod);


    this->show();
}
