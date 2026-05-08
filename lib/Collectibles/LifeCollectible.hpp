#pragma once
#include "Collectible.hpp"

class LifeCollectible : public Collectible{

public:
  LifeCollectible(int16_t x, int16_t y, uint16_t width, uint16_t height) : Collectible(x,y,width,height,LIFE1){

  }
};
