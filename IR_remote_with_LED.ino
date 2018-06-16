#include <Servo.h>

#include <IRremote.h>

int RECV_PIN = 2;
IRrecv irrecv(RECV_PIN);
decode_results results;

#define BUTTON_1 0xFF807F
#define BUTTON_2 0xFF40BF
#define BUTTON_3 0xFFC03F
#define BUTTON_4 0xFF20DF
#define BUTTON_5 0xFFA05F
#define BUTTON_6 0xFF609F
#define BUTTON_ON 0xFFD02F
#define BUTTON_OK 0xFF7887


int blue_LED = 7;
int red_LED = 6;
int green_LED = 5;

Servo amine;
void setup()
{
  amine.attach(3);
  pinMode(blue_LED, OUTPUT);
  pinMode(red_LED, OUTPUT);
  pinMode(green_LED, OUTPUT);
  
  irrecv.enableIRIn();
}
void loop() {

  if (irrecv.decode(&results))
  {
    if (results.value == BUTTON_OK)
    {
      digitalWrite(blue_LED, LOW);
      digitalWrite(red_LED, LOW);
      digitalWrite(green_LED, LOW);
    }
    if (results.value == BUTTON_ON)
    {
      digitalWrite(blue_LED, HIGH);
      digitalWrite(red_LED, HIGH);
      digitalWrite(green_LED, HIGH);
    }
    if (results.value == BUTTON_1)
    {
      digitalWrite(blue_LED, HIGH);
    }
    if (results.value == BUTTON_2)
    {
      digitalWrite(red_LED, HIGH);
    }
    if (results.value == BUTTON_3)
    {
      digitalWrite(green_LED, HIGH);
    }
    if (results.value == BUTTON_4)
    {
      amine.write(180);
    }
    if (results.value == BUTTON_5)
    {
      amine.write(0);
    }
    if (results.value == BUTTON_6)
    {
      for(int i = 0; i<=180 ; i++){
        amine.write(i);
        delay(15);
        }
    }
    irrecv.resume();
  }
}
