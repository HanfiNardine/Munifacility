#ifndef CAPTEUR_HUMIDITE_H
#define CAPTEUR_HUMIDITE_H

#include<QtSerialPort/QtSerialPort>
#include<QtSerialPort/QSerialPortInfo>
class Capteur_humidite
{
public:
    Capteur_humidite();
    int connect_capteur_humidite();
    int close_Capteur_humidite();

    QByteArray read_from_capteur_humidite();
    QSerialPort* getserial();
    QString get_capteur_humidite_port_name();
    int write_to_arduino(QByteArray); //envoie des données à arduino
    /***********************/
private :
    QSerialPort *serial;
    static const quint16 arduino_uno_vendor_id=9025;
    static const quint16 arduino_uno_producy_id=67;
    QString arduino_port_name;
    bool arduino_is_available;
    QByteArray data;
};

#endif // CAPTEUR_HUMIDITE_H
