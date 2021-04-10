#include <iostream>
#include<cmath>
using namespace std;

class doubleList{
    private:
        double list[15];
        //int maxSize;
    public:
        // declare constructors and member functions
        doubleList();
        double get(int);

};

class boolList{
    private:
        double list[3];
    public:
        void display();
        void set(int,bool);

};


class boolMatrix{
    private:
        bool list[3][3];
    public:
        // declare constructors and member functions
        void display();
        void set(int,int,bool);
};

class point{
    private:
        double x;
        double y;
    public:
        point();
        point(double,double);
        void setX(double);
        void setY(double);
        double getX();
        double getY();

        // declare constructors and member functions
};

class circle{
    private:
        double radius;
        point c;
    public:
        circle();
        circle(double,point);
        double getRadius();
        void setRadius(double);
        point getCentre();


};

class triangle{
    private:
        point A, B, C;
    public:
        triangle();
        triangle(point, point, point);
        point getA();
        point getB();
        point getC();
        void setA(point);
        void setB(point);
        void setC(point);
        // declare other constructors and member functions as you go
};

class rectangle{
    private:
        point D, E;
    public:
        rectangle();
        rectangle(point,point);
        point getD();
        point getE();
        void setD(point);
        void setE(point);

};
// Make class structors for circle, rectangle, boolList etc.

class geometry{
    private:
        point p;
        triangle T;
        rectangle R;
        circle C;
    public:
        geometry();
        geometry(doubleList);
        circle getCircle();
        point getPoint();
        rectangle getRectangle();
        triangle getTriangle();
        bool isPointLie();
        double circleArea();
        double triangleArea();
        double rectangleArea();
        // declare other constructors and member functions as you go

};

boolList areShapesIntersect(geometry, geometry);  // function prototype
boolMatrix areShapesBigger(geometry, geometry);   // function prototype
// Note-1: Don't define any other functions for main().
// Note-2: Don't make any changes in body of the main().
int main()
{
    doubleList list1, list2;
    geometry set1(list1), set2(list2);
    bool Answer1 = set1.isPointLie();  // Is the point lie on the all closed geometric shapes in set-1?
    bool Answer2 = set2.isPointLie();  // Is the point lie on the all closed geometric shapes in set-2?
    cout << std::boolalpha;
    boolList Answer3 = areShapesIntersect(set1, set2); // Are alike shapes in set1 and set2 intersect?
    boolMatrix Answer4 = areShapesBigger(set1, set2);  // Are shapes in set1 bigger than set2?
    cout << std::boolalpha;
    cout<<Answer1<<endl; // display answer1 as boolean
    cout<<Answer2<<endl; // display answer2 as boolean
    Answer3.display();  // display answer3 as boolean list
    cout<<endl;
    Answer4.display(); // display answer3 as boolean matrix
    return 0;
}


// #####################  Definitations of all constructors, member functions in classes and functions used in main #######################
// ******************************** member functions for the class: doubleList ***********************************
//code here for defining doubleList
doubleList :: doubleList(){
    for(int i = 0 ; i < 15; i++){
            cin >> list[i];
        }
}

double doubleList :: get(int index){
    return list[index];
}

// ******************************** member functions for the class: boolList ***********************************
//code here for defining boolList
void boolList :: display(){
    for(int i=0 ; i<3 ;i++){
        cout<<bool(list[i])<<'\t';
    }
}
void boolList :: set(int i,bool value){
    this->list[i] = value;
}

// ******************************** member functions for the class: boolMatrix ***********************************
 //code here for defining boolMatrix
void boolMatrix :: display(){
    for(int i=0 ; i<3 ;i++){
        for(int j=0;j<3;j++){
            cout<<list[i][j]<<'\t';
        }
        cout<<endl;
    }
}
void boolMatrix :: set(int i,int j,bool value){
    this->list[i][j] = value;
}


