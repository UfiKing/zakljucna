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
// Global instances of the Display and the Game Handler
static LGFX_Lcd lcd;
static GameHandler Handler(&lcd);

#include "Controller.hpp"


extern "C" void app_main() {
	// Initialize the LCD display, Canvas, Player, and Joystick
	Handler.init();
	// Populate the scene with static rectangular actors (platforms/obstacles)
	
	Handler.loadLevel();
	int startTime = 0;
	int timePassed = 0;	
	// Main Game Loop
  while (true) {
		startTime = esp_timer_get_time();
		Handler.update();
		Handler.draw(); 	

		timePassed = esp_timer_get_time() - startTime;
		//ESP_LOGI("TAG", "%d", timePassed);
		if (timePassed < 16000){
    	vTaskDelay(pdMS_TO_TICKS(16 - timePassed / 1000)); // Delay roughly 16 milliseconds to hit ~60 FPS
		} else {
			ESP_LOGE("TIME", "THE GAME LOOP TOOK LONGER THAN 16MILLIS");
			ESP_LOGE("TIME", "THE AMMOUT OF TIME IT TOOK: %d", timePassed);
		}
		// predamo handle operacijskem sistemu da lohk nardi svoje	
		vTaskDelay(1); 
  }
}
