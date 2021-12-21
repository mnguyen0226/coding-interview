// Code for sparse matrix representative in C

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

struct Element
{
    int row_pos; // row
    int col_pos; // col
    int value;
};

struct Sparse
{
    int num_row;
    int num_col;
    int num_values;    // number of non-zeros elements
    struct Element *e; // create a dynamic array of elements of non-zero elements
};

void Create(struct Sparse *S)
{
    printf("Enter Dimension of the Sparse Matrix including number of rows and columns: \n");
    scanf("%d %d", &S->num_row, &S->num_col);

    printf("Enter number of non-zero element.\n");
    scanf("%d", &S->num_values);

    // S->e = new Element[S->num_values];
    S->e = (struct Element *)malloc((S->num_values) * sizeof(struct Element));

    printf("Enter All Element: ");
    for (int i = 0; i < S->num_values; i++)
    {
        scanf("%d %d %d", &S->e[i].row_pos, &S->e[i].col_pos, &S->e[i].value);
    }
}

void Display(struct Sparse S)
{
    int i, j, k = 0;
    for (i = 0; i < S.num_row; i++)
    {
        for (j = 0; j < S.num_col; j++)
        {
            if (i == S.e[k].row_pos && j == S.e[k].col_pos)
            {
                printf("%d ", S.e[k++].value);
            }
            else
            {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

// Sparse add(Sparse *S1, Sparse *S2)
// {
//     Sparse *SUM = new Sparse;

//     if(S1->num_row != S2->num_row || S1->num_col != S2->num_col){
//         // Not able to add if either number of rows or cols of each of them is not equal
//         return 0; 
//     }

// }

int main()
{
    struct Sparse S;
    Create(&S);
    Display(S);
    return 0;
}