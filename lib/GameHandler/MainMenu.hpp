#pragma once
#include <LovyanGFX.hpp>
#include "Controller.hpp"

enum MainMenuScreens{
	WELCOME,
	CREDITSSCREEN,
};

enum PointerPositions{
	PLAY,
	CREDITS
};

class MainMenu{
	LGFX_Sprite* canvas;
	enum MainMenuScreens currentScreen = WELCOME;
	enum PointerPositions pointer = PLAY;
	Controller* controller;
	int backgroundColour = TFT_SKYBLUE;
public:
	bool exit = false;	
	MainMenu(LGFX_Sprite* canvas, Controller* controller){
		this->canvas = canvas;
		this->controller = controller;
	}

	void draw();

	void drawWelcome();

	void drawCredits();

	void update();

	void updateWelcome();

	void updateCredits();

};