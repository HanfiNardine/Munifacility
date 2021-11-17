#include "capteur_mouvement.h"

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Employe.h"
#include<QMessageBox>
#include "compte.h"
#include<QListWidgetItem>
#include"connection.h"
#include<QDebug>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include <QtMultimedia/QMediaPlayer>
#include <QPropertyAnimation>
#include "ramassage.h"
#include"zone_verte.h"
#include"capteur_humidite.h"
#include <QSqlError>
#include <QModelIndex>
#include <QDate>
#include <QMovie>
#include <QSize>
#include <QSortFilterProxyModel>
#include <QtCharts>
#include <QLineSeries>
#include <QtCore>
#include <QHeaderView>
#include <QGridLayout>
#include <QPrinter>
#include <QPrintDialog>
#include "citoyen.h"
#include "evenement.h"
#include"clock.h"
#include <QDate>
#include <QSignalMapper>
#include <QSizePolicy>
#include <QTableWidget>
#include <Qt>
#include <qsizepolicy.h>
#include <reclamation.h>
#include <ressourcemateriel.h>

#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>

// Define the scope for your variables and functions

QT_CHARTS_USE_NAMESPACE

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    QIcon m ("C:/Users/Bader Semah/Desktop/Smart_Municipality_2A3/munifacility_2Nf_3");
     setWindowIcon(m);
    ui->stackedWidget_Main->setCurrentIndex(1);
  ui->stackedWidget_resources_humaines->setCurrentIndex(0);

  /* Resize ***/

  m_autoResizeHandler=new AutoResize(this,this->rect().width(),this->rect().height());
  m_autoResizeHandler->setAutoResizeFlag(
          AutoResize::INCLUDE_BUTTON|AutoResize::INCLUDE_COMBOBOX|
          AutoResize::INCLUDE_EDITOR|AutoResize::INCLUDE_LABEL


          );
  //add widget* manualy

  resizeAllElements(m_autoResizeHandler);
  m_autoResizeHandler->pushAllResizeItem();

/********************************************** Begin Wassim *******************************************/

  ui->lineEdit_cin_compte_AJ->setValidator(new QIntValidator(0,9999999999, this));
  ui->lineEdit_cin_MAJ_compte->setValidator(new QIntValidator(0,9999999999, this));
  ui->lineEdit_cin_employe_AJ->setValidator(new QIntValidator(0,9999999999, this));
  ui->lineEdit_cin_employe_MAJ->setValidator(new QIntValidator(0,9999999999, this));
  
  ui->listView_compte->setContextMenuPolicy(Qt::CustomContextMenu);
  ui->listView_employe->setContextMenuPolicy(Qt::CustomContextMenu);
      connect(ui->listView_compte, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(showContextMenu(QPoint)));
      connect(ui->listView_employe, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(showContextMenue(QPoint)));
    /*  int ret3=M.connect_capteur_mouvement();
         qDebug()<<"ret"<<ret3;
         switch(ret3)
          {
           case(0):qDebug()<<"arduino is available and connected to: "<<M.get_capteur_mouvement_port_name();
           break;
           case(1):qDebug()<<"arduino is available but not connected to:"<<M.get_capteur_mouvement_port_name();
           break;
           case(-1):qDebug()<<"arduino is not available";
           break;
           }
         QObject::connect(M.getserial(),SIGNAL(readyRead()),this,SLOT(updateemp())); */

void updateemp();
{

}

/********************************************** End Wassim *******************************************/

/********************************************** Begin Rima *******************************************/
      ui->comboBox_Type_Tri->addItem("Choisisser le critère de tri");
       ui->comboBox_Type_Tri->addItem("Aucun critère de tri");
           ui->comboBox_Type_Tri->addItem("Tri selon le nom de cartier");
            ui->comboBox_Type_Tri->addItem("Tri selon le nombre de poubelle");
             ui->comboBox_Type_Tri->addItem("Tri selon la date");
            ui->tri_ramassage->hide();

 ui->Notif_irrigation->hide();
 ui->pushButton_Irrigat->hide();
      //Add items to comoBox_AdresseAJ
  ui->comboBox_NomCartier_AJ->addItem("EL Menzah 1 ");
  ui->comboBox_NomCartier_AJ->addItem("EL Menzah 4");
  ui->comboBox_NomCartier_AJ->addItem("EL Menzah 5 ");
  ui->comboBox_NomCartier_AJ->addItem("EL Menzah 6");
  ui->comboBox_NomCartier_AJ->addItem("EL Menzah 7");
  ui->comboBox_NomCartier_AJ->addItem("EL Menzah 8");
  ui->comboBox_NomCartier_AJ->addItem("EL Menzah 9");
  ui->comboBox_NomCartier_AJ->addItem("Ennasr 1");
  ui->comboBox_NomCartier_AJ->addItem("Ennasr 2");
  ui->comboBox_NomCartier_AJ->addItem("Riadh andalous");

  ui->comboBox_NomCartier_MAJ->addItem("EL Menzah 1 ");
  ui->comboBox_NomCartier_MAJ->addItem("EL Menzah 4");
  ui->comboBox_NomCartier_MAJ->addItem("EL Menzah 5 ");
  ui->comboBox_NomCartier_MAJ->addItem("EL Menzah 6");
  ui->comboBox_NomCartier_MAJ->addItem("EL Menzah 7");
  ui->comboBox_NomCartier_MAJ->addItem("EL Menzah 8");
  ui->comboBox_NomCartier_MAJ->addItem("EL Menzah 9");
  ui->comboBox_NomCartier_MAJ->addItem("Ennasr 1");
  ui->comboBox_NomCartier_MAJ->addItem("Ennasr 2");
  ui->comboBox_NomCartier_MAJ->addItem("Riadh andalous");

  ui->comboBox_Adresse_ZV_AJ->addItem("Ave Ariana Les Roses");
  ui->comboBox_Adresse_ZV_AJ->addItem("Rue el amine chebbi");
  ui->comboBox_Adresse_ZV_AJ->addItem("Rue Kaboul");
  ui->comboBox_Adresse_ZV_AJ->addItem("Amilcar");
  ui->comboBox_Adresse_ZV_AJ->addItem("Rue Hanoun");
  ui->comboBox_Adresse_ZV_AJ->addItem("Avenue Abdellaziz Thaalbi");



  ui->lineEdit_recherche_R->setPlaceholderText("Chercher ");
  ui->lineEdit_recherche_ZV->setPlaceholderText("Chercher ");

  //Critère Recherche
  ui->comboBox_TypeRech_Ramas->setCurrentIndex(0);
  ui->comboBox_TypeRech_Ramas->addItem("Choississez un critère ");
  ui->comboBox_TypeRech_Ramas->addItem("Identifiant");
  ui->comboBox_TypeRech_Ramas->addItem("Matricule camion");
  ui->comboBox_TypeRech_Ramas->addItem("Date");
  ui->comboBox_TypeRech_Ramas->addItem("Nombre de poubelles");
  ui->comboBox_TypeRech_Ramas->addItem("Duree");
  ui->comboBox_TypeRech_Ramas->addItem("Heure début");
  ui->comboBox_TypeRech_Ramas->addItem("Nom Cartier");

  ui->comboBox_TypeRech_ZV->setCurrentIndex(0);
  ui->comboBox_TypeRech_ZV->addItem("Choississez un critère ");
  ui->comboBox_TypeRech_ZV->addItem("Identifiant");
  ui->comboBox_TypeRech_ZV->addItem("Libellé");
  ui->comboBox_TypeRech_ZV->addItem("Adresse");
  ui->comboBox_TypeRech_ZV->addItem("Aire");


  //Contrainte de saisie Aire
  ui->lineEdit_Aire_ZV_AJ->setValidator(new QIntValidator(0,999999, this));
  ui->lineEdit_Aire_MAJ_ZV->setValidator(new QIntValidator(0,999999, this));
  ui->lineEdit_IDChauffeurAJ->setValidator(new QIntValidator(0,99999999, this));

  ui->lineEdit_IDEmpl1_Rama->setValidator(new QIntValidator(0,99999999, this));

  ui->lineEdit_IDEmpl2_Rama->setValidator(new QIntValidator(0,99999999, this));


  QRegularExpression rx("[0-9][0-9][0-9]TN[0-9][0-9][0-9][0-9][0-9] ");
  QValidator *validator = new QRegularExpressionValidator(rx, this);
  ui->lineEdit_Matricule_MAJ->setValidator(validator);
  ui->lineEdit_MatriculeAJ->setValidator(validator);

  Clock* clock=new Clock(ui->widget_clock);
clock->setDisabled(1);
clock->resize(200, clock->height());
clock->resize(200, clock->width());
clock->show();
Clock* clock2=new Clock(ui->widget_clock2);
clock2->setDisabled(1);
clock2->show();

Clock* clock3=new Clock(ui->widget_clock3);
clock3->setDisabled(1);
clock3->show();

Clock* clock4=new Clock(ui->widget_clock_4);
clock4->setDisabled(1);
clock4->resize(200, clock4->height());
clock4->resize(200, clock4->width());
clock4->show();
  //Affichage Tab ZV
       ui->tableView_ZV ->setModel(tmpZV.afficher());
       ui->tableView_ZV ->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);


  //Affichage Tab Ramassage
    ui->tableView_Ramas->setModel(tmpR.afficher());
    ui->tableView_Ramas->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);


   ui->tableWidget->hide();

  //Delete gif
  auto movie = new QMovie(this);

  movie->setFileName("C:/Users/Bader Semah/Desktop/Smart_Municipality_2A3/gifs2.gif");
  QSize size(100,100);
    connect(movie, &QMovie::frameChanged, [=]{
      ui->pushButton_Delete_Ramas->setIcon(movie->currentPixmap());
    });
  ui->pushButton_Delete_Ramas->setIconSize(size);
   connect(movie, &QMovie::frameChanged, [=]{
      ui->pushButton_Sup_ZV->setIcon(movie->currentPixmap());
    });
  ui->pushButton_Delete_Ramas->setIconSize(size);

  ui->pushButton_Sup_ZV->setIconSize(size);
  movie->start();
  movie->setSpeed(200);


  //Modifier gif

    auto movie2 = new QMovie(this);

    movie2->setFileName("C:/Users/Bader Semah/Desktop/Smart_Municipality_2A3/crayons.gif");
      connect(movie2, &QMovie::frameChanged, [=]{
        ui->pushButton_MAJ_Ramas->setIcon(movie2->currentPixmap());
      });

    ui->pushButton_Delete_Ramas->setIconSize(size);
     connect(movie2, &QMovie::frameChanged, [=]{
        ui->pushButton_MAJ_ZV->setIcon(movie2->currentPixmap());
      });
    ui->pushButton_MAJ_Ramas->setIconSize(size);
    ui->pushButton_MAJ_ZV->setIconSize(size);

      movie2->start();
      movie2->setSpeed(50);

   //Search gif

      auto movie3 = new QMovie(this);
      QSize size2(31,31);
      movie3->setFileName("C:/Users/Bader Semah/Desktop/Smart_Municipality_2A3/loupe_anim.gif");
      connect(movie3, &QMovie::frameChanged, [=]{
        ui->pushButton_Icon_serachZV->setIcon(movie3->currentPixmap());

      });
      ui->pushButton_Icon_serachZV->setIconSize(size2);

      movie3->setFileName("C:/Users/Bader Semah/Desktop/Smart_Municipality_2A3/loupe_anim.gif");
      connect(movie3, &QMovie::frameChanged, [=]{
        ui->pushButton_Icon_serachR->setIcon(movie3->currentPixmap());

      });
      ui->pushButton_Icon_serachR->setIconSize(size2);
      movie3->start();
      movie3->setSpeed(50);

      //print gif
      auto movie4 = new QMovie(this);
      QSize size3(90,71);
      movie4->setFileName("C:/Users/Bader Semah/Desktop/Smart_Municipality_2A3/printer2.gif");
      connect(movie4, &QMovie::frameChanged, [=]{
        ui->pushButton_Print->setIcon(movie4->currentPixmap());
   ui->pushButton_Imprimer->setIcon(movie4->currentPixmap());
      });
      ui->pushButton_Print->setIconSize(size3);
          ui->pushButton_Imprimer->setIconSize(size3);
      movie4->start();
      movie4->setSpeed(230);

      auto movie5 = new QMovie(this);
      QSize size4(90,71);
      movie5->setFileName("C:/Users/Bader Semah/Desktop/Smart_Municipality_2A3/irrigation3.gif");
      connect(movie5, &QMovie::frameChanged, [=]{
        ui->pushButton_Irrigat->setIcon(movie5->currentPixmap());

      });
      ui->pushButton_Irrigat->setIconSize(size4);
      movie5->start();
      movie5->setSpeed(190);

      //Type d'employe


   //Connection Arduino Capteur Humidité
    int ret1=C.connect_capteur_humidite();
    qDebug()<<"ret"<<ret1;
    switch(ret1)
     {
      case(0):qDebug()<<"arduino is available and connected to: "<<C.get_capteur_humidite_port_name();
      break;
      case(1):qDebug()<<"arduino is available but not connected to:"<<C.get_capteur_humidite_port_name();
      break;
      case(-1):qDebug()<<"arduino is not available";
      break;
      }

  ui->pushButton_Ajout_ZV_Disab->hide();
  ui->pushButton_Disab->hide();

/************************************* End Rima *************************************************/
 /****************************************************Begin Nardine*********************************************/
      /************************AFFICHAGE DES TABLES : RAFRAICHIR******************************/
      ui->tableView_event->setModel(Etmp.afficher());
      ui->tableView_citoyen->setModel(Ctmp.afficher());


      /**********************************ICON & ANIMATION**********************************/
   //  setWindowIcon(QIcon("C:/Users/user/Desktop/logo.jpg"));
      QPixmap pixel ("C:/Users/user/Desktop/logo.jpg");
      ui->icon->setPixmap(pixel.scaled(400,400,Qt::KeepAspectRatio));
      int w= ui->icon->width();
      int h=ui->icon->height();
      animation=new QPropertyAnimation(ui->icon,"geometry");
      animation->setDuration(5000);
      animation->setStartValue(ui->icon->geometry());
      animation->setEndValue(QRect(1100,150,w,h));
      animation->setLoopCount(-1);
      animation->start();
      statistiques();

/********************************************End Nardine********************************************************/

/********************************************** Begin Semah *******************************************/

      Reclamation R ;
     ui->tableView_Reclamations_2->setStyleSheet("QHeaderView::section { background-color: white ; color :  rgb(192, 128, 129) }");
     ui->tableView_Ressources_2->setStyleSheet("QHeaderView::section { background-color: white ; color : rgb(192, 128, 129) }");

     Clock* maintenance_clock1=new Clock(ui->maintenance_clock1);
   maintenance_clock1->setDisabled(1);
   maintenance_clock1->resize(200, clock->height());
   maintenance_clock1->resize(200, clock->width());
   maintenance_clock1->show();
   Clock* maintenance_clock2=new Clock(ui->maintenance_clock2);
   maintenance_clock2->setDisabled(1);
  // maintenance_clock2->resize(10, clock->height());
   maintenance_clock2->setBaseSize(100,100);
   //maintenance_clock2->resize(30, clock->width());
   maintenance_clock2->show();

   Clock* maintenance_clock3=new Clock(ui->maintenance_clock3);
   maintenance_clock3->setDisabled(1);
  // maintenance_clock3->resize(60, clock->height());
  // maintenance_clock3->resize(30, clock->width());
   maintenance_clock3->setBaseSize(10,10);
   maintenance_clock3->show();

 /*  int ret=A.connect_arduino();
     switch(ret){
     case 0 :
         qDebug()<<"arduino is available on connected to "<<A.getarduino_port_name();
         break;
     case 1 :
         qDebug()<<"arduino is available but not connected to : "<<A.getarduino_port_name();
         break;
     case -1 :
         qDebug()<<"arduino is not available";
         break;
     }*/
 /********************************************** End Semah *******************************************/
   //*************************begin sahraoui*******************************************
   ui->afficher_marchand->setModel(tmp1.afficher());
   ui->afficher_mission->setModel(tmp2.afficher());
   MainWindow::stat();
   //**********************************end sahraoui**************************************


}

MainWindow::~MainWindow()
{
    delete ui;

}

/***RESIZE*/
void MainWindow::resizeAllElements(AutoResize *A){

    A->addOtherItem(ui->stackedWidget_Main);
    A->addOtherItem(ui->graphicsView_Munifacility);
    A->addOtherItem(ui->graphicsView_Munivipalit_LOGO);
    A->addOtherItem(ui->widget_clock);
    A->addOtherItem(ui->widget_clock2);
    A->addOtherItem(ui->widget_clock3);

    //widgets
    A->addOtherItem(ui->stackedWidgetMaintennance);
    A->addOtherItem(ui->stackedWidget_Environnement);
    A->addOtherItem(ui->stackedWidget);
    A->addOtherItem(ui->stackedWidget_resources_humaines);

    //tables
    A->addOtherItem(ui->tableView_Ressources_2);
    A->addOtherItem(ui->tableView_Reclamations_2);
    A->addOtherItem(ui->tableView_Ramas);
    A->addOtherItem(ui->tableView_ZV);
    A->addOtherItem(ui->tableView_citoyen);
    A->addOtherItem(ui->tableView_event);
    A->addOtherItem(ui->tableView_compte);
    A->addOtherItem(ui->tableView_employe);
    A->addOtherItem(ui->tableView_StatR);
    A->addOtherItem(ui->listView_compte);
    A->addOtherItem(ui->listView_employe);




    //Maintenance
    A->addOtherItem(ui->Ressource_Search_2);
    A->addOtherItem(ui->Reclamation_Serach_2);
    A->addOtherItem(ui->checkBox_ETAT_RESS_2);
    A->addOtherItem(ui->checkBox_NOM_RESS_2);
    A->addOtherItem(ui->checkBox_Route_REc_2);
    A->addOtherItem(ui->checkBox_TYPE_RESS_2);
    A->addOtherItem(ui->checkBox_Date_2);
    A->addOtherItem(ui->checkBox_Route_REc_2);
    A->addOtherItem(ui->checkBox_Type_REc_2);
    A->addOtherItem(ui->checkBox_nature_REc_2);
    A->addOtherItem(ui->Stat_2);
    A->addOtherItem(ui->maintenance_clock1);
    A->addOtherItem(ui->maintenance_clock2);
    A->addOtherItem(ui->maintenance_clock3);

    //Env
    A->addOtherItem(ui->groupBox);
    A->addOtherItem(ui->groupBox_2);
    A->addOtherItem(ui->graphicsView);
    A->addOtherItem(ui->Date_Stat);
    A->addOtherItem(ui->dateEditR_AJ);
    A->addOtherItem(ui->dateEditR_MAJ);
    A->addOtherItem(ui->timeEdit_DebAJ);
    A->addOtherItem(ui->timeEdit_DebMAJ);
    A->addOtherItem(ui->timeEdit_DureeAJ);
    A->addOtherItem(ui->timeEdit_DureeMAJ);
    A->addOtherItem(ui->spinBox_NbPoubelle_AJ);
    A->addOtherItem(ui->spinBox_NbPoubelle_MAJ);
    A->addOtherItem(ui->Notif_irrigation);

//Com
    A->addOtherItem(ui->frame);

//RH
    A->addOtherItem(ui->spinBox_NbPoubelle_AJ);
    A->addOtherItem(ui->spinBox_NbPoubelle_AJ);
    A->addOtherItem(ui->spinBox_NbPoubelle_AJ);
    A->addOtherItem(ui->spinBox_NbPoubelle_AJ);



}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    m_autoResizeHandler->doAutoResize();
}


/****/

/********************************************** Begin Wassim *******************************************/
void MainWindow::on_pushButton_Annuler_compte_MAJ_clicked()
{
    load();
     ui->stackedWidget_resources_humaines->setCurrentIndex(5);
}




void MainWindow::on_pushButton_aj_clicked()
{
    loade();

    ui->stackedWidget_resources_humaines->setCurrentIndex(3);

}


void MainWindow::on_pushButton_Annuler_AJ_clicked()
{
    loade();
    ui->lineEdit_mail_employe_AJ->clear();
    ui->lineEdit_nom_employe_AJ->clear();
    ui->lineEdit_prenom_employe_AJ->clear();

    ui->lineEdit_cin_employe_AJ->clear();

    ui->stackedWidget_resources_humaines->setCurrentIndex(2);
}

void MainWindow::on_pushButton_Annuler_MAJ_clicked()
{
      ui->stackedWidget_resources_humaines->setCurrentIndex(2);
}

void MainWindow::on_pushButton_Save_MAJ_clicked()
{
QString Type;
QString Nom;
QString Prenom;
QString mail;
QString cin;
QString etat;


bool test;
Nom= ui->lineEdit_nom_employe_MAJ->text();
Prenom= ui->lineEdit_prenom_employe_MAJ->text();

mail = ui->lineEdit_mail_employe_MAJ->text();

Type = ui->comboBox_Type_employe_MAJ->currentText();

cin = ui->lineEdit_cin_employe_MAJ->text();

etat = ui->comboBox_etat_employe_MAJ->currentText();

Employe e(Type,Nom,Prenom,cin,mail,etat);
if(!(ui->lineEdit_nom_employe_MAJ->text().isEmpty()||ui->lineEdit_prenom_employe_MAJ->text().isEmpty()||ui->lineEdit_cin_employe_MAJ->text().isEmpty()||ui->lineEdit_mail_employe_MAJ->text().isEmpty()))
{

 test = e.Update();
  }
if(test)

{

    QMessageBox :: information(nullptr, QObject :: tr("employe Modifié"),

                               QObject::tr("employe Modifié"),QMessageBox::Ok);
    ui->stackedWidget_resources_humaines->setCurrentIndex(2);


}

else

{
    QMessageBox::critical(this,"Alerte","Il faut tout remplire ! ");


}

}

void MainWindow::on_pushButton_compte_clicked()
{

    load();


    ui->stackedWidget_resources_humaines->setCurrentIndex(5);
}



void MainWindow::on_pushButton_Annuler_compte_clicked()
{
    load();
    ui->lineEdit_Identifiant_compte_AJ->clear();
    ui->lineEdit_mdp_compte_AJ->clear();
    ui->lineEdit_cin_compte_AJ->clear();
    ui->stackedWidget_resources_humaines->setCurrentIndex(5);
}





void MainWindow::on_pushButton_Ajout_compte_clicked()
{
    load();
if (aud==0)
    {
    ui->stackedWidget_resources_humaines->setCurrentIndex(6);
    }
else
{
    QMessageBox::information(this, tr("accees limité"),tr("tu n'est pas un admin"), QMessageBox::Ok);
}

}





void MainWindow::on_pushButton_Save_compte_MAJ_clicked()
{
    QString Type;
    QString mdp;
    QString Identifiant;
    QString cin;
 bool test;

    Identifiant = ui->lineEdit_ID_MAJ_compte->text();

    mdp = ui->lineEdit_mdp_MAJ_compte->text();

    Type = ui->comboBox_Type_MAJ_compte->currentText();

    cin = ui->lineEdit_cin_MAJ_compte->text();


    compte u(Type,Identifiant,cin,mdp);

    if(!(ui->lineEdit_ID_MAJ_compte->text().isEmpty()||ui->lineEdit_mdp_MAJ_compte->text().isEmpty()||ui->lineEdit_cin_MAJ_compte->text().isEmpty()))
    {

    test = u.Update();
    }

    if(test)

    {

        QMessageBox :: information(nullptr, QObject :: tr("compte Modifié"),

                                   QObject::tr("compte Modifié"),QMessageBox::Ok);
        ui->stackedWidget_resources_humaines->setCurrentIndex(5);

    }

    else

    {

        QMessageBox::critical(this,"Alerte","Il faut tout remplire ! ");



    }
    load();


}

void MainWindow::on_pushButton_Menu_compte_clicked()
{
     ui->stackedWidget_resources_humaines->setCurrentIndex(1);
}



//A MODIFIER


void MainWindow::on_pushButton_Close_clicked()
{
    QApplication::quit();
}

void MainWindow::on_pushButton_Close_affu_clicked()
{
    QApplication::quit();

}

void MainWindow::on_pushButton_Close_Em_maj_clicked()
{
    QApplication::quit();

}

void MainWindow::on_pushButton_Close_Em_AJ_clicked()
{
     QApplication::quit();
}



void MainWindow::on_pushButton_Close_compte_MAJ_clicked()
{
      QApplication::quit();
}

void MainWindow::on_pushButton_Close_compte_AJ_clicked()
{
      QApplication::quit();
}

void MainWindow::on_pushButton_Close_em_clicked()
{
    QApplication::quit();

}


void MainWindow::on_pushButton_Close_compte_clicked()
{
    QApplication::quit();

}
void MainWindow::on_pushButton_Close_affe_clicked()
{
    QApplication::quit();

}



void MainWindow::on_pushButton_Environ_pressed()
{  QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("C:/Users/Bader Semah/Desktop/Smart_Municipality_2A3/Click2.mp3"));
    player->setVolume(50);
    player->play();
    QPropertyAnimation *animation= new QPropertyAnimation(ui->pushButton_Environ,"geometry");
         animation->setDuration(2000);
         animation->setStartValue(QRect(20,80, 171,41));
         animation->setEndValue(QRect(60,80,171,41));

         animation->start();

         QPropertyAnimation *animation2= new QPropertyAnimation(ui->pushButton_Environ,"geometry");
              animation2->setDuration(1000);
              animation2->setStartValue(QRect(60,80, 171,41));
              animation2->setEndValue(QRect(20,80,171,41));
                 animation2->start();
  animation->destroyed() ;
    animation2->destroyed() ;
}





void MainWindow::on_pushButton_Marche_clicked()
{
    ui->stackedWidget_Main->setCurrentIndex(5);
    ui->stackedWidget_2->setCurrentIndex(0);
}

void MainWindow::on_pushButton_Marche_pressed()
{ QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("C:/Users/Bader Semah/Desktop/Smart_Municipality_2A3/Click2.mp3"));
    player->setVolume(50);
    player->play();
    QPropertyAnimation *animation= new QPropertyAnimation(ui->pushButton_Marche,"geometry");
         animation->setDuration(2000);
         animation->setStartValue(QRect(20,140, 171,41));
         animation->setEndValue(QRect(60,140,171,41));

         animation->start();

         QPropertyAnimation *animation2= new QPropertyAnimation(ui->pushButton_Marche,"geometry");
              animation2->setDuration(1000);
              animation2->setStartValue(QRect(60,140, 171,41));
              animation2->setEndValue(QRect(20,140,171,41));
                 animation2->start();
                 animation->destroyed() ;
                   animation2->destroyed() ;
}

void MainWindow::on_pushButton_MP_pressed()
{ QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("C:/Users/Bader Semah/Desktop/Smart_Municipality_2A3/Click2.mp3"));
    player->setVolume(50);
    player->play();
    QPropertyAnimation *animation= new QPropertyAnimation(ui->pushButton_MP,"geometry");
         animation->setDuration(2000);
         animation->setStartValue(QRect(20,20, 171,41));
         animation->setEndValue(QRect(60,20,171,41));

         animation->start();

         QPropertyAnimation *animation2= new QPropertyAnimation(ui->pushButton_MP,"geometry");
              animation2->setDuration(1000);
              animation2->setStartValue(QRect(60,20, 171,41));
              animation2->setEndValue(QRect(20,20,171,41));
                 animation2->start();
                 animation2->destroyed() ;
                   animation->destroyed() ;
}





void MainWindow::on_pushButton_Maintenance_pressed()
{ QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("C:/Users/Bader Semah/Desktop/Smart_Municipality_2A3/Click2.mp3"));
    player->setVolume(50);
    player->play();
    QPropertyAnimation *animation= new QPropertyAnimation(ui->pushButton_Maintenance,"geometry");
         animation->setDuration(2000);
         animation->setStartValue(QRect(20,260, 171,41));
         animation->setEndValue(QRect(60,260,171,41));

         animation->start();

         QPropertyAnimation *animation2= new QPropertyAnimation(ui->pushButton_Maintenance,"geometry");
              animation2->setDuration(1000);
              animation2->setStartValue(QRect(60,260, 171,41));
              animation2->setEndValue(QRect(20,260,171,41));
                 animation2->start();
                 animation2->destroyed() ;
                   animation->destroyed() ;
}





void MainWindow::on_pushButton_employe_clicked()
{
loade();
    ui->stackedWidget_resources_humaines->setCurrentIndex(2);

}

void MainWindow::on_pushButton_Menu_RH_clicked()
{
    ui->stackedWidget_resources_humaines->setCurrentIndex(1);

}

void MainWindow::load()
{
    compte u;
    QSqlQueryModel *model=new QSqlQueryModel();
    model=u.load();
    ui->listView_compte->setModel(model);
}




void MainWindow::showContextMenu(const QPoint &pos)
{
    // Handle global position
    QPoint globalPos = ui->listView_compte->mapToGlobal(pos);

    // Create menu and insert some actions
    QMenu myMenu;

    myMenu.addAction("Afficher", this, SLOT(viewcompte()));
    myMenu.addAction("Modifier",  this, SLOT(editcompte()));
    myMenu.addAction("Supprimer", this, SLOT(deletecompte()));


    // Show context menu at handling position
    myMenu.exec(globalPos);

}

void MainWindow::viewcompte()
{
    if (aud==0)
    {
   compte u;
           QModelIndex index = ui->listView_compte->currentIndex();

               QString info = index.data(Qt::DisplayRole).toString();
               ui->tableView_compte->setModel(u.read(info));

               ui->stackedWidget_resources_humaines->setCurrentIndex(8);  }
               else
               {
                   QMessageBox::information(this, tr("accees limité"),tr("tu n'est pas un admin"), QMessageBox::Ok);
               }

}

void MainWindow::deletecompte()
{
    if (aud==0)
    {
    compte u;
    QModelIndex index = ui->listView_compte->currentIndex();

    QString info = index.data(Qt::DisplayRole).toString();



            bool test=u.Delete(info);

            if(test)
            {
                 load();
                 QMessageBox::information(this, tr("compte supprimé"),tr("OK"), QMessageBox::Ok);
            }  }
            else
            {
                QMessageBox::information(this, tr("accees limité"),tr("tu n'est pas un admin"), QMessageBox::Ok);
            }

}

void MainWindow::editcompte()
{
    if (aud==0)
    {
    QModelIndex index = ui->listView_compte->currentIndex();

        QString info = index.data(Qt::DisplayRole).toString();

        QSqlQuery view;

        compte u;

        view=u.editview(info);

        while(view.next())

        {

              ui->lineEdit_ID_MAJ_compte->setText(view.value(0).toString());

              ui->lineEdit_mdp_MAJ_compte->setText(view.value(1).toString());
              ui->comboBox_Type_MAJ_compte->setCurrentText(view.value(2).toString());


              ui->lineEdit_cin_MAJ_compte->setText(view.value(3).toString());

    ui->stackedWidget_resources_humaines->setCurrentIndex(7);


        }}
        else
        {
            QMessageBox::information(this, tr("accees limité"),tr("tu n'est pas un admin"), QMessageBox::Ok);
        }



}


void MainWindow::on_pushButton_annuler_aff_clicked()
{
    ui->stackedWidget_resources_humaines->setCurrentIndex(5);
}



void MainWindow::on_pushButton_Save_employe_clicked()
{
    {
    bool test;
    QString Nom,Prenom,mail,cin,Type,etat,Nomtemp;

    Nom = ui->lineEdit_nom_employe_AJ->text();
    Prenom = ui->lineEdit_prenom_employe_AJ->text();

    mail = ui->lineEdit_mail_employe_AJ->text();
    Type = ui->comboBox_Type_employe_AJ->currentText();
    cin = ui->lineEdit_cin_employe_AJ->text();
    etat = ui->comboBox_etat_employe_AJ->currentText();



    Employe E(Type,Nom,Prenom,cin,mail,etat);
    if(!(ui->lineEdit_nom_employe_AJ->text().isEmpty()||ui->lineEdit_prenom_employe_AJ->text().isEmpty()||ui->lineEdit_cin_employe_AJ->text().isEmpty()||ui->lineEdit_mail_employe_AJ->text().isEmpty()))
    {
    test=E.ajouter();
}
    if(test)
    {
        QMessageBox :: information(nullptr, QObject :: tr("ajout employe"),
                                               QObject::tr("employe ajouté"),QMessageBox::Ok);
        ui->stackedWidget_resources_humaines->setCurrentIndex(2);

    }
    else
    {
        QMessageBox::critical(this,"Alerte","Il faut tout remplire ! ");


    }


    }

    ui->lineEdit_nom_employe_AJ->clear();
    ui->lineEdit_prenom_employe_AJ->clear();

    ui->lineEdit_mail_employe_AJ->clear();
    ui->lineEdit_cin_employe_AJ->clear();
    loade();




}

void MainWindow::on_pushButton_Save_compte_clicked()
{

    bool test;
    QString Identifiant,mdp,cin,Type;

    Identifiant = ui->lineEdit_Identifiant_compte_AJ->text();
    mdp = ui->lineEdit_mdp_compte_AJ->text();
    Type = ui->comboBox_Type_compte_AJ->currentText();
    cin = ui->lineEdit_cin_compte_AJ->text();

    compte u(Type,Identifiant,cin,mdp);
    if(!(ui->lineEdit_Identifiant_compte_AJ->text().isEmpty()||ui->lineEdit_mdp_compte_AJ->text().isEmpty()||ui->lineEdit_cin_compte_AJ->text().isEmpty()))
    {    test=u.ajouter();
}
    if(test)
    {
        QMessageBox :: information(nullptr, QObject :: tr("compte ajouté"),
                                               QObject::tr("compte ajouté"),QMessageBox::Ok);
        ui->stackedWidget_resources_humaines->setCurrentIndex(5);
    }
    else
    {
        QMessageBox::critical(this,"Alerte","Il faut tout remplire ! ");


    }

     ui->lineEdit_Identifiant_compte_AJ->clear();
     ui->lineEdit_mdp_compte_AJ->clear();
     ui->lineEdit_cin_compte_AJ->clear();

     load();



    }









void MainWindow::on_pushButton_affiche_compte_clicked()
{
    load();
}

void MainWindow::loade()
{
    Employe e;
    QSqlQueryModel *model=new QSqlQueryModel();
    model=e.load();
    ui->listView_employe->setModel(model);
}




void MainWindow::showContextMenue(const QPoint &pos2)
{
     //Handle global position
   QPoint globalPos2 = ui->listView_employe->mapToGlobal(pos2);

    // Create menu and insert some actions
    QMenu myMenu2;
    myMenu2.addAction("Afficher", this, SLOT(viewemploye()));
    myMenu2.addAction("Modifier",  this, SLOT(editemploye()));
    myMenu2.addAction("Supprimer", this, SLOT(deleteemploye()));
    myMenu2.addAction("Email", this, SLOT(emailemploye()));
    // Show context menu at handling position
    myMenu2.exec(globalPos2);
}

void MainWindow::viewemploye()
{
   Employe e;
           QModelIndex index = ui->listView_employe->currentIndex();

               QString info = index.data(Qt::DisplayRole).toString();
               ui->tableView_employe->setModel(e.read(info));

               ui->stackedWidget_resources_humaines->setCurrentIndex(9);
}

void MainWindow::deleteemploye()
{
    if( aud == 0)
    {
        Employe e;
        QModelIndex index = ui->listView_employe->currentIndex();

        QString info = index.data(Qt::DisplayRole).toString();



                bool test=e.Delete(info);

                if(test)
                {
                     loade();
                     QMessageBox::information(this, tr("employe supprimé"),tr("OK"), QMessageBox::Ok);
                }

    }
    else
    {
        QMessageBox::information(this, tr("accees limité"),tr("tu n'est pas un admin"), QMessageBox::Ok);
    }
}

void MainWindow::editemploye()
{
    if(aud == 0)
    {
        QModelIndex index = ui->listView_employe->currentIndex();

            QString info = index.data(Qt::DisplayRole).toString();

            QSqlQuery view;

            Employe e;

            view=e.editview(info);

            while(view.next())

            {

                ui->lineEdit_nom_employe_MAJ->setText(view.value(0).toString());

                            ui->lineEdit_prenom_employe_MAJ->setText(view.value(1).toString());

                            ui->lineEdit_mail_employe_MAJ->setText(view.value(2).toString());
                            ui->comboBox_Type_employe_MAJ->setCurrentText(view.value(3).toString());


                            ui->lineEdit_cin_employe_MAJ->setText(view.value(4).toString());
                            ui->comboBox_etat_employe_MAJ->setCurrentText(view.value(5).toString());


                  ui->stackedWidget_resources_humaines->setCurrentIndex(4);


            }

    }
    else
    {
        QMessageBox::information(this, tr("accees limité"),tr("tu n'est pas un admin"), QMessageBox::Ok);
    }



}




void MainWindow::on_pushButton_affiche_em_clicked()
{
    loade();
}





void MainWindow::on_pushButton_annuler_affe_clicked()
{
    ui->stackedWidget_resources_humaines->setCurrentIndex(2);

}

void MainWindow::on_pushButton_login_clicked()
{

    /*QString Identifiant,mdp;
    compte u;
QSqlQuery test;
    Identifiant=(ui->Login_identifiant->text());
   mdp=(ui->Login_mdp->text());
   test=u.authen(Identifiant,mdp);
   {
       if(test.next())
       {
                 if()
                 {

                 }
                 ui->stackedWidget_Main->setCurrentIndex(0);

                 QMessageBox::information(this,"login"," Bienvenue");


     }
     else
     {
     QMessageBox::information(this,"non existe"," information incorrecte");
     }*/

    QString id = ui->Login_identifiant->text();

    compte c;

    bool test = c.search(id);

    if(test == true)
    {
        QSqlQuery view = c.readid(id);
        if(view.value(1).toString() == ui->Login_mdp->text())
        {
            if(view.value(2).toString() == "Administrateur")
            {
                aud=0;
            }
            else
            {
                aud=1;
            }

            ui->stackedWidget_Main->setCurrentIndex(0);

            QMessageBox::information(this,"login"," Bienvenue");

        }
        else
        {
            QMessageBox::information(this,"Password incorrecte"," information incorrecte");
        }
    }
    else
    {
        QMessageBox::information(this,"id non existe"," information incorrecte");
    }


    if(aud==1)
       {
          ui->pushButton->setDisabled(true);
          ui->pushButton_Ajout_ZV->setDisabled(true);
          ui->pushButton_MAJ_ZV->setDisabled(true);
          ui->pushButton_MAJ_Ramas->setDisabled(true);
          ui->pushButton_Delete_Ramas->setDisabled(true);
          ui->pushButton_Sup_ZV->setDisabled(true);
          ui->pushButton_Ajout_ZV_Disab->show();
          ui->pushButton_Ajout_ZV->hide();
          ui->pushButton_Disab->show();
          ui->pushButton->hide();
      }


}

