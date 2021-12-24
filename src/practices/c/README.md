# 1. Solutions for Print Challenges

### Challenge 1: 
```
Write a C program to print
*
**
***
****
on screen.
```
```c++
#include <stdio.h>

int main(){
    printf("*\n");
    printf("* *\n");
    printf("* * *\n");
    printf("* * * *\n");

    return 0;
}
```

### Challenge 2:
Store two integers in two variables x and y. Print the sum of the two.
```c++
#include <stdio.h>
int main(){
    int x = 1;
    int y = 2;
    printf("Sum is %d", x + y);

    return 0;
}
```

### Challenge 3:
Store two integers in two variables x and y. Print the product of the two.
```c++
#include <stdio.h>
int main(){
    int x = 1;
    int y = 2;
    printf("Product is %d", x * y);

    return 0;
}
```

### Challenge 4:
```
Print the following pattern on the screen
****
 ** 
  *  
 ** 
****
```
```c++
#include <stdio.h>
int main(){
    printf("****\n");
    printf(" ** \n");
    printf("  *\n");
    printf("****\n");
    return 0; 
}
```

### Challenge 5:
Write a C program to take two integers inputs from users and print the sum and priduct of them
```c++
#include <stdio.h>
int main(){
    int x; 
    int y;
    printf("Please enter two values:");
    scanf("%d", &x);
    scanf("%d", &y);
    printf("The sum is %d, the product is %d\n", x + y, x*y);
    return 0;
}
```

# 2. Solutions for Data-Type Challenges
### Challenge 1:
Write a C program to take an int, a float, and a char input from user and print them on the screen.

```c++
#include <stdio.h>
int main()
{
    int x;
    float y;
    char c;
    printf("Please enter an int, float, and char in that order:");
    scanf("%d", &x);
    scanf("%f", &y);
    scanf(" %c", &c); // notify scan a char after a whitespace
    printf("Int: %d; Float: %f; Char: %c\n", x, y, c);
    return 0;
}
```

### Challenge 2:
Take the values of length and breath of a rectangle from a user and print the area of it.
```c++
#include <stdio.h>
int main()
{
    int length;
    int breadth;
    printf("Please enter length and breadth: ");
    scanf("%d", &length);
    scanf("%d", &breadth);
    printf("The area is: %d", length*breadth);

    return 0;
}
```

### Challenge 3:
Take a char input from user and print it's ASCII value

```c++
#include <stdio.h>
int main()
{
    char c;
    printf("Please input a char value: ");
    scanf("%c", &c);
    printf("The ASCII value is: %d", c);
    return 0;
}
```

### Challenge 4:
Take a float input from the uder and type case it to and int and print it on the screen.
```c++
#include <stdio.h>
int main()
{
    float f;
    printf("Please enter the float value: ");
    scanf("%f", &f);
    printf("The value is %d\n", (int)f);
    int i = (int)f;
    printf("The value is %d\n", i);
    return 0;
}
```

### Challenge 5:
Take value of length and breadth of a rectangle from the user as float. Find its area and print it on the screen after type casting it to int.
```c++
#include <stdio.h>
int main()
{
    float length;
    float breadth;
    printf("Please enter the length and breadth int float: ");
    scanf("%f", &length);
    scanf("%f", &breadth);
    int area = (int)length * (int)breadth;
    printf("The area is %d", area);
    return 0;
}
```

# 3. Solutions for Operators Challenges
### Challenge 1:
```c++
#include <stdio.h>
int main()
{
    int a = 15;

    // printf("%d\n", ++a); // increment then print => 16
    printf("%d\n", a++); // print then increment => 15

    return 0;
}
```

### Challenge 2:
The total number of students in a class are 45 or out which 25 are boys. If 80% of the total student secured grade A out of which 15 are boys, then write a program to calculate the total number of girls getting A.
```c++
#include <stdio.h>
int main()
{
    int total = 45;
    int boys = 25;
    int girls = total - boys;
    int total_A = 45 * 0.8;
    int total_boys_A = 15;
    int total_girls_A = total_A - total_boys_A;

    printf("%d\n", total_girls_A);

    return 0;
}
```

### Challenge 3:
Write a program to calculate the sum of the first and the second last digit of a 5 digit number entered from the keyboard.
```c++
#include <stdio.h>
int main()
{
    int d;
    printf("Please enter a 5 digits number: ");
    scanf("%d", &d);

    int first = d / 10000;
    d = d % 10000;

    int second = d / 1000;
    d = d % 1000;

    int third = d / 100;
    d = d % 100;

    int fourth = d / 10;
    int fifth = d % 10;

    int sum = first + fourth;
    printf("Sum is: %d", sum);

    return 0;
}
```

