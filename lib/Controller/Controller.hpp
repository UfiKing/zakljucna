#pragma once
#include <driver/gpio.h>
#include <esp_attr.h>
#include <esp_log.h>

/// GPIO pin assigned to the UP button (BUTTON1)
#define BUTTON1_PIN 3
/// GPIO pin assigned to the RIGHT button (BUTTON2)
#define BUTTON2_PIN 32
/// GPIO pin assigned to the LEFT button (BUTTON3)
#define BUTTON3_PIN 21 
/// GPIO pin assigned to the DOWN button (BUTTON4)
#define BUTTON4_PIN 22
/// Default interrupt flag used for GPIO ISR allocation
#define ESP_INTR_FLAG_DEFAULT 0

/**
 * @brief A data structure to store the current state of the gamepad buttons.
 * Used to globally track which buttons are currently pressed.
 */
class GamepadButtons{
	bool upButton = false;
	bool downButton = false;
	bool leftButton = false;
	bool rightButton = false;

public:
	/**
	 * @brief Construct a new Gamepad Buttons object.
	 */
	GamepadButtons(){}

	/**
	 * @brief Sets the UP button state to ON (pressed).
	 */
	void upButtonOn(){
		upButton = true;
	}
	
	/**
	 * @brief Sets the UP button state to OFF (released).
	 */
	void upButtonOff(){
		upButton = false;
	}

	/**
	 * @brief Gets the current state of the UP button.
	 * @return true if pressed, false otherwise.
	 */
	bool getUpButton(){
		return upButton;
	}

	/**
	 * @brief Sets the DOWN button state to ON (pressed).
	 */
	void downButtonOn(){
		downButton = true;
	}
	
	/**
	 * @brief Sets the DOWN button state to OFF (released).
	 */
	void downButtonOff(){
		downButton = false;
	}

	/**
	 * @brief Gets the current state of the DOWN button.
	 * @return true if pressed, false otherwise.
	 */
	bool getDownButton(){
		return downButton;
	}
	
	/**
	 * @brief Sets the LEFT button state to ON (pressed).
	 */
	void leftButtonOn(){
		leftButton = true;
	}
	
	/**
	 * @brief Sets the LEFT button state to OFF (released).
	 */
	void leftButtonOff(){
		leftButton = false;
	}

	/**
	 * @brief Gets the current state of the LEFT button.
	 * @return true if pressed, false otherwise.
	 */
	bool getLeftButton(){
		return leftButton;
	}

	/**
	 * @brief Sets the RIGHT button state to ON (pressed).
	 */
	void rightButtonOn(){
		rightButton = true;
	}
	
	/**
	 * @brief Sets the RIGHT button state to OFF (released).
	 */
	void rightButtonOff(){
		rightButton = false;
	}

	/**
	 * @brief Gets the current state of the RIGHT button.
	 * @return true if pressed, false otherwise.
	 */
	bool getRightButton(){
		return rightButton;
	}
};

/**
 * @brief ISR handler for BUTTON1 (UP).
 * Updates the UP button state based on the current GPIO level.
 * @param arg User argument (unused).
 */
static void IRAM_ATTR button_isr_handler1(void *arg){
  GamepadButtons* buttons = static_cast<GamepadButtons*>(arg);
  int level = gpio_get_level((gpio_num_t)BUTTON1_PIN);
	// Active low: level == 0 means pressed (falling edge), level == 1 means released (rising edge)
	if(level == 0){
		buttons->upButtonOn();
	}else{
		buttons->upButtonOff();
	}
}

/**
 * @brief ISR handler for BUTTON2 (RIGHT).
 * Updates the RIGHT button state based on the current GPIO level.
 * @param arg User argument (unused).
 */
static void IRAM_ATTR button_isr_handler2(void *arg){
  GamepadButtons* buttons = static_cast<GamepadButtons*>(arg);
  int level = gpio_get_level((gpio_num_t)BUTTON2_PIN);
	if(level == 0){
		buttons->rightButtonOn();
	}else{
		buttons->rightButtonOff();
	}
}

