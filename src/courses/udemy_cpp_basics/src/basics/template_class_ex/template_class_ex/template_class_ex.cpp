// template_class_ex.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

template<class T>
class Stack {
private:
    T* stk; // pointer to array
    int top; // top pointer
    int size; // size of stack
public:
    Stack(int sz) {
        size = sz;
        top = -1;
        stk = new int[size];
    }
    void push(T x);
    T pop();

};

template<class T>
void Stack<T>::push(T x) {
    if (top == size - 1) {
        cout << "Stack is Full";
    }
    else {
        top++;
        stk[top] = x;
    }
}

template<class T>
T Stack<T>::pop() {
    int x = 0;
    if (top == -1) {
        cout << "Stack is empty" << endl;
    }
    else {
        x = stk[top];
        top--;
    }
    return x;

}

int main()
{
    std::cout << "Hello World!\n";
    Stack<int> s(10);
    s.push(10);
    s.push(2);
    s.push(33);
}
