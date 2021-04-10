#ifndef NONLINEARDE_H
#define NONLINEARDE_H

#include<iostream>
#include<vector>
#include "AD.h"
#include "NonLinearSolver.h"
#include "Matrix.h"

using namespace std;

template<class T>
class NonLinearDE {
    int numVar;
    var<T> **var_list;
    gNode<T> A,B,C,D,E;
    int Nx,Ny;
    T p,q,r,s,a,b,c,d;
    NonLinearSolver<T> *ns;
    LinearSolver<T> *ls;
    Matrix<T> mesh;
    vector<T> *initialiGuess;

public:
    NonLinearDE() {};
    NonLinearDE(int,var<T>**,gNode<T>&,AD<T>,AD<T>,AD<T>,AD<T>,AD<T>,T,T,T,T,T,T,T,T,int,int);
    void solveDE(vector<T>*=NULL,NonLinearSolver<T>*=NULL,LinearSolver<T>*=NULL);
    Matrix<T> getSolution(){return mesh;}

};
template<class T>
NonLinearDE<T> :: NonLinearDE(int numVar,var<T>** variables,gNode<T> &U,AD<T> A,AD<T> B,AD<T> C,AD<T> D,AD<T> E,T p,T q,T r,T s,T a,T b,T c,T d,int Nx,int Ny){
    if(numVar>2){
        cout<<"Too many variables"<<endl;
        exit(1);
    }

    this->numVar=numVar;
    this->var_list=variables;
    this->U=&U;
    this->A=A; this->B=B; this->C=C; this->D=D; this->E=E;
    this->p=p;this->q=q;this->r=r;this->s=s;
    this->a=a;this->b=b;this->c=c;this->d=d;
    this->Nx=Nx;this->Ny=Ny;

}
template<class T>
void NonLinearDE<T> :: solveDE(vector<T>* initialGuess,NonLinearSolver<T>* ns,LinearSolver<T>* ls){
    if(initialGuess==NULL){
        cout<<"default guess is 1"<<endl;
        int size=(this->Nx-2)*(this->Ny-2);
        this->initialGuess=new vector<T>(size,1);
    }
    else if((*initialGuess).size()!=(this->Nx-2)*(this->Ny-2)){
        cout<<"initial guss vector's size not match with no of eqn"<<endl;
        exit(1);
    }
    else
        this->initialGuess=initialGuess;

    var<T> v_mesh[this->Nx][this->Ny];
    for(int i=0;i<this->Nx;i++){
        v_mesh[i][0]=a;
        v_mesh[i][this->Ny-1]=b;
    }
    for(int j=0;j<this->Ny;j++){
        v_mesh[0][j]=c;
        v_mesh[this->Nx-1][j]=d;
    }
    int count=0;
    for(int i=1;i<this->Nx-1;i++){
        for(int j=1;j<this->Ny-1;j++){
            v_mesh[i][j]=(*(this->initialGuess))[count++];
        }
    }

    AD<T> *F_list=new AD<T>[(this->Nx-2)*(this->Ny-2)];
    gNode<T> _Ui,_Uj,Ui_,Uj_;//U(i-1,j) U(i,j-1) U(i+1,j) U(i,j+1)
    T h=(q-p)/(this->Nx-1), k=(s-r)/(this->Ny-1);

    count=0;
    for(int i=1;i<this->Nx-1;i++){
        for(int j=1;j<this->Ny-1;j++){
            *(this->var_list[0])=this->p+i*h;

            if(this->numVar>1)
                *(this->var_list[1])=this->r+j*k;

            _Ui=v_mesh[i-1][j];
            _Uj=v_mesh[i][j-1];
            *(this->U)=v_mesh[i][j];
            ui_=v_mesh[i+1][j];
            uj_=v_mesh[i][j+1];

            AD<T> c1=this->A*(Ui_ -2.0*(*(this->U))+ _Ui)/(h*h);
            AD<T> c2=this->B*(Uj_ -2.0*(*(this->U))+ _Uj)/(k*k);
            AD<T> c3=this->C*(Ui_ - _Ui)/(2.0*h);
            AD<T> c4=this->D*(Uj_ - _Uj)/(2.0*k);

            AD<T> temp=sCopyAD(c1+c2+c3+c4+this->E);
            F_list[count++]=copyAD(temp);


        }
    }

    var<T> **v_linear=new var<T>*[(this->Nx-2)*(this->Ny-2)];

}

#endif // NONLINEARDE_H





























