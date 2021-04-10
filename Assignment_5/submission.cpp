#include<iostream>
#include<cmath>
#define pi M_PI
using namespace std;
class AD{
    public:
        int N;
        double f ;// function value at x
        double *df; // derivative of function at x
        AD();
        AD(int);
        AD(int,int,double);
        void operator=(AD);
        friend AD operator+(AD,AD); // f + g
        friend AD operator-(AD,AD); // f - g
        friend AD operator*(AD,AD); // f * g
        friend AD operator/(AD,AD); // f / g
        friend AD operator^(AD,AD); //f^g
        // Do for the rest of all possible operations like,
        // f+c, f-c, f*c, f/c.
        friend AD operator+(AD,double);//f+c
        friend AD operator-(AD,double);//f-c
        friend AD operator*(AD,double);//f*c
        friend AD operator/(AD,double);//f/c
        friend AD operator^(AD,double);//f^c

        // c+f, c-f, c*f, c/f, c^f.
        friend AD operator+(double,AD);//c+f
        friend AD operator-(double,AD);//c-f
        friend AD operator*(double,AD);//c*f
        friend AD operator/(double,AD);//c/f
        friend AD operator^(double,AD);//c^f

        // sin(f), cos(f), tan(f), cosec(f), sec(f), cot(f).
        // arcsin(f), arccos(f), arctan(f), sinh(f), cosh(f), tanh(f).
        // log(f), exp(f).
        // etc.

        friend AD sin(AD);
        friend AD cos(AD);
        friend AD tan(AD);
        friend AD cosec(AD);
        friend AD sec(AD);
        friend AD cot(AD);

        friend AD arcsin(AD);
        friend AD arccos(AD);
        friend AD arctan(AD);
        friend AD arccosec(AD);
        friend AD arcsec(AD);
        friend AD arccot(AD);

        friend AD sinh(AD);
        friend AD cosh(AD);
        friend AD tanh(AD);
        friend AD cosech(AD);
        friend AD sech(AD);
        friend AD coth(AD);

        friend AD arcsinh(AD);
        friend AD arccosh(AD);
        friend AD arctanh(AD);
        friend AD arccosech(AD);
        friend AD arcsech(AD);
        friend AD arccoth(AD);

        friend AD exp(AD);
        friend AD log(AD);




};
AD :: AD(){}
AD :: AD(int Nt){
    N=Nt; f=0;
    df=new double[N];
    for(int i=0;i<N;i++){
        df[i]=0;
    }
}
AD :: AD(int Nt,int var,double value){
    N=Nt; f=value;
    df=new double[N];
    for(int i=0;i<N;i++){
        df[i]=0;
    }
    df[var]=1;

}
void AD :: operator = (AD New){

        N = New.N; f = New.f;
        df = new double[N];
        for (int i = 0; i < N; i++)
            df[i] = New.df[i];
}

AD operator+(AD c,AD g){
    AD h=AD(g.N);
    h.f = c.f + g.f;
    for(int i=0;i<h.N;i++){
        h.df[i]=c.df[i]+g.df[i];
    }
    return h;
}
AD operator-(AD c,AD g){
    AD h=AD(g.N);
    h.f = c.f - g.f;
    for(int i=0;i<h.N;i++){
        h.df[i]=c.df[i]-g.df[i];
    }
    return h;
}

AD operator*(AD c,AD g){
    AD h=AD(g.N);
    h.f = c.f * g.f;
    for(int i=0;i<h.N;i++){
        h.df[i]=c.f*g.df[i]+c.df[i]*g.f;
    }
    return h;
}

AD operator/( AD c,AD g){
    AD h=AD(g.N);
    h.f = c.f / g.f;
    for(int i=0;i<h.N;i++){
        h.df[i]=(c.df[i]*g.f-c.f*g.df[i])/(g.f*g.f);
    }
    return h;
}
AD operator^(AD c,AD g){
    AD h=AD(g.N);
    h.f=pow(c.f,g.f);
    for(int i=0;i<h.N;i++){
        h.df[i]=pow(c.f,g.f)*log(c.f)*g.df[i];
    }
    return h;
}

