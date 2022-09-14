int Neg[5]={2, 3, 4, 5, 6};
int Pos[5]={7, 8, 9, 10, 11};

int del = 1;

int letterE[15][2] = {{0,0}, {0, 1}, {0, 2}, {0, 3}, {0, 4}, {1, 0}, {2, 0}, {3, 0}, {4, 0}, {4, 1}, {4, 2}, {4, 3}, {4, 4}, {2, 1}, {2, 2}};
int letterN[13][2] = {{0,0}, {1, 0}, {2, 0}, {3, 0}, {4, 0}, {0, 4}, {1, 4}, {2, 4}, {3, 4}, {4, 4}, {1, 1}, {2, 2}, {3, 3}};
int letterA[16][2] = {{0,0}, {1, 0}, {2, 0}, {3, 0}, {4, 0}, {0, 4}, {1, 4}, {2, 4}, {3, 4}, {4, 4}, {0, 1}, {0, 2}, {0, 3}, {2, 1}, {2, 2}, {2, 3}};
int letterS[17][2] = {{0,0}, {0, 1}, {0, 2}, {0, 3}, {0, 4}, {2, 0}, {2, 1}, {2,2}, {2, 3}, {2, 4}, {4, 0}, {4, 1}, {4, 2}, {4, 3}, {4, 4}, {1, 0}, {3, 4}};

int pin = 5; 

int oldValue = 0; 

int newValue = 0; 

int dValue = 0; 

int threshold = 512; 

int state = 0; 


int allumerLed(int x,int y) {
  digitalWrite(Pos[x], HIGH);
  digitalWrite(Neg[y], LOW);
}
int eteindreLed(int x,int y) {
  digitalWrite(Pos[x], LOW);
  digitalWrite(Neg[y], HIGH);  
}

int allumerLetterE() {
  for (int d=0; d<50; d++) {
    for (int t=0; t<15; t++) {
      allumerLed(letterE[t][0], letterE[t][1]);
      delay(del);
      eteindreLed(letterE[t][0], letterE[t][1]);
    }
  }
}


int allumerLetterN() {
  for (int d=0; d<50; d++) {
    for (int t=0; t<13; t++) {
      allumerLed(letterN[t][0], letterN[t][1]);
      delay(del);
      eteindreLed(letterN[t][0], letterN[t][1]);
    }
  }
}


int allumerLetterS() {
  for (int d=0; d<50; d++) {
    for (int t=0; t<17; t++) {
      allumerLed(letterS[t][0], letterS[t][1]);
      delay(del);
      eteindreLed(letterS[t][0], letterS[t][1]);
    }
  }
}


int allumerLetterA() {
  for (int d=0; d<50; d++) {
    for (int t=0; t<16; t++) {
      allumerLed(letterA[t][0], letterA[t][1]);
      delay(del);
      eteindreLed(letterA[t][0], letterA[t][1]);
    }
  }
}


void setup() { 

  Serial.begin(9600); 

  pinMode(pin, OUTPUT); 
  for (int t=0; t<5; t++)
   {
    pinMode(Pos[t], OUTPUT);
    pinMode(Neg[t], OUTPUT);
   }

}

  

  

void loop() { 

  newValue = analogRead(A0); 

  Serial.println(newValue); 

  if (newValue >= threshold) { 

    state = 1; 

    //digitalWrite(pin, HIGH); 

    allumerLetterE();
    
    allumerLetterN();

    allumerLetterS();

    allumerLetterE();

    allumerLetterA();
    } 

} 
