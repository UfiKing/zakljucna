#include "player.hpp"

//player class

void Player::draw(LGFX_Sprite *canvas){
	//canvas->drawRect(position.x, position.y, width, height, colour);
	canvas->drawRect(64, position.y, width, height, getColour());
}

void Player::move(Controller* controller){

	if(controller->buttons->getUpButton() && touchedGround && !hasJumped){
		velocity.y = -jumpConstant; // Use assignment to guarantee exact jump height
		touchedGround = false;	
		hasJumped = true;
	}else if(!controller->buttons->getUpButton() && hasJumped){
		hasJumped = false;
	}

  if (controller->buttons->getLeftButton()){
    position.x -= speed;
  }else if(controller->buttons->getRightButton()){
    position.x += speed;
  }
}

void Player::update(Controller* controller){
	move(controller);
	applyGravity();
}

void Player::applyGravity(){
  velocity.y += gravityConstant; // Apply gravity
  // Cap falling speed to maxSpeed
  if (velocity.y > maxSpeed) {
    velocity.y = maxSpeed;
  }

	position += velocity;
}

void Player::resetVelocity(){
  velocity.x = 0;
  velocity.y = 0;
}

void Player::setVelocityY(int16_t v){
  velocity.y = v;
}

Vektor<int16_t> Player::getVelocity() const { return velocity; }

void Player::resize(uint8_t size){
	width = size;	
	height = size;
}

void Player::resetSize(){
	width = defaultSize;
	height = defaultSize;	
}

void Player::changeSpeed(int16_t speed){
	this->speed = speed;
}

void Player::resetSpeed(){
	this->speed = this->defaultSpeed;
}

void Player::changeJump(int16_t jump){
	this->jumpConstant = jump;
}

void Player::resetJump(){
	this->jumpConstant = this->defaultJump;
}

