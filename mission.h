#ifndef MISSION_H
#define MISSION_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class mission
{


    int cin;
    QString horaire,date,type,emplacement;

public:
    mission();
    mission(int ,QString,QString,QString,QString);

    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int );
    QSqlQueryModel * rechercheDynamic(QString);



};

#endif // MISSION_H
