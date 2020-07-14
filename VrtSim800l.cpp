

#include "Arduino.h"
#include "VrtSim800l.h"
#include <SoftwareSerial.h>

VrtSim800l::VrtSim800l(void) : SoftwareSerial(DEFAULT_RX_PIN, DEFAULT_TX_PIN)
{
    RX_PIN = DEFAULT_RX_PIN;
    TX_PIN = DEFAULT_TX_PIN;
}

VrtSim800l::VrtSim800l(uint8_t rx, uint8_t tx) : SoftwareSerial(rx, tx)
{
    RX_PIN = rx;
    TX_PIN = tx;
}

void VrtSim800l::begin()
{

    _baud = DEFAULT_BAUD_RATE;

    this->SoftwareSerial::begin(_baud);
}

void VrtSim800l::begin(uint32_t baud)
{

    _baud = baud;

    this->SoftwareSerial::begin(baud);
}

boolean VrtSim800l::isOperator()
{

    this->SoftwareSerial::print("AT\r");

    if (_serialRead().indexOf("OK"))
    {
        return true;
    }
    else
    {
        return false;
    }
}

String VrtSim800l::statusRegistered()
{

    this->SoftwareSerial::print("AT+CREG?\r");

    String status = _serialRead();

    if (status.indexOf("1"))
    {
        return "connected";
    }
    else if (status.indexOf("5"))
    {
        return "roamming";
    }
    else
    {
        return "not conect";
    }
}

//Gets

String VrtSim800l::getImei()
{

    this->SoftwareSerial::print("AT+CGSN\r");

    return _serialRead();
}

String VrtSim800l::getIntensitySignal()
{

    this->SoftwareSerial::print("AT+CSQ\r");

    return _serialRead();
}

String VrtSim800l::getBattery()
{

    this->SoftwareSerial::print("AT+CBC\r");

    return _serialRead();
}

String VrtSim800l::getNumberCardSim()
{

    this->SoftwareSerial::print("AT+CCID\r");

    return _serialRead();
}

String VrtSim800l::getOperatorConnect()
{

    this->SoftwareSerial::print("AT+COPS?\r");

    return _serialRead();
}

String VrtSim800l::getListOperator()
{

    this->SoftwareSerial::print("AT+COPS=?\r");

    return _serialRead(5000);
}

String VrtSim800l::getUseVelocitySerial()
{
    this->SoftwareSerial::print("AT+IPR?\r");

    return _serialRead();
}

String VrtSim800l::getVelocityAvailable()
{

    this->SoftwareSerial::print("AT+IPR=?\r");

    return _serialRead();
};

String VrtSim800l::getFabricator()
{
    this->SoftwareSerial::print("AT+CGMI\r");

    return _serialRead();
}

//methods for read serial

String VrtSim800l::_serialRead()
{

    boolean status = false;
    String str;

    //   delay(500);

    while (status == false)
    {

        while (this->SoftwareSerial::available())
        {

            char word = this->SoftwareSerial::read();

            str += word;

            if (str.indexOf("OK")!=-1)
            {
                status = true;
            }
            
        }
    }

    return str;
}

