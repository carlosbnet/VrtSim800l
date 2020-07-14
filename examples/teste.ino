
#include <VrtSim800l.h>

VrtSim800l sim800(11,10);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  sim800.begin();

}

void loop() {
  Serial.println("------------Inicio-----------");
  Serial.println(sim800.getNumberCardSim());
  Serial.println("------------Fim-----------");
  

}