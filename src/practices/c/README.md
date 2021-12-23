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