void MainWindow::on_lineEdit_recherche_compte_textChanged(const QString &arg1)
{
     compte c;
        QString info =arg1;
        if(info!="")
        ui->listView_compte->setModel(c.chercher(info));
        else
            load();
}




void MainWindow::on_lineEdit_recherche_employe_textChanged(const QString &arg1)
{
    {
         Employe e;
            QString info =arg1;
            if(info!="")
            ui->listView_employe->setModel(e.chercher(info));
            else
                loade();
    }

}
/**************** Déplacement entre les modules pour le  Module Ressources Humaines *****************************************/
void MainWindow::on_pushButton_MP_clicked()
{
     ui->stackedWidget_Main->setCurrentIndex(0);
}

void MainWindow::on_pushButton_Environ_clicked()
{
    ui->stackedWidget_Main->setCurrentIndex(2);
    ui->stackedWidget_Environnement->setCurrentIndex(0);
}
void MainWindow::on_pushButton_Maintenance_clicked()
{
     ui->stackedWidget_Main->setCurrentIndex(4);
}

void MainWindow::on_communication_RH_clicked()
{
    ui->stackedWidget_Main->setCurrentIndex(3);
       ui->stackedWidget->setCurrentIndex(0);
}
void MainWindow::emailemploye()
{
    if(aud == 0)
    {
        QModelIndex index = ui->listView_employe->currentIndex();

        QString info = index.data(Qt::DisplayRole).toString();

        QSqlQuery view;

        Employe E;

        view=E.readmail(info);


        mail=view.value(2).toString();


        ui->stackedWidget_resources_humaines->setCurrentIndex(10);

    }
else
    {
        QMessageBox::information(this, tr("accees limité"),tr("tu n'est pas un admin"), QMessageBox::Ok);
    }
}
void MainWindow::on_pushButton_RessourcesHumaine_clicked()
{
     ui->stackedWidget_Main->setCurrentIndex(1);
     ui->stackedWidget_resources_humaines->setCurrentIndex(1);
}



void MainWindow::on_pushButton_cancelm_clicked()
{
    ui->stackedWidget_resources_humaines->setCurrentIndex(2);

}

void MainWindow::on_pushButton_send_clicked()
{
    smtp = new Smtp("projetqt2021@gmail.com" , "projet123456", "smtp.gmail.com",465);

    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

    msg=ui->plainTextEdit->toPlainText();

    qDebug()<<mail;

    smtp->sendMail("projetqt2021@gmail.com",mail,ui->lineEdit->text(),msg);
}

void MainWindow::on_pushButton_tri_em_clicked()
{
    Employe E;

    QSqlQueryModel *model=new QSqlQueryModel();

    model=E.sort();

    ui->listView_employe->setModel(model);
}

void MainWindow::on_pushButton_imprimer_em_clicked()
{
    QModelIndex index = ui->listView_employe->currentIndex();

        QString info = index.data(Qt::DisplayRole).toString();

        QSqlQuery view;

        Employe e;

        view=e.editview(info);
    view.next();
    QPlainTextEdit text;
        text.setStyleSheet("QPlainTextEdit{color: #ffff00; background-color: #303030;");
        QTextDocument *doc = text.document();
        QFont font = doc->defaultFont();
        font.setBold(true);
        font.setFamily("Arial");
        font.setPixelSize(20);
        doc->setDefaultFont(font);
        text.appendPlainText("municipalité");
        text.appendPlainText("");
        text.appendPlainText("");
        text.appendPlainText("nom: "+view.value(0).toString()+"");

        text.appendPlainText("prenom: "+view.value(1).toString()+"");

        text.appendPlainText("mail: "+view.value(2).toString()+"");
             qDebug()<< view.value(2).toString();
        text.appendPlainText("type: "+view.value(3).toString()+"");

        text.appendPlainText("cin: "+view.value(4).toString()+"");

        text.appendPlainText("etat: "+view.value(5).toString()+"");

        QPrinter printer;
            printer.setPrinterName("Print");
            QPrintDialog dlg(&printer,this);
            if (dlg.exec() == QDialog::Rejected)
            {
                return;
            }
            text.print(&printer);
}

void MainWindow::on_pushButton_retour_em_clicked()
{
    ui->stackedWidget_resources_humaines->setCurrentIndex(2);

}

void MainWindow::on_pushButton_statistique_em_clicked()
{
    Employe E;
        QChartView * chartView=new QChartView(E.statistic());
        chartView ->setParent(ui->statisticFrame);
        chartView->setFixedSize(ui->statisticFrame->size());
        ui->stackedWidget_resources_humaines->setCurrentIndex(11);
}



/******************** Fin déplacement entre les modules pour le  Module Ressources Humaines*************************************/


/********************************************** End Wassim *******************************************/
/******************************************************************************************************/






/******************************************************************************************************/
/**********************************************   Begin Rima   *******************************************/
void MainWindow::INIT()
{
    ui->lineEdit_ID_Ramas_Aff->clear();
    ui->lineEdit_Matricule_Aff->clear();
    ui->lineEdit_IDChauffeur_Aff->clear();
    ui->lineEdit_IDEmploye1_Aff->clear();
    ui->lineEdit_IDEmploye2_Aff->clear();
    ui->lineEdit_Date_Aff->clear();
    ui->lineEdit_NbPoubelle_Aff->clear();
    ui->lineEdit_Duree_Aff->clear();
    ui->lineEdit_NomCartier_Aff->clear();
    ui->lineEdit_HeureDebut_Aff->clear();
    ui->groupBox_2->setTitle("");

}

void MainWindow::INIT_ZV()
{
    ui->lineEdit_ID_Aff_ZV->clear();
    ui->lineEdit_Libelle_Aff_ZV->clear();
    ui->lineEdit_Adresse_Aff_ZV->clear();
     ui->lineEdit_Aire_Aff_ZV->clear();

ui->groupBox->setTitle("");
}

//SaveAJ_Ramassage
void MainWindow::on_pushButton_Save_AJ_clicked()
{  INIT();
Ramassage R;
QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("C:/Users/Bader Semah/Desktop/Smart_Municipality_2A3/Click2.mp3"));
    player->setVolume(50);
    player->play();
    ui->tableView_Ramas->setModel(tmpR.afficher());
    ui->tri_ramassage->hide();
/*************/
//Set Values
R.setIdChauffeur(ui->lineEdit_IDChauffeurAJ->text());
R.setMatricule(ui->lineEdit_MatriculeAJ->text());
R.setNom_cartier(ui->comboBox_NomCartier_AJ->currentText());
R.setDate(ui->dateEditR_AJ->date().toString("dd/MM/yyyy"));
R.setHdepart(ui->timeEdit_DebAJ->time());
R.setDuree(ui->timeEdit_DureeAJ->time());
R.setNb_Poubelle(ui->spinBox_NbPoubelle_AJ->text());
R.setId_empl1(ui->lineEdit_IDEmpl1_Rama->text());
R.setId_empl2(ui->lineEdit_IDEmpl2_Rama->text());

bool test;
if(!(ui->lineEdit_IDChauffeurAJ->text().isEmpty()||ui->lineEdit_MatriculeAJ->text().isEmpty()||
     ui->comboBox_NomCartier_AJ->currentText().isEmpty()||ui->dateEditR_AJ->date().isNull()||ui->timeEdit_DebAJ->time().isNull()||ui->timeEdit_DureeAJ->time().isNull()||
    ui->spinBox_NbPoubelle_AJ->cleanText().isEmpty()||ui->lineEdit_IDEmpl1_Rama->text().isEmpty()||ui->lineEdit_IDEmpl2_Rama->text().isEmpty()))
{
test= R.ajouter();


 if (test)
{
     QString ch;
      bool test1;
     for(int i=0;i<3;i++)
     {if(i==0)
            { ch=R.getIdchauffeur();
     test1=R.affectation(ch);
         }
         else if (i==1)
         { ch=R.getId_empl1();
     test1=R.affectation2(ch);
      }
         else if (i==2)
         { ch=R.getId_empl2();
     test1=R.affectation3(ch);
 }
     }
     if(test1)
     {
 QMessageBox::information(this,"Notification","Le rammasage a bien été enregistré ");


  //Affichage
 ui->tableView_Ramas->setModel(tmpR.afficher());




ui->stackedWidget_Environnement->setCurrentIndex(1);


 }
else {QMessageBox::critical(this,"Alerte","Les données entrées sont incorrectes ! ");
        R.SupprimerEmploye(R.getId_Ramassage());
         R.Supprimer(R.getId_Ramassage());
ui->stackedWidget_Environnement->setCurrentIndex(1);

}
}

 ui->lineEdit_IDChauffeurAJ->clear();
 ui->lineEdit_MatriculeAJ->clear();
 ui->dateEditR_AJ->clear();
 ui->timeEdit_DureeAJ->clear();
 ui->timeEdit_DebAJ->clear();
 ui->dateEditR_AJ->clear();
 ui->spinBox_NbPoubelle_AJ->clear();
 ui->lineEdit_IDEmpl1_Rama->clear();
 ui->lineEdit_IDEmpl2_Rama->clear();
}
else QMessageBox::critical(this,"Alerte","Il faut tout remplire ! ");



}


//Ajout_ZV
void MainWindow::on_pushButton_Save_ZV_clicked()
{ Zone_Verte Z;
    INIT_ZV();
    //sound
    QMediaPlayer *player = new QMediaPlayer;
        player->setMedia(QUrl::fromLocalFile("C:/Users/Bader Semah/Desktop/Smart_Municipality_2A3/Click2.mp3"));
        player->setVolume(50);
        player->play();

        /****/

        if(!(ui->comboBox_Adresse_ZV_AJ->currentText().isEmpty()||ui->lineEdit_Libelle_ZV_AJ->text().isEmpty()||ui->lineEdit_Aire_ZV_AJ->text().isEmpty()))
        {

    Z.setAdresse(ui->comboBox_Adresse_ZV_AJ->currentText());
    Z.setLibelle(ui->lineEdit_Libelle_ZV_AJ->text());
    Z.setAire(ui->lineEdit_Aire_ZV_AJ->text());
    QMessageBox msgB;

    msgB.setText("La zone verte a bien été enregistrée ");
    msgB.exec();
      ui->stackedWidget_Environnement->setCurrentIndex(4);


      //Reset lineEdit
      ui->lineEdit_Libelle_ZV_AJ->clear();
      ui->lineEdit_Aire_ZV_AJ->clear();
        }
        else
QMessageBox::critical(this,"Alerte","Il faut tout remplire ! ");
//Ajout
Z.ajouter();
//Affichage
ui->tableView_ZV ->setModel(tmpZV.afficher());

}

void MainWindow::on_pushButton_Annuler_ZV_MAJ_clicked()
{
     ui->stackedWidget_Environnement->setCurrentIndex(4);
}


void MainWindow::on_pushButton_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("C:/Users/Bader Semah/Desktop/Smart_Municipality_2A3/Click2.mp3"));
    player->setVolume(50);
    player->play();

    ui->stackedWidget_Environnement->setCurrentIndex(3);

}


void MainWindow::on_pushButton_Annuler_AJ_R_clicked()
{    INIT();
    QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("C:/Users/Bader Semah/Desktop/Smart_Municipality_2A3/Click2.mp3"));
    player->setVolume(50);
    player->play();
    ui->tableView_Ramas->setModel(tmpR.afficher());
    ui->tri_ramassage->hide();
    ui->stackedWidget_Environnement->setCurrentIndex(1);
}

void MainWindow::on_pushButton_Annuler_MAJ_R_clicked()
{

    QMediaPlayer *player = new QMediaPlayer;
        player->setMedia(QUrl::fromLocalFile("C:/Users/Bader Semah/Desktop/Smart_Municipality_2A3/Click2.mp3"));
        player->setVolume(50);
        player->play();
        ui->tableView_Ramas->setModel(tmpR.afficher());
        ui->tri_ramassage->hide();

    ui->stackedWidget_Environnement->setCurrentIndex(1);
}


void MainWindow::on_pushButton_ZV_clicked()
{ INIT_ZV();
     ui->tableView_ZV ->setModel(tmpZV.afficher());
    ui->stackedWidget_Environnement->setCurrentIndex(4);
}



void MainWindow::on_pushButton_Annuler_ZV_clicked()
{
    INIT_ZV();
    QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("C:/Users/Bader Semah/Desktop/Smart_Municipality_2A3/Click2.mp3"));
    player->setVolume(50);
    player->play();
    ui->stackedWidget_Environnement->setCurrentIndex(4);
}



void MainWindow::on_pushButton_Menu_Environ_Aff_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("C:/Users/Bader Semah/Desktop/Smart_Municipality_2A3/Click2.mp3"));
    player->setVolume(50);
    player->play();
     ui->stackedWidget_Environnement->setCurrentIndex(0);
}



void MainWindow::on_pushButton_Ajout_ZV_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("C:/Users/Bader Semah/Desktop/Smart_Municipality_2A3/Click2.mp3"));
    player->setVolume(50);
    player->play();
    ui->stackedWidget_Environnement->setCurrentIndex(6);
}






void MainWindow::on_pushButton_Menu_Environ_Aff_ZV_clicked()
{QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("C:/Users/Bader Semah/Desktop/Smart_Municipality_2A3/Click2.mp3"));
    player->setVolume(50);
    player->play();
     ui->stackedWidget_Environnement->setCurrentIndex(0);
}





void MainWindow::on_pushButton_Close_Envir_clicked()
{
    QApplication::quit();
}

void MainWindow::on_pushButton_Close_Envir_2_clicked()
{
       QApplication::quit();

}

void MainWindow::on_pushButton_Close_Envir_3_clicked()
{
    QApplication::quit();

}

void MainWindow::on_pushButton_Close_Envir_4_clicked()
{
     QApplication::quit();
}

void MainWindow::on_pushButton_Close_Envir_5_clicked()
{
      QApplication::quit();
}

void MainWindow::on_pushButton_Close_Envir_6_clicked()
{
      QApplication::quit();
}

void MainWindow::on_pushButton_Close_Envir_8_clicked()
{
      QApplication::quit();
}





//////////////////////////////////////////////////////

void MainWindow::on_pushButton_R_clicked()
{

INIT();
 ui->tableView_Ramas->setModel(tmpR.afficher());
    ui->stackedWidget_Environnement->setCurrentIndex(1);

}

//////////////////////////////////////////////////////////////


void MainWindow::on_tableView_ZV_activated(const QModelIndex &index)
{ ui->Notif_irrigation->show();
 ui->pushButton_Irrigat->show();
Zone_Verte Z;
QString ID=ui->tableView_ZV->model()->data(index).toString();
QString Aire,Libelle,Adresse;

      Z. Remplissage(&ID,&Libelle,&Adresse,&Aire);

      ui->lineEdit_ID_Aff_ZV->setText(ID) ;
      ui->lineEdit_Libelle_Aff_ZV->setText(Libelle);
      ui->lineEdit_Adresse_Aff_ZV->setText(Adresse);
       ui->lineEdit_Aire_Aff_ZV->setText(Aire);

 ui->groupBox->setTitle( ui->lineEdit_ID_Aff_ZV->text());
    QObject::connect(C.getserial(),SIGNAL(readyRead()),this,SLOT(update_label()));

}



void MainWindow::on_tableView_Ramas_activated(const QModelIndex &index)
{
Ramassage R;
  QString ID=ui->tableView_Ramas->model()->data(index).toString();

QString Matricule,Id_chauffeur,id_empl1,id_empl2,Date,Nb_poubelle,Nom_Cartier,Duree,Heure;
R.Remplissage(&ID,&Matricule,&Date,&Nb_poubelle,&Nom_Cartier,&Duree,&Heure);

 QVector<QString> tab;

tab= R.afficheremploye(&ID);


ui->lineEdit_ID_Ramas_Aff->setText(ID);
ui->lineEdit_Matricule_Aff->setText(Matricule);
ui->lineEdit_IDChauffeur_Aff->setText(tab[0]);
ui->lineEdit_IDEmploye1_Aff->setText(tab[1]);
ui->lineEdit_IDEmploye2_Aff->setText(tab[2]);
ui->lineEdit_Date_Aff->setText(Date);
ui->lineEdit_NbPoubelle_Aff->setText(Nb_poubelle);
ui->lineEdit_Duree_Aff->setText(Duree);
ui->lineEdit_NomCartier_Aff->setText(Nom_Cartier);
ui->lineEdit_HeureDebut_Aff->setText(Heure);


ui->groupBox_2->setTitle( ui->lineEdit_ID_Ramas_Aff->text());
}






void MainWindow::on_pushButton_Delete_Ramas_clicked()
{

    QMediaPlayer *player = new QMediaPlayer;
        player->setMedia(QUrl::fromLocalFile("C:/Users/Bader Semah/Desktop/Smart_Municipality_2A3/trash.mp3"));
        player->setVolume(50);
Ramassage R;


    QString ID;
     ID=ui->lineEdit_ID_Ramas_Aff->text();

    bool test1=R.SupprimerEmploye(ID);
    if  (test1 &&!( ui->groupBox_2->title().isEmpty()) )
       {   player->play();
   tmpR.Supprimer(ID);
        ui->lineEdit_ID_Ramas_Aff->clear();
        ui->lineEdit_Matricule_Aff->clear();
        ui->lineEdit_IDChauffeur_Aff->clear();
        ui->lineEdit_IDEmploye1_Aff->clear();
        ui->lineEdit_IDEmploye2_Aff->clear();
        ui->lineEdit_Date_Aff->clear();
        ui->lineEdit_NbPoubelle_Aff->clear();
        ui->lineEdit_Duree_Aff->clear();
        ui->lineEdit_NomCartier_Aff->clear();
        ui->lineEdit_HeureDebut_Aff->clear();
         ui->lineEdit_Adresse_Aff_ZV->clear();
        ui->groupBox_2->setTitle("");
        ui->tableView_Ramas->setModel(tmpR.afficher());
        QMessageBox::information(nullptr,QObject::tr("Supprimer un ramassage")
                                 ,QObject::tr("Le ramassage a été supprimé"));

    }
    else if ( ui->groupBox_2->title().isEmpty())
    {
        QMessageBox::critical(nullptr,QObject::tr("Supprimer un ramassage")
                                 ,QObject::tr("Pas de ramassage à supprimer!"));
    }
    player->stop();
}

void MainWindow::on_pushButton_Sup_ZV_clicked()
{
    QString ID;
    ID= ui->lineEdit_ID_Aff_ZV->text();
   bool test= tmpZV.Supprimer(ID);
   if  (test && !( ui->groupBox->title().isEmpty()))
      {
       ui->lineEdit_ID_Aff_ZV->clear();
       ui->lineEdit_Libelle_Aff_ZV->clear();
       ui->lineEdit_Adresse_Aff_ZV->clear();
        ui->lineEdit_Aire_Aff_ZV->clear();
       ui->groupBox->setTitle("");
   ui->tableView_ZV ->setModel(tmpZV.afficher());
       QMessageBox::information(nullptr,QObject::tr("Supprimer une zone verte")
                                ,QObject::tr("La zone verte a été supprimée"));

   }
   else if ( ui->groupBox->title().isEmpty())
   {
       QMessageBox::critical(nullptr,QObject::tr("Supprimer une zone verte")
                                ,QObject::tr("Pas de zone verte à supprimer!"));
   }
}