// ******************************** member functions for the class: point **********************************
//code here for defining point
point :: point(){
    this->x=0;
    this->y=0;
}
point :: point(double x,double y){
    this->x=x;
    this->y=y;
}
void point :: setX(double x){
    this->x=x;
}
void point :: setY(double y){
    this->y=y;
}
double point :: getX(){
    return this->x;
}
double point :: getY(){
    return this->y;
}

// ******************************** member functions for the class: circle **********************************
//code here for defining circle
circle :: circle(){
    this->radius = 1;
    this->c.setX(0);
    this->c.setY(0);
}
circle :: circle(double radius,point p){
    this->radius=radius;
    this->c=p;
}
void circle :: setRadius(double radius){
    this->radius = radius;
}
double circle :: getRadius(){
    return this->radius;
}

point circle :: getCentre(){
    return this->c;
}
// ******************************** member functions for the class: triangle **********************************
 //code here for defining triangle

triangle :: triangle(){
    point a;
    point b;
    point c;
    a.setX(0);
    a.setY(0);
    b.setX(1);
    b.setY(1);
    c.setX(2);
    c.setY(2);
    this->A=a;
    this->B=b;
    this->C=c;
}
triangle :: triangle(point a,point b,point c){
    this->A=a;
    this->B=b;
    this->C=c;
}
point triangle :: getA(){
    return this->A;
}
point triangle :: getB(){
    return this->B;
}
point triangle :: getC(){
    return this->C;
}
void triangle :: setA(point a){
    this->A=a;
}
void triangle :: setB(point b){
    this->B=b;
}
void triangle :: setC(point c){
    this->C=c;
}

//Rectangle
rectangle :: rectangle(){
    point a;
    point b;
    a.setX(0);
    a.setY(0);
    b.setX(1);
    b.setY(1);
    this->D=a;
    this->E=b;

}
rectangle :: rectangle(point d,point e){
    this->D=d;
    this->E=e;
}
point rectangle :: getD(){
    return this->D;
}
point rectangle :: getE(){
    return this->E;
}
void rectangle :: setD(point d){
    this->D=d;
}
void rectangle :: setE(point e){
    this->E=e;
}
// ******************************** member functions for the class: geometry **********************************
 //code here for defining geometry

