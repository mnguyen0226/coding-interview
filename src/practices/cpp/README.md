# 1. Solutions for Print Challenges

### Challenge 1:

```
Write a C++ program to print
*
**
***
****
on screen
```

```c++
#include <iostream>
using namespace std;

int main(){
    cout << "*" << endl;
    cout << "**" << endl;
    cout << "***" << endl;
    cout << "****" << endl;
    return 0;
}
```

### Challenge 2:

Store an integer in a variable x and print it on the screen.

```c++
#include <iostream>
using namespace std;

int main()
{
    int x;
    cout << "Please enter a variable: ";
    cin >> x;
    cout << "Value is: " << x;

    return 0;
}
```

# 2. Solutions for Variables & Literals Challenges

### Challenge 1:

Store two integers in two variable x and y. Print the product of the two.

```c++
#include <iostream>
using namespace std;

int main(){
    int x, y;
    cout << "Please enter two value: ";
    cin >> x >> y;
    cout << "Product is: " << x * y;

    return 0;
}
```

### Challenge 2:

Print the SDCII value of the character 'h'

```c++
#include <iostream>
using namespace std;

int main()
{
    char c = 'h';
    cout << int(c) << endl;

    return 0;
}
```

# 3. Solutions for Operators Challenges

### Challenge 1:

Length and breadth of a rectangle are 5 and 7 respectively. Write a program to calculate the area and perimeter of a rectangle.

```c++
#include <iostream>
using namespace std;

int main()
{
    int l, b;
    cout << "Please enter the length and breadth: ";
    cin >> l >> b;
    cout << "The Area is: " << l * b << endl;
    cout << "The Perimeter is: " << 2 * (l + b) << endl;
    return 0;
}
```

### Challenge 2:

Write a program to calculate the sum of the first and the second last digit of a 5 digit.

```c++
#include <iostream>

using namespace std;

int main()
{
    int num;
    cout << "Please enter a 5-digit number: ";
    cin >> num;

    int first = num / 10000;
    num = num % 10000;

    int second = num / 1000;
    num = num % 1000;

    int third = num / 100;
    num = num % 100;

    int fourth = num / 10;
    int fifth = num % 10;

    int result = first + fourth;
    cout << "The result is: " << result << endl;

    return 0;
}
```

# 4. Solutions for Decide if/else Challenges

### Challenge 1:

Write a program to check if a year is leap year or not. If a year is divisible by 4 then it is a leap year but if the year is a century like 2000, 1900, 2100, then it must be divisible by 400.

```c++
#include <iostream>

using namespace std;

int main()
{
    int year = 0;
    cout << "Please enter a year: ";
    cin >> year;

    if (year % 100 == 0)
    {
        if (year % 400 == 0)
        {
            cout << "The year is leap year." << endl;
        }
        else
        {
            cout << "The year is not leap year." << endl;
        }
    }
    else
    {
        if (year % 4 == 0)
        {
            cout << "The year is leap year." << endl;
        }
        else
        {
            cout << "The year is not leap year." << endl;
        }
    }
    return 0;
}
```

# 5. Solutions for Loops Challenges

### Challenge 1:

A three digit number is called Armstrong number if sum of sube of its digit is equal to number itself

```c++
#include <iostream>

using namespace std;

int main()
{
    for (int i = 100; i <= 500; i++)
    {
        int num = i;

        int first = num / 100;
        num = num % 100;

        int second = num / 10;
        int third = num % 10;

        if (first * first * first + second * second * second + third * third * third == i)
        {
            cout << "Number: " << i << endl;
        }
    }

    return 0;
}
```

### Challenge 2:
Using recursion, define a function to know the nth term of the Fibonacci series.
```c++
#include <iostream>
using namespace std;
int Fib(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    return Fib(n - 1) + Fib(n - 2);
}

int main()
{
    int n;
    cout << "Please enter nth term: ";
    cin >> n;
    cout << "Fibonacci Series Results: " << Fib(n) << endl;

    return 0;
}
```

