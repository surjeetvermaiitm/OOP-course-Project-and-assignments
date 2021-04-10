#include<iostream>
#include<cmath>
#define EPSILON 10e-4
#define pi M_PI

using namespace std;
// Define classes here.
class GeometricObject{
    private:
        string color;
        bool filled;
    public:
        GeometricObject();
        GeometricObject(string color, bool filled);
        string getColor();
        void setColor(string color);
        bool isFilled();
        void setFilled(bool filled);
        string print();
        virtual double getArea()=0;
        virtual double getPerimeter()=0;


};
class Circle : public GeometricObject{
    private:
        double radius;
    public:
        Circle();
        Circle(double radius);
        Circle(double radius, string color, bool filled);
        double getRadius();
        void setRadius(double);
        double getArea();
        double getPerimeter();
        friend istream& operator>>(istream&, Circle&);

};
class Rectangle : public GeometricObject{
    private:
        double width;
        double height;
    public:
        Rectangle();
        Rectangle(double,double);
        double getWidth();
        void setWidth(double);
        double getHeight();
        void setHeight(double);
        double getArea();
        double getPerimeter();
        friend istream& operator>>(istream&, Rectangle&);


};

//***************************************************************************************************
bool equalPerimeter(GeometricObject& g1,GeometricObject& g2){
    return fabs(g1.getPerimeter() - g2.getPerimeter()) < EPSILON ?  true : false;
}

int main()
{
  int n;
  cin >> n;
  Circle circle[n];
  Rectangle rectangle[n];
  for(int i = 0 ; i < n ; i++){
      cin >> circle[i];
      cin >> rectangle[i];
  }

  for(int i = 0 ; i < n ; i++)
      cout << (equalPerimeter(circle[i], rectangle[i]) ? "Yes" : "No") <<"\t";
  return 0;
}
//***************************************************************************************************
GeometricObject :: GeometricObject(){
    color = "White";
    filled = false;
}
GeometricObject :: GeometricObject(string color, bool filled){
    this->color = color;
    this->filled = filled;
}
string GeometricObject :: getColor(){
    return color;
}
void GeometricObject :: setColor(string color){
    this->color = color;
}
void GeometricObject :: setFilled(bool filled){
    this->filled = filled;
}
bool GeometricObject :: isFilled(){
    return filled;
}
string GeometricObject :: print(){
    return "Geometric Object";
}


Circle :: Circle(){
    radius = 1;
}

Circle :: Circle(double radius){
    setRadius(radius);
}

Circle :: Circle(double radius, string color, bool filled){
    setRadius(radius);
    setColor(color);
    setFilled(filled);
}

void Circle :: setRadius(double radius){
    this->radius = (radius >= 0 ) ? radius : 0;
}

double Circle :: getRadius(){
    return radius;
}

double Circle :: getArea(){
    return pi*radius*radius;
}

double Circle :: getPerimeter(){
    return 2*radius*pi;
}
istream& operator>>(istream& in,Circle& circle){
    double r;
    cin>>r;
    circle.setRadius(r);
}
Rectangle :: Rectangle(){
    width=1;
    height=1;
}
Rectangle :: Rectangle(double w,double h){
    width=w;
    height=h;
}
double Rectangle :: getWidth(){
    return width;
}
void Rectangle :: setWidth(double w){
    width=w;
}
double Rectangle :: getHeight(){
    return height;
}
void Rectangle :: setHeight(double h){
    height=h;
}
double Rectangle :: getArea(){
    return width*height;
}
double Rectangle :: getPerimeter(){
    return 2*(width+height);
}
istream& operator>>(istream& in,Rectangle& rectangle){
    double w;
    double h;
    cin>>w>>h;
    rectangle.setWidth(w);
    rectangle.setHeight(h);
}













