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

# 6. Solutions for Functions Challenges

# 7. Solutions for Pointers Challenges

# 8. Solutions for Array Challenges

# 9. Solutions for String Challenges

# 10. Solutions for Pre-processor Challenges

# 11. Solutions for Structure Challenges

# 12. Solutions for Classes & Objects Challenges

# 13. Solutions for Subclass Challenges

# 14. Solutions for Constructor Overloading Challenges

# 15. Solutions for Array of objects Challenges

# 16. Solutions for Multiple inheritance Challenges
