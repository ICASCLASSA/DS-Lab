#include <iostream>
using namespace std;

template <class T>
class Queue {
	T* queue;
	int front;
	int rear;
	int cap;

 public:
 	Queue(int size) {
 		queue = new T[size];
 		front = 0;
 		rear = 0;

 		cap = size;
 	}

 	bool is_Empty() {
 		return (front == rear);
 	}

 	bool is_Full() {
 		return (rear == cap);
 	}

 	void insert(T x) {
 		if(is_Full()) {
 			cout<<"\nQueue Full! Unable to insert: "<<x;
			return;
 		}
 		queue[rear++] = x;
 	}

 	T Delete() {
		if(is_Empty()) {
			cout<<"\nQueue Empty!";
			return (T)32;
		}
		return queue[front++];
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