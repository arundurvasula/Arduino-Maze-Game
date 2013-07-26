// Libraries
#include <ArduinoNunchuk.h>
#include <Wire.h>
#include <fontALL.h>
#include <TVout.h>
#include <video_gen.h>
#include <avr/pgmspace.h>

// BEGIN global variables
TVout TV;
ArduinoNunchuk nunchuk = ArduinoNunchuk();
const uint8_t WIDTH = 128;
const uint8_t HEIGHT = 96;
int maze[96][128];
uint8_t playerx; // needs a default value
uint8_t playery; //needs a default value
uint8_t lastplayerx;
uint8_t lastplayery;
boolean collisionflag = false;

void setup() {
  TV.begin(NTSC, WIDTH, HEIGHT);
  nunchuk.init();
  drawMaze();  
}

void loop() {
  getInput();
  checkCollisions();
  if collisionflag == false {
    drawPlayer(playerx, playery);
  }
  else {
    //reset player position
    playerx = lastplayerx;
    playery = lastplayery;
    drawPlayer(playerx, playery);
  }
}

void get_input() {
  lastplayerx = playerx;
  lastplayery = playery;
  nunchuk.update();
  //update playerx and playery according to the nunchuk
  
}

void checkCollisions() {
  //if playerx,y == some point on the maze
  // collision flag == TRUE
}

void createMaze() {
  //todo
}

void drawMaze() {
  //todo
  //loop through maze[][] and set pixels accordingly
}

void drawPlayer(uint8_t x, uint8_t y) {
  TV.set_pixel(x, y, 1);
}
