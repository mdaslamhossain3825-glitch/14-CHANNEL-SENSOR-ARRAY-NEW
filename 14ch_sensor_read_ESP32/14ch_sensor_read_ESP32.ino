// Define control pins for the multiplexer
#define S0 27        //13//11
#define S1 26       //12//10
#define S2 25       //14//8
#define S3 33       //27//7
#define SIG_PIN 32  //26//A7  // Define the signal pin connected to the multiplexer (SIG)
#define sensorNumber 14
uint16_t sensor[sensorNumber];
uint16_t reference[sensorNumber]={};
//
void setup() {
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(SIG_PIN, INPUT);
  Serial.begin(115200);
}
//
void loop() {
  analogValue();
  //digitalValue();
  }
//
void selectChannel(int channel) {
  digitalWrite(S0, bitRead(channel, 0));digitalWrite(S1, bitRead(channel, 1));
  digitalWrite(S2, bitRead(channel, 2));digitalWrite(S3, bitRead(channel, 3));
}
//
void analogValue()
{for (unsigned char i=0;i<sensorNumber;i++) {selectChannel(i);sensor[i] = analogRead(SIG_PIN);
  Serial.print(String(sensor[i]) + "  ");}Serial.println();}
//
void digitalValue(){
  for (unsigned char i=0;i<sensorNumber;i++) {selectChannel(i);sensor[i] = analogRead(SIG_PIN);
  if(sensor[i]>reference[i]){sensor[i]=1;}else{sensor[i]=0;}
  Serial.print(String(sensor[i]) + "  ");}Serial.println();
}
