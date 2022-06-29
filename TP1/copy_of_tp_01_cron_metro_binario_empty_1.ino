
/*
 *	Trabajo Práctico 1: Cronómetro Binario
 *
 *	Al iniciar la simulacion, todos los led deben comenzar apagados.
 *	Cada 1 segundo que transcurra, se deben encender los led
 *	de acuerdo al numero que representan.
 *
 *	Ejemplo:
 *   
 *	El numero 15 (0000001111) se representaria encendiendo los 
 *	leds AMARILLO y NARANJA.
 *	Al pasar al numero 16 (0000010000), se deben apagar todos 
 *	los led anteriores y encenderse uno de los leds VERDES. 
 *	Notese, en el ejemplo los 0 representan los led apagados 
 *	y los 1 los led encendidos). 
 *   
 *	-------------------------------------------------------
 *   
 *	Al presionarse el boton START, debe iniciar el cronometro.
 *	Volver a presionarlo hace que la secuencia se detenga. 
 *  (Como si se hubiese presionado pausa).
 *	Al presionarse el boton RESET, el cronometro
 *	debe reiniciarse y arrancar de 0.
 *
 *	Tip: Modularizar la función que controla el encendido de los 
 *	LEDS y de ser posible, todo el código para evitar repetir lineas lo mas posible.
 *  Usar millis para controlar el tiempo del contador para que el cambio de los 
 *	leds encendidos sea perceptible para el ojo humano y 
 *	documentar cada función creada en el código. 
 *	Un breve comentario que diga que es lo que hace esa función
 *  y de corresponder, que retorna).
*/

//##### Una Ayudita #####
//--- Defines ---//
#define ZERO_TO_HERO 0          //? To start the counter from 0
#define BUTTON_START 2
#define BUTTON_RESET 3
#define FIRST_LED 4             //? First pin of the leds
#define LAST_LED 13             //? Last pin of the leds
#define BASE_MILLI_SECONDS 1000 //? Secods expresed in miliseconds
#define MAX_SECONDS 1023        //! Max amount of secods to show
//--- End Defines ---//

// C++ code
//



void setup()
{
  pinMode(2,INPUT);
  pinMode(3, INPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  
  Serial.begin(9600);
}
	int botonStarAntes=0;
	int botonResetAntes=0;
	int contador = 0;
	unsigned long tiempoAntes = 0;
	int banderaStar;
	int valorBandera= 0;
	int banderaReset = 0;

void loop()
{
  unsigned long tiempoAhora = millis();
  
  int botonStarAhora = digitalRead(2);
  int botonResetAhora = digitalRead(3);
  
  if(botonStarAhora == 1 && botonStarAntes == 0)
  {
    valorBandera = !valorBandera;
    banderaStar = valorBandera;
  }
  botonStarAntes = botonStarAhora;
 
  if(botonResetAhora == 1 && botonResetAntes == 0)
  {
    banderaReset = 1;
  }
  botonResetAntes=botonResetAhora;
  
  if(banderaReset ==  1)
  {
    contador = 0;
    banderaReset = 0;
  }
  
  if(contador >1023)
  {
    banderaStar = apagarTodosLosLeds();
    contador = 0;
  }
  
  
  if(banderaStar == 1)
  {
      if(tiempoAhora - tiempoAntes >= 1000)
      {
        contador++;
        Serial.print("Segundo : ");
        Serial.print(contador);
        Serial.print(" | Binario : ");
        Serial.println(contador,BIN);
        tiempoAntes = tiempoAhora;
      }

		EncenderLeds(contador);
  }
	
  delay(50);
}

//FUNCION QUE APAGA TODOS LOS LEDS CUADNO LLEGE A  1024
int apagarTodosLosLeds()
{
  int bandera;
  
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
  digitalWrite(13, LOW);
  bandera = 0;
  
  return bandera;
}




//FUNCION QUE ENCIENDE Y APAGA LOS LEDS
void EncenderLeds(int bits)
{
  
   bits = bitRead(contador,0);
  
      if(bits == 1)
      {
        digitalWrite(4, HIGH);
      }else
      {
        digitalWrite(4, LOW);
      }
  
  bits = bitRead(contador,1);
  
      if(bits == 1)
      {
        digitalWrite(5, HIGH);
      }else
      {
        digitalWrite(5, LOW);
      }
  
   bits = bitRead(contador,2);
  
      if(bits == 1)
      {
        digitalWrite(6, HIGH);
      }else
      {
        digitalWrite(6, LOW);
      }
  
   bits = bitRead(contador,3);
  
      if(bits == 1)
      {
        digitalWrite(7, HIGH);
      }else
      {
        digitalWrite(7, LOW);
      }
  
   bits = bitRead(contador,4);
  
      if(bits == 1)
      {
        digitalWrite(8, HIGH);
      }else
      {
        digitalWrite(8, LOW);
      }
  
   bits = bitRead(contador,5);
  
      if(bits == 1)
      {
        digitalWrite(9, HIGH);
      }else
      {
        digitalWrite(9, LOW);
      }
  	
   bits = bitRead(contador,6);
  
      if(bits == 1)
      {
        digitalWrite(10, HIGH);
      }else
      {
        digitalWrite(10, LOW);
      }
  
     bits = bitRead(contador,7);
  
      if(bits == 1)
      {
        digitalWrite(11, HIGH);
      }else
      {
        digitalWrite(11, LOW);
      }
  
     bits = bitRead(contador,8);
  
      if(bits == 1)
      {
        digitalWrite(12, HIGH);
      }else
      {
        digitalWrite(12, LOW);
      }
  
     bits = bitRead(contador,9);
  
      if(bits == 1)
      {
        digitalWrite(13, HIGH);
      }else
      {
        digitalWrite(13, LOW);
      }
}


