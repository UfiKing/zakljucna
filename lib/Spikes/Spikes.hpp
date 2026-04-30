#pragma once
#include "Object.hpp"

class Spike : public Object{
	enum ObjectTypes type = SPIKE;
public:
	Spike(int16_t x, int16_t y, int16_t width, int16_t height) : Object(x,y,width,height, TFT_DARKGRAY){

	}

	void draw(LGFX_Sprite* canvas);
  void draw(LGFX_Sprite* canvas, int offsetX, int offsetY);

	enum ObjectTypes getType();

};