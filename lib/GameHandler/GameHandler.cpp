#include "GameHandler.hpp"
#include "LCD.hpp"
#include <algorithm>
#include <esp_log.h>

void GameHandler::draw(){
	// Clear the off-screen canvas to prepare for the new frame
	canvas->fillScreen(TFT_BLACK);

	// Draw all active scene objects (platforms, walls)
  for (Object* obj: objects){
		if(obj == nullptr) continue;
    obj->draw(canvas, -player->getX() + 64, 0);
  }

	for(Coin* coin: coins){
		if(coin == nullptr) continue;
		coin->draw(canvas, -player->getX() + 64, 0);
	}

	// Draw the player on top
	player->draw(canvas);

	// Push the fully drawn canvas frame to the actual LCD display
	canvas->pushSprite(0,0);
}

void GameHandler::update(){
	// Update player movements and physics state (This evaluates the jump using LAST frame's collision data)
	player->update(joystick);

	// Reset ground state BEFORE checking collisions for THIS frame
	player->touchedGround = false;

	// Update scene objects and check for collisions
	for(Object* obj : objects){
		obj->update();
		if(checkCollision(player,obj)){
			if(obj->getType() == SPIKE){
				obj->changeColour(TFT_WHITE);
			}else{
				int side = resolveCollision(player, obj);
			
				if (side == 1) { // 1 means Player landed on top of an object (Floor)
					player->touchedGround = true;
					player->setVelocityY(0); // Stop falling
				}
			}
		}
	}


	for(Coin* obj : coins){
		obj->update();
		if(checkCollision(player, obj)){
			//removeObject(obj);	
			obj->changeColour(TFT_BLUE);
		}else{
			obj->changeColour(TFT_GOLD);
		}
	}

}

void GameHandler::addObject(Object* newObj){
  objects.push_back(newObj);
}

void GameHandler::removeObject(Object* obj){
	// Free the memory and then remove the pointer from our active vector
	delete obj;
	objects.erase(std::remove(objects.begin(), objects.end(), obj), objects.end());
}

void GameHandler::removeObject(int pos, ObjectTypes type){
	// Delete using vector indexing. 
	switch(type){
		case ACTOR:
		case PLATFORM:
			delete objects.at(pos);
			objects.erase(objects.begin() + pos);
			break;
		case COLLECTIBLE:
			delete coins.at(pos);
			coins.erase(coins.begin() + pos);
			break;
		default:
			break;
	}
	
}

void GameHandler::addObject(Coin* newObj){
  coins.push_back(newObj);
}

void GameHandler::removeObject(Coin* obj){
	// Free the memory and then remove the pointer from our active vector
	delete obj;
	coins.erase(std::remove(coins.begin(), coins.end(), obj), coins.end());
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

bool GameHandler::checkCollision(Actor* obj1, Coin* obj2){
	// Standard Axis-Aligned Bounding Box (AABB) Collision Detection
	// Checks if any gap exists between the objects on any axis. If no gap exists, they are colliding.
	bool test1 = obj1->getLeft() > obj2->getRight() - obj2->getRadius();
	bool test2 = obj1->getRight() < obj2->getLeft() - obj2->getRadius();
	bool test3 = obj1->getBottom() < obj2->getTop() - obj2->getRadius();
	bool test4 = obj1->getTop() > obj2->getBottom() - obj2->getRadius(); 
	return !(test1 || test2 || test3 || test4);
}

int8_t GameHandler::resolveCollision(Actor* obj1, Actor* obj2){
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
		return 1;
	} else if (minOverlap == overlapBottom) {
		obj1->setTop(obj2->getBottom());
		return 2;
	} else if (minOverlap == overlapLeft) {
		obj1->setRight(obj2->getLeft());
		return 3;
	} else if (minOverlap == overlapRight) {
		obj1->setLeft(obj2->getRight());
		return 4;
	}
	return 0;
}

int8_t GameHandler::resolveCollision(Actor* obj1, Coin* obj2){
	// Calculate how far obj1 has penetrated obj2 on all four sides
	int16_t overlapLeft = obj1->getRight() - obj2->getLeft() - obj2->getRadius();
	int16_t overlapRight = obj2->getRight() - obj1->getLeft() - obj2->getRadius();
	int16_t overlapTop = obj1->getBottom() - obj2->getTop() - obj2->getRadius();
	int16_t overlapBottom = obj2->getBottom() - obj1->getTop() - obj2->getRadius();

	// Find the axis with the minimum penetration/overlap
	int16_t minOverlap = std::min({overlapLeft, overlapRight, overlapTop, overlapBottom});

	// Resolve the collision by pushing obj1 out of obj2 along the shortest overlap distance
	if (minOverlap == overlapTop) {
		obj1->setBottom(obj2->getTop());
		return 1;
	} else if (minOverlap == overlapBottom) {
		obj1->setTop(obj2->getBottom());
		return 2;
	} else if (minOverlap == overlapLeft) {
		obj1->setRight(obj2->getLeft());
		return 3;
	} else if (minOverlap == overlapRight) {
		obj1->setLeft(obj2->getRight());
		return 4;
	}
	return 0;
}