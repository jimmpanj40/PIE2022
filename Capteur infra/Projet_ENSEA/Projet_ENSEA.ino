int pin = 5; 

int oldValue = 0; 

int newValue = 0; 

int dValue = 0; 

int threshold = 512; 

int state = 0; 


void setup() { 

  Serial.begin(9600); 

  pinMode(pin, OUTPUT); 

} 

  

  

void loop() { 

  newValue = analogRead(A0); 

  Serial.println(newValue*5/1024); 

  if (newValue >= threshold) { 

    state = 1; 

    digitalWrite(pin, HIGH); 

    } 

  else { 

    state = 0; 

    digitalWrite(pin, LOW); 

    } 

} 
