#pragma once
#include "Collectible.hpp"

/**
 * @brief Represents a collectible coin in the game.
 * Inherits from Collectible, drawn with a custom pixel-art style on the screen.
 */
class Coin : public Collectible{
	int16_t radius;                      ///< Radius of the coin
	int16_t width;                       ///< Width of the coin's bounding box
	int16_t height;                      ///< Height of the coin's bounding box
	Vektor<int16_t> position;            ///< 2D vector storing the X and Y coordinates
	int accentColour;                    ///< Lighter color used for highlights
	int shadeColour;                     ///< Darker color used for shading/shadows
	int accentShadeColour;               ///< Mixed color for shaded highlights
public:

	/**
	 * @brief Construct a new Coin object.
	 * @param x Initial X coordinate.
	 * @param y Initial Y coordinate.
	 * @param radius Radius of the coin.
	 */
	Coin(int16_t x, int16_t y, int16_t radius) : Collectible(x,y,(uint16_t)(radius * 2), (uint16_t)(radius * 2), TFT_GOLD, COIN1){
		position = Vektor(x,y);
		this->width = 2 * radius;
		this->height = 2 * radius;
		this->radius = radius;
		this->colour = TFT_GOLD;
		accentColour = TFT_YELLOW;
		shadeColour = 24992;
		accentShadeColour = 43776;
		this->type = COLLECTIBLE;
	}

	/**
	 * @brief Construct a new Coin object with custom colors.
	 * @param x Initial X coordinate.
	 * @param y Initial Y coordinate.
	 * @param radius Radius of the coin.
	 * @param colour Base color of the coin.
	 * @param accentColour Highlight color.
	 * @param shadeColour Shadow color.
	 * @param accentShadeColour Highlight shadow color.
	 */
	Coin(int16_t x, int16_t y, int16_t radius, int colour, int accentColour, int shadeColour, int accentShadeColour) : Collectible(x,y,(uint16_t)(radius * 2), (uint16_t)(radius * 2), TFT_GOLD, COIN1){
		position = Vektor(x,y);
		this->width = 2 * radius;
		this->height = 2 * radius;
		this->radius = radius;
		this->colour = colour;
		this->accentColour = accentColour;
		this->shadeColour = shadeColour;
		this->accentShadeColour = accentShadeColour;
	}

	/**
	 * @brief Draws the coin onto the provided canvas.
	 * @param canvas Pointer to the LovyanGFX sprite to draw on.
	 */
	void draw(LGFX_Sprite* canvas) override;

	/**
	 * @brief Draws the coin onto the provided canvas with an offset.
	 * @param canvas Pointer to the LovyanGFX sprite to draw on.
	 * @param offsetX X coordinate offset.
	 * @param offsetY Y coordinate offset.
	 */
	void draw(LGFX_Sprite* canvas, int offsetX, int offsetY) override;
	
	/**
	 * @brief Gets the radius of the coin.
	 * @return int16_t The radius.
	 */
	int16_t getRadius();


};