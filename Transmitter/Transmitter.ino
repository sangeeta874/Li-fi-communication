#define LED_PIN A1
#define PERIOD 15
char* string = "VLSI Minor Project 'Short Range Li-Fi Communication' Submitted to Dr.Vaibhav Neema, by Group 1 E&TC'A'.";
int string_length;
void setup()
{
pinMode(LED_PIN, OUTPUT);
string_length = strlen(string);
}
void loop()
{
  for(int i = 0; i < string_length; i ++)
    send_byte(string[i]);
  delay(1000);
}
void send_byte(char my_byte)
{
  digitalWrite(LED_PIN, LOW);
  delay(PERIOD);
  for(int i = 0; i < 8; i++)                //transmission of bits
  {
    digitalWrite(LED_PIN, (my_byte&(0x01 << i))!=0 );
    delay(PERIOD);
  }
  digitalWrite(LED_PIN, HIGH);
  delay(PERIOD);
}
