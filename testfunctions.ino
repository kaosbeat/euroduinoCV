//void cycleOuts(){
//  delay(20);
//  digitalWrite(outD1, HIGH);
//  digitalWrite(outD2, HIGH);
//  digitalWrite(outHF1, HIGH);
//  digitalWrite(outHF2, HIGH);
//  digitalWrite(outHV1, HIGH);
//  digitalWrite(outHV2, HIGH);
//
//  delay(20);
//  //  delay(delaypulse);
//  digitalWrite(outD1, LOW);
//  digitalWrite(outD2, LOW);
//  digitalWrite(outHF1, LOW);
//  digitalWrite(outHF2, LOW);
//  digitalWrite(outHV1, LOW);
//  digitalWrite(outHV2, LOW);
//}
//
//

//
//  int led1pulse = analogRead(A0);
////  analogWrite(led3, led1pulse/4);
//  int delaypulse = analogRead(A0);
//  //  delay(delayprepulse);
//  int sensorValue = analogRead(A4);
//  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
//  float voltage = sensorValue * (5.0 / 1023.0);
//  analogWrite(led3, sensorValue/4);
//  analogWrite(led1, digitalRead(buttonRed)*4);





////freqout code by Paul Badger 
//// freq - frequency value
//// t - time duration of tone
//void freqout(int freq, int t) { 
//  int hperiod;     //calculate 1/2 period in us 
//  long cycles, i; 
//
//  // subtract 7 us to make up for digitalWrite overhead - determined empirically 
//  hperiod = (500000 / ((freq - 7) * 128));             
//
//  // calculate cycles 
//  cycles = ((long)freq * (long)t) / 1000;    // calculate cycles 
//  for (i=0; i<= cycles; i++)
//  {              // play note for t ms  
//    digitalWrite(outHF1, HIGH);  
//    delayMicroseconds(hperiod); 
//    digitalWrite(outHF1, LOW);  
//    delayMicroseconds(hperiod - 1);     // - 1 to make up for fractional microsecond in digitaWrite overhead 
//  } 
//}
