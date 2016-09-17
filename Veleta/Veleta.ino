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
 
void setup()
{
  // Inicializamos el LCD
//  NokiaLCD.init();
//  NokiaLCD.clear();
 
  // Inicializamos la lectura del encoder
  pinMode(a, INPUT);
  pinMode(b, INPUT);
 
  // Inicializamos las variables
  anterior = 1;
  contador = 0;
  escribir();
}
 
void loop()
{
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
}

//Escribir en la salida serie del PC
void escribir()
{
}
 /*
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
