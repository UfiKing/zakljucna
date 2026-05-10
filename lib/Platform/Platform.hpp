#pragma once
#include "Object.hpp"
#include "PlatformTypes.hpp"
#include "ObjectTypes.hpp"

/**
 * @brief Represents a solid platform object in the game world.
 * Inherits from Object. Platforms have different visual styles determined by their PlatformType.
 */
class Platform : public Object{
protected:
	enum PlatformTypes platformType; ///< The visual style/type of this platform.
public:
	/**
	 * @brief Construct a new Platform object.
	 * @param x Initial X coordinate.
	 * @param y Initial Y coordinate.
	 * @param width Width of the platform's bounding box.
	 * @param height Height of the platform's bounding box.
	 * @param platformType The visual style of the platform (e.g., GRAYBRICKS).
	 */
	Platform(int16_t x, int16_t y, int16_t width, int16_t height, enum PlatformTypes platformType) : Object(x,y,width,height, TFT_LIGHTGRAY){
		this->platformType = platformType;
		this->type = PLATFORM;
	}

	/**
	 * @brief Master draw function that delegates rendering to specific functions based on platformType.
	 * @param canvas Pointer to the LovyanGFX sprite to draw on.
	 * @param offsetX X coordinate offset (usually camera/scroll offset).
	 * @param offsetY Y coordinate offset.
	 */
	void draw(LGFX_Sprite* canvas, int offsetX, int offsetY) override;
	
	/**
	 * @brief Renders the platform using the GRAYBRICKS visual style.
	 * @param canvas Pointer to the LovyanGFX sprite to draw on.
	 * @param offsetX X coordinate offset.
	 * @param offsetY Y coordinate offset.
	 */
	void drawGrayBricks(LGFX_Sprite* canvas, int offsetX, int offsetY);
	
	/**
	 * @brief Renders the platform using the GRAYBLOCK visual style.
	 * @param canvas Pointer to the LovyanGFX sprite to draw on.
	 * @param offsetX X coordinate offset.
	 * @param offsetY Y coordinate offset.
	 */
	void drawGrayBlock(LGFX_Sprite* canvas, int offsetX, int offsetY);

};