#pragma once
#include "Object.hpp"
#include "ObjectTypes.hpp"

class Checkpoint : public Object {
public:
    // Constructor
    Checkpoint(int x, int y, int w, int h, uint16_t color);

    // Destructor
    ~Checkpoint();

    // Overridden methods from Object
    void draw(LGFX_Sprite* canvas, int offsetX, int offsetY) override;
    void update() override;

    // Method to be called when player hits this checkpoint
    void onPlayerHit();
};
