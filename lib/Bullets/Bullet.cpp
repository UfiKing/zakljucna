#include "Bullet.hpp"

void Bullet::update() {
  // Move bullet based on direction
  switch (direction) {
    case Direction::LEFT:
      position.x -= speed;
      break;
    case Direction::RIGHT:
      position.x += speed;
      break;
    case Direction::UP:
      position.y -= speed;
      break;
    case Direction::DOWN:
      position.y += speed;
      break;
  }
}

void Bullet::draw(LGFX_Sprite* canvas, int offsetX, int offsetY){
	int xoff = position.x + offsetX;
	int yoff = position.y + offsetY;
	int colour = 8420;
	canvas->drawRect(xoff + 2, yoff, 8, 7, TFT_BLACK);
	canvas->fillRect(xoff + 2, yoff + 1, 7, 5, colour);
	canvas->drawFastVLine(xoff + 1, yoff + 2, 3, colour);
	canvas->drawFastVLine(xoff + 1, yoff + 2, 3, colour);
	canvas->drawPixel(xoff + 1, yoff + 1, TFT_BLACK);
	canvas->drawPixel(xoff + 1, yoff + 5, TFT_BLACK);
	canvas->drawFastHLine(xoff + 2, yoff + 1, 2,TFT_WHITE);

}

void Bullet::setDirection(Direction newDirection) {
  direction = newDirection;
}

void Bullet::setSpeed(int16_t newSpeed) {
  speed = newSpeed;
}

void Bullet::destroy(){
	destroyed = true;
}