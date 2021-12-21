// exception_throw.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

class MyException1 : exception {

};
class MyException2 : MyException1 {

};

int main()
{
    std::cout << "Hello World!\n";
    try {
        throw 1.5;
    }
    catch (MyException2 e) {
        cout << "ME2 Catch" << endl;
    }
    catch (MyException1 e) {
        cout << "ME1 Catch" << endl;
    }
    catch (int e) {
        cout << "Int Catch" << endl;
    }
    catch (double e)
    {
        cout << "Double Catch" << endl;
    }
    catch (...) {
        cout << "Something else, All Catch" << endl;
    }

    return 0;
}

