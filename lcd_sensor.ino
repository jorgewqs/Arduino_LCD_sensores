/*

Display LCD com sensor de temperatura e Voltagem e um Chave de Estado.
Autor: Jorge Wendell
Email: jorgewqs@gmail.com

*/

// include the library code:
#include <LiquidCrystal.h>
#define Luz_Fundo 7

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int sensor = A0;
int chave = 8;

byte grau[8] = { 
  0b01110,
  0b01010,
  0b01110,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
};

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  pinMode(Luz_Fundo, OUTPUT);
  pinMode(chave, INPUT);
  digitalWrite(chave, HIGH);
  digitalWrite(Luz_Fundo, HIGH);

}

void loop() {
  
  int chaveEstado = digitalRead(chave);
  
  int readsensor = analogRead(sensor);
  float voltage = readsensor * 5.0/1023;
  float tempC = voltage * 100;
  
 if(chaveEstado == 1){
  
  lcd.setCursor(0, 0);
  lcd.print("Voltage   V");
  lcd.setCursor(0, 1);
  lcd.print("Tempo     C");
  lcd.createChar(1,grau);
  lcd.setCursor(12,0);
  lcd.print(voltage);
  lcd.setCursor(11,1);
  lcd.write(1);
  lcd.setCursor(12,1);
  lcd.print(tempC);
  delay(500);
 }
 if(chaveEstado == 0){
  // Print a message to the LCD.
  lcd.setCursor(0, 0);
  lcd.print("Jorge Wendell QS");
  lcd.setCursor(0, 1);
  lcd.print("  Arduino LAB!  ");
  delay(100);
 }
}
