/*Illustration of Stack stl*/
#include <iostream>
#include <stack>

using namespace std;

/*User Interface*/
int main()
{
    stack<int> mystack;

    mystack.push(1);
    mystack.push(2);
    mystack.push(3);
    mystack.push(4);
    mystack.push(5);

    // check for stack emptyness
    if (mystack.empty())
        cout << "Stack is empty." << endl;
    else
        cout << "Stack is not empty." << endl;

    cout << "Size: " << mystack.size() << endl;
    cout << "Top: " << mystack.top() << endl;

    // add a new element at the top of the stack
    mystack.emplace(1000);
    cout << "Top: " << mystack.top() << endl;

    mystack.pop();
    cout << "Top: " << mystack.top() << endl;

    stack<int> mystack2;
    mystack2.push(11);
    mystack.swap(mystack2);
    cout << "Top: " << mystack2.top() << endl;
    cout << "Top: " << mystack.top() << endl;

    return 0;
}