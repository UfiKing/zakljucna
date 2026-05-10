#include "GameHandler.hpp"
#include "LCD.hpp"
#include <algorithm>
#include <esp_log.h>
#include "BulletSpawner.hpp"


void GameHandler::loadLevel(){
	checkpointX = 510;
	checkpointY = 20;

	addObject(new Platform(-20,90,10,10,GRAYBRICKS));

	for(int i = 0; i < 5; i++){
		addObject(new Spike(130 + i * 20,100,10,4));
	}

	for(int i = 0; i < 3; i++){
		addObject(new Spike(230 + i * 10,100,10,10));
	}

	addObject(new Spike(270,100,10,4));
	//na unmu velkmu letecem boxu
	for(int i = 0; i < 10; i++){
		addObject(new Spike(365+i*5,61,5,5));
	}

	addObject(new Coin(245,46,5));
	addObject(new LifeCollectible(387,22));
	addObject(new Coin(352,32,5));
	addObject(new Coin(427,32,5));
	
	addObject(new Coin(575,62,5));
	addObject(new Coin(585,62,5));
	addObject(new Coin(615,62,5));
	addObject(new Coin(625,62,5));
	addObject(new Coin(635,62,5));
	addObject(new Coin(645,62,5));

	//addObject(new MovingSpike(290, 100, 480, 100, 10,10,1));
 
 
  addObject(new Object(-60,0,10,100,TFT_DARKGRAY));
  addObject(new Object(-60,100,780,10,TFT_DARKGRAY));
  addObject(new Object(-10,0,830,10,TFT_DARKGRAY));
  addObject(new Platform(120,90,10,10,GRAYBLOCK));
  addObject(new Platform(140,80,10,20,GRAYBLOCK));
  addObject(new Platform(160,70,10,30,GRAYBLOCK));
  addObject(new Platform(180,60,10,40,GRAYBLOCK));
  addObject(new Platform(200,60,10,40,GRAYBLOCK));
  addObject(new Platform(220,70,10,30,GRAYBLOCK));
  addObject(new Platform(240,55,10,10,GRAYBLOCK));
  addObject(new Platform(260,70,10,30,GRAYBLOCK));
  addObject(new Platform(280,80,10,20,GRAYBLOCK));
  addObject(new Platform(340,82,5,8,GRAYBRICKS));
  addObject(new Platform(340,61,5,10,GRAYBRICKS));
  addObject(new Platform(340,40,5,10,GRAYBRICKS));
  addObject(new Platform(345,40,20,50,GRAYBRICKS));
  addObject(new Platform(365,61,50,28,GRAYBRICKS));
  addObject(new Platform(415,40,20,50,GRAYBRICKS));
  addObject(new Platform(385,30,10,10,GRAYBRICKS));
  addObject(new Platform(435,82,5,8,GRAYBRICKS));
  addObject(new Platform(435,61,5,10,GRAYBRICKS));
  addObject(new Platform(435,40,5,10,GRAYBRICKS));
  addObject(new Platform(490,80,10,20,GRAYBRICKS));
  addObject(new Platform(550,30,20,40,GRAYBRICKS));
  addObject(new Platform(570,10,20,20,GRAYBRICKS));
  addObject(new Platform(570,70,20,20,GRAYBRICKS));
  addObject(new Platform(610,10,60,20,GRAYBRICKS));
  addObject(new Platform(650,30,20,40,GRAYBRICKS));
  addObject(new Platform(610,70,60,10,GRAYBRICKS));
  addObject(new Platform(735,33,30,80,GRAYBRICKS));
  addObject(new Platform(710,10,10,70,GRAYBRICKS));
  addObject(new Platform(775,30,40,10,GRAYBRICKS));
  addObject(new Platform(825,30,40,10,GRAYBRICKS));
  addObject(new Platform(765,40,100,70,GRAYBRICKS));

  addSpawner(new BulletSpawner(660,90,16,10,5000,LEFT,1,10,10)); 

	
}

void GameHandler::clearLevel(){
	score = 0;
	for(int i = 0; i < objects.size(); i++){
		if(objects[i] != nullptr) delete objects[i];	
	}
	objects.clear();
	for(int i = 0; i < collectibles.size(); i++){
		if(collectibles[i] != nullptr) delete collectibles[i];

	}
	collectibles.clear();
	for(int i = 0; i < spawners.size();i ++){
		if(spawners[i] != nullptr) delete spawners[i];
	}
	spawners.clear();
}

void GameHandler::draw(){
	// Clear the off-screen canvas to prepare for the new frame
	canvas->startWrite();
	canvas->fillScreen(TFT_NAVY);
	switch(currentScreen){
		case START:
			drawStart();
			break;
		case GAME:
			drawGame();
			break;
		case DEATH:
			drawDeath();
			break;
		case GAMEOVER:
			drawGameOver();
			break;
	}
	canvas->endWrite();
	// Push the fully drawn canvas frame to the actual LCD display
	canvas->pushSprite(0,0);

}

