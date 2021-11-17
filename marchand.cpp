#include "marchand.h"
marchand::marchand(){

}

marchand::marchand(QString nom ,QString prenom,QString emplacement,int numero)
{ this->nom=nom;
    this->prenom=prenom;
    this->emplacement=emplacement;
    this->numero=numero;

}
bool marchand::ajouter() {
    QSqlQuery query;
    QString n= QString::number(numero);


 query.prepare("INSERT INTO marchand (id,nom,prenom,emplacement,numero) VALUES (null,:nom, :prenom,:emplacement,:numero)");
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":emplacement",emplacement);
    query.bindValue(":numero",n);


    return    query.exec();
 }
bool marchand::supprimer(int id)
{
    QSqlQuery query;
    QString i=QString::number(id);

query.prepare("Delete from marchand where id = :id ");
query.bindValue(":id", i);
return    query.exec();
}

QSqlQueryModel * marchand::afficher(){
    QSqlQueryModel *model = new QSqlQueryModel;
  model->setQuery("SELECT * FROM marchand ");

  model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
  model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
  model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
  model->setHeaderData(3, Qt::Horizontal, QObject::tr("numero"));
  model->setHeaderData(4, Qt::Horizontal, QObject::tr("emplacement"));

  return  model;
  }



bool marchand::modifier(int id){
    QSqlQuery query;
    QString n= QString::number(numero);
    QString i= QString::number(id);



    query.prepare("update marchand set nom=:nom,prenom=:prenom,emplacement=:emplacement,numero=:numero where id=:id ");
    query.bindValue(":id",i);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":emplacement",emplacement);
    query.bindValue(":numero",n);

   return query.exec();
}


QSqlQueryModel * marchand::rechercheDynamic(QString SearchName){
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("SELECT * FROM marchand WHERE nom LIKE '"+SearchName+"%'");

                  model->setHeaderData(4, Qt::Horizontal, QObject::tr("numero"));
                  model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
                  model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
                  model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
                  model->setHeaderData(3, Qt::Horizontal, QObject::tr("emplacement"));
  return  model;
  }
