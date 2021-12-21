## Note on recursion and time complexity
1. Recursion:
- There are 5 types of recursions:
    - Tail Recursion
        - If the call of func(n-1) is the last of the function, then it is a tail recursion.

        ```
        void func(int n){
            if (n > 0){
                printf("%d", n);
                func(n-1);
                ...
            }
        }
        
        // Equally
        void func(int n){
            while(n > 0){
                printf("%d", n);
                n--;
            }
        }
        ```
        - Time Complexity: O(n)
    - Head Recursion
        - If the call of func(n-1) is at the beginning of the function, then it is a head recursion.
        ```
        void func(int n){
            if (n > 0){
                func(n-1);
                printf("%d", n);
                ...
            }
        }
        
        // Equally same printing format
        void func(int n){
            int i = 1;
            while(i <= n>){
                printf("%d", n);
                i++ ;
            }
        }
        ```
        - Time Complexity: O(n)

    - Tree Recursion
        - If a function calls itself more than one time, then it is a tree recursion.
        ```
        void func(int n){
            if (n > 0){
                func(n-1);
                printf("%d", n);
                func(n-1);
                ...
            }
        }
        ```
        - Time Complexity: O(2^n) = 2^(n+1) - 1 total number of calls.

    - Indirect Recursion
        - If there is two or more functions that call each other back and forth multiple times, then it is indirect recursion
        ``` 
        void funcA(int n){
            if(n > 0){
                printf("%d", n);
                funcB(n-1);
            }
        }

        void funcB(int n){
            if(n > 1){
                printf("%d", n);
                funcA(n/2);
            }
        }
        ```
    - Nested Recursion
        - If the function, when doing recursive call has the parameter is itself, then it is consider nested recursion
        ```
        int func(int n){
            if(n > 100){
                return n - 10;
            }
            else{
                return func(func(n+11));
            }
        }
        ```
- Leet Code:
    - 1 - Find the sum of natural number using recursion.
    - 2 - Find the factorial of a number using recursion.
    - 3 - Find the power/exponential using recursion.
    - 4 - Find the taylor series result using recursion.
    - 5 - Find the Fibonacci series sum using recursion.
    - 6 - Find the Combination formula using recursion.
    - Tower of Hanoi with recursion.