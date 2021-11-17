#include "ramassage.h"
#include"connection.h"

#include<QDebug>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include <QModelIndex>
#include <QVector>
Ramassage::Ramassage()
{}


bool Ramassage::ajouter()
{



      QSqlQuery query;


      query.prepare("insert into RAMASSAGE (ID_RAMASSAGE,MATRICULE,DATE_RAMASSAGE,"
                          "NOMBRE_POUBELLE,DUREE,NOM_CARTIER,HEURE_DEBUT) values(ID_RAMASSAGE.NEXTVAL,:Matricule,:date,:nb_p,:duree,:cartier,:heure)");

query.bindValue(":Matricule",getMatricule());
query.bindValue(":date",getDate());
query.bindValue(":nb_p",getNbPoubelle());
query.bindValue(":duree",getDuree().toString("HH:mm"));
query.bindValue(":cartier",getNom_cartier());
query.bindValue(":heure", getHdepart().toString());

return query.exec();

}
bool Ramassage::affectation(QString ch)
{
    QSqlQuery query;


query.prepare("insert into EMPLOYE_RAMASSAGE (ID_RAMASSAGE,CIN) values(ID_RAMASSAGE.NEXTVAL-11,:CIN)");
query.bindValue(":id",getId_Ramassage());
query.bindValue(":CIN",ch);



return query.exec();
}
bool Ramassage::affectation2(QString ch)
{
    QSqlQuery query;


query.prepare("insert into EMPLOYE_RAMASSAGE (ID_RAMASSAGE,CIN) values(ID_RAMASSAGE.NEXTVAL-22,:CIN)");
query.bindValue(":id",getId_Ramassage().toInt());
query.bindValue(":CIN",ch);



return query.exec();
}
bool Ramassage::affectation3(QString ch)
{
    QSqlQuery query;


query.prepare("insert into EMPLOYE_RAMASSAGE (ID_RAMASSAGE,CIN) values(ID_RAMASSAGE.NEXTVAL-33,:CIN)");
query.bindValue(":id",getId_Ramassage().toInt());
query.bindValue(":CIN",ch);



return query.exec();
}



QSqlQueryModel * Ramassage ::afficher()
{
    QSqlQueryModel *model= new QSqlQueryModel();
    model->setQuery("SELECT ID_RAMASSAGE FROM RAMASSAGE ");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("IDENTIFIANT"));


return model;
}

 QVector<QString> Ramassage::afficheremploye(QString* ID)
{

    QSqlQuery q;
QString ch;

   q.prepare("select * from EMPLOYE_RAMASSAGE where ID_RAMASSAGE='"+*ID+"' ");
   if(q.exec())
   {
       while(q.next())
       {
           ch= q.value(0).toString();
           *ID=q.value(1).toString();
          tab.push_back(ch);
       }

   }

return tab;
}


void Ramassage::Remplissage(QString* ID,QString*Matricule,QString*Date,QString*Nb_poubelle,QString*Nom_Cartier,QString*Duree,QString*Heure)
{
//QVector<Ramassage> tabR;
    QSqlQuery q;

   q.prepare("select * from RAMASSAGE where ID_RAMASSAGE='"+*ID+"'");

    if(q.exec())
    {
        while(q.next())
        {
*ID= q.value(0).toString();
*Matricule=q.value(1).toString();
*Date   =q.value(2).toString();
*Nb_poubelle  =q.value(3).toString();
*Duree  =q.value(4).toString();
*Nom_Cartier  =q.value(5).toString();
*Heure=q.value(6).toString();

}
    }



}

bool Ramassage::Supprimer(QString ID)
{

    QSqlQuery query;
    query.prepare("Delete from RAMASSAGE where ID_RAMASSAGE = :ID");
    query.bindValue(":ID",ID);
    return query.exec();
}

bool Ramassage::SupprimerEmploye(QString ID)
{

    QSqlQuery query;
    query.prepare("Delete from EMPLOYE_RAMASSAGE where ID_RAMASSAGE = :ID");
    query.bindValue(":ID",ID);
    return query.exec();
}

bool Ramassage::Modifier(QString ID, QString Matricule, QString Date, QString Nb_poubelle, QString Nom_cartier, QString Duree, QString Heure)
{
    QSqlQuery query;



query.prepare("update RAMASSAGE set MATRICULE= :Matricule,DATE_RAMASSAGE= :date,NOMBRE_POUBELLE= :nb_p,DUREE= :duree,NOM_CARTIER= :cartier,HEURE_DEBUT= :heure where ID_RAMASSAGE= :ID");

query.bindValue(":ID",ID);
query.bindValue(":Matricule",Matricule);

query.bindValue(":date",Date);
query.bindValue(":nb_p",Nb_poubelle);
query.bindValue(":duree",Duree);
query.bindValue(":cartier",Nom_cartier);
query.bindValue(":heure", Heure);



return   query.exec();

}


QSqlQueryModel* Ramassage::Recherche(int indice,QString ch)
{



QSqlQueryModel *model= new QSqlQueryModel();
if(indice==1)
{
    model->setQuery("select ID_RAMASSAGE from RAMASSAGE where  ID_RAMASSAGE='"+ch+"'");
}
    else if (indice==2)
{
     model->setQuery("select ID_RAMASSAGE from RAMASSAGE where Matricule= '"+ch+"' ");
}
else if (indice==3)
{
 model->setQuery("select ID_RAMASSAGE from RAMASSAGE where DATE_RAMASSAGE= '"+ch+"' ");
}
else if (indice==4)
{
 model->setQuery("select ID_RAMASSAGE from RAMASSAGE where NOMBRE_POUBELLE= '"+ch+"' ");
}
else if (indice==5)
{
 model->setQuery("select ID_RAMASSAGE from RAMASSAGE where DUREE= '"+ch+"' ");
}
else if (indice==6)
{
 model->setQuery("select ID_RAMASSAGE from RAMASSAGE where HEURE_DEBUT= '"+ch+"' ");
}
else if (indice==7)
{
 model->setQuery("select ID_RAMASSAGE from RAMASSAGE where NOM_CARTIER= '"+ch+"' ");
}

model->setHeaderData(0,Qt::Horizontal,QObject::tr("IDENTIFIANT"));


return model;
}

QSqlQueryModel * Ramassage ::afficherSTAT(QString ch,QString ch2)
{
qDebug()<<"Annee"<<ch;

    QSqlQueryModel *model= new QSqlQueryModel();
    model->setQuery("SELECT ID_RAMASSAGE,NOMBRE_POUBELLE,DATE_RAMASSAGE FROM RAMASSAGE where DATE_RAMASSAGE like'%/"+ch+"' ORDER BY TO_DATE(DATE_RAMASSAGE,'dd/MM/yyyy') ASC");

model->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifiant"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nombre de poubelle"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("Date"));


return model;
}

QSqlQueryModel * Ramassage::Tri(int index)
{
    QSqlQueryModel *model= new QSqlQueryModel();
    if (index==2)
    model->setQuery("select ID_RAMASSAGE from RAMASSAGE ORDER BY NOM_CARTIER DESC");
    else if(index==3)
            model->setQuery("select ID_RAMASSAGE from RAMASSAGE ORDER BY to_number(NOMBRE_POUBELLE) DESC");
    else if (index==4)
        model->setQuery("select ID_RAMASSAGE from RAMASSAGE ORDER BY to_date(DATE_RAMASSAGE,'dd/MM/yyyy') DESC");
   model->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifiant"));
   return model;
}
