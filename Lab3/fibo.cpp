#include <iostream>

using namespace std;

template<class T>
void fibo(T limit, T first = 0, T second = 1) {
	if(first == 0)
		cout<<" "<<first<<" "<<second;
	if(first+second > limit)
		return;
	cout<<" "<<first+second;
	fibo(limit, second, first+second);
}


int main() {
	fibo(30);
}
