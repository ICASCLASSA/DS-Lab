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
