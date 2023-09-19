#include "List.h"

//无参构造函数
template<class Element>
List<Element>::List()
{
    length = 0;
}

template<class Element>
List<Element>::~List()
{

}

//有参构造函数
template<class Element>
List<Element>::List(Element a[],int n)
{
    if(n>MaxSize) throw "参数非法";
    for(int i=0;i<n;i++)
    {
        data[i] = a[i];
    }
    length = n;     //这行忘写了？构造函数？哈哈哈！
}
//求长度
template<class Element>
int List<Element>::getLength()
{
    return length;
}
//按位查找
template<class Element>
Element List<Element>::getItem(int i)
{
    if(i<1||i>length)
    {
        throw "查找位置非法";
        return data[0];
    }
    else return data[i-1];
}
//按值查找
template<class Element>
int List<Element>::locate(Element x)
{
    for(int i=0;i<length;i++)
        if(data[i]==x) return i+1;
    return 0;
}
//插入
template<class Element>
void List<Element>::insert(int i,Element x)
{
    if(length>=MaxSize)
    {
//        QMessageBox::warning(this,"错误","上溢");
        qDebug()<<"上溢";
    }
    if(i<1||i>length+1)
    {
//        QMessageBox::warning(this,"错误","位置异常");
        qDebug()<<"位置异常";
    }
    for(int j=length;j>=i;j--)
        data[j]=data[j-1];
    data[i-1]=x;
    length++;
}
//删除
template<class Element>
void/*Element*/ List<Element>::remove(int i)
{
    if(length == 0) throw"下溢";
    if(i<1||i>length) throw"删除位置错误";
//    Element x=data[i-1];
    for(int j=i;j<length;j++)
        data[j-1]=data[j];
    length--;
//    return x;
}

