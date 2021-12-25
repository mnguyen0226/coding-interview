#include <iostream>
#include <cstring>
#include <sstream>

using namespace std;

int main()
{
    string s = "www.google.com";
    stringstream ss(s);
    string temp;
    int counter = 0;
    while (getline(ss, temp, '.')) // stream a string, put in a temp string cut out by delimiter
    {
        for (int i = temp.size() - 1; i >= 0; i--)
        {
            cout << temp[i];
        }
        counter++;
        if (counter < 3)
        {
            cout << '.';
        }
    }
    return 0;
}