#include "GameHandler.hpp"
#include "LCD.hpp"
#include <algorithm>
#include <esp_log.h>
void GameHandler::draw(){
	canvas->fillScreen(TFT_BLACK);

  for (Actor* actor : objects){
		if(actor == nullptr) continue;
    actor->draw(canvas);
  }
	player->draw(canvas);

	canvas->pushSprite(0,0);
}

void GameHandler::update(){
	player->update();
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
	delete obj;
	objects.erase(std::remove(objects.begin(), objects.end(), obj), objects.end());
}

void GameHandler::removeObject(int pos){
	delete objects.at(pos);
	objects.erase(objects.begin() + pos - 1);
}

bool GameHandler::checkCollision(Actor* obj1, Actor* obj2){
	bool test1 = obj1->getLeft() > obj2->getRight();
	bool test2 = obj1->getRight() < obj2->getLeft();
	bool test3 = obj1->getBottom() < obj2->getTop();
	bool test4 = obj1->getTop() > obj2->getBottom(); 
	return !(test1 || test2 || test3 || test4);
}

void GameHandler::resolveCollision(Actor* obj1, Actor* obj2){
	int16_t overlapLeft = obj1->getRight() - obj2->getLeft();
	int16_t overlapRight = obj2->getRight() - obj1->getLeft();
	int16_t overlapTop = obj1->getBottom() - obj2->getTop();
	int16_t overlapBottom = obj2->getBottom() - obj1->getTop();

	int16_t minOverlap = std::min({overlapLeft, overlapRight, overlapTop, overlapBottom});

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