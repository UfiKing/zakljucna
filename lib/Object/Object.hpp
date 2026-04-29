#pragma once
#include "Actor.hpp"
#include "ObjectTypes.hpp"

class Object : public Actor{
	int colour;
	enum ObjectTypes type = OBJECT;
public:

	Object(int16_t x, int16_t y, int16_t width, int16_t height, int16_t colour) : Actor(x,y,width,height){
		this->colour = colour;

	}
  virtual void draw(LGFX_Sprite *canvas);

	virtual void draw(LGFX_Sprite *canvas, int offsetX, int offsetY);

	virtual void changeColour(int newColour);

	virtual int getColour();

};
