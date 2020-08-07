
//controling leds via serial with numbers 
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(9,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
  digitalWrite(12,HIGH);
  digitalWrite(11,HIGH);
  digitalWrite(10,HIGH);
  digitalWrite(9,HIGH);

}

void loop() {

  // put your main code here, to run repeatedly:
if(Serial.available()){
  //thene read the serial as char not int
  char outTopic= Serial.read();
  switch (outTopic){
    case '0':
    digitalWrite(12,LOW);
    break;
    case '1':
    digitalWrite(12,HIGH);
    break;
    case '2':
    digitalWrite(11,LOW);
    break;
    case'3':
    digitalWrite(11,HIGH);
    break;
    case '4':
    digitalWrite(10,LOW);
    break;
    case '5':
    digitalWrite(10,HIGH);
    break;
    case '6':
    digitalWrite(9,LOW);
    break;
    case'7':
    digitalWrite(9,HIGH);
    break;
  }
  
}
  
}