void MainWindow::on_pushButton_MAJ_ZV_clicked()
{if (ui->groupBox->title().isEmpty())
    {
        QMessageBox::critical(nullptr,QObject::tr("Modifier une zone verte")
                                 ,QObject::tr("Pas de zone verte à modifier!"));
    }
    else
    {
     ui->stackedWidget_Environnement->setCurrentIndex(5);

     ui->lineEdit_ID_MAJ_ZV->setText(ui->lineEdit_ID_Aff_ZV->text());
     ui->lineEdit_Aire_MAJ_ZV->setText(ui->lineEdit_Aire_Aff_ZV->text());
     ui->lineEdit_Libelle_MAJ_ZV->setText(ui->lineEdit_Libelle_Aff_ZV->text());

 ui->lineEdit_ID_MAJ_ZV->setDisabled(true);
    }
}
void MainWindow::on_pushButton_MAJ_Ramas_clicked()
{
    if (ui->groupBox_2->title().isEmpty())
    {
        QMessageBox::critical(nullptr,QObject::tr("Modifier un ramassage")
                                 ,QObject::tr("Pas de ramassage à modifier!"));
    }

    else
    {
    ui->stackedWidget_Environnement->setCurrentIndex(2);
    ui->lineEdit_IDRamassage_MAJ->setText(ui->lineEdit_ID_Ramas_Aff->text());
    ui->lineEdit_Matricule_MAJ->setText(ui->lineEdit_Matricule_Aff->text());

    qDebug()<<"Date: "<<ui->lineEdit_Date_Aff->text();
    ui->dateEditR_MAJ->setDate(QDate::fromString(ui->lineEdit_Date_Aff->text(),"dd/MM/yyyy"));
    ui->spinBox_NbPoubelle_MAJ->setValue(ui->lineEdit_NbPoubelle_Aff->text().toInt());
    ui->timeEdit_DureeMAJ->setTime( QTime::fromString(ui->lineEdit_Duree_Aff->text()));
    ui->comboBox_NomCartier_MAJ->setCurrentText(ui->lineEdit_NomCartier_Aff->text());
    ui->timeEdit_DebMAJ->setTime( QTime::fromString(ui->lineEdit_HeureDebut_Aff->text()));
    ui->lineEdit_IDRamassage_MAJ->setDisabled(true);
    }
}
void MainWindow::on_pushButton_Save_ZV_MAJ_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("C:/Users/Bader Semah/Desktop/Smart_Municipality_2A3/Click2.mp3"));
    player->setVolume(50);
    player->play();

QString ID,Aire,Libelle,Adresse;
Aire=ui->lineEdit_Aire_MAJ_ZV->text();
Libelle=ui->lineEdit_Libelle_MAJ_ZV->text();
ID= ui->lineEdit_ID_MAJ_ZV->text();
Adresse=ui->lineEdit_Adresse_Aff_ZV->text();
  bool test= tmpZV.Modifier(ID,Libelle,Aire,Adresse);
  if  (test)
     {

  ui->tableView_ZV ->setModel(tmpZV.afficher());
      QMessageBox::information(nullptr,QObject::tr("Modifier une zone verte")
                               ,QObject::tr("La zone verte a été modifiée"));
       ui->stackedWidget_Environnement->setCurrentIndex(4);
Zone_Verte Z;

     Z. Remplissage(&ID,&Libelle,&Adresse,&Aire);

     ui->lineEdit_Libelle_Aff_ZV->setText(Libelle);
     ui->lineEdit_Adresse_Aff_ZV->setText(Adresse);
      ui->lineEdit_Aire_Aff_ZV->setText(Aire);
        }

}



void MainWindow::on_pushButton_SaveR_MAJ_clicked()
{
    QMessageBox msgB;
        Ramassage R;
    //Sound
       QMediaPlayer *player = new QMediaPlayer;
        player->setMedia(QUrl::fromLocalFile("C:/Users/Bader Semah/Desktop/Smart_Municipality_2A3/Click2.mp3"));
        player->setVolume(50);
        player->play();
        ui->tableView_Ramas->setModel(tmpR.afficher());
        ui->tri_ramassage->hide();
    //Affichage de l'id à MAJ
 //   ui->lineEdit_IDChauffeurMAJ->setText(ui->lineEdit_IDChauffeur_Aff->text());


    QString ID,Matricule,Id_chauffeur,id_empl1,id_empl2,Date,Nb_poubelle,Nom_Cartier,Duree,Heure;


    //Set des vals à jour
   ID=ui->lineEdit_IDRamassage_MAJ->text();

   Matricule=ui->lineEdit_Matricule_MAJ->text();

    Nom_Cartier=ui->comboBox_NomCartier_MAJ->currentText();
    Date=ui->dateEditR_MAJ->date().toString("dd/MM/yyyy");
    Heure=ui->timeEdit_DebMAJ->time().toString();
    Duree=ui->timeEdit_DureeMAJ->time().toString("HH:mm");
    Nb_poubelle=ui->spinBox_NbPoubelle_MAJ->text();

    bool test= tmpR.Modifier(ID,Matricule,Date,Nb_poubelle,Nom_Cartier,Duree,Heure);


    if  (test)
       {

    ui->tableView_Ramas ->setModel(tmpR.afficher());
        QMessageBox::information(nullptr,QObject::tr("Modifier un ramassage ")
                                 ,QObject::tr("Le ramassage  a été modifié"));


R.Remplissage(&ID,&Matricule,&Date,&Nb_poubelle,&Nom_Cartier,&Duree,&Heure);

ui->lineEdit_Matricule_Aff->setText(Matricule);

ui->lineEdit_Date_Aff->setText(Date);
ui->lineEdit_NbPoubelle_Aff->setText(Nb_poubelle);
ui->lineEdit_Duree_Aff->setText(Duree);
ui->lineEdit_NomCartier_Aff->setText(Nom_Cartier);
ui->lineEdit_HeureDebut_Aff->setText(Heure);
ui->stackedWidget_Environnement->setCurrentIndex(1);
  }





}

void MainWindow::on_comboBox_TypeRech_ZV_currentIndexChanged(int index)
{
    if(index==1)
ui->lineEdit_recherche_ZV->setPlaceholderText("Chercher par Identifiant");
   else  if(index==2)
ui->lineEdit_recherche_ZV->setPlaceholderText("Chercher par Libelle");
    else if (index==3)
        ui->lineEdit_recherche_ZV->setPlaceholderText("Chercher par Adresse");
    else if (index==4)
        ui->lineEdit_recherche_ZV->setPlaceholderText("Chercher par Aire");

}


void MainWindow::on_lineEdit_recherche_ZV_returnPressed()
{
 Zone_Verte z;
  QString ch,ch1;
    int indice=0;
  ch= ui->lineEdit_recherche_ZV->text();
      ui->lineEdit_ID_Aff_ZV->clear() ;
       ui->lineEdit_Libelle_Aff_ZV->clear();
       ui->lineEdit_Adresse_Aff_ZV->clear();
      ui->lineEdit_Aire_Aff_ZV->clear();
      ui->groupBox->setTitle("");
ch1=ui->lineEdit_recherche_ZV->placeholderText();
if(ch1=="Chercher par Identifiant")
  {
    indice=1;
 ui->tableView_ZV->setModel(tmpZV.Recherche(indice,ch));
 ui->comboBox_TypeRech_ZV->setCurrentIndex(0);
 ui->lineEdit_recherche_ZV->setPlaceholderText("Chercher ");

}
else if(ch1=="Chercher par Libelle")
{
    indice=2;
    ui->tableView_ZV->setModel(tmpZV.Recherche(indice,ch));
    ui->comboBox_TypeRech_ZV->setCurrentIndex(0);
    ui->lineEdit_recherche_ZV->setPlaceholderText("Chercher ");
}
else if(ch1=="Chercher par Adresse")
{
    indice=3;
    ui->tableView_ZV->setModel(tmpZV.Recherche(indice,ch));
    ui->comboBox_TypeRech_ZV->setCurrentIndex(0);
    ui->lineEdit_recherche_ZV->setPlaceholderText("Chercher ");
}
else if(ch1=="Chercher par Aire")
{
    indice=4;
    ui->tableView_ZV->setModel(tmpZV.Recherche(indice,ch));
    ui->comboBox_TypeRech_ZV->setCurrentIndex(0);
    ui->lineEdit_recherche_ZV->setPlaceholderText("Chercher ");
}
else if(indice==0 && ch=="")
{  //
  ui->tableView_ZV->setModel(tmpZV.afficher());
}
else if(indice==0 && ch!="")
{
    QMessageBox::critical(this,"Attention","Il faut choisire un critère de recherche");
}

}
void MainWindow::on_comboBox_TypeRech_Ramas_currentIndexChanged(int index)
{
  if(index==1)
      ui->lineEdit_recherche_R->setPlaceholderText("Chercher par Identifiant");
    else if (index==2)
            ui->lineEdit_recherche_R->setPlaceholderText("Chercher par Matricule");
       else if (index==3)
               ui->lineEdit_recherche_R->setPlaceholderText("Chercher par Date");
          else if (index==4)
                ui->lineEdit_recherche_R->setPlaceholderText("Chercher par Nombre de poubelle");
              else if (index==5)
                  ui->lineEdit_recherche_R->setPlaceholderText("Chercher par Durée");
                  else if (index==6)
                       ui->lineEdit_recherche_R->setPlaceholderText("Chercher par Heure Début");
                          else if (index==7)
                               ui->lineEdit_recherche_R->setPlaceholderText("Chercher par Nom Cartier");
}
void MainWindow::on_lineEdit_recherche_R_returnPressed()
{
    QString ch,ch1;
    int indice=0;
  ch= ui->lineEdit_recherche_R->text();

ch1=ui->lineEdit_recherche_R->placeholderText();
if(ch1=="Chercher par Identifiant")
  {
    indice=1;
    ui->tableView_Ramas->setModel(tmpR.Recherche(indice,ch));
     ui->comboBox_TypeRech_Ramas->setCurrentIndex(0);
     ui->lineEdit_recherche_R->setPlaceholderText("Chercher ");

}
else if(ch1=="Chercher par Matricule")
{
    indice=2;
    ui->tableView_Ramas->setModel(tmpR.Recherche(indice,ch));
     ui->comboBox_TypeRech_Ramas->setCurrentIndex(0);
     ui->lineEdit_recherche_R->setPlaceholderText("Chercher ");
}
else if(ch1=="Chercher par Date")
{
    indice=3;
    ui->tableView_Ramas->setModel(tmpR.Recherche(indice,ch));
     ui->comboBox_TypeRech_Ramas->setCurrentIndex(0);
     ui->lineEdit_recherche_R->setPlaceholderText("Chercher ");
}
else if(ch1=="Chercher par Nombre de poubelle")
{
    indice=4;
   ui->tableView_Ramas->setModel(tmpR.Recherche(indice,ch));
    ui->comboBox_TypeRech_Ramas->setCurrentIndex(0);
    ui->lineEdit_recherche_R->setPlaceholderText("Chercher ");
}
else if(ch1=="Chercher par Durée")
{
    indice=5;
    ui->tableView_Ramas->setModel(tmpR.Recherche(indice,ch));
     ui->comboBox_TypeRech_Ramas->setCurrentIndex(0);
     ui->lineEdit_recherche_R->setPlaceholderText("Chercher ");
}
else if(ch1=="Chercher par Heure Début")
{
    indice=6;
    ui->tableView_Ramas->setModel(tmpR.Recherche(indice,ch));
     ui->comboBox_TypeRech_Ramas->setCurrentIndex(0);
     ui->lineEdit_recherche_R->setPlaceholderText("Chercher ");
}
else if(ch1=="Chercher par Nom Cartier")
{
    indice=7;
    ui->tableView_Ramas->setModel(tmpR.Recherche(indice,ch));
     ui->comboBox_TypeRech_Ramas->setCurrentIndex(0);
     ui->lineEdit_recherche_R->setPlaceholderText("Chercher ");
}
else if(indice==0 && ch=="")
{
ui->tableView_Ramas->setModel(tmpR.afficher());
}
else if(indice==0 && ch!="")
{
    QMessageBox::critical(this,"Attention","Il faut choisire un critère de recherche");
}





ui->lineEdit_ID_Ramas_Aff->clear();
ui->lineEdit_Matricule_Aff->clear();
ui->lineEdit_IDChauffeur_Aff->clear();
ui->lineEdit_IDEmploye1_Aff->clear();
ui->lineEdit_IDEmploye2_Aff->clear();
ui->lineEdit_Date_Aff->clear();
ui->lineEdit_NbPoubelle_Aff->clear();
ui->lineEdit_Duree_Aff->clear();
ui->lineEdit_NomCartier_Aff->clear();
ui->lineEdit_HeureDebut_Aff->clear();
ui->groupBox_2->setTitle("");

}



void MainWindow::on_pushButton_StatR_clicked()
{

   ui->stackedWidget_Environnement->setCurrentIndex(7);
   ui->graphicsView->show();
 ui->tableView_StatR->hide();

 QChart *chart = new QChart;
   QBarSeries *series = new QBarSeries();

  chart->addSeries(series);
  QBarCategoryAxis *axis= new QBarCategoryAxis();
chart->createDefaultAxes();

  chart->setAxisX(axis,series);
    ui->graphicsView->setChart(chart);
        ui->graphicsView->setRenderHint(QPainter::Antialiasing);
        ui->graphicsView->setMinimumSize(800,550);

/*****************************************************************************/

}




void MainWindow::on_pushButton_Menu_Environ_Aff_2_clicked()
{
        ui->stackedWidget_Environnement->setCurrentIndex(0);


}



void MainWindow::on_pushButton_Print_clicked()
{
    if(!ui->groupBox_2->title().isEmpty())
    {ui->stackedWidget_Environnement->setCurrentIndex(8);
            ui->lineEdit_Date_Imp->setText(ui->lineEdit_Date_Aff->text());
             ui->lineEdit_Duree_Imp->setText(ui->lineEdit_Duree_Aff->text());
            ui->lineEdit_IDChauffeur_Imp->setText(ui->lineEdit_IDChauffeur_Aff->text());
            ui->lineEdit_IDEmploye1_Imp->setText(ui->lineEdit_IDEmploye1_Aff->text());
             ui->lineEdit_IDEmploye2_Imp->setText(ui->lineEdit_IDEmploye2_Aff->text());
              ui->lineEdit_ID_Ramas_Imp->setText(ui->lineEdit_ID_Ramas_Aff->text());
               ui->lineEdit_NomCartier_Imp->setText(ui->lineEdit_NomCartier_Aff->text());
                ui->lineEdit_NbPoubelle_Imp->setText(ui->lineEdit_NbPoubelle_Aff->text());
                 ui->lineEdit_HeureDebut_Imp->setText(ui->lineEdit_HeureDebut_Aff->text());
                  ui->lineEdit_Matricule_Imp->setText(ui->lineEdit_Matricule_Aff->text());
    }
    else QMessageBox::critical(this,"Attention","Vous devez choisire un ramassage à imprimer");
}







void MainWindow::on_pushButton_Imprimer_clicked()
{

    Ramassage R;
        QString ID=ui->lineEdit_ID_Ramas_Imp->text();

        QPrinter printer(QPrinter::HighResolution);

        printer.setCopyCount(1);


            QPrintDialog *dialog = new QPrintDialog(&printer, this);

            dialog->setWindowTitle(tr("Print Document"));
             dialog->addEnabledOption(QAbstractPrintDialog::PrintSelection);


                QPainter painter;

     painter.begin(&printer);


    QFile file;
    QDir::setCurrent("/tmp");
    file.setFileName("back2.jpg");
    QDir::setCurrent("C:/Users/Bader Semah/Desktop/Smart_Municipality_2A3");
    file.open(QIODevice::ReadOnly);
    QImage img(file.fileName());
    painter.drawImage(0,0,img.scaled(4958,7017, Qt::IgnoreAspectRatio, Qt::FastTransformation));


    QFile file2;
    QDir::setCurrent("/tmp");
    file2.setFileName("municipal.png");
    QDir::setCurrent("C:/Users/Bader Semah/Desktop/Smart_Municipality_2A3");
    file2.open(QIODevice::ReadOnly);
    QImage img2(file2.fileName());
    painter.drawImage(0,0,img2.scaled(900,1000, Qt::IgnoreAspectRatio, Qt::FastTransformation));



    QString Matricule,Id_chauffeur,id_empl1,id_empl2,Date,Nb_poubelle,Nom_Cartier,Duree,Heure;
    Id_chauffeur=ui->lineEdit_IDChauffeur_Imp->text();
    id_empl1=ui->lineEdit_IDEmploye1_Imp->text();
    id_empl2=ui->lineEdit_IDEmploye2_Imp->text();
    R.Remplissage(&ID,&Matricule,&Date,&Nb_poubelle,&Nom_Cartier,&Duree,&Heure);

     painter.setFont(QFont("Harlow Solid Italic",30,-1,1));
      painter.setPen(QColor(0,102,204));
    painter.drawText(width()+100,height()+600,"Ramassage d'identifiant "+ID+"" );
     painter.setFont(QFont("Berlin Sans FB Demi Bold",15));
       painter.setPen(QColor(0,0,0));
    painter.drawText(width()-500,height()+1600,"Matricule du camion:  "+Matricule+"" );
    painter.drawText(width()-500,height()+2100,"Nom du cartier:  "+Nom_Cartier+"" );
    painter.drawText(width()-500,height()+2600,"Date:  "+Date+"" );
    painter.drawText(width()-500,height()+3100,"Heure début:  "+Heure+"" );
    painter.drawText(width()-500,height()+3600,"Durée:  "+Duree+"" );

    painter.drawText(width()-500,height()+4100,"CIN des employés:  "+Id_chauffeur+" , "+id_empl1+" , "+id_empl2+"" );
    painter.drawText(width()-500,height()+4600,"Nombres de poubelles à ramasser:  "+Nb_poubelle+"" );




                painter.end();

}



void MainWindow::on_pushButton_Menu_Environ_Aff_3_clicked()
{
          ui->stackedWidget_Environnement->setCurrentIndex(0);
}




void MainWindow::update_label()
{int val;
    data=C.read_from_capteur_humidite();
qDebug()<<"Entrain de mesurer l'humidité de cette zone verte";
    val=data.toInt();
     qDebug()<<data.toInt();
    if(data.toInt()>=600)
      {
        qDebug()<<"Sèche";
          ui->Notif_irrigation->show();
            ui->tableView_ZV->setStyleSheet(" selection-background-color: red ");
            QMediaPlayer *player = new QMediaPlayer;
            player->setMedia(QUrl::fromLocalFile("C:/Users/Bader Semah/Desktop/Smart_Municipality_2A3/Alarm.mp3"));
            player->setVolume(30);
            player->play();
            C.write_to_arduino(data);

      }
        else if(data.toInt()>100&&data.toInt()<600)
    {
        qDebug()<<"Humide";
           ui->Notif_irrigation->hide();
            ui->tableView_ZV->setStyleSheet(" selection-background-color: green  ");
    }

}








