#ifndef WIFE_H
#define WIFE_H

#include"haru.h"

class Wife : public QObject
{
public:
    Wife();
    Wife(QString name1,int age1,QString vocal1,QString character1);
    Wife(const Wife & a);
    QString getName(){return name;}
    int getAge(){return age;}
    QString getVocal(){return vocal;}
    QString getCharacter(){return character;}
private:
    QString name;
    int age;
    QString vocal;
    QString character;
signals:

};

#endif // WIFE_H
