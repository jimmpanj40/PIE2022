int Pos[5]={2, 3, 4, 5, 6};
int Neg[5]={7, 8, 9, 10, 10};

int del = 500;

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
    allumerLetter(letterE);
    eteindreLetter(letterE);
    delay(del);

    allumerLetter(letterN);
    eteindreLetter(letterN);
    delay(del);

    allumerLetter(letterS);
    eteindreLetter(letterS);
    delay(del);

    allumerLetter(letterE);
    eteindreLetter(letterE);
    delay(del);

    allumerLetter(letterA);
    eteindreLetter(letterA);
    delay(del);
    } 

  else { 

    state = 0; 

    digitalWrite(pin, LOW); 

    } 

} 

int allumerLed(int x,int y) {
  digitalWrite(Pos[x], HIGH);
  digitalWrite(Neg[y], LOW);
}
int eteindreLed(int x,int y) {
  digitalWrite(Pos[x], LOW);
  digitalWrite(Neg[y], HIGH);  
}

int allumerLetter(int letter[][2]) {
  for (int t=0; sizeof(letter)<5; t++) {
    allumerLed(letter[t][0], letter[t][1]);
  }
}
