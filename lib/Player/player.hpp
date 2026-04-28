#pragma once
#include "joystick.hpp"
#include "Vektor.hpp"
#include "Actor.hpp"

/**
 * @brief Represents the player character in the game.
 * Handles physics (like gravity and velocity) and updates based on joystick input.
 */
class Player : public Actor{
protected:
  int8_t speed = 2;                  ///< Horizontal movement speed applied per frame
  const int16_t gravityConstant = 1; ///< Downward force applied each frame to simulate gravity
  const int8_t maxSpeed = 2;         ///< Maximum velocity limit (for both axes)
  Vektor<int16_t> velocity;          ///< Current movement velocity vector of the player
public:
  
  /**
   * @brief Construct a new Player object.
   * @param x Initial X coordinate.
   * @param y Initial Y coordinate.
   * @param width Player width.
   * @param height Player height.
   */
  Player(int16_t x, int16_t y, uint16_t width, uint16_t height) : Actor(x, y, width, height){
		colour = TFT_GREEN;
  } 

  /**
   * @brief Draws the player onto the provided canvas.
   * @param canvas Pointer to the LovyanGFX sprite to draw on.
   */
	void draw(LGFX_Sprite *canvas);

  /**
   * @brief Main update loop for the player. Applies physics and handles inputs.
   * @param joystick Pointer to the joystick to read inputs from.
   */
	void update(Joystick *joystick);	

  /**
   * @brief Applies gravitational force and limits the velocity to maxSpeed.
   */
  void applyGravity();

  /**
   * @brief Updates the player's horizontal position based on joystick input.
   * @param joystick Pointer to the joystick reading horizontal inputs.
   */
	void move(Joystick *joystick);

  /** @brief Gets the current X position. */
  int16_t getX() const;
  /** @brief Gets the current Y position. */
  int16_t getY() const;
  /** @brief Gets the current velocity vector. */
  Vektor<int16_t> getVelocity() const;
  /** @brief Gets the left edge coordinate (same as X). */
  int16_t getLeft() const;
  /** @brief Gets the right edge coordinate (X + width). */
  int16_t getRight() const;
  /** @brief Gets the top edge coordinate (same as Y). */
  int16_t getTop() const;
  /** @brief Gets the bottom edge coordinate (Y + height). */
  int16_t getBottom() const;
  
  /**
   * @brief Halts the player's movement by zeroing out the velocity vector.
   */
  void resetVelocity();
  
	
};
