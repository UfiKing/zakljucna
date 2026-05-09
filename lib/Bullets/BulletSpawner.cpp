#include "BulletSpawner.hpp"
#include <algorithm>


BulletSpawner::BulletSpawner(int16_t x, int16_t y, int16_t width, int16_t height, float intervalSeconds, 
                             Direction direction, int16_t speed, 
                             int bWidth, int bHeight) 
    : Object(x, y, width, height, TFT_DARKGRAY) {
    
  spawnIntervalMs = static_cast<int>(intervalSeconds * 1000);
  lastSpawnTime = 0;
  spawnDirection = direction;
  bulletSpeed = speed;
  bulletWidth = bWidth;
  bulletHeight = bHeight;
}

BulletSpawner::~BulletSpawner() {
  // Clean up memory for all bullets
  for (Bullet* bullet : children) {
    delete bullet;
  }
  children.clear();
}

void BulletSpawner::update() {
  uint32_t currentTime = esp_timer_get_time(); 
  
  // Check if it's time to spawn a new bullet
  if (currentTime - lastSpawnTime >= spawnIntervalMs) {
    // Create a new bullet at the spawner's position
    // We spawn it slightly offset depending on direction to avoid immediate self-collision
    int spawnX = position.x;
    int spawnY = position.y;
    
    switch (spawnDirection) {
      case Direction::RIGHT:
        spawnX += width; 
        break;
      case Direction::LEFT:
        spawnX -= bulletWidth;
        break;
      case Direction::DOWN:
        spawnY += height;
        break;
      case Direction::UP:
        spawnY -= bulletHeight;
        break;
    }

    Bullet* newBullet = new Bullet(
      spawnX, 
      spawnY, 
      bulletWidth, 
      bulletHeight, 
      spawnDirection, 
      bulletSpeed 
    );
    
    children.push_back(newBullet);
    lastSpawnTime = currentTime;
  }

  // Update existing bullets
  for (auto it = children.begin(); it != children.end(); ) {
    Bullet* bullet = *it;
    
    // Update bullet position
    bullet->update();
    
    if (bullet->isDestroyed()) {
      delete bullet;
      it = children.erase(it); // Remove bullet from vector and move iterator
    } else {
      ++it;
    }
  }
}

void BulletSpawner::draw(LGFX_Sprite* canvas) {
  draw(canvas, 0, 0);
}

void BulletSpawner::draw(LGFX_Sprite* canvas, int offsetX, int offsetY) {
	int xoff = position.x + offsetX;
	int yoff = position.y + offsetY + 9;
	//front of the cannon
	canvas->fillRect(xoff, yoff - 7, 2, 5, TFT_BLACK);
	//circular part
	canvas->fillCircle(xoff + 10, yoff - 5, 4, TFT_BLACK);
	//barrel
	canvas->fillRect(xoff + 2, yoff - 6, 4, 3, TFT_BLACK);
	//triangle
	canvas->fillTriangle(xoff + 6, yoff, xoff + 10, yoff - 4, xoff + 14, yoff, TFT_SILVER);
	canvas->drawPixel(xoff + 10, yoff - 4, TFT_BLACK);
  // Draw bullets with the same offset
  for (Bullet* bullet : children) {
    bullet->draw(canvas, offsetX, offsetY);
  }
}