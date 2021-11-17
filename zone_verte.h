#ifndef ZONE_VERTE_H
#define ZONE_VERTE_H
#include<QString>
#include<QSqlQueryModel>

class Zone_Verte
{
    QString Adresse;
    QString Libelle;
    QString Identifiant;
    QString Aire;

public:
    Zone_Verte();
   //Ajouter un constructeur avec paramètres

    Zone_Verte(QString,QString,QString,QString);
    QString getAdresse()
    {return Adresse;}
    QString getLibelle()
    {return Libelle;}
    QString getIdentifiant()
    {return Identifiant;}
    QString getAire()
    {return Aire; }

    void setAdresse(QString a)
    {Adresse=a;}
    void setLibelle(QString l)
    {Libelle=l;}
    void setIdentifiant(QString id)
    { Identifiant=id;}
    void setAire(QString ch)
    {Aire=ch; }


   bool ajouter();

  QSqlQueryModel* afficher();

  void Remplissage(QString*,QString*,QString*,QString*);
  bool Supprimer(QString ID);
  bool Modifier(QString,QString,QString,QString );
  QSqlQueryModel*  Recherche(int,QString);
};

#endif // ZONE_VERTE_H
