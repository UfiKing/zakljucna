#include "Object.hpp"

void Object::draw(LGFX_Sprite *canvas){
  // Draw the actor as a filled rectangle using its current position, dimensions, and color
  canvas->fillRect(position.x, position.y, width, height, colour);
}

void Object::draw(LGFX_Sprite *canvas, int offsetX, int offsetY){
	canvas->fillRect(position.x + offsetX, position.y + offsetY, width, height, colour);
}

void Object::changeColour(int newColour){
	colour = newColour;
}

int Object::getColour(){
	return colour;
}