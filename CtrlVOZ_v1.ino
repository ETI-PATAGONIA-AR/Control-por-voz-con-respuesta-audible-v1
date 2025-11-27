//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//Ejemplo: Ctrl VOZ con respuesta audible - prof.martintorres@educ.ar - ETI Patagonia
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
#include <SoftwareSerial.h>
#include "VoiceRecognitionV3.h"
#include <SimpleSDAudio.h>
/**
  Connection
  Arduino    VoiceRecognitionModule
   2   ------->     TX
   3   ------->     RX
*/
VR myVR(2, 3);   // 2:RX 3:TX, you can choose your favourite pins.

uint8_t records[7]; // save record
uint8_t buf[64];

int Ralarma = 5;
int Rcocina = 6;
int Rcomedor = 7;
int Rliving = 8;
//int Rdesactivar = 9;

#define encender   (0)
#define apagar     (1)
#define alarma     (2)
#define cocina     (3)
#define comedor    (4)
#define living     (5)
#define desactivar (6)

void printSignature(uint8_t *buf, int len)
{
  int i;
  for (i = 0; i < len; i++) {
    if (buf[i] > 0x19 && buf[i] < 0x7F) {
      Serial.write(buf[i]);
    }
    else {
//      Serial.print("[");
//      Serial.print(buf[i], HEX);
//      Serial.print("]");
    }
  }
}

void printVR(uint8_t *buf)
{
 // Serial.println("VR Index\tGroup\tRecordNum\tSignature");

 // Serial.print(buf[2], DEC);
 // Serial.print("\t\t");

  if (buf[0] == 0xFF) {
//    Serial.print("NONE");
  }
  else if (buf[0] & 0x80) {
 //   Serial.print("UG ");
 //   Serial.print(buf[0] & (~0x80), DEC);
  }
  else {
 //   Serial.print("SG ");
 //   Serial.print(buf[0], DEC);
  }
//  Serial.print("\t");

//  Serial.print(buf[1], DEC);
//  Serial.print("\t\t");
  if (buf[3] > 0) {
    printSignature(buf + 4, buf[3]);
  }
  else {
//    Serial.print("NONE");
  }
//  Serial.println("\r\n");
}

void setup(void) {
  /** initialize */
myVR.begin(9600);
 Serial.begin (115200);//Velocidad del puerto serial
  // SdPlay.setSDCSPin(10); // Habilitar SÓLO si su tarjeta SD no está en el pin número 4
 SdPlay.init(SSDA_MODE_HALFRATE | SSDA_MODE_MONO | SSDA_MODE_AUTOWORKER);

 Serial.println("-LISTO!-");


  pinMode(Ralarma, OUTPUT);
  pinMode(Rcocina, OUTPUT);
  pinMode(Rcomedor, OUTPUT);
  pinMode(Rliving, OUTPUT);
  //pinMode(Rdesactivar, OUTPUT);


////////////////////////////////////////////

  if (myVR.clear() == 0) {
    Serial.println("Comandos cargados:");
  } else {
 //   Serial.println("No se encuentra el modulo de reconocimiento de voz V3");
 //   Serial.println("Por favor verificar la conexion y haga reset del equipo");
    while (1);
  }

 if (myVR.load((uint8_t)encender) >= 0) {
  //  Serial.println("encender");

  }

   if (myVR.load((uint8_t)apagar) >= 0) {
  //  Serial.println("apagar");

  }
 
  if (myVR.load((uint8_t)alarma) >= 0) {
   // Serial.println("alarma");

  }

  if (myVR.load((uint8_t)cocina) >= 0) {
   // Serial.println("cocina");

  }

  if (myVR.load((uint8_t)comedor) >= 0) {
    //Serial.println("comedor");

  }

  if (myVR.load((uint8_t)living) >= 0) {
    //Serial.println("living");

  }

 if (myVR.load((uint8_t)desactivar) >= 0) {
    //Serial.println("desactivar");
 }
}

void loop()
{
  int ret;
  ret = myVR.recognize(buf, 50);
  if (ret > 0) {
    switch (buf[1]) {
      case alarma:
        if (digitalRead(Ralarma) == 0) {
          digitalWrite(Ralarma, HIGH);
          Serial.println("Alarma Encendida");
          SdPlay.setFile("alari.wav");//con setFile vamos a cargar el archivo que queremos reproducir
          SdPlay.play(); // play reproduciomos el archivo
          delay(1400);
          SdPlay.stop();
             }
        else {
          digitalWrite(Ralarma, LOW);
          Serial.println("Alarma Apagada");
          SdPlay.setFile("alaro.wav");//con setFile vamos a cargar el archivo que queremos reproducir
          SdPlay.play(); // play reproduciomos el archivo
          delay(1400);
          SdPlay.stop();
             }
        break;
       case cocina:
        if (digitalRead(Rcocina) == 0) {
          digitalWrite(Rcocina, HIGH);
          Serial.println("Iluminacion Cocina Encendida");
          SdPlay.setFile("lucesi.wav");//con setFile vamos a cargar el archivo que queremos reproducir
          SdPlay.play(); // play reproduciomos el archivo
          delay(1400);
          SdPlay.stop();
             }
        else {
          digitalWrite(Rcocina, LOW);
          Serial.println("Iluminacion Cocina Apagada");
          SdPlay.setFile("luceso.wav");//con setFile vamos a cargar el archivo que queremos reproducir
          SdPlay.play(); // play reproduciomos el archivo
          delay(1400);
          SdPlay.stop();
             }
break;
       case comedor:
        if (digitalRead(Rcomedor) == 0) {
          digitalWrite(Rcomedor, HIGH);
          Serial.println("Iluminacion Comedor Encendida");
          SdPlay.setFile("lucesi.wav");//con setFile vamos a cargar el archivo que queremos reproducir
          SdPlay.play(); // play reproduciomos el archivo
          delay(1400);
          SdPlay.stop();
             }
        else {
          digitalWrite(Rcomedor, LOW);
          Serial.println("Iluminacion Comedor Apagada");
          SdPlay.setFile("luceso.wav");//con setFile vamos a cargar el archivo que queremos reproducir
          SdPlay.play(); // play reproduciomos el archivo
          delay(1400);
          SdPlay.stop();
               
         }
break;
       case living:
        if (digitalRead(Rliving) == 0) {
          digitalWrite(Rliving, HIGH);
          Serial.println("Iluminacion Living Encendida");
          SdPlay.setFile("lucesi.wav");//con setFile vamos a cargar el archivo que queremos reproducir
          SdPlay.play(); // play reproduciomos el archivo
          delay(1400);
          SdPlay.stop();
             }
        else {
          digitalWrite(Rliving, LOW);
          Serial.println("Iluminacion Living Apagada");
          SdPlay.setFile("luceso.wav");//con setFile vamos a cargar el archivo que queremos reproducir
          SdPlay.play(); // play reproduciomos el archivo
          delay(1400);
          SdPlay.stop();
            }
break;


         /**case desactivar:
        if (digitalRead(foco2) == 0) {
          digitalWrite(foco2, HIGH);
          Serial.println("Foco2 encendido ;)");
          tmrpcm.play("3.wav");
        }
        else {
          digitalWrite(foco2, LOW);
          Serial.println("Foco2 Apagado ;)");
        }

        break;

      default:
        Serial.println("Record function undefined");
        break;
    }
*/
    /** voice recognized */
    printVR(buf);
  }
}
}