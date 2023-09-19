#include "Wife.h"
#include"haru.h"

Wife::Wife()
{
    name = "你没有老婆";
    age = 0 ;
    vocal = "你没有老婆";
    character = "你没有老婆";
}

Wife::Wife(QString name1,int age1,QString vocal1,QString character1)
{
    name = name1;
    age = age1;
    vocal = vocal1;
    character = character1;
}

Wife::Wife(const Wife & a)
{
    name = a.name;
    age = a.age;
    vocal = a.vocal;
    character = a.character;
}
