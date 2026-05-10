#pragma once
#include "Object.hpp"
#include <string>

class Text : public Object{
	char* text;
	float textSize;
	int backgroundColour;
public:
	Text(int16_t x, int16_t y, uint16_t width, uint16_t height, char* text, float textSize, int colour, int backgroundColour) 
	: Object(x,y,width,height,colour){	
		this->text = text;
		this->textSize = textSize;
		this->backgroundColour = backgroundColour;
	}

	~Text(){
		delete text;
	}

	void draw(LGFX_Sprite*, int offsetX, int offsetY) override;

	void update() override;
};