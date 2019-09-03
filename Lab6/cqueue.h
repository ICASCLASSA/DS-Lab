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
 		front = rear = -1;
 		cap = size;
 	}

 	bool is_Empty() {
 		return front == -1;
 	}

 	bool is_Full() {
 		return ((front == 0 && rear == cap-1) || rear == front-1);
 	}

 	void insert(T x) {
 		if(is_Full()) {
 			cout<<"\nQueue Full! Unable to insert: "<<x;
			return;
 		}
		
		if(front == -1)
			front = rear = 0;
		else if(front != 0 && rear == cap-1)
			rear = 0;
		else
			rear++;
		
 		queue[rear] = x;
 	}

 	T Delete() {
		if(is_Empty()) {
			cout<<"\nQueue Empty!";
			return (T)32;
		}

		T val = queue[front];

		if(front == rear)		// Reset Pointers
			front = rear = -1;
		else if(front == cap-1)
			front = 0;
		else 
			front++;
		
		return val;
 	}

	void display() {
		if(!is_Empty()) {
			if(rear >= front) {
				cout << "[" << queue[front] << "]";
				for (int i = front + 1; i <= rear; ++i)
					cout << " | " << queue[i];
			}
			else {
				cout << "[" << queue[front] << "]";
				for (int i = front + 1; i < cap; ++i)
					cout << " | " << queue[i];

				for (int i = 0; i <= rear; ++i)
					cout << " | " << queue[i];
			}			
		}
		else
			cout<<"\nQueue Empty!";
	}
};