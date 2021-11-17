#include "Employe.h"
#include"connection.h"
#include<QDebug>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QSqlQueryModel>
Employe::Employe()

{

}

Employe::Employe(QString Type,QString Nom,QString Prenom,QString cin,QString mail,QString etat)
{
    this->Type=Type;
    this->Nom=Nom;
    this->cin=cin;
    this->mail=mail;
    this->Prenom=Prenom;

    this->etat=etat;

}

bool Employe::ajouter()
{

      QSqlQuery query;

      query.prepare("insert into EMPLOYE (NOM,PRENOM,MAIL,TYPE,CIN,ETAT)" "values (:NOM,:PRENOM,:MAIL,:TYPE,:CIN,:ETAT)");
      query.bindValue(":NOM",Nom);
      query.bindValue(":PRENOM",Prenom);

      query.bindValue(":MAIL",mail);
      query.bindValue(":TYPE",Type);
      query.bindValue(":CIN",cin);
      query.bindValue(":ETAT",etat);

      return query.exec();

}

QSqlQueryModel * Employe::load()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("select NOM from Employe");
    query.exec();
    model->setQuery(query);
    return model;
}

QSqlQueryModel * Employe::read(QString info)
{

    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select * from Employe where Nom='"+info+"'");
   model->setHeaderData(0,Qt::Horizontal,QObject::tr("NOM"));
   model->setHeaderData(1,Qt::Horizontal,QObject::tr("PRENOM"));
   model->setHeaderData(2,Qt::Horizontal,QObject::tr("MAIL"));
   model->setHeaderData(3,Qt::Horizontal,QObject::tr("TYPE"));
   model->setHeaderData(4,Qt::Horizontal,QObject::tr("CIN"));
   model->setHeaderData(5,Qt::Horizontal,QObject::tr("ETAT"));

   return model;

}

bool Employe::Delete(QString info)
{
    QSqlQuery query;
    query.prepare("Delete from Employe where Nom='"+info+"'");
    return query.exec();
}

bool Employe::Update()
{
    QSqlQuery query;
    query.prepare("update Employe set NOM='"+Nom+"',PRENOM='"+Prenom+"',MAIL='"+mail+"',TYPE='"+Type+"',CIN='"+cin+"',etat='"+etat+"' where Nom='"+Nom+"'");

    //Creation des variables liées

    query.bindValue(":NOM",Nom);
    query.bindValue(":PRENOM",Prenom);

    query.bindValue(":MAIL",mail);
    query.bindValue(":TYPE",Type);
    query.bindValue(":CIN",cin);
    query.bindValue(":ETAT",etat);


    //exec() envoie la requete pour l'executer
    return query.exec();
}

QSqlQuery Employe::editview(QString info)

{

    QSqlQuery query;

    query.prepare("select * from Employe where Nom='"+info+"'");

    if(query.exec())

    {

        return query;

    }

}


QSqlQueryModel * Employe::chercher(QString info)
{

    QSqlQueryModel *model=new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("select nom from employe where NOM='"+info+"'");
    query.exec();
    model->setQuery(query);
    return model;
}
QSqlQuery Employe::readmail(QString info)
{
    QSqlQuery query;

    query.prepare("select * from Employe where nom='"+info+"'");

    query.exec();

    query.next();


    return query;



}
QSqlQueryModel * Employe :: sort()

{

    QSqlQueryModel * model=new QSqlQueryModel();

    QSqlQuery query ;

    query.prepare("SELECT nom FROM EMPLOYE ORDER BY nom ASC");

    query.exec();

    query.next();

    model->setQuery(query);


    return model;

}

QChart * Employe::statistic()

{

    int secretaire=0, agent=0;


    QSqlQuery query;

    query.prepare("select type from Employe");

    query.exec();


    while(query.next())

    {

        if(query.value(0).toString() == "Secretaire")

        {

            secretaire++;

        }

        else if(query.value(0).toString() == "Agent")

        {

            agent++;

        }

    }


    QPieSeries *series = new QPieSeries();

    series->append("Secretaire",secretaire);

    series->append("Agent",agent);

    QChart * chart=new  QChart();

    chart->addSeries(series);

    chart->setTitle("type statisque");


    return   chart;


}


