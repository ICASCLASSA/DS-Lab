#include <iostream>

using namespace std;

template <class T>
class DLList;

template <class T>
class Node {
    T data;
    Node<T> *prev;
    Node<T> *next;

    friend class DLList<T>;
 public:
 	Node(T x) {
 		data = x;
 		prev = next = NULL;
 	}
};

template <class T>
class DLList {
	Node<T> *head;
    Node<T> *tail;

 public:
 	DLList() {
 		head = tail = NULL;
 	}

    ~DLList() {
        Node<T> *curr;
        while(head) {
            curr = head->next;
            delete head;
            head = curr;
        }
    }

    void insertFirst(T value) {
        Node<T> *newNode;
        newNode = new Node<T>(value);

        if(head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            head->prev = newNode;
            newNode->next = head;
            head = newNode;
        }
    }

    void insertLast(T value) {
        Node<T> *newNode;
        newNode = new Node<T>(value);

        if(tail == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void deleteFirst() {
        if(head == NULL) {
            cout<<"\n\t\t\t List Empty!\n";
            return;
        }

        if(head == tail) {
            Node<T> *cur;
            cur = head;

            head = NULL;
            tail = NULL;
            delete cur;
        }
        else {
            Node<T> *cur;
            cur = head;

            head = head->next;
            head->prev=NULL;
            delete cur;
        }
    }

    void deleteLast() {
        if(head==NULL) {
            cout<<"\n\t\t\t List Empty!\n";
            return;
        }

        if(head == tail) {
            Node<T> *cur;
            cur = head;

            head=NULL;
            tail=NULL;
            delete cur;
        }
        else {
            Node<T> *cur;
            cur = tail;

            tail = tail->prev;
            tail->next = NULL;
            delete cur;
        }
    }

    void display() {
        Node<T>* current = head;
        while(current != NULL) {
            cout<<current->data<<" <-> ";
            current = current->next;
        }
        cout<<" !!!";
    }
};



int main() {
    char ch;
    char val;
    DLList<char> dllist;

    while(1) {
        cout << "\033[2J\033[1;1H";  // Internet Code, for Clearing Screen
        cout<<"\n\t\tDoubly Linked List Ops\n";
        dllist.display();
        cout<<"\n\n1. Prepend";
        cout<<"\n2. Append";
        cout<<"\n3. Remove from Head";
        cout<<"\n4. Remove from Tail";
        cout<<"\n5. Exit\n>>> ";
        cin>>ch;

        switch(ch) {
            case '1' : cout<<"\nValue to be Inserted: ";
                       cin>>val;
                       dllist.insertFirst(val);
                       break;
            case '2' : cout<<"\nValue to be Inserted: ";
                       cin>>val;
                       dllist.insertLast(val);
                       break;
            case '3' : dllist.deleteFirst();
                       break;
            case '4' : dllist.deleteLast();
                       break;
            case '5' : exit(0);
            default  : cout<<"Invalid Menu Item, Try Again!";
        }
        cout<<"\n\t\t<ENTER ANY KEY TO CONTINUE>";
        cin.ignore();
        cin.get();
    }
}
