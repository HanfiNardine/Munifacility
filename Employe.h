#ifndef Employe_H
#define Employe_H
#include<QString>
#include<QSqlQueryModel>
#include <QChartView>
#include<QtCharts>
#include<QChart>

class Employe
{

    QString Nom;
    QString Prenom;
    QString mail;
    QString Type;
    QString cin;
    QString etat;


public:

    QString getType()
    {return Type;}
    QString getmail()
    {return mail;}
    QString getNom()
    {return Nom;}
    QString getPrenom()
    {return Prenom;}

    QString getcin()
    {return cin; }
    QString getetat()
    {return etat; }
    void setType(QString t)
    {Type=t;}
    void setmail(QString m)
    {mail=m;}
    void setNom(QString nt)
    { Nom=nt;}

    void setPrenom(QString p)
    { Prenom=p;}
    void setcin(QString c)
    {cin=c; }
    void setetat(QString e)
    {etat=e; }

    Employe();
    Employe(QString,QString,QString,QString,QString,QString);

    bool ajouter();
    QSqlQueryModel *load();
    QSqlQueryModel * read(QString);
    QSqlQuery editview(QString);
    QSqlQueryModel * chercher(QString);
    QSqlQuery readmail(QString);
    QSqlQueryModel *sort();
    QChart *statistic();
    bool Delete(QString);
    bool Update();


};


#endif // Employe_H
