#include "GameHandler.hpp"
#include "LCD.hpp"

void GameHandler::draw(){
	canvas.fillScreen(TFT_BLACK);

  for (Actor* actor : objects){
    actor->draw(&canvas);
  }


	canvas.pushSprite(0,0);
}

void GameHandler::update(){
}

void GameHandler::addObject(Actor* newObj){
  objects.push_back(newObj);
}

void GameHandler::removeObject(Actor* obj){}