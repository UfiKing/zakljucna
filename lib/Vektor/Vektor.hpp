#pragma once

/**
 * @brief A 2D vector template class for mathematical operations.
 * @tparam Type The numeric type of the vector coordinates (e.g., int16_t, float).
 */
template <typename Type>
struct Vektor{
  Type x; ///< The X coordinate
  Type y; ///< The Y coordinate
    
  /**
   * @brief Construct a new Vektor object with specific X and Y coordinates.
   */
  Vektor(Type x, Type y){
    this->x = x;
    this->y = y;
  }

  /**
   * @brief Construct a new Vektor object, initializing coordinates to 0.
   */
  Vektor(){
    this->x = (Type)0;
    this->y = (Type)0;
  }
    
  /**
   * @brief Adds a scalar to both coordinates.
   */
  Vektor operator+(Type num) const {
    return Vektor(x+num, y+num);
  }

  /**
   * @brief Adds another vector.
   */
  Vektor operator+(const Vektor& vektor) const {
    return Vektor(x + vektor.x, y + vektor.y);
  }

  /**
   * @brief Adds a scalar to this vector in-place.
   */
  Vektor& operator+=(const Type& RHSNum){
    x += RHSNum;
    y += RHSNum;
    return *this;
  }
    
  /**
   * @brief Adds another vector to this vector in-place.
   */
  Vektor& operator+=(const Vektor& RHSVektor){
    x += RHSVektor.x;
    y += RHSVektor.y;
    return *this;
  }
    
  /**
   * @brief Subtracts a scalar from both coordinates.
   */
  Vektor operator-(Type num) const {
    return Vektor(x - num, y - num);
  }

  /**
   * @brief Subtracts another vector.
   */
  Vektor operator-(const Vektor& vektor) const {
    return Vektor(x - vektor.x, y - vektor.y);
  }

  /**
   * @brief Multiplies both coordinates by a scalar.
   */
  Vektor operator*(Type num) const {
    return Vektor(x * num, y * num);
  }

  /**
   * @brief Calculates the dot product of two vectors.
   */
  Type operator*(const Vektor& vektor) const {
    return x * vektor.x + y * vektor.y;
  }

  /**
   * @brief Divides both coordinates by a scalar.
   */
  Vektor operator/(Type num) const {
    return Vektor(x / num, y / num);
  }
    

};

/** @brief Convenience typedef for a 2D integer vector. */
typedef Vektor<int> VektorInt;
