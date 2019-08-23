#include <iostream>

using namespace std;

template<class T>
T GCD(T n1, T n2) {
    if (n2 != 0)
       return GCD(n2, n1 % n2);

    return n1;
}

int main() {
	int a=10, b=15;
	cout<<"GCD for "<<a<<" & "<<b<<": "<<GCD(b, a);
}
