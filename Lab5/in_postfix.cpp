#include <iostream>
#include "stack.h"

using namespace std;

enum token {
	Lpar, Rpar, Operand, Operator
};

int tokentype(char x) {
	if(isalpha(x) || isdigit(x))
		return Operand;
	else
		if(x == '(')
			return Lpar;
		else
			if(x == ')')
				return Rpar;
			else
				return Operator;
}

int isp(char x) {
	switch(x) {
		case '^' : return 3;
		case '*' : 
		case '/' : return 2;
		case '+' : 
		case '-' : return 1;
		case '(' : return 0;
		case '#' : return -1;
	}
}

int icp(char x) {
	switch(x) {
		case '(' : return 4; 
		case '^' : return 4;
		case '*' : 
		case '/' : return 2;
		case '+' : 
		case '-' : return 1;
	}
}

void infix_Postfix(char infix[], char postfix[]) {
	Stack<char> s(100);
	char x, y;
	int j = 0;
	s.push('#');
	for(int i = 0, x = infix[i]; x!='\0'; i++, x=infix[i]) {
		switch(tokentype(x)) {
			case Operand :  postfix[j++] = x;
							break;
			case Rpar : y = s.pop();
						while(y != '(') {
							postfix[j++] = y;
							y = s.pop();
						}
						break;
			case Lpar : s.push('(');
						break;
			case Operator : y = s.pop();
							while(isp(y) >= icp(x)) {
								postfix[j++] = y;
								y = s.pop();
							}
							s.push(y);
							s.push(x);
		}
	}
	y = s.pop();
	while (y != '#') {
		postfix[j++] = y;
		y = s.pop();
	}
	postfix[j] = '\0';
}

int main() {
	char infix[100], postfix[100];
	cout<<"Enter an infix expression: ";
	cin>>infix;
	infix_Postfix(infix, postfix);
	cout<<"Equivalent Postfix expression: "<<postfix;
}