//f+k
AD operator+(AD c,double k){
    AD h=AD(c.N);
    h.f=c.f+k;
    for(int i=0;i<h.N;i++){
        h.df[i]=c.df[i]+0;
    }
    return h;
}
AD operator-(AD c,double k){
    AD h=AD(c.N);
    h.f=c.f-k;
    for(int i=0;i<h.N;i++){
        h.df[i]=c.df[i]-0;
    }
    return h;
}
AD operator*(AD c,double k){
    AD h=AD(c.N);
    h.f=c.f*k;
    for(int i=0;i<h.N;i++){
        h.df[i]=k*c.df[i];
    }
    return h;
}
AD operator/(AD c,double k){
    AD h=AD(c.N);
    h.f=c.f/k;
    for(int i=0;i<h.N;i++){
        h.df[i]=c.df[i]/k;
    }
    return h;
}
AD operator^(AD c,double k){
    AD h=AD(c.N);
    h.f = pow(c.f, k);
    for(int i=0;i<h.N;i++){
        h.df[i]=k*pow(c.f,k-1)*c.df[i];
    }
    return h;
}
//k+g
AD operator+(double k,AD g){
    return g+k;
}
AD operator-(double k,AD g){
    AD h=AD(g.N);
    h.f=k-g.f;
    for(int i=0;i<h.N;i++){
        h.df[i]=0-g.df[i];
    }
    return h;
}
AD operator*(double k,AD g){
    return g*k;
}
AD operator/(double k,AD g){
    AD h=AD(g.N);
    h.f=k/g.f;
    for(int i=0;i<h.N;i++){
        h.df[i]==-(k/pow(g.f,2))*g.df[i];
    }
    return h;
}
AD operator^(double k,AD g){
    AD h=AD(g.N);
    h.f=pow(k,g.f);
    for(int i=0;i<h.N;i++){
        h.df[i]=pow(k,g.f)*log(k)*g.df[i];
    }
    return h;
}

AD sin(AD g){
    AD h=AD(g.N);
    h.f = sin(g.f);
    for(int i=0;i<h.N;i++){
        h.df[i] = cos(g.f)*g.df[i];
    }
    return h;
}
AD cos(AD g){
    AD h=AD(g.N);
    h.f = cos(g.f);
    for(int i=0;i<h.N;i++){
        h.df[i] = -sin(g.f)*g.df[i];
    }
    return h;
}
AD sec(AD g){
    AD h=AD(g.N);
    h.f=1/cos(g.f);
    for(int i=0;i<h.N;i++){
        h.df[i]=(1/cos(g.f))*tan(g.f)*g.df[i];
    }
    return h;
}
AD tan(AD g){
    AD h=AD(g.N);
    h.f=tan(g.f);
    for(int i=0;i<h.N;i++){
        h.df[i]=pow(1/cos(g.f),2)*g.df[i];
    }
    return h;
}

