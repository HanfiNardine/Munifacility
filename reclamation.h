#ifndef RECLAMATION_H
#define RECLAMATION_H

#include<QString>

#include <QtSql/QSqlQueryModel>

class Reclamation
{
public:
    Reclamation();
    Reclamation(QString,QString,QString,QString,QString);


    QSqlQueryModel *AfficherReclamation();
    bool AjouterReclamation();
    bool ModifierReclamation(QString,QString);
    bool SupprimerReclamation(QString );
    QSqlQueryModel *chercheReclamation(int check,QString Search);
    void Statistique();
    QSqlQueryModel *Sort(int);





    protected:
    QString id_reclamation;
    QString nom_route;
    QString type_panne;
    QString date;
    //int etat_reclamatio;
    QString Nature;
    QString ID_COMP;

public:
    QString getId_reclamation() const;
    void setId_reclamation(int value);
    QString getNom_route() const;
    void setNom_route(const QString &value);
    QString getType_panne() const;
    void setType_panne(const QString &value);
    int getEtat_reclamatio() const;
    void setEtat_reclamatio(int value);
};

#endif // RECLAMATION_H
