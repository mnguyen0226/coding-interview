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

### Challenge 1:

Write a macro to calculate the simple interest from principal, rate of interest and time

```c++
#include <iostream>
#define interest(p, r, t) ((p * r * t) / 100.0)
using namespace std;
int main()
{
    double d = interest(1.0, 2.0, 3.0);
    cout << d << endl;
    return 0;
}
```

# 11. Solutions for Structure Challenges

- Have been done in [C Practice](https://github.com/mnguyen0226/coding-interview-swe-ml/tree/main/src/practices/c).

# 12. Solutions for Classes & Objects Challenges

### Challenge 1:

Create a class named "Student" with a string variable 'name' and an integer variable 'roll_no'. Assign the value of roll_nbo as '2' and that name as "John" by create a object from class student.

```c++
#include <iostream>
#include <cstring>
using namespace std;

class Student
{
public:
    int roll_no;
    string name;
};

int main()
{
    Student s;
    s.name = "John";
    s.roll_no = 2;
    cout << s.name << " " << s.roll_no << endl;

    return 0;
}
```

### Challenge 2:

Assign and print the roll number, phone number, and address of two students having names "Sam" and "John" respectively by creating two objects of the class "Student"

```c++
#include <iostream>
using namespace std;

class Student
{
public:
    int roll_no;
    int phone_no;
    string name;
    string address;
};

int main()
{
    Student s, j;
    s.name = "Sam";
    s.roll_no = 1;
    s.phone_no = 2;
    s.address = "ABC";

    j.name = "John";
    j.roll_no = 1;
    j.phone_no = 2;
    j.address = "ABC";

    cout << s.name << " " << s.roll_no << " " << s.phone_no << " " << s.address << endl;
    cout << j.name << " " << j.roll_no << " " << j.phone_no << " " << j.address << endl;

    return 0;
}
```

### Challenge 3:

Write a program to print the area and perimeter of of a triable having sides of 3 4 5 units by creating a class named "Triangle" with constructor having the three sides as its parameters.

```c++
#include <iostream>
using namespace std;

class Triangle
{
private:
    int a, b, c;

public:
    Triangle()
    {
        a = 3;
        b = 4;
        c = 5;
    }
    Triangle(int a, int b, int c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
    int Area() { return 1; }
    int Peri() { return a + b + c; }
};

int main()
{
    Triangle t;
    cout << t.Area() << " " << t.Peri() << endl;
    Triangle t1(1, 2, 3);
    cout << t1.Area() << " " << t1.Peri() << endl;

    return 0;
}
```

### Challenge 4:

Write a program to print the area of a rectangle by creating a class named "Area" taking a values of its length and breadth as parameters of its constructor and having a function named "returnArea" which returns the area of a rectangle.

```c++
#include <iostream>
using namespace std;

class Rectangle
{
private:
    int length;
    int breadth;

public:
    // default constructor
    Rectangle()
    {
        length = 1;
        breadth = 2;
    };

    // parameterized constructor
    void setDim(int l, int b)
    {
        this->length = l;
        this->breadth = b;
    }

    int getArea()
    {
        return length * breadth;
    }
};

int main()
{
    Rectangle r;
    r.setDim(3, 4);
    cout << r.getArea() << endl;

    return 0;
}
```

### Challenge 5:

Write a program by creating an 'Employee' class having the following functions and print the final salary.

- 1 - 'getInfo()' which takes the salary, number of hours of work per day of employee as parameters
- 2 - 'AddSal()' which adds $10 to the salary of the employee if it is less than $500.
- 3 - 'AddWork()' which adds $5 to the salary of the employee if the number of hours of work per day is more than 6 hours.

```c++
#include <iostream>
using namespace std;

class Employee
{
private:
    int salary;
    int hour;

public:
    Employee()
    {
        salary = 0;
        hour = 0;
    };
    Employee(int s, int h)
    {
        this->salary = s;
        this->hour = h;
    }
    void getInfo(int *s, int *h) // return multiple values
    {
        *s = this->salary;
        *h = this->hour;
    }
    void AddSal()
    {
        if (this->salary < 500)
        {
            this->salary += 10;
        }
    }
    void AddWork()
    {
        if (this->hour > 6)
        {
            this->salary += 5;
        }
    }
};

int main()
{
    Employee e(1, 7);
    int s, h;
    e.getInfo(&s, &h);
    cout << s << " " << h << endl;

    e.AddSal();
    e.AddWork();
    e.getInfo(&s, &h);
    cout << s << " " << h << endl;
}
```

# 13. Solutions for Subclass Challenges

### Challenge 1:

Create a class with a function the prints "This is parent class" and its subclass with another function that prints "this is a child class. Now, create an object for each class and call.

- 1. function of the parent class by the object of the parent class.
- 2. function of the child class by the object of child class.
- 3. function of the parent class by the object of the child class.

```c++
#include <iostream>
using namespace std;

class Parent
{
public:
    Parent(){}; // constructor
    void func1() { cout << "This is a parent class" << endl; }
};

class Child : public Parent
{
public:
    Child(){}; // constructor
    void func2() { cout << "This is a child class" << endl; }
};

int main()
{
    Parent p;
    Child c;
    p.func1();
    c.func2();
    c.func1();

    return 0;
}
```

### Challenge 2:

```
Create a class named 'Member' having the following members:
Data members
1 - Name
2 - Age
3 - Phone number
4 - Address
It also has a function named 'printSalary' which prints the salary of the members.
Two classes 'Employee' and 'Manager' inherits the 'Member' class. The 'Employee' and 'Manager' classes have data members 'specialization' and 'department' respectively. Now, assign name, age, phone number, address and salary to an employee and a manager by making an object of both of these classes and print the same.
```

```c++
#include <iostream>

using namespace std;

class Member
{
public:
    string name;
    int age;
    int phone;
    string address;
    int salary;

    // default constructor
    Member(){};

    // parameterized constructor
    Member(string n, int a, int p, string ad, int s)
    {
        this->name = n;
        this->age = a;
        this->phone = p;
        this->address = ad;
        this->salary = s;
    }

    void printSalary()
    {
        cout << "Salary: " << this->salary << endl;
    }
};

class Employee : public Member
{
private:
    string specialization;
    string department;

public:
    Employee(string n, int a, int p, string ad, int s)
    {
        this->name = n;
        this->age = a;
        this->phone = p;
        this->address = ad;
        this->salary = s;
    };
};

class Manager : public Member
{
private:
    string specialization;
    string department;

public:
    Manager(string n, int a, int p, string ad, int s)
    {
        this->name = n;
        this->age = a;
        this->phone = p;
        this->address = ad;
        this->salary = s;
    };
};

int main()
{
    Employee e("A", 1, 2, "asd", 4);
    Manager m("A", 1, 2, "asd", 5);
    e.printSalary();
    m.printSalary();
    return 0;
}
```

# 14. Solutions for Constructor Overloading Challenges
### Challenge 1:
Write a program to print the names of students by creating a Student class. If no name is passed while creating an object of the Student class, then the name should be "Unknown", otherwise, the name should be equal to the String value passed while creating the object of Student class.
```c++
#include <iostream>

using namespace std;

class Student
{
private:
    string name;

public:
    // default constructor
    Student() { this->name = "Unknown"; }

    // parameterized constructor
    Student(string n)
    {
        this->name = n;
    }

    void print_name()
    {
        cout << "Name: " << this->name << endl;
    }
};

int main()
{
    Student s, s1("ABC");
    s.print_name();
    s1.print_name();

    return 0;
}
```

### Challenge 2:
```
Create a class named 'Rectangle' with two data members- length and breadth and a function to calculate the area which is 'length*breadth'. The class has three constructors which are :
1 - having no parameter - values of both length and breadth are assigned zero.
2 - having two numbers as parameters - the two numbers are assigned as length and breadth respectively.
3 - having one number as parameter - both length and breadth are assigned that number.
Now, create objects of the 'Rectangle' class having none, one and two parameters and print their areas.
```
```c++
#include <iostream>
using namespace std;

class Rectangle
{
private:
    int length;
    int breadth;

public:
    // default constructor
    Rectangle()
    {
        this->length = 0;
        this->breadth = 0;
    }

    // paramtereized constructor
    Rectangle(int l, int b)
    {
        this->length = l;
        this->breadth = b;
    }

    // customed constructor
    Rectangle(int i)
    {
        this->length = i;
        this->breadth = i;
    }

    int Area()
    {
        return this->breadth * this->length;
    }
};

int main()
{
    Rectangle r1, r2(1, 2), r3(1);
    cout << "Rectange 1: " << r1.Area() << endl;
    cout << "Rectange 2: " << r2.Area() << endl;
    cout << "Rectange 3: " << r3.Area() << endl;

    return 0;
}
```

# 15. Solutions for Array of objects Challenges

# 16. Solutions for Multiple inheritance Challenges
