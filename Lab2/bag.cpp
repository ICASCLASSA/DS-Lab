#include <iostream>
#include <string>

using namespace std;

template<class T>
class bag {
	T arr[50];
	int size;
	int count;

 public:
	bag(int n) {
		size = n;
		count = 0;
	}
	
	void disp() {
		cout<<"\tBAG > ";
		for (int i = 0; i < count; ++i)
			cout<<arr[i]<<"  ";
	}

	void insert() {
		if(count == size) {
			cout<<"\nOVERFLOW ENCOUNTERED: Remove an item!";
			remove();
		}

		cout<<"\nEnter item into bag: ";
		cin>>arr[count++];
	}

	void remove() {
		T item;
		cout<<"\nEnter Item to be removed: ";
		cin>>item;

		for (int i = 0; i < count; ++i) {
			 if(item == arr[i]) {
			 	for (int j = i; j < count; ++j) {
			 		arr[j] = arr[j+1];
			 	}
			 	count--;
			 }
		}
	}
};


int main() {
	bag<string> names(4);
	for (int i = 0; i < 5; ++i) {
		names.insert();
		names.disp();
	}
	names.remove();
	names.disp();
}
