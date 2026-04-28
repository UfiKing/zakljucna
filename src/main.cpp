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


extern "C" void app_main() {
	// Initialize the LCD display, Canvas, Player, and Joystick
	Handler.init();
	
	// Populate the scene with static rectangular actors (platforms/obstacles)
	Handler.addObject(new Actor(0,0,10,TFT_BLUE));
	Handler.addObject(new Actor(40,40,10,40, TFT_BROWN));
	Handler.addObject(new Actor(0,100,200,10,TFT_GOLD));
	Handler.addObject(new Actor(70,-5,10,10,TFT_GOLD));
	
	Handler.draw();
	vTaskDelay(pdMS_TO_TICKS(500));
	
	// Main Game Loop
  while (true) {
		Handler.update();
		Handler.draw();
		
    vTaskDelay(pdMS_TO_TICKS(16)); // Delay roughly 16 milliseconds to hit ~60 FPS
  }
}
