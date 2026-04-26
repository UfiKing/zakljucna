#pragma once
#include "joystick.hpp"
#include "Vektor.hpp"
#include "Actor.hpp"

class Player : public Actor{
protected:
  int8_t speed = 2;
  const int8_t gravityConstant = 1;
  const int8_t maxSpeed = 6;
  Vektor<int16_t> velocity;
public:
  
  Player(int16_t x, int16_t y, uint16_t width, uint16_t height, LGFX_Sprite *canvas) : Actor(x, y, width, height, canvas){
    //konstruktor
  } 

  void draw();
  void move(Joystick *joystick);
  void applyGravity(uint16_t dt);
  void resetVelocity();
  
};