AD cosec(AD g){
    AD h=AD(g.N);
    h.f=1/sin(g.f);
    for(int i=0;i<h.N;i++){
        h.df[i]=-(1/sin(g.f))*(1/tan(g.f))*g.df[i];
        }
    return h;
}
AD cot(AD g){
    AD h=AD(g.N);
    h.f=1/tan(g.f);
    for(int i=0;i<h.N;i++){
        h.df[i]=-pow(1/sin(g.f),2)*g.df[i];
    }
    return h;
}
AD sinh(AD g){
    AD h=AD(g.N);
    h.f=sinh(g.f);
    for(int i=0;i<h.N;i++){
        h.df[i]=cosh(g.f)*g.df[i];
    }
    return h;
}
AD cosh(AD g){
    AD h=AD(g.N);
    h.f=cosh(g.f);
    for(int i=0;i<h.N;i++){
        h.df[i]=sinh(g.f)*g.df[i];
    }
    return h;
}
AD tanh(AD g){
    AD h=AD(g.N);
    h.f=tanh(g.f);
    for(int i=0;i<h.N;i++){
        h.df[i]=pow(1/cosh(g.f),2)*g.df[i];
    }
    return h;
}
AD coth(AD g){
    AD h=AD(g.N);
    h.f=1/tanh(g.f);
    for(int i=0;i<h.N;i++){
        h.df[i]=-pow(1/sinh(g.f),2)*g.df[i];
    }
    return h;
}
AD sech(AD g){
    AD h=AD(g.N);
    h.f=1/cosh(g.f);
    for(int i=0;i<h.N;i++){
        h.df[i]=-(1/cosh(g.f))*tanh(g.f)*g.df[i];
    }
    return h;
}
AD cosech(AD g){
    AD h=AD(g.N);
    h.f=1/sinh(g.f);
    for(int i=0;i<h.N;i++){
        h.df[i]=-(1/sinh(g.f))*(1/tanh(g.f))*g.df[i];
    }
    return h;
}
AD arcsin(AD g){
    AD h=AD(g.N);
    h.f=asin(g.f);
    for(int i=0;i<h.N;i++){
        h.df[i]=(1/(pow(1-pow(g.f,2),0.5)))*g.df[i];
    }
    return h;
}
AD arccos(AD g){
    AD h=AD(g.N);
    h.f=acos(g.f);
    for(int i=0;i<h.N;i++){
        h.df[i]=(-1/(pow(1-pow(g.f,2),0.5)))*g.df[i];
    }
    return h;
}
AD arctan(AD g){
    AD h=AD(g.N);
    h.f=atan(g.f);
    for(int i=0;i<h.N;i++){
        h.df[i]=(1/(1+pow(g.f,2)))*g.df[i];
    }
    return h;
}
AD arccot(AD g){
    AD h=AD(g.N);
    h.f=1/atan(g.f);
    for(int i=0;i<h.N;i++){
        h.df[i]=(-1/(1+pow(g.f,2)))*g.df[i];
    }
    return h;
}
AD arcsec(AD g){
    AD h=AD(g.N);
    h.f=1/acos(g.f);
    for(int i=0;i<h.N;i++){
        h.df[i]=(1/(abs(g.f)*pow(pow(g.f,2)-1,0.5)))*g.df[i];
    }
    return h;
}
AD arccosec(AD g){
    AD h=AD(g.N);
    h.f=1/asin(g.f);
    for(int i=0;i<h.N;i++){
        h.df[i]=(-1/(abs(g.f)*pow(pow(g.f,2)-1,0.5)))*g.df[i];
    }
    return h;
}
AD arcsinh(AD g){
    AD h=AD(g.N);
    h.f=asinh(g.f);
    for(int i=0;i<h.N;i++){
        h.df[i]=(1/(pow(pow(g.f,2)+1,0.5)))*g.df[i];
    }
    return h;
}
AD arccosh(AD g){
    AD h=AD(g.N);
    h.f=acosh(g.f);
    for(int i=0;i<h.N;i++){
        h.df[i]=(1/(pow(pow(g.f,2)-1,0.5)))*g.df[i];
    }
    return h;
}
AD arctanh(AD g){
    AD h=AD(g.N);
    h.f=atanh(g.f);
    for(int i=0;i<h.N;i++){
        h.df[i]=(1/(1-pow(g.f,2)))*g.df[i];
    }
    return h;
}
AD arccosech(AD g){
    AD h=AD(g.N);
    h.f=1/asinh(g.f);
    for(int i=0;i<h.N;i++){
        h.df[i]=-(1/(abs(g.f)*pow(pow(g.f,2)+1,0.5)))*g.df[i];
    }
    return h;
}
AD arcsech(AD g){
    AD h=AD(g.N);
    h.f=1/acosh(g.f);
    for(int i=0;i<h.N;i++){
        h.df[i]=-(1/((g.f)*pow(1-pow(g.f,2),0.5)))*g.df[i];
    }
    return h;
}
AD arccoth(AD g){
    AD h=AD(g.N);
    h.f=1/atanh(g.f);
    for(int i=0;i<h.N;i++){
        h.df[i]=(1/(1-pow(g.f,2)))*g.df[i];
    }
    return h;
}
AD log(AD g){
    AD h=AD(g.N);
    h.f=log(g.f);
    for(int i=0;i<h.N;i++){
        h.df[i]=(1/g.f)*g.df[i];
    }
    return h;
}
AD exp(AD g){
    AD h=AD(g.N);
    h.f=exp(g.f);
    for(int i=0;i<h.N;i++){
        h.df[i]=exp(g.f)*g.df[i];
    }
    return h;
}
class ExpSet{
public:
    int N;
    double *Vals;

