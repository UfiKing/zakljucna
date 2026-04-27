#include <LovyanGFX.hpp>
#include <cstdint>
#include "player.hpp"
#include <esp_adc/adc_oneshot.h>
#include "Vektor.hpp"
//player class





void Player::move(Joystick *joystick){
  int x = joystick->readX();
  int y = joystick->readY();
  if (x <= joystick->lowerResting){
    position.x -= speed;
  }else if(joystick->upperResting < x){
    position.x += speed;
  }
  
  if (y <= joystick->lowerResting){
    position.y -= speed;
  }else if(joystick->upperResting < y){
    position.y += speed;
  }

}

void Player::applyGravity(uint16_t dt){
  velocity += Vektor((int16_t)0,(int16_t)gravityConstant);
  if (velocity.x >= maxSpeed) velocity.x = maxSpeed;
  if (velocity.y >= maxSpeed) velocity.y = maxSpeed;
  position += velocity;
}

void Player::resetVelocity(){
  velocity.x = 0;
  velocity.y = 0;
}

