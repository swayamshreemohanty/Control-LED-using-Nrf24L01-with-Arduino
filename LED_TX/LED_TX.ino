//Code by Swayamshree Mohanty

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
byte msg[3];
RF24 radio(9, 10); //SPI BUS
const uint64_t pipe = 0xE8E8F0F0E1LL;
int SW1 = 7; //switch initialization

void setup(void) {
  Serial.begin(115200);
  radio.begin();
  radio.setDataRate(RF24_250KBPS); //transfer speed
  radio.enableDynamicPayloads();
  radio.setRetries(5, 15);
  radio.openWritingPipe(pipe);
}

void loop(void)
{
  if (digitalRead(SW1) == HIGH)
  {
    Serial.println(F("This is ON condition"));
    msg[0] = 11;
    radio.write(msg, 1);
  }
  else
  {
    Serial.println(F("This is OFF condition"));
    msg[0] = 10;
    radio.write(msg, 1);
  }
  delay(10);
}
