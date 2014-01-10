
import android.media.*;
import android.content.res.*;

PlaySound sineWave = new PlaySound();
boolean on=false;

void setup()
{
  size(displayWidth, displayHeight);
  textAlign(CENTER,CENTER);
  fill(255, 0, 0);
  rect(30, 30, 120, 120);
  rect(300, 30, 120, 120);
  fill(0);
  text("ON", 75, 75);
  text("Sinus 45 Hz", 75, 90);
  text("OFF", 360, 75);
  text("Sinus 95 Hz", 360, 90);
}

void draw() {

  if (mouseX>30 &&
    mouseX<150 &&
    mouseY>30 && 
    mouseY<150 && 
    mousePressed) { 
    sineWave.genTone(45); 
    delay(15);
    sineWave.playSound(true);
    delay(200);
    sineWave.playSound(false);
  }



  if (mouseX>300 &&
    mouseX<420 &&
    mouseY>30 && 
    mouseY<150 && 
    mousePressed) { 
    sineWave.genTone(95); 
    delay(15);
    sineWave.playSound(true);
    delay(200);
    sineWave.playSound(false);
  }
}

