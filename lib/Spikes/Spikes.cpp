#include "Spikes.hpp"

void Spike::draw(LGFX_Sprite* canvas){
	canvas->fillTriangle(position.x, position.y, position.x + (width / 2), position.y - height, position.x + width, position.y, getColour());
}

void Spike::draw(LGFX_Sprite* canvas, int offX, int offY){
	canvas->fillTriangle(position.x + offX, position.y + offY, position.x + (width / 2) + offX, position.y - height + offY, position.x + width + offX, position.y + offY, getColour());
}

enum ObjectTypes Spike::getType(){
	return type;
}