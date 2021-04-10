
#ifndef NONLINEARSOLVER_H
#define NONLINEARSOLVER_H

#include<iostream>
#include<vector>
#include<cmath>
#include "AD.h"
#include "LinearSolver.h"
#include "Matrix.h"

using namespace std;

template<class T>
class NonLinearSolver{
public:
    virtual void input(int,var<T>**,vector<T>,AD<T>*,LinearSolver<T>*);
    virtual vector<T> NonLinearSolve()=0;
private:

};
//Newton method
template<class T>
class Newton: public NonLinearSolver<T>{
public:
    Newton(){};
    Newton(int,var<T>**,vector<T>,AD<T>*,LinearSolver<T>*);
    void input(int,var<T>**,vector<T>,AD<T>*,LinearSolver<T>*);
    vector NonLinearSolve();
    int getNumVar();
    var<T>** getVariables();
    vector<T> getInitialvec();
    AD<T>* getADList();
private:
    int numberOfVariables;
    var<T>** variables;
    vector<T> initialVector;
    AD<T>* functions;
    LinearSolver<T>* sol;
};

template<class T>
Newton<T>::Newton(int numVar,var<T>** variables,vector<T> initialVec,AD<T>* functions,LinearSolver<T>* s){
    this->numberOfVariables=numVar;
    this->variables=variables;
    this->initialVector=initialVec;
    this->functions=functions;
    this->sol=s;
}
template<class T>
vector<T> Newton<T>::NonLinearSolve(){
    vector<T> v,funcVector,b;
    Matrix<T> jacob_f(numberOfVariables);
    var<T>** variables=this->getVariables();
    vector<T> initialVec=this->getInitialvec(),oldVec,newVec;
    AD<T>* AD_list=this->getADList();
    vector<T> initialVector;
    int maxItr=50;

    for(int k=0;k<maxItr;k++){
        oldVec=initialVec;
        for(int i=0;i<this->getNumVar();i++){
            *(variables[i])=initialVec[i];
        }

        for(int i=0;i<this->getNumVar();i++){
            AD_list[i].reeval();
        }

        jacob_f=jacobian(numberOfVariables,variables,AD_list);
        funcVector=functionVector(numberOfVariables,AD_list);

        b=(jacob_f*initialVec)-funcVector;
        initialVec=sol->solve(jacob_f,b);
        newVec=initialVec;

        if(abs(norm(oldVec-newVec))<0.000001){
            break;
        }
        else if(k==50){
            cout<<"Solution diverge"<<endl;
            exit(1);
        }
    }
    return newVec;
}

#endif

























