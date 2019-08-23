#include <iostream>
using namespace std;

template<class T>
class Stack {
	T* stack;
	int top;
	int cap;

public:
	Stack(int size) {
		stack = new T[size];
		cap = size;
		top = -1;
	}

	bool is_Full() {
		return (top == (cap - 1));
	}

	bool is_Empty() {
		return (top == -1);
	}
	
	void push(T x) {
		if(is_Full()) {
			cout<<"\nStack Full! Unable to Push: "<<x;
			return;
		}
		stack[++top] = x;
	}

	T pop() {
		if(is_Empty()) {
			cout<<"\nStack Empty!";
			return (T)32;
		}
		return stack[top--];
	}

	T& Top() {
		return stack[top];
	}

	void display() {
		if(!is_Empty()) {
			for (int i = 0; i < top; ++i)
				cout<<stack[i]<<" | ";
			cout<<"["<<stack[top]<<"]";
		}
		else
			cout<<"\nStack Empty!";
	}
};