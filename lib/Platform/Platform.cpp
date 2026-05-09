#include "Platform.hpp"

void Platform::draw(LGFX_Sprite* canvas, int offsetX, int offsetY){
	switch(platformType){
		case GRAYBRICKS:
			drawGrayBricks(canvas, offsetX, offsetY);
			break;
		case GRAYBLOCK:
			drawGrayBlock(canvas, offsetX, offsetY);
			break;
	}
}

void Platform::drawGrayBricks(LGFX_Sprite* canvas, int offsetX, int offsetY) {
	int x = getX() + offsetX;
	int y = getY() + offsetY;
	int w = getWidth();
	int h = getHeight();

	int rows = h;
	int cols = w;

	//future optimizing jure, tuki pa pomojem se ne da velik vec. Ze startWrite pa endWrite pomojem ful pomagata
	//tuki se pa pozna ker mas tko 200+ rectov

	canvas->startWrite();
	//old drawing method

	for(int i = 0; i < rows; i++){
		switch(i % 7){
			case 1:
			case 2:
				canvas->fillRect(x,y + 1 + (i / 7) * 7,w,2,TFT_DARKGRAY);
				for(int j = 3; j < cols; j+=5){
					canvas->drawFastVLine(x + j, y + 1 + (i / 7) * 7,2, TFT_TRANSPARENT);
				}
				break;
			case 4:
			case 5:
			case 6:
				canvas->fillRect(x,y + 4 + (i / 7) * 7,w,3, TFT_DARKGRAY);
				for(int j = 0; j < cols; j+=5){
					canvas->drawFastVLine(x + j, y + 4 + (i / 7) * 7,3, TFT_TRANSPARENT);
				}
				break;
		}
	}
	canvas->endWrite();
}

void Platform::drawGrayBlock(LGFX_Sprite* canvas, int offsetX, int offsetY){
	int x = getX() + offsetX;
	int y = getY() + offsetY;
	int w = getWidth();
	int h = getHeight();

	int rows = h / 10;
	int cols = w / 10;

	int xoff = x;
	int yoff = y;
	canvas->startWrite();
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			xoff = x + j * 10;
			yoff = y + i * 10;	
			//first draw the box in the middle
			canvas->fillRect(xoff + 2, yoff + 2, 6, 6, TFT_DARKGRAY);
			//then the white boxes on the left and the top
			canvas->fillRect(xoff, yoff, 9,2, TFT_WHITE);
			canvas->fillRect(xoff, yoff, 2, 9, TFT_WHITE);
			//then the black boxes
			canvas->fillRect(xoff + 8, yoff + 1, 2, 9, TFT_BLACK);
			canvas->fillRect(xoff + 1, yoff + 8, 9, 2, TFT_BLACK);
			//then the little pixels in the corners
			canvas->drawPixel(xoff, yoff, TFT_DARKGRAY);
			canvas->drawPixel(xoff + 1, yoff + 1, TFT_DARKGRAY);
			
			canvas->drawPixel(xoff, yoff + 9, TFT_DARKGRAY);
			canvas->drawPixel(xoff + 1, yoff + 8, TFT_DARKGRAY);

			canvas->drawPixel(xoff + 9, yoff, TFT_DARKGRAY);
			canvas->drawPixel(xoff + 8, yoff + 1, TFT_DARKGRAY);
			
			canvas->drawPixel(xoff + 8, yoff + 8, TFT_DARKGRAY);
			canvas->drawPixel(xoff + 9, yoff + 9, TFT_DARKGRAY);
		}
	}
	canvas->endWrite();

}