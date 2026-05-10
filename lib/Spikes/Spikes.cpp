#include "Spikes.hpp"

void Spike::draw(LGFX_Sprite* canvas){
	canvas->fillTriangle(position.x, position.y + height, position.x + (width / 2), position.y, position.x + width, position.y + height, getColour());
}

void Spike::draw(LGFX_Sprite* canvas, int offX, int offY){
	canvas->fillTriangle(position.x + offX, position.y + height + offY , position.x + (width / 2) + offX, position.y + offY, position.x + width + offX, position.y + height + offY, getColour());
}

enum ObjectTypes Spike::getType(){
	return type;
}