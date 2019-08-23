#include <iostream>
using namespace std;
 
template<class T>
T fact(T n) {
    if ((n==0)||(n==1))
        return 1;
    return n*fact(n-1);
}
 
template<class T>
T Multiply(T x, T y) {
    if (y == 1)
        return x;
    return x + Multiply(x, y - 1);
}
 
template<class T>
T exponentiate(T m, T n) {
    if(n == 0)
        return 1;
    return m * exponentiate(m, n - 1);
}
 
#include <bits/stdc++.h>
using namespace std;
 
void towerOfHanoi(int n, char from_rod,
                    char to_rod, char aux_rod)
{
    if (n == 1)
    {
        cout << "Move disk 1 from rod " << from_rod <<
                            " to rod " << to_rod<<endl;
        return;
    }
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
    cout << "Move disk " << n << " from rod " << from_rod <<
                                " to rod " << to_rod << endl;
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}  
 
// Driver code
int main()
{
    int n = 4; // Number of disks
    towerOfHanoi(n, 'A', 'C', 'B'); // A, B and C are names of rods
    return 0;
}
 
 
int main() {
   int n = 4;
   cout<<"Factorial of "<<n<<" is "<<fact(n);
}