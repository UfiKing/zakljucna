#include "GameHandler.hpp"
#include "LCD.hpp"
#include <algorithm>
#include <esp_log.h>
#include "BulletSpawner.hpp"
#include <cstring>

void GameHandler::loadLevel(){
	switch(currentLevel){
		case LEVEL1:
			loadLevel1();
			break;
		case LEVEL2: 
			loadLevel2();
			break;
		case LEVEL3:
			loadLevel3();
			break;
	}
	player->setX(checkpointX);
	player->setY(checkpointY);
	player->resetVelocity();
}


void GameHandler::loadLevel1(){
	backgroundColour = TFT_SKYBLUE;
	checkpointX = 000;
	checkpointY = 0;
	player->changeColour(TFT_BLACK);

	  addObject(new Object(-10,0,10,128,TFT_SKYBLUE));
  addObject(new Object(-50,100,490,30,TFT_GREEN));
  addObject(new Object(460,100,210,30,TFT_GREEN));
  addObject(new Object(670,100,100,30,TFT_GREEN));
  addObject(new Object(800,100,500,30,TFT_GREEN));
  addObject(new Object(1100,0,10,100,TFT_SKYBLUE));
  addObject(new Platform(260,90,10,10,BROWNBLOCK));
  addObject(new Platform(270,80,10,20,BROWNBLOCK));
  addObject(new Platform(280,70,10,30,BROWNBLOCK));
  addObject(new Platform(300,70,10,30,BROWNBLOCK));
  addObject(new Platform(320,60,10,40,BROWNBLOCK));
  addObject(new Platform(340,70,10,30,BROWNBLOCK));
  addObject(new Platform(360,70,10,30,BROWNBLOCK));
  addObject(new Platform(370,80,10,20,BROWNBLOCK));
  addObject(new Platform(380,90,10,10,BROWNBLOCK));
  addObject(new Platform(490,90,10,10,BROWNBLOCK));
  addObject(new Platform(500,80,10,20,BROWNBLOCK));
  addObject(new Platform(510,70,10,30,BROWNBLOCK));
  addObject(new Platform(520,60,10,40,BROWNBLOCK));
  addObject(new Platform(530,50,10,50,BROWNBLOCK));
  addObject(new Platform(600,90,10,10,BROWNBLOCK));
  addObject(new Platform(590,80,10,20,BROWNBLOCK));
  addObject(new Platform(580,70,10,30,BROWNBLOCK));
  addObject(new Platform(570,60,10,40,BROWNBLOCK));
  addObject(new Platform(560,50,10,50,BROWNBLOCK));
  addObject(new Platform(720,90,10,10,BROWNBLOCK));
  addObject(new Platform(730,80,10,20,BROWNBLOCK));
  addObject(new Platform(740,70,10,30,BROWNBLOCK));
  addObject(new Platform(750,60,10,40,BROWNBLOCK));
  addObject(new Platform(760,50,10,50,BROWNBLOCK));
  addObject(new Platform(890,40,10,60,BROWNBRICKS));
  addObject(new Platform(860,0,10,80,BROWNBRICKS));
  addObject(new Platform(900,40,50,10,BROWNBRICKS));

	for(int i = 0; i < 4; i++){
		addObject(new Spike(290 + i * 20,89,10,10));
	}
	
	const char* text1Const = "This is a coin";
	const char* text2Const = "It gives you 5 score";
	char* text1 = new char[17];
	char* text2 = new char[35];
	std::strncpy(text1,text1Const,17);
	std::strncpy(text2,text2Const,35);
	addNonCollidingObject(new Text(50,50,102,10,text1,1,TFT_BLACK,backgroundColour));
	addNonCollidingObject(new Text(50,70,150,10,text2,1,TFT_BLACK,backgroundColour));
	addObject(new Coin(90,95,5));

	const char* text3Const = "This is a spike";
	const char* text4Const = "It kills you";
	char* text3 = new char[20];
	char* text4 = new char[20];
	std::strncpy(text3,text3Const,20);
	std::strncpy(text4,text4Const,20);
	addNonCollidingObject(new Text(185,50,100,10,text3,1,TFT_BLACK,backgroundColour));
	addNonCollidingObject(new Text(185,70,100,10,text4,1,TFT_BLACK,backgroundColour));
	addObject(new Spike(200,94,10,5));
 

	const char* text5Const = "This is a heart";
	const char* text6Const = "It gives you an extra life";
	char* text5 = new char[20];
	char* text6 = new char[30];
	std::strncpy(text5,text5Const,20);
	std::strncpy(text6,text6Const,30);
	addNonCollidingObject(new Text(300,25,100,10,text5,1,TFT_BLACK,backgroundColour));
	addNonCollidingObject(new Text(300,35,200,30,text6,1,TFT_BLACK,backgroundColour));
	addObject(new LifeCollectible(322,52));

	const char* text7Const = "You can wall jump";
	char* text7 = new char[20];
	std::strncpy(text7,text7Const,20);
	addNonCollidingObject(new Text(755,20,150,10,text7,1,TFT_BLACK,backgroundColour));


	const char* text8Const = "This is a checkpoint";
	const char* text9Const = "It transports you to";
	const char* textAConst = "the next level.";
	const char* textBConst = "press down (yellow) to use";
	char* text8 = new char[22];
	char* text9 = new char[22];
	char* textA = new char[20];
	char* textB = new char[30];
	std::strncpy(text8, text8Const,22);
	std::strncpy(text9, text9Const,22);
	std::strncpy(textA, textAConst,20);
	std::strncpy(textB, textBConst,30);
	addNonCollidingObject(new Text(960,20,150,10,text8,1,TFT_BLACK,backgroundColour));
	addNonCollidingObject(new Text(960,30,150,10,text9,1,TFT_BLACK,backgroundColour));
	addNonCollidingObject(new Text(960,40,150,10,textA,1,TFT_BLACK,backgroundColour));
	addNonCollidingObject(new Text(960,50,150,10,textB,1,TFT_BLACK,backgroundColour));
	addNonCollidingObject(new Checkpoint(1000,81));


	addObject(new Spike(540,74,20,25));

}

