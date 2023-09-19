#ifndef LIST_H
#define LIST_H

#include"haru.h"

template < class Element>
class List
{
public:
    List();
    List(Element a[],int n);
    ~List();
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
};

#endif // LIST_H
