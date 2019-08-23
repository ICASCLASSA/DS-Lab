#include<iostream>

using namespace std;

template<typename T>
void BubbleSort(T arr[], int n) {
	int i, j;
	for (i = 0; i < n; ++i) {
		for (j = 0; j < n-1-i; ++j) {
			if(arr[j] > arr[j+1]) {
				arr[j] = arr[j] + arr[j+1];
				arr[j+1] = arr[j] - arr[j+1];
				arr[j] = arr[j] - arr[j+1];
			}
		}
	}
}

template<class T>
void printArr(T arr[], int n) {
	cout<<"\n>> ";
	for (int i = 0; i < n; ++i) {
		cout<<arr[i]<<" ";
	}
}




int main()
{
	int iarr[5] = {23, 3, 65, 12, 1};
	float farr[5] = {1.9, 0.3, 3.5, 6.4, 5.2};
	double darr[5] = {0.2, 0.4, 3.2, 6.4, 2.2};

	BubbleSort(iarr, 5);
	BubbleSort(farr, 5);
	BubbleSort(darr, 5);

	printArr(iarr, 5);
	printArr(farr, 5);
	printArr(darr, 5);
}
