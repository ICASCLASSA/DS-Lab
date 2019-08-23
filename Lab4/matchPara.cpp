#include <iostream>
#include "stack.h"

using namespace std;

bool check(string str) {
	Stack<char> stack(50);

	for (size_t i = 0; i < str.size(); i++) {
	    char ch = str[i];
	    if(ch == '(')
			stack.push(ch);
		if(ch == ')') {
			if(stack.is_Empty())
				return false;
			stack.pop();
		}
	}
	if(!stack.is_Empty())
		return false;
	else 
		return true;
}


int main() {
	string str;
	cout<<"Enter a String: ";
	getline(cin,str);
	cout<<endl<<str<<endl;
	if(check(str))
		cout<<"Parenthesis match in the given string!";
	else
		cout<<"Parenthesis do not match in the given string!";
}
