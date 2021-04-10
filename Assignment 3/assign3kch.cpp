#include <iostream>
#include <cmath>
using namespace std;
#define max 500

class Stack{
    private:
        int maxCapacity;
        int top;
    public:
        Stack();
        bool isEmpty();
        bool isFull();
        int getCurrentSize();
        void incrementTop();
        void decrementTop();
        int getTop();
};
class charList{
    private:
        char elements[500];
        int Size;
    public:
        charList();
        charList(int);
        void setvalue(int, char);
        char getvalue(int);
        int prec(char);
        int isOperand(char);
        charList infix_to_postfix();
        double evaluate();
        void display();
};
class intList{
    private:
        int elements[500];
        int Size;
    public:
        intList(int);
        void setvalue(int, int);
        int getvalue(int);
};
class charStack : public Stack{
    private:
        charList elements = charList(500);
    public:
        charStack();
        void push(char);
        char pop();
        char getTopElement();
};
class intStack : public Stack{
    private:
        intList elements = intList(500);
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
    postfix.display(); // Answer-1
    double value = postfix.evaluate();
    cout <<"Value is : "<< value << endl; // Answer-2
    return 0;
}
//########################### class charList: Function Definitions ##################################

charList :: charList(){
    cin >> elements;

}
charList :: charList(int val){
    Size = val;
}
void charList :: setvalue(int a, char c){
    elements[a] = c;
}
char charList :: getvalue(int a){
    return elements[a];
}
int charList :: prec(char z)
    {
        if(z == '^')
            return 3;
        else if(z == '*' || z == '/')
            return 2;
        else if(z == '+' || z == '-')
            return 1;
        else
            return -1;
    }
int charList :: isOperand(char x){
    if (x == '+' || x == '-' || x == '*' || x == '/' ||
        x == '^' || x == '(' || x == ')'){
        return 0;
        }
    return 1;
    }
charList charList :: infix_to_postfix(){
    charStack st;
    charList output(500);
    int length = 0;
    for(int i = 0; elements[i] != '\0'; i++)
    {
        if(elements[i] >= '0' && elements[i] <= '9')
            {output.setvalue(length, elements[i]);
            length++;}
        else if(elements[i] == '(')
            {st.push('(');}
        else if(elements[i] == '^'){
            output.setvalue(length, ' ');
            length++;
            st.push('^');
        }
        else if(elements[i] == ')')
        {
            char next = st.pop();
            while(st.isEmpty() != true && next!= '(')
            {
                output.setvalue(length, next);
                length++;
                next = st.pop();
            }
        }

        else{
            while(st.isEmpty() != true && prec(elements[i]) <= prec(st.getTopElement()))
            {
                output.setvalue(length, ' '); length++;
                output.setvalue(length, st.pop());
                 length++;

            } output.setvalue(length, ' '); length++;
            st.push(elements[i]);
        }

    }
    while(st.isEmpty() != true)
    {
        output.setvalue(length, ' ');
        length++;
        output.setvalue(length, st.pop());

        length++;
    }
    output.setvalue(length, '\0');
    return output;

}
double charList :: evaluate(){
	intStack st1;
	charStack st2;
	int result = 0; int length = 0;
	char d;
	int m,n;
	for (int i = 0; elements[i]!='\0'; i++) {
		d = elements[i];
		if (d >= '0' && d <= '9') {
			st2.push(d);
            length++;
		}
        else if (d == ' ' && !st2.isEmpty()) {
            for (int j=0;j<length;j++) {
                result += (st2.pop()-'0') * pow(10,j);
            }
            st1.push(result);

            length=result=0;

        }
		else if (d == '+') {
            for (int j=0;j<length;j++) {
                result += (st2.pop()-'0') * pow(10,j);
            }
            if(result !=0){
            st1.push(result);
            length=result=0;}
			m=st1.pop();
			n=st1.pop(); //cout<< m+n<< endl;
			st1.push(m + n);
		}
		else if (d == '-') {
            for (int j=0;j<length;j++) {
                result += (st2.pop()-'0') * pow(10,j);
            }
            if(result !=0){
            st1.push(result);
            length=result=0;}
			m=st1.pop();
			n=st1.pop(); //cout<< n-m<< endl;
			st1.push(n - m);
		}
		else if (d == '*') {
            for (int j=0;j<length;j++) {
                result += (st2.pop()-'0') * pow(10,j);
            }
            if(result !=0){
            st1.push(result);
            length=result=0;}
			m=st1.pop();
			n=st1.pop(); //cout<< m*n<< endl;
			st1.push(m * n);
		}
		else if (d == '/') {
            for (int j=0;j<length;j++) {
                result += (st2.pop()-'0') * pow(10,j);
            }
            if(result !=0){
            st1.push(result);
            length=result=0;}
			m=st1.pop();
			n=st1.pop(); //cout<< n/m<< endl;
			st1.push(n / m);
		}
        else if (d == '^') {
            for (int j=0;j<length;j++) {
                result += (st2.pop()-'0') * pow(10,j);
            }
            if(result !=0){
            st1.push(result);
            length=result=0;}
            m=st1.pop();
            n=st1.pop(); //cout<< pow(n,m)<< endl;
            st1.push(pow(n,m));
        }
	}

	return st1.pop();


}
void charList :: display(){
    for(int i=0; elements[i] != '\0'; i++){
           if(elements[i] != ' '){
                cout << elements[i];
            }
    }cout<< endl;
}

//########################### class intList: Function Definitions ##################################

intList :: intList(int val){
    Size = val;
}
void intList :: setvalue(int a, int c){
    elements[a] = c;
}
int intList :: getvalue(int a){
    return elements[a];
}

//########################### class stack: Function Definitions ##################################

Stack :: Stack(){
    maxCapacity = 500;
    top = -1;
}
bool Stack :: isEmpty(){
    if(top == -1){
        return true;
    }return false;
}
bool Stack :: isFull(){
    if(top == maxCapacity - 1){
        return true;
    }return false;
}
int Stack :: getCurrentSize(){
    return maxCapacity;
}
void Stack :: incrementTop(){
    top = top + 1;
}
void Stack :: decrementTop(){
    top = top - 1;
}
int Stack :: getTop(){
    return top;
}
//########################### class charStack: Function Definitions ##################################

charStack :: charStack(){ }
void charStack :: push(char a){
    incrementTop();
    elements.setvalue(getTop(), a);
}
char charStack :: pop(){
    if(isEmpty() == false){
    char c = elements.getvalue(getTop());
    elements.setvalue(getTop(), '\0');
    decrementTop();
    return c;
    }
}
char charStack :: getTopElement(){
    return elements.getvalue(getTop());
}
//########################### class intStack: Function Definitions ##################################

intStack :: intStack(){ }
void intStack :: push(int b){
    if(isFull() == false){
    incrementTop();
    elements.setvalue(getTop(), b);
    }
}
int intStack :: pop(){
    if(isEmpty() == false){
    int c = elements.getvalue(getTop());
    decrementTop();
    return c;}
}
int intStack :: getTopElement(){
    return elements.getvalue(getTop());
}



