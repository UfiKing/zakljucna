#pragma once
#include <LovyanGFX.h>

/**
 * @brief Custom LCD device configuration for the ST7735S display.
 * Inherits from LovyanGFX's LGFX_Device to set up SPI bus and panel parameters.
 */
class LGFX_Lcd : public lgfx::LGFX_Device {
  lgfx::Panel_ST7735S _panel_instance; ///< Panel instance for ST7735S
  lgfx::Bus_SPI _bus_instance;         ///< SPI bus instance

public:
  /**
   * @brief Construct a new LGFX_Lcd object.
   * Configures the SPI bus pins, frequency, and panel resolution/offsets.
   */
  LGFX_Lcd() {
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
      cfg.rgb_order        = true; 
      _panel_instance.config(cfg);
    }
    setPanel(&_panel_instance);
  }

};