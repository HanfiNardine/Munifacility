#include "evenement.h"
#include <QChartGlobal>


Evenement::Evenement()
{

}

Evenement::Evenement(QString id,QString nom,QString type,QString date,QString horaire,QString empl ,QString etat )
{
    this->Id_event=id;
    this->Nom_event=nom;
    this->Type_event=type;
    this->Date_event=date;
    this->Horaire_event=horaire;
    this->Empl_event=empl;
    this->Etat_event=etat;

}

bool Evenement::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO EVENEMENT (ID_EVENT,NOM_EVENT,TYPE_EVENT,DATE_EVENT,HOR_EVENT,EMPL_EVENT,ETAT_EVENT)"" VALUES(:Id_event, :Nom_event, :Type_event, :Date_event,:Horaire_event,:Empl_event,:Etat_event)");
    query.bindValue(":Id_event",Id_event);
    query.bindValue(":Nom_event",Nom_event);
    query.bindValue(":Type_event",Type_event);
    query.bindValue(":Date_event",Date_event);
    query.bindValue(":Horaire_event",Horaire_event);
    query.bindValue(":Empl_event",Empl_event);
    query.bindValue(":Etat_event",Etat_event);
    return query.exec();

}
bool Evenement::controle_hor()
{ if(((Horaire_event[2]=="H")||(Horaire_event[2]=="h"))&&(Horaire_event.length()==5))
    {
        return true;
    }
    else return false;
}
bool Evenement::controle_date()
{
    if((Date_event[2]=="/") &&(Date_event[5]=="/")&&(Date_event.length()==10))
        {
            return true;
        }
        else return false;
}
bool Evenement::controle()
{
   if((Id_event=="") or (Nom_event=="") or (Type_event=="") or (!controle_date()) or(!controle_hor()) )
   {
       return false;
   }
   else            return true;


}

bool Evenement::supprimer(QString Id_event)
{
   QSqlQuery query;
   query.prepare("DELETE FROM EVENEMENT WHERE ID_EVENT= :id");
   query.bindValue(":id",Id_event);
   return query.exec();

}

QSqlQueryModel * Evenement::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();

       model->setQuery("select *from Evenement");
       model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_EVENT"));
       model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM_EVENT"));
       model->setHeaderData(2,Qt::Horizontal,QObject::tr("TYPE_EVENT"));
       model->setHeaderData(3,Qt::Horizontal,QObject::tr("DATE_EVENT"));
       model->setHeaderData(4,Qt::Horizontal,QObject::tr("HORAIRE_EVENT"));
       model->setHeaderData(5,Qt::Horizontal,QObject::tr("EMPL_EVENT"));
       model->setHeaderData(6,Qt::Horizontal,QObject::tr("ETAT_EVENT"));

       return model;
}
bool Evenement::maj(QString old_id)
{
    QSqlQuery qry;

    qry.prepare("UPDATE EVENEMENT SET ID_EVENT=:id, NOM_EVENT=:Nom_event, TYPE_EVENT=:Type_event,DATE_EVENT=:Date_event, HOR_EVENT=:Hor_event,EMPL_EVENT=:Empl_event,ETAT_EVENT=:Etat_event WHERE ID_EVENT =:old_id ");
    qry.bindValue(":id",Id_event);
    qry.bindValue(":Nom_event",Nom_event);
    qry.bindValue(":Type_event",Type_event);
    qry.bindValue(":Date_event",Date_event);
    qry.bindValue(":Hor_event",Horaire_event);
    qry.bindValue(":Empl_event",Empl_event);
    qry.bindValue(":Etat_event",Etat_event);
    qry.bindValue(":old_id",old_id);

     if(!qry.exec()){
         QMessageBox::critical(nullptr, QObject::tr("mise à jour non effectuée"),
                     QObject::tr("reéssayez plus tard"), QMessageBox::Ok);
         return false;
     }
     else{
         qDebug("Values added to DB");
         return true;
     }
 }
QSqlQueryModel * Evenement::trier(int tri)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    if(tri==1)
    {
        model->setQuery("SELECT * FROM EVENEMENT ORDER BY TYPE_EVENT ;");
    }
    else
    {
        if(tri==2)
        {
            model->setQuery("SELECT * FROM EVENEMENT ORDER BY ETAT_EVENT ;");
        }
        else if(tri==3)
        {
            model->setQuery("SELECT * FROM EVENEMENT ORDER BY NOM_EVENT ;");
        }
    }
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_EVENT"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM_EVENT"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("TYPE_EVENT"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("DATE_EVENT"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("HORAIRE_EVENT"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("EMPL_EVENT"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("ETAT_EVENT"));


    return model;
}
double Evenement::total()
{

       QSqlQuery query("SELECT COUNT (*) FROM EVENEMENT");
       query.next();
       double nbevent = query.value(0).toDouble();
       return nbevent;

}

int Evenement::passe()
{
    QSqlQuery query;
    QString type="passé";
    query.prepare("SELECT COUNT (*) FROM EVENEMENT WHERE (ETAT_EVENT=:passé); ");
    query.bindValue(":passé",type);
    int nbevent;
    while(query.next())
    {
            nbevent = query.value(0).toInt();
    }

    return nbevent;

}
int Evenement::attente()
{
    QSqlQuery query;
    query.prepare(" SELECT COUNT (*) FROM EVENEMENT WHERE (ETAT_EVENT=:en_attente); ");
    query.bindValue(":en_attente","en attente");
    int nbevent;
    while(query.next())
    {
       nbevent = query.value(0).toInt();
    }

    return nbevent;
}
int Evenement::annule()
{
    QSqlQuery query;
    query.prepare(" SELECT COUNT (*) FROM EVENEMENT WHERE (ETAT_EVENT=:annulé) ;");
    query.bindValue(":annulé","annulé");
    int nbevent;
    while(query.next())
    {
       nbevent = query.value(0).toInt();
    }

    return nbevent;
}
QSqlQuery Evenement::select(QString ID)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM EVENEMENT WHERE ID_EVENT='"+ID+"'");
    return query;
}

QSqlQuery Evenement::detail_mail(QString id)
{
    QSqlQuery query;

    query.prepare("select * from EVENEMENT where ID_EVENT='"+id+"'");

    query.exec();

    query.next();


    return query;



}
QChart * Evenement::stat()

{

    int annule=0, passe=0, cours=0;


    QSqlQuery query;

    query.prepare("select Etat_event from Evenement");

    query.exec();


    while(query.next())

    {

        if(query.value(0).toString() == "passe")

        {

            passe++;

        }

        else if(query.value(0).toString() == "annule")

        {

            annule++;

        }
        else if(query.value(0).toString() == "en cours")

        {

            cours++;

        }

    }


    QPieSeries *series = new QPieSeries();

    series->append("annule",annule);
    series->append("en cours",cours);
    series->append("passe",passe);

    QChart * chart=new  QChart();

    chart->addSeries(series);

    chart->setTitle("repartition par état");


    return   chart;


}


