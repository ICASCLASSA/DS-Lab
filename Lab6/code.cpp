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














========================================================================================================================

#include <iostream>
#include <cstdlib>
#include "cqueue.h"

using namespace std;

int main() {
	char ch;
	CirQueue<char> q(4);

	while(1) {
		cout << "\033[2J\033[1;1H";  // Internet Code, for Clearing Screen
		cout<<"\n\t\tCircular Queue Ops\n";
		q.display();
		cout<<"\n\n1. Insert";
		cout<<"\n2. Remove";
		cout<<"\n3. Exit\n>>> ";
		cin>>ch;

		switch(ch) {
			case '1' : char val;
					   cout<<"\nValue to be Inserted: ";
					   cin>>val;
					   q.insert(val);
					   break;
			case '2' : cout<<"Removed Value: "<<q.Delete();
					   break;
			case '3' : exit(0);
			default  : cout<<"Invalid Menu Item, Try Again!";
		}
		cout<<"\n\t\t<ENTER ANY KEY TO CONTINUE>";
		cin.ignore();
		cin.get();
	}
}

========================================================================================================================

#include <iostream>
#include <cstdlib>
#include "queue.h"

using namespace std;

int main() {
	char ch;
	Queue<char> q(4);

	while(1) {
		cout << "\033[2J\033[1;1H";  // Internet Code, for Clearing Screen
		cout<<"\n\t\tQueue Ops\n";
		q.display();
		cout<<"\n\n1. Insert";
		cout<<"\n2. Remove";
		cout<<"\n3. Exit\n>>> ";
		cin>>ch;

		switch(ch) {
			case '1' : char val;
					   cout<<"\nValue to be Inserted: ";
					   cin>>val;
					   q.insert(val);
					   break;
			case '2' : cout<<"Removed Value: "<<q.Delete();
					   break;
			case '3' : exit(0);
			default  : cout<<"Invalid Menu Item, Try Again!";
		}
		cout<<"\n\t\t<ENTER ANY KEY TO CONTINUE>";
		cin.ignore();
		cin.get();
	}
}

========================================================================================================================


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

========================================================================================================================

#include <iostream>
#include <cstdlib>
#include <string>
#include "queue.h"
#include "stack.h"


int main() 
{
    while ( true )
    {
        std::string letters;
        std::cout << "Please enter a string (Enter - exit): ";
        std::getline( std::cin, letters );

        if ( letters.empty() ) break;

        std::stack<char> 
            s( std::stack<char>::container_type( letters.begin(), letters.end() ) );
        std::queue<char> 
            q( std::queue<char>::container_type( letters.begin(), letters.end() ) );

        while ( !s.empty() && s.top() == q.front() )
        {
            s.pop();
            q.pop();
        }

        if ( s.empty() ) std::cout << "The string is a palindrome" << std::endl;
        else std::cout << "The string is not a palindrome" << std::endl;
    }

    return 0;
}