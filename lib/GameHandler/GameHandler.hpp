#pragma once
#include <LovyanGFX.hpp>
#include <vector> 
#include "Actor.hpp"
#include "LCD.hpp"
#include "joystick.hpp"
#include "player.hpp"

/**
 * @brief Central game manager responsible for handling the main game loop,
 * rendering to the LCD, maintaining game objects, and managing collisions.
 */
class GameHandler {
  LGFX_Sprite *canvas;         ///< Off-screen buffer/sprite for double-buffered rendering
  Player *player;              ///< The active player instance
  std::vector<Actor*> objects; ///< List of active game world objects (platforms, obstacles)
  LGFX_Lcd *lcd_ptr;           ///< Pointer to the physical LCD screen structure
  Joystick *joystick;          ///< Handles joystick and button inputs

public:
  /**
   * @brief Construct a new GameHandler object.
   * @param lcd Pointer to the LovyanGFX LCD instance.
   */
  GameHandler(LGFX_Lcd *lcd) : lcd_ptr(lcd) {
		// Pre-allocate memory for 100 objects to improve performance, but keep it empty initially
		objects.reserve(100);
	}
    
  /**
   * @brief Initializes the LCD, the canvas sprite, player, and joystick hardware.
   */
  void init() {
		lcd_ptr->setRotation(3);
		lcd_ptr->init();

		canvas = new LGFX_Sprite(lcd_ptr);
		canvas->createSprite(lcd_ptr->width(), lcd_ptr->height());
		player = new Player(40,20,10,10);
		joystick = new Joystick();
  }

  /**
   * @brief Destructor clears out any dynamically allocated objects to free memory.
   */
  ~GameHandler(){
		for(Actor* obj : objects){
			delete obj;
		}
		
		delete player;
  }

  /**
   * @brief Renders the entire scene (background, objects, player) onto the sprite,
   * and then pushes it to the display.
   */
  void draw();

  /**
   * @brief Advances the game state by updating player logic, object logic,
   * and running collision detection and resolution.
   */
	void update();

  /**
   * @brief Adds a new Actor object to the game scene.
   * @param newObj Pointer to the Actor to be added.
   */
  void addObject(Actor* newObj);

  /**
   * @brief Removes a specific Actor from the scene by its pointer.
   * @param obj Pointer to the Actor to be deleted and removed.
   */
  void removeObject(Actor* obj);

  /**
   * @brief Removes an Actor from the scene by its vector index.
   * @param pos Index of the object in the vector.
   */
	void removeObject(int pos);

  /**
   * @brief Checks if two Actor objects are physically colliding.
   * @return true If the two objects intersect.
   */
	bool checkCollision(Actor* obj1, Actor* obj2);

  /**
   * @brief Resolves a detected collision by shifting obj1 out of obj2 along the axis of least penetration.
   * @return int The side of obj2 that obj1 collided with: 1=Top, 2=Bottom, 3=Left, 4=Right.
   */
	int resolveCollision(Actor* obj1, Actor* obj2);
};