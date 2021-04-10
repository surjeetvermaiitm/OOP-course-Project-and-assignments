#include <iostream>
#include<cmath>
using namespace std;
#define max 500
// define classes here without defining member fucntions and constructors in them.
// define member functions space provided below
class charList{
    private:
        char elements[max];
        int size;
    public:
        charList();
        charList(int);
        int getsize();
        char getvalue(int index);
        void setvalue(int index,char value);
        charList infix_to_postfix();
        void display();
        int evaluate();
        int isOperand(char x);
        int priority(char o);
        bool isOperator(char o);

};
class intList{
    private:
        int arr[max];
        int size;
    public:
        intList();
        intList(int);
        int getSize();
        int getValue(int index);
        void setValue(int index,int val);
};
class stack{
    private:
        int top;
        int maxCapacity;
    public:
        stack();
        bool isEmpty();
        bool isFull();
        int getCurrentSize();
        void incrementTop();
        void decrementTop();
        int getTop();

};
class charStack : public stack{
    private:
        charList ele=charList(max);
    public:
        charStack();
        void push(char);
        char pop();
        char getTopElement();
};
class intStack : public stack{
    private:
        intList array=intList(max);
    public:
        intStack();
        void push(int);
        int pop();
        int getTopElement();
};

int main()
{
    charList infix;
    charList postfix = infix.infix_to_postfix();
    postfix.display();
    int value = postfix.evaluate();
    cout<<"Value is : "<< value << endl; // Answer-2
    return 0;
}
//########################### class charList: Function Definitons ##################################
// code here for charList
charList :: charList(){
    cin>>elements;
}
charList :: charList(int num){
    size=num;
    char b[size];
    for(int i=0;i<size;i++){
        elements[i]=b[i];
    }
    for(int i=0;i<size;i++){
        elements[i]='\0';
    }


}

int charList :: getsize(){
    int ct=0;
    for (int i=0;elements[i]!='\0';i++){
        int ct=ct+1;
    }
    return ct;
}
char charList :: getvalue(int index){
    return elements[index];
}
void charList :: setvalue(int index,char value){
    elements[index]=value;
}
void charList :: display(){
    int i=0;
    while(elements[i]!='\0'){
        if(elements[i]!=' '){
            cout<<elements[i];
            }
            i++;
    }
    cout<<endl;
}
int charList :: isOperand(char x){
    if (x == '+' || x == '-' || x == '*' || x == '/' ||
        x == '^' || x == '(' || x == ')'){
        return 0;
        }
    return 1;
}
int charList :: priority(char o){
    switch (o) {
    case '^':
        return 3;
	case '*':
	case '/':
		return 2;
	case '+':
	case '-':
		return 1;
	case '(':
		return 0;
	}
}
bool charList :: isOperator(char o){
    	return (o == '+' || o == '-' || o == '*' || o == '/' || o=='^');
}
intList :: intList(){
    size=max;
}
intList :: intList(int num){
    size=num;
    int c[size];
    for(int i=0;i<size;i++){
        arr[i]=c[i];
    }
    for(int i=0;i<size;i++){
        arr[i]=0;
    }
}
int intList :: getSize(){
   return size;
}
int intList :: getValue(int index){
    return arr[index];
}
void intList :: setValue(int index,int val){
    arr[index]=val;
}


charList charList :: infix_to_postfix(){
    charList post(max);
    char postfix1[max];
    char postfix2[max];
    charStack s;
    int i=0;
    int j = 0;
    int k = 0;
    char d;
    char temp;
    while (elements[i] != '\0'){
        if (isOperand(elements[i])){
            postfix1[j++] = elements[i++];
        } else {
            postfix1[j++]=' ';
            postfix1[j++]=elements[i++];
            postfix1[j++]=' ';
        }
    }
    postfix1[j] = '\0';
    
    for (int i = 0;postfix1[i]!=0; i++) {
	d = postfix1[i];
	if ((d >= '0' && d <= '9') || (d == ' ')) {
		postfix2[k++]=d;
		}
	else if (isOperator(d)) {
		if ((priority(d)>priority(s.getTopElement()) || s.isEmpty())) {
			s.push(d);
			}
		else if (priority(d) <= priority(s.getTopElement())) {
            if (d == '^' && s.getTopElement() == '^') {
                s.push(d);
                }
            else {
				while ((priority(d) <= priority(s.getTopElement()) && !s.isEmpty())) {
					  temp=s.pop();
					  postfix2[k++]= ' ';
					  postfix2[k++]= temp;
				     }
				s.push(d);
                }
			}
		}

		
		else if (d == '(') {
			s.push(d);
		}
		else if (d == ')') {
			while (s.getTopElement() != '(' && !s.isEmpty()) {
		        temp=s.pop();
				postfix2[k++]= ' ';
				postfix2[k++]= temp;
			}
			temp=s.pop();
		}
		
	}
	while (!s.isEmpty()) {
		temp=s.pop();
		postfix2[k++]= ' ';
		postfix2[k++]= temp;
	}
    postfix2[k]='\0';
    int m;
    for( m=0;postfix2[m]!='\0';m++){
        post.setvalue(m,postfix2[m]);
    }
    post.setvalue(m,'\0');

    return post;

}

int charList :: evaluate(){
	intStack s;
	char d;
	int m,n;
    charStack temp;
    int size=0;
    int result=0;
	for (int i = 0; elements[i]!='\0'; i++) {
		d = elements[i];
		if (d >= '0' && d <= '9') {
			temp.push(d);
            size++;
		}
        else if (d == ' ' && !temp.isEmpty()) {
            for (int j=0;j<size;j++) {
                result += (temp.pop()-'0') * pow(10,j);
            }
            s.push(result);
            size=0;
            result=0;

        }
		else if (d == '+') {
			m=s.pop();
			n=s.pop();
			s.push(m + n);
		}
		else if (d == '-') {
			m=s.pop();
			n=s.pop();
			s.push(n - m);
		}
		else if (d == '*') {
			m=s.pop();
			n=s.pop();
			s.push(m * n);
		}
		else if (d == '/') {
			m=s.pop();
			n=s.pop();
			s.push(n / m);
		}
        else if (d == '^') {
            m=s.pop();
            n=s.pop();
            s.push(pow(n,m));
        }
	}

	return s.pop();
}

//########################### class charStack: Function Definitons ##################################
stack :: stack(){
    top = -1;
    maxCapacity=1000;
}
bool stack :: isEmpty(){
    if(top == -1){
        return true;
    }
    return false;
}
bool stack :: isFull(){
    if(top == maxCapacity-1){
        return true;
    }
    return false;
}

int stack :: getCurrentSize(){
    return top+1;
}
void stack :: incrementTop(){
    this->top++;
}
void stack :: decrementTop(){
    this->top--;
}
int stack :: getTop(){
    if(isEmpty()){
        return -1;
    }
    return top;
}
// code here for charStack
charStack :: charStack(){

}
void charStack :: push(char x){
    incrementTop();
    ele.setvalue(getTop(),x);

}
char charStack :: pop(){
    char ch = ele.getvalue(getTop());
    decrementTop();
    return ch;

}
char charStack :: getTopElement(){
    return ele.getvalue(getTop());
}
intStack :: intStack(){

}
void intStack :: push(int y){
    incrementTop();
    array.setValue(getTop(),y);
}
int intStack :: pop(){
    int m=array.getValue(getTop());
    decrementTop();
    return m;
}
int intStack :: getTopElement(){
    return array.getValue(getTop());
}







