# README

## Hardware 
- ESP32 (I used the mini D1 ESP32)
-	SPI TFT RGB display (128*160 pixels; st7735)

## Libraries used
- LovyanGFX (https://github.com/lovyan03/LovyanGFX)
- ESPIDF sdk by Espressif (https://www.espressif.com/en/products/sdks/esp-idf)

## Description
It is a 2D platformer, inspired by the original super mario bros.
The physical thing has 4 buttons (up, down, left, right) for controlling.
The player initialy has 5 lives, and 0 score, but that can be increased by ingame collectibles.
The player can also die from a spike, bullet or the void.

### How to play
You can move the cursor with up and down buttons, and confirm with the right button.
When in game you can move left and right with their respective buttons, and jump with the up buttons
Most screens (except the main menu selection) have instructions on what to do.

## Bug reporting
If you find a bug and want to report it, feel free to open an issue, or if you find the cause of it, open a pull request with the fix.


## Usage of generative LLMs
There was some usage of generative LLMs (from now on "AI", even tho there is nothing intelligent about them).
AI was mainly used to aid in writing some boilerplate code, most of the comments, general debugging, and writing git commit messages.
Most of the code was written by me, except the classes Checkpoint and Bullet was writen primarly with AI.
I was mainly testing the effectivnes of local AI models compared to gemini pro, and general AI use in my coding worklow, as I haven't used it (int this capacity) yet.