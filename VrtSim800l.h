/*

  VrtSim800l.h
  Autor: Dev. Carlos Aires
  Abril de 2020


*/

#ifndef VrtSim800l_h
#define VrtSim800l_h


#include <SoftwareSerial.h>
#include "Arduino.h"

//Valores padrões caso o usuario nao informe nehum
#define DEFAULT_RX_PIN     10
#define DEFAULT_TX_PIN    11
#define DEFAULT_BAUD_RATE    9600
#define TIME_OUT_READ_SERIAL  5000


//Classe
class VrtSim800l : public  SoftwareSerial
{
  public:

    //Pinos RX e TX
    uint8_t  RX_PIN;
    uint8_t  TX_PIN;

    //Contrutores
    VrtSim800l();
    VrtSim800l(uint8_t rx, uint8_t tx);
    
    //Metodos
    void begin();
    void begin(uint32_t baud);


    boolean isOperator();
    String  isRegistered();
    String getImei();
    String getIntensitySignal();
   









  private:

    uint32_t _baud;
    String _serialRead();
    String _serialRead(uint32_t timeout);















  
};


#endif