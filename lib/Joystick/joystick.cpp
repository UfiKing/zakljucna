#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <esp_adc/adc_oneshot.h>
#include "joystick.hpp"

Joystick::Joystick(){
  adc_oneshot_unit_init_cfg_t xInitConfig = {
    .unit_id = ADC_UNIT_1,
    .clk_src = ADC_RTC_CLK_SRC_DEFAULT,
    .ulp_mode = ADC_ULP_MODE_DISABLE,
  };

  adc_oneshot_unit_init_cfg_t yInitConfig = {
    .unit_id = ADC_UNIT_2,
    .clk_src = ADC_RTC_CLK_SRC_DEFAULT,
    .ulp_mode = ADC_ULP_MODE_DISABLE,
  };

  ESP_ERROR_CHECK(adc_oneshot_new_unit(&xInitConfig, &xHandle));
  ESP_ERROR_CHECK(adc_oneshot_new_unit(&yInitConfig, &yHandle));


  adc_oneshot_chan_cfg_t config = {
    .atten = ADC_ATTEN_DB_12,
    .bitwidth = ADC_BITWIDTH_12,
  };

  ESP_ERROR_CHECK(adc_oneshot_config_channel(xHandle, X_PIN, &config));
  ESP_ERROR_CHECK(adc_oneshot_config_channel(yHandle, Y_PIN, &config));

}

int Joystick::readX(){
  ESP_ERROR_CHECK(adc_oneshot_read(xHandle, X_PIN, &xValue));
  return xValue;
}

int Joystick::readY(){
  ESP_ERROR_CHECK(adc_oneshot_read(yHandle, Y_PIN, &yValue));
  return yValue;
}

//bool Joystick::readButton();

int Joystick::getX(){
  return xValue;
}

int Joystick::getY(){
  return yValue;
}

//bool Joystick::getButton();
