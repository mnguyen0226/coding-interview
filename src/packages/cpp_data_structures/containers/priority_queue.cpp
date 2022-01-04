/*Illustration of heap stl*/
#include <iostream>
#include <queue>

using namespace std;

int main()
{
    priority_queue<int> mypq;

    // populate the queue
    for (int i = 1; i <= 10; i++)
        mypq.push(i);

    if (mypq.empty())
        cout << "Queue is empty." << endl;
    else
        cout << "Queue is not empty." << endl;

    cout << "Size: " << mypq.size() << endl;
    cout << "Top: " << mypq.top() << endl;

    // although add to back but largest element is on top
    mypq.push(100);
    cout << "Top: " << mypq.top() << endl;

    mypq.emplace(123);
    cout << "Top: " << mypq.top() << endl;

    priority_queue<int> mypq2;
    mypq2.push(456);
    mypq2.push(789);
    mypq.swap(mypq2);
    cout << "Top: " << mypq.top() << endl;
    cout << "Top: " << mypq2.top() << endl;

    return 0;
}