#include<iostream>
using namespace std;
int main(){
    cout << "Please enter a variable: ";
    int num, *p;
    p = &num; // pointer points to the address of a variable
    cin >> num;
    cout << "Address is: " << p;

    return 0;
}