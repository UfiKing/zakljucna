#pragma once
#include <LovyanGFX.hpp>
#include "Controller.hpp"

// Enum to define the different screens within the MainMenu state machine
enum MainMenuScreens{
	WELCOME,
	CREDITSSCREEN,
};

// Enum to define the selectable options/pointer positions on the menu
enum PointerPositions{
	PLAY,
	CREDITS
};

class MainMenu{
	LGFX_Sprite* canvas;      ///< Pointer to the canvas/sprite buffer for rendering
	enum MainMenuScreens currentScreen = WELCOME; ///< Tracks which screen is currently active
	enum PointerPositions pointer = PLAY;         ///< Tracks the current menu selection highlight
	Controller* controller; ///< Pointer to the controller input handler
	int backgroundColour = TFT_SKYBLUE; ///< Background color constant for the menu
public:
	bool exit = false;	///< Flag to signal exit from the main menu back to the game loop
	MainMenu(LGFX_Sprite* canvas, Controller* controller){
		this->canvas = canvas;
		this->controller = controller;
	}

	/**
	 * @brief Updates input state and navigates between screens.
	 */
	void update();

	/**
	 * @brief Renders the current screen to the canvas.
	 */
	void draw();

	/**
	 * @brief Draws the Welcome screen content (title, options, pointer).
	 */
	void drawWelcome();

	/**
	 * @brief Draws the Credits screen content (text, instructions).
	 */
	void drawCredits();

	/**
	 * @brief Handles input logic for the Welcome screen (navigation, selection).
	 */
	void updateWelcome();

	/**
	 * @brief Handles input logic for the Credits screen (navigation).
	 */
	void updateCredits();

	void reset();

};