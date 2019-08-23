#include <iostream>

using namespace std;

template<class T>
T fact(T n) {
    if ((n==0)||(n==1))
        return 1;
    return n*fact(n-1);
}

int main() {
   int n = 5;
   cout<<n<<"! = "<<fact(n);
}
