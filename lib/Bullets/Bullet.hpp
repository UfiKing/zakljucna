#pragma once
#include "Object.hpp"
#include "ObjectTypes.hpp"
enum Direction {
  LEFT,
  RIGHT,
  UP,
  DOWN
};

/**
 * @brief Represents a projectile that moves in one direction until it hits an object.
 * Inherits from Object and adds movement functionality and collision handling.
 */
class Bullet : public Object {
protected:
  Direction direction;  ///< Movement direction of the bullet
  int16_t speed;        ///< Speed of movement in pixels per frame
  bool destroyed;       ///< Flag to indicate if bullet has hit something
    
public:
  /**
   * @brief Construct a new Bullet object.
   * @param x Initial X coordinate.
   * @param y Initial Y coordinate.
   * @param width Bullet width (usually small).
   * @param height Bullet height (usually small).
   * @param direction Direction of movement.
   * @param speed Speed in pixels per frame.
   */
  Bullet(int16_t x, int16_t y, int16_t width, int16_t height, 
        Direction direction, int16_t speed) 
      : Object(x, y, width, height, TFT_DARKGRAY) {
    this->direction = direction;
    this->speed = speed;
    this->destroyed = false;
		this->type = BULLET;
  }

  /**
   * @brief Updates the bullet's position and checks for collisions.
   */
  virtual void update();

  /**
   * @brief Check if the bullet has been destroyed.
   * @return true if destroyed, false otherwise.
   */
  bool isDestroyed() const {
    return destroyed;
  }

	/**
   * @brief Draws the bullet onto the provided canvas with an offset.
   * @param canvas Pointer to the LovyanGFX sprite to draw on.
   * @param offsetX X coordinate offset (camera scroll).
   * @param offsetY Y coordinate offset.
   */
	void draw(LGFX_Sprite* canvas, int offsetX, int offsetY);

  /**
   * @brief Sets new movement direction for the bullet.
   * @param newDirection New direction from enum Direction
   */
  void setDirection(Direction newDirection);

  /**
   * @brief Sets new speed for the bullet.
   * @param newSpeed New speed in pixels per frame
   */
  void setSpeed(int16_t newSpeed);
};
