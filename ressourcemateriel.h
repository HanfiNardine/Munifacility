#ifndef RESSOURCEMATERIEL_H
#define RESSOURCEMATERIEL_H

#include <QSqlQueryModel>
#include<QString>

class RessourceMateriel
{
public:
    RessourceMateriel();
    RessourceMateriel(QString B,QString C,QString D,double E,double F);

    QString gen_random();

    QSqlQueryModel *AfficherComposant();
    bool AjouterComposant();
    bool ModifierComposant(QString id,QString Nature);
    bool SupprimerComposant(QString);
    QSqlQueryModel *chercheComposant(int ref,QString Search);
    void ChangerCouleur();




 public:

    QString id_composant;
    QString type_composant;
    QString etat_composant;
    QString nom_route;
    double posx_composant;
    double posy_composant;

public:

    QString getId_composant() const;
    void setId_composant(const QString &value);

    QString getType_composant() const;
    void setType_composant(const QString &value);
    QString getEtat_composant() const;
    void setEtat_composant(QString value);
    QString getNom_route() const;
    void setNom_route(const QString &value);
    double getPosx_composant() const;
    void setPosx_composant(double value);
    double getPosy_composant() const;
    void setPosy_composant(double value);
};

#endif // RESSOURCEMATERIEL_H
