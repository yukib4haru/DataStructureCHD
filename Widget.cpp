#include "Widget.h"
#include "ui_widget.h"
#include"haru.h"
#include"Wife.h"
#include"List.h"
#include"List.cpp"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    initData();
    initWindow();   //初始化窗口
}

void Widget::initData()
{
    //    Wife wife[10];
    //    List<Wife> wifeList(wife,10);
    Laopo wife1 = {"东海帝皇",16,"Machico","开朗"};
    Laopo wife2 = {"艾拉",16,"雨宫天","温柔"};
    Laopo wife3 = {"惠惠",14,"李依李","傲娇"};
    Laopo wife4 = {"阿库娅",18,"雨宫天","活泼"};
    Laopo wife[100]={wife1,wife2,wife3,wife4};
    listLaopo = new List<Laopo>(wife,4);

    qDebug()<<"Length:"<<listLaopo->getLength();
    //Length:0 ?? 总算调对了

    Wife a("东海帝皇",16,"Machico","开朗");
    Wife b("艾拉",16,"雨宫天","温柔");
    Wife c("惠惠",14,"李依李","傲娇");
    Wife d("阿库娅",18,"雨宫天","活泼");
    Wife hougong[100]={a,b,c,d};
    //    List<Wife> listWife(hougong,4);
}

void Widget::initWindow()
{
    this->setWindowTitle("WifeManager");

    tableView = new QTableView;

    /* 设置表格视图大小 */
    this->setFixedSize(850,400);
    tableView->resize(850, 400);

    /* 创建数据模型 */
    model = new QStandardItemModel();

    model->setHorizontalHeaderLabels({"Name", "Age", "Vocal", "Character"});

    /* 自适应所有列，让它布满空间 */
    tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    /* 加载共length行数据，并每行有4列数据 */
    for (int i = 0; i < listLaopo->getLength(); i++) {
        /* 加载第一列(姓名)数据 */
        model->setItem(i, 0, new QStandardItem(QString(listLaopo->getItem(i+1).name)));
        /* 加载第二列(年龄)数据 */
        model->setItem(i, 1, new QStandardItem(QString("%1").arg(listLaopo->getItem(i+1).age)));
        /* 加载第三列(声优)数据 */
        model->setItem(i, 2, new QStandardItem(QString(listLaopo->getItem(i+1).vocal)));
        /* 加载第四列(性格)数据 */
        model->setItem(i, 3, new QStandardItem(QString(listLaopo->getItem(i+1).character)));
    }

    /* 设置表格视图数据 */
    tableView->setModel(model);

    //设置按钮
    QPushButton* btnA = new QPushButton("查找");
    QPushButton* btnB = new QPushButton("插入");
    QPushButton* btnC = new QPushButton("删除");
    btnA->setParent(tableView);
    btnB->setParent(tableView);
    btnC->setParent(tableView);
    btnA->move(150,350);
    btnB->move(350,350);
    btnC->move(550,350);

    connect(btnA, &QPushButton::clicked, this, &Widget::findSignal);
    connect(btnB, &QPushButton::clicked, this, &Widget::insertSignal);
    connect(btnC, &QPushButton::clicked, this, &Widget::deleteSignal);

    /* 显示 */
//    tableView->show();
    tableView->setParent(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::findSignal()
{
//    qDebug()<<"ok";
    bool ok;
    bool numok;
    QString text = QInputDialog::getText(this, "你要宠幸谁呢", "序号", QLineEdit::Normal, "", &ok);
    if (ok && !text.isEmpty())
    {
        int number = text.toInt(&numok);
        qDebug()<<"shuzi"<<number;
        if(numok)   find(number);     // 调用带参数的槽函数
        else QMessageBox::warning(this,"错误","输入不能为空或必须为整数!");
    }
}

void Widget::insertSignal()
{
    bool ok,numok1,numok2;
    int pos1,age1;
    QString text1, text2, text3, text4, text5;
    Laopo temp;

    // 弹出插入序号输入框
    text1 = QInputDialog::getText(this, "Position", "Position");
    pos1 = text1.toInt(&numok1);

    // 弹出第二个输入框
    text2 = QInputDialog::getText(this, "Name", "Name");

    // 弹出第三个输入框
    text3 = QInputDialog::getText(this, "Age", "Age");
    age1 = text3.toInt(&numok2);

    // 弹出第四个输入框
    text4 = QInputDialog::getText(this, "Vocal", "Vocal");

    // 弹出第五个输入框
    text5 = QInputDialog::getText(this, "Character", "Character", QLineEdit::Normal, "", &ok);

    if(ok && numok1 && numok2)
    {
        temp.name=text2;
        temp.age=age1;
        temp.vocal=text4;
        temp.character=text5;
        listLaopo->insert(pos1,temp);
//        qDebug()<<listLaopo->getItem(5).name;     //调试后忘记删除
        model->insertRow(pos1-1);
        model->setItem(pos1-1, 0, new QStandardItem(text2));
        model->setItem(pos1-1, 1, new QStandardItem(text3));
        model->setItem(pos1-1, 2, new QStandardItem(text4));
        model->setItem(pos1-1, 3, new QStandardItem(text5));
//      试图使用刷新来重新显示表格失败
//        initWindow();
//        this->tableView->update();
    }
    else QMessageBox::warning(this,"错误","检查一下哪里输错了吧！");
}

void Widget::deleteSignal()
{
    bool ok;
    bool numok;
    QString text = QInputDialog::getText(this, "你要逐出谁呢", "序号", QLineEdit::Normal, "", &ok);
    if (ok && !text.isEmpty())
    {
        int number = text.toInt(&numok);
        qDebug()<<"shuzi"<<number;
        if(numok)
        {
            listLaopo->remove(number);
            model->removeRow(number-1);
        }
        else QMessageBox::warning(this,"错误","输入不能为空或必须为整数!");
    }
}

void Widget::find(int num1)
{
    Laopo temp = listLaopo->getItem(num1);
    QString strAge = QString::number(listLaopo->getItem(num1).age);
    QString strData = "Name: " + temp.name + "\nAge: " + strAge + "\nVocal: " + temp.vocal + "\nCharacter: " + temp.character;
    QMessageBox msgBox;
    msgBox.setText(strData);
    msgBox.exec();
}
//void Widget::insert(QString name1,int age1,QString vocal1,QString character1){}
//void Widget::deleteWife(QString name1){}

