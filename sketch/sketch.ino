#include <Arduino_RouterBridge.h>
#include <IskakINO_LiquidCrystal_I2C.h>
#include <Modulino.h>

ModulinoButtons buttons;
LiquidCrystal_I2C lcd(20, 4);

volatile bool audioReady = false;

const char *radios[] = {
 "    ",
 "info",
  "rtl",
  "inter",
  "musique",
  "nostalgie",
  "mradio"
};

const uint8_t RADIO_COUNT = sizeof(radios) / sizeof(radios[0]);

int radioIndex;
uint8_t volume = 50;
bool radioRunning = true;

void audio() {
  audioReady = true;
}

void displayRadio()
{
  lcd.setCursor(0, 0);
  lcd.print("Radio :            ");
  lcd.setCursor(8, 0);

  if (radioRunning) {
    lcd.print(radios[radioIndex]);
  } else {
    lcd.print("arretee");
  }
}

void displayVolume()
{
  lcd.setCursor(0, 2);
  lcd.print("Volume :           ");
  lcd.setCursor(9, 2);
  lcd.print(volume);
  lcd.print("%");
}

void displayAll()
{
  displayRadio();
  displayVolume();
}

void playCurrentRadio()
{
  radioRunning = true;
  displayRadio();
  Bridge.notify("api_radio", radios[radioIndex]);
}

void nextRadio()
{
  if (radioRunning) {
    radioIndex++;

    if (radioIndex >= RADIO_COUNT) {
      radioIndex = 1;
    }
  }

  playCurrentRadio();
}

void nextVolume()
{
  if (!radioRunning) {
    return;
  }

  volume += 10;

  if (volume > 100) {
    volume = 0;
  }

  displayVolume();
  Bridge.notify("api_volume", volume);
}

void stopRadio()
{
  radioRunning = false;
  displayAll();
  Bridge.notify("api_stop");
}

void setup()
{
  Bridge.begin();
  Monitor.begin();

  Modulino.begin();
  buttons.begin();

  Bridge.provide("audio", audio);
  
  lcd.begin();
  lcd.backlight();

  radioIndex = 0;
  volume = 50;
  radioRunning = true;

  displayAll();
 
}

void loop()
{

  if (audioReady) {
    audioReady = false;
    lcd.setCursor(8, 0);
    lcd.print("OK");
     
}
  
  if (buttons.update()) {

    if (buttons.isPressed('A')) {
      nextRadio();
    }

    if (buttons.isPressed('B')) {
      nextVolume();
    }

    if (buttons.isPressed('C')) {
      stopRadio();
    }
  }
}
