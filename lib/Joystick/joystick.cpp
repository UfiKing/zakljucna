#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <esp_adc/adc_oneshot.h>
#include <driver/gpio.h>
#include "joystick.hpp"
#include <esp_log.h>
Joystick::Joystick(){
  // Configure the ADC unit for the X axis
  adc_oneshot_unit_init_cfg_t xInitConfig = {
    .unit_id = ADC_UNIT_1,
    .clk_src = ADC_RTC_CLK_SRC_DEFAULT,
    .ulp_mode = ADC_ULP_MODE_DISABLE,
  };

  // Configure the ADC unit for the Y axis
  adc_oneshot_unit_init_cfg_t yInitConfig = {
    .unit_id = ADC_UNIT_2,
    .clk_src = ADC_RTC_CLK_SRC_DEFAULT,
    .ulp_mode = ADC_ULP_MODE_DISABLE,
  };

  // Initialize the ADC units
  ESP_ERROR_CHECK(adc_oneshot_new_unit(&xInitConfig, &xHandle));
  ESP_ERROR_CHECK(adc_oneshot_new_unit(&yInitConfig, &yHandle));


  // Setup the channel configuration (12-bit width and 11dB attenuation for 0-3.3V range)
  adc_oneshot_chan_cfg_t config = {
    .atten = ADC_ATTEN_DB_12,
    .bitwidth = ADC_BITWIDTH_12,
  };

  // Apply the configuration to both X and Y channels
  ESP_ERROR_CHECK(adc_oneshot_config_channel(xHandle, X_PIN, &config));
  ESP_ERROR_CHECK(adc_oneshot_config_channel(yHandle, Y_PIN, &config));

  // Configure the button GPIO
  gpio_config_t io_conf = {};
  io_conf.intr_type = GPIO_INTR_DISABLE;        // No interrupts
  io_conf.mode = GPIO_MODE_INPUT;               // Set as Input
  io_conf.pin_bit_mask = (1ULL << BUTTON_PIN);  // Bitmask for Pin 32
  io_conf.pull_down_en = GPIO_PULLDOWN_DISABLE; // Disable pull-down
  io_conf.pull_up_en = GPIO_PULLUP_ENABLE;      // Enable pull-up (Active low)
  ESP_ERROR_CHECK(gpio_config(&io_conf));
}

int Joystick::readX(){
  // Read the raw ADC value for the X axis and store it in xValue
  ESP_ERROR_CHECK(adc_oneshot_read(xHandle, X_PIN, &xValue));
  return xValue;
}

int Joystick::readY(){
  // Read the raw ADC value for the Y axis and store it in yValue
  ESP_ERROR_CHECK(adc_oneshot_read(yHandle, Y_PIN, &yValue));
  return yValue;
}

bool Joystick::readButton(){
  // Read the GPIO level.
  // Note: Since we are using a pull-up, the pin reads 0 when pressed (Active low).
  // We invert the result so that pressed evaluates to true.
  button = !(gpio_get_level((gpio_num_t)BUTTON_PIN));
  return button;
}

int Joystick::getX(){
  return xValue;
}

int Joystick::getY(){
  return yValue;
}

bool Joystick::getButton(){
  return button;
}
