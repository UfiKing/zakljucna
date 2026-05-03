#include "Coin.hpp"

void Coin::draw(LGFX_Sprite *canvas){
  // Draw the actor as a filled rectangle using its current position, dimensions, and color
	canvas->fillCircle(position.x, position.y, radius, getColour());
}

void Coin::draw(LGFX_Sprite *canvas, int offsetX, int offsetY){
	canvas->fillCircle(position.x + offsetX, position.y + offsetY, radius, getColour());
}

int16_t Coin::getRadius(){
	return radius;
}