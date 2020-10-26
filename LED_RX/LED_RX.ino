//code by Swayamshree Mohanty

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
byte msg[3];
RF24 radio(9, 10);
const uint64_t pipe = 0xE8E8F0F0E1LL;
int LED1 = 8;

void setup(void)
{
  Serial.begin(115200);
  radio.begin();
  radio.enableDynamicPayloads();
  radio.setRetries(5, 15);
  radio.openReadingPipe(1, pipe);
  radio.startListening();
  pinMode(LED1, OUTPUT);
}

void loop(void)
{
  if (radio.available())
  {
    radio.read(msg, 1);
    //Serial.println(msg[0]);
    
    if (msg[0] == 11) {
      delay(20);
      Serial.println("LED is ON");
      digitalWrite(LED1, HIGH);
    }
    else if (msg[0] == 10)
    {
      delay(20);
      Serial.println("LED is OFF");
      digitalWrite(LED1, LOW);
    }
  }
  else
  {
    delay(100);
    Serial.println("No Signal");
  }
}