    ExpSet(int Nt, double *IVals)
    {
        N = Nt;
        Vals = new double[N];
        for (int i = 0; i < N; i++)
            Vals[i] = IVals[i];
    }
    AD operator() (int V)
    {
        return AD(N, V, Vals[V]);
    }
};
void jacobian(int num,AD f[]){
     for(int i=0;i<num;i++){
        for(int j=0;j<num;j++){
            cout<<f[i].df[j]<<'\t';
        }
        cout<<endl;
     }
}
int main()
{    //test case 1
     int num1=3;
     double val1[num1]={3,8,-1};
     ExpSet Z1(num1,val1);//Expression object having no of input and array of values of variables as argument
     AD x=Z1(0),y=Z1(1),z=Z1(2);
     AD f1_1,f1_2,f1_3;
     f1_1=x*y*z+sin(x*y)*2+x*y*cos(z);
     f1_2=x*x+y*y+z*z+x*y*z;
     f1_3=x*y+y*z+z*x;
     AD f1[]={f1_1,f1_2,f1_3};
     cout<<"Test case 1:"<<endl;
     jacobian(num1,f1);
     cout<<endl;

     //test case 2
     int num2=4;
     double val2[num2]={8,2,1,5};
     ExpSet Z2(num2,val2);//Expression object having no of input and array of values of variables as argument
     AD y1=Z2(0),y2=Z2(1),y3=Z2(2),y4=Z2(3);
     AD f2_1,f2_2,f2_3,f2_4;
     f2_1=y1*cos(y1*y2)-y1*y2*log(y2)/y3+exp(y1*y2-y3);
     f2_2=log(y1)*cos(y1*y2)+y2*sin(y1+y2)/y3+exp(y1*y2-y3);
     f2_3=y1*y2*log(y2)/y3+exp(y1*y2-y3)-log(y4)*cos(y1*y2);
     f2_4=(y1+y2+y3+y4)*((y1+y2)^4);
     AD f2[]={f2_1,f2_2,f2_3,f2_4};
     cout<<"Test case 2:"<<endl;
     jacobian(num2,f2);
     cout<<endl;

     //test case 3
     int num3=3;
     double val3[num3]={1,-2,pi/3};
     ExpSet Z3(num3,val3);//Expression object having no of input and array of values of variables as argument
     AD x3_1=Z3(0), x3_2=Z3(1), x3_3=Z3(2);
     AD f3_1,f3_2,f3_3;
     f3_1=2*x3_1+3*(x3_2^2)-sin(x3_3);
     f3_2=3*x3_1-cos(x3_2*x3_3)-1.5;
     f3_3=exp(-1*x3_1*x3_2)+3*x3_3;
     AD f3[]={f3_1,f3_2,f3_3};
     cout<<"Test case 3:"<<endl;
     jacobian(num3,f3);
     cout<<endl;

     //test case 4
     int num4=1;
     double val4[num4]={pi/4};
     ExpSet Z4(num4,val4);//Expression object having no of input and array of values of variables as argument
     AD x4_1=Z4(0);
     AD f4_1;
     f4_1=sin(x4_1)*cos(x4_1)+(x4_1^3)*sin(2*x4_1);
     AD f4[]={f4_1};
     cout<<"Test case 4:"<<endl;
     jacobian(num4,f4);
     cout<<endl;

     //test case 5
     int num5=50;
     double val5[num5]={0};
     for(int i=0;i<num5;i++){
            val5[i]=i+1;
     }
     ExpSet Z5(num5,val5);//Expression object having no of input and array of values of variables as argument
     AD x1[num5];
     for(int i=0;i<num5;i++){
        x1[i]=Z5(i);
    }
     AD f[num5];
     AD m=x1[0];
     for(int j=1;j<num5;j++){
            m=m*x1[j];
     }
     for(int i=0;i<num5;i++){
        f[i]=x1[i]+m/x1[i];
     }
     cout<<"Test case 5:"<<endl;
     jacobian(num5,f);
     cout<<endl;


     return 0;
}











































































