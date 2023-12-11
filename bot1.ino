/*
  ESP8266 Blink by Simon Peter
  Blink the blue LED on the ESP-01 module
  This example code is in the public domain

  The blue LED on the ESP-01 module is connected to GPIO1
  (which is also the TXD pin; so we cannot use Serial.print() at the same time)

  Note that this sketch uses LED_BUILTIN to find the pin with the internal LED
*/
#include <stdio.h>
#include <FastBot.h>

#define WIFI_SSID "123"
#define WIFI_PASS "123456789"
#define BOT_TOKEN "6847332421:AAFRB-59B4Hrtgx2ZyZUMMEsLKhvnhZFSSw"

#define a1 "В который раз собирается одна и та же компания. Все анекдоты уже рассказаны, поэтому в компании решают рассказывать анекдоты по номерам. Вот сидят они, перешучиваются:\n— Анекдот №325!\n— Ха-ха-ха!\n— Анекдот №719!\n— Ха-ха-ха!\n— Анекдот №18!\n— Ха-ха-ха!\n— Анекдот №133!\nМолчание…\n— Что такое? Анекдот №133!Молчание…\n— Чего вы это? Смешной же анекдот!\n— Понимаешь… Одни умеют рассказывать анекдоты, а другие — нет…"
#define a2 "Если у вас закончилась мазь от зуда,\n— Не спешите выбрасывать тюбик.\nЕго уголком очень удобно чесаться."
#define a3 "Цилечка, я по тебе так соскучился!\n— Сёмочка, мы же сегодня, таки уже хорошо виделись.\nЦилечка, у меня молодой организм,\n— Он таки может скучать по нескольку раз в день."

FastBot bot(BOT_TOKEN);
void setup() {
  connectWiFi();
  bot.attach(newMsg);
}
// обработчик сообщений
void newMsg(FB_msg& msg) {
  // отправить сообщение обратно
  if (msg.text == "анекдот 1") bot.sendMessage(a1, msg.chatID);
  else if (msg.text == "анекдот 2") bot.sendMessage(a2, msg.chatID);
  else if (msg.text == "анекдот 3") bot.sendMessage(a3, msg.chatID);
  else bot.sendMessage("Таких анекдотов не знаю", msg.chatID);  
}

void loop() {
  bot.tick();
}
void connectWiFi() {
  delay(2000);
  Serial.begin(115200);
  Serial.println();
  WiFi.begin(WIFI_SSID, WIFI_PASS);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    if (millis() > 15000) ESP.restart();
  }
  Serial.println("Connected");
}