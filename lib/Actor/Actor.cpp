#include "Actor.hpp"
#include <LovyanGFX.h>

uint16_t Actor::getHeight(){
  return height;
}

uint16_t Actor::getWidth(){
  return width;
}

void Actor::draw(LGFX_Sprite *canvas){
  // Draw the actor as a filled rectangle using its current position, dimensions, and color
  canvas->fillRect(position.x, position.y, width, height, colour);
}

void Actor::draw(LGFX_Sprite *canvas, int offsetX, int offsetY){
	canvas->fillRect(position.x + offsetX, position.y + offsetY, width, height, colour);
}

void Actor::update(int16_t newX, int16_t newY){
  // Directly override the actor's coordinates
  position.x = newX;
  position.y = newY;
}

// Default empty update logic (meant to be overridden by dynamic actors like Player)
void Actor::update(){}

// --- Bounding Box Getters ---
// Note: The coordinate system origin (0,0) is at the top-left of the screen.
int16_t Actor::getLeft() const { return position.x; }
int16_t Actor::getRight() const { return position.x + width; }
int16_t Actor::getTop() const { return position.y; }
int16_t Actor::getBottom() const { return position.y + height; }

// --- Basic Coordinate Getters ---
int16_t Actor::getX() const { return position.x; }
int16_t Actor::getY() const { return position.y; }

// --- Basic Coordinate Setters ---
void Actor::setX(int16_t newX){ position.x = newX; }
void Actor::setY(int16_t newY){ position.y = newY; }

// --- Bounding Box Setters ---
void Actor::setLeft(int16_t newLeft) {
  position.x = newLeft;
}

void Actor::setRight(int16_t newRight) {
  // Adjust the X coordinate so that the right bounding edge aligns with newRight
  position.x = newRight - width;
}

void Actor::setTop(int16_t newTop) {
  position.y = newTop;
}

void Actor::setBottom(int16_t newBottom) {
  // Adjust the Y coordinate so that the bottom bounding edge aligns with newBottom
  position.y = newBottom - height;
}


void Actor::changeColour(int newColour){
	colour = newColour;
}