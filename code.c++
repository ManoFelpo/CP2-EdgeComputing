#include <LiquidCrystal.h>

#define SENSOR_TEMP A1
#define SENSOR_UMI  A0
#define SENSOR_LDR  A2
#define BUZZER      9
#define LED_VERM  10
#define LED_VERD  13
#define LED_AMAR  8

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

unsigned long tempoAnterior = 0;
const unsigned long intervalo = 5000;

float mediaLeitura(int pino) {
  int soma = 0;
  for (int i = 0; i < 5; i++) {
    soma += analogRead(pino);
    delay(50);
  }
  return soma / 5.0;
}

void setup() {
  lcd.begin(16, 2);
  pinMode(BUZZER, OUTPUT);
  pinMode(LED_VERM, OUTPUT);
  pinMode(LED_VERD, OUTPUT);
  pinMode(LED_AMAR, OUTPUT);
  pinMode(SENSOR_TEMP, INPUT);
  pinMode(SENSOR_UMI, INPUT);
  pinMode(SENSOR_LDR, INPUT);

  Serial.begin(9600);
}

void loop() {
  unsigned long tempoAtual = millis();
  if (tempoAtual - tempoAnterior >= intervalo) {
    tempoAnterior = tempoAtual;

    float leituraTemp = mediaLeitura(SENSOR_TEMP);
    float leituraUmi  = mediaLeitura(SENSOR_UMI);
    float leituraLuz  = mediaLeitura(SENSOR_LDR);

    float temperatura = 5.0 + ((leituraTemp - 11.0) * (15.0 / (112.0 - 11.0)));
    int umidade = map(leituraUmi, 200, 800, 0, 100);
    umidade = constrain(umidade, 0, 100);
    float luminosidadeLux = (1023.0 - leituraLuz) * (500.0 / 1023.0);

    Serial.print("\nTemperatura: "); Serial.println(temperatura);
    Serial.print("Umidade: "); Serial.print(umidade); Serial.println(" %");
    Serial.print("Luminosidade: "); Serial.print(luminosidadeLux, 0); Serial.println(" lux");

    if (luminosidadeLux > 168 && luminosidadeLux < 297) {
      lcd.clear();
      lcd.print("Ambiente a meia");
      lcd.setCursor(0, 1);
      lcd.print("luz");
      digitalWrite(LED_AMAR, HIGH);
      delay(1000);
      digitalWrite(LED_AMAR, LOW);
      noTone(BUZZER);

    } else if (luminosidadeLux > 297) {
      lcd.clear();
      lcd.print("Ambiente muito");
      lcd.setCursor(0, 1);
      lcd.print("CLARO");
      digitalWrite(LED_VERM, HIGH);
      delay(1000);
      digitalWrite(LED_VERM, LOW);
      tone(BUZZER, 500);

    } else if (temperatura < 10) {
      lcd.clear();
      lcd.print("Temp. BAIXA");
      lcd.setCursor(0, 1);
      lcd.print("Temp. = "); lcd.print(temperatura); lcd.print("C");
      digitalWrite(LED_AMAR, HIGH);
      delay(1000);
      digitalWrite(LED_AMAR, LOW);
      tone(BUZZER, 500);

    } else if (temperatura > 15) {
      lcd.clear();
      lcd.print("Temp. ALTA");
      lcd.setCursor(0, 1);
      lcd.print("Temp. = "); lcd.print(temperatura); lcd.print("C");
      digitalWrite(LED_AMAR, HIGH);
      delay(1000);
      digitalWrite(LED_AMAR, LOW);
      tone(BUZZER, 500);

    } else if (umidade < 50) {
      lcd.clear();
      lcd.print("Umidade BAIXA");
      lcd.setCursor(0, 1);
      lcd.print("Umidade = "); lcd.print(temperatura); lcd.print("%");
      digitalWrite(LED_VERM, HIGH);
      delay(1000);
      digitalWrite(LED_VERM, LOW);
      tone(BUZZER, 500);

    } else if (umidade > 70) {
      lcd.clear();
      lcd.print("Umidade ALTA");
      lcd.setCursor(0, 1);
      lcd.print("Umidade = "); lcd.print(temperatura); lcd.print("%");
      digitalWrite(LED_VERM, HIGH);
      delay(1000);
      digitalWrite(LED_VERM, LOW);
      tone(BUZZER, 500);

    } else {
      noTone(BUZZER);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Temperatura OK");
      lcd.setCursor(0, 1);
      lcd.print("Temp. = "); lcd.print(temperatura); lcd.print("C");
      digitalWrite(LED_VERD, HIGH);
      delay(3000);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Umidade OK");
      lcd.setCursor(0, 1);
      lcd.print("Umidade = "); lcd.print(temperatura); lcd.print("%");
      digitalWrite(LED_VERD, LOW);
      noTone(BUZZER);
    }
  }
} 