### Challenge 4:
Supose you entered a 4 digit number. Write a program to display a number whose digits are 2 greater than the corresponding digits of the entered number
```c++
#include <stdio.h>
int main()
{
    int d;
    int final = 0;
    printf("Please enter a 4 digits number: ");
    scanf("%d", &d);

    int first = d / 1000; // get the number at the first position
    first += 2; // increment by 2
    first = first % 10; // in case that value is more than 10 then we interested in the last value only
    first *= 1000; 
    final += first; // add to the final value
    d = d % 1000; // get the mod of the rest of 3 values

    int second = d / 100;
    second += 2;
    second = second % 10;
    second *= 100;
    final += second;
    d = d % 100;

    int third = d / 10;
    third += 2;
    third = third % 10;
    third *= 10;
    final += third;

    int fourth = d % 10;
    fourth += 2;
    fourth = fourth % 10;
    final += fourth;

    printf("Final is: %d\n", final);

    return 0;
}
```

### Challenge 5:
Write a program to calculate the sum of the digits of a 3-digit number which is entered from the keyboard.
```c++
#include <stdio.h>
int main()
{
    int d;
    int sum = 0;
    printf("Please enter a 3 digits number: ");
    scanf("%d", &d);

    int first = d / 100;
    d = d % 100;

    int second = d / 10;
    int third = d % 10;

    sum = first + second + third;

    printf("Sum is: %d\n", sum);

    return 0;
}
```

### Challenge 6:
Write a program to reverse a 3-digit number which is entered from keyboard.
```c++
#include <stdio.h>
int main()
{
    int d;
    int final = 0;
    printf("Please enter a 3 digits number: ");
    scanf("%d", &d);

    int first = d / 100;
    d = d % 100;

    int second = d / 10;
    int third = d % 10;

    final = third * 100 + second * 10 + first;

    printf("Reversed number is: %d\n", final);

    return 0;
}
```

# 4. Solutions for Decide If/Else Challenges
### Challenge 1:
Take values of length and breadth of a rectangle from user and check if it is square or not
```c++
#include <stdio.h>
int main()
{
    int length, breadth;
    printf("Please enter the length and breadth values: ");
    scanf("%d", &length);
    scanf("%d", &breadth);
    if (length == breadth)
    {
        printf("The rectangle is square.");
    }
    else
    {
        printf("The rectangle is NOT square.");
    }

    return 0;
}
```

### Challenge 2:
Take two int values from user and print greatest among them
```c++
#include <stdio.h>
int main()
{
    int x, y;
    printf("Please enter two int values: ");
    scanf("%d", &x);
    scanf("%d", &y);
    if (x > y)
    {
        printf("Larger number is: %d", x);
    }
    else
    {
        printf("Larger number is: %d", y);
    }

    return 0;
}
```

### Challenge 3:
A shop will give discount of 10% if the cost of purchased quantity is more than 1000.
Ask user for quantity
Suppose, one unit will cost 100.
Judge and print total cost for user.
```c++
#include <stdio.h>
int main()
{
    int quantity = 0;
    printf("Please enter the quantity: ");
    scanf("%d", &quantity);
    if (100 * quantity > 1000)
    {
        printf("Cost is: %f", 100 * (float)quantity * 0.9);
    }
    else
    {
        printf("Cost is: %d", 100 * quantity);
    }

    return 0;
}
```

### Challenge 4:
A company decided to give bonus of 5% to employee if his/her year of service is more than 5 years. Ask user for their salary and year of service and print the net bonus amount.
```c++
#include <stdio.h>
int main()
{
    int year = 0;
    int salary = 0;
    printf("Please enter the number of years of service: ");
    scanf("%d", &year);
    printf("Please enter the current salary: ");
    scanf("%d", &salary);
    if (year > 5)
    {
        printf("Net bonus amount: %f", (float)salary * 1.05);
    }
    else
    {
        printf("Net bonus amount: %f", (float)salary);
    }

    return 0;
}
```

### Challenge 5:
Write a C program to check if a year is a leap year or not. If a year is divisible by 4 then it is a leap year, but if the year is century year like 2000, 1900, 2100 then it must be divisible by 400
```c++
#include <stdio.h>
int main()
{
    int year = -1;
    while (year < 0)
    { // keep asking till getting the positive year
        printf("Please enter the non-negative year: ");
        scanf("%d", &year);
    }
    if (year % 100 == 0)
    { // if it is a century year
        if (year % 400 == 0)
        {
            printf("This is leap year.");
        }
        else
        {
            printf("This is not leap year");
        }
    }
    else // not a century year
    {
        if (year % 4 == 0)
        {
            printf("This is leap year.");
        }
        else
        {
            printf("This is not leap year");
        }
    }

    return 0;
}
```

