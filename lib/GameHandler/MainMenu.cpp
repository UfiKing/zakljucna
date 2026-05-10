#include "MainMenu.hpp"


void MainMenu::reset(){
	currentScreen = WELCOME;
	exit = false;
}

void MainMenu::update(){
	switch(currentScreen){
		case WELCOME:
			updateWelcome();
			break;
		case CREDITSSCREEN:
			updateCredits();
			break;
	}
}

void MainMenu::draw(){
	switch(currentScreen){
		case WELCOME:
			drawWelcome();
			break;
		case CREDITSSCREEN:
			drawCredits();
			break;
	}
}

void MainMenu::drawWelcome(){

	canvas->fillScreen(backgroundColour);
	canvas->setTextColor(TFT_BLACK, backgroundColour);
	canvas->setTextSize(2.5);
	canvas->setCursor(40,10);
	canvas->println("BLOCK");

	canvas->setCursor(25,30);
	canvas->println("JUMPING");

	canvas->setTextSize(1);
	canvas->setCursor(60,65);
	canvas->println("play");

	canvas->setCursor(60,80);
	canvas->println("credits");

	if(pointer == PLAY){
		canvas->fillTriangle(53,65, 58, 68, 53,71,TFT_BLACK);
	}else if(pointer == CREDITS){
		canvas->fillTriangle(53,80, 58, 83, 53,86,TFT_BLACK);
	}
	
}

void MainMenu::updateWelcome(){
	if(controller->buttons->getDownButton()){
		pointer = CREDITS;
	}else if(controller->buttons->getUpButton()){
		pointer = PLAY;
	}else if(controller->buttons->getRightButton()){
		if(pointer == PointerPositions::CREDITS) currentScreen = CREDITSSCREEN;
		//else if(pointer == PLAY) currentScreen = PLAYSCREEN;

		else if(pointer == PLAY) exit = true;
	}
}

void MainMenu::drawCredits(){
	canvas->fillScreen(backgroundColour);
	canvas->setTextColor(TFT_BLACK,TFT_SKYBLUE);
	canvas->setTextSize(2.5);
	canvas->setCursor(25,10);
	canvas->println("CREDITS");
	canvas->setTextSize(1);
	canvas->setCursor(6,50);
	canvas->println("This game was made by ufi");

	canvas->setCursor(8,70);
	canvas->println("Press back (green button)");

	canvas->setCursor(50,80);
	canvas->println("To go back");
}

void MainMenu::updateCredits(){
	if(controller->buttons->getLeftButton()) currentScreen = WELCOME;
}