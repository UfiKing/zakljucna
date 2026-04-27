#pragma once
#include <LovyanGFX.hpp>
#include <vector> 
#include "Actor.hpp"
#include "LCD.hpp"
#include "joystick.hpp"

class GameHandler {
  LGFX_Sprite canvas;
  Player *player;
  std::vector<Actor*> objects;
	Joystick joystick = Joystick();

public:
  GameHandler(LGFX_Lcd *lcd) : objects(100, nullptr){
  	lcd->setRotation(3);
		lcd->init();

		canvas = LGFX_Sprite(lcd);
		canvas.createSprite(lcd->width(), lcd->height());

	}
    
  ~GameHandler(){
		for(Actor* obj : objects){
			delete obj;
		}
		
		delete player;
  }

  void draw();
	void update();
  void addObject(Actor* newObj);
  void removeObject(Actor* obj);
};