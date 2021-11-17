#ifndef capteur_mouvement_H
#define capteur_mouvement_H

#include<QtSerialPort/QtSerialPort>
#include<QtSerialPort/QSerialPortInfo>
class capteur_mouvement
{
public:
    capteur_mouvement();
    int connect_capteur_mouvement();
    int close_capteur_mouvement();
    int write_to_capteur_mouvement( QByteArray);

    QByteArray read_from_capteur_mouvement();
    QSerialPort* getserial();
    QString get_capteur_mouvement_port_name();
    /***********************/
private :
    QSerialPort *serial;
    static const quint16 arduino_uno_vendor_id=9025;
    static const quint16 arduino_uno_product_id=67;
    QString arduino_port_name;
    bool arduino_is_available;
    QByteArray dat;

};

#endif // capteur_mouvement_H
