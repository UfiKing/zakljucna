#pragma once
#include "Object.hpp"
#include "PlatformTypes.hpp"

class Platform : public Object{
protected:
	enum PlatformTypes platformType;
public:
	Platform(int16_t x, int16_t y, int16_t width, int16_t height, enum PlatformTypes platformType) : Object(x,y,width,height, TFT_LIGHTGRAY){
		this->platformType = platformType;
	}

	void draw(LGFX_Sprite* canvas, int offsetX, int offsetY) override;
	void drawGrayBricks(LGFX_Sprite* canvas, int offsetX, int offsetY);
	void drawGrayBlock(LGFX_Sprite* canvas, int offsetX, int offsetY);

};