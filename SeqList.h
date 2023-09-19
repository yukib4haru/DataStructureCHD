#ifndef SEQLIST_H
#define SEQLIST_H

#include"haru.h"

template < class Element>
class SeqList : public QObject
{
    Q_OBJECT
public:
    explicit SeqList(QObject *parent = nullptr);
    SeqList();
    SeqList(Element a[],int n);
    ~SeqList();
    int getLength();
    Element getItem(int i);
    int locate(Element x);
    void insert(int i,Element x);
    /*Element*/void remove(int i);
    bool empty();
    void printList();
private:
    Element data[MaxSize];
    int length;
signals:

};

#endif // SEQLIST_H
