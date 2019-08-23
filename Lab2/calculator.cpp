#include <iostream>

using namespace std;

template<class T>
class calculator {
	T num1;
	T num2;

 public:
	calculator() {
		cout<<"\n\nInput 2 Numbers: \n";
		cin>>num1>>num2;
	}

	void output() {
		cout<<"\nnum1 = "<<num1;
		cout<<"\nnum2 = "<<num2;
		cout<<"\n + : "<<add();
		cout<<"\n - : "<<sub();
		cout<<"\n x : "<<mul();
		cout<<"\n / : "<<div();
	}

	T add() {
		return (num1 + num2);
	}

	T sub() {
		return (num1 - num2);
	}

	T mul() {
		return (num1 * num2);
	}
	
	T div() {
		return (num1 / num2);
	}
};

int main() {
	calculator<int> iObj;
	iObj.output();

	calculator<float> fObj;
	fObj.output();

	calculator<double> dObj;
	dObj.output();
}