void MainWindow::on_Date_Stat_dateChanged(const QDate &date)
{


QBarSet *set0 = new QBarSet("ramassage");

QString ch1,ch2,ch3;
QStringList list1;
ch1=date.toString("MM/yyyy");
        QStringList list, list2;

        Ramassage R;

 ui->tableView_StatR->show();

     ui->tableView_StatR->setModel(tmpR.afficherSTAT(ch1,ch2));


          ui->tableView_StatR->adjustSize();

QVector<Ramassage> tab;


        for( int row = 0; row < ui->tableView_StatR->model()->rowCount(); ++row )
               {   ui->tableWidget->setColumnCount(3);
           ui->tableWidget->insertRow(ui->tableWidget->rowCount());
         for( int col = 0; col < ui->tableView_StatR->model()->columnCount(); ++col )
                 {
                  QModelIndex index =ui->tableView_StatR->model()->index(row,0);
                   QModelIndex index2 =ui->tableView_StatR->model()->index(row,1);
                    QModelIndex index3 =ui->tableView_StatR->model()->index(row,2);
                    list1.append(index.data().toString());
                   R.setId_Ramassage(index.data().toString());
                   R.setNb_Poubelle(index2.data().toString());
                   R.setDate(index3.data().toString());
        ui->tableWidget->hide();
                }
          tab.push_back(R);

        }


        for(int m=0;m<tab.size();m++)
       {
            for(int index=0;index<tab.size();index++)

     {
       if(tab[index].getDate()==tab[m].getDate()&& m!=index)

       {

           tab[index].setId_Ramassage("");
              int x=tab[m].getNbPoubelle().toInt()+tab[index].getNbPoubelle().toInt();
               QString ch=QVariant(x).toString();
               tab[m].setNb_Poubelle(ch);

         }

       }




       for(int k=0;k<tab.size();k++)

        list.append(tab[k].getDate());

       if(tab[m].getId_Ramassage()!="")
       {

    *set0<<tab[m].getNbPoubelle().toInt();


        }
        }



          ui->stackedWidget_Environnement->setCurrentIndex(7);
                QBarSeries *series = new QBarSeries();
                     series->append(set0);

                    QChart *chart = new QChart;
                     chart->addSeries(series);
                     chart->setTitle("Le nombre de ramassages effectués par la municipalité en '"+ch1+"'");
    QFont serifFont("Segoe Print", 15, QFont::Bold);
                     chart->setTitleFont(serifFont);
                chart->setAnimationOptions(QChart::AllAnimations);

                QBarCategoryAxis *axis= new QBarCategoryAxis();
                axis->append(list);

                chart->createDefaultAxes();

                chart->setAxisX(axis,series);
                chart->legend()->setVisible(true);
                chart->legend()->setAlignment(Qt::AlignBottom);
                QPalette pal =  ui->graphicsView->palette();
                pal.setColor(QPalette::Window, QRgb(0x121218));
                pal.setColor(QPalette::WindowText, QRgb(0xd6d6d6));

       ui->graphicsView->show();

     ui->graphicsView->setPalette(pal);
            ui->graphicsView->setChart(chart);
            ui->graphicsView->setRenderHint(QPainter::Antialiasing);
            ui->graphicsView->setMinimumSize(800,550);
}
void MainWindow::on_pushButton_Irrigat_clicked()
{
     ui->stackedWidget_Environnement->setCurrentIndex(9);
}
void MainWindow::on_pushButton_Menu_Environ_Aff_ZV_2_clicked()
{
    ui->stackedWidget_Environnement->setCurrentIndex(0);
}


void MainWindow::on_comboBox_Type_Tri_activated(int index)
{
          ui->tableView_Ramas->setModel(tmpR.Tri(index));
          if(index==0)
               {
           ui->tableView_Ramas->setModel(tmpR.afficher());
           ui->tri_ramassage->hide();
          }
          if(index==1)
               {
           ui->tableView_Ramas->setModel(tmpR.afficher());
           ui->tri_ramassage->hide();
          }
          else if(index==2)
         { ui->tri_ramassage->show();
              ui->tri_ramassage->setText("Les ramassages triés selon \nle nom de cartier");

          }
          else if(index==3)
          { ui->tri_ramassage->show();
               ui->tri_ramassage->setText("Les ramassages triés selon \nle nombre de ramassage");

           }
          else if(index==4)
          { ui->tri_ramassage->show();
               ui->tri_ramassage->setText("Les ramassages triés selon \nla date");

           }
           ui->comboBox_Type_Tri->setCurrentIndex(0);
}


/**************** Déplacement entre les modules pour le  Module Environnement *****************************************/
void MainWindow::on_pushButton_MP_Envi_clicked()
{
ui->stackedWidget_Main->setCurrentIndex(0);
}
void MainWindow::on_pushButton_MP_Envi_pressed()
{
    QMediaPlayer *player = new QMediaPlayer;
        player->setMedia(QUrl::fromLocalFile("C:/Users/Bader Semah/Desktop/Smart_Municipality_2A3/Click2.mp3"));
        player->setVolume(50);
        player->play();
        QPropertyAnimation *animation= new QPropertyAnimation(ui->pushButton_MP_Envi,"geometry");
             animation->setDuration(2000);
             animation->setStartValue(QRect(20,10, 171,41));
             animation->setEndValue(QRect(60,10,171,41));

             animation->start();

             QPropertyAnimation *animation2= new QPropertyAnimation(ui->pushButton_MP_Envi,"geometry");
                  animation2->setDuration(1000);
                  animation2->setStartValue(QRect(60,10, 171,41));
                  animation2->setEndValue(QRect(20,10,171,41));
                     animation2->start();
                     animation2->destroyed() ;
                       animation->destroyed() ;
}

void MainWindow::on_pushButton_Marche_Envi_clicked()
{
    ui->stackedWidget_Main->setCurrentIndex(5);
    ui->stackedWidget_2->setCurrentIndex(0);
}

void MainWindow::on_pushButton_Marche_Envi_pressed()
{
    QMediaPlayer *player = new QMediaPlayer;
        player->setMedia(QUrl::fromLocalFile("C:/Users/Bader Semah/Desktop/Smart_Municipality_2A3/Click2.mp3"));
        player->setVolume(50);
        player->play();
        QPropertyAnimation *animation= new QPropertyAnimation(ui->pushButton_Marche_Envi,"geometry");
             animation->setDuration(2000);
             animation->setStartValue(QRect(20,90, 171,41));
             animation->setEndValue(QRect(60,90,171,41));

             animation->start();

             QPropertyAnimation *animation2= new QPropertyAnimation(ui->pushButton_Marche_Envi,"geometry");
                  animation2->setDuration(1000);
                  animation2->setStartValue(QRect(60,90, 171,41));
                  animation2->setEndValue(QRect(20,90,171,41));
                     animation2->start();
                     animation->destroyed() ;
                     animation2->destroyed() ;
}

void MainWindow::on_pushButton_RH_Envi_clicked()
{
    ui->stackedWidget_Main->setCurrentIndex(1);
    ui->stackedWidget_resources_humaines->setCurrentIndex(1);
}

void MainWindow::on_pushButton_RH_Envi_pressed()
{
    QMediaPlayer *player = new QMediaPlayer;
        player->setMedia(QUrl::fromLocalFile("C:/Users/Bader Semah/Desktop/Smart_Municipality_2A3/Click2.mp3"));
        player->setVolume(50);
        player->play();
        QPropertyAnimation *animation= new QPropertyAnimation(ui->pushButton_RH_Envi,"geometry");
             animation->setDuration(2000);
             animation->setStartValue(QRect(20,170, 171,41));
             animation->setEndValue(QRect(60,170,171,41));

             animation->start();

             QPropertyAnimation *animation2= new QPropertyAnimation(ui->pushButton_RH_Envi,"geometry");
                  animation2->setDuration(1000);
                  animation2->setStartValue(QRect(60,170, 171,41));
                  animation2->setEndValue(QRect(20,170,171,41));
                     animation2->start();
                     animation2->destroyed() ;
                       animation->destroyed() ;
}
void MainWindow::on_pushButton_Maintenance_Envi_clicked()
{
ui->stackedWidget_Main->setCurrentIndex(4);
ui->stackedWidgetMaintennance->setCurrentIndex(1);
}

void MainWindow::on_pushButton_Maintenance_Envi_pressed()
{
    QMediaPlayer *player = new QMediaPlayer;
        player->setMedia(QUrl::fromLocalFile("C:/Users/Bader Semah/Desktop/Smart_Municipality_2A3/Click2.mp3"));
        player->setVolume(50);
        player->play();
        QPropertyAnimation *animation= new QPropertyAnimation(ui->pushButton_Maintenance_Envi,"geometry");
             animation->setDuration(2000);
             animation->setStartValue(QRect(20,250, 171,41));
             animation->setEndValue(QRect(60,250,171,41));

             animation->start();

             QPropertyAnimation *animation2= new QPropertyAnimation(ui->pushButton_Maintenance_Envi,"geometry");
                  animation2->setDuration(1000);
                  animation2->setStartValue(QRect(60,250, 171,41));
                  animation2->setEndValue(QRect(20,250,171,41));
                     animation2->start();
                     animation2->destroyed() ;
                       animation->destroyed() ;
}

void MainWindow::on_communication_Envi_clicked()
{
        ui->stackedWidget_Main->setCurrentIndex(3);
         ui->stackedWidget->setCurrentIndex(0);
}
void MainWindow::on_communication_Envi_pressed()
{
    QMediaPlayer *player = new QMediaPlayer;
        player->setMedia(QUrl::fromLocalFile("C:/Users/Bader Semah/Desktop/Smart_Municipality_2A3/Click2.mp3"));
        player->setVolume(50);
        player->play();
        QPropertyAnimation *animation= new QPropertyAnimation(ui->communication_Envi,"geometry");
             animation->setDuration(2000);
             animation->setStartValue(QRect(20,330, 171,41));
             animation->setEndValue(QRect(60,330,171,41));

             animation->start();

             QPropertyAnimation *animation2= new QPropertyAnimation(ui->communication_Envi,"geometry");
                  animation2->setDuration(1000);
                  animation2->setStartValue(QRect(60,330, 171,41));
                  animation2->setEndValue(QRect(20,330,171,41));
                     animation2->start();
                     animation2->destroyed() ;
                       animation->destroyed() ;
}

/**************** Fin Déplacement entre les modules pour le  Module Environnement *****************************************/



/************************************** End Rima ***************************************************/
/*****************************************************************************************************/

/************************************Begin Nardine*********************************************/
void MainWindow::on_pushButton_event_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->tableView_event->setModel(Etmp.afficher());
    if(aud==1)
     {
        ui->pushButtonajoutcit->setDisabled(true);
    }
}

void MainWindow::on_pushButton_etat_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
    ui->tableView_citoyen->setModel(Ctmp.afficher());
    if(aud==1)
     {
        ui->ajouter_cit->setDisabled(true);
        ui->pushButton_maj_cit->setDisabled(true);
        ui->pushButton_del_cit->setDisabled(true);
    }
}



void MainWindow::on_pushButtonajoutcit_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_save_clicked() /*************************************AJOUT EVENT**********************************/
{

    //recupération des information saisies
    QString id= ui->input_id->text();
    QString nom= ui->input_nom->text();
    QString type= ui->input_type->text();
    QString date= ui->input_date->text();
    QString hor= ui->input_hor->text();
    QString empl= ui->input_empl->text();
    QString etat= ui->input_etat->currentText();
    Evenement E(id,nom,type,date,hor,empl,etat); //instancier un objet de la classe citoyen
    bool controle=E.controle();
    if(controle)
    {
        bool test=E.ajouter(); //insertion de citoyen dans la table
        if (test)
        {
            QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("ajout effectuée \n click cancel to exit"),QMessageBox::Cancel);
            ui->tableView_event->setModel(Etmp.afficher());  //actualisation de la liste
            ui->stackedWidget->setCurrentIndex(1);
        }
    }
    else
    {
        QMessageBox::information(nullptr,QObject::tr("not ok"),QObject::tr("ajout non effectuée \n click cancel to exit"),QMessageBox::Cancel);
    }
}

void MainWindow::on_pushButton_cancel_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


/*void MainWindow::on_tri_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}
*/
void MainWindow::on_pushButton_maj_event_clicked()/********************************AFFICHAGE UPDATE EVENT************************************/
{
    QString ID= ui->out_id->text();
    QSqlQuery query=Etmp.select(ID);

    if(query.exec())
    {
        while(query.next())
        {
            ui->maj_id->setText(query.value(0).toString());
            ui->maj_nom->setText(query.value(1).toString());
            ui->maj_type->setText(query.value(2).toString());
            ui->maj_date->setText(query.value(3).toString());
            ui->maj_hor->setText(query.value(4).toString());
            ui->maj_empl->setText(query.value(5).toString());
            ui->maj_etat->setText(query.value(6).toString());
        }
        ui->stackedWidget->setCurrentIndex(4);
    }

}

void MainWindow::on_pushButton_del_event_clicked() /********************************DELETE EVENT********************************/
{
    QString id=ui->out_id->text();
    bool test=Etmp.supprimer(id);
    if(test)
    {
        QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("suppression effectuée \n click cancel to exit"),QMessageBox::Cancel);
        ui->tableView_event->setModel(Etmp.afficher());  //actualisation de la liste

        ui->stackedWidget->setCurrentIndex(1);
    }
    else
    {
        QMessageBox::information(nullptr,QObject::tr("not ok"),QObject::tr("suppression non effectuée \n click cancel to exit"),QMessageBox::Cancel);

    }

}

void MainWindow::on_maj_save_clicked()/****************************SAVE UPDATE EVENT CLICKED***********************************/
{
    QString id= ui->maj_id->text();
    QString nom= ui->maj_nom->text();
    QString type= ui->maj_type->text();
    QString date= ui->maj_date->text();
    QString hor= ui->maj_hor->text();
    QString empl= ui->maj_empl->text();
    QString etat= ui->maj_etat->text();
    Evenement E(id,nom,type,date,hor,empl,etat);
    E.maj(ID);
    ui->stackedWidget->setCurrentIndex(1);
    ui->tableView_event->setModel(Etmp.afficher());

}

void MainWindow::on_maj_cancel_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}
/****************************************************CITOYENS*****************************************************/
void MainWindow::on_ajouter_cit_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_Menu_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_recherche_clicked() /*******************************RECHERCHE CITOYEN**********************************/
{
    QString nom = ui->input_recherche->text();
    if(nom=="")
    {
        ui->tableView_citoyen->setModel(Ctmp.afficher());
    }
    else
    {
        if( ui->rech_id->isChecked())
        {
            ui->tableView_citoyen->setModel(Ctmp.recherche_id(nom));
        }
        if( ui->rech_nom->isChecked())
        {
            ui->tableView_citoyen->setModel(Ctmp.recherche_nom(nom));
        }
        if( ui->rech_prenom->isChecked())
        {
            ui->tableView_citoyen->setModel(Ctmp.recherche_prenom(nom));
        }
    }
    //ui->tableView_citoyen->setModel(Ctmp.recherche(nom));
    // ui->tableView_citoyen->setModel(Ctmp.trier());
}

void MainWindow::on_rech_nom_stateChanged(int arg1)
{
    if(ui->rech_nom->isChecked())
    {
    ui->rech_id->setDisabled(true);
    ui->rech_prenom->setDisabled(true);
    }
    else
    {
        ui->rech_id->setDisabled(false);
        ui->rech_prenom->setDisabled(false);

    }
}


void MainWindow::on_rech_prenom_stateChanged(int arg1)
{
    if(ui->rech_prenom->isChecked())
    {
    ui->rech_id->setDisabled(true);
    ui->rech_nom->setDisabled(true);
    }
    else
    {
        ui->rech_id->setDisabled(false);
        ui->rech_nom->setDisabled(false);

    }
}


void MainWindow::on_rech_id_stateChanged(int arg1)
{
    if(ui->rech_id->isChecked())
    {
    ui->rech_nom->setDisabled(true);
    ui->rech_prenom->setDisabled(true);
    }
    else
    {
        ui->rech_nom->setDisabled(false);
        ui->rech_prenom->setDisabled(false);

    }
}
void MainWindow::on_pushButton_save_2_clicked()/********************************SAVE AJOUT CITOYEN***************************************/
{
    //recupération des information saisies
    QString id= ui->input_id_2->text();
    QString nom= ui->input_nom_2->text();
    QString prenom= ui->input_prenom->text();
    QString sexe= ui->input_sexe->currentText();
    QString date= ui->input_naissance->text();
    QString lieu= ui->input_lieu->text();
    QString mail= ui->input_mail->text();
    QString tel= ui->input_tel->text();
    Citoyen C(id,nom,prenom,sexe,date,lieu,mail,tel); //instancier un objet de la classe citoyen
    bool controle=C.controle();
    if(controle)
    {
        bool test=C.ajouter(); //insertion de citoyen dans la table

        if (test)
        {    QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("ajout effectuée \n click cancel to exit"),QMessageBox::Cancel);
            ui->tableView_citoyen->setModel(Ctmp.afficher());  //actualisation de la liste
            ui->stackedWidget->setCurrentIndex(5);
        }
    }
    else   {
        QMessageBox::information(nullptr,QObject::tr("not ok"),QObject::tr("ajout non effectuée \n click cancel to exit"),QMessageBox::Cancel);
    }
}

void MainWindow::on_pushButton_cancel_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}


void MainWindow::on_pushButton_impression_clicked() /*******************************PDF CLICKED***********************************/
{
    QString id,nom,prenom,sexe,date,lieu,mail,tel;
    QSqlQuery query=Ctmp.select(ID);
    if(query.exec())
    {
        while(query.next())
        {
            id= query.value(0).toString();
            nom= query.value(1).toString();
            prenom= query.value(2).toString();
            sexe= query.value(3).toString();
            date= query.value(4).toString();
            lieu= query.value(5).toString();
            mail= query.value(6).toString();
            tel= query.value(7).toString();
        }
        num++;
        Citoyen C(id,nom,prenom,sexe,date,lieu,mail,tel);
        C.printPDF(num);
    }

}

void MainWindow::on_pushButton_maj_cit_clicked() /*******************AFFICHAGE UPDATE CITOYEN***********************************/
{
    QString ID= ui->out_id_2->text();

    QSqlQuery query=Ctmp.select(ID);
    if(query.exec())
    {
        while(query.next())
        {
            ui->maj_id_2->setText(query.value(0).toString());
            ui->maj_nom_2->setText(query.value(1).toString());
            ui->maj_prenom->setText(query.value(2).toString());
            ui->maj_sexe->setText(query.value(3).toString());
            ui->maj_date_cit->setText(query.value(4).toString());
            ui->maj_lieu->setText(query.value(5).toString());
            ui->maj_mail->setText(query.value(6).toString());
            ui->maj_tel->setText(query.value(7).toString());

        }
        ui->stackedWidget->setCurrentIndex(8);

    }
}

void MainWindow::on_pushButton_del_cit_clicked()/********************************DELETE CITOYEN**************************************/
{
    QString id=ui->out_id_2->text();
    bool test=Ctmp.supprimer(id);
    if(test)
    {
        QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("suppression effectuée \n click cancel to exit"),QMessageBox::Cancel);
        ui->tableView_citoyen->setModel(Ctmp.afficher());  //actualisation de la liste
        ui->stackedWidget->setCurrentIndex(5);
    }
    else
    {
        QMessageBox::information(nullptr,QObject::tr("not ok"),QObject::tr("suppression non effectuée \n click cancel to exit"),QMessageBox::Cancel);

    }
}


