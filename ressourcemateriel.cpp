#include "ressourcemateriel.h"
#include<QString>
#include <QtSql/qsqlquery.h>
#include <QDebug>


RessourceMateriel::RessourceMateriel()
{

}

RessourceMateriel::RessourceMateriel(QString B,QString C,QString D,double E,double F)
{

   // this->id_composant=ID;
    this->type_composant=B;
    this->etat_composant=C;
    this->nom_route=D;
    this->posx_composant=E;
    this->posy_composant=F;

}


double RessourceMateriel::getPosy_composant() const
{
    return posy_composant;
}

void RessourceMateriel::setPosy_composant(double value)
{
    posy_composant = value;
}

double RessourceMateriel::getPosx_composant() const
{
    return posx_composant;
}

void RessourceMateriel::setPosx_composant(double value)
{
    posx_composant = value;
}

QString RessourceMateriel::getNom_route() const
{
    return nom_route;
}

void RessourceMateriel::setNom_route(const QString &value)
{
    nom_route = value;
}

QString RessourceMateriel::getEtat_composant() const
{
    return etat_composant;
}

void RessourceMateriel::setEtat_composant(QString value)
{
    etat_composant = value;
}

QString RessourceMateriel::getType_composant() const
{
    return type_composant;
}

void RessourceMateriel::setType_composant(const QString &value)
{
    type_composant = value;
}

QString RessourceMateriel::getId_composant() const
{
    return id_composant;
}

void RessourceMateriel::setId_composant(const QString &value)
{
    id_composant = value;
}






bool RessourceMateriel:: AjouterComposant()
{


    QSqlQuery query;
    query.prepare("INSERT INTO RESSOURCE(TYPE_COMPOSANT ,ETAT_COMPOSANT, NOM_ROUTE  ,  POSX,POSY)"
                  "VALUES (:TYPE_COMPOSANT,:ETAT_COMPOSANT, :NOM_ROUTE ,  :POSX,:POSY)");

    query.bindValue(":TYPE_COMPOSANT",type_composant);
    query.bindValue(":ETAT_COMPOSANT",etat_composant);
    query.bindValue(":NOM_ROUTE",nom_route);
    query.bindValue(":POSX",posx_composant);
    query.bindValue(":POSY",posy_composant);



    return query.exec();

}

QSqlQueryModel *RessourceMateriel:: AfficherComposant()
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select *from RESSOURCE");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("TYPE_COMPOSANT"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("ETAT_COMPOSANT"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("NOM_ROUTE"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("POSX"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("POSY"));
    model->insertColumn(5);
    model->insertColumn(6);
    model->setHeaderData(5,Qt::Horizontal,QObject::tr(" "));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr(" "));



    return model;


}
bool RessourceMateriel::SupprimerComposant(QString id){

    QSqlQuery query;

    query.prepare("Delete from RESSOURCE where ID=:ID");
    query.bindValue(":ID",id);

       return query.exec();
}

bool RessourceMateriel::ModifierComposant(QString id,QString ETAT_COMPOSANT)
{qDebug()<<"Etat"<<ETAT_COMPOSANT;
    QSqlQuery query;
    query.prepare(" UPDATE RESSOURCE set  ETAT_COMPOSANT=:ETAT_COMPOSANT  where ID=:ID  ");
    query.bindValue(":ID",id);
    query.bindValue(":ETAT_COMPOSANT",ETAT_COMPOSANT);

    return query.exec();
}


QSqlQueryModel *RessourceMateriel::chercheComposant(int check,QString Search)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    QSqlQuery query;

    if(check==1)
    {
        qDebug("ouut ");
        qDebug()<<check<<" "<<Search;
        query.prepare("select * from RESSOURCE where NOM_ROUTE = ? ");
        query.addBindValue(Search);
        query.exec();
    }
    else  if(check==2)
    {
        query.prepare("select * from RESSOURCE where ETAT_COMPOSANT = ? ");
        query.addBindValue(Search);
        query.exec();
    }
     else if(check==3)
    {
        query.prepare("select * from RESSOURCE where TYPE_COMPOSANT = ?");
        query.addBindValue(Search);
        query.exec();
    }



    model->setQuery(query);
   // model->setQuery("select *from RESSOURCE");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("TYPE_COMPOSANT"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("ETAT_COMPOSANT"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("NOM_ROUTE"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("POSX"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("POSY"));
    model->insertColumn(5);
    model->insertColumn(6);
    model->setHeaderData(5,Qt::Horizontal,QObject::tr(" "));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr(" "));




  return model;
}
