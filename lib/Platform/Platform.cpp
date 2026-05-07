#include "Platform.hpp"
#include <esp_log.h>
void Platform::draw(LGFX_Sprite* canvas, int offsetX, int offsetY) {
	/*for(int i = 0; i < getHeight() ;i++){
		for(int j = 0; j < getWidth(); j++){
			if(((j%5 < 3) && (i%2 == 0)) || ((j%5 >= 3) && (i%2 == 1))) canvas->drawPixel(getX() + j + offsetX, getY() + i + offsetY, TFT_DARKGRAY);
			else canvas->drawPixel(getX() + j + offsetX, getY() + i + offsetY, TFT_LIGHTGRAY);
		}
	}*/

	for(int i = 0; i < getHeight(); i++){
		for(int j = 0; j < getWidth(); j++){
			//full lines
			if(i%10 == 0 || i%10 == 3 || i%10 == 7) canvas->fillRect(getX() + offsetX, getY() + i + offsetY, 10, 1,TFT_LIGHTGRAY);
			//2 high vertical lines
			else if(j%5 == 3 && (i < 3 || i >= 8 )) canvas->drawPixel(getX() + offsetX + j, getY() + offsetY + i, TFT_LIGHTGRAY);
			//3 high vertical lines
			else if(j%5 == 0 && (i >= 4 && i <=6)) canvas->drawPixel(getX() + offsetX + j, getY() + offsetY + i, TFT_LIGHTGRAY);
			//ostalo
			else canvas->drawPixel(getX() + j + offsetX, getY() + i + offsetY, TFT_DARKGRAY);
		}
	}
}