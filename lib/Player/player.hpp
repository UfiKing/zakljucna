#pragma once
#include "joystick.hpp"
#include "Vektor.hpp"
#include "Actor.hpp"

class Player : public Actor{
protected:
  int8_t speed = 2;
  const int16_t gravityConstant = 1;
  const int8_t maxSpeed = 2;
  Vektor<int16_t> velocity;
public:
  
  Player(int16_t x, int16_t y, uint16_t width, uint16_t height) : Actor(x, y, width, height){
		colour = TFT_GREEN;
  } 

	void draw(LGFX_Sprite *canvas);
	void update();	
  void applyGravity();
	void move(Joystick *joystick);

  int16_t getX() const;
  int16_t getY() const;
  Vektor<int16_t> getVelocity() const;
  int16_t getLeft() const;
  int16_t getRight() const;
  int16_t getTop() const;
  int16_t getBottom() const;
  void resetVelocity();
  
	
};
