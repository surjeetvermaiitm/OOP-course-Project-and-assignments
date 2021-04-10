#include<iostream>
#include<fstream>
#include<ctime>
#include<cstdlib>
#include "Circle.h"
using namespace std;

int main(){

      fstream myFile;
      int i = 1, k =1, numberOfCircles = 100, numberOfIncorrectCircles = 0;
      double radius_Correct = 6;    // This is given through email.
      double areaSum_Wrong = 0, areaSum_Correct = 0, Answer = 0;

      myFile.open("circleObjects.dat", ios::in | ios::binary);  // Uploaded file_name must match here and it is provided through email.
      i = 1;
      int counter = 0;

      while(i <= numberOfCircles){
          Circle c;
          myFile.read(reinterpret_cast<char*>(&c), sizeof(Circle)); // This is reading circles sequentially from .dat file
         
          if ((c.getRadius() >=1 )&& (c.getRadius() <= 20)){
              areaSum_Correct += c.getArea();
              }
          else {
            c.setRadius(radius_Correct);
            areaSum_Wrong += c.getArea();
            numberOfIncorrectCircles++;
          }
          i++;
	   }
      myFile.close();


      cout<<"\n\tSum of areas of circles(Wrong): "<<areaSum_Wrong<<endl; //Evaluate areaSum_Correct so it don't be 0.
      cout<<"\n\tSum of areas of circles(Correct): "<<areaSum_Correct<<endl;    //Evaluate areaSum_Correct so it don't be 0.
      Answer = areaSum_Correct - areaSum_Wrong;
      cout<<"\n\tDifference between correct and wrong areas : "<<Answer<<endl;
      cout<<"\n\tNumber of incorrect circles : "<<numberOfIncorrectCircles<<endl; //Evaluate numberOfIncorrectCircles so it don't be 0.
    return 0;
}

