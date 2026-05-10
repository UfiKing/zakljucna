#include "Text.hpp"

void Text::draw(LGFX_Sprite* canvas, int offsetX, int offsetY){
	canvas->setTextColor(colour, backgroundColour);	
	canvas->setTextSize(textSize);
	canvas->drawString(text,position.x + offsetX, position.y + offsetY);
	
	
}

void Text::update(){

}