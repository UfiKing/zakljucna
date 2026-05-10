#pragma once
#include <LovyanGFX.hpp>
#include <vector> 
#include "Actor.hpp"
#include "LCD.hpp"
#include "player.hpp"
#include "Coin.hpp"
#include "ObjectTypes.hpp"
#include "Spikes.hpp"
#include "GameHandler.hpp"
#include "Platform.hpp"
#include "MovingSpikes.hpp"
#include "Collectible.hpp"
#include "LifeCollectible.hpp"
#include "MainMenu.hpp"

/**
 * @brief Enumeration for the different game states/screens.
 */
enum Screens {
	START,    ///< The initial start screen shown upon boot.
	GAME,     ///< The main active gameplay screen.
	DEATH,    ///< The screen shown when the player dies (respawn prompt).
	GAMEOVER  ///< The screen shown when all lives are lost.
};

/**
 * @brief Central game manager responsible for handling the main game loop,
 * rendering to the LCD, maintaining game objects, and managing collisions.
 */
class GameHandler {
  LGFX_Sprite *canvas;         ///< Off-screen buffer/sprite for double-buffered rendering
  Player *player;              ///< The active player instance
  std::vector<Object*> objects; ///< List of active game world objects (platforms, obstacles)
	std::vector<Collectible*> collectibles;		 ///< List of active coins in the world
	std::vector<Object*> spawners;
	std::vector<Object*> nonCollidingObjects;
  LGFX_Lcd *lcd_ptr;           ///< Pointer to the physical LCD screen structure
  enum Screens currentScreen = START; ///< Tracks the current game screen/state for rendering and logic control
  int16_t score = 0;                  ///< Current score of the player.
	const int8_t maxLives = 5;           ///< Maximum number of lives the player starts with.
	int8_t life = maxLives;              ///< Current remaining lives.
	int16_t checkpointX;                 ///< X coordinate of the player's last checkpoint.
	int16_t checkpointY;                 ///< Y coordinate of the player's last checkpoint.
	Controller* controller;              ///< Pointer to the gamepad controller instance.
	const int16_t startingPosX = 1080;    ///< Initial player X spawn position.
	const int16_t startingPosY = 20;     ///< Initial player Y spawn position.
	int backgroundColour = TFT_BLACK;
	MainMenu* mainMenu;
public:
  /**
   * @brief Construct a new GameHandler object.
   * @param lcd Pointer to the LovyanGFX LCD instance.
   */
  GameHandler(LGFX_Lcd *lcd) : lcd_ptr(lcd) {
		// Pre-allocate memory for 100 objects to improve performance, but keep it empty initially
		objects.reserve(100);
		collectibles.reserve(10);
		spawners.reserve(10);
		nonCollidingObjects.reserve(10);
	}
    
  /**
   * @brief Initializes the LCD, the canvas sprite, player, and joystick hardware.
   */
  void init() {
		lcd_ptr->setRotation(3);
		lcd_ptr->init();
		
		canvas = new LGFX_Sprite(lcd_ptr);
		canvas->createSprite(lcd_ptr->width(), lcd_ptr->height());
		player = new Player(startingPosX,startingPosY);
		controller = new Controller();

		mainMenu = new MainMenu(canvas, controller);
  }

  /**
   * @brief Destructor clears out dynamically allocated world objects and the player.
   */
  ~GameHandler(){
		for(Object* obj : objects){
			if(obj != nullptr) delete obj;
		}
		objects.clear();

		for(Collectible* obj : collectibles){
			if(obj != nullptr) delete obj;
		}
		collectibles.clear();

		for(Object* obj : spawners){
			if(obj != nullptr) delete obj;
		}
		spawners.clear();

		for(Object* obj : nonCollidingObjects){
			if(obj != nullptr) delete obj;
		}
		nonCollidingObjects.clear();

		delete player;
		delete controller;
		delete mainMenu;
		delete canvas;
  }

  /**
   * @brief Draws a heart icon representing a life at the specified coordinates.
   * @param x The X coordinate on the screen.
   * @param y The Y coordinate on the screen.
   */
	void drawHeart(int16_t x, int16_t y);

  /**
   * @brief Loads the initial level layout, including platforms, spikes, and collectibles.
   */
  void loadLevel();

  /**
   * @brief Clears the current level layout by deleting all dynamically allocated objects
   * and collectibles, and resetting the score.
   */
  void clearLevel();

  /**
   * @brief Master draw function that delegates to specific draw methods based on the current screen state.
   * Fills the screen with black and pushes the canvas to the LCD at the end.
   */
  void draw();

  /**
   * @brief Master update function that delegates to specific update methods based on the current screen state.
   */
  void update();

  /**
   * @brief Renders the entire scene (background, objects, player, UI) onto the canvas sprite.
   * Note: This does not push to the display; that is handled by draw().
   */
  void drawGame();

  /**
   * @brief Advances the game state by updating player logic, object logic,
   * running collision detection and resolution, and managing collectibles.
   */
	void updateGame();

  /**
   * @brief Renders the start screen text.
   */
  void drawStart();

  /**
   * @brief Renders the death screen text and remaining lives.
   */
  void drawDeath();

  /**
   * @brief Renders the game over screen text.
   */
	void drawGameOver();

  /**
   * @brief Handles logic for the start screen (e.g., waiting for input to start the game).
   */
  void updateStart();

  /**
   * @brief Handles logic for the death screen, respawning at the checkpoint or moving to GAMEOVER.
   */
  void updateDeath();

  /**
   * @brief Handles logic for the game over screen, waiting for input to reset positions and restart the game.
   */
	void updateGameOver();	


  /**
   * @brief Adds a new Object to the game scene.
   * @param newObj Pointer to the Object to be added.
   */
  void addObject(Object* newObj);

  /**
   * @brief Adds a new Collectible object to the game scene.
   * @param newObj Pointer to the Collectible to be added.
   */
  void addObject(Collectible* newObj);

	void addNonCollidingObject(Object* newObj);

	void addSpawner(Object* newObj);

	int checkCollisionX(Object* obj);
	
	int checkCollisionY(Object* obj);

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