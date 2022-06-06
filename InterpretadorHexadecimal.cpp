#include <string.h>

int valor, pinoledverm = 3;
char valorByte, valorByte2, valorByte3, hex2, hex3;

char geraHexa(char vByte)
{
  char hex;
  if(vByte >= '0' && vByte <= '9')
    hex = vByte - '0';  
  
  else if(vByte >= 'A' && vByte <= 'F')
    hex = vByte - 'A' + 10;
    
  return hex;
}

void setup() {
  // put your setup code here, to run once:
  pinMode(pinoledverm, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() == 3){
    
    valorByte = Serial.read();
    valorByte2 = Serial.read();
    valorByte3 = Serial.read();

    hex2 = geraHexa(valorByte2); 
    hex3 = geraHexa(valorByte3);

    valor = hex2*16+hex3;
    
    if(valorByte == '0')
      digitalWrite(pinoledverm, LOW); 
           
    if(valorByte == '1')
     analogWrite(pinoledverm, valor); 
      
  }
}