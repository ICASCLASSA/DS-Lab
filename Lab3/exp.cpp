#include <iostream>

using namespace std;

template<class T>
T exponentiate(T m, T n) {
    if(n == 0)
        return 1;
    return m * exponentiate(m, n - 1);
}

int main() {
	int m = 2, n = 3;
	cout<<m<<"^"<<n<<" = "<<exponentiate(m, n);
}