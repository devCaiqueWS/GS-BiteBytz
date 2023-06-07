#include <LiquidCrystal.h>


const int pinoRS = 11;
const int pinoE = 10;
const int pinoD4 = 7;
const int pinoD5 = 6;
const int pinoD6 = 5;
const int pinoD7 = 4;


const int pinoLDR = A0;
const int pinoSensorHumidade = A5;
const int pinoTemp = A3;
const int pinoGreenLED = 0;    
const int pinoYellowLED = 12;   
const int pinoRedLED = 13;     
const int pinoBuzzer = 2;

LiquidCrystal lcd(pinoRS, pinoE, pinoD4, pinoD5, pinoD6, pinoD7);

void setup() {
  
  Serial.begin(9600);

  
  lcd.begin(16, 2);

  
  pinMode(pinoGreenLED, OUTPUT);
  pinMode(pinoYellowLED, OUTPUT);
  pinMode(pinoRedLED, OUTPUT);
  pinMode(pinoBuzzer, OUTPUT);
  
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Inicializando...");
}

void loop() {
  
  int valorLDR = analogRead(pinoLDR);
  int valorSensorHumidade = analogRead(pinoSensorHumidade)/10.23;
  float valorTemp = analogRead(pinoTemp) * 0.48875; 
  lcd.clear();

  
  lcd.print("Luminosidade: ");
  lcd.println(valorLDR);
  if (valorLDR < 850) {
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("Luminosidade");
    lcd.setCursor(5, 1);
    lcd.print("ideal");    
    digitalWrite(pinoGreenLED, HIGH);
    digitalWrite(pinoYellowLED, LOW);
    digitalWrite(pinoRedLED, LOW);
  } else if (valorLDR < 960) {
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("Ambiente em");
    lcd.setCursor(3, 1);
    lcd.print("meia luz");   
    digitalWrite(pinoGreenLED, LOW);
    digitalWrite(pinoYellowLED, HIGH);
    digitalWrite(pinoRedLED, LOW);
  } else {
    lcd.clear();
    lcd.setCursor(3, 0);
    lcd.print("Ambiente");
    lcd.setCursor(5, 1);
    lcd.print("claro");   
    digitalWrite(pinoGreenLED, LOW);
    digitalWrite(pinoYellowLED, LOW);
    digitalWrite(pinoRedLED, HIGH);
    digitalWrite(pinoBuzzer, HIGH);
    delay(3000);
    digitalWrite(pinoBuzzer, LOW);
    delay(3000);
    
  }
  delay(2000);
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Humidade: ");
  lcd.print(valorSensorHumidade); 
  lcd.print("%");
  if (valorSensorHumidade<25){//As medidas foram adquiridas após pesquisas, da humidade ideal para manter um vinho de qualidade
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("Risco ao alimento");
    digitalWrite(pinoRedLED, HIGH);
    digitalWrite(pinoBuzzer, HIGH);
    delay(3000);
    digitalWrite(pinoBuzzer, LOW);
    delay(3000);
  }else if(valorSensorHumidade<50){
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("+Humidade");
  }else if(valorSensorHumidade<75){
    lcd.clear();
    lcd.setCursor(1, 1);
    lcd.print("Humidade Certa");
  }else{
    lcd.setCursor(0, 1);
    lcd.print("Risco de bolor");
    digitalWrite(pinoRedLED, HIGH);
    digitalWrite(pinoBuzzer, HIGH);
    delay(3000);
    digitalWrite(pinoBuzzer, LOW);
    delay(3000);
  }
  delay(2000);
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(valorTemp);
  lcd.print(" C");
  if (valorTemp<10){//As medidas foram adquiridas após pesquisas, da temperatura ideal para manter um vinho de qualidade
    lcd.clear();
    lcd.setCursor(1, 1);
    lcd.print("Aumente a temp");
    digitalWrite(pinoRedLED, HIGH);
    digitalWrite(pinoBuzzer, HIGH);
    delay(3000);
    digitalWrite(pinoBuzzer, LOW);
    delay(3000);
  }else if(valorTemp<20){
    lcd.clear();
    lcd.setCursor(2, 1);
    lcd.print("Temp. ideal");
  }else if (valorTemp<35){    
    lcd.clear();
    lcd.setCursor(1, 1);
    lcd.print("Abaixe a temp");
  }else{
    lcd.clear();
    lcd.setCursor(1, 1);
    lcd.print("Risco ao alimento");
    digitalWrite(pinoRedLED, HIGH);
    digitalWrite(pinoBuzzer, HIGH);
    delay(3000);
    digitalWrite(pinoBuzzer, LOW);
    delay(3000);
  }
  delay(2000);
  
delay(500);
}
