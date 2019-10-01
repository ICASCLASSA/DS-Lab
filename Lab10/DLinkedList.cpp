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

    T deleteFirst() {
        if(head == NULL) {
            cout<<"\n\t\t\t List Empty!\n";
            return T(32);
        }

        T data;

        if(head == tail) {
            Node<T> *cur;
            cur = head;
            data = cur->data;

            head = NULL;
            tail = NULL;
            delete cur;
        }
        else {
            Node<T> *cur;
            cur = head;
            data = cur->data;

            head = head->next;
            head->prev=NULL;
            delete cur;
        }

        return data;
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
        cout<<"!!!";
    }

    void insertInBetween(T value, int idx) {
        Node<T> *newNode;
        newNode = new Node<T>(value);

        int i = 0;
        Node<T> *current = head;

        while(current != NULL && i < idx) {
            current = current->next;
            i++;
            cout<<i<<endl;
        }

        if(current != NULL) {
            newNode->next = current;        // Connecting newNode in the DLL
            newNode->prev = current->prev;

            current->prev->next = newNode;  // Securing Two Way Connections
            current->prev = newNode;    
        }
    }

    bool isEmpty() {
        return head==NULL;
    }

    void count() {
        int count = 0;
        Node<T>* current = head;
        while(current != NULL) {
            count++;
            current = current->next;
        }
        cout<<"\n\t\t\t Count: "<<count;
    }

    void search(T val) {
        Node<T>* current = head;
        while(current != NULL) {
            if(current->data == val) {
                cout<<endl<<val<<" Found!";
                return;
            }
            current = current->next;
        }
        cout<<endl<<val<<"Not Found!";
    }

    void reverse() {
        Node<T>* current = tail;
        while(current != NULL) {
            cout<<current->data<<" <-> ";
            current = current->prev;
        }
        cout<<" !!!";
    }

    static DLList& mergeAppend(DLList &d1, DLList &d2) {
        T data;
        
        if(d1.isEmpty())
            return d2;
        else if(d2.isEmpty())
            return d1;
        while(!d2.isEmpty()) {
            data = d2.deleteFirst();
            d1.insertLast(data);
        }

        return d1;
    }

    static DLList& mergeZigZag(DLList& dllist, DLList& dllist_1) {
        T data;

        if(dllist.isEmpty())
            return dllist_1;
        else if(dllist_1.isEmpty())
            return dllist;
        while(!dllist_1.isEmpty()) {
            data = dllist_1.deleteFirst();
            cout<<endl<<data;
            dllist.insertLast(data);
        }
    }
};



int main() {
    char ch;
    char val;
    int idx;
    DLList<char> dllist;
    DLList<char> dllist_1;
    dllist_1.insertFirst('E');
    dllist_1.insertFirst('S');
    dllist_1.insertFirst('O');
    dllist_1.insertFirst('R');
    dllist_1.display();

    while(1) {
        cout << "\033[2J\033[1;1H";  // Internet Code, for Clearing Screen
        cout<<"\n\t\tDoubly Linked List Ops\n";
        dllist.display();
        cout<<"\n\n1. Prepend";
        cout<<"\n2. Append";
        cout<<"\n3. Insert";
        cout<<"\n4. Remove from Head";
        cout<<"\n5. Remove from Tail";
        cout<<"\n6. Show List Item Count";
        cout<<"\n7. Search";
        cout<<"\n8. Reverse";
        cout<<"\n9. Merge Using Append";
        // cout<<"\n9. Merge Using ZigZag";
        cout<<"\nE. Exit\n>>> ";
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
            case '3' : cout<<"\nValue to be Inserted: ";
                       cin>>val;
                       cout<<"\nInsertion Index: ";
                       cin>>idx;
                       dllist.insertInBetween(val, idx);
                       break;
            case '4' : dllist.deleteFirst();
                       break;
            case '5' : dllist.deleteLast();
                       break;
            case '6' : dllist.count();
                       break;
            case '7' : cout<<"\nValue to be Searched: ";
                       cin>>val;
                       dllist.search(val);
                       break;
            case '8' : dllist.reverse();
                       break;
            case '9' : {
                        DLList<char> &mA = DLList<char>::mergeAppend(dllist, dllist_1);
                        cout<<"\n\t";
                        mA.display();
                        break;
                       }
            // case '9' : DLList<char>::mergeZigZag(dllist, dllist_1);
            //            break;
            case 'E' : exit(0);
            default  : cout<<"Invalid Menu Item, Try Again!";
        }
        cout<<"\n\t\t<ENTER ANY KEY TO CONTINUE>";
        cin.ignore();
        cin.get();
    }
}
