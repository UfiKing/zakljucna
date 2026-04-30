#include "Spikes.hpp"
#include <esp_log.h>

void Spike::draw(LGFX_Sprite* canvas){
	canvas->fillTriangle(getLeft(), getBottom(), getX() + getWidth() / 2, getTop(), getRight(), getBottom(), getColour());
	ESP_LOGI("TAG", "drawing");
}

void Spike::draw(LGFX_Sprite* canvas, int offsetX, int offsetY){
	canvas->fillTriangle(getLeft() + offsetX, getBottom() + offsetY, (getX() + getWidth() / 2) + offsetX, getTop() + offsetY, getRight() + offsetX, getBottom() + offsetY, getColour());
	ESP_LOGI("TAG", "drawing");
}

enum ObjectTypes Spike::getType(){
	return type;
}