#include "zone_verte.h"
#include"connection.h"
#include<QDebug>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QSqlQueryModel>
Zone_Verte::Zone_Verte()
{

}

Zone_Verte::Zone_Verte(QString Adresse,QString Libelle,QString Identifiant,QString Aire)
{
this->Adresse=Adresse;
this->Libelle=Libelle;
this->Identifiant=Identifiant;
this->Aire=Aire;
}

bool Zone_Verte::ajouter()
{

      QSqlQuery query;

query.prepare("insert into ZONE_VERTE (ID_ZONEVERTE,LIBELLE,ADRESSE,AIRE) values (ID_ZoneVerte.NEXTVAL,:libelle,:adresse,:aire) ");

query.bindValue(":libelle",getLibelle());
query.bindValue(":adresse",getAdresse());
query.bindValue(":aire",getAire());
   return   query.exec();

}

void Zone_Verte::Remplissage(QString*ID,QString*Libelle,QString*Adresse,QString*Aire)
{  QSqlQuery q;

    q.prepare("select * from ZONE_VERTE where ID_ZONEVERTE='"+*ID+"'");

     if(q.exec())
     {
         while(q.next())
         {
 *ID=q.value(0).toString();
 *Libelle= q.value(1).toString();
 *Adresse= q.value(2).toString();
 *Aire=q.value(3).toString();

 }

 }

}
QSqlQueryModel * Zone_Verte::afficher()
{
    QSqlQueryModel *model= new QSqlQueryModel();

    model->setQuery("SELECT ID_ZONEVERTE FROM ZONE_VERTE ");


return model;
}

bool Zone_Verte::Supprimer(QString ID)
{

    QSqlQuery query;
    query.prepare("Delete from Zone_Verte where ID_ZONEVERTE = :ID");
    query.bindValue(":ID",ID);
    return query.exec();


}

bool Zone_Verte::Modifier(QString ID,QString Libelle,QString Aire,QString Adresse)
{
     QSqlQuery q;

q.prepare("update ZONE_VERTE set LIBELLE= :libelle,ADRESSE= :adresse ,AIRE= :aire where ID_ZONEVERTE= :id");

q.bindValue(":id",ID);
q.bindValue(":libelle",Libelle);
q.bindValue(":adresse",Adresse);
q.bindValue(":aire",Aire);

q.exec();
        return   q.exec();
}

QSqlQueryModel* Zone_Verte::Recherche(int indice,QString ch)
{

    QSqlQueryModel *model= new QSqlQueryModel();
    if(indice==1)
   {
        model->setQuery("select ID_ZONEVERTE from ZONE_VERTE where ID_ZONEVERTE= '"+ch+"' ");
   }
    else if (indice==2)
    {
     model->setQuery("select ID_ZONEVERTE from ZONE_VERTE where LIBELLE='"+ch+"'");
    }
    else if (indice==3)
    {
     model->setQuery("select ID_ZONEVERTE from ZONE_VERTE where ADRESSE='"+ch+"'");
    }
    else if (indice==4)
    {
     model->setQuery("select ID_ZONEVERTE from ZONE_VERTE where AIRE='"+ch+"'");
    }

      model->setHeaderData(0,Qt::Horizontal,QObject::tr("IDENTIFIANT"));
return model;
}