void MainWindow::on_majcit_cancel_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_maj_save_2_clicked() /*********************************SAVE UPDATE CITOYEN****************************************/
{

    //recupération des données modifiées
    QString id= ui->maj_id_2->text();
    QString nom= ui->maj_nom_2->text();
    QString prenom= ui->maj_prenom->text();
    QString sexe= ui->maj_sexe->text();
    QString date= ui->maj_date_cit->text();
    QString lieu= ui->maj_lieu->text();
    QString mail= ui->maj_mail->text();
    QString tel= ui->maj_tel->text();
    Citoyen C(id,nom,prenom,sexe,date,lieu,mail,tel);
    C.maj(ID);
    ui->stackedWidget->setCurrentIndex(5);
    ui->tableView_citoyen->setModel(Ctmp.afficher());

}

void MainWindow::on_maj_cancel_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::on_Menu_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}



void MainWindow::on_tableView_citoyen_activated(const QModelIndex &index) /***********************AFFICHAGE UN CITOYEN ****************************/
{
    QString Id=ui->tableView_citoyen->model()->data(index).toString();
    ID=Id;
    QSqlQuery query=Ctmp.select(ID);
    if(query.exec())
    {
        while(query.next())
        {
            ui->out_id_2->setText(query.value(0).toString());
            ui->out_nom_2->setText(query.value(1).toString());
            ui->out_prenom->setText(query.value(2).toString());
            ui->out_sexe->setText(query.value(3).toString());
            ui->out_naissance->setText(query.value(4).toString());
            ui->out_lieu->setText(query.value(5).toString());
            ui->out_mail->setText(query.value(6).toString());
            ui->out_tel->setText(query.value(7).toString());

        }
        ui->stackedWidget->setCurrentIndex(7);
    }
    else
    {
        QMessageBox::information(nullptr,QObject::tr("not ok"),QObject::tr("citoyen non existant \n click cancel to exit"),QMessageBox::Cancel);
    }
}

void MainWindow::on_tableView_event_activated(const QModelIndex &index)/*****************************AFFICHAGE D'UN EVENT***************************/
{
    QString id=ui->tableView_event->model()->data(index).toString();
    ID=id;
    if(aud==1)
     {
        ui->pushButton_del_event->setDisabled(true);
        ui->pushButton_maj_event->setDisabled(true);
    }
    QSqlQuery query=Etmp.select(ID);
    if(query.exec())
    {
        while(query.next())
        {
            ui->out_id->setText(query.value(0).toString());
            ui->out_nom->setText(query.value(1).toString());
            ui->out_type->setText(query.value(2).toString());
            ui->out_date->setText(query.value(3).toString());
            ui->out_hor->setText(query.value(4).toString());
            ui->out_empl->setText(query.value(5).toString());
            ui->out_etat->setText(query.value(6).toString());

        }
        ui->stackedWidget->setCurrentIndex(3);
    }
    else
    {
        QMessageBox::information(nullptr,QObject::tr("not ok"),QObject::tr("evenement non existant \n click cancel to exit"),QMessageBox::Cancel);
    }
}

void MainWindow::on_exit_clicked()/***********************************CLOSE ALL CLICKED**************************************/
{
    close();
}

void MainWindow::on_pushButton_stat_clicked()/************************AFFICHAGE STATISTIQUES***************************/
{
    //statistiques
    //statistiques();
        Evenement E;
        QChartView * chartView=new QChartView(E.stat());
        chartView ->setParent(ui->frame);
        chartView->setFixedSize(ui->frame->size());
        ui->stackedWidget->setCurrentIndex(9);
}

void MainWindow::on_tri_clicked()/*****************************TRIER LES EVENTS**********************************/
{
    QString type= ui->input_tri->currentText();
    int tri=0;
    if(type=="TYPE")
    {
        tri=1;
    }
    else if(type=="ETAT")
    {
        tri=2;
    }
    else tri=3;

    ui->tableView_event->setModel(Etmp.trier(tri));
}
//******************************************************************************
void MainWindow::statistiques()
{
     QPieSeries *series = new QPieSeries();
     int nbpasse= Etmp.passe();
     int nbattente =Etmp.attente();
     int nbannule= Etmp.annule();
        series->append("Passé",nbpasse);
        series->append("En attente",nbattente);
        series->append("Annulé",nbannule);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Nombre d'evenements selon l'état");

    QChartView *chartview = new QChartView(chart);
    chartview->setParent(ui->frame);

}

void MainWindow::on_stat_cancel_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}
void MainWindow::on_annuler_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_close_clicked()
{
    close();
}

void MainWindow::on_mailing_clicked()
{
    ui->stackedWidget->setCurrentIndex(10);
}

void MainWindow::on_send_clicked()
{
    smtp = new Smtp("projetqt2021@gmail.com" , "projet123456", "smtp.gmail.com",465);

    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

    msg=ui->corps->toPlainText();
   QString mail="nardine.hanfi@esprit.tn" ;
    qDebug()<<mail;
    smtp->sendMail("projetqt2021@gmail.com",mail,ui->objet->text(),msg);
}

void MainWindow::on_back_mail_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

/*****************deplacement entre les modules:: module communication*************************************/
void MainWindow::on_MenuP_clicked()
{
    ui->stackedWidget_Main->setCurrentIndex(0);
}

void MainWindow::on_envi_clicked()
{
     ui->stackedWidget_Main->setCurrentIndex(2);
}
void MainWindow::on_res_clicked()
{
    ui->stackedWidget_Main->setCurrentIndex(1);
}
void MainWindow::on_maintenance_clicked()
{
    ui->stackedWidget_Main->setCurrentIndex(4);
}

void MainWindow::on_marche_clicked()
{
    ui->stackedWidget_Main->setCurrentIndex(5);
    ui->stackedWidget_2->setCurrentIndex(0);
}




/******************************fin deplacement entre module:: module communication****************************/
/**************************************End Nardine**************************************************************/




/********************************************** Begin Semah *******************************************/


