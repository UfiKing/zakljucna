#pragma once
#include "Object.hpp"
#include "Vektor.hpp"
#include <LovyanGFX.hpp>

class Coin : public Object{
	int16_t radius; 
	int16_t width;
	int16_t height;
	Vektor<int16_t> position;
	enum ObjectTypes type = COLLECTIBLE;
public:
	Coin(int16_t x, int16_t y, int16_t radius) : Object(x,y,radius * 2, radius * 2, TFT_GOLD){
		position = Vektor(x,y);
		this->width = 2 * radius;
		this->height = 2 * radius;
		this->radius = radius;
	}

	void draw(LGFX_Sprite* canvas);
	void draw(LGFX_Sprite* canvas, int offsetX, int offsetY);
	
	int16_t getRadius();

};