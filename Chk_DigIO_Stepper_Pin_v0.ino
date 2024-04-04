int pin,indexOfSpace,opt; // 54 Step 55 Dir 38    ;enable= 0 38; disable 1,38; dir 0 55; step 3 54   
// X 38E 54S 55D;  Y 56E 60S 61D // 1500=180 degree (for 1/16)
// Input Example  0 38 (LOW Enable), 1 55 (HIGH Dir), 2 54 (200 step) 
String data;

void setup() {
  Serial.begin(9600);
}

void loop() {
 if(Serial.available() > 0)//check to see if we are connected
  {
    data = Serial.readStringUntil('\n');//reads string and store it in data
    indexOfSpace = data.indexOf(' ');//getting index of space
    opt=data.substring(0,indexOfSpace).toInt();
    pin=data.substring(indexOfSpace).toInt();
    pinMode(pin, OUTPUT);

    if (opt==0){digitalWrite(pin, LOW);}
    else if (opt==1){digitalWrite(pin, HIGH);}
    else if (opt==2){
      for (int i=0; i<200;i++)
      {digitalWrite(pin, HIGH);
      delayMicroseconds(700);
      //delay(1);
      digitalWrite(pin, LOW);
      delayMicroseconds(700);
      //delay(1);
        }
      }
 
};}
