#pragma once
#include "Spikes.hpp"

/**
 * @brief Represents a moving spike obstacle in the game.
 * Inherits from Spike. It patrols back and forth horizontally between two X boundaries.
 */
class MovingSpike : public Spike{
protected:
	int16_t x1;    ///< Left X boundary for the patrol path.
	int16_t y1;    ///< Starting Y coordinate (Note: Vertical movement is currently unimplemented).
	int16_t x2;    ///< Right X boundary for the patrol path.
	int16_t y2;    ///< Target Y coordinate (Note: Vertical movement is currently unimplemented).
	int16_t speed; ///< Horizontal movement speed applied per frame.
public:
	/**
	 * @brief Construct a new Moving Spike object.
	 * @param x1 Left boundary X coordinate.
	 * @param y1 Starting Y coordinate.
	 * @param x2 Right boundary X coordinate.
	 * @param y2 Target Y coordinate.
	 * @param width Width of the spike's bounding box.
	 * @param height Height of the spike's bounding box.
	 * @param speed Horizontal movement speed in pixels per frame.
	 */
	MovingSpike(int16_t x1, int16_t y1, int16_t x2, int16_t y2, int16_t width, int16_t height, int16_t speed) : Spike(x1, y1, width, height){
		this->x1 = x1;
		this->y1 = y1;
		this->x2 = x2;
		this->y2 = y2;
		this->speed = speed;
		this->type = SPIKE;
	}

	/**
	 * @brief Draws the moving spike onto the provided canvas with an offset.
	 * @param canvas Pointer to the LovyanGFX sprite to draw on.
	 * @param offsetX X coordinate offset.
	 * @param offsetY Y coordinate offset.
	 */
	void draw(LGFX_Sprite* canvas, int offsetX, int offsetY) override;

	/**
	 * @brief Updates the spike's horizontal position and reverses its speed when hitting x1 or x2.
	 */
	void update() override;
};