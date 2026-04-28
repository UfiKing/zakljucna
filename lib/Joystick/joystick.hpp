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

/**
 * @brief A class to handle joystick input, including X/Y analog axes and a digital button.
 */
class Joystick{
  private:
    bool button; ///< Stores the current state of the joystick button
    int xValue;  ///< Stores the current raw ADC value for the X axis (int used to match esp-idf api)
    int yValue;  ///< Stores the current raw ADC value for the Y axis
    adc_oneshot_unit_handle_t xHandle; ///< ADC handle for the X axis
    adc_oneshot_unit_handle_t yHandle; ///< ADC handle for the Y axis

  public:
    //const uint16_t deadzone[2] = {1500, 2500};
    const uint16_t lowerResting = 1500; ///< Lower bound of the joystick's resting deadzone
    const uint16_t upperResting = 2500; ///< Upper bound of the joystick's resting deadzone

    /**
     * @brief Construct a new Joystick object, initializing the ADC channels and GPIO pin.
     */
    Joystick();

    /**
     * @brief Reads and updates the current X axis value from the ADC.
     * @return int The newly read X axis ADC value.
     */
    int readX();

    /**
     * @brief Reads and updates the current Y axis value from the ADC.
     * @return int The newly read Y axis ADC value.
     */
    int readY();

    /**
     * @brief Reads and updates the current button state from the GPIO.
     * @return true If the button is currently pressed.
     * @return false If the button is currently released.
     */
    bool readButton();

    /**
     * @brief Gets the last read X axis value without triggering a new ADC reading.
     * @return int The last read X axis value.
     */
    int getX();

    /**
     * @brief Gets the last read Y axis value without triggering a new ADC reading.
     * @return int The last read Y axis value.
     */
    int getY();

    /**
     * @brief Gets the last read button state without triggering a new GPIO reading.
     * @return true If the button was pressed.
     * @return false If the button was released.
     */
    bool getButton();


};

#endif // !JOYSTICK_H
