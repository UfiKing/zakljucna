#pragma once
#include "Collectible.hpp"

/**
 * @brief Represents a life collectible (heart) in the game.
 * Inherits from Collectible. When picked up, it grants the player an extra life.
 */
class LifeCollectible : public Collectible{

public:
  /**
   * @brief Construct a new Life Collectible object.
   * @param x Initial X coordinate.
   * @param y Initial Y coordinate.
   */
  LifeCollectible(int16_t x, int16_t y) : Collectible(x - 2 ,y - 2,12,12,LIFE1){
		this->collectibleType = LIFE1;
  }

  /**
   * @brief Draws the life collectible (heart shape) onto the provided canvas with an offset.
   * @param canvas Pointer to the LovyanGFX sprite to draw on.
   * @param offsetX X coordinate offset (usually camera/scroll offset).
   * @param offsetY Y coordinate offset.
   */
	void draw(LGFX_Sprite* canvas, int offsetX, int offsetY) override;
};
