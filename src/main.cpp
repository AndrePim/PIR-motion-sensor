#include <Arduino.h>

int ledPin = 13;  // Пин для светодиода
int analog = 500; // Пороговое значение для срабатывание датчика

void setup() {
  Serial.begin(9600);      // Инициализация последовательного соединения и задание скорости передачи данных в бит/с(бод)
  pinMode(ledPin, OUTPUT); // Установка режима работы пина светодиода на выход
}

void loop() {
  // Сравнение значения с порта А0 с пороговым значением
  if (analogRead(A0) > analog) {
    Serial.println("Motion detected!"); // Вывод надписи в мониторе последовательного порта
    digitalWrite(ledPin, HIGH);         // Загорается светодиод
  }
  else {
    Serial.println("Motion stopped!"); // Вывод надписи в мониторе последовательного порта
    digitalWrite(ledPin, LOW);         // Светодиод не горит
  }
}