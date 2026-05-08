#include "LifeCollectible.hpp"


void LifeCollectible::draw(LGFX_Sprite* canvas, int offsetX, int offsetY){
	int x = position.x + offsetX + 2;
	int y = position.y + offsetY + 2;
	canvas->startWrite();
	canvas->fillRect(x+1,y,2,1,TFT_RED);
	canvas->fillRect(x+4,y,2,1,TFT_RED);
	canvas->fillRect(x,y+1,7,2,TFT_RED);
	canvas->fillRect(x+1,y+3,5,1,TFT_RED);
	canvas->fillRect(x+2,y+4,3,1,TFT_RED);
	canvas->drawPixel(x+3,y+5,TFT_RED);
	canvas->endWrite();
}