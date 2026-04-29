#pragma once
#include "Vektor.hpp"
#include <LovyanGFX.hpp>

/**
 * @brief Base class for all physical entities in the game.
 * Provides standard properties like position, dimensions, and color, 
 * as well as common interfaces for updating and drawing.
 */
class Actor {
protected:
  Vektor<int16_t> position; ///< 2D vector storing the X and Y coordinates
  uint16_t width;           ///< Width of the actor's bounding box
  uint16_t height;          ///< Height of the actor's bounding box
  int colour;               ///< Display color of the actor (e.g., TFT_WHITE)
public:

  /**
   * @brief Construct a rectangular actor with default white color.
   */
  Actor(int16_t x, int16_t y, uint16_t width, uint16_t height){
    position = Vektor(x,y);
    this->width = width;
    this->height = height;
    this->colour = TFT_WHITE;
  }
  
  /**
   * @brief Construct a square actor with default white color.
   */
  Actor(int16_t x, int16_t y, uint16_t width){
    position = Vektor(x,y);
    this->width = width;
    this->height = width;
    this->colour = TFT_WHITE;
  }
  
  /**
   * @brief Construct a rectangular actor with a specific color.
   */
  Actor(int16_t x, int16_t y, uint16_t width, uint16_t height, int colour){
    position = Vektor(x,y);
    this->width = width;
    this->height = height;
    this->colour = colour;
  }
  
  /**
   * @brief Construct a square actor with a specific color.
   */
  Actor(int16_t x, int16_t y, uint16_t width, int colour){
    position = Vektor(x,y);
    this->width = width;
    this->height = width;
    this->colour = colour;
  }

  /**
   * @brief Virtual destructor for safe polymorphic deletion.
   */
  virtual ~Actor(){
    
  }

  /**
   * @brief Updates the actor's position to specific coordinates.
   * @param newX The new X coordinate.
   * @param newY The new Y coordinate.
   */
  virtual void update(int16_t newX, int16_t newY);

  /**
   * @brief Generic update loop for the actor.
   * Intended to be overridden by derived classes to handle frame-by-frame logic.
   */
	virtual void update();

  /**
   * @brief Draws the actor to the specified canvas.
   * @param canvas Pointer to the LovyanGFX sprite to draw on.
   */
  virtual void draw(LGFX_Sprite *canvas);

	virtual void draw(LGFX_Sprite *canvas, int offsetX, int offsetY);

  /**
   * @brief Gets the width of the actor.
   * @return uint16_t The width.
   */
  virtual uint16_t getWidth();

  /**
   * @brief Gets the height of the actor.
   * @return uint16_t The height.
   */
  virtual uint16_t getHeight();
	
  /**
   * @brief Gets the left edge X coordinate of the actor.
   * @return int16_t The left X coordinate.
   */
	virtual int16_t getLeft() const;

  /**
   * @brief Gets the right edge X coordinate of the actor.
   * @return int16_t The right X coordinate.
   */
  virtual int16_t getRight() const;

  /**
   * @brief Gets the top edge Y coordinate of the actor.
   * @return int16_t The top Y coordinate.
   */
  virtual int16_t getTop() const;

  /**
   * @brief Gets the bottom edge Y coordinate of the actor.
   * @return int16_t The bottom Y coordinate.
   */
  virtual int16_t getBottom() const;

  /**
   * @brief Gets the current X position of the actor.
   * @return int16_t The X coordinate.
   */
  virtual int16_t getX() const; 

  /**
   * @brief Gets the current Y position of the actor.
   * @return int16_t The Y coordinate.
   */
  virtual int16_t getY() const;

  /**
   * @brief Sets the X position of the actor.
   * @param newX The new X coordinate.
   */
	virtual void setX(int16_t newX);

  /**
   * @brief Sets the Y position of the actor.
   * @param newY The new Y coordinate.
   */
	virtual void setY(int16_t newY); 

  /**
   * @brief Aligns the left edge of the actor to the specified X coordinate.
   * @param newLeft The new left X coordinate.
   */
	virtual void setLeft(int16_t newLeft);

  /**
   * @brief Aligns the right edge of the actor to the specified X coordinate.
   * @param newRight The new right X coordinate.
   */
	virtual void setRight(int16_t newRight);

  /**
   * @brief Aligns the top edge of the actor to the specified Y coordinate.
   * @param newTop The new top Y coordinate.
   */
	virtual void setTop(int16_t newTop);

  /**
   * @brief Aligns the bottom edge of the actor to the specified Y coordinate.
   * @param newBottom The new bottom Y coordinate.
   */
	virtual void setBottom(int16_t newBottom);

	virtual void changeColour(int newColour);

};
