#pragma once
#include "Collectible.hpp"

class LifeCollectible : public Collectible{

public:
  LifeCollectible(int16_t x, int16_t y) : Collectible(x - 2 ,y - 2,12,12,LIFE1){
		this->collectibleType = LIFE1;
  }

	void draw(LGFX_Sprite* canvas, int offsetX, int offsetY) override;
};
