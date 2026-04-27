#pragma once
#include <LovyanGFX.hpp>
#include <vector> 
#include "Actor.hpp"
#include "LCD.hpp"
#include "joystick.hpp"
#include "player.hpp"
class GameHandler {
  LGFX_Sprite *canvas;
  Player *player;
  std::vector<Actor*> objects;
  LGFX_Lcd *lcd_ptr;
	//Joystick joystick = Joystick();

public:
  GameHandler(LGFX_Lcd *lcd) : lcd_ptr(lcd) {
		// Pre-allocate memory for 100 objects to improve performance, but keep it empty initially
		objects.reserve(100);
	}
    
  void init() {
		lcd_ptr->setRotation(3);
		lcd_ptr->init();

		canvas = new LGFX_Sprite(lcd_ptr);
		canvas->createSprite(lcd_ptr->width(), lcd_ptr->height());
		player = new Player(64,20,25,25);
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
	void removeObject(int pos);
	bool checkCollision(Actor* obj1, Actor* obj2);
	void resolveCollision(Actor* obj1, Actor* obj2);
};