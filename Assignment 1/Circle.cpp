#include "Circle.h"
#include<math.h>

Circle::Circle(){
 // code here for default circle
 radius=1.0;

}


Circle::Circle(double newRadius){
    // code here
    radius = newRadius;
}


double Circle::getArea(){
  // code here
  return M_PI*radius*radius;
}


double Circle::getRadius(){
  // code here
  return radius;
}


void Circle::setRadius(double newRadius){
 // code here
 radius = newRadius;
}
