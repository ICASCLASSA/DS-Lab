#include<iostream>

using namespace std;

template<typename T>
T maxT(T a, T b, T c) {
	return (a > b)? ((a > c)? a:c) : ((b > c)? b:c);
}

template<typename T>
T minT(T a, T b, T c) {
	return (a < b)? ((a < c)? a:c) : ((b < c)? b:c);
}

int main() {
	cout<<"\nMax: "<<maxT<int>(2, 6, 3);
	cout<<"\nMin: "<<minT<int>(2, 6, 3);

	cout<<"\n\nMax: "<<maxT<float>(12.32, 23.2, 4.2);
	cout<<"\nMin: "<<minT<float>(12.32, 23.2, 4.2);

	cout<<"\n\nMax: "<<maxT<double>(12.32, 23.2, 4.2);
	cout<<"\nMin: "<<minT<double>(12.32, 23.2, 4.2);
}
