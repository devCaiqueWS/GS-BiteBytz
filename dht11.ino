#include <LiquidCrystal.h>
#include <DHT.h>

const int pinoRS = 11;
const int pinoE = 10;
const int pinoD4 = 7;
const int pinoD5 = 6;
const int pinoD6 = 5;
const int pinoD7 = 4;

const int pinoGreenLED = 0;
const int pinoYellowLED = 12;
const int pinoRedLED = 13;
const int pinoBuzzer = 2;

const int pinoDHT = 3;
DHT dht(pinoDHT, DHT11);

LiquidCrystal lcd(pinoRS, pinoE, pinoD4, pinoD5, pinoD6, pinoD7);

void setup() {
  Serial.begin(9600);

  lcd.begin(16, 2);

  pinMode(pinoGreenLED, OUTPUT);
  pinMode(pinoYellowLED, OUTPUT);
  pinMode(pinoRedLED, OUTPUT);
  pinMode(pinoBuzzer, OUTPUT);

  dht.begin();

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Inicializando...");
}

void loop() {
  float valorHumidade = dht.readHumidity();
  float valorTemp = dht.readTemperature();

  lcd.clear();

  Serial.print("Humidade: ");
  Serial.print(valorHumidade);
  Serial.print("%  ");
  Serial.print("Temperatura: ");
  Serial.print(valorTemp);
  Serial.println("C");

  lcd.setCursor(0, 0);
  lcd.print("Humidade: ");
  lcd.print(valorHumidade);
  lcd.print("%");
  if (valorHumidade < 25) {
    lcd.setCursor(0, 1);
    lcd.print("Risco a rolha");
  } else if (valorHumidade < 50) {
    lcd.setCursor(0, 1);
    lcd.print("+Humidade");
  } else if (valorHumidade < 75) {
    lcd.setCursor(0, 1);
    lcd.print("Humidade Certa");
  } else {
    lcd.setCursor(0, 1);
    lcd.print("Risco de bolor");
  }
  delay(2000);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(valorTemp);
  lcd.print(" C");
  if (valorTemp < 10) {
    lcd.setCursor(1, 1);
    lcd.print("Aumente a temp");
  } else if (valorTemp < 20) {
    lcd.setCursor(2, 1);
    lcd.print("Temp. ideal");
  } else if (valorTemp < 35) {
    lcd.setCursor(1, 1);
    lcd.print("Abaixe a temp");
  } else {
    lcd.setCursor(1, 1);
    lcd.print("Risco ao vinho");
  }
  delay(2000);

  delay(500);
}
