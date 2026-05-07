#include "Coin.hpp"

void Coin::draw(LGFX_Sprite *canvas){
  // Draw the actor as a filled rectangle using its current position, dimensions, and color
	canvas->fillCircle(position.x, position.y, radius, getColour());
	canvas->drawFastVLine(position.x, position.y - radius + 1, 2 * radius - 2, accentColour);
}

void Coin::draw(LGFX_Sprite *canvas, int offsetX, int offsetY){
	canvas->fillCircle(position.x + offsetX, position.y + offsetY, radius, getColour());
	//canvas->drawFastVLine(position.x + offsetX, position.y - radius + 1 + offsetY, 2 * radius - 2, accentColour);
	canvas->fillRect(position.x - 1 + offsetX, position.y - radius + 1 + offsetY, 3, 2 * radius - 2, accentColour);
}

int16_t Coin::getRadius(){
	return radius;
}