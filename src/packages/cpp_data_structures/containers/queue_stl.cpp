/*Illustration for queue stl*/

#include <iostream>
#include <queue>

using namespace std;

int main()
{
    queue<int> myq;
    // push in the back
    myq.push(1);
    myq.push(2);
    myq.push(3);
    myq.push(100);

    if (myq.empty())
        cout << "Queue is empty." << endl;
    else
        cout << "Queue is not empty." << endl;

    cout << "Size: " << myq.size() << endl;
    cout << "Front: " << myq.front() << endl;
    cout << "Back: " << myq.back() << endl;

    myq.emplace(111);
    cout << "Back: " << myq.back() << endl;

    myq.pop();
    cout << "Front: " << myq.front() << endl;

    queue<int> myq2;
    myq2.push(123);
    myq2.push(456);
    myq.swap(myq2);
    cout << "Front: " << myq.front() << endl;
    cout << "Front: " << myq2.front() << endl;

    return 0;
}