void MainWindow::update_btn()
{ qDebug()<<"semah !";
    data=C.read_from_capteur_humidite();


    qDebug()<<"Data ************ :"<<data;

    if(data == "1"){
        QString TYPE =  "canal d'eau";
        QString ID_COMP = "12";
        QString ROUTE = "Ghazela";
        QString NATURE = "Urgente";
        QString DATE =QDate::currentDate().toString();


        Reclamation R(ROUTE,TYPE,DATE,NATURE,ID_COMP);

        if(1)
       {

            QMessageBox msgBox;
            msgBox.setText(tr("ALERT !.\n Type de Composant : %1 \n Nom de route : %2 \n ID_Composant : %3 \n ")
                           .arg(TYPE)
                           .arg(ROUTE)
                           .arg(ID_COMP)
                           );
            QAbstractButton* pButtonYes = msgBox.addButton(tr("Reclamer!"), QMessageBox::YesRole);
            msgBox.exec();

            if (msgBox.clickedButton()==pButtonYes) {

               R.AjouterReclamation();
            }


       }
         else
           {  QMessageBox::critical(nullptr, QObject::tr("Ajouter"),
                         QObject::tr("Erreur !.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);

       }


        qDebug("coloooorrr");

    }
}
















void MainWindow::on_pushButton_MaintenanceIN_clicked()
{
    ui->stackedWidget_Main->setCurrentIndex(4);
    ui->stackedWidgetMaintennance->setCurrentIndex(1);

}



void MainWindow::on_pushButton_backMaintenance_3_clicked()
{

}
void MainWindow::on_pushButton_Ress_BackBTN_clicked()
{
    ui->stackedWidgetMaintennance->setCurrentIndex(1);

}

void MainWindow::on_pushButton_backMaintenance_4_clicked()
{
    qDebug("fdsfdsfsdf");

    ui->stackedWidgetMaintennance->setCurrentIndex(1);

}

//////////Maintenance

void MainWindow::on_pushButton_Ressource_Materiel_2_clicked()
{
    RessourceMateriel R ;

    QMediaPlayer *Maintenancesound = new QMediaPlayer;
        Maintenancesound->setMedia(QUrl::fromLocalFile("C:/Users/Bader Semah/Desktop/2eme/Nouveau dossier/Smart_Municipality_2A3/Maintenance_click_soundd.mp3"));
        Maintenancesound->setVolume(100);
        Maintenancesound->play();

    ui->tableView_Ressources_2->setModel( R.AfficherComposant());

    if(aud==1)
     {
        ui->pushButton_AjouterComposant_2->setDisabled(true);
    }
    ////// edit delete buttons
    ///
    ///

    for (int i = 0; i< R.AfficherComposant()->rowCount(); i++)
       {
       // QPushButton *DELETE = new QPushButton(" DELETE");
        QPushButton *DELT = new QPushButton(" DELETE");
          QPushButton *EDIT = new QPushButton(" CHANGER ETAT");

          DELT->setStyleSheet("background-color : red;color : white ");

          EDIT->setStyleSheet("background-color : green;color : white ");



          ui->tableView_Ressources_2->setIndexWidget(ui->tableView_Ressources_2->model()->index(i, 5), EDIT);
           ui->tableView_Ressources_2->setIndexWidget(ui->tableView_Ressources_2->model()->index(i, 6), DELT);


           QSignalMapper *signalMapper = new QSignalMapper(this);
               connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(DeleteSlotRessource(int)));
                   connect(DELT, SIGNAL(clicked()), signalMapper, SLOT(map()));
                   signalMapper->setMapping(DELT, i);

                   QSignalMapper *signalMapper1 = new QSignalMapper(this);
                       connect(signalMapper1, SIGNAL(mapped(int)), this, SLOT(ModifierSlotRessource(int)));
                           connect(EDIT, SIGNAL(clicked()), signalMapper1, SLOT(map()));
                           signalMapper1->setMapping(EDIT, i);

                           if(aud==1)
                            {
                               DELT->setDisabled(true);
                               EDIT->setDisabled(true);
                               DELT->setStyleSheet("background-color : gray;color : white ");

                               EDIT->setStyleSheet("background-color : gray;color : white ");
                           }
        }
    ////

    ui->stackedWidgetMaintennance->setCurrentIndex(2);


}

void MainWindow::on_pushButton_AnnulerSauvgarderCoomposant_2_clicked()
{
    ui->stackedWidgetMaintennance->setCurrentIndex(2);

}


void MainWindow::on_pushButton_SauvgarderComposant_2_clicked()
{

   qDebug("bouton: « ajouterPersonne » appuyé");



   QString TYPE = ui->comboBox_typeComp_2->currentText();
   QString ETAT = ui->comboBox_EtatComp_2->currentText();
   QString ROUTE = ui->comboBox_NomrouteComp_2->currentText();
   double POSX=ui->doubleSpinBox_XComp_2->value();
   double POSY=ui->doubleSpinBox_YComp_2->value();

   RessourceMateriel R(TYPE,ETAT,ROUTE,POSX,POSY);

   bool test = R.AjouterComposant();

   if(test)
  {

  QMessageBox::information(nullptr, QObject::tr("Ajouter "),
                    QObject::tr(" ajouté.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

  ui->stackedWidgetMaintennance->setCurrentIndex(2);


  }
    else
      {  QMessageBox::critical(nullptr, QObject::tr("Ajouter"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

  }



   ui->tableView_Ressources_2->setModel( R.AfficherComposant());

   ////// edit delete buttons
   ///
   ///

    for (int i = 0; i< R.AfficherComposant()->rowCount(); i++)
      {
        QPushButton *EDIT = new QPushButton(" CHANGER ETAT");
         QPushButton *DELT = new QPushButton("DELETE");

         DELT->setStyleSheet("background-color : red;color : white  ");

         EDIT->setStyleSheet("background-color : green;color : white ");

         ui->tableView_Ressources_2->setIndexWidget(ui->tableView_Ressources_2->model()->index(i, 5), EDIT);
          ui->tableView_Ressources_2->setIndexWidget(ui->tableView_Ressources_2->model()->index(i, 6), DELT);


          QSignalMapper *signalMapper = new QSignalMapper(this);
              connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(DeleteSlotRessource(int)));
                  connect(DELT, SIGNAL(clicked()), signalMapper, SLOT(map()));
                  signalMapper->setMapping(DELT, i);

                  QSignalMapper *signalMapper1 = new QSignalMapper(this);
                      connect(signalMapper1, SIGNAL(mapped(int)), this, SLOT(ModifierSlotRessource(int)));
                          connect(EDIT, SIGNAL(clicked()), signalMapper1, SLOT(map()));
                          signalMapper1->setMapping(EDIT, i);

                          if(aud==1)
                           {
                              DELT->setDisabled(true);
                              EDIT->setDisabled(true);
                              DELT->setStyleSheet("background-color : gray;color : white ");

                              EDIT->setStyleSheet("background-color : gray;color : white ");
                          }


}

   ////


    ///// init comboboxs
    ui->comboBox_EtatComp_2->setCurrentIndex(0);
    ui->comboBox_NomrouteComp_2->setCurrentIndex(0);
    ui->comboBox_NatureRecl_2->setCurrentIndex(0);
    ui->comboBox_typeComp_2->setCurrentIndex(0);
    ui->doubleSpinBox_XComp_2->setValue(0.0);
    ui->doubleSpinBox_YComp_2->setValue(0.0);


    ///

}

void MainWindow::on_pushButton_AjouterComposant_2_clicked()
{
    for (int i = 0 ; i < ui->comboBox_EtatComp_2->count() ; ++i) {
    ui->comboBox_EtatComp_2->setItemData(i, Qt::AlignCenter, Qt::TextAlignmentRole);
    }
    for (int i = 0 ; i < ui->comboBox_NomrouteComp_2->count() ; ++i) {
        ui->comboBox_NomrouteComp_2->setItemData(i, Qt::AlignCenter, Qt::TextAlignmentRole);
        }
    for (int i = 0 ; i < ui->comboBox_typeComp_2->count() ; ++i) {
        ui->comboBox_typeComp_2->setItemData(i, Qt::AlignCenter, Qt::TextAlignmentRole);
        }

    ui->stackedWidgetMaintennance->setCurrentIndex(4);

}





///////////////// reclamations
///
///
void MainWindow::on_pushButton_Reclamations_2_clicked()
{
    Reclamation R ;
    QObject::connect(C.getserial(),SIGNAL(readyRead()),this,SLOT(update_btn()));

    QMediaPlayer *Maintenancesound = new QMediaPlayer;
        Maintenancesound->setMedia(QUrl::fromLocalFile("C:/Users/Bader Semah/Desktop/2eme/Nouveau dossier/Smart_Municipality_2A3/Maintenance_click_soundd.mp3"));
        Maintenancesound->setVolume(100);
        Maintenancesound->play();

    ui->tableView_Reclamations_2->setModel( R.AfficherReclamation());

    if(aud==1)
    {
        ui->pushButton_AjouterReclamation_2->setDisabled(true);
    }

    ////// edit delete buttons
    ///
    ///
    for (int i = 0; i< R.AfficherReclamation()->rowCount(); i++)
       {
        QPushButton *EDIT = new QPushButton(" CHANGER ETAT");
          QPushButton *DELT = new QPushButton("DELETE");

          DELT->setStyleSheet("background-color : red;color : white ");

          EDIT->setStyleSheet("background-color : green;color : white ");

          ui->tableView_Reclamations_2->setIndexWidget(ui->tableView_Reclamations_2->model()->index(i, 4), EDIT);
           ui->tableView_Reclamations_2->setIndexWidget(ui->tableView_Reclamations_2->model()->index(i, 5), DELT);


           QSignalMapper *signalMapper = new QSignalMapper(this);
               connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(DeleteSlotReclamation(int)));
                   connect(DELT, SIGNAL(clicked()), signalMapper, SLOT(map()));
                   signalMapper->setMapping(DELT, i);

                   QSignalMapper *signalMapper1 = new QSignalMapper(this);
                       connect(signalMapper1, SIGNAL(mapped(int)), this, SLOT(ModifierSlotReclamation(int)));
                           connect(EDIT, SIGNAL(clicked()), signalMapper1, SLOT(map()));
                           signalMapper1->setMapping(EDIT, i);

                           if(aud==1)
                            {
                               DELT->setDisabled(true);
                               EDIT->setDisabled(true);
                               DELT->setStyleSheet("background-color : gray;color : white ");

                               EDIT->setStyleSheet("background-color : gray;color : white ");
                           }

}
    ////
    ui->stackedWidgetMaintennance->setCurrentIndex(3);

}

void MainWindow::on_pushButton_AjouterReclamation_2_clicked()
{
    RessourceMateriel R;
    ui->comboBox_id_Composant_2->addItem("");
    for(int i=0;i<R.AfficherComposant()->rowCount();i++)
    {
        QString id=ui->tableView_Ressources_2->model()->index(i,7).data().toString();
        ui->comboBox_id_Composant_2->addItem(id);
    }

    for (int i = 0 ; i < ui->comboBox_TypeRecl_2->count() ; ++i) {
    ui->comboBox_TypeRecl_2->setItemData(i, Qt::AlignCenter, Qt::TextAlignmentRole);
    }
    for (int i = 0 ; i < ui->comboBox_id_Composant_2->count() ; ++i) {
    ui->comboBox_id_Composant_2->setItemData(i, Qt::AlignCenter, Qt::TextAlignmentRole);
    }
    for (int i = 0 ; i < ui->comboBox_NatureRecl_2->count() ; ++i) {
        ui->comboBox_NatureRecl_2->setItemData(i, Qt::AlignCenter, Qt::TextAlignmentRole);
        }
    for (int i = 0 ; i < ui->comboBox_NomRouteRecl_2->count() ; ++i) {
        ui->comboBox_NomRouteRecl_2->setItemData(i, Qt::AlignCenter, Qt::TextAlignmentRole);
        }
    ui->stackedWidgetMaintennance->setCurrentIndex(5);

}


void MainWindow::on_pushButton_Sauvgarder_Reclamation_2_clicked()
{
    qDebug("bouton: « ajouterPersonne » appuyé");




    QString TYPE =ui->comboBox_TypeRecl_2->currentText();

    QString ROUTE = ui->comboBox_NomRouteRecl_2->currentText();

    QString DATE =QDate::currentDate().toString();
    QString NATURE = ui->comboBox_NatureRecl_2->currentText();
    QString ID_COMP = ui->comboBox_id_Composant_2->currentText();


    Reclamation R(ROUTE,TYPE,DATE,NATURE,ID_COMP);

    bool test = R.AjouterReclamation();
    if(test)
   {

   QMessageBox::information(nullptr, QObject::tr("Ajouter "),
                     QObject::tr(" ajouté.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

   ui->stackedWidgetMaintennance->setCurrentIndex(3);


   }
     else
       {  QMessageBox::critical(nullptr, QObject::tr("Ajouter"),
                     QObject::tr("Erreur !.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

   }


    ui->tableView_Reclamations_2->setModel( R.AfficherReclamation());

    ////// edit delete buttons
    ///
    ///
    for (int i = 0; i< R.AfficherReclamation()->rowCount(); i++)
       {
        QPushButton *EDIT = new QPushButton(" CHANGER ETAT");
          QPushButton *DELT = new QPushButton("DELETE");

          DELT->setStyleSheet("background-color : red;color : white ");

          EDIT->setStyleSheet("background-color : green;color : white ");

          ui->tableView_Reclamations_2->setIndexWidget(ui->tableView_Reclamations_2->model()->index(i, 4), EDIT);
           ui->tableView_Reclamations_2->setIndexWidget(ui->tableView_Reclamations_2->model()->index(i, 5), DELT);


           QSignalMapper *signalMapper = new QSignalMapper(this);
               connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(DeleteSlotReclamation(int)));
                   connect(DELT, SIGNAL(clicked()), signalMapper, SLOT(map()));
                   signalMapper->setMapping(DELT, i);

                   QSignalMapper *signalMapper1 = new QSignalMapper(this);
                       connect(signalMapper1, SIGNAL(mapped(int)), this, SLOT(ModifierSlotReclamation(int)));
                           connect(EDIT, SIGNAL(clicked()), signalMapper1, SLOT(map()));
                           signalMapper1->setMapping(EDIT, i);

                           if(aud==1)
                            {
                               DELT->setDisabled(true);
                               EDIT->setDisabled(true);
                               DELT->setStyleSheet("background-color : gray;color : white ");

                               EDIT->setStyleSheet("background-color : gray;color : white ");
                           }
}
    ////

    ///int combos !
   ui->comboBox_NatureRecl_2->setCurrentIndex(0);
   ui->comboBox_TypeRecl_2->setCurrentIndex(0);
   ui->comboBox_NomRouteRecl_2->setCurrentIndex(0);
   ui->comboBox_id_Composant_2->clear();



    ///

}

void MainWindow::on_pushButton_Annuler_Reclamation_2_clicked()
{
    ///int combos !
   ui->comboBox_NatureRecl_2->setCurrentIndex(0);
   ui->comboBox_TypeRecl_2->setCurrentIndex(0);
   ui->comboBox_NomRouteRecl_2->setCurrentIndex(0);
   ui->comboBox_id_Composant_2->clear();


    ///
    ui->stackedWidgetMaintennance->setCurrentIndex(3);

}



//////////////// methodes /////



void MainWindow::DeleteSlotRessource(int i){

    RessourceMateriel R ;


   QString id= ui->tableView_Ressources_2->model()->index(i,7).data().toString();

     R.SupprimerComposant(id);
     ui->tableView_Ressources_2->setModel( R.AfficherComposant());

     ////// edit delete buttons
     ///
     ///

      for (int i = 0; i< R.AfficherComposant()->rowCount(); i++)
        {
          QPushButton *EDIT = new QPushButton("CHANGER ETAT");
           QPushButton *DELT = new QPushButton("DELETE");

           DELT->setStyleSheet("background-color : red;color : white  ");

           EDIT->setStyleSheet("background-color : green;color : white ");

           ui->tableView_Ressources_2->setIndexWidget(ui->tableView_Ressources_2->model()->index(i, 5), EDIT);
            ui->tableView_Ressources_2->setIndexWidget(ui->tableView_Ressources_2->model()->index(i, 6), DELT);

            QSignalMapper *signalMapper = new QSignalMapper(this);
                connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(DeleteSlotRessource(int)));
                    connect(DELT, SIGNAL(clicked()), signalMapper, SLOT(map()));
                    signalMapper->setMapping(DELT, i);

                    QSignalMapper *signalMapper1 = new QSignalMapper(this);
                        connect(signalMapper1, SIGNAL(mapped(int)), this, SLOT(ModifierSlotReclamation(int)));
                            connect(EDIT, SIGNAL(clicked()), signalMapper1, SLOT(map()));
                            signalMapper1->setMapping(EDIT, i);

                            if(aud==1)
                             {
                                DELT->setDisabled(true);
                                EDIT->setDisabled(true);
                                DELT->setStyleSheet("background-color : gray;color : white ");

                                EDIT->setStyleSheet("background-color : gray;color : white ");
                            }

  }

     ////
      ui->Reclamation_Serach_2->setText("");


}

void MainWindow::DeleteSlotReclamation(int i){

    Reclamation R ;


   QString id= ui->tableView_Reclamations_2->model()->index(i,6).data().toString();

      if(id=="12"){C.write_to_arduino("2");};

     R.SupprimerReclamation(id);

     ui->tableView_Reclamations_2->setModel( R.AfficherReclamation());

     ////// edit delete buttons
     ///
     ///

      for (int i = 0; i< R.AfficherReclamation()->rowCount(); i++)
        {
          QPushButton *EDIT = new QPushButton(" CHANGER ETAT");
           QPushButton *DELT = new QPushButton("DELETE");

           DELT->setStyleSheet("background-color : red;color : white  ");

           EDIT->setStyleSheet("background-color : green;color : white ");

           ui->tableView_Reclamations_2->setIndexWidget(ui->tableView_Reclamations_2->model()->index(i, 4), EDIT);
            ui->tableView_Reclamations_2->setIndexWidget(ui->tableView_Reclamations_2->model()->index(i, 5), DELT);

            QSignalMapper *signalMapper = new QSignalMapper(this);
                connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(DeleteSlotReclamation(int)));
                    connect(DELT, SIGNAL(clicked()), signalMapper, SLOT(map()));
                    signalMapper->setMapping(DELT, i);
                    QSignalMapper *signalMapper1 = new QSignalMapper(this);
                        connect(signalMapper1, SIGNAL(mapped(int)), this, SLOT(ModifierSlotReclamation(int)));
                            connect(EDIT, SIGNAL(clicked()), signalMapper1, SLOT(map()));
                            signalMapper1->setMapping(EDIT, i);

                            if(aud==1)
                             {
                                DELT->setDisabled(true);
                                EDIT->setDisabled(true);
                                DELT->setStyleSheet("background-color : gray;color : white ");

                                EDIT->setStyleSheet("background-color : gray;color : white ");
                            }
  }

     ////
      ui->Reclamation_Serach_2->setText("");


}


void MainWindow::ModifierSlotReclamation(int i){


Reclamation R ;


QString id= ui->tableView_Reclamations_2->model()->index(i,6).data().toString();
QString NATURE= ui->tableView_Reclamations_2->model()->index(i,3).data().toString();

qDebug()<<"Nature:"<<NATURE;

if( NATURE == "")
{

    ui->comboBox_NatureRecl_2->setCurrentIndex(1);
    NATURE = ui->comboBox_NatureRecl_2->currentText();
}
else if(NATURE == "Urgente")
{
     qDebug("INN URGENTE");

    ui->comboBox_NatureRecl_2->setCurrentIndex(0);
    NATURE = ui->comboBox_NatureRecl_2->currentText();
}

  R.ModifierReclamation(id,NATURE);

  ui->tableView_Reclamations_2->setModel( R.AfficherReclamation());

  ////// edit delete buttons
  ///
  ///

   for (int i = 0; i< R.AfficherReclamation()->rowCount(); i++)
     {
       QPushButton *EDIT = new QPushButton(" CHANGER ETAT");
        QPushButton *DELT = new QPushButton("DELETE");

        DELT->setStyleSheet("background-color : red;color : white  ");

        EDIT->setStyleSheet("background-color : green;color : white ");

        ui->tableView_Reclamations_2->setIndexWidget(ui->tableView_Reclamations_2->model()->index(i, 4), EDIT);
         ui->tableView_Reclamations_2->setIndexWidget(ui->tableView_Reclamations_2->model()->index(i, 5), DELT);

         QSignalMapper *signalMapper = new QSignalMapper(this);
             connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(DeleteSlotReclamation(int)));
                 connect(DELT, SIGNAL(clicked()), signalMapper, SLOT(map()));
                 signalMapper->setMapping(DELT, i);

                 QSignalMapper *signalMapper1 = new QSignalMapper(this);
                     connect(signalMapper1, SIGNAL(mapped(int)), this, SLOT(ModifierSlotReclamation(int)));
                         connect(EDIT, SIGNAL(clicked()), signalMapper1, SLOT(map()));
                         signalMapper1->setMapping(EDIT, i);

                         if(aud==1)
                          {
                             DELT->setDisabled(true);
                             EDIT->setDisabled(true);
                             DELT->setStyleSheet("background-color : gray;color : white ");

                             EDIT->setStyleSheet("background-color : gray;color : white ");
                         }

}

  ////
   ui->Reclamation_Serach_2->setText("");


}

void MainWindow:: ModifierSlotRessource(int i){


 RessourceMateriel R ;


 QString id= ui->tableView_Ressources_2->model()->index(i,7).data().toString();
 QString ETAT_COMP= ui->tableView_Ressources_2->model()->index(i,1).data().toString();


 if( ETAT_COMP == "Fonctionne")
 {

     ui->comboBox_EtatComp_2->setCurrentIndex(1);
     ETAT_COMP = ui->comboBox_EtatComp_2->currentText();
 }
 else if(ETAT_COMP == "En Panne")
 {
      qDebug("INN URGENTE");

     ui->comboBox_EtatComp_2->setCurrentIndex(0);
     ETAT_COMP = ui->comboBox_EtatComp_2->currentText();
 }

   R.ModifierComposant(id,ETAT_COMP);

   ui->tableView_Ressources_2->setModel( R.AfficherComposant());

   ////// edit delete buttons
   ///
   ///

    for (int i = 0; i< R.AfficherComposant()->rowCount(); i++)
      {
        QPushButton *EDIT = new QPushButton(" CHANGER ETAT");
         QPushButton *DELT = new QPushButton("DELETE");

         DELT->setStyleSheet("background-color : red;color : white  ");

         EDIT->setStyleSheet("background-color : green;color : white ");

         ui->tableView_Ressources_2->setIndexWidget(ui->tableView_Ressources_2->model()->index(i, 5), EDIT);
          ui->tableView_Ressources_2->setIndexWidget(ui->tableView_Ressources_2->model()->index(i, 6), DELT);

          QSignalMapper *signalMapper = new QSignalMapper(this);
              connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(DeleteSlotRessource(int)));
                  connect(DELT, SIGNAL(clicked()), signalMapper, SLOT(map()));
                  signalMapper->setMapping(DELT, i);

                  QSignalMapper *signalMapper1 = new QSignalMapper(this);
                      connect(signalMapper1, SIGNAL(mapped(int)), this, SLOT(ModifierSlotRessource(int)));
                          connect(EDIT, SIGNAL(clicked()), signalMapper1, SLOT(map()));
                          signalMapper1->setMapping(EDIT, i);

                          if(aud==1)
                           {
                              DELT->setDisabled(true);
                              EDIT->setDisabled(true);
                              DELT->setStyleSheet("background-color : gray;color : white ");

                              EDIT->setStyleSheet("background-color : gray;color : white ");
                          }

 }

   ////

    ui->Ressource_Search_2->setText("");
};




/// Search
///
void MainWindow::on_Ressource_Search_2_textChanged(const QString &arg1)
{
    RessourceMateriel R;
    if(ui->checkBox_NOM_RESS_2->isChecked())
    {

        ui->tableView_Ressources_2->setModel( R.chercheComposant(1,arg1));

    }
    else if(ui->checkBox_ETAT_RESS_2->isChecked())
    {

        ui->tableView_Ressources_2->setModel( R.chercheComposant(2,arg1));

    }
    else if(ui->checkBox_TYPE_RESS_2->isChecked())
    {

        ui->tableView_Ressources_2->setModel( R.chercheComposant(3,arg1));

    }
    else
    {
        ui->tableView_Ressources_2->setModel( R.chercheComposant(1,arg1));

    }

    if(ui->Ressource_Search_2->text() == "")
    {
        ui->checkBox_NOM_RESS_2->setDisabled(false);
        ui->checkBox_TYPE_RESS_2->setDisabled(false);
        ui->checkBox_ETAT_RESS_2->setDisabled(false);
        ui->checkBox_NOM_RESS_2->setChecked(false);
        ui->checkBox_TYPE_RESS_2->setChecked(false);
        ui->checkBox_ETAT_RESS_2->setChecked(false);
        ui->tableView_Ressources_2->setModel( R.AfficherComposant());


    }

    ////// edit delete buttons
    ///
    ///

     for (int i = 0; i< R.AfficherComposant()->rowCount(); i++)
       {
         QPushButton *EDIT = new QPushButton(" CHANGER ETAT");
          QPushButton *DELT = new QPushButton("DELETE");

          DELT->setStyleSheet("background-color : red;color : white  ");

          EDIT->setStyleSheet("background-color : green;color : white ");

          ui->tableView_Ressources_2->setIndexWidget(ui->tableView_Ressources_2->model()->index(i, 5), EDIT);
           ui->tableView_Ressources_2->setIndexWidget(ui->tableView_Ressources_2->model()->index(i, 6), DELT);

           QSignalMapper *signalMapper = new QSignalMapper(this);
               connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(DeleteSlotRessource(int)));
                   connect(DELT, SIGNAL(clicked()), signalMapper, SLOT(map()));
                   signalMapper->setMapping(DELT, i);

                   QSignalMapper *signalMapper1 = new QSignalMapper(this);
                       connect(signalMapper1, SIGNAL(mapped(int)), this, SLOT(ModifierSlotRessource(int)));
                           connect(EDIT, SIGNAL(clicked()), signalMapper1, SLOT(map()));
                           signalMapper1->setMapping(EDIT, i);

                           if(aud==1)
                            {
                               DELT->setDisabled(true);
                               EDIT->setDisabled(true);
                               DELT->setStyleSheet("background-color : gray;color : white ");

                               EDIT->setStyleSheet("background-color : gray;color : white ");
                           }

 }

    ////


}





void MainWindow::on_checkBox_NOM_RESS_2_stateChanged(int arg1)
{
    if(ui->checkBox_NOM_RESS_2->isChecked())
    {
    ui->checkBox_ETAT_RESS_2->setDisabled(true);
    ui->checkBox_TYPE_RESS_2->setDisabled(true);
    }
    else
    {
        ui->checkBox_TYPE_RESS_2->setDisabled(false);
        ui->checkBox_ETAT_RESS_2->setDisabled(false);
    }
}

void MainWindow::on_checkBox_TYPE_RESS_2_stateChanged(int arg1)
{

    if(ui->checkBox_TYPE_RESS_2->isChecked())
    {
        ui->checkBox_NOM_RESS_2->setDisabled(true);
        ui->checkBox_ETAT_RESS_2->setDisabled(true);
    }
    else
    {
        ui->checkBox_NOM_RESS_2->setDisabled(false);
        ui->checkBox_ETAT_RESS_2->setDisabled(false);
    }
}

void MainWindow::on_checkBox_ETAT_RESS_2_stateChanged(int arg1)
{

    if(ui->checkBox_ETAT_RESS_2->isChecked())
    {
        ui->checkBox_TYPE_RESS_2->setDisabled(true);
        ui->checkBox_NOM_RESS_2->setDisabled(true);
    }
    else
    {
        ui->checkBox_TYPE_RESS_2->setDisabled(false);
        ui->checkBox_NOM_RESS_2->setDisabled(false);
    }
}



//Reclamation





void MainWindow::on_Reclamation_Serach_2_textChanged(const QString &arg1)
{

    Reclamation R;

    if(ui->checkBox_Route_REc_2->isChecked())
    {

        ui->tableView_Reclamations_2->setModel( R.chercheReclamation(2,arg1));

    }
    else if(ui->checkBox_Type_REc_2->isChecked())
    {

        ui->tableView_Reclamations_2->setModel( R.chercheReclamation(3,arg1));

    }
    else if(ui->checkBox_nature_REc_2->isChecked())
    {

        ui->tableView_Reclamations_2->setModel( R.chercheReclamation(4,arg1));

    }
    else
    {
        ui->tableView_Reclamations_2->setModel( R.chercheReclamation(2,arg1));

    }

    if(ui->Reclamation_Serach_2->text() == "")
    {
        ui->checkBox_Type_REc_2->setDisabled(false);
        ui->checkBox_Route_REc_2->setDisabled(false);
        ui->checkBox_nature_REc_2->setDisabled(false);
        ui->checkBox_Date_2->setDisabled(false);


        ui->checkBox_Type_REc_2->setChecked(false);
        ui->checkBox_Route_REc_2->setChecked(false);
        ui->checkBox_nature_REc_2->setChecked(false);
        ui->checkBox_Date_2->setChecked(false);

        ui->tableView_Reclamations_2->setModel( R.AfficherReclamation());


    }


    ////// edit delete buttons
    ///
    ///

     for (int i = 0; i< R.AfficherReclamation()->rowCount(); i++)
       {
         QPushButton *EDIT = new QPushButton(" CHANGER ETAT");
          QPushButton *DELT = new QPushButton("DELETE");

          DELT->setStyleSheet("background-color : red;color : white  ");

          EDIT->setStyleSheet("background-color : green;color : white ");

          ui->tableView_Reclamations_2->setIndexWidget(ui->tableView_Reclamations_2->model()->index(i, 4), EDIT);
           ui->tableView_Reclamations_2->setIndexWidget(ui->tableView_Reclamations_2->model()->index(i, 5), DELT);

           QSignalMapper *signalMapper = new QSignalMapper(this);
               connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(DeleteSlotReclamation(int)));
                   connect(DELT, SIGNAL(clicked()), signalMapper, SLOT(map()));
                   signalMapper->setMapping(DELT, i);

                   QSignalMapper *signalMapper1 = new QSignalMapper(this);
                       connect(signalMapper1, SIGNAL(mapped(int)), this, SLOT(ModifierSlotReclamation(int)));
                           connect(EDIT, SIGNAL(clicked()), signalMapper1, SLOT(map()));
                           signalMapper1->setMapping(EDIT, i);

                           if(aud==1)
                            {
                               DELT->setDisabled(true);
                               EDIT->setDisabled(true);
                               DELT->setStyleSheet("background-color : gray;color : white ");

                               EDIT->setStyleSheet("background-color : gray;color : white ");
                           }

 }

    ////

}

void MainWindow::on_checkBox_nature_REc_2_stateChanged(int arg1)
{
    if(ui->checkBox_nature_REc_2->isChecked())
    {
    ui->checkBox_Type_REc_2->setDisabled(true);
    ui->checkBox_Route_REc_2->setDisabled(true);
    ui->checkBox_Date_2->setDisabled(true);


    }
    else
    {
        ui->checkBox_Type_REc_2->setDisabled(false);
        ui->checkBox_Route_REc_2->setDisabled(false);
        ui->checkBox_Date_2->setDisabled(false);

    }
}

void MainWindow::on_checkBox_Type_REc_2_stateChanged(int arg1)
{
    if(ui->checkBox_Type_REc_2->isChecked())
    {
    ui->checkBox_nature_REc_2->setDisabled(true);
    ui->checkBox_Route_REc_2->setDisabled(true);
    ui->checkBox_Date_2->setDisabled(true);


    }
    else
    {
        ui->checkBox_nature_REc_2->setDisabled(false);
        ui->checkBox_Route_REc_2->setDisabled(false);
        ui->checkBox_Date_2->setDisabled(false);

    }
}

void MainWindow::on_checkBox_Route_REc_2_stateChanged(int arg1)
{
    if(ui->checkBox_Route_REc_2->isChecked())
    {
    ui->checkBox_nature_REc_2->setDisabled(true);
    ui->checkBox_Type_REc_2->setDisabled(true);
    ui->checkBox_Date_2->setDisabled(true);


    }
    else
    {
        ui->checkBox_nature_REc_2->setDisabled(false);
        ui->checkBox_Type_REc_2->setDisabled(false);
        ui->checkBox_Date_2->setDisabled(false);

    }
}
void MainWindow::on_checkBox_Date_2_stateChanged(int arg1)
{
    if(ui->checkBox_Date_2->isChecked())
    {
    ui->checkBox_nature_REc_2->setDisabled(true);
    ui->checkBox_Type_REc_2->setDisabled(true);
    ui->checkBox_Route_REc_2->setDisabled(true);


    }
    else
    {
        ui->checkBox_nature_REc_2->setDisabled(false);
        ui->checkBox_Type_REc_2->setDisabled(false);
        ui->checkBox_Route_REc_2->setDisabled(false);

    }
}


