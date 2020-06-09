


#include "Arduino.h"
#include "VrtSim800l.h"
#include <SoftwareSerial.h>


VrtSim800l::VrtSim800l(void) : SoftwareSerial(DEFAULT_RX_PIN, DEFAULT_TX_PIN)
{
    RX_PIN 		= DEFAULT_RX_PIN;
    TX_PIN 		= DEFAULT_TX_PIN;
   
}

VrtSim800l::VrtSim800l(uint8_t rx, uint8_t tx) : SoftwareSerial(rx, tx)
{
    RX_PIN 		= rx;
    TX_PIN 		= tx;
   
}

void VrtSim800l::begin(){

    _baud = DEFAULT_BAUD_RATE;

    this->SoftwareSerial::begin(_baud);

}

void VrtSim800l::begin(uint32_t baud){

    _baud = baud;

    this->SoftwareSerial::begin(baud);

}

boolean VrtSim800l::isOperator(){

   this->SoftwareSerial::print("AT\r");

    if(_serialRead().indexOf("OK")){
        return true;
    }else
    {
        return false;
    }
}


//Gets

String VrtSim800l::getImei(){

     this->SoftwareSerial::print("AT+CGSN\r");

     return _serialRead();

}

String VrtSim800l::getIntensitySignal(){

     this->SoftwareSerial::print("AT+CSQ\r");

     return _serialRead();

}



String VrtSim800l::isRegistered(){

    this->SoftwareSerial::print("AT+CREG?\r");

     return _serialRead();

}






















String VrtSim800l:: _serialRead(){

  
   String str;

   
    delay(500);
    while (this->SoftwareSerial::available())
    {
       str += (char) this->SoftwareSerial::read();
    }
    
    return str;


}

