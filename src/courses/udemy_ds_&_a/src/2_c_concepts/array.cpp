#include<iostream>

using namespace std;

int main(){
    int A[5]; 
    A[0]= 120;
    A[1]=15;
    A[2]= 25;

    // each integer gets 4 bytes so total of 20 bytes
    cout << sizeof(A) << endl;

    return 0;
}