/**
 * @brief ISR handler for BUTTON3 (LEFT).
 * Updates the LEFT button state based on the current GPIO level.
 * @param arg User argument (unused).
 */
static void IRAM_ATTR button_isr_handler3(void *arg){
  GamepadButtons* buttons = static_cast<GamepadButtons*>(arg);
  int level = gpio_get_level((gpio_num_t)BUTTON3_PIN);
	if(level == 0){
		buttons->leftButtonOn();
	}else{
		buttons->leftButtonOff();
	}
}

/**
 * @brief ISR handler for BUTTON4 (DOWN).
 * Updates the DOWN button state based on the current GPIO level.
 * @param arg User argument (unused).
 */
static void IRAM_ATTR button_isr_handler4(void *arg){
  GamepadButtons* buttons = static_cast<GamepadButtons*>(arg);
  int level = gpio_get_level((gpio_num_t)BUTTON4_PIN);
	if(level == 0){
		buttons->downButtonOn();
	}else{
		buttons->downButtonOff();
	}
}

/**
 * @brief Manages gamepad hardware initialization and state reading.
 */
class Controller{
public: 
	GamepadButtons* buttons; ///< Pointer to the shared GamepadButtons state.
	
  /**
   * @brief Construct a new Controller object.
   * Configures the GPIO pins as inputs with pull-ups, installs the ISR service,
   * and attaches the specific interrupt handlers for each button.
   */
  Controller(){
		this->buttons = new GamepadButtons();
    const gpio_config_t button1Config = gpio_config_t{
      .pin_bit_mask = 1ULL << BUTTON1_PIN,
      .mode = GPIO_MODE_INPUT,
      .pull_up_en = GPIO_PULLUP_ENABLE,
      .pull_down_en = GPIO_PULLDOWN_DISABLE,
      .intr_type = GPIO_INTR_ANYEDGE
    };

    const gpio_config_t button2Config = gpio_config_t{
      .pin_bit_mask = 1ULL << BUTTON2_PIN,
      .mode = GPIO_MODE_INPUT,
      .pull_up_en = GPIO_PULLUP_ENABLE,
      .pull_down_en = GPIO_PULLDOWN_DISABLE,
      .intr_type = GPIO_INTR_ANYEDGE
    };

    const gpio_config_t button3Config = gpio_config_t{
      .pin_bit_mask = 1ULL << BUTTON3_PIN,
      .mode = GPIO_MODE_INPUT,
      .pull_up_en = GPIO_PULLUP_ENABLE,
      .pull_down_en = GPIO_PULLDOWN_DISABLE,
      .intr_type = GPIO_INTR_ANYEDGE 
    };

    const gpio_config_t button4Config = gpio_config_t{
      .pin_bit_mask = 1ULL << BUTTON4_PIN,
      .mode = GPIO_MODE_INPUT,
      .pull_up_en = GPIO_PULLUP_ENABLE,
      .pull_down_en = GPIO_PULLDOWN_DISABLE,
      .intr_type = GPIO_INTR_ANYEDGE
    };

    gpio_config(&button1Config);
    gpio_config(&button2Config);
    gpio_config(&button3Config);
    gpio_config(&button4Config);

    gpio_install_isr_service(ESP_INTR_FLAG_DEFAULT);
    gpio_isr_handler_add((gpio_num_t)BUTTON1_PIN, button_isr_handler1, this->buttons);
    gpio_isr_handler_add((gpio_num_t)BUTTON2_PIN, button_isr_handler2, this->buttons);
    gpio_isr_handler_add((gpio_num_t)BUTTON3_PIN, button_isr_handler3, this->buttons);
    gpio_isr_handler_add((gpio_num_t)BUTTON4_PIN, button_isr_handler4, this->buttons);
  }
  
	~Controller() {
		delete buttons;
	}

	/**
	 * @brief Checks if any button on the gamepad is currently pressed.
	 * @return true if at least one button is pressed, false otherwise.
	 */
	bool getAnyButton(){
		return buttons->getDownButton() || buttons->getLeftButton() || buttons->getRightButton() || buttons->getUpButton();
	}
};
