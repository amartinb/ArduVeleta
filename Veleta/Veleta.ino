/*
 * Proyecto Veleta
 * Alfonso Martin, 2016
 * 
 * Basaddo en un rotary encoder, un arduino
 * Version 0.1   Prueba del encoder, salida serial al PC 
 * Version 0.2   Añadir pantalla LCD
 * 
 */
//#include "NokiaLCD.h"


// Setup del LCD
//NokiaLCD NokiaLCD(3,4,5,6,7); // (SCK, MOSI, DC, RST, CS)
// Pines de lectura del encoder
int a = 9;
int b = 8;
// Valores de medida
int anterior = 1;
int contador;
char texto[10];

int pinA = 9;  // Connected to CLK on KY-040
int pinB = 8;  // Connected to DT on KY-040
int encoderPosCount = 0; 
int pinALast;  
int aVal;
int bVal;
int aLast;
int bLast;
int encoderCount = 0;
boolean bCW;
boolean cambio;
 
void setup()
{
  // Inicializamos el LCD
//  NokiaLCD.init();
//  NokiaLCD.clear();

// initialize serial communication at 9600 bits per second:
Serial.begin(9600);
 
  // Inicializamos la lectura del encoder
  pinMode(a, INPUT);
  pinMode(b, INPUT);

  pinALast = digitalRead(pinA);
  aLast = digitalRead(pinA);
 
  // Inicializamos las variables
  anterior = 1;
  contador = 0;
  Serial.println("Preparado");
//  escribir();
}
 
void loop()
{
   /* Codigo original del sketch pero no va muy bien
  // Lectura de A, si es 0, volvemos a medir para asegurar el valor
  int actual = digitalRead(a);
  if(actual == 0) {
    delay(10);
    actual = digitalRead(a);
  }
 
  // Actuamos únicamente en el flanco descendente
  if(anterior == 1 && actual == 0)
  {
    int valor_b = digitalRead(b);
    if(valor_b == 1) contador++;  // Si B = 1, aumentamos el contador
    else contador--;  // Si B = 0, reducimos el contador
    escribir();  // Escribimos el valor en pantalla
  }
  anterior = actual;

  */
  // Codigo amb simple
  
  aVal = digitalRead(pinA);
  bVal = digitalRead(pinB);
  if(aVal == 0) {
    delay(10);
    aVal = digitalRead(pinA);
    bVal = digitalRead(pinB);
  }
  if ((aVal != aLast) || (bVal != bLast)){
    Serial.print(aVal);
    Serial.print(" ");
    Serial.println(bVal);
    Serial.println("-------");
    if ((aVal==1)&&(bVal==1)){
      encoderPosCount++;
      if (encoderPosCount>24){
        encoderPosCount = 0;
      }
    }
    Serial.println(encoderPosCount);
    Serial.println(".......");
    aLast = aVal;
    bLast = bVal;
  }


/* Version con rebotes
   aVal = digitalRead(pinA);
   if (aVal != pinALast){ // Means the knob is rotating
     // if the knob is rotating, we need to determine direction
     // We do that by reading pin B.
     if (digitalRead(pinB) != aVal) {  // Means pin A Changed first - We're Rotating Clockwise
       encoderPosCount ++;
       bCW = true;
     } else {// Otherwise B changed first and we're moving CCW
       bCW = false;
       encoderPosCount--;
     }
     */

    
/*
     // Otra version para evitar rebotes en vias de mejorar
    aVal = digitalRead(pinA);
    bVal = digitalRead(pinB);
    if (aVal == LOW){     //¿Evito rebotes?
      delay(10);
      aVal = digitalRead(pinA);
      bVal = digitalRead(pinB);
    }
    cambio = false;
    if ((aVal != aLast)&&(aVal==LOW)) { // Knob Rotated l when aVal changes, BUT use only if aVal is LOW.
      if(bVal == LOW){ 
        bCW = true;
        cambio = true;
        encoderCount++;
        }else {
          cambio = true;
          bCW = false;
          encoderCount--;
          }
    }
    aLast = aVal; // Don’t forget this

     if (cambio){
     Serial.print ("Rota: ");
     if (bCW){
       Serial.println ("anti horario");
     }else{
       Serial.println("horario");
     }
     Serial.print("Posicion: ");
     Serial.println(encoderCount);
     }
     
*/
}

 /*
//Escribir en la salida serie del PC
void escribir()
{
  String s = String(contador);  // Convertimos el número en texto
  s.toCharArray(texto, 10);  // Convertimos el texto en un formato compatible
  Serial.println("Volumen:");
  Serial.println(texto);
}


// Esta función escribe en el LCD el valor de
// la variable "contador"
void escribir()
{
  String s = String(contador);  // Convertimos el número en texto
  s.toCharArray(texto, 10);  // Convertimos el texto en un formato compatible
  NokiaLCD.clear();
  NokiaLCD.setCursor(3,2);
  NokiaLCD.print("Volumen:");
  NokiaLCD.setCursor(64,2);
  NokiaLCD.print(texto);
}
*/
