#include <LovyanGFX.hpp>
#include <cstdint>

//player class
class Player{

public:
  uint8_t x;
  uint8_t y;
  uint8_t width = 10;

  Player(uint8_t initX, uint8_t initY){
    x = initX;
    y = initY;
  }

  void draw(){

  }
};
