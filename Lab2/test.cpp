#include <iostream>

using namespace std;

template<class T1, class T2>
class test {
	T1 x;
	T2 y;
public:
    test(T1 X, T2 Y);
    void disp();
};

template<class T1, class T2>
test<T1, T2>::test(T1 X, T2 Y) {
	x = X;
	y = Y;
}

template<class T1, class T2>
void test<T1, T2>::disp() {
	cout<<"\n\nX = "<<x;
	cout<<"\nY = "<<y;
}

int main() {
	test<float, int> obj1(7.8, 3);
	obj1.disp();

	test<char, float> obj2('g', 4.23);
	obj2.disp();
}
