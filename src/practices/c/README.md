# 1. Solutions to Print challenges

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

# 2. Solutions to Data-Type Challenge
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

### Challenge 6:


