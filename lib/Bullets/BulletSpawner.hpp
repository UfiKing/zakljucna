#pragma once
#include "Object.hpp"
#include "Bullet.hpp"
#include <vector>
#include <cstdint>
#include <LovyanGFX.h>
/**
 * @brief Spawns bullets at regular intervals.
 * Inherits from Object to allow positioning and drawing a spawn indicator if desired.
 */
class BulletSpawner : public Object {
private:
  int spawnIntervalMs;          ///< Interval in milliseconds between spawns
  uint32_t lastSpawnTime;       ///< Timestamp of the last spawn
  Direction spawnDirection;     ///< Direction to spawn bullets
  int bulletSpeed;              ///< Speed for spawned bullets
  int bulletWidth;              ///< Width for spawned bullets
  int bulletHeight;             ///< Height for spawned bullets
  uint16_t bulletColor;         ///< Color for spawned bullets
public:
  std::vector<Bullet*> children; ///< List of active bullets spawned by this object  
  /**
   * @brief Construct a new Bullet Spawner object.
   * @param x Initial X coordinate (BOTTOM LEFT of the object).
   * @param y Initial Y coordinate (BOTTOM LEFT of the object).
   * @param width Width of the spawner's bounding box.
   * @param height Height of the spawner's bounding box.
   * @param intervalSeconds Interval in seconds between spawns.
   * @param direction Direction to shoot bullets.
   * @param speed Speed of the spawned bullets.
   * @param bWidth Width of the spawned bullets.
   * @param bHeight Height of the spawned bullets.
   */
  BulletSpawner(int16_t x, int16_t y,  float intervalSeconds, 
                Direction direction, int16_t speed);

  /**
   * @brief Destroy the Bullet Spawner object and clean up bullets.
   */
  ~BulletSpawner() override;

  /**
   * @brief Update spawner state: spawn new bullets and update existing ones.
   * @param objectsVector Pointer to the global list of game objects for collision checks.
   */
  void update() override;


	void draw(LGFX_Sprite* canvas);

  /**
   * @brief Draws the spawner with an offset.
   * @param canvas Pointer to the LovyanGFX sprite to draw on.
   * @param offsetX X coordinate offset.
   * @param offsetY Y coordinate offset.
   */
  void draw(LGFX_Sprite* canvas, int offsetX, int offsetY) override;
};