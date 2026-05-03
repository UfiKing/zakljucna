#pragma once
#include "Actor.hpp"

/**
 * @brief Represents a static or dynamic object in the game.
 * Inherits from Actor and adds color and drawing functionality.
 */
class Object : public Actor{
	enum ObjectTypes type = OBJECT; ///< Type identification for collision handling
protected:
	uint16_t colour;                     ///< The color of the object
public:

	/**
	 * @brief Construct a new Object.
	 * @param x Initial X coordinate.
	 * @param y Initial Y coordinate.
	 * @param width Object width.
	 * @param height Object height.
	 * @param colour Color of the object.
	 */
	Object(int16_t x, int16_t y, int16_t width, int16_t height, uint16_t colour) : Actor(x,y,width,height){
		this->colour = colour;

	}
	/**
	 * @brief Draws the object onto the provided canvas.
	 * @param canvas Pointer to the LovyanGFX sprite to draw on.
	 */
	virtual void draw(LGFX_Sprite *canvas);

	/**
	 * @brief Draws the object onto the provided canvas with an offset.
	 * @param canvas Pointer to the LovyanGFX sprite to draw on.
	 * @param offsetX X coordinate offset.
	 * @param offsetY Y coordinate offset.
	 */
	virtual void draw(LGFX_Sprite *canvas, int offsetX, int offsetY);

	/**
	 * @brief Changes the color of the object.
	 * @param newColour The new color to set.
	 */
	virtual void changeColour(uint16_t newColour);

	/**
	 * @brief Gets the current color of the object.
	 * @return uint16_t The color.
	 */
	virtual uint16_t getColour();

};
