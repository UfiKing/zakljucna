#pragma once

template <typename Type>
struct Vektor{
  Type x;
  Type y;
    
  Vektor(Type x, Type y){
    this->x = x;
    this->y = y;
  }

  Vektor(){
    this->x = (Type)0;
    this->y = (Type)0;
  }
    
  Vektor operator+(Type num){
    return Vektor(x+num, y+num);
  }

  Vektor operator+(Vektor vektor){
    return Vektor(x + vektor.x, y + vektor.y);
  }

  Vektor& operator+=(const Type& RHSNum){
    x += *RHSNum;
    y += *RHSNum;
    return *this;
  }
    
  Vektor& operator+=(const Vektor& RHSVektor){
    x += RHSVektor.x;
    y += RHSVektor.y;
    return *this;
  }
    
  Vektor operator-(Type num){
    return Vektor(x - num, y - num);
  }

  Vektor operator-(Vektor vektor){
    return Vektor(x - vektor.x, y - vektor.y);
  }

  Vektor operator*(Type num){
    return Vektor(x * num, y * num);
  }

  Type operator*(Vektor vektor){
    return x * vektor.x + y * vektor.y;
  }

  Vektor operator/(Type num){
    return Vektor(x / num, y / num);
  }
    

};

typedef Vektor<int> VektorInt;

