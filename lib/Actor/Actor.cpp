#include "Actor.hpp"
#include <LovyanGFX.h>
uint16_t Actor::getHeight(){
  return height;
}

uint16_t Actor::getWidth(){
  return width;
}

void Actor::draw(LGFX_Sprite *canvas){
  canvas->fillRect(position.x, position.y, width, height, colour);
}

void Actor::update(int16_t newX, int16_t newY){
  position.x = newX;
  position.y = newY;
}