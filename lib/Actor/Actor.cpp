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

void Actor::update(){}

int16_t Actor::getLeft() const { return position.x; }
int16_t Actor::getRight() const { return position.x + width; }
int16_t Actor::getTop() const { return position.y; }
int16_t Actor::getBottom() const { return position.y + height; }

int16_t Actor::getX() const { return position.x; }
int16_t Actor::getY() const { return position.y; }

void Actor::setX(int16_t newX){ position.x = newX; }
void Actor::setY(int16_t newY){ position.y = newY; }

void Actor::setLeft(int16_t newLeft) {
  position.x = newLeft;
}

void Actor::setRight(int16_t newRight) {
  position.x = newRight - width;
}

void Actor::setTop(int16_t newTop) {
  position.y = newTop;
}

void Actor::setBottom(int16_t newBottom) {
  position.y = newBottom - height;
}