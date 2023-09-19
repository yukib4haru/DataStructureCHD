#ifndef WIDGET_H
#define WIDGET_H

#include"haru.h"
#include"List.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void initWindow();
    void initData();

private:
    Ui::Widget *ui;
    List<Laopo>* listLaopo;
    QTableView *tableView;
    QStandardItemModel* model;
signals:

public slots:
    void findSignal();
    void insertSignal();
    void deleteSignal();
    void find(int num1);
//    void insert(QString name1,int age1,QString vocal1,QString character1);
//    void deleteWife(QString name1);
};
#endif // WIDGET_H
