#include "Checkpoint.hpp"
#include <LovyanGFX.hpp>

// External pointers assumed to exist in GameHandler context or passed via constructor
// For simplicity, we assume we can draw a simple rectangle or pattern

Checkpoint::Checkpoint(int x, int y, int w, int h, uint16_t color) 
    : Object(x, y, w, h, color) {
    // No collision physics, handled separately by GameHandler
}

Checkpoint::~Checkpoint() {
    // Clean up any internal resources if necessary
}

void Checkpoint::draw(LGFX_Sprite* canvas, int offsetX, int offsetY) {
}

void Checkpoint::update() {
}

void Checkpoint::onPlayerHit() {
}