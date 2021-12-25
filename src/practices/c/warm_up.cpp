#include <stdio.h>

struct Complex
{
    int real;
    int imaginary;
};

struct Complex add(struct Complex a, struct Complex b)
{
    struct Complex r;
    r.real = a.real + b.real;
    r.imaginary = a.imaginary + b.imaginary;
    return r;
}

struct Complex sub(struct Complex a, struct Complex b)
{
    struct Complex r;
    r.real = a.real - b.real;
    r.imaginary = a.imaginary - b.imaginary;
    return r;
}

struct Complex multi(struct Complex a, struct Complex b)
{
    struct Complex r;
    r.real = a.real * b.real;
    r.imaginary = a.imaginary * b.imaginary;
    return r;
}

int main()
{
    struct Complex a, b, r;
    a = {1, 2};
    b = {2, 3};

    r = add(a, b);
    printf("Add - real: %d, - imaginary: %d\n", r.real, r.imaginary);

    r = sub(a, b);
    printf("Sub - real: %d, - imaginary: %d\n", r.real, r.imaginary);

    r = multi(a, b);
    printf("Multi - real: %d, - imaginary: %d\n", r.real, r.imaginary);

    return 0;
}