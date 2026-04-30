#include <LovyanGFX.hpp>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <esp_log.h>
#include <string>
#include "player.hpp"
#include "joystick.hpp"
#include "Vektor.hpp"
#include "LCD.hpp"
#include "GameHandler.hpp"
#include "Collectible.hpp"
#include "Object.hpp"

// Global instances of the Display and the Game Handler
static LGFX_Lcd lcd;
static GameHandler Handler(&lcd);


extern "C" void app_main() {
	// Initialize the LCD display, Canvas, Player, and Joystick
	Handler.init();
	
	// Populate the scene with static rectangular actors (platforms/obstacles)
  Handler.addObject(new Object(-60,-10,10,120,TFT_LIGHTGRAY));
  Handler.addObject(new Object(-60,100,150,10,TFT_LIGHTGRAY));
  Handler.addObject(new Object(110,100,20,10,TFT_LIGHTGRAY));
  Handler.addObject(new Object(150,100,20,10,TFT_LIGHTGRAY));
  Handler.addObject(new Object(190,100,20,10,TFT_LIGHTGRAY));
  Handler.addObject(new Object(230,100,80,10,TFT_LIGHTGRAY));
	Handler.addObject(new Coin(10,85,5));	
	Handler.draw();
	vTaskDelay(pdMS_TO_TICKS(500));
	int startTime = 0;
	int timePassed = 0;	
	// Main Game Loop
  while (true) {
		startTime = esp_timer_get_time() / 1000;
		Handler.update();
		Handler.draw(); 	

		timePassed = esp_timer_get_time() / 1000 - startTime;
		//ESP_LOGI("TAG", "%d", timePassed);
		if (timePassed < 16){
    	vTaskDelay(pdMS_TO_TICKS(16 - timePassed)); // Delay roughly 16 milliseconds to hit ~60 FPS
		} else {
			ESP_LOGE("TIME", "THE GAME LOOP TOOK LONGER THAN 16MILLIS");
			ESP_LOGE("TIME", "THE AMMOUT OF TIME IT TOOK (INT MILLIS): %d", timePassed);
		}
		// predamo handle operacijskem sistemu da lohk nardi svoje	
		vTaskDelay(1); 
  }
}
