#include "player.hpp"


void Player::draw(LGFX_Sprite *canvas){
	// Draw the player at a fixed screen X-coordinate (64) while world objects move around them.
	// This creates a side-scrolling camera effect centered on the player.
	canvas->drawRect(64, position.y, width, height, getColour());
}

void Player::move(Controller* controller){

	// Decay horizontal velocity (used for wall jump push-back momentum)
	if (velocity.x > 0) velocity.x--;
	else if (velocity.x < 0) velocity.x++;

	// Jump and Wall Jump logic
	if(controller->buttons->getUpButton() && !hasJumped){
		if (touchedGround) {
			velocity.y = -jumpConstant; // Use assignment to guarantee exact jump height
			touchedGround = false;	
			hasJumped = true;
		} else if (touchingWallRight) {
			velocity.y = -jumpConstant;
			velocity.x = -(speed * 3); // Push left, away from the right wall
			hasJumped = true;
		} else if (touchingWallLeft) {
			velocity.y = -jumpConstant;
			velocity.x = speed * 3; // Push right, away from the left wall
			hasJumped = true;
		}
	} else if(!controller->buttons->getUpButton() && hasJumped){
		hasJumped = false;
	}

  // Horizontal movement logic
  if (controller->buttons->getLeftButton()){
    position.x -= speed;
  }else if(controller->buttons->getRightButton()){
    position.x += speed;
  }

  // Wall sliding (slows down falling speed when hugging a wall)
  if ((touchingWallLeft || touchingWallRight) && !touchedGround && velocity.y > 0) {
    velocity.y = 1; 
  }
}

void Player::update(Controller* controller){
	// Execute movement logic and then apply gravity to the player
	move(controller);
	applyGravity();
}

void Player::applyGravity(){
  velocity.y += gravityConstant; // Apply gravity
  // Cap falling speed to maxSpeed
  if (velocity.y > maxSpeed) {
    velocity.y = maxSpeed;
  }

	// Update physical position based on the current velocity vector
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
