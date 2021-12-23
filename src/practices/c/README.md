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


# 5. Solutions for Loop Challenges


# 6. Solutions for Functions Challenges


# 7. Solutions for Pointer Challenges


# 8. Solutions for Array Challenges


# 9. Solutions for Strings Challenges


# 10. Solutions for Pre-processor Challenges


# 11. Solutions for Structure Challenges