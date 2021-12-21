// Represent Polynomial in array

#include <stdio.h>
#include <stdlib.h>

struct Term
{
    int coeff;
    int exp;
};

struct Poly
{
    int n;
    struct Term *terms; // array of terms but not sure number of elements
    // array create d in the heap
};

void Create(struct Poly *p)
{
    printf("Number of terms?");
    scanf("%d", &p->n); // for float, char, int, you must have & for scanf, for string, no need of &
    p->terms = (struct Term *)malloc(p->n * sizeof(struct Term));

    printf("Enter terms coefficient and exponential \n");
    for (int i = 0; i < p->n; i++)
    {
        scanf("%d%d", &p->terms[i].coeff, &p->terms[i].exp);
    }
}

void Display(struct Poly p)
{
    for (int i = 0; i < p.n; i++)
    {
        printf("%dx%d + ", p.terms[i].coeff, p.terms[i].exp);
    }
}

struct Poly *Add(struct Poly *p1, struct Poly *p2)
{
    int i, j, k;
    struct Poly *sum = (struct Poly *)malloc(sizeof(struct Poly));

    // create array with size of sum of two array polynomial
    sum->terms = (struct Term *)malloc((p1->n + p2->n) * sizeof(struct Term));
    i = j = k = 0;
    while (i < p1->n && j < p2->n)
    {
        if (p1->terms[i].exp > p2->terms[j].exp)
        {
            // Copy the whole term including coefficient and expo
            sum->terms[k++] = p1->terms[i++];
        }
        else if (p1->terms[i].exp < p2->terms[j].exp)
        {
            // Copy the whole term including coefficient and expo
            sum->terms[k++] = p1->terms[j++];
        }
        else
        {
            sum->terms[k].exp = p1->terms[i].exp + p2->terms[j].exp;
            sum->terms[k++].coeff = p1->terms[i++].coeff + p2->terms[j++].coeff;
        }
    }
    // Copy the rest of the array to the sum array
    for (; i < p1->n; i++)
    {
        sum->terms[k++] = p1->terms[i];
    }
    for (; j < p1->n; j++)
    {
        sum->terms[k++] = p2->terms[j];
    }
    sum->n = k; // reset the number of terms in the array
    return sum;
}

int main()
{
    struct Poly p1, p2, *p3;
    Create(&p1);
    Create(&p2);
    p3 = Add(&p1, &p2);

    printf("\n");
    Display(p1);
    printf("\n");
    Display(p2);
    printf("\n");
    Display(*p3);

    return 0;
}