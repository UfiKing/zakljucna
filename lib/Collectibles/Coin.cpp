#include "Coin.hpp"

void Coin::draw(LGFX_Sprite *canvas){
  // Draw the actor as a filled rectangle using its current position, dimensions, and color
	canvas->fillCircle(position.x, position.y, radius, getColour());
	canvas->drawFastVLine(position.x, position.y - radius + 1, 2 * radius - 2, accentColour);
}

void Coin::draw(LGFX_Sprite *canvas, int offsetX, int offsetY){
	//canvas->fillCircle(position.x + offsetX, position.y + offsetY, radius, getColour());
	//canvas->fillRect(position.x - 1 + offsetX, position.y - radius + 1 + offsetY, 3, 2 * radius - 2, accentColour);
	int x = position.x - 4 + offsetX;
	int y = position.y - 4 + offsetY;
	
	//future ufi, ce zacen performance jebat se lahko to skrajsa za tri ukaze (uporabis fillRect)
	//realisticno ne vem kok bo to pomagalo ker se itak uporablja start pa endWrite za lock-anje SPI busa
	//ampak pomojem lahko na vsak draw prihranis se cirka 20-30 B, zdej kok se bo pa to poznal... Ce ne bos imel lih 200 Coinsov pomojem ne...
	canvas->startWrite();
	canvas->drawFastVLine(x, y+2,6,colour);
	canvas->drawFastVLine(x+1,y+1,8,colour);
	
	canvas->drawFastVLine(x+2,y,10,colour);
	canvas->drawFastVLine(x+3,y,10,colour);
	canvas->drawFastVLine(x+4,y,10,colour);
	canvas->drawFastVLine(x+5,y,10,colour);

	canvas->drawFastVLine(x+6,y,10,shadeColour);
	canvas->drawFastVLine(x+6,y+1,8,colour);

	canvas->drawFastVLine(x+7,y+1,8,shadeColour);
	canvas->drawFastVLine(x+7,y+2,6,colour);

	canvas->drawFastVLine(x+8,y+2,6,shadeColour);

	canvas->drawFastVLine(x+2,y+2,6,accentColour);
	canvas->drawFastVLine(x+5,y+2,6,accentShadeColour);
	canvas->drawFastHLine(x+3,y+1,2,accentColour);
	canvas->drawFastHLine(x+3,y+8,2,accentColour);
	canvas->endWrite();
}

int16_t Coin::getRadius(){
	return radius;
}