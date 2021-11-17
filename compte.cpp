#include "compte.h"
#include"connection.h"
#include<QDebug>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QMessageBox>

#include<QSqlQueryModel>
compte::compte()
{

}

compte::compte(QString Type,QString Identifiant,QString cin,QString mdp)
{
    this->Type=Type;
    this->Identifiant=Identifiant;
    this->cin=cin;
    this->mdp=mdp;
}

bool compte::ajouter()
{

      QSqlQuery query;



      query.prepare("insert into compte (Identifiant,Mot_de_passe,TYPE_AUTHEN,CIN)" "values (:Identifiant,:Mot_de_passe,:TYPE_AUTHEN,:CIN)");
      query.bindValue(":Identifiant",Identifiant);
      query.bindValue(":Mot_de_passe",mdp);
      query.bindValue(":TYPE_AUTHEN",Type);
      query.bindValue(":CIN",cin);

      return query.exec();

}

QSqlQueryModel * compte::load()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("select Identifiant from compte");
    query.exec();
    model->setQuery(query);
    return model;
}

QSqlQueryModel * compte::read(QString info)
{

    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select * from compte where Identifiant='"+info+"'");
   model->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifiant"));
   model->setHeaderData(1,Qt::Horizontal,QObject::tr("Mot_de_passe"));
   model->setHeaderData(2,Qt::Horizontal,QObject::tr("TYPE_AUTHENT"));

   model->setHeaderData(3,Qt::Horizontal,QObject::tr("CIN"));
   return model;

}

bool compte::Delete(QString info)
{
    QSqlQuery query;
    query.prepare("Delete from compte where Identifiant='"+info+"'");
    return query.exec();
}

bool compte::Update()
{

    QSqlQuery query;

    query.prepare("update compte set Identifiant='"+Identifiant+"',Mot_de_passe='"+mdp+"',TYPE_AUTHEN='"+Type+"',CIN='"+cin+"' where Identifiant='"+ Identifiant+"'");


    //Creation des variables liées
    query.bindValue(":Identifiant",Identifiant);
    query.bindValue(":Mot_de_passe",mdp);
    query.bindValue(":TYPE_AUTHEN",Type);
    query.bindValue(":CIN",cin);

    //exec() envoie la requete pour l'executer
    return query.exec();
}

QSqlQuery compte::editview(QString info)

{

    QSqlQuery query;

    query.prepare("select * from compte where Identifiant='"+info+"'");

    if(query.exec())

    {

        return query;

    }

}

QSqlQueryModel * compte::chercher(QString info)
{

    QSqlQueryModel *model=new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("select id from compte where Identifiant='"+info+"'");
    query.exec();
    model->setQuery(query);
    return model;
}

QSqlQuery  compte::authen(QString Identifiant,QString mdp)

{
QSqlQuery qry;


        if(qry.exec("SELECT Identifiant,Mot_De_Passe FROM compte Where Identifiant=\'" + Identifiant +"\'AND mot_de_passe=\'" +mdp+"\'"))
        {

            return qry;


        }



}


bool compte::search(QString info)

{

    QSqlQuery query;

    query.prepare("select * from compte where identifiant='"+info+"'");

    query.exec();

    if(query.next())

    {

        return true;

    }


    return false;

}

QSqlQuery compte::readid(QString info)
{
    QSqlQuery query;

    query.prepare("select * from compte where identifiant='"+info+"'");

    query.exec();

    query.next();


    return query;



}



