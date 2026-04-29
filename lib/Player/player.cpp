#include <LovyanGFX.hpp>
#include <cstdint>
#include "player.hpp"
#include <esp_adc/adc_oneshot.h>
#include "Vektor.hpp"
#include <esp_log.h>
#include <cmath>
//player class



void Player::draw(LGFX_Sprite *canvas){
	//canvas->drawRect(position.x, position.y, width, height, colour);
	canvas->drawRect(64, position.y, width, height, getColour());
}

void Player::move(Joystick *joystick){
  int x = joystick->readX();

	if(joystick->readButton() && touchedGround && !hasJumped){
		velocity.y = -jumpConstant; // Use assignment to guarantee exact jump height
		touchedGround = false;	
		hasJumped = true;
	}else if(!joystick->getButton() && hasJumped){
		hasJumped = false;
	}

  if (x <= joystick->lowerResting){
    position.x -= speed;
  }else if(joystick->upperResting < x){
    position.x += speed;
  }
  
}

void Player::update(Joystick *joystick){
	move(joystick);
	applyGravity();
}

void Player::applyGravity(){
	position += velocity;

  velocity.y += gravityConstant; // Apply gravity
  // Cap falling speed to maxSpeed
  if (velocity.y > maxSpeed) {
    velocity.y = maxSpeed;
  }
}

void Player::resetVelocity(){
  velocity.x = 0;
  velocity.y = 0;
}

void Player::setVelocityY(int16_t v){
  velocity.y = v;
}

Vektor<int16_t> Player::getVelocity() const { return velocity; }

