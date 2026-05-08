#pragma once
#include "Object.hpp"
#include "CollectibleType.hpp"

class Collectible : public Object{
protected:
  enum CollectibleType collectibleType;

public:
  Collectible(int16_t x, int16_t y, uint16_t width, uint16_t height, enum CollectibleType type) : Object(x,y,width,height, TFT_GRAY){
    this->collectibleType = type;
  }

  Collectible(int16_t x, int16_t y, uint16_t width, uint16_t height, int16_t colour, enum CollectibleType type) : Object(x,y,width,height, colour){
    this->collectibleType = type;
  }

  enum CollectibleType getCollectibleType();
};



