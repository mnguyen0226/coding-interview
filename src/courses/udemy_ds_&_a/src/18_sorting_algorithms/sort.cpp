// Implementation of Bubble Sort

#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>

// Swap position of two number
void Swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

// Bubble Sort
void BubbleSort(int A[], int n) // function manipulate the array directly due to array is pointer
{                               // n is the length of the array
    int flag = 0;               // allow Bubble Sort to be adaptive, save time
    for (int i = 0; i < n - 1; i++)
    {
        flag = 0;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (A[j] > A[j + 1])
            {
                flag = 1;
                Swap(&A[j], &A[j + 1]);
            }
        };
        if (flag == 0)
        {
            printf("The array has been sorted \n");
            break;
        }
    }
}

// Insertion Sort
void InsertionSort(int A[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int j = i - 1; // j as previous number for start comparison
        int x = A[i];  // get the value for comparison as well as put in the new sorted position
        while (A[j] > x && j >= 0)
        { // stop when j == -1
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = x; // put x right after A[j] with A[j] < x
    }
}

// Selection Sort
void SelectionSort(int A[], int n)
{
    int i, j, k;
    for (i = 0; i < n - 1; i++)
    { // don't need to sort the last element
        for (j = k = i; j < n; j++)
        { // j has to go to the last element to compare
            if (A[j] < A[k])
            {
                k = j;
            }
        }
        Swap(&A[i], &A[k]);
    }
}

// Helper Function Recursion for QuickSort
int Partition(int A[], int l, int h)
{
    int pivot = A[l];
    int i = l, j = h;
    do
    {
        do
        {
            i++;
        } while (A[i] <= pivot);
        do
        {
            j--;
        } while (A[j] > pivot);
        if (i < j)
        {
            Swap(&A[i], &A[j]);
        }
    } while (i < j);
    Swap(&A[l], &A[j]);
    return j;
}

// Quick Sort
void QuickSort(int A[], int l, int h)
{
    int j;
    if (l < h)
    {
        j = Partition(A, l, h);
        QuickSort(A, l, j);
        QuickSort(A, j + 1, h);
    }
}

// Helper function Merge Sort, not that the sub lists have to be sorted
void MergeSort(int A[], int low, int mid, int high)
{
    // m is the capacity of A[], n is the capacity of B[]
    int i, j, k;
    i = low, j = mid + 1, k = low;

    int B[high + 1]; // create a new array

    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
        {
            B[k++] = A[i++];
        }
        else
        {
            B[k++] = A[j++];
        }
    }

    // if there is some elements left from the two sorted array, we just move them to the bigger array
    for (; i <= mid; i++)
    {
        B[k++] = A[i];
    }
    for (; j <= high; j++)
    {
        B[k++] = A[j];
    }
    // Copy all elements in the new array to the old array
    for (i = low; i <= high; i++)
    { // <= instead of < because high is the index position, not the len
        A[i] = B[i];
    }
}

// Iterative Merge Sort
void IterativeMergeSort(int A[], int n)
{
    int p, i, low, mid, high;      // p = number of element in a list
    for (p = 2; p <= n; p = p * 2) // Says, we got 8 elements, thus we got 3 passes.
    {
        for (i = 0; i + p - 1 < n; i = i + p)
        {
            low = i;
            high = i + p - 1;
            mid = (low + high) / 2;
            MergeSort(A, low, mid, high);
        }
        // if (n - i > p / 2)
        // {
        //     low = i;
        //     high = i + p - 1;
        //     mid = (low + high) / 2;
        //     MergeSort(A, low, mid, n - 1);
        // }
    }
    if (p / 2 < n) // if the array is odd, in the end, there is 1 extra element, we need to merge sort it
    {
        MergeSort(A, 0, p / 2 - 1, n - 1); // n - 1 is the last element
    }
}

// MergeSort using recursion, similar to binary sort
void RecursiveMergeSort(int A[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        RecursiveMergeSort(A, low, mid);
        RecursiveMergeSort(A, mid + 1, high);
        MergeSort(A, low, mid, high);
    }
}

// Helper function for count sort
int FindMax(int A[], int n)
{
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (A[i] > max)
        {
            max = A[i];
        }
    }
    return max;
}

// Count Sort
void CountSort(int A[], int n)
{
    int max;
    int *count_arr; // create a new array
    max = FindMax(A, n);
    count_arr = (int *)malloc(sizeof(int) * max + 1);
    // count_arr = new int[max + 1]; // c++ style, +1 for null in array.

    for (int i = 0; i < max + 1; i++)
    {
        count_arr[i] = 0; // initialize the count array as 0
    }

    // count the elements based on the index
    for (int i = 0; i < n; i++)
    {
        count_arr[A[i]]++; // increment the array
    }

    int i = 0; // for retraverse count_arr[]
    int j = 0; // for traverse and fill out value in A[]
    while (i < max + 1)
    {
        if (count_arr[i] > 0) // if the count_arr has value
        {
            A[j++] = i;     // copy the value, then increment j
            count_arr[i]--; // deduce count
        }
        else
        {
            i++; // move to the next i in count_arr[]
        }
    }
}

// Shell Sort
void ShellSort(int A[], int n)
{
    int gap, i, j, temp;

    for (gap = n / 2; gap >= 1; gap /= 2)
    {
        for (i = gap; i < n; i++)
        {
            temp = A[i];
            j = i - gap;
            while (j >= 0 && A[j] > temp)
            {
                A[j + gap] = A[j];
                j = j - gap;
            }
            A[j + gap] = temp;
        }
    }
}

// Display all values in the array
void Display(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d, ", A[i]);
    }
    printf("\n");
}

// User Interface
int main()
{
    int A[] = {3, 7, 9, 10, 6, 5, 12, 4, 11, 2, INT_MAX};
    int A1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, INT_MAX};
    int A2[] = {6, 7, 8, 9, 10, 1, 2, 3, 4, 5};
    int n = 11;

    // BubbleSort(A, n);
    // InsertionSort(A, n);
    // SelectionSort(A, n);
    // QuickSort(A, 0, 10);
    // MergeSort(A2, 0, 4, 9); // merge sort the two sub-sorted array
    // IterativeMergeSort(A, 10);
    // RecursiveMergeSort(A, 0, 9);
    // CountSort(A, 10);
    ShellSort(A, 10);
    Display(A, 10);

    // BubbleSort(A1, n);
    // InsertionSort(A1, n);
    // SelectionSort(A1, n);
    // QuickSort(A1, 0, 10);
    // IterativeMergeSort(A1, 10);
    // RecursiveMergeSort(A1, 0, 9);
    // CountSort(A1, 10);
    ShellSort(A1, 10);
    Display(A1, 10);

    return 0;
}