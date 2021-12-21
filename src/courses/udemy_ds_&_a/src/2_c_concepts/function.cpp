// Pass by value, address, and reference

#include <iostream>

using namespace std;

int add(int a, int b){
    int c = a+b;
    return c;
}

int main(){
    int num1 = 10, num2 = 5, sum;
    
    sum = add(num1, num2);

    cout << sum << endl;

    return 0;
}


