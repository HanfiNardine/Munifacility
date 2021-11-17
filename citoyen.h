#ifndef ETATCIVIL_H
#define ETATCIVIL_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include<QMessageBox>
#include <QPrinter>
#include <QPainter>
#include<QPrintDialog>
#include<QPdfWriter>
#include <QImage>

class Citoyen
{
    QString Id_cit;
    QString Nom_cit;
    QString Prenom_cit;
    QString Sexe_cit;
    QString Date_cit;
    QString Lieu_cit;
    QString Mail_cit;
    QString Tel_cit;

public:
    //constructeurs
    Citoyen();
    Citoyen(QString id,QString nom,QString prenom,QString sexe,QString date,QString lieu ,QString mail ,QString tel);
    //setters
    void setId(QString id) {Id_cit=id;}
    void setNom(QString nom) {Nom_cit=nom;}
    void setPrenom(QString prenom) {Prenom_cit=prenom;}
    void setSexe(QString sexe) {Sexe_cit=sexe;}
    void setDatec(QString date) {Date_cit=date;}
    void setLieu(QString lieu) {Lieu_cit=lieu;}
    void setMail(QString mail) {Mail_cit=mail;}
    void setTel(QString tel) {Tel_cit=tel;}
    //getter
    QString getId(){return Id_cit;}
    QString getNom(){return Nom_cit;}
    QString getPrenom(){return Prenom_cit;}
    QString getSexe(){return Sexe_cit;}
    QString getDatec(){return Date_cit;}
    QString getLieu(){return Lieu_cit;}
    QString getMail(){return Mail_cit;}
    QString getTel(){return Tel_cit;}
    //fonctionnalités de base
    bool ajouter();
    bool controle_date();
    bool controle_mail();
    bool controle();
    bool supprimer(QString id);
    QSqlQueryModel * afficher();
    bool maj(QString old_id);
    QSqlQuery select(QString ID);
    //fonctionnalités avancées
    QSqlQueryModel * recherche_id(QString id);
    QSqlQueryModel * recherche_nom(QString nom);
    QSqlQueryModel * recherche_prenom(QString prenom);
    QSqlQueryModel * trier();
    void printPDF(int num);
    QSqlQuery date();
};

#endif // ETATCIVIL_H