### Challenege 3: 
Define a function named "perfect" that determines if parameter number is a perfect number. Use this function in a program that determines and prints all the perfect numbers between 1 and 1000.

# 6. Solutions for Functions Challenges

### Challenge 1:

Write a program to print the circumference and area of a circle of radius entered by user by defining your own function.

```c++
#include <iostream>
using namespace std;

double Area(double r)
{
    return 3.14 * r * r;
}

double Circum(double r)
{
    return 3.14 * r * 2;
}

int main()
{
    double r;
    cout << "Please enter your radius: ";
    cin >> r;
    double area = Area(r);
    double circ = Circum(r);

    cout << "The area is: " << area << " circumference: " << circ << endl;
    return 0;
}
```

# 7. Solutions for Pointers Challenges
### Challenge 1:
Write a program to print the address of a variable whose value is input from user.
```c++
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
```

# 8. Solutions for Array Challenges
### Challenge 1: 
Take 10 integer inputs from user and store then in an array and print them on screen.
```c++
#include <iostream>
using namespace std;

int main()
{
    int A[10];

    // input
    for (int i = 0; i < 10; i++)
    {
        cout << "Please enter 10 variables: ";
        cin >> A[i];
    }

    // display
    for (int i = 0; i < 10; i++)
    {
        cout << A[i] << " ";
    }

    return 0;
}
```

# 9. Solutions for String Challenges
### Challenge 1:
Write a program to check if the word 'orange' is present in the "This is orange juice".
```c++
#include <iostream>
#include <cstring>
#include <sstream>
using namespace std;

int main()
{
    string s = "This is orange juice";
    string o = "orange";
    string temp;
    stringstream ss(s);  // parse through a string
    int flag = 0;

    while (ss >> temp)
    { // push the string to string 'o' to check if it is empty, strip down !, ., ?
        if (temp.compare(o) == 0)
        {
            cout << "There is a word orange" << endl;
            flag = 1;
        }
    }
    if (flag == 0)
    {
        cout << "There is no word orange" << endl;
    }

    return 0;
}
```

### Challenge 2: 
Write a program that takes your full name as input and displays the abbreviations of the first and middle names except the last name which is displayed as it is.
```c++
#include <iostream>
#include <cstring>
#include <sstream>
using namespace std;

int main()
{
    string name;
    int count = 0;
    cout << "Please enter your FULL name: ";
    getline(cin, name);
    cout << "Please enter the number of words in your name: ";
    cin >> count;

    string temp; // place holder
    stringstream ss(name);
    while (ss >> temp)
    { // while temp is not null
        if (count != 1)
        {
            cout << temp[0] << ". ";
        }
        else
        {
            cout << temp << endl;
        }
        count--;
    }

    return 0;
}
```

### Challenge 3:
Write a program to delete all consonents from the string "Hello, have a good day."
```c++
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    string s = "Hello, have a good day.";
    string new_s;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != 'u' && s[i] != 'e' && s[i] != 'o' && s[i] != 'a' && s[i] != 'i')
        {
            new_s += s[i];
        }
    }
    cout << new_s << endl;

    return 0;
}
```

### Challenge 4:
Write a program to reverse a string with and without using any predefined function.
```c++
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    string s = "Hello, this is Minh";
    string r_s;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        r_s += s[i];
    }
    cout << r_s << endl;

    return 0;
}
```

### Challenge 5:
Write a program to reverse individual words in a string, where each word may be delimited by a dot, comma, space or tab, like www.google.com should become www.elgoog.moc.
```c++
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
```

# 10. Solutions for Pre-processor Challenges

# 11. Solutions for Structure Challenges

# 12. Solutions for Classes & Objects Challenges

# 13. Solutions for Subclass Challenges

# 14. Solutions for Constructor Overloading Challenges

# 15. Solutions for Array of objects Challenges

# 16. Solutions for Multiple inheritance Challenges
