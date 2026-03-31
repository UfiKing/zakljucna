#include <LovyanGFX.hpp>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

class LGFX_App : public lgfx::LGFX_Device {
    lgfx::Panel_ST7735S _panel_instance;
    lgfx::Bus_SPI _bus_instance;

public:
    LGFX_App() {
        {
            auto cfg = _bus_instance.config();
            cfg.spi_host = SPI2_HOST;     
            cfg.spi_mode = 0;
            cfg.freq_write = 27000000;    
            cfg.pin_sclk = 21;            
            cfg.pin_mosi = 18;           
            cfg.pin_miso = -1;
            cfg.pin_dc   = 22;            
            _bus_instance.config(cfg);
            _panel_instance.setBus(&_bus_instance);
        }
        {
            auto cfg = _panel_instance.config();
            cfg.pin_cs           = 5;     
            cfg.pin_rst          = 23;    
            cfg.panel_width      = 128;
            cfg.panel_height     = 160;
            cfg.memory_width     = 128;
            cfg.memory_height    = 160;
            cfg.offset_x         = 0;
            cfg.offset_y         = 0;
            cfg.offset_rotation  = 0;
            cfg.rgb_order        = false; 
            _panel_instance.config(cfg);
        }
        setPanel(&_panel_instance);
    }
};

static LGFX_App lcd;
static LGFX_Sprite canvas(&lcd);

extern "C" void app_main() {
    lcd.init();
    lcd.setRotation(2);
    
    canvas.createSprite(lcd.width(), lcd.height());

    int x = 0;
    int y = 50;

    while (true) {
        x = (x + 2) % lcd.width();

        canvas.fillScreen(TFT_BLACK);
        canvas.setTextColor(TFT_GREEN);
        canvas.drawString("2D GAME START", 10, 10);
        canvas.fillRect(x, y, 20, 20, TFT_RED); 

        canvas.pushSprite(0, 0);

        vTaskDelay(pdMS_TO_TICKS(16)); // Cca 60 FPS
    }
}
