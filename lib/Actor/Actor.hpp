#pragma once
#include "Vektor.hpp"
#include <LovyanGFX.hpp>

class Actor {
protected:
  Vektor<int16_t> position;
  uint16_t width;
  uint16_t height;
  int colour;
public:
  Actor(int16_t x, int16_t y, uint16_t width, uint16_t height){
    position = Vektor(x,y);
    this->width = width;
    this->height = height;
    this->colour = TFT_WHITE;
  }
  
  Actor(int16_t x, int16_t y, uint16_t width){
    position = Vektor(x,y);
    this->width = width;
    this->height = width;
    this->colour = TFT_WHITE;
  }
  
  Actor(int16_t x, int16_t y, uint16_t width, uint16_t height, int colour){
    position = Vektor(x,y);
    this->width = width;
    this->height = height;
    this->colour = colour;
  }
  
  Actor(int16_t x, int16_t y, uint16_t width, int colour){
    position = Vektor(x,y);
    this->width = width;
    this->height = width;
    this->colour = colour;
  }

  
  virtual ~Actor(){
    
  }

  virtual void update(int16_t newX, int16_t newY);
	virtual void update();
  virtual void draw(LGFX_Sprite *canvas);

  uint16_t getWidth();
  uint16_t getHeight();
	
	virtual int16_t getLeft() const;
  virtual int16_t getRight() const;
  virtual int16_t getTop() const;
  virtual int16_t getBottom() const;
  virtual int16_t getX() const; 
  virtual int16_t getY() const;
	virtual void setX(int16_t newX);
	virtual void setY(int16_t newY); 
	virtual void setLeft(int16_t newLeft);
	virtual void setRight(int16_t newRight);
	virtual void setTop(int16_t newTop);
	virtual void setBottom(int16_t newBottom);

};
