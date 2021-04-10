#include<iostream>
#include<cmath>
#define pi M_PI
using namespace std;
class AD{
    public:
        double f ;
        double *df;
        int N;

        AD(){}
        AD(int Nvar){
            N=Nvar; f=0;
            df=new double[N];
            for(int i=0;i<N;i++){
                df[i]=0;
            }
        }
        AD(int Nvar,int v,double val){
            N=Nvar; f=val;
            df=new double[N];
            for(int i=0;i<N;i++){
                df[i]=0;
            }
            df[v]=1;

        }
        void operator = (AD k){

                N = k.N; f = k.f;
                df = new double[N];
                for (int i = 0; i < N; i++)
                    df[i] = k.df[i];
        }

};
AD operator+(AD p,AD g){
    AD h=AD(g.N);
    h.f = p.f + g.f;
    for(int i=0;i<h.N;i++){
        h.df[i]=p.df[i]+g.df[i];
    }
    return h;
}
AD operator-(AD p,AD g){
    AD h=AD(g.N);
    h.f = p.f - g.f;
    for(int i=0;i<h.N;i++){
        h.df[i]=p.df[i]-g.df[i];
    }
    return h;
}

AD operator*(AD p,AD g){
    AD h=AD(g.N);
    h.f = p.f * g.f;
    for(int i=0;i<h.N;i++){
        h.df[i]=p.f*g.df[i]+p.df[i]*g.f;
    }
    return h;
}

AD operator/( AD p,AD g){
    AD h=AD(g.N);
    h.f = p.f / g.f;
    for(int i=0;i<h.N;i++){
        h.df[i]=(p.df[i]*g.f-p.f*g.df[i])/(g.f*g.f);
    }
    return h;
}
AD operator^(AD p,AD g){
    AD h=AD(g.N);
    h.f=pow(p.f,g.f);
    for(int i=0;i<h.N;i++){
        h.df[i]=pow(p.f,g.f)*log(p.f)*g.df[i];
    }
    return h;
}

//g+k
AD operator+(AD g,double k){
    AD h=AD(g.N);
    h.f=g.f+k;
    for(int i=0;i<h.N;i++){
        h.df[i]=g.df[i]+0;
    }
    return h;
}
AD operator-(AD g,double k){
    AD h=AD(g.N);
    h.f=g.f-k;
    for(int i=0;i<h.N;i++){
        h.df[i]=g.df[i]-0;
    }
    return h;
}
AD operator*(AD g,double k){
    AD h=AD(g.N);
    h.f=g.f*k;
    for(int i=0;i<h.N;i++){
        h.df[i]=k*g.df[i];
    }
    return h;
}
AD operator/(AD g,double k){
    AD h=AD(g.N);
    h.f=g.f/k;
    for(int i=0;i<h.N;i++){
        h.df[i]=g.df[i]/k;
    }
    return h;
}
AD operator^(AD g,double k){
    AD h=AD(g.N);
    h.f = pow(g.f, k);
    for(int i=0;i<h.N;i++){
        h.df[i]=k*pow(g.f,k-1)*g.df[i];
    }
    return h;
}
//c+g
AD operator+(double c,AD g){
    return g+c;
}
AD operator-(double c,AD g){
    AD h=AD(g.N);
    h.f=c-g.f;
    for(int i=0;i<h.N;i++){
        h.df[i]=0-g.df[i];
    }
    return h;
}
AD operator*(double c,AD g){
    return g*c;
}
AD operator/(double c,AD g){
    AD h=AD(g.N);
    h.f=c/g.f;
    for(int i=0;i<h.N;i++){
        h.df[i]==-(c/pow(g.f,2))*g.df[i];
    }
    return h;
}
AD operator^(double c,AD g){
    AD h=AD(g.N);
    h.f=pow(c,g.f);
    for(int i=0;i<h.N;i++){
        h.df[i]=pow(c,g.f)*log(c)*g.df[i];
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

void j_matrix(AD funArray[],int n){
     for(int i=0;i<n;i++){
        for(int k=0;k<n;k++){
            cout<<funArray[i].df[k]<<'\t';
        }
        cout<<endl;
     }
}
int main(){
     //test case 1
     cout<<"output of Test case 1:"<<endl;
     AD p1,p2,p3;
     p1=AD(3,0,3),p2=AD(3,1,8),p3=AD(3,2,-1);
     AD fun1_1,fun1_2,fun1_3;
     fun1_1=p1*p2*p3+sin(p1*p2)*2+p1*p2*cos(p3);
     fun1_2=p1*p1+p2*p2+p3*p3+p1*p2*p3;
     fun1_3=p1*p2+p2*p3+p3*p1;
     AD fun1[3]={fun1_1,fun1_2,fun1_3};
     j_matrix(fun1,3);
     cout<<'\n';

     //test case 2
     cout<<"output of Test case 2:"<<endl;
     AD x1,x2,x3,x4;
     x1=AD(4,0,8),x2=AD(4,1,2),x3=AD(4,2,1),x4=AD(4,3,5);
     AD fun2_1,fun2_2,fun2_3,fun2_4;
     fun2_1=x1*cos(x1*x2)-x1*x2*log(x2)/x3+exp(x1*x2-x3);
     fun2_2=log(x1)*cos(x1*x2)+x2*sin(x1+x2)/x3+exp(x1*x2-x3);
     fun2_3=x1*x2*log(x2)/x3+exp(x1*x2-x3)-log(x4)*cos(x1*x2);
     fun2_4=(x1+x2+x3+x4)*((x1+x2)^4);
     AD fun2[4]={fun2_1,fun2_2,fun2_3,fun2_4};
     j_matrix(fun2,4);
     cout<<'\n';

     //test case 3
     cout<<"output of Test case 3:"<<endl;
     AD y1,y2,y3;
     y1=AD(3,0,1),y2=AD(3,1,-2),y3=AD(3,2,pi/3);
     AD fun3_1,fun3_2,fun3_3;
     fun3_1=2*y1+3*(y2^2)-sin(y3);
     fun3_2=3*y1-cos(y2*y3)-1.5;
     fun3_3=exp(-1*y1*y2)+3*y3;
     AD fun3[3]={fun3_1,fun3_2,fun3_3};
     j_matrix(fun3,3);
     cout<<'\n';

     //test case 4
     cout<<"output of Test case 4:"<<endl;
     AD k =AD(1,0,pi/4);
     AD fun4_1=sin(k)*cos(k)+(k^3)*sin(2*k);
     AD fun4[1]={fun4_1};
     j_matrix(fun4,1);
     cout<<'\n';

     //test case 5
     cout<<"output of Test case 5:"<<endl;
     AD x[50];
     for(int i=0;i<50;i++){
        x[i]=AD(50,i,i+1);
    }
     AD fun[50];
     AD product=x[0];
     for(int j=1;j<50;j++){
            product=product*x[j];
     }
     for(int k=0;k<50;k++){
        fun[k]=x[k]+product/x[k];
     }
     j_matrix(fun,50);
     cout<<'\n';

     return 0;
}











































