///


///////// SORTTT

void MainWindow::on_Order_2_clicked()
{
    Reclamation R;

    if(ui->checkBox_Route_REc_2->isChecked())
    {

        ui->tableView_Reclamations_2->setModel( R.Sort(2));

    }
    else if(ui->checkBox_Type_REc_2->isChecked())
    {

        ui->tableView_Reclamations_2->setModel( R.Sort(3));

    }
    else if(ui->checkBox_nature_REc_2->isChecked())
    {

        ui->tableView_Reclamations_2->setModel(R.Sort(4));

    }
    else if(ui->checkBox_Date_2->isChecked())
    {

        ui->tableView_Reclamations_2->setModel( R.Sort(1));

    }
    else
    {
        ui->tableView_Reclamations_2->setModel( R.Sort(1));

    }

    ////// edit delete buttons
    ///
    ///

     for (int i = 0; i< R.AfficherReclamation()->rowCount(); i++)
       {
         QPushButton *EDIT = new QPushButton(" CHANGER ETAT");
          QPushButton *DELT = new QPushButton("DELETE");

          DELT->setStyleSheet("background-color : red;color : white  ");

          EDIT->setStyleSheet("background-color : green;color : white ");

          ui->tableView_Reclamations_2->setIndexWidget(ui->tableView_Reclamations_2->model()->index(i, 4), EDIT);
           ui->tableView_Reclamations_2->setIndexWidget(ui->tableView_Reclamations_2->model()->index(i, 5), DELT);

           QSignalMapper *signalMapper = new QSignalMapper(this);
               connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(DeleteSlotReclamation(int)));
                   connect(DELT, SIGNAL(clicked()), signalMapper, SLOT(map()));
                   signalMapper->setMapping(DELT, i);

                   QSignalMapper *signalMapper1 = new QSignalMapper(this);
                       connect(signalMapper1, SIGNAL(mapped(int)), this, SLOT(ModifierSlotReclamation(int)));
                           connect(EDIT, SIGNAL(clicked()), signalMapper1, SLOT(map()));
                           signalMapper1->setMapping(EDIT, i);

                           if(aud==1)
                            {
                               DELT->setDisabled(true);
                               EDIT->setDisabled(true);
                               DELT->setStyleSheet("background-color : gray;color : white ");

                               EDIT->setStyleSheet("background-color : gray;color : white ");
                           }

 }

    ////

     ui->checkBox_Type_REc_2->setDisabled(false);
     ui->checkBox_Route_REc_2->setDisabled(false);
     ui->checkBox_nature_REc_2->setDisabled(false);
     ui->checkBox_Date_2->setDisabled(false);

     ui->checkBox_Type_REc_2->setChecked(false);
     ui->checkBox_Route_REc_2->setChecked(false);
     ui->checkBox_nature_REc_2->setChecked(false);
     ui->checkBox_Date_2->setChecked(false);

}

///

//////////////////Statistics

void MainWindow::on_pushButton_Statistique_2_clicked()
{
    ui->stackedWidgetMaintennance->setCurrentIndex(6);

}

void MainWindow::on_pushButton_StatMaint_Retour_clicked()
{
    delete ui->Stat_2->layout();

     ui->comboBox_stat_2->setCurrentIndex(0);
    ui->stackedWidgetMaintennance->setCurrentIndex(3);

}

void MainWindow::on_comboBox_stat_2_currentIndexChanged(int index)
{

    Reclamation R ;
    int p=0,c=0;

    if(index==3)
    {
        for (int i = 0; i< R.AfficherReclamation()->rowCount(); i++)
          {
            QString type= ui->tableView_Reclamations_2->model()->index(i,1).data().toString();
            if(type == "canal d'eau"){c++;}
            else{p++;};


          }

        QPieSeries *series = new QPieSeries();
            series->append("Canal D'Eau",c);
            series->append("Poteaux Electirque",p);


            // Add label to 1st slice
            QPieSlice *slice0 = series->slices().at(0);
            slice0->setLabelVisible();
            qDebug()<<p<<""<<c;

            // Add label, explode and define brush for 2nd slice
            QPieSlice *slice1 = series->slices().at(1);
            slice1->setExploded();
            slice1->setLabelVisible();
            slice1->setPen(QPen(Qt::darkGreen, 2));
            slice1->setBrush(Qt::yellow);
            // Create the chart widget
            QChart *chart = new QChart();

            // Add data to chart with title and hide legend
            chart->addSeries(series);
            chart->setTitle("TYPES");
            chart->legend()->hide();

            // Used to display the chart
            QChartView *chartView = new QChartView(chart);
            chartView->setRenderHint(QPainter::Antialiasing);

            QGridLayout* gridLayout;

            gridLayout = new QGridLayout(ui->Stat_2);
            gridLayout->addWidget(chartView,0,0);

}

    if(index==1)
    {
        Reclamation R ;
        int Gha=0,Nkhi=0;
        for (int i = 0; i< R.AfficherReclamation()->rowCount(); i++)
          {
            QString type= ui->tableView_Reclamations_2->model()->index(i,0).data().toString();
            if(type == "Ghazela"){Gha++;}
            else if(type == "Nkhilette") {Nkhi++;};


          }

        QPieSeries *series = new QPieSeries();
            series->append("Ghazela",Gha);
            series->append("Nkhilette",Nkhi);


            // Add label to 1st slice
            QPieSlice *slice0 = series->slices().at(0);
            slice0->setLabelVisible();
            qDebug()<<p<<""<<c;

            // Add label, explode and define brush for 2nd slice
            QPieSlice *slice1 = series->slices().at(1);
            slice1->setExploded();
            slice1->setLabelVisible();
            slice1->setPen(QPen(Qt::gray, 2));
            slice1->setBrush(Qt::magenta);
            // Create the chart widget
            QChart *chart = new QChart();

            // Add data to chart with title and hide legend
            chart->addSeries(series);
            chart->setTitle("Routes");
            chart->legend()->hide();

            // Used to display the chart
            QChartView *chartView = new QChartView(chart);
            chartView->setRenderHint(QPainter::Antialiasing);

            QGridLayout* gridLayout;

            gridLayout = new QGridLayout(ui->Stat_2);
            gridLayout->addWidget(chartView,0,0);

    }


        if(index==2)
        {
            Reclamation R ;
            int urg=0,non=0;
            for (int i = 0; i< R.AfficherReclamation()->rowCount(); i++)
              {
                QString type= ui->tableView_Reclamations_2->model()->index(i,3).data().toString();
                if(type == "Urgente"){urg++;}
                else{non++;};


              }

            QPieSeries *series = new QPieSeries();
                series->append("Urgente",urg);
                series->append("N'est pas Urgente",non);


                // Add label to 1st slice
                QPieSlice *slice0 = series->slices().at(0);
                slice0->setLabelVisible();
                qDebug()<<p<<""<<c;

                // Add label, explode and define brush for 2nd slice
                QPieSlice *slice1 = series->slices().at(1);
                slice1->setExploded();
                slice1->setLabelVisible();
                slice1->setPen(QPen(Qt::red, 2));
                slice1->setBrush(Qt::green);
                // Create the chart widget
                QChart *chart = new QChart();

                // Add data to chart with title and hide legend
                chart->addSeries(series);
                chart->setTitle("Narure");
                chart->legend()->hide();

                // Used to display the chart
                QChartView *chartView = new QChartView(chart);
                chartView->setRenderHint(QPainter::Antialiasing);

                QGridLayout* gridLayout;

                gridLayout = new QGridLayout(ui->Stat_2);
                gridLayout->addWidget(chartView,0,0);

        }
       if(ui->comboBox_stat_2->currentIndex()==0)
        {
           delete ui->Stat_2->layout();

        }



}

void MainWindow::on_tableView_Reclamations_2_doubleClicked(const QModelIndex &index)
{

    QMessageBox msgBox;
    msgBox.setText(tr("Vous voulez imprimer la reclamation !? \n "));
    QAbstractButton* pButtonYes = msgBox.addButton(tr("Imprimer!"), QMessageBox::YesRole);
    QAbstractButton* pButtonNo = msgBox.addButton(tr("Annuler!"), QMessageBox::NoRole);

    msgBox.exec();

    if (msgBox.clickedButton()==pButtonYes)
    {
            QPrinter printer(QPrinter::HighResolution);

            printer.setCopyCount(1);


                QPrintDialog *dialog = new QPrintDialog(&printer, this);

                dialog->setWindowTitle(tr("Reclamation Document"));
                 dialog->addEnabledOption(QAbstractPrintDialog::PrintSelection);


                    QPainter painter;

         painter.begin(&printer);


        QFile file;
        QDir::setCurrent("/tmp");
        file.setFileName("back2.jpg");
        QDir::setCurrent("C:/Users/Bader Semah/Desktop/Smart_Municipality_2A3");
        file.open(QIODevice::ReadOnly);
        QImage img(file.fileName());
        painter.drawImage(0,0,img.scaled(6000,7017, Qt::IgnoreAspectRatio, Qt::FastTransformation));


        QFile file2;
        QDir::setCurrent("/tmp");
        file2.setFileName("municipal.png");
        QDir::setCurrent("C:/Users/Bader Semah/Desktop/Smart_Municipality_2A3");
        file2.open(QIODevice::ReadOnly);
        QImage img2(file2.fileName());
        painter.drawImage(0,0,img2.scaled(900,1000, Qt::IgnoreAspectRatio, Qt::FastTransformation));

        QString TYPE = ui->tableView_Reclamations_2->model()->index(index.row(),1).data().toString() ;
        QString ID_COMP = ui->tableView_Reclamations_2->model()->index(index.row(),7).data().toString();
        QString ID_REC = ui->tableView_Reclamations_2->model()->index(index.row(),6).data().toString();
        QString ROUTE = ui->tableView_Reclamations_2->model()->index(index.row(),0).data().toString();
        QString NATURE = ui->tableView_Reclamations_2->model()->index(index.row(),3).data().toString();
        QString DATE =ui->tableView_Reclamations_2->model()->index(index.row(),2).data().toString();
        if(NATURE == ""){NATURE = "N'est pas Urgente";};


         painter.setFont(QFont("Harlow Solid Italic",30,-1,1));
          painter.setPen(QColor(0,102,204));
        painter.drawText(width()+100,height()+600,"Identifiant de Reclamation : "+ID_REC+"" );
         painter.setFont(QFont("Berlin Sans FB Demi Bold",15));
           painter.setPen(QColor(0,0,0));
        painter.drawText(width()-500,height()+1400,"Identifiant de Composant :  "+ID_COMP+"" );
        painter.drawText(width()-500,height()+1800,"Nom de Route :  "+ROUTE+"" );
        painter.drawText(width()-500,height()+2200,"Type de Composant :  "+TYPE+"" );
        painter.drawText(width()-500,height()+2600,"Date :  "+DATE+"" );
        painter.drawText(width()-500,height()+3000,"Nature :  "+NATURE+"" );

                    painter.end();

    }
    else if (msgBox.clickedButton()==pButtonNo)
    {
        msgBox.close();
    }
}


void MainWindow::on_pushButton_Scnario_Pression_clicked()
{
    C.write_to_arduino("0");
}


void MainWindow::on_MenuP_2_clicked()
{
    ui->stackedWidget_Main->setCurrentIndex(0);
}

void MainWindow::on_res_2_clicked()
{
    ui->stackedWidget_Main->setCurrentIndex(1);
     ui->stackedWidget_resources_humaines->setCurrentIndex(0);
}

void MainWindow::on_envi_2_clicked()
{
     ui->stackedWidget_Main->setCurrentIndex(2);
     ui->stackedWidget_Environnement->setCurrentIndex(0);
}

void MainWindow::on_communication_2_clicked()
{
    ui->stackedWidget_Main->setCurrentIndex(5);
    ui->stackedWidget_2->setCurrentIndex(0);

}

void MainWindow::on_marche_2_clicked()
{
    ui->stackedWidget_Main->setCurrentIndex(5);
       ui->stackedWidget->setCurrentIndex(0);
}

/****************************** fin deplacement entre module:: module Maintenance ****************************/
/************************************** End Semah **************************************************************/







void MainWindow::on_pushButton_Environnement_clicked()
{
     ui->stackedWidget_Main->setCurrentIndex(2);
          ui->stackedWidget_Environnement->setCurrentIndex(0);
}



void MainWindow::on_pushButton_Communication_clicked()
{
     ui->stackedWidget_Main->setCurrentIndex(3);
        ui->stackedWidget->setCurrentIndex(0);
}


//**************************************************************************************************
//****************************************BEGIN SAHRAOUI********************************************
void MainWindow::on_ajouter_marchant_clicked()
{
    QString nom=ui->nom_marchand->text();
    QString prenom=ui->prenom_marchand->text();
    int numero=ui->numero_marchand->text().toInt();
    QString emplacement=ui->emplacement_marchand->text();

    QMessageBox msg;
    marchand m(nom,prenom,emplacement,numero);
    if(m.ajouter()){
           ui->afficher_marchand->setModel(tmp1.afficher());
    }else {
        msg.setText("failed to add");
           msg.exec();
    }


}

void MainWindow::on_modifier_marchand_clicked()
{
    int id=ui->id_marchand->text().toInt();

        QString nom=ui->nom_marchand->text();
        QString prenom=ui->prenom_marchand->text();
        int numero=ui->numero_marchand->text().toInt();
        QString emplacement=ui->emplacement_marchand->text();
        QMessageBox msg;
        marchand m(nom,prenom,emplacement,numero);
        if(m.modifier(id)){
              ui->afficher_marchand->setModel(tmp1.afficher());

        }else {
            msg.setText("failed to edit");
               msg.exec();
        }
}

void MainWindow::on_supprimer_marchand_clicked()
{
    int id=ui->id_marchand->text().toInt();
        marchand m;
        QMessageBox msg;

        if(m.supprimer(id)){
          ui->afficher_marchand->setModel(tmp1.afficher());
        }else {
            msg.setText("failed to delete");
               msg.exec();
        }
}

void MainWindow::on_pushButton_5_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);
}

void MainWindow::on_ajouter_mission_clicked()
{
    int cin=ui->cin_mission->text().toInt();
         QString horaire=ui->horaire_mission->text();
         QString date=ui->date_mission->text();
         QString type=ui->type_mission->text();
         QString emplacement=ui->emplacement_mission->text();
          mission m(cin, horaire,date, type , emplacement);
          QMessageBox msg;

          if(m.ajouter()){
           ui->afficher_mission->setModel(tmp2.afficher());
          }else {
              msg.setText("failed to add");
                 msg.exec();

          }
}

void MainWindow::on_modifier_mission_clicked()
{
    int cin=ui->cin_mission->text().toInt();
        QString horaire=ui->horaire_mission->text();
        QString date=ui->date_mission->text();
        QString type=ui->type_mission->text();
        QString emplacement=ui->emplacement_mission->text();
         mission m(cin, horaire,date, type , emplacement);
         QMessageBox msg;
    if(m.modifier(cin)){
        ui->afficher_mission->setModel(tmp2.afficher());

    }else {
        msg.setText("failed to edit");
           msg.exec();
    }

}

void MainWindow::on_supprimer_mission_clicked()
{
    int cin=ui->cin_mission->text().toInt();
        mission m;
        QMessageBox msg;

        if(m.supprimer(cin)){
          ui->afficher_mission->setModel(tmp2.afficher());
        }else {
            msg.setText("failed to delete");
               msg.exec();
        }


}

void MainWindow::on_pushButton_6_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);
}

void MainWindow::on_pushButton_7_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(1);
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(2);
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(3);
}

void MainWindow::on_recherche_2_textChanged(const QString &arg1)
{
    ui->afficher_marchand->setModel(tmp1.rechercheDynamic(arg1));
}

void MainWindow::on_recherche_mission_textChanged(const QString &arg1)
{
    ui->afficher_mission->setModel(tmp2.rechercheDynamic(arg1));
}
void MainWindow::stat(){


    QSqlQuery query;

            QString marchand="";
            query.prepare("SELECT COUNT(*) FROM marchand");
            query.exec();
            while(query.next()){
            marchand= query.value(0).toString();}


            QString mission="";
            query.prepare("SELECT COUNT(*) FROM mission");
            query.exec();
            while(query.next()){
            mission= query.value(0).toString();}



        QBarSet *set0 = new QBarSet("mission/marchand");


           *set0 << marchand.toInt()  << mission.toInt()   ;
        QBarSeries *series = new QBarSeries();
         series->append(set0);
         QChart *chart = new QChart();
             chart->addSeries(series);
             chart->setTitle("statistique");
             chart->setAnimationOptions(QChart::SeriesAnimations);

             QStringList categories;
                categories << "nombre mission" <<  "nombre marchand" ;
                QBarCategoryAxis *axisX = new QBarCategoryAxis();
                axisX->append(categories);
                chart->addAxis(axisX, Qt::AlignBottom);
                series->attachAxis(axisX);



                chart->legend()->setVisible(true);
                    chart->legend()->setAlignment(Qt::AlignBottom);

                    QChartView *chartView = new QChartView(chart);
                    chartView->setRenderHint(QPainter::Antialiasing);
                    chartView->setParent(ui->horizontalFrame);

}

void MainWindow::on_afficher_marchand_activated(const QModelIndex &index)
{
    QString val=ui->afficher_marchand->model()->data(index).toString();
    ui->id_marchand->setText(val);
}

void MainWindow::on_afficher_mission_activated(const QModelIndex &index)
{
    QString val=ui->afficher_mission->model()->data(index).toString();
    ui->cin_mission->setText(val);
}

//**********************deplacement pour le module oraganisation*****************************************


void MainWindow::on_pushButton_MP_2_clicked()
{
    ui->stackedWidget_Main->setCurrentIndex(0);
}

void MainWindow::on_pushButton_Environ_2_clicked()
{
    ui->stackedWidget_Main->setCurrentIndex(2);
        ui->stackedWidget_Environnement->setCurrentIndex(0);
}

void MainWindow::on_pushButton_Marche_2_clicked()
{
    ui->stackedWidget_Main->setCurrentIndex(1);
     ui->stackedWidget_resources_humaines->setCurrentIndex(1);
}

void MainWindow::on_pushButton_Maintenance_2_clicked()
{
    ui->stackedWidget_Main->setCurrentIndex(4);
     ui->stackedWidgetMaintennance->setCurrentIndex(1);
}

void MainWindow::on_pushButton_8_clicked()
{
    ui->stackedWidget_Main->setCurrentIndex(3);
     ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_backMaintenance_5_clicked()
{
    ui->stackedWidget_Main->setCurrentIndex(0);
}

void MainWindow::on_pushButton_RessourcesHumaine_2_clicked()
{
    ui->stackedWidget_Main->setCurrentIndex(5);
    ui->stackedWidget_2->setCurrentIndex(0);
}
//***********************fin deplacement entre modules**********************************
//*****************************END SAHRAOUI**************************************************

