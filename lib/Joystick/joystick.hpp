#include <esp_adc/adc_oneshot.h>
#ifndef JOYSTICK_H
#define JOYSTICK_H
//PINS:
//xValue = 34; channel 6
//yValue = 27; channel 7
//button = 32
#define X_PIN ADC_CHANNEL_6
#define Y_PIN ADC_CHANNEL_7
#define BUTTON_PIN 32

class Joystick{
  private:
    bool button;
    int xValue; //int moramo uporabit zato ker knjiznica ne pusti manjsih datatypov (npr uint16_t)
    int yValue;
    adc_oneshot_unit_handle_t xHandle; 
    adc_oneshot_unit_handle_t yHandle;

  public:
    //const uint16_t deadzone[2] = {1500, 2500};
    const uint16_t lowerResting = 1500;
    const uint16_t upperResting = 2500;

    Joystick();
    int readX();
    int readY();
    bool readButton();
    int getX();
    int getY();
    bool getButton();


};

#endif // !JOYSTICK_H
