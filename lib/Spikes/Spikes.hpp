#pragma once
#include "Object.hpp"

/**
 * @brief Represents a stationary spike obstacle in the game.
 * Inherits from Object. Colliding with a spike instantly kills the player.
 */
class Spike : public Object{
	enum ObjectTypes type = SPIKE; ///< Type identification for collision handling.
public:
	/**
	 * @brief Construct a new Spike object.
	 * @param x Initial X coordinate.
	 * @param y Initial Y coordinate.
	 * @param width Width of the spike's bounding box.
	 * @param height Height of the spike's bounding box.
	 */
	Spike(int16_t x, int16_t y, int16_t width, int16_t height) : Object(x,y,width,height, TFT_DARKGRAY){

	}

	/**
	 * @brief Draws the spike as a dark gray triangle onto the provided canvas.
	 * @param canvas Pointer to the LovyanGFX sprite to draw on.
	 */
	void draw(LGFX_Sprite* canvas);

	/**
	 * @brief Draws the spike as a dark gray triangle onto the provided canvas with an offset.
	 * @param canvas Pointer to the LovyanGFX sprite to draw on.
	 * @param offsetX X coordinate offset (usually camera scroll offset).
	 * @param offsetY Y coordinate offset.
	 */
  void draw(LGFX_Sprite* canvas, int offsetX, int offsetY);

	/**
	 * @brief Gets the type of the object.
	 * @return enum ObjectTypes Returns SPIKE.
	 */
	enum ObjectTypes getType();

};