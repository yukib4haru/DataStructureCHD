#ifndef HARU_H
#define HARU_H

#include <QString>
#include <QObject>
#include <QWidget>
#include <QApplication>
#include <QLocale>
#include <QTranslator>

#include <QTableView>
#include <QHeaderView>
#include <QStandardItemModel>

#include <QPushButton>
#include <QInputDialog>
#include <QMessageBox>
#include <QVBoxLayout>

struct Laopo
{
    QString name;
    int age;
    QString vocal;
    QString character;
};

#define MaxSize 100

#endif // HARU_H