geometry :: geometry(){
    this->p=point();
    this->C=circle();
    this->T=triangle();
    this->R=rectangle();
}
geometry :: geometry(doubleList list){
    this->p=point(list.get(0),list.get(1));
    this->C=circle(list.get(2),point(list.get(3),list.get(4)));
    this->T=triangle(point(list.get(5),list.get(6)),point(list.get(7),list.get(8)),point(list.get(9),list.get(10)));
    this->R=rectangle(point(list.get(11),list.get(12)),point(list.get(13),list.get(14)));

}
point geometry :: getPoint(){
    return this->p;
}
circle geometry :: getCircle(){
    return this->C;
}
triangle geometry :: getTriangle(){
    return this->T;
}
rectangle geometry :: getRectangle(){
    return this->R;
}
bool geometry :: isPointLie(){
    double x,y,r,x1,y1,x2,y2,x3,y3,x4,y4,x5,y5,x6,y6;
    x=p.getX();
    y=p.getY();
    r=C.getRadius();
    x1=C.getCentre().getX();
    y1=C.getCentre().getY();
    x2=T.getA().getX();
    y2=T.getA().getY();
    x3=T.getB().getX();
    y3=T.getB().getY();
    x4=T.getC().getX();
    y4=T.getC().getY();
    x5=R.getD().getX();
    y5=R.getD().getY();
    x6=R.getE().getX();
    y6=R.getE().getY();
    bool cir,tri,rec;
    cir=pow(x1-x,2)+pow(y1-y,2)<=pow(r,2);
    if (x5<x6 && y5<y6){
        rec=((x5<=x) && (x<=x6)) &&((y5<=y) && (y<y6));
    }
    else if(x5>x6 && y5>y6){
        rec=((x6<=x) && (x<=x5)) &&((y6<=y) && (y<y5));
    }
    else if(x5>x6 && y5<y6){
        rec=((x6<=x) && (x<=x5)) &&((y5<=y) && (y<y6));
    }
    else if(x5<x6 && y5>y6){
        rec=((x5<=x) && (x<=x6)) &&((y6<=y) && (y<y5));
    }
    double a1,a2,a3,A;
    a1=abs((x*(y3-y4) + x3*(y4-y)+ x4*(y-y3))/2.0);
    a2=abs((x2*(y-y4) + x*(y4-y2)+ x4*(y2-y))/2.0);
    a3=abs((x2*(y3-y) + x3*(y-y2)+ x*(y2-y3))/2.0);
    A=abs((x2*(y3-y4) + x3*(y4-y2)+ x4*(y2-y3))/2.0);
    tri = abs(A-(a1+a2+a3))<=0.1;
    return cir && rec && tri;

}
double geometry :: circleArea(){
    double r,x1,y1;
    r=C.getRadius();
    return M_PI*r*r;

}
double geometry :: triangleArea(){
    double x2,y2,x3,y3,x4,y4;
    x2=T.getA().getX();
    y2=T.getA().getY();
    x3=T.getB().getX();
    y3=T.getB().getY();
    x4=T.getC().getX();
    y4=T.getC().getY();

    return abs((x2*(y3-y4) + x3*(y4-y2)+ x4*(y2-y3))/2.0);

}
double geometry :: rectangleArea(){
    double x5,y5,x6,y6;
    x5=R.getD().getX();
    y5=R.getD().getY();
    x6=R.getE().getX();
    y6=R.getE().getY();

    return abs(x5-x6)*abs(y5-y6);

}

// ******************************** functions for main() **********************************
bool pointInTriangle(point p,triangle t){
    double x,y,x1,y1,x2,y2,x3,y3,D,s,k,dx,dy,dx1,dy1;
    x=p.getX();
    y=p.getY();
    x1=t.getA().getX();
    y1=t.getA().getY();
    x2=t.getB().getX();
    y2=t.getB().getY();
    x3=t.getC().getX();
    y3=t.getC().getY();
    dx=x-x3;
    dy=y-y3;
    dx1=x3-x2;
    dy1=y2-y3;
    D=dy1*(x1-x3)+dx1*(y1-y3);
    s=dy1*dx+dx1*dy;
    k=(y3-y1)*dx+(x1-x3)*dy;
    if (D<0){
        return s<=0 && k<=0 && s+k>=D;
    }
    return s>=0 && k>=0 && s+k<=D;
}
bool lineIntersect(point a,point b,point c,point d){
    double x1,y1,x2,y2,x3,y3,x4,y4,x12,y12,x34,y34,m,a1,b1,x,y;
    x1=a.getX();
    y1=a.getY();
    x2=b.getX();
    y2=b.getY();
    x3=c.getX();
    y3=c.getY();
    x4=d.getX();
    y4=d.getY();
    x12=x1-x2;
    x34=x3-x4;
    y12=y1-y2;
    y34=y3-y4;
    m=x12*y34-y12*x34;
    if (m==0){return false;}
    a1=x1*y2-y1*x2;
    b1=x3*y4-y3*x4;
    x=(a1*x34-b1*x12)/m;
    y=(a1*y34-b1*y12)/m;
    return (min(x1,x2)<x && x<max(x1,x2) && min(x3,x4)<x && x<max(x3,x4)) || (min(y1,y2)<y && y<max(y1,y2) && min(y3,y4)<y && y<max(y3,y4));


}



