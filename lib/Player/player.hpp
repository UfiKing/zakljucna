#pragma once
#include "Object.hpp"
#include "Controller.hpp"

/**
 * @brief Represents the player character in the game.
 * Handles physics (like gravity and velocity) and updates based on joystick input.
 */
class Player : public Object{
protected:
  int8_t speed = 2;                  ///< Horizontal movement speed applied per frame
  const int16_t gravityConstant = 1; ///< Downward force applied each frame to simulate gravity
  const int8_t maxSpeed = 4;         ///< Maximum velocity limit (for both axes)
	const int8_t jumpConstant = 6;	   ///< Force applied when jumping
	bool hasJumped = false;			 			 ///< Prevents jumping every frame
  Vektor<int16_t> velocity;          ///< Current movement velocity vector of the player
	enum ObjectTypes type = PLAYER;
public:
	bool touchedGround = true;				  ///< Indicates if the player is currently touching the ground (prevents double jumping)

  /**
   * @brief Construct a new Player object.
   * @param x Initial X coordinate.
   * @param y Initial Y coordinate.
   * @param width Player width.
   * @param height Player height.
   */
  Player(int16_t x, int16_t y, uint16_t width, uint16_t height) : Object(x, y, width, height, TFT_PINK){

  }

  /**
   * @brief Draws the player onto the provided canvas.
   * @param canvas Pointer to the LovyanGFX sprite to draw on.
   */
	void draw(LGFX_Sprite* canvas);


	void update(Controller* controller);	

  /**
   * @brief Applies gravitational force and limits the velocity to maxSpeed.
   */
  void applyGravity();


	void move(Controller* controller);

  /** @brief Gets the current velocity vector. */
  Vektor<int16_t> getVelocity() const;
  
	/**
   * @brief Halts the player's movement by zeroing out the velocity vector.
   */
  void resetVelocity();
  
  /**
   * @brief Allows direct override of the Y velocity (useful for stopping gravity on floors).
   */
  void setVelocityY(int16_t v);
	
};
