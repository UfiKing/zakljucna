#include "Platform.hpp"

void Platform::draw(LGFX_Sprite* canvas, int offsetX, int offsetY) {
	int x = getX() + offsetX;
	int y = getY() + offsetY;
	int w = getWidth();
	int h = getHeight();

	canvas->fillRect(x, y, w, h, TFT_DARKGRAY);

	int rows = h / 10;
	int cols = w / 10;

	for(int j = 0; j < rows; j++){
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
	}
}