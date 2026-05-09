#include "Platform.hpp"

void Platform::draw(LGFX_Sprite* canvas, int offsetX, int offsetY) {
	int x = getX() + offsetX;
	int y = getY() + offsetY;
	int w = getWidth();
	int h = getHeight();


	//int rows = h / 10;
	//int cols = w / 10;
	int rows = h;
	int cols = w;

	//future optimizing jure, tuki pa pomojem se ne da velik vec. Ze startWrite pa endWrite pomojem ful pomagata
	//tuki se pa pozna ker mas tko 200+ rectov

	canvas->startWrite();
	//old drawing method

	//canvas->fillRect(x, y, w, h, TFT_DARKGRAY);
	/*for(int j = 0; j < rows; j++){
		int y_ofs = y + (j * 10);
		canvas->drawFastHLine(x, y_ofs, w, TFT_LIGHTGRAY);
		canvas->drawFastHLine(x, y_ofs + 3, w, TFT_LIGHTGRAY);
		canvas->drawFastHLine(x, y_ofs + 7, w, TFT_LIGHTGRAY);
		for(int i = 0; i < cols; i++){
			int x_ofs = x + (i * 10);
			canvas->drawFastVLine(x_ofs + 3, y_ofs + 1, 2, TFT_LIGHTGRAY);
			canvas->drawFastVLine(x_ofs + 8, y_ofs + 1, 2, TFT_LIGHTGRAY);
			canvas->drawFastVLine(x_ofs + 3, y_ofs + 8, 2, TFT_LIGHTGRAY);
			canvas->drawFastVLine(x_ofs + 8, y_ofs + 8, 2, TFT_LIGHTGRAY);

			canvas->drawFastVLine(x_ofs, y_ofs + 4, 3, TFT_LIGHTGRAY);
			canvas->drawFastVLine(x_ofs + 5, y_ofs + 4, 3, TFT_LIGHTGRAY);
		}	
	}*/
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