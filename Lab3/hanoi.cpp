#include <iostream>

using namespace std;

int count=0;

template<class T>
void towerOfHanoi(T n, char from_rod, char to_rod, char aux_rod) {
    if (n == 1) {
        cout<<"Move disk 1 from rod "<<from_rod<<" to rod "<<to_rod<<endl;
        ++count;
        return;
    }
    // moving n-1 disks from A to B using C as auxiliary
    towerOfHanoi(n-1, from_rod, aux_rod, to_rod);
    cout<<"Move disk "<<n<<" from rod "<<from_rod<<" to rod "<<to_rod<<endl;
    ++count;

    // moving n-1 disks from B to C using A as auxiliary
    towerOfHanoi(n-1, aux_rod, to_rod, from_rod);
}  
 

int main()
{
    int n = 4; // Number of disks
    towerOfHanoi(n, 'A', 'C', 'B'); // A, B and C are names of rods
    cout<<"\n No. of Moves: "<<count;
    return 0;
}
