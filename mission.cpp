#include "mission.h"

mission::mission(){}
mission::mission(int cin, QString horaire,QString date, QString type , QString emplacement)
{    this->cin=cin;
     this->horaire=horaire;
     this->date=date;
     this->type=type;
     this->emplacement=emplacement;
}
bool mission::ajouter() {
    QSqlQuery query;
    QString c= QString::number(cin);


 query.prepare("INSERT INTO mission (CIN, HORAIRE,date_mission, TYPE, EMPLACEMENT) VALUES (:CIN, :HORAIRE,:DATE,:TYPE,  :EMPLACEMENT)");
    query.bindValue(":CIN",c);
    query.bindValue(":HORAIRE",horaire);
    query.bindValue(":DATE",date);
    query.bindValue(":TYPE",type);
    query.bindValue(":EMPLACEMENT",emplacement);


    return    query.exec();
 }

bool mission::supprimer(int cin)
{
QSqlQuery query;
QString c=QString::number(cin);

query.prepare("Delete from mission where CIN = :CIN ");
query.bindValue(":CIN", c);
return    query.exec();
}


bool mission::modifier(int cin){
    QSqlQuery query;
    QString c= QString::number(cin);


    query.prepare("update mission set CIN=:CIN,HORAIRE=:HORAIRE,DATE_mission=:DATE,TYPE=:TYPE,EMPLACEMENT=:EMPLACEMENT where CIN=:CIN ");
    query.bindValue(":CIN",c);
    query.bindValue(":HORAIRE",horaire);
    query.bindValue(":DATE",date);
    query.bindValue(":TYPE",type);
    query.bindValue(":EMPLACEMENT",emplacement);

   return query.exec();
}
QSqlQueryModel * mission::afficher(){ QSqlQueryModel *model = new QSqlQueryModel;
  model->setQuery("SELECT * FROM mission ");

  model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
  model->setHeaderData(1, Qt::Horizontal, QObject::tr("horaire"));
  model->setHeaderData(2, Qt::Horizontal, QObject::tr("date"));
  model->setHeaderData(3, Qt::Horizontal, QObject::tr("type"));
  model->setHeaderData(4, Qt::Horizontal, QObject::tr("emplacement"));

  return  model;
  }


QSqlQueryModel * mission::rechercheDynamic(QString cin){
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("SELECT * FROM mission WHERE CIN LIKE '"+cin+"%'");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("horaire"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("date"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("type"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("emplacement"));
  return  model;
  }