bool isCircleIntersest(geometry set1,geometry set2){
    circle c1,c2;
    double r1,r2,x1,y1,x2,y2;
    c1=set1.getCircle();
    c2=set2.getCircle();
    r1=c1.getRadius();
    r2=c2.getRadius();
    x1=c1.getCentre().getX();
    y1=c1.getCentre().getY();
    x2=c2.getCentre().getX();
    y2=c2.getCentre().getY();
    bool ans;
    ans=pow(x2-x1,2)+pow(y2-y1,2)<=pow(r1+r2,2);
    return ans;


}
bool isTriangleIntersect(geometry set1,geometry set2){
    triangle t1,t2;
    point p1,p2,p3,p4,p5,p6;
    t1=set1.getTriangle();
    t2=set2.getTriangle();
    p1=t1.getA();
    p2=t1.getB();
    p3=t1.getC();
    p4=t2.getA();
    p5=t2.getB();
    p6=t2.getC();
    bool ans1=pointInTriangle(p1,t2);
    bool ans2=pointInTriangle(p2,t2);
    bool ans3=pointInTriangle(p3,t2);
    bool ans4=pointInTriangle(p4,t1);
    bool ans5=pointInTriangle(p5,t1);
    bool ans6=pointInTriangle(p6,t1);

    bool ans7=lineIntersect(p1,p2,p4,p5);
    bool ans8=lineIntersect(p1,p2,p5,p6);
    bool ans9=lineIntersect(p1,p2,p4,p6);
    bool ans10=lineIntersect(p2,p3,p4,p5);
    bool ans11=lineIntersect(p2,p3,p5,p6);
    bool ans12=lineIntersect(p2,p3,p4,p6);
    bool ans13=lineIntersect(p1,p3,p4,p5);
    bool ans14=lineIntersect(p1,p3,p5,p6);
    bool ans15=lineIntersect(p1,p3,p4,p6);

    return ans1 ||ans2 || ans3 || ans4 || ans5 || ans6 || ans7 ||ans8 || ans9 || ans10 || ans11 || ans12 || ans13 ||ans14 || ans15;

}
bool isRectangleIntersect(geometry set1,geometry set2){
    rectangle r1,r2;
    double x1,y1,x2,y2,x3,y3,x4,y4;
    bool rec1,rec2,rec3,rec4,ans;
    r1=set1.getRectangle();
    r2=set2.getRectangle();
    if(set1.rectangleArea()<set2.rectangleArea()){
        rectangle temp=r1;
        r1=r2;
        r2=temp;
    }
    x1=r1.getD().getX();
    y1=r1.getD().getY();
    x2=r1.getE().getX();
    y2=r1.getE().getY();
    x3=r2.getD().getX();
    y3=r2.getD().getY();
    x4=r2.getE().getX();
    y4=r2.getE().getY();
    //point1
    if (x1<x2 && y1<y2){
        rec1=((x1<=x3) && (x3<=x2)) &&((y1<=y3) && (y3<y2));
    }
    else if(x1>x2 && y1>y2){
        rec1=((x2<=x3) && (x3<=x1)) &&((y2<=y3) && (y3<y1));
    }
    else if(x1>x2 && y1<y2){
        rec1=((x2<=x3) && (x3<=x1)) &&((y1<=y3) && (y3<y2));
    }
    else if(x1<x2 && y1>y2){
        rec1=((x1<=x3) && (x3<=x2)) &&((y2<=y3) && (y3<y1));
    }
    //point 2
    if (x1<x2 && y1<y2){
        rec2=((x1<=x4) && (x4<=x2)) &&((y1<=y3) && (y3<y2));
    }
    else if(x1>x2 && y1>y2){
        rec2=((x2<=x4) && (x4<=x1)) &&((y2<=y3) && (y3<y1));
    }
    else if(x1>x2 && y1<y2){
        rec2=((x2<=x4) && (x4<=x1)) &&((y1<=y3) && (y3<y2));
    }
    else if(x1<x2 && y1>y2){
        rec2=((x1<=x4) && (x4<=x2)) &&((y2<=y3) && (y3<y1));
    }
    //point 3
    if (x1<x2 && y1<y2){
        rec3=((x1<=x3) && (x3<=x2)) &&((y1<=y4) && (y4<y2));
    }
    else if(x1>x2 && y1>y2){
        rec3=((x2<=x3) && (x3<=x1)) &&((y2<=y4) && (y4<y1));
    }
    else if(x1>x2 && y1<y2){
        rec3=((x2<=x3) && (x3<=x1)) &&((y1<=y4) && (y4<y2));
    }
    else if(x1<x2 && y1>y2){
        rec3=((x1<=x3) && (x3<=x2)) &&((y2<=y4) && (y4<y1));
    }
    //point 4
    if (x1<x2 && y1<y2){
        rec4=((x1<=x4) && (x4<=x2)) &&((y1<=y4) && (y4<y2));
    }
    else if(x1>x2 && y1>y2){
        rec4=((x2<=x4) && (x4<=x1)) &&((y2<=y4) && (y4<y1));
    }
    else if(x1>x2 && y1<y2){
        rec4=((x2<=x4) && (x4<=x1)) &&((y1<=y4) && (y4<y2));
    }
    else if(x1<x2 && y1>y2){
        rec4=((x1<=x4) && (x4<=x2)) &&((y2<=y4) && (y4<y1));
    }
    point p1(x1,y1),p2(x2,y1),p3(x2,y2),p4(x1,y2),p5(x3,y3),p6(x4,y3),p7(x4,y4),p8(x3,y4);
    bool ans1=lineIntersect(p1,p2,p5,p6);
    bool ans2=lineIntersect(p1,p2,p6,p7);
    bool ans3=lineIntersect(p1,p2,p7,p8);
    bool ans4=lineIntersect(p1,p2,p5,p8);
    bool ans5=lineIntersect(p2,p3,p5,p6);
    bool ans6=lineIntersect(p2,p3,p6,p7);
    bool ans7=lineIntersect(p2,p3,p7,p8);
    bool ans8=lineIntersect(p2,p3,p5,p8);
    bool ans9=lineIntersect(p3,p4,p5,p6);
    bool ans10=lineIntersect(p3,p4,p6,p7);
    bool ans11=lineIntersect(p3,p4,p7,p8);
    bool ans12=lineIntersect(p3,p4,p5,p8);
    bool ans13=lineIntersect(p4,p1,p5,p6);
    bool ans14=lineIntersect(p4,p1,p6,p7);
    bool ans15=lineIntersect(p4,p1,p7,p8);
    bool ans16=lineIntersect(p4,p1,p5,p8);

    ans=rec1||rec2||rec3||rec4 || ans1 || ans2 || ans3 || ans4 || ans5 || ans6 || ans7 || ans8 || ans9 || ans10 || ans11 || ans12 || ans13 || ans14 || ans15 || ans16;
    return ans;

}
boolList areShapesIntersect(geometry set1, geometry set2){
    boolList answer;
    bool val1=isCircleIntersest(set1,set2);
    bool val2=isTriangleIntersect(set1,set2);
    bool val3=isRectangleIntersect(set1,set2);

    answer.set(0,val1);
    answer.set(1,val2);
    answer.set(2,val3);

    return answer;
}

boolMatrix areShapesBigger(geometry set1, geometry set2){
    boolMatrix answer;
    answer.set(0,0,set1.circleArea()>set2.circleArea());
    answer.set(0,1,set1.circleArea()>set2.triangleArea());
    answer.set(0,2,set1.circleArea()>set2.rectangleArea());
    answer.set(1,0,set1.triangleArea()>set2.circleArea());
    answer.set(1,1,set1.triangleArea()>set2.triangleArea());
    answer.set(1,2,set1.triangleArea()>set2.rectangleArea());
    answer.set(2,0,set1.rectangleArea()>set2.circleArea());
    answer.set(2,1,set1.rectangleArea()>set2.triangleArea());
    answer.set(2,2,set1.rectangleArea()>set2.rectangleArea());
    return answer;

}

