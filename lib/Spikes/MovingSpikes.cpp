#include "MovingSpikes.hpp"


void MovingSpike::draw(LGFX_Sprite* canvas, int offsetX, int offsetY){
	canvas->fillTriangle(position.x + offsetX, position.y + height + offsetY,
		 position.x + (width / 2)+ offsetX, position.y + offsetY, 
		 position.x + width + offsetX, position.y + height + offsetY, 
		 getColour());
}

void MovingSpike::update(){
	position.x += speed;
	if(position.x >= x2 || position.x <= x1){
		speed = -speed;
	}
}