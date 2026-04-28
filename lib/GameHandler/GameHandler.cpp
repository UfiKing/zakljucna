#include "GameHandler.hpp"
#include "LCD.hpp"
#include <algorithm>
#include <esp_log.h>

void GameHandler::draw(){
	// Clear the off-screen canvas to prepare for the new frame
	canvas->fillScreen(TFT_BLACK);

	// Draw all active scene objects (platforms, walls)
  for (Actor* actor : objects){
		if(actor == nullptr) continue;
    actor->draw(canvas);
  }
	// Draw the player on top
	player->draw(canvas);

	// Push the fully drawn canvas frame to the actual LCD display
	canvas->pushSprite(0,0);
}

void GameHandler::update(){
	// Update player movements and physics state
	player->update(joystick);
	
	// Update scene objects and check for collisions
	for(Actor* obj : objects){
		obj->update();
		if(checkCollision(player,obj)){
			resolveCollision(player, obj);
		}
	}
}

void GameHandler::addObject(Actor* newObj){
  objects.push_back(newObj);
}

void GameHandler::removeObject(Actor* obj){
	// Free the memory and then remove the pointer from our active vector
	delete obj;
	objects.erase(std::remove(objects.begin(), objects.end(), obj), objects.end());
}

void GameHandler::removeObject(int pos){
	// Delete using vector indexing. (Note: using pos-1 looks like a 1-based index offset logic)
	delete objects.at(pos);
	objects.erase(objects.begin() + pos - 1);
}

bool GameHandler::checkCollision(Actor* obj1, Actor* obj2){
	// Standard Axis-Aligned Bounding Box (AABB) Collision Detection
	// Checks if any gap exists between the objects on any axis. If no gap exists, they are colliding.
	bool test1 = obj1->getLeft() > obj2->getRight();
	bool test2 = obj1->getRight() < obj2->getLeft();
	bool test3 = obj1->getBottom() < obj2->getTop();
	bool test4 = obj1->getTop() > obj2->getBottom(); 
	return !(test1 || test2 || test3 || test4);
}

void GameHandler::resolveCollision(Actor* obj1, Actor* obj2){
	// Calculate how far obj1 has penetrated obj2 on all four sides
	int16_t overlapLeft = obj1->getRight() - obj2->getLeft();
	int16_t overlapRight = obj2->getRight() - obj1->getLeft();
	int16_t overlapTop = obj1->getBottom() - obj2->getTop();
	int16_t overlapBottom = obj2->getBottom() - obj1->getTop();

	// Find the axis with the minimum penetration/overlap
	int16_t minOverlap = std::min({overlapLeft, overlapRight, overlapTop, overlapBottom});

	// Resolve the collision by pushing obj1 out of obj2 along the shortest overlap distance
	if (minOverlap == overlapTop) {
		obj1->setBottom(obj2->getTop());
	} else if (minOverlap == overlapBottom) {
		obj1->setTop(obj2->getBottom());
	} else if (minOverlap == overlapLeft) {
		obj1->setRight(obj2->getLeft());
	} else if (minOverlap == overlapRight) {
		obj1->setLeft(obj2->getRight());
	}
}