#include <iostream>
using namespace std;

template <class T>
class CirQueue {
	T* queue;
	int front;
	int rear;
	int cap;

 public:
 	CirQueue(int size) {
 		queue = new T[size];
 		front = 0;
 		rear = 0;

 		cap = size;
 	}

 	bool is_Empty() {
 		return (front == 0) && (rear == 0);
 	}

 	bool is_Full() {
 		return ((front == 0 && rear == cap) || rear == front);
 	}

 	void insert(T x) {
 		if(is_Full()) {
 			cout<<"\nQueue Full! Unable to insert: "<<x;
			return;
 		}

 		rear = (rear == cap)? 0 : rear;  // Wrap Around
 		queue[rear++] = x;
 	}

 	T Delete() {
		if(is_Empty()) {
			cout<<"\nQueue Empty!";
			return (T)32;
		}

		T val = queue[front];

		if(front == rear-1)		// Reset Pointers
			front = rear = 0;
		front = (front == cap-1)? 0 : front+1;  // Wrap Around
		
		return val;
 	}

	void display() {
		if(!is_Empty()) {
			cout<<"["<<queue[front]<<"]";
			for (int i = front+1; i < rear; ++i)
				cout<<" | "<<queue[i];
			
		}
		else
			cout<<"\nQueue Empty!";
	}
};
