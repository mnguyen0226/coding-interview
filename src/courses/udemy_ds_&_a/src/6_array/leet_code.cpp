// Find single missing element in the array

#include <stdio.h>

struct Array
{
    int A[10]; // A[] for the other main example
    int size;
    int length; // length <= size
};

// Function finds the missing element in the sorted consecutive array
void missing_e_sorted(Array arr, int arr_len, int last_num)
{
    int sum = 0;
    for (int i = 0; i < arr_len; i++)
    {
        sum = sum + arr.A[i];
    }

    // Sum of the first 12 number
    int s = last_num * (last_num + 1) / 2;
    printf("Missing number is %d\n", s - sum);
}

// Function finds the missing element in the sorted consecutive, not starting at 1 array
void missing_e_sorted2(Array arr, int arr_len)
{
    int difference = arr.A[0];
    for (int i = 0; i < arr.length; i++)
    {
        if (arr.A[i] - i != difference)
        {
            printf("Missing number is %d\n", arr.A[i] - 1);
            break;
        }
    }
}

// Function finds the missing element in the sorted consecutive, not starting at 1 array
void missing_multi_sorted(Array arr, int arr_len)
{
    int difference = arr.A[0];
    for (int i = 0; i < arr.length; i++)
    {
        if (arr.A[i] - i != difference)
        {
            while (difference < arr.A[i] - i)
            {
                printf("Missing number is %d\n", i + difference);
                difference++;
            }
        }
    }
}

// Function finds the missing element in the sorted consecutive, not starting at 1 array
void missing_multi_unsorted(Array arr, int arr_len)
{
    Array arr2 = {{}, 0, arr_len};
    // fill 0 in the array
    for (int i = 0; i < arr_len; i++)
    {
        arr2.A[i] = 0;
    }

    for (int j = 0; j < arr_len; j++)
    {
        arr2.A[arr.A[j]] = 1;
    }

    int difference = 1;
    for (int i = 0; i < arr2.length; i++)
    {
        if (arr2.A[i] == 0)
        {
            printf("Missing number is %d\n", i);
        }
    }
}

// Find a pair of elements with sum K in a unique array
void SumPair(Array arr, int arr_len, int sum)
{
    int counter = 0;
    for (int i = 0; i < arr_len - 1; i++)
    {
        for (int j = i + 1; j < arr_len; j++)
        {
            if (arr.A[i] + arr.A[j] == sum)
            {
                printf("The pair is (%d, %d).\n", i, j);
                counter++;
            }
        }
    }
    if (counter == 0)
    {
        printf("There is no such pair in the array with the sum %d", &sum);
    }
}

// Find a pair of elements with sum K in a unique array
void SumPairHash(Array arr, int arr_len, int sum)
{
    int hash_len = arr_len * 3;

    Array hash_arr = {{}, 0, hash_len};

    // fill 0 in the array
    for (int i = 0; i < hash_len; i++)
    {
        hash_arr.A[i] = 0;
    }

    for (int i = 0; i < arr_len; i++)
    {
        if (hash_arr.A[sum - arr.A[i]] != 0 && sum - arr.A[i] > 0)
        {
            printf("The pair is (%d, %d).\n", arr.A[i], sum - arr.A[i]);
        }
        hash_arr.A[arr.A[i]]++;
    }
}

// Find a pair of elements with sum K in a unique, sorted array
void SumPairSorted(Array arr, int arr_len, int sum)
{
    int i = 0;
    int j = arr_len - 1;
    while (i < j)
    {
        if (arr.A[i] + arr.A[j] == sum)
        {
            printf("The pair is (%d, %d).\n", arr.A[i], arr.A[j]);
            i++;
            j--;
        }
        else if (arr.A[i] + arr.A[j] < sum)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
}

int main()
{
    Array arr = {{1, 2, 3, 5}, 4, 10};
    missing_e_sorted(arr, arr.length, 5);
    printf("\n");

    Array arr2 = {{5, 6, 7, 8, 10, 12}, 6, 10};
    missing_e_sorted2(arr2, 6);
    printf("\n");

    Array arr3 = {{5, 6, 7, 8, 10, 12}, 6, 10};
    missing_multi_sorted(arr3, 6);
    printf("\n");

    Array arr4 = {{1, 3, 5, 12, 2, 8, 6, 0}, 8, 10};
    missing_multi_unsorted(arr4, 8);

    printf("\n");

    Array arr5 = {{6, 3, 8, 10, 16, 7, 5, 2, 9, 14}, 10, 20};
    SumPair(arr5, 10, 10);
    printf("\n");

    SumPairHash(arr5, 10, 10);

    printf("\n");
    Array arr6 = {{1, 3, 4, 5, 6, 8, 9, 10, 12, 14}, 10, 10};
    SumPairSorted(arr6, 10, 10);
    printf("\n");

    SumPairHash(arr6, 10, 10);

    return 0;
}