#include "Spikes.hpp"

void Spike::draw(LGFX_Sprite* canvas){
	canvas->fillTriangle(getX(), getY(), getX() + (getWidth() / 2), getY() - getHeight(), getX() + getWidth(), getY(), getColour());
}

void Spike::draw(LGFX_Sprite* canvas, int offsetX, int offsetY){
	canvas->fillTriangle(getX()+ offsetX, getY() + offsetY, getX() + (getWidth() / 2)+ offsetX, getY() - getHeight() + offsetY, getX() + getWidth()+ offsetX, getY() + offsetY, getColour());
}

enum ObjectTypes Spike::getType(){
	return type;
}