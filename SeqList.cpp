#include "SeqList.h"

template<class Element>
SeqList<Element>::SeqList(QObject *parent)
    : QObject{parent}
{
    length = 0;
}
//无参构造函数
template<class Element>
SeqList<Element>::SeqList()
{
    length = 0;
}
//有参构造函数
template<class Element>
SeqList<Element>::SeqList(Element a[],int n)
{
    if(n>MaxSize) throw "参数非法";
    for(int i=0;i<n;i++)
    {
        data[i] = a[i];
    }
}
//求长度
template<class Element>
int SeqList<Element>::getLength()
{
    return length;
}
//按位查找
template<class Element>
Element SeqList<Element>::getItem(int i)
{
    if(i<1||i>length) throw "查找位置非法";
    else return data[i-1];
}
//按值查找
template<class Element>
int SeqList<Element>::locate(Element x)
{
    for(int i=0;i<length;i++)
        if(data[i]==x) return i+1;
    return 0;
}
//插入
template<class Element>
void SeqList<Element>::insert(int i,Element x)
{
    if(length>=MaxSize) throw"上溢";
    if(i<1||i>length+1) throw"位置异常";
    for(int j=length;j>=i;j--)
        data[j]=data[j-1];
    data[i-1]=x;
    length++;
}
//删除
template<class Element>
void /*Element*/ SeqList<Element>::remove(int i)
{
    if(length == 0) throw"下溢";
    if(i<1||i>length) throw"删除位置错误";
//    x=data[i-1];
    for(int j=i;j<length;j++)
        data[j-1]=data[j];
    length--;
//    return x;
}
