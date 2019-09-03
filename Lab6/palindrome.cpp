#include <iostream>
#include <cstdlib>
#include <string>
#include "queue.h"
#include "stack.h"

using namespace std;

int main() {
    string letters;
    cout<<"Please enter a string (Enter - exit): ";
    getline(cin, letters);

    if (letters.empty()) break;

    stack<char> s(50);
    queue<char> q(50);

    while(!s.is_Empty() && s.Top() == q.Front()) {
        s.pop();
        q.Delete();
    }

    if (s.is_Empty()) cout<<"The string is a palindrome"<<endl;
    else cout<<"The string is not a palindrome"<<endl;

    return 0;
}