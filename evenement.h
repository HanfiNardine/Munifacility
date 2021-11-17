#ifndef EVENEMENT_H
#define EVENEMENT_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include<QMessageBox>
#include <QPainter>
#include <QChartView>
#include<QtCharts>
#include<QChart>
/*#include<QtChartsDepends>
#include<QtChartsVersion>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
*/
class Evenement
{   private :
    QString Id_event;
    QString Nom_event;
    QString Type_event;
    QString Date_event;
    QString Horaire_event;
    QString Empl_event;
    QString Etat_event;
      public :
     //constructeurs
     Evenement();
     Evenement(QString,QString,QString,QString,QString,QString,QString);
     //setters
     void setId(QString id) {Id_event=id;}
     void setNom(QString nom) {Nom_event=nom;}
     void setType(QString type) {Type_event=type;}
     void setDate(QString date) {Date_event=date;}
     void setHor(QString hor) {Horaire_event=hor;}
     void setEmpl(QString empl) {Empl_event=empl;}
     void setEtat(QString etat) {Etat_event=etat;}
     //getters
     QString getId(){return Id_event;}
     QString getNom(){return Nom_event;}
     QString getType(){return Type_event;}
     QString getDate(){return Date_event;}
     QString getHor(){return Horaire_event;}
     QString getEmpl(){return Empl_event;}
     QString getEtat(){return Etat_event;}
     //fonctionnalités de base
     bool ajouter();
     QSqlQueryModel * afficher();
     bool controle_date();
     bool controle_hor();
     bool controle();
     bool supprimer(QString ID);
     bool maj(QString old_id);
     QSqlQuery select(QString ID);
     //fonctionnalités avancées
     double total();
     int passe();
     int attente();
     int annule();
     QSqlQueryModel *trier(int tri);
     QSqlQuery detail_mail(QString mail);
     QChart *stat();

};

#endif // EVENEMENT_H
