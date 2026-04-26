#pragma once
#include "Vektor.hpp"
#include <LovyanGFX.hpp>

class Actor {
protected:
  Vektor<int16_t> position;
  uint16_t width;
  uint16_t height;
public:
  LGFX_Sprite *canvas;
  Actor(int16_t x, int16_t y, uint16_t width, uint16_t height, LGFX_Sprite *canvas){
    position = Vektor(x,y);
    this->width = width;
    this->height = height;
    this->canvas = canvas;
  }
  
  uint16_t getWidth();
  uint16_t getHeight();
};
