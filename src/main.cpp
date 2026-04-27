#include <LovyanGFX.hpp>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <esp_log.h>

#include "player.hpp"
#include "joystick.hpp"
#include "Vektor.hpp"
#include "LCD.hpp"
#include "GameHandler.hpp"

static LGFX_Lcd lcd;
static GameHandler Handler(&lcd);

Joystick joystick = Joystick();



extern "C" void app_main() {
	Handler.addObject(new Actor(0,0,10,TFT_BLUE));
	Handler.addObject(new Actor(40,40,10,40, TFT_BROWN));
  while (true) {
		Handler.draw();

        

    vTaskDelay(pdMS_TO_TICKS(16)); // Cca 60 FPS
  }
}
