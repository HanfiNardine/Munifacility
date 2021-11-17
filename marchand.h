#ifndef MARCHAND_H
#define MARCHAND_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class marchand
{
   QString nom,prenom,emplacement;
   int numero;
public:
    marchand();

    marchand(QString ,QString,QString,int);


    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int);
    QSqlQueryModel * rechercheDynamic(QString);
};

#endif // MARCHAND_H
