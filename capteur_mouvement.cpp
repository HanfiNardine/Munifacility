#include "capteur_mouvement.h"
#include<QSerialPort>
capteur_mouvement::capteur_mouvement()
{
    dat;
    arduino_port_name = "" ;
    arduino_is_available = false;
    serial = new QSerialPort;

}
int capteur_mouvement::connect_capteur_mouvement()
{   // recherche du port sur lequel la carte arduino identifée par  arduino_uno_vendor_id
    // est connectée
    foreach (const QSerialPortInfo &serial_port_info, QSerialPortInfo::availablePorts()){
           if(serial_port_info.hasVendorIdentifier() && serial_port_info.hasProductIdentifier()){
               if(serial_port_info.vendorIdentifier() == arduino_uno_vendor_id && serial_port_info.productIdentifier()
                       == arduino_uno_product_id) {
                   arduino_is_available = true;
                   arduino_port_name=serial_port_info.portName();
               } } }
        qDebug() << "arduino_port_name is :" << arduino_port_name;

        if(arduino_is_available){ // configuration de la communication ( débit...)

           serial->setPortName(arduino_port_name);

            //qDebug()<<arduino_port_name;

            if(serial->open(QSerialPort::ReadWrite)){
                serial->setBaudRate(QSerialPort::Baud9600); // débit : 9600 bits/s
                serial->setDataBits(QSerialPort::Data8); //Longueur des données : 8 bits,
                serial->setParity(QSerialPort::NoParity); //1 bit de parité optionnel
                serial->setStopBits(QSerialPort::OneStop); //Nombre de bits de stop : 1
                serial->setFlowControl(QSerialPort::NoFlowControl);

                return 0;

            }
            return 1;
        }
        return -1;
}
int capteur_mouvement::close_capteur_mouvement()
{
    if(serial->isOpen())
    {
        serial->close();
        return 0;

    }
    return 1;
}

 QByteArray capteur_mouvement:: read_from_capteur_mouvement()
{
     if(serial-> isReadable())
     {
         dat=serial->readAll();
         return dat;
     }

 }
  QString capteur_mouvement::get_capteur_mouvement_port_name()
  {
      return arduino_port_name;
  }
    QSerialPort* capteur_mouvement:: getserial()
    {
        return serial;
    }

    int capteur_mouvement::write_to_capteur_mouvement( QByteArray d)

    {

        if(serial->isWritable()){
            serial->write(d);  // envoyer des donnés vers arduino
           qDebug()<<d;;

        }else{
            qDebug() << "Couldn't write to serial!";
        }


    }

