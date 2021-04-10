#include<iostream>
#include<cmath>
#include<vector>
#include<map>
#include "Matrix.h"
#include "LinearSolver.h"
#include "NonLinearSolver.h"
#include "NonLinearDE.h"
#include <fstream>

using namespace std;
int main(){
    AD<double> A,B,C,D,E;
    var<double> x,y;
    gNode<double> U;

    //poisson eqn
    double p=0,q=1,r=0,s=1;
    double a=0,b=0,c=0,d=0;
    int Nx=6,Ny=7;
    A=1;
    B=1;
    C=0;
    D=0;
    E=2;

    var<double> *varlist[]={&x,&y};
    vector<double> InitialGuess((Nx-2)*(Ny-2),1);
    Newton<double> NS;
    Gauss_Seidal<double> GS;

    NonLinearDE<double> nde(2,varlist,U,A,B,C,D,E,p,q,r,s,a,b,c,d,Nx,Ny);
    nde.solveDE(&InitialGuess,&NS,&GS);

    cout<<"solution"<<endl;
    Matrix<double> solution = nde.getSolution();
    solution.disp();

}


























