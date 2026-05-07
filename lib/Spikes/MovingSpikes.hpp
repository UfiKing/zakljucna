#pragma once
#include "Spikes.hpp"

class MovingSpike : public Spike{
protected:
	int16_t x1;
	int16_t y1;
	int16_t x2;
	int16_t y2;
	int16_t speed;
public:
	MovingSpike(int16_t x1, int16_t y1, int16_t x2, int16_t y2, int16_t width, int16_t height, int16_t speed) : Spike(x1, y1, width, height){
		this->x1 = x1;
		this->y1 = y1;
		this->x2 = x2;
		this->y2 = y2;
		this->speed = speed;
	}

	void draw(LGFX_Sprite* canvas, int offsetX, int offsetY) override;
	void update() override;
};