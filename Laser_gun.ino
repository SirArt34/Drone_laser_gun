#define LASER 1
#define HITLED 0
#define BUTTON 3
int btn_stan;

    int zmSwiec=0;  //0 - Ready, 2- Shot, 1 - Hit, 2 - RESPAWN,
    #define READY 0
    #define HIT 1
    #define RESPAWN 2
 

void setup() {

  pinMode (BUTTON, INPUT_PULLUP);
  btn_stan = digitalRead(BUTTON);
  pinMode (LASER, OUTPUT);
  pinMode (HITLED, OUTPUT);

digitalWrite(HITLED, LOW);
}

void loop() {
          int PHOTO = analogRead(A2);
          int btn = digitalRead(BUTTON);

  
  switch(zmSwiec) 
      { 
        //---------------------------------------------------------------------------- 
        case READY: 

                            
              if (PHOTO >= 700){ 
                 zmSwiec=HIT;
              }
                            
              if (btn == LOW && btn_stan == HIGH){
                
                  digitalWrite(LASER, HIGH);
                  delay(50);
                  digitalWrite(LASER, LOW);
                  }

                btn_stan = digitalRead(BUTTON);


        break;  
        
        //---------------------------------------------------------------------------- 
        case HIT: 
                  digitalWrite(HITLED, HIGH);
                  delay(5000);
                  digitalWrite(HITLED, LOW);
                  zmSwiec=RESPAWN;
                  
        break;          
        //----------------------------------------------------------------------------         
        case RESPAWN: 
      
              while (digitalRead(BUTTON) == HIGH){
                  digitalWrite(HITLED, HIGH);
                  delay(200);
                  digitalWrite(HITLED, LOW);
                  delay(200);
                  }
                  zmSwiec=READY;
                  
        break;  
        //---------------------------------------------------------------------------- 


    }
}
