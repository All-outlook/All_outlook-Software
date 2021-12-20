int SpeakerPin = 35;
unsigned int i;

unsigned int j;

void setup(){
pinMode(SpeakerPin, OUTPUT);
}

void mario_1up(){
for (i=0; i<97; i++){
digitalWrite(SpeakerPin,HIGH);
delayMicroseconds(379);
digitalWrite(SpeakerPin,LOW);
delayMicroseconds(379);
}
for (i=0; i<235; i++){
digitalWrite(SpeakerPin,HIGH);
delayMicroseconds(319);
digitalWrite(SpeakerPin,LOW);
delayMicroseconds(319);
}
for (i=0; i<396; i++){
digitalWrite(SpeakerPin,HIGH);
delayMicroseconds(189);
digitalWrite(SpeakerPin,LOW);
delayMicroseconds(189);
}
for (i=0; i<315; i++){
digitalWrite(SpeakerPin,HIGH);
delayMicroseconds(238);
digitalWrite(SpeakerPin,LOW);
delayMicroseconds(238);
}
for (i=0; i<353; i++){
digitalWrite(SpeakerPin,HIGH);
delayMicroseconds(212);
digitalWrite(SpeakerPin,LOW);
delayMicroseconds(212);
}
for (i=0; i<471; i++){
digitalWrite(SpeakerPin,HIGH);
delayMicroseconds(159);
digitalWrite(SpeakerPin,LOW);
delayMicroseconds(159);
}

}

void get_coin(){
for (i=0; i<250; i++){
digitalWrite(SpeakerPin,HIGH);
delayMicroseconds(253);
digitalWrite(SpeakerPin,LOW);
delayMicroseconds(253);
}
for (i=0; i<500; i++){
digitalWrite(SpeakerPin,HIGH);
delayMicroseconds(189);
digitalWrite(SpeakerPin,LOW);
delayMicroseconds(189);
}
delay(50);

}


void loop(){

for(j=0; j<3; j++){
get_coin();
delay(50);
}

for(j=0; j<3; j++){
mario_1up();
delay(50);
}
delay(500);
}
