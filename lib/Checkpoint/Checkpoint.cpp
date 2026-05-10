#include "Checkpoint.hpp"
#include <LovyanGFX.hpp>


void Checkpoint::draw(LGFX_Sprite* canvas, int offsetX, int offsetY) {
	int xoff = position.x + offsetX;
	int yoff = position.y + offsetY;

	canvas->fillRect(xoff,yoff + 5, 18,14,TFT_BROWN);
	canvas->fillRect(xoff + 4, yoff + 8, 10, 11, TFT_BLACK);
	canvas->drawFastHLine(xoff + 5, yoff + 7, 8);
	canvas->drawFastHLine(xoff + 7, yoff + 6, 4);
	canvas->fillTriangle(xoff, yoff + 5, xoff + 8, yoff, xoff + 8, yoff + 5, TFT_GOLD);
	canvas->fillTriangle(xoff + 9, yoff , xoff + 9, yoff + 5, xoff + 17, yoff + 5);
}

void Checkpoint::update() {
}

void Checkpoint::onPlayerHit() {
}

ObjectTypes Checkpoint::getType(){return type;}