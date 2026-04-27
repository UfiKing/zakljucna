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

static LGFX_Lcd lcd;
static GameHandler Handler(&lcd);
//Joystick joystick = Joystick();


extern "C" void app_main() {
	Handler.init();
	Handler.addObject(new Actor(0,0,10,TFT_BLUE));
	Handler.addObject(new Actor(40,40,10,40, TFT_BROWN));
	Handler.addObject(new Actor(0,100,200,10,TFT_GOLD));
	Handler.addObject(new Actor(70,-5,10,10,TFT_GOLD));
	Handler.draw();
	vTaskDelay(pdMS_TO_TICKS(500));
  while (true) {
		Handler.update();
		Handler.draw();
		
    vTaskDelay(pdMS_TO_TICKS(16)); // Cca 60 FPS
  }
}
