#include "mainwindow.h"

#include <QApplication>
#include "connection.h"
#include <QMessageBox>
#include <QtMultimedia/QMediaPlayer>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Connection C;

    QMessageBox msg;
    bool test=C.TestConnection();
    msg.setWindowTitle ( "Munifacility" );
    QIcon m ("C:/Users/Bader Semah/Desktop/Smart_Municipality_2A3/munifacility_2Nf_3");
     msg.setWindowIcon(m);
     QMediaPlayer *player = new QMediaPlayer;
     player->setMedia(QUrl::fromLocalFile("C:/Users/Bader Semah/Desktop/Smart_Municipality_2A3/MainWindow.mp3"));
     player->setVolume(50);
  player->play();
    if (test)
      msg.setText("Connection réussite");
    else msg.setText("Connection impossible");

    msg.exec();
   player->stop();
   w.show();

    return a.exec();
}
