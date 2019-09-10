#include <iostream>

using namespace std;

template <class T>
class Node {
 public:
    T data;
    Node<T> *next;
    
    Node(T n) {
		data = n;
		next = NULL;
	}
};

template <class T>
class LinkedList {
    Node<T> *head;

 public:
    LinkedList() {
        head = NULL;
    }

    void prepend(T n) {
        Node<T>* newhead = new Node<T>(n);
        newhead->next = head;
        head = newhead;

        newhead = NULL;
        delete newhead;
    }



    void Delete() {
        if(head==NULL){
            cout<<"List is empty!"<<endl;
            return;
        }
        cout<<head->data<<" is removed"<<endl;
        Node<T> *temp = head;
        head = head->next;
        delete temp;
    }

    void transversal() {
        Node<T>* current = head;
        while(current != NULL) {
            cout<<current->data<<" -> ";
            current = current->next;
        }
        cout<<" !!!";
    }
};

int main() {
    char ch;
    LinkedList<char> llist;

    while(1) {
        cout << "\033[2J\033[1;1H";  // Internet Code, for Clearing Screen
        cout<<"\n\t\tLinked List Ops\n";
        llist.transversal();
        cout<<"\n\n1. Insert";
        cout<<"\n2. Remove";
        cout<<"\n3. Exit\n>>> ";
        cin>>ch;

        switch(ch) {
            case '1' : char val;
                       cout<<"\nValue to be Inserted: ";
                       cin>>val;
                       llist.prepend(val);
                       break;
            case '2' : llist.Delete();
                       break;
            case '3' : exit(0);
            default  : cout<<"Invalid Menu Item, Try Again!";
        }
        cout<<"\n\t\t<ENTER ANY KEY TO CONTINUE>";
        cin.ignore();
        cin.get();
    }
}
