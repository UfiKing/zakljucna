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
   * @param x Initial X coordinate.
   * @param y Initial Y coordinate.
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
   * @param num The scalar to add.
   * @return Vektor The resulting vector after addition.
   */
  Vektor operator+(Type num) const {
    return Vektor(x+num, y+num);
  }

  /**
   * @brief Adds another vector.
   * @param vektor The vector to add.
   * @return Vektor The resulting vector after addition.
   */
  Vektor operator+(const Vektor& vektor) const {
    return Vektor(x + vektor.x, y + vektor.y);
  }

  /**
   * @brief Adds a scalar to this vector in-place.
   * @param RHSNum The scalar to add.
   * @return Vektor& Reference to this vector.
   */
  Vektor& operator+=(const Type& RHSNum){
    x += RHSNum;
    y += RHSNum;
    return *this;
  }
    
  /**
   * @brief Adds another vector to this vector in-place.
   * @param RHSVektor The vector to add.
   * @return Vektor& Reference to this vector.
   */
  Vektor& operator+=(const Vektor& RHSVektor){
    x += RHSVektor.x;
    y += RHSVektor.y;
    return *this;
  }
    
  /**
   * @brief Subtracts a scalar from both coordinates.
   * @param num The scalar to subtract.
   * @return Vektor The resulting vector after subtraction.
   */
  Vektor operator-(Type num) const {
    return Vektor(x - num, y - num);
  }

  /**
   * @brief Subtracts another vector.
   * @param vektor The vector to subtract.
   * @return Vektor The resulting vector after subtraction.
   */
  Vektor operator-(const Vektor& vektor) const {
    return Vektor(x - vektor.x, y - vektor.y);
  }

  /**
   * @brief Multiplies both coordinates by a scalar.
   * @param num The scalar to multiply by.
   * @return Vektor The resulting vector after multiplication.
   */
  Vektor operator*(Type num) const {
    return Vektor(x * num, y * num);
  }

  /**
   * @brief Calculates the dot product of two vectors.
   * @param vektor The other vector.
   * @return Type The resulting dot product scalar value.
   */
  Type operator*(const Vektor& vektor) const {
    return x * vektor.x + y * vektor.y;
  }

  /**
   * @brief Divides both coordinates by a scalar.
   * @param num The scalar to divide by.
   * @return Vektor The resulting vector after division.
   */
  Vektor operator/(Type num) const {
    return Vektor(x / num, y / num);
  }
    

};

/** @brief Convenience typedef for a 2D integer vector. */
typedef Vektor<int> VektorInt;
