

/*fonctionne avec n'importe quel fichier son, créé avec Audacity
 
 frequences stables sinus a ajuster peut etre !
 2000 Hz => 85
 625 Hz => 170
 355 Hz => 255
 300 Hz => 340
 200 Hz => 425
 170 Hz => 510
 140 Hz => 595
 120 Hz => 680
 110 Hz => 765
 95 Hz => 850
 88 Hz => 935
 80 Hz => 1020
 75 Hz => 1105
 70 Hz => 1190
 55 Hz => 1445
 45 Hz => 1700
 35 Hz => 2550
 23 Hz => 3400
 */

int count=0;
int frequence=0;
int avgcount=0;
void setup(){
  attachInterrupt(0, interrupt, LOW);
  pinMode(11,OUTPUT); // relié à l'entrée D2, pour l'interruption
  pinMode(13,OUTPUT); // broche de la led
  Serial.begin(9600);

}

void loop(){
  while(analogRead(A0)>10){    
    digitalWrite(13,LOW);
  }
  digitalWrite(13,HIGH);
  if(count>0){
    avgcount++;
    if(avgcount==2){    //filtrage du son (on prend la deuxieme mesure
      Serial.println(count); 
      avgcount=0;   
      if(count==1700){  // 45 Hz
        digitalWrite(11,HIGH);
        delay(50); 

      }
      if(count == 850){ //95 Hz
        digitalWrite(11,LOW);
        delay(50);
      }


    }
  }
  count = 0;




}

void interrupt()
{
  count++;
}