### Challenge 5:
A 4 digit number is entered through keyboard. Write a C program to print a new number with digits reversed as of original one.
```c++
#include <stdio.h>
int main()
{
    int num = 0;
    int final;
    printf("Please enter a 4 digits number: ");
    scanf("%d", &num);

    int first = num / 1000;
    num = num % 1000;

    int second = num / 100;
    num = num % 100;

    int third = num / 10;
    int fourth = num % 10;

    final = fourth * 1000 + third * 100 + second * 10 + first;
    printf("Final is % d", final);
    
    return 0;
}
```

### Challenge 6: 
Write a C program to check whether an entered character is lowercase of uppercase.
```c++
#include <stdio.h>
int main()
{
    char c;
    printf("Please enter a character: ");
    scanf("%c", &c);
    if (c >= 65 && c <= 90)
    {
        printf("Uppercase");
    }
    else
    {
        printf("Lowercase");
    }

    return 0;
}
```

# 5. Solutions for Loop Challenges
### Challenge 1:
This will print infinitely
```c++
#include <stdio.h>
int main(){
    for(int i = 0;1;i++){
        printf("%d\n",i);
    }
    return 0;
}
```

### Challenge 2: 
This will print z: 12 (0 3 6 9 12)
```c++
#include <stdio.h>
int main( )
{
    int x = 10, y = 3, z;
    for(z = 0; z<x; )
    z = z++ +y; // execute this line in loop
    printf("%d\n", z) ;
    return 0;
}
```

### Challenge 3: 
```
Print the following patterns using loop :
a.
*
**
***
****
```
```c++
#include <stdio.h>
int main()
{
    for (int i = 0; i < 4; i++) //row
    {
        for (int j = 0; j < 4; j++) //col 
        {
            if (j <= i)
            {
                printf("* ");
            }
        }
        printf("\n");
    }

    return 0;
}
```

### Challenge 4: 
Write a C program to calculate factorial of a number.
```c++
#include <stdio.h>
int main()
{
    int num = 0;
    printf("Please enter a number: ");
    scanf("%d",&num);
    int result = 1;
    for(int i = 1; i <= num; i++){
        result *= i;
    }

    printf("Factorial: %d", result);
    return 0;
}
```

### Challenge 5:
Write a C program to find the GCD and LCM of the given two number.
```c++
#include <stdio.h>
int main()
{
    int x, y, count = 1, small;
    int gcd, lcm;
    printf("Please enter the two values: ");
    scanf("%d", &x);
    scanf("%d", &y);

    small = (x < y) ? x : y; // if x < y, then return x

    while (count <= small)
    {
        if (x % count == 0 && y % count == 0)
        {
            gcd = count; // keep replacing this till find the gcd
        }
        count++;
    }
    // note that lcm = (num 1 * num 2) / gcd

    lcm = (x * y) / gcd;

    printf("LCM is: %d; GCD is: %d", lcm, gcd);
    return 0;
}
```

### Challenge 6:
A three digit number is called Armstrong number if sum of sube of its digit is equal to number itself. For instance 153 is arm strong number because 1^3 + 5^3 + 3^3 = 153. Write all arm strong numbers between 100 to 500.

```c++
int main()
{
    for (int i = 100; i <= 500; i++)
    {
        int num = i;
        int first = num / 100;
        num = num % 100;

        int second = num / 10;
        int third = num % 10;
        if (i == (first * first * first + second * second * second + third * third * third))
        {
            printf("Number: %d\n", i);
        }
    }
    return 0;
}
```

# 6. Solutions for Functions Challenges

### Challenge 1:
Write a function to calculate area and perimeter of a rectangle.
```c++
#include <stdio.h>
void calculate(int a, int b)
{
    printf("Perimeter: %d, Area: %d", (a + b) * 2, a * b);
}

int main(){
    calculate(1, 2);
    return 0;
}
```

### Challenge 2:
Write a function to calculate the fibonacci series.
```c++
#include <stdio.h>

int fibonacci(int n){
    if(n == 0){
        return 0;
    }
    else if(n == 1){
        return 1;
    }
    return fibonacci(n-1) + fibonacci(n-2);
}

int main(){
    printf("Fibonacci: %d", fibonacci(4));
    return 0;
}
```

# 7. Solutions for Pointer Challenges
### Challenge 1:
Write a program to print the value of the address of the pointer to a variable whose value is input from user.
```c++
#include <stdio.h>

int main(){
    int num;
    printf("Please enter a value: ");
    scanf("%d", &num);
    int* i = &num; // pointer points to address of the number
    printf("Address is: %u", &i);
    return 0;
}
```

### Challenge 2:
Write a program to print a number which is entered from keyboard using pointer.
```c++
#include <stdio.h>

int main(){
    int num, *p;
    printf("Please enter a number: ");
    scanf("%d", &num);
    p = &num;
    printf("Number: %d", *p);

    return 0;
}
```

