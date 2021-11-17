#include "reclamation.h"
#include<QString>
#include <QtSql/qsqlquery.h>
#include<QDebug>
Reclamation::Reclamation()
{

}

Reclamation::Reclamation(QString ROUTE,QString TYPE,QString DATE,QString NATURE,QString ID_COMP){

  //  this->id_reclamation=ID;
    this->nom_route=ROUTE;
    this->type_panne=TYPE;
    this->date=DATE;
   // this->etat_reclamatio=ETAT;
    this->Nature=NATURE;
    this->ID_COMP=ID_COMP;

}

/*
int Reclamation::getEtat_reclamatio() const
{
    return etat_reclamatio;
}

void Reclamation::setEtat_reclamatio(int value)
{
    etat_reclamatio = value;
}
*/
QString Reclamation::getType_panne() const
{
    return type_panne;
}

void Reclamation::setType_panne(const QString &value)
{
    type_panne = value;
}

QString Reclamation::getNom_route() const
{
    return nom_route;
}

void Reclamation::setNom_route(const QString &value)
{
    nom_route = value;
}

QString Reclamation::getId_reclamation() const
{
    return id_reclamation;
}

void Reclamation::setId_reclamation(int value)
{
    id_reclamation = value;
}


bool Reclamation:: AjouterReclamation()
{

    QSqlQuery query;
    query.prepare("INSERT INTO RECLAMATION(NOM_ROUTE ,TYPE_PANNE, DATE_RECLAMAT  ,NATURE,ID_COMP)"
                  "VALUES (:NOM_ROUTE,:TYPE_PANNE, :DATE_RECLAMAT ,:NATURE,:ID_COMP)");

    query.bindValue(":NOM_ROUTE",nom_route);
    query.bindValue(":TYPE_PANNE",type_panne);
    query.bindValue(":DATE_RECLAMAT",date);
   // query.bindValue(":ETAT_RECL",etat_reclamatio);
    query.bindValue(":NATURE",Nature);
  //  query.bindValue(":ID",id_reclamation);
    query.bindValue(":ID_COMP",ID_COMP);




    return query.exec();

}
QSqlQueryModel *Reclamation::AfficherReclamation()
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select *from RECLAMATION");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("NOM_ROUTE"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("TYPE_PANNE"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("DATE_RECLAMAT"));
    //model->setHeaderData(3,Qt::Horizontal,QObject::tr("ETAT_RECL"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("NATURE"));
    model->insertColumn(4);
    model->insertColumn(5);
    model->setHeaderData(4,Qt::Horizontal,QObject::tr(" "));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr(" "));




    return model;
}

bool Reclamation::SupprimerReclamation(QString id){

    QSqlQuery query;

    query.prepare("Delete from RECLAMATION where ID=:ID");
    query.bindValue(":ID",id);

       return query.exec();
}

bool Reclamation::ModifierReclamation(QString id,QString Nature)
{
    qDebug()<<"ID:"<<id;
        qDebug()<<"Nature:"<<Nature;
    QSqlQuery query;
    qDebug("modifier ");
 //   QString res=QString::number(Ref);
    query.prepare(" UPDATE RECLAMATION set  Nature=:NATURE  where ID=:ID  ");
    qDebug("ouut ");

    query.bindValue(":ID",id);
    query.bindValue(":NATURE",Nature);

    return query.exec();
}

QSqlQueryModel *Reclamation::chercheReclamation(int check,QString Search)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    QSqlQuery query;


    if(check==2)
    {
        query.prepare("select * from RECLAMATION where NOM_ROUTE= ? ");
        query.addBindValue(Search);
        query.exec();
    }
    else if(check==3)
    {
        query.prepare("select * from RECLAMATION where TYPE_PANNE= ? ");
        query.addBindValue(Search);
        query.exec();
    }
    else if(check==4)
    {
        qDebug("ouut ");

        query.prepare("select * from RECLAMATION where NATURE= ? ");
        query.addBindValue(Search);
        query.exec();
    }



    model->setQuery(query);
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("NOM_ROUTE"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("TYPE_PANNE"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("DATE_RECLAMAT"));
   // model->setHeaderData(3,Qt::Horizontal,QObject::tr("ETAT_RECL"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("NATURE"));
    model->insertColumn(4);
    model->insertColumn(5);
    model->setHeaderData(4,Qt::Horizontal,QObject::tr(" "));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr(" "));




  return model;
}

QSqlQueryModel *Reclamation::Sort(int check)
{


    QSqlQueryModel * model=new QSqlQueryModel();



    if(check==1)
    {
        model->setQuery("select *from RECLAMATION ORDER BY DATE_RECLAMAT");

    }
    else if(check==2)
    {
        model->setQuery("select *from RECLAMATION ORDER BY NOM_ROUTE");

    }
    else if(check==3)
    {

        model->setQuery("select *from RECLAMATION ORDER BY TYPE_PANNE");

    }
    else if(check==4)
    {

        model->setQuery("select *from RECLAMATION ORDER BY NATURE");

    }



    model->setHeaderData(0,Qt::Horizontal,QObject::tr("NOM_ROUTE"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("TYPE_PANNE"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("DATE_RECLAMAT"));
   // model->setHeaderData(3,Qt::Horizontal,QObject::tr("ETAT_RECL"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("NATURE"));
    model->insertColumn(4);
    model->insertColumn(5);
    model->setHeaderData(4,Qt::Horizontal,QObject::tr(" "));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr(" "));

    return model;
}


/*void Reclamation::Statistique()
{



}
*/
