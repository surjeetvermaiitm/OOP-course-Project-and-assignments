#ifndef AD_H
#define AD_H
#include<iostream>
#include<cmath>
#include<vector>
#define pi M_PI
#include "Matrix.h"

using namespace std;

template<class T>
int varCount = 0;
class AD{
private:
    T f;
    vector<T> df;
    int id;
public:
    AD();
    AD(T);
    void setVar();
    T getf();
    T getDf(int);
    vector<T> getGradient();


    AD operator *(Diff);
    AD operator +(AD);

    AD operator*(double);

    friend AD sin(AD);
    friend AD cos(AD);

};

matrix getJacobian();

AD :: AD(){
    f = 0;
}

AD :: AD(double value){
    this->f = value;
    this->id = varCount;
    varCount++;
}

void AD :: setVar(){
    this->df = vector(varCount);
    for(int i=0 ; i<this->id ; i++)
        this->df[i] = 0;
    this->df[this->id] =  1;
    for(int i = this->id + 1 ; i < varCount ;i++)
        this->df[i] = 0;
}

double AD :: getf(){
   return this->f;
}
double AD :: getDf(int index){
    return df[index];
}

vector AD :: getGradient(){
    vector gradient(varCount);
    for(int i=0 ;i<varCount;i++)
        gradient[i] = this->df[i];
    return gradient;
}

//Binary operators

AD AD :: operator +(AD g){
    AD h;
    h.f = this->f + g.f;
    h.df = vector(varCount);
    for(int i = 0 ;i<varCount ;i++)
      h.df[i] = this->df[i] + g.df[i];
    return h;
}

AD AD :: operator *(AD g){
    AD h;
    h.f = this-> f * g.f;
    h.df = vector(varCount);
    for(int i = 0 ; i <varCount ;i++)
        h.df[i] = (this->f * g.df[i]  + g.f * this->df[i]);
    return h;
}

AD sin(AD g){
    AD h;
    h.f = sin(g.f);
    h.df = vector(varCount);
    for(int i=0 ;i < varCount ; i++)
        h.df[i] = cos(g.f)*g.df[i];
    return h;
}

AD cos(AD g){
    AD h;
    h.f = cos(g.f);
    h.df = vector(varCount);
    for(int i=0 ;i < varCount ; i++)
        h.df[i] = -sin(g.f)*g.df[i];
    return h;
}

AD AD :: operator *(double s){
    AD h;
    h.f = s*(this->f);
    h.df = vector(varCount);
    for(int i = 0; i<varCount ;i++)
        h.df[i] = s*this->df[i];
    return h;
}
matrix getJacobian(int n, AD funList[]){
    matrix M = matrix(n,n);
      for(int i = 0; i<n ; i++)
       for(int j = 0 ; j< n ; j++)
         M(i,j) = funList[i].getDf(j);
    return M;
}
#endif
