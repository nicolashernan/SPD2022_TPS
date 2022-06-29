// C++ code
//
//LiquidCrystal(rs, enable, d4, d5, d6, d7)
#include <LiquidCrystal.h>

LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

void setup()
{
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  
  lcd.begin(1,2);
  lcd.setCursor(3,1);
  lcd.print("_________");
  //Palabra secreta "ARGENTINA"
  lcd.setCursor(10,0);
  lcd.print("LP:***");
 
	
}
	//Letras en codigo Ascii (65 = A, 66 = B, 67 = C,...)
  	int letrasAscii = 65;
	//Botones
	int botonSubirLetraAntes = 0;
	int botonBajarLetraAntes = 0;
	int botonProbarLetraAntes = 0;
	int contadorVidas = 15;
	//Variables
	char letras;
	//Banderas
	int banderaVictoriaUno = 0;
	int banderaVictoriaDos = 0;
	int banderaVictoriaTres = 0;
	int banderaVictoriaCuatro = 0;
	int banderaVictoriaCinco = 0;
	int banderaVictoriaSeis = 0;
	int banderaVictoriaSiete = 0;
	int banderaFin = 0;
	
	//Variable Tiempo
	unsigned long tiempoAntes = 0;


void loop()
{ 
  int botonSubirLetraAhora = digitalRead(A0);
  unsigned long tiempoAhora = millis();
  
  //Boton Subir Letra
  if(botonSubirLetraAhora == 1 && botonSubirLetraAntes == 0 && banderaFin == 0)
  {
    letrasAscii++;
  }
  
  botonSubirLetraAntes = botonSubirLetraAhora;
  
   //Boton bajar Letra
  int botonBajarLetraAhora = digitalRead(A2);
  
  if(botonBajarLetraAhora == 1 && botonBajarLetraAntes == 0 && banderaFin == 0)
  {
    letrasAscii--;
  }
  
  botonBajarLetraAntes=botonBajarLetraAhora;
  
  //Cuando se llege a la letra Z (90) y se use el boton de
  //subir letra , la suigiente letra volvera a ser la A (65)
  //y lo mismo a la inversa.
  if(letrasAscii < 65)
  {
    letrasAscii = 90;
  }else if(letrasAscii >90){
  	letrasAscii = 65;
  }
  
  //Validar que el valor de letrasAscii pertenesca al valor
  //de una letra del abecedario.
  if(letrasAscii > 64 && letrasAscii < 91)
  {
    //Esta funcion convierte el valor de letrasAscii a la 
    //letra que represente su numero en el codigo Ascii
    	letras = String(letrasAscii).toInt();
  
   		lcd.setCursor(6,0); 
   		lcd.print(letras);
  }

  //Boton probrar letra
  int botonProbarLetraAhora = digitalRead(A1);
  
  if(botonProbarLetraAhora == 1 && botonProbarLetraAntes == 0 && banderaFin == 0)
  {
    switch(letras)
    {
      case 'A':
      	lcd.setCursor(3,1);
      	lcd.print(letras);
        lcd.setCursor(11,1);
      	lcd.print(letras);
      	banderaVictoriaUno = 1;
      break;
      case 'R':
      	lcd.setCursor(4,1);
      	lcd.print(letras);
      	banderaVictoriaDos = 1;
      break;
      case 'G':
      	lcd.setCursor(5,1);
      	lcd.print(letras);
      	banderaVictoriaTres = 1;
      break;
      case 'E':
       	lcd.setCursor(6,1);
      	lcd.print(letras);
     	banderaVictoriaCuatro = 1;
      break;
      case 'N':
      	lcd.setCursor(7,1);
      	lcd.print(letras);
        lcd.setCursor(10,1);
      	lcd.print(letras);
      	banderaVictoriaCinco = 1;
      break;
      case 'T':
       	lcd.setCursor(8,1);
      	lcd.print(letras);
      	banderaVictoriaSeis = 1;
      break;
      case 'I':
       	lcd.setCursor(9,1);
      	lcd.print(letras);
      	banderaVictoriaSiete = 1;
      break;
      default:
      	lcd.setCursor(contadorVidas,0);
      	lcd.print(" ");
      	contadorVidas--;
  	  break;
    } 
    
    //mensaje de que perdio
       if(contadorVidas==12 )
       {
          lcd.setCursor(0,0);
    	  lcd.print("                ");
          lcd.setCursor(0,1);
    	  lcd.print("                ");
          letrasAscii = 69;
          lcd.setCursor(2,0);
          lcd.print("-GAME OVER-");
          lcd.setCursor(3,1);
          lcd.print("ARGENTINA");
          banderaFin = 1;
          tiempoAntes = tiempoAhora;
       }
       
    //mensaje de que gano
        if( banderaVictoriaUno == 1 &&
            banderaVictoriaDos == 1 &&
            banderaVictoriaTres == 1 &&
            banderaVictoriaCuatro == 1 &&
            banderaVictoriaCinco == 1 &&
            banderaVictoriaSeis == 1 &&
            banderaVictoriaSiete == 1)
        {
              lcd.setCursor(0,0);
              lcd.print("                ");
              lcd.setCursor(0,1);
              lcd.print("                ");
              letrasAscii = 67;
              lcd.setCursor(3,0);
              lcd.print("-VICTORIA-");
              lcd.setCursor(3,1);
              lcd.print("ARGENTINA");
          	  banderaFin = 1;
          	  tiempoAntes = tiempoAhora;
        }
    
  }
  
   botonProbarLetraAntes=botonProbarLetraAhora;
  
  //El mensaje se muestra por 5 segundos y luego se reinicia
  //el juego con este if.
  if(banderaFin == 1 && tiempoAhora - tiempoAntes >= 5000)
  {
      contadorVidas  = 15;
      lcd.setCursor(0,0);
      lcd.print("                ");
      lcd.setCursor(0,1);
      lcd.print("                ");
      lcd.setCursor(3,1);
  	  lcd.print("_________");
  	  lcd.setCursor(10,0);
  	  lcd.print("LP:***");
   	  banderaVictoriaUno = 0;
	  banderaVictoriaDos = 0;
	  banderaVictoriaTres = 0;
	  banderaVictoriaCuatro = 0;
	  banderaVictoriaCinco = 0;
	  banderaVictoriaSeis = 0;
	  banderaVictoriaSiete = 0;
      banderaFin = 0;
      letrasAscii = 65;
  }
  

 
  //pueden quitar el delay, yo lo uso porque sino me corre lento el simulador
  delay(100);
}