# 8. Solutions for Array Challenges
### Challenge 1:
Take 10 integer inputs from user and store themn in an array and print them on screen.
```c++
#include <stdio.h>
int main(){
    int A[10];
    int count = 0;
    int num;
    while(count < 10){
        printf("Enter a number: ");
        scanf("%d", &num);
        A[count] = num; 
        count++;
    }

    for(int i = 0; i < 10; i++){ // print all values
        printf("%d ", A[i]);
    }

    return 0;
}
```

### Challenge 2:
Take 10 integer inputs from user and store them in an array. Then copy all element in another array in reverse order.
```c++
#include <stdio.h>

int main(){
    int num;
    int A[10];
    int rA[10];
    for(int i = 0; i < 10; i++){
        printf("Enter a number: ");
        scanf("%d", &num);
        A[i] = num;
        rA[9-i] = num;
    }

    for(int i = 0; i < 10; i++){
        printf("%d ", rA[i]);
    }

    return 0;
}
```

### Challenge 3:
Find the largest and smallest elements of an array.
```c++
#include <stdio.h>

int main()
{
    int A[] = {1, 2, 3, 5, 100, -100, 233, 8};
    int smallest = 100000;
    int largest = -100000;
    int len = sizeof(A) / sizeof(A[0]);
    for (int i = 0; i < len; i++)
    {
        if (smallest > A[i])
        {
            smallest = A[i];
        }
        if (largest < A[i])
        {
            largest = A[i];
        }
    }
    printf("Len: %d, Smallest: %d, Largest: %d", len, smallest, largest);

    return 0;
}
```

# 9. Solutions for Strings Challenges
### Challenge 1:
Write a program to print a string entered by user.
```c++
#include <stdio.h>
int main(){
    char name[25];
    printf("Please enter your name less than 25 char, no space: ");
    scanf("%s", &name);
    printf("Name is: %s", name);
    return 0;
}
```

### Challenge 2:
Write a program to find the length of the string "refrigerator".
```c++
#include<stdio.h>

int main(){
    char c[] = "refrigerator";
    int len = sizeof(c) / sizeof(c[0]);
    printf("Len is: %d", len);

    return 0;
}
```

### Challenge 3:
Write a program to enter a string s1 and copy it to another string s2.
```c++
#include <stdio.h>
#include <string.h>

int main()
{
    char c[] = "Hello Minh";
    char t[100];
    strcpy(t, c);
    printf("String: %s", t);
    return 0;
}
```

### Challenge 4:
Write a program to compare if two strings entered by user are equal or not without using the predefined string functions.
```c++
#include <stdio.h>
int main()
{
    char s[] = "minh nguyen";
    char t[] = "minh nguyen";

    for (int i = 0; i < sizeof(t) / sizeof(t[0]); i++)
    {
        if (s[i] > t[i])
        {
            printf("s > t\n");
            break;
        }
        else if (s[i] < t[i])
        {
            printf("s < t\n");
            break;
        }
        else if(s[i] == t[i] && i == sizeof(t) / sizeof(t[0]) - 1){
            printf("s == t\n");
        }
        continue;
    }

    return 0;
}
```

### Challenge 5:
Write a program to check if the word 'orange' is present in the sentence "This is orange juice".
```c++
#include <stdio.h>
#include <string.h>

int main()
{
    char c[] = "orange";
    char s[] = "This is orange juice";
    int flag = 0;
    // get the first token
    char *pch = strtok(s, " "); // breaks string str into a series of tokens using the delimiter delim.
    while (pch != NULL)
    {
        if (strcmp(pch, c) == 0)
        {
            printf("There is an orange");
            flag = 1;
        }
        pch = strtok(NULL, " "); // standard
    }
    if (flag == 0)
    {
        printf("There is no orange");
    }

    return 0;
}
```

### Challenge 6:
Write a program that takes your full name as input and displays the abbreviations of the first and the middle names except the last name which is displayed as it is. For example, if you name is Minh Tran Binh Nguyen, then the output should be M. T. B. Nguyen.
```c++
#include <stdio.h>
#include <string.h>

int main()
{
    char name[] = "Nguyen Tran Binh Minh";
    int num_letter = 4;
    int count = 1;

    // parse through the string, find the last element.
    char *pch = strtok(name, " "); // get the first token
    while (pch != NULL)
    {
        if (count == 4)
        {
            printf("%s ", pch);
        }
        else{
            printf("%c. ", pch[0]);
        }
        pch = strtok(NULL, " ");
        count++;
    }

    return 0;
}
```

# 10. Solutions for Pre-processor Challenges


# 11. Solutions for Structure Challenges