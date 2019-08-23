#include<iostream>

using namespace std;

template<typename T>
void linSearch(T arr[], int len, T var) {
	int i;
	for (i = 0; i < len; ++i)
		if(arr[i] == var)
			break;
	if(i != len)
		cout<<"\nValue "<<var<<" found at index: "<<i;
	else
		cout<<"\nValue "<<var<<" Not Found";
} 


int main()
{
	int iarr[5] = {1, 2, 3, 4, 5};
	float farr[5] = {1.9, 0.3, 3.5, 6.4, 5.2};
	double darr[5] = {0.2, 0.4, 3.2, 6.4, 2.2};

	linSearch(iarr, sizeof(iarr)/sizeof(int), 5);
	
	// linSearch(farr, sizeof(farr)/sizeof(float), 0.3);   Error, as 0.3 is promoted to double when it's passed as arg
	
	linSearch<float>(farr, sizeof(farr)/sizeof(float), 0.3);
	
	linSearch(darr, sizeof(darr)/sizeof(double), 0.5);
}