void GameHandler::update(){
	switch (currentScreen){
		case START:
			updateStart();
			break;
		case GAME:
			updateGame();
			break;
		case DEATH:
			updateDeath();
			break;
		case GAMEOVER:
			updateGameOver();
			break;
	}

}

void GameHandler::updateGameOver(){
	if(controller->getAnyButton()){
		// Reset player position and velocity
		player->setX(startingPosX);
		player->setY(startingPosY);
		player->resetVelocity();

		currentScreen = GAME;

		life = maxLives;
		clearLevel();
		loadLevel();
		draw();
		vTaskDelay(pdMS_TO_TICKS(500)); 
	}
}

void GameHandler::drawGameOver(){
	canvas->setTextColor(TFT_WHITE);
	canvas->setTextSize(2);
	canvas->setCursor(25, 15);
	canvas->print("Game Over!");
	canvas->setTextSize(1);
	canvas->setCursor(30, 50);
	canvas->print("Press Any Button");
	canvas->setCursor(30, 70);
	canvas->print("To Restart");
}

void GameHandler::drawStart(){
	canvas->setTextColor(TFT_WHITE);
	canvas->setTextSize(1);
	canvas->setCursor(20, 30);
	canvas->print("Press Any Button");
	canvas->setCursor(20, 70);
	canvas->print("to Start");	
}

void GameHandler::updateStart(){
	if(controller->getAnyButton()){
		currentScreen = GAME;
		draw();
		vTaskDelay(pdMS_TO_TICKS(500)); 
	}
}

void GameHandler::drawDeath(){
	canvas->setTextColor(TFT_WHITE);
	canvas->setTextSize(2);
	canvas->setCursor(25, 15);
	canvas->print("You Died!");
	canvas->setTextSize(1);
	canvas->setCursor(30, 50);
	canvas->print("Press Any Button");
	canvas->setCursor(30, 70);
	canvas->print("To Respawn");
	canvas->setCursor(30, 90);
	canvas->print("At Last Checkpoint");
	canvas->setCursor(30,110);
	canvas->print("Remaining Lives: ");
	canvas->print(life);

}

void GameHandler::updateDeath(){
	if(life == 0){
		currentScreen = GAMEOVER;
		return;
	}
	if(controller->getAnyButton()){
		// Reset player position and velocity
		player->setX(checkpointX);
		player->setY(checkpointY);
		player->resetVelocity();

		currentScreen = GAME;
		//clearLevel();
		//loadLevel();
		draw();
		vTaskDelay(pdMS_TO_TICKS(500)); 
	}
}

void GameHandler::drawGame(){
  // Draw all active scene objects (platforms, walls)

  int screenWidth = lcd_ptr->width();
  int offset = -player->getX() + 64;
  for (Object* obj: objects){
    if(obj == nullptr) continue;
    int renderX = obj->getX() - player->getX() + 64;
    if(renderX + obj->getWidth() < 0 || renderX > screenWidth) continue;
    obj->draw(canvas, offset, 0);
  }

  for(Object* obj : spawners){
    obj->draw(canvas, offset, 0);
  }

  for(Collectible* obj: collectibles){
    if(obj== nullptr) continue;
    int renderX = obj->getX() - player->getX() + 64;
    if(renderX + obj->getWidth() < 0 || renderX > screenWidth) continue;
    obj->draw(canvas, offset, 0);
  }
  canvas->fillRect(0,0,60,17,TFT_BLACK);
  canvas->setTextColor(TFT_GOLD);
  canvas->setCursor(1,1);
  canvas->print("Score: ");
  canvas->print(score);

  for(int i = 0; i < life; i++){
    drawHeart(1 + i*10,10);
  }
  // Draw the player on top
  player->draw(canvas);

}

