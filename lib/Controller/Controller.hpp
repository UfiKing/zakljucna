#pragma once
#include <driver/gpio.h>
#include <esp_attr.h>
#include <esp_log.h>
#define BUTTON1_PIN 3
#define BUTTON2_PIN 32
#define BUTTON3_PIN 21 
#define BUTTON4_PIN 22
#define ESP_INTR_FLAG_DEFAULT 0
/*
BUTTON1 = up
BUTTON2 = right
BUTTON3 = left
BUTTON4 = down
*/

static class GamepadButtons{
	bool upButton = false;
	bool downButton = false;
	bool leftButton = false;
	bool rightButton = false;

public:
	GamepadButtons(){}

	void upButtonOn(){
		upButton = true;
	}
	
	void upButtonOff(){
		upButton = false;
	}

	bool getUpButton(){
		return upButton;
	}

	void downButtonOn(){
		downButton = true;
	}
	
	void downButtonOff(){
		downButton = false;
	}

	bool getDownButton(){
		return downButton;
	}
	
	void leftButtonOn(){
		leftButton = true;
	}
	
	void leftButtonOff(){
		leftButton = false;
	}

	bool getLeftButton(){
		return leftButton;
	}

	void rightButtonOn(){
		rightButton = true;
	}
	
	void rightButtonOff(){
		rightButton = false;
	}

	bool getRightButton(){
		return rightButton;
	}
}buttons;

//rising edge = 0
//falling edge = 1
static void IRAM_ATTR button_isr_handler1(void *arg){
  int level = gpio_get_level((gpio_num_t)BUTTON1_PIN);
	if(level == 0){
		buttons.upButtonOn();
	}else{
		buttons.upButtonOff();
	}

}

static void IRAM_ATTR button_isr_handler2(void *arg){
  int level = gpio_get_level((gpio_num_t)BUTTON2_PIN);
	if(level == 0){
		buttons.rightButtonOn();
	}else{
		buttons.rightButtonOff();
	}


}

static void IRAM_ATTR button_isr_handler3(void *arg){
  int level = gpio_get_level((gpio_num_t)BUTTON3_PIN);
	if(level == 0){
		buttons.leftButtonOn();
	}else{
		buttons.leftButtonOff();
	}


}

static void IRAM_ATTR button_isr_handler4(void *arg){
  int level = gpio_get_level((gpio_num_t)BUTTON4_PIN);
	if(level == 0){
		buttons.downButtonOn();
	}else{
		buttons.downButtonOff();
	}
}



class Controller{
public: 
	GamepadButtons* buttons;	
  Controller(GamepadButtons* buttons){
		this->buttons = buttons;
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
    gpio_isr_handler_add((gpio_num_t)BUTTON1_PIN, button_isr_handler1, NULL);
    gpio_isr_handler_add((gpio_num_t)BUTTON2_PIN, button_isr_handler2, NULL);
    gpio_isr_handler_add((gpio_num_t)BUTTON3_PIN, button_isr_handler3, NULL);
    gpio_isr_handler_add((gpio_num_t)BUTTON4_PIN, button_isr_handler4, NULL);
  }
  
	bool getAnyButton(){
		return buttons->getDownButton() || buttons->getLeftButton() || buttons->getRightButton() || buttons->getUpButton();
	}


};
