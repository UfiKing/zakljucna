#pragma once
#include "Object.hpp"
#include "ObjectTypes.hpp"

class Checkpoint : public Object {
	enum ObjectTypes type = CHECKPOINT;
public:
    // Constructor
		Checkpoint(int x, int y) : Object(x, y, 18, 19, TFT_BROWN) {
		}

    // Destructor
    ~Checkpoint(){

		}

    // Overridden methods from Object
    void draw(LGFX_Sprite* canvas, int offsetX, int offsetY) override;
    void update() override;

    // Method to be called when player hits this checkpoint
    void onPlayerHit();

		ObjectTypes getType() override;
};
