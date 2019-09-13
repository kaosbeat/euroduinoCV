const int outD1 = 4;
//const int outHF1 = 5;
//const int outHF2 = 6;
const int outHV1 = 7;
const int outHV2 = 8;
const int outD2 = 13;

//const int inD1 = 4;
const int inHF1 = 5;
const int inHF2 = 6;
//const int inHV1 = 7;
//const int inHV2 = 8;
//const int inD2 = 13;




const int buttonWhite = 0;
const int buttonBlack = 1;
const int buttonRed = 2;


//const int inD1 = 4;
//const int inD2 = 7;
//const int inD3 = 8;
//const int inD4 = 13;


//const int inputpin = 4;
//
//const int ledPin = 13;


const int led1 = 3;
const int led2 = 9;
const int led3 = 11;
const int led4 = 10;

bool testout = true;
bool testin = false;

//void setin(){
//  pinMode(inD1, INPUT);
//  pinMode(inD2, INPUT);
//  pinMode(inD3, INPUT);
//  pinMode(inD4, INPUT);
//}
//
int  t1state = 0;
int  t1prevstate = 0;
int  t1reset = 10;

//output pulses
int p1state = 0;
//int p1prevstate = 0;
int p1reset = 10;
int p2state = 0;
//int p2prevstate = 0;
int p2reset = 10;
int p3state = 0;
//int p3prevstate = 0;
int p3reset = 10;
int p4state = 0;
//int p4prevstate = 0;
int p4reset = 10;

//LEDs
int led1duration = 50;
int led1state = 0;

int led2duration = 50;
int led2state = 0;

int led3duration = 50;
int led3state = 0;

int led4duration = 50;
int led4state = 0;

///Timings
unsigned long currentMillis = 0;
unsigned long t1Millis = 0;
unsigned long led1Millis = 0;
unsigned long led2Millis = 0;
unsigned long led3Millis = 0;
unsigned long led4Millis = 0;
unsigned long p1Millis = 0;
unsigned long p2Millis = 0;
unsigned long p3Millis = 0;
unsigned long p4Millis = 0;

unsigned long tick = 0;
unsigned long prvtick = 0;
unsigned long interval = 0;
int tickcount = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);


  pinMode(outD1, OUTPUT);
  pinMode(outD2, OUTPUT);
  //  pinMode(outHF1, OUTPUT);
  //  pinMode(outHF2, OUTPUT);
  pinMode(outHV1, OUTPUT);
  pinMode(outHV2, OUTPUT);

  //  pinMode(inD1, INPUT);
  //  pinMode(inD2, INPUT);
  pinMode(inHF1, INPUT);
  pinMode(inHF2, INPUT);
  //  pinMode(inHV1, INPUT);
  //  pinMode(inHV2, INPUT);


  pinMode(buttonWhite, INPUT_PULLUP);
  pinMode(buttonBlack, INPUT_PULLUP);
  pinMode(buttonRed, INPUT);

  digitalWrite(led1, HIGH);
  delay(20);
  digitalWrite(led2, HIGH);
  delay(20);
  digitalWrite(led3, HIGH);
  delay(20);
  digitalWrite(led4, HIGH);
  delay(20);
  digitalWrite(led1, LOW);
  delay(20);
  digitalWrite(led2, LOW);
  delay(20);
  digitalWrite(led3, LOW);
  delay(20);
  digitalWrite(led4, LOW);


  //  Serial.end();
  //to fix the buttons swap them with LED buttons...
  // D0 is hard to use as INPUT in combo with low-impedance...\
  //https://forum.arduino.cc/index.php?topic=481405.0

}





void loop() {
  currentMillis = millis();
  int t1 = digitalRead(inHF1);
  if (t1 != t1prevstate) {
    t1Millis = currentMillis;
  }
  if (currentMillis - t1Millis >= t1reset) {
    // if the button state has changed:
    if (t1 != t1state) {
      t1state = t1;

      // only toggle the LED if the new button state is HIGH
      if (t1state == HIGH) {
        //        led1state = !led1state;
        tickcount++;
        fireLED1();
        firePulse1();
        if ((tickcount % 4) == 0) {
          fireLED2();
        }
        if ((tickcount % 8) == 0) {
          fireLED3();
        }
        if ((tickcount % 16) == 0) {
          fireLED4();
        }
        tick = currentMillis;
        interval = tick - prvtick;
//        Serial.println(interval);
        prvtick = tick;
      }
    }
  }

  //  if (currentMillis - prevtick


  updatePulses();
  updateLEDs();
  t1prevstate = t1;

}

//  // compare the buttonState to its previous state
//  if (t1state != t1prevstate) {
//    // if the state has changed, increment the counter
//    if (t1state == HIGH) {
//      freqout (440, 100);
//    }
//  }
//  t1prevstate = t1state;



void fireLED1() {
  //  Serial.print("firing LED1 tick: ");
  //  Serial.println(tickcount);
  led1state = 1;
  led1Millis = currentMillis;

}

void fireLED2() {
  //  Serial.print("firing LED2 tick: "  );
  //  Serial.println(tickcount);
  led2state = 1;
  led2Millis = currentMillis;

}

void fireLED3() {
  //  Serial.print("firing LED3 tick: "  );
  //  Serial.println(tickcount);
  led3state = 1;
  led3Millis = currentMillis;

}

void fireLED4() {
  //  Serial.print("firing LED3 tick: "  );
  //  Serial.println(tickcount);
  led4state = 1;
  led4Millis = currentMillis;

}


void firePulse1() {
  p1state = 0; ///inverse for outHVx
  p1Millis = currentMillis;
}

void updateLEDs() {
  if (led1state == 1) {
    if (currentMillis - led1Millis >= led1duration) {
      led1state = 0;
    }
  }
  if (led2state == 1) {
    if (currentMillis - led2Millis >= led2duration) {
      led2state = 0;
    }
  }
  if (led3state == 1) {
    if (currentMillis - led3Millis >= led3duration) {
      led3state = 0;
    }
  }
  if (led4state == 1) {
    if (currentMillis - led3Millis >= led4duration) {
      led4state = 0;
    }
  }
  digitalWrite(led1, led1state);
  digitalWrite(led2, led2state);
  digitalWrite(led3, led3state);
  digitalWrite(led4, led4state);
}


void updatePulses() {
//  Serial.println("updating pulse");
  if (p1state == 0) { ///inverse state for HVpins
    if (currentMillis - p1Millis >= p1reset) {
      p1state = 1;
    }
  }
  digitalWrite(outHV1, p1state);
}