void GameHandler::updateGame(){

	for(Object* obj : objects){
		if(obj != nullptr) obj->update();
	}

	uint32_t start_time = esp_timer_get_time();
	for(Object* obj : spawners){
		if(obj != nullptr) obj->update();		
		BulletSpawner* spawner = (BulletSpawner*)obj;
		for(Bullet* bullet: spawner->children){
			for(Object* object : objects){
				if(checkCollision(bullet, object)) bullet->destroy();
			}
		}	
	}
	uint32_t current_time = esp_timer_get_time() - start_time;
	//ESP_LOGI("TAG", "%d", current_time);

	// 1. Move player purely on the X axis
	player->move(controller);

	// Reset wall touch states BEFORE checking new collisions
	player->touchingWallLeft = false;
	player->touchingWallRight = false;

	// Check X axis collisions
	for(Object* obj : objects){
		//if its a bullet or a spike we return
		if(checkCollisionX(obj)) return;
			
	}

	for(Object* obj : spawners){
		//if its a bullet or a spike we return
		if(checkCollisionX(obj)) return;
		BulletSpawner* spawner = (BulletSpawner*)obj;
		for(Bullet* child : spawner->children){
			if(checkCollisionX(child)){
				child->destroy();
				return;	
			}
		}
	}

	player->applyGravity();
	
	if(player->getY() > 130){
		currentScreen = DEATH;
		life--;
		return;
	}

	player->touchedGround = false;

	// Update scene objects and check for collisions
	for(Object* obj : objects){
		//if its a bullet or a spike we return
		if(checkCollisionY(obj)) return;
	}

	for(Object* obj : spawners){
		//if its a bullet or a spike we return
		if(checkCollisionY(obj)) return;
		BulletSpawner* spawner = (BulletSpawner*)obj;
		for(Bullet* child : spawner->children){
			if(checkCollisionX(child)){
				child->destroy();
				return;	
			}
		}
	}

	for(auto it = collectibles.begin(); it != collectibles.end();){
		Collectible* obj = *it;
		obj->update();

		bool collected = false;
		enum CollectibleType type = obj->getCollectibleType();

		if(type == COIN1){
			if(checkCollision(player, (Coin*)obj)){
				collected = true;
				score++;
			}
		}else if (type == LIFE1){
			if(checkCollision(player,obj)){
				collected = true;
				score += 5;
				life++;
			}
		}

		if(collected){
			delete obj;
			it = collectibles.erase(it);
		} else {
			++it;
		}
	}
}

int GameHandler::checkCollisionX(Object* obj){
	if(obj == nullptr) return 0;
	if(checkCollision(player,obj)){
		if(obj->getType() == SPIKE || obj->getType() == BULLET){
			currentScreen = DEATH;
			life--;
			return 1;
		}else{
			int16_t overlapLeft = player->getRight() - obj->getLeft();
			int16_t overlapRight = obj->getRight() - player->getLeft();

			if (overlapLeft < overlapRight) {
				player->setRight(obj->getLeft());
				player->touchingWallRight = true;
			} else {
				player->setLeft(obj->getRight());
				player->touchingWallLeft = true;
			}
		}
	}
	return 0;
}

int GameHandler::checkCollisionY(Object* obj){
	if(obj == nullptr) return 0;
	if(checkCollision(player,obj)){
		if(obj->getType() == SPIKE){
			currentScreen = DEATH;
			life--;
			return 1;
		}else{
			int16_t overlapTop = player->getBottom() - obj->getTop();
			int16_t overlapBottom = obj->getBottom() - player->getTop();
		
			if (overlapTop < overlapBottom) {
				player->setBottom(obj->getTop());
				player->touchedGround = true;
				player->setVelocityY(0); // Stop falling
			} else {
				player->setTop(obj->getBottom());
				player->setVelocityY(0); // Hit ceiling, stop rising
			}
		}
	}
	return 0;
}

void GameHandler::drawHeart(int16_t x, int16_t y){
	canvas->startWrite();
	canvas->fillRect(x+1,y,2,1,TFT_RED);
	canvas->fillRect(x+4,y,2,1,TFT_RED);
	canvas->fillRect(x,y+1,7,2,TFT_RED);
	canvas->fillRect(x+1,y+3,5,1,TFT_RED);
	canvas->fillRect(x+2,y+4,3,1,TFT_RED);
	canvas->drawPixel(x+3,y+5,TFT_RED);
	canvas->endWrite();

}

void GameHandler::addObject(Object* newObj){
  objects.push_back(newObj);
}

void GameHandler::addObject(Collectible* newObj){
  collectibles.push_back(newObj);
}

void GameHandler::addSpawner(Object* newObj){
  spawners.push_back(newObj);
}

bool GameHandler::checkCollision(Actor* obj1, Actor* obj2){
	// Standard Axis-Aligned Bounding Box (AABB) Collision Detection
	// Checks if any gap exists between the objects on any axis. If no gap exists, they are colliding.
	bool test1 = obj1->getLeft() >= obj2->getRight();
	bool test2 = obj1->getRight() <= obj2->getLeft();
	bool test3 = obj1->getBottom() <= obj2->getTop();
	bool test4 = obj1->getTop() >= obj2->getBottom();
	return !(test1 || test2 || test3 || test4);
}

bool GameHandler::checkCollision(Actor* obj1, Coin* obj2){
	// Standard Axis-Aligned Bounding Box (AABB) Collision Detection
	// Checks if any gap exists between the objects on any axis. If no gap exists, they are colliding.
	bool test1 = obj1->getLeft() >= obj2->getRight() - obj2->getRadius();
	bool test2 = obj1->getRight() <= obj2->getLeft() - obj2->getRadius();
	bool test3 = obj1->getBottom() <= obj2->getTop() - obj2->getRadius();
	bool test4 = obj1->getTop() >= obj2->getBottom() - obj2->getRadius(); 
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
