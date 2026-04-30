#pragma once
#include <LovyanGFX.hpp>
#include <vector> 
#include "Actor.hpp"
#include "LCD.hpp"
#include "joystick.hpp"
#include "player.hpp"
#include "Collectible.hpp"
#include "ObjectTypes.hpp"
#include "Spikes.hpp"

enum Screens {
	START,
	GAME,
	DEATH
};

/*
 * @brief Central game manager responsible for handling the main game loop,
 * rendering to the LCD, maintaining game objects, and managing collisions.
 */
class GameHandler {
  LGFX_Sprite *canvas;         ///< Off-screen buffer/sprite for double-buffered rendering
  Player *player;              ///< The active player instance
  std::vector<Object*> objects; ///< List of active game world objects (platforms, obstacles)
	std::vector<Coin*> coins;		 ///< List of active coins in the world
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
		coins.reserve(10);
	}
    
  /**
   * @brief Initializes the LCD, the canvas sprite, player, and joystick hardware.
   */
  void init() {
		lcd_ptr->setRotation(3);
		lcd_ptr->init();

		canvas = new LGFX_Sprite(lcd_ptr);
		canvas->createSprite(lcd_ptr->width(), lcd_ptr->height());
		player = new Player(20,20,10,10);
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
  void addObject(Object* newObj);

  /**
   * @brief Removes a specific Actor from the scene by its pointer.
   * @param obj Pointer to the Actor to be deleted and removed.
   */
  void removeObject(Object* obj);

  /**
   * @brief Removes an object from the scene by its index and type.
   * @param pos The index of the object in its respective list.
   * @param type The type of the object to determine which list to remove from.
   */
	void removeObject(int pos, ObjectTypes type);

  /**
   * @brief Adds a new Coin object to the game scene.
   * @param newObj Pointer to the Coin to be added.
   */
  void addObject(Coin* newObj);

  /**
   * @brief Removes a specific Coin from the scene by its pointer.
   * @param obj Pointer to the Coin to be deleted and removed.
   */
  void removeObject(Coin* obj);

  /**
   * @brief Checks if two Actor objects are physically colliding.
   * @param obj1 First actor to check.
   * @param obj2 Second actor to check.
   * @return true If the two objects intersect.
   */
	bool checkCollision(Actor* obj1, Actor* obj2);
	
  /**
   * @brief Checks if an Actor object and a Coin are physically colliding.
   * Takes the coin's circular bounds into consideration using its radius.
   * @param obj1 The Actor.
   * @param obj2 The Coin.
   * @return true If the two objects intersect.
   */
  bool checkCollision(Actor* obj1, Coin* obj2);

  /**
   * @brief Resolves a detected collision by shifting obj1 out of obj2 along the axis of least penetration.
   * @param obj1 First actor involved in the collision.
   * @param obj2 Second actor involved in the collision.
   * @return int The side of obj2 that obj1 collided with: 1=Top, 2=Bottom, 3=Left, 4=Right.
   */
	int8_t resolveCollision(Actor* obj1, Actor* obj2);

  /**
   * @brief Resolves a detected collision between an Actor and a Coin.
   * @param obj1 The Actor.
   * @param obj2 The Coin.
   * @return int The side of obj2 that obj1 collided with: 1=Top, 2=Bottom, 3=Left, 4=Right.
   */
	int8_t resolveCollision(Actor* obj1, Coin* obj2);
};