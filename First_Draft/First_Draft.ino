//Library imports

//Pin definitions on an Arduino MEGA2560
const int DFF=2;
const int DFR=3;
const int DRF=4;
const int DRR=5;
const int PFF=6;
const int PFR=7;
const int PRF=8;
const int PRR=9;
const int BMF=10;
const int BMR=11;
const int Data=12;
//Method Definitions
void Command_Parse(char data);
void Stop();
void Forward();
void Reverse();
void Left();
void Right();
void Blade_Start();
void Blade_Stop();


void setup() {
  Serial.begin(115200);
  pinMode(DFF, OUTPUT);
  pinMode(DFR, OUTPUT);
  pinMode(DRF, OUTPUT);
  pinMode(DRR, OUTPUT);
  pinMode(PFF, OUTPUT);
  pinMode(PFR, OUTPUT);
  pinMode(PRF, OUTPUT);
  pinMode(PRR, OUTPUT);
  pinMode(BMF, OUTPUT);
  pinMode(BMR, OUTPUT);
  pinMode(Data, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  while (Serial.available() == 0) {
  }
  char data_rcvd = Serial.read();   // read one byte from serial buffer and save to data_rcvd
  Command_Parse(data_rcvd);
}

void Command_Parse(char data){
  switch(data){
    case '0':
      Serial.print("Stop\n");
      Stop();
    break;
    case '1':
      Serial.print("Forward\n");
      Forward();
    break;
    case '2':
      Serial.print("Reverse\n");
      Reverse();
    break;
    case '3':
      Serial.print("Left\n");
      Left();
    break;
    case '4':
      Serial.print("Right\n");
      Right();
    break;
    case '5':
      Serial.print("Blade_Start\n");
      Blade_Start;
    break;
    case '6':
      Serial.print("Blade_Stop\n");
      Blade_Stop();
    break;
    default:
      Serial.print("I am in the default for some reason\n");
    break;
  }
  return;
}

void Forward(){
  digitalWrite(DFF,HIGH);
  digitalWrite(DFR,LOW);
  digitalWrite(PFF,HIGH);
  digitalWrite(PFR,LOW);
  digitalWrite(DRF,HIGH);
  digitalWrite(DRR,LOW);
  digitalWrite(PRF,HIGH);
  digitalWrite(PRR,LOW);
  return;
}

void Reverse(){
  digitalWrite(DFF,LOW);
  digitalWrite(DFR,HIGH);
  digitalWrite(PFF,LOW);
  digitalWrite(PFR,HIGH);
  digitalWrite(DRF,LOW);
  digitalWrite(DRR,HIGH);
  digitalWrite(PRF,LOW);
  digitalWrite(PRR,HIGH);
  return;
}

void Stop(){
  digitalWrite(DFF,LOW);
  digitalWrite(DFR,LOW);
  digitalWrite(PFF,LOW);
  digitalWrite(PFR,LOW);
  digitalWrite(DRF,LOW);
  digitalWrite(DRR,LOW);
  digitalWrite(PRF,LOW);
  digitalWrite(PRR,LOW);
  return;
}

void Left(){
  digitalWrite(DFF,HIGH);
  digitalWrite(DFR,LOW);
  digitalWrite(PFF,LOW);
  digitalWrite(PFR,HIGH);
  digitalWrite(DRF,HIGH);
  digitalWrite(DRR,LOW);
  digitalWrite(PRF,LOW);
  digitalWrite(PRR,HIGH);
  return;
}

void Right(){
  digitalWrite(DFF,LOW);
  digitalWrite(DFR,HIGH);
  digitalWrite(PFF,HIGH);
  digitalWrite(PFR,LOW);
  digitalWrite(DRF,LOW);
  digitalWrite(DRR,HIGH);
  digitalWrite(PRF,HIGH);
  digitalWrite(PRR,LOW);
  return;
}

void Blade_Stop(){
  digitalWrite(BMF,LOW);
  digitalWrite(BMR,LOW);
  return;
}

void Blade_Start(){
  digitalWrite(BMF,HIGH);
  digitalWrite(BMR,LOW);
  return;
}
