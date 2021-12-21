// Pass by value is helpful if the function is meant to return a result.
// Pass by reference if helpful if the function is void, for small function
// Pass by address if helpful if the function is void, for complicated loop function

#include <iostream>

using namespace std;

// Pass by reference
void swap(int &a, int &b){
    int temp;
    temp = a;
    a = b;
    b = temp;
}

int main(){
    int num1 = 10, num2 = 5;
    
    swap(num1, num2);

    cout << num1 << " " << num2 << endl;

    return 0;
}