void GameHandler::loadLevel2(){

	checkpointX = 0000;
	checkpointY = 20;
	backgroundColour = 8420;

	player->changeColour(TFT_PINK);


	for(int i = 0; i < 5; i++){
		addObject(new Spike(130 + i * 20,96,10,4));
	}

	for(int i = 0; i < 3; i++){
		addObject(new Spike(230 + i * 10,90,10,10));
	}

	addObject(new Spike(270,96,10,4));
	//na unmu velkmu letecem boxu
	for(int i = 0; i < 10; i++){
		addObject(new Spike(365+i*5,56,5,5));
	}

	addSpawner(new BulletSpawner(810,56,2000,RIGHT,1));
	for(int i = 0; i < 4; i++){
		addObject(new Spike(835 + i * 25,75,10,5));
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

	addObject(new LifeCollectible(972,110));
	addObject(new Coin(955,112,5));
	addObject(new Coin(965,112,5));
	addObject(new Coin(985,112,5));
	addObject(new Coin(995,112,5));
	addSpawner(new BulletSpawner(930,113,1500,LEFT,2));


	addObject(new MovingSpike(290, 90, 480, 90, 10,10,1));
 
  addObject(new Object(-60,0,10,100,TFT_DARKGRAY));
  addObject(new Object(-60,100,780,10,TFT_DARKGRAY));
  addObject(new Object(-60,0,1220,10,TFT_DARKGRAY));
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
  addObject(new Platform(735,33,30,97,GRAYBRICKS));
  addObject(new Platform(710,10,10,70,GRAYBRICKS));
  addObject(new Platform(775,30,40,10,GRAYBRICKS));
  addObject(new Platform(825,30,40,10,GRAYBRICKS));
  addObject(new Platform(875,30,40,10,GRAYBRICKS));
  addObject(new Platform(925,30,85,10,GRAYBRICKS));
  addObject(new Platform(765,40,235,15,GRAYBRICKS));
  addObject(new Platform(1000,40,10,20,GRAYBRICKS));
  addObject(new Object(765,120,235,10,TFT_DARKGRAY));
  addObject(new Platform(1000,70,20,10,GRAYBRICKS));
  addObject(new Platform(1000,80,10,50,GRAYBRICKS));
  addObject(new Object(1010,100,150,10,TFT_DARKGRAY));
  addObject(new Platform(790,80,210,10,GRAYBRICKS));
  addObject(new Platform(790,105,10,15,GRAYBRICKS));
  addObject(new Object(1150,0,10,100,TFT_DARKGRAY));
 

  addSpawner(new BulletSpawner(680,90,5000,LEFT,1)); 
	
	addSpawner(new BulletSpawner(945,20,2500,LEFT,1));

	addNonCollidingObject(new Checkpoint(1060,81));


}

void GameHandler::loadLevel3(){
	backgroundColour = 8420;
	currentScreen = DLC;	
}

void GameHandler::clearLevel(){
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

	for (int i = 0; i < nonCollidingObjects.size(); i++) {
    if (nonCollidingObjects[i] != nullptr) delete nonCollidingObjects[i];
  }
  nonCollidingObjects.clear();
}

void GameHandler::draw(){
	// Clear the off-screen canvas to prepare for the new frame
	canvas->startWrite();
	canvas->fillScreen(backgroundColour);
	switch(currentScreen){
		case START:
			//drawStart();
			mainMenu->draw();
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
		case DLC:
			drawDlc();
			break;
		case PURCHASE:
			drawPurchase();
			break;
	}
	canvas->endWrite();
	// Push the fully drawn canvas frame to the actual LCD display
	canvas->pushSprite(0,0);

}

void GameHandler::update(){
	switch (currentScreen){
		case START:
			//updateStart();
			mainMenu->update();
			if(mainMenu->exit) {
				currentScreen = GAME;
				clearLevel();
				loadLevel();
			}
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
		case DLC:
			updateDlc();
			break;
		case PURCHASE:
			updatePurchase();
			break;
	}

}

void GameHandler::updateDlc(){
	if(controller->getAnyButton()){
		currentScreen = PURCHASE;
		vTaskDelay(pdMS_TO_TICKS(500));
	}
}

void GameHandler::drawDlc(){
	canvas->setTextSize(1);
	canvas->setCursor(20,20);
	canvas->println("For more content");
	canvas->setCursor(20,30);
	canvas->println("Buy the DLC");
	canvas->setCursor(20,40);
	canvas->println("Only 99.99Eur");

	canvas->setCursor(20,60);
	canvas->println("Press any button");
	canvas->setCursor(20,70);
	canvas->println("To purchase the DLC");

}

void GameHandler::drawPurchase(){
	canvas->setTextSize(1);
	canvas->setCursor(20,20);
	canvas->println("Just joking ;)");
	canvas->setCursor(20,30);
	canvas->println("This is it!");
	canvas->setCursor(20,40);
	canvas->println("You achived a score of:");
	canvas->setCursor(20,50);
	canvas->println(score);

	canvas->setCursor(20,60);
	canvas->println("Press any button");
	canvas->setCursor(20,70);
	canvas->println("To go to the Main Menu");
}

void GameHandler::updatePurchase(){
	if(controller->getAnyButton()){
		currentScreen = START;
		currentLevel = LEVEL1;
		score = 0;
		life = maxLives;
		mainMenu->reset();
		vTaskDelay(pdMS_TO_TICKS(200));
	}
}

void GameHandler::updateGameOver(){
	if(controller->getAnyButton()){
		// Reset player position and velocity
		player->setX(startingPosX);
		player->setY(startingPosY);
		player->resetVelocity();

		currentScreen = GAME;
		score = 0;	
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

  for (Object* obj : nonCollidingObjects) {
    if (obj == nullptr) continue;
    int renderX = obj->getX() - player->getX() + 64;
    // Only draw if visible
    if (renderX + obj->getWidth() < 0 || renderX > screenWidth) continue;
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

	for(Object* obj : spawners){
		if(obj == nullptr) continue; 		
    obj->update();
		BulletSpawner* spawner = (BulletSpawner*)obj;
		for(Bullet* bullet: spawner->children){
			for(Object* object : objects){
				if(checkCollision(bullet, object)) bullet->destroy();
			}
		}	
	}

	for(Object* obj : nonCollidingObjects){
		if(obj != nullptr) obj->update();
	}

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
		score-= 10;
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

	for(Object* obj : nonCollidingObjects){
		if(obj == nullptr) continue;
		if(obj->getType() == CHECKPOINT){
			ESP_LOGI("TAG", "%d", checkCollision(player,obj) && controller->buttons->getDownButton());
			if(checkCollision(player, obj) && controller->buttons->getDownButton()){
				if(currentLevel == LEVEL1){
					currentLevel = LEVEL2;
					clearLevel();
					loadLevel();
					vTaskDelay(pdMS_TO_TICKS(200));
					return;
				}
				else if(currentLevel == LEVEL2){
					currentLevel = LEVEL3;
					clearLevel();
					loadLevel();
					vTaskDelay(pdMS_TO_TICKS(200));
					return;
				}
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
				score+=5;
			}
		}else if (type == LIFE1){
			if(checkCollision(player,obj)){
				collected = true;
				score += 20;
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
			score-= 10;
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
		if(obj->getType() == SPIKE || obj->getType() == BULLET){
			currentScreen = DEATH;
			life--;
			score-= 10;
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

void GameHandler::addNonCollidingObject(Object* newObj){
	nonCollidingObjects.push_back(newObj);
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
