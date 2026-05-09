#pragma once
#include "Object.hpp"
#include "Controller.hpp"

/**
 * @brief Represents the player character in the game.
 * Handles physics (like gravity and velocity) and updates based on joystick input.
 */
class Player : public Object{
protected:
  const int16_t gravityConstant = 1; ///< Downward force applied each frame to simulate gravity
	const uint8_t defaultMaxSpeed = 4; ///< Default maximum downward velocity (terminal falling speed)
	const int8_t defaultSize = 5;      ///< Default width and height of the player's bounding box
	const uint8_t defaultJump = 7;     ///< Default force applied when jumping
	const uint8_t defaultSpeed = 2;    ///< Default horizontal movement speed
  uint8_t speed = defaultSpeed;                  ///< Horizontal movement speed applied per frame
  uint8_t maxSpeed = defaultMaxSpeed;         ///< Maximum downward velocity limit (terminal falling speed)
	uint8_t jumpConstant = defaultJump;	   ///< Force applied when jumping
	bool hasJumped = false;			 			 ///< Prevents continuous jumping while the jump button is held down
  Vektor<int16_t> velocity;          ///< Current movement velocity vector of the player
	enum ObjectTypes type = PLAYER;    ///< Type identification for collision handling
public:
	bool touchedGround = true;				  ///< Indicates if the player is currently touching the ground (prevents double jumping)
	bool touchingWallLeft = false;			  ///< True if the player is touching a wall on their left
	bool touchingWallRight = false;			  ///< True if the player is touching a wall on their right


  /**
   * @brief Construct a new Player object.
   * @param x Initial X coordinate.
   * @param y Initial Y coordinate.
   */
  Player(int16_t x, int16_t y) : Object(x, y, 5, 5, TFT_PINK){

  }

  /**
   * @brief Draws the player onto the provided canvas at a fixed screen X-coordinate.
   * This creates a side-scrolling camera effect, ignoring the physical X position for rendering.
   * @param canvas Pointer to the LovyanGFX sprite to draw on.
   */
	void draw(LGFX_Sprite* canvas);

  /**
   * @brief Master update function for the player.
   * Handles both controller-based movement and physical gravity application.
   * @param controller Pointer to the gamepad controller instance.
   */
	void update(Controller* controller);	

  /**
   * @brief Applies gravitational force and limits the velocity to maxSpeed.
   */
  void applyGravity();

  /**
   * @brief Handles movement logic including walking, jumping, and wall sliding based on input.
   * @param controller Pointer to the gamepad controller instance.
   */
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
	
	/**
	 * @brief Changes the player's bounding box size.
	 * @param size The new width and height.
	 */
	void resize(uint8_t size);

	/**
	 * @brief Resets the player's bounding box size back to defaultSize.
	 */
	void resetSize();

	/**
	 * @brief Temporarily changes the player's horizontal movement speed.
	 * @param speed The new movement speed.
	 */
	void changeSpeed(int16_t speed);

	/**
	 * @brief Resets the player's movement speed back to defaultSpeed.
	 */
	void resetSpeed();

	/**
	 * @brief Temporarily changes the player's jump force.
	 * @param jump The new jump force applied.
	 */
	void changeJump(int16_t jump);

	/**
	 * @brief Resets the player's jump force back to defaultJump.
	 */
	void resetJump();
};
