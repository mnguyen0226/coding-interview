/* Array Abstract Data Type */

#include <stdio.h>
#include <stdlib.h>

// Functions declaration
void Display(struct Array arr);
void Append(struct Array *arr, int x);
void Insert(struct Array *arr, int index, int x);
int Delete(struct Array *arr, int index);
int LinearSearch(struct Array *arr, int key);
int BinarySearchLoop(struct Array arr, int key);
int BinarySearchRecursion(struct Array arr, int key);
int Get(struct Array arr, int index);
void Set(struct Array *arr, int index, int x);
int Max(struct Array arr);
int Min(struct Array arr);
int Sum(struct Array arr);
void Reverse(struct Array *arr);
void InsertSort(struct Array *arr, int x);
int isSorted(struct Array arr);
void ReArrange(struct Array *arr);
Array *Merge(struct Array *arr1, struct Array *arr2);
Array *Union(Array *arr1, Array *arr2);
Array *Intersection(Array *arr1, Array *arr2);
Array *Difference(Array *arr1, Array *arr2);
void swap(int *x, int *y);

/* Struct data type for array */
struct Array
{
    int *A; // A[] for the other main example
    int size;
    int length; // length <= size
};

/* Function displays all element in the array */
void Display(struct Array arr)
{
    printf("Elements in the array are: ");
    for (int i = 0; i < arr.length; i++)
    {
        printf("%d ", arr.A[i]);
    }
    printf("\n");
}

/* Function appends an element into the array at the end of the array */
void Append(struct Array *arr, int x)
{
    if (arr->length < arr->size)
    {                              // if still able to add element
        arr->A[arr->length++] = x; // add at the end of the array
    }
}

/* Function inserts an element into the array at specific index */
void Insert(struct Array *arr, int index, int x)
{
    if (index >= 0 && index <= arr->length)
    {
        // shift all the element behind the index
        for (int i = arr->length; i > index; i--)
        {
            arr->A[i] = arr->A[i - 1];
        }
        arr->A[index] = x;
        arr->length++;
    }
    else
    {
        printf("Please enter the valid index for Insert().\n");
    }
}

/* Function deletes an element into the array at specific index */
int Delete(struct Array *arr, int index)
{
    if (index >= 0 && index <= arr->length - 1)
    {
        int x = arr->A[index];
        // move all element backward to delete
        for (int i = index; i < arr->length - 1; i++)
        {
            arr->A[i] = arr->A[i + 1];
        }
        arr->length--;
        return x;
    }
    printf("Please enter the valid index for Delete().\n");
    return -1;
}

/* Function does linear search for an element in the array and return index */
int LinearSearch(struct Array *arr, int key)
{
    for (int i = 0; i < arr->length; i++)
    {
        if (key == arr->A[i])
        {
            swap(&arr->A[i], &arr->A[0]); // transposition
            return i;
        }
    }
    printf("Not able to find the index of the element.\n");
    return -1;
}

/* Function does binary search for an element in the array and return index */
int BinarySearchLoop(struct Array arr, int key)
{
    int pos_low = 0;
    int pos_high = arr.length - 1;
    while (pos_low <= pos_high)
    {
        int pos_mid = (pos_low + pos_high) / 2;
        if (key == arr.A[pos_mid])
        {
            return pos_mid;
        }
        else if (key > arr.A[pos_mid])
        {
            pos_low = pos_mid + 1;
        }
        else
        {
            pos_high = pos_mid - 1;
        }
    }
    printf("Not able to find the index of the element.\n");
    return -1;
}

/* Function does binary search for an element in the array and return index */
int BinarySearchRecursion(struct Array arr, int key)
{
    static int pos_low = 0;
    static int pos_high = arr.length - 1;
    while (pos_low <= pos_high)
    {
        int pos_mid = (pos_low + pos_high) / 2;
        if (key == arr.A[pos_mid])
        {
            return pos_mid;
        }
        else if (key > arr.A[pos_mid])
        {
            pos_low = pos_mid + 1;
            return BinarySearchRecursion(arr, key);
        }
        else
        {
            pos_high = pos_mid - 1;
            return BinarySearchRecursion(arr, key);
        }
    }
    printf("Not able to find the index of the element.\n");
    return -1;
}

/* Function gets the value in the array at the specific index */
int Get(struct Array arr, int index)
{
    if (index >= 0 && index < arr.length)
    {
        return arr.A[index];
    }
    printf("Not able to find the index of the element.\n");
    return -1;
}

/* Function sets the value in the array at the specific index */
void Set(struct Array *arr, int index, int x)
{
    if (index >= 0 && index < arr->length)
    {
        arr->A[index] = x;
    }
    else
    {
        printf("Not able to find the index of the element.\n");
    }
}

/* Function finds the max value stored in the array */
int Max(struct Array arr)
{
    int max = arr.A[0];
    for (int i = 0; i < arr.length; i++)
    {
        if (arr.A[i] >= max)
        {
            max = arr.A[i];
        }
    }
    return max;
}

/* Function finds the min value stored in the array */
int Min(struct Array arr)
{
    int min = arr.A[0];
    for (int i = 0; i < arr.length; i++)
    {
        if (arr.A[i] <= min)
        {
            min = arr.A[i];
        }
    }
    return min;
}

/* Function finds the sum of all values in the array */
int Sum(struct Array arr)
{
    int sum = 0;
    for (int i = 0; i < arr.length; i++)
    {
        sum += arr.A[i];
    }
    return sum;
}

/* Function reverses the array */
void Reverse(struct Array *arr)
{
    int i, j;
    for (i = 0, j = arr->length - 1; i < j; i++, j--)
    {
        int temp = arr->A[i];
        arr->A[i] = arr->A[j];
        arr->A[j] = temp;
    }
}

/* Function insert an element in a sorted array */
void InsertSort(struct Array *arr, int x)
{
    int pos_end = arr->length - 1;
    if (arr->length == arr->size)
    {
        return; // when the array is full
    }
    // compare the number value from the back and backtrack to front
    while (pos_end >= 0 && arr->A[pos_end] > x)
    {
        arr->A[pos_end + 1] = arr->A[pos_end];
        pos_end--;
    }
    arr->A[pos_end + 1] = x;
    arr->length++;
}

/* Function check if the array is sorted or not */
int isSorted(struct Array arr)
{
    for (int i = 0; i < arr.length - 1; i++)
    {
        // if there is an element larger than the next element
        if (arr.A[i] > arr.A[i + 1])
        {
            return 0;
        }
    }
    return 1;
}

/* Function that move the negative to the left side and positive to the right side if any */
void ReArrange(struct Array *arr)
{
    int i, j;
    i = 0;
    j = arr->length - 1;

    while (i < j)
    {
        while (arr->A[i] < 0)
        {
            i++;
        }
        while (arr->A[j] >= 0)
        {
            j--;
        }
        if (i < j)
        {
            swap(&arr->A[i], &arr->A[j]);
        }
    }
}
/* Function combines two sorted lists in to one sorted list */
Array *Merge(Array *arr1, Array *arr2)
{
    int i = 0;
    int j = 0;
    int k = 0;
    Array *arr3 = (Array *)malloc(sizeof(Array)); // create in heap
    arr3->length = arr1->length + arr2->length;   // make sure to set length, else there will be garbage values

    // copy and SORT the new array
    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
        {
            arr3->A[k++] = arr1->A[i++];
        }
        else
        {
            arr3->A[k++] = arr2->A[j++];
        }
    }
    // Copy the remaining of the two arrays
    for (; i < arr1->length; i++)
    {
        arr3->A[k++] = arr1->A[i];
    }
    for (; j < arr2->length; j++)
    {
        arr3->A[k++] = arr2->A[j];
    }
    return arr3;
}

/* Function finds the union two sorted lists in to one sorted list */
Array *Union(Array *arr1, Array *arr2)
{
    int i = 0;
    int j = 0;
    int k = 0;
    Array *arr3 = (Array *)malloc(sizeof(Array)); // create in heap

    // copy and SORT the new array
    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
        {
            arr3->A[k++] = arr1->A[i++];
        }
        else if (arr1->A[i] > arr2->A[j])
        {
            arr3->A[k++] = arr2->A[j++];
        }
        else // copy 1 element and increase both i and j
        {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }
    // Copy the remaining of the two arrays
    for (; i < arr1->length; i++)
    {
        arr3->A[k++] = arr1->A[i];
    }
    for (; j < arr2->length; j++)
    {
        arr3->A[k++] = arr2->A[j];
    }
    arr3->length = k;
    arr3->size = 10; // lmao
    return arr3;
}

/* Function finds the intersection two sorted lists in to one sorted list */
Array *Intersection(Array *arr1, Array *arr2)
{
    int i = 0;
    int j = 0;
    int k = 0;
    Array *arr3 = (Array *)malloc(sizeof(Array)); // create in heap

    // copy and SORT the new array
    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
        {
            i++;
        }
        else if (arr1->A[i] > arr2->A[j])
        {
            j++;
        }
        else // copy 1 element and increase both i and j
        {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }
    arr3->length = k;
    arr3->size = 10; // lmao
    return arr3;
}

/* Function find the difference of two sorted lists in to one sorted list. Note that take the values from the first values ONLY */
Array *Difference(Array *arr1, Array *arr2)
{
    int i = 0;
    int j = 0;
    int k = 0;
    Array *arr3 = (Array *)malloc(sizeof(Array)); // create in heap

    // copy and SORT the new array
    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
        {
            arr3->A[k++] = arr1->A[i++];
        }
        else if (arr1->A[i] > arr2->A[j]) // we don't
        {
            j++;
        }
        else // copy 1 element and increase both i and j
        {
            i++;
            j++;
        }
    }
    // Copy the remaining of the two arrays
    for (; i < arr1->length; i++)
    {
        arr3->A[k++] = arr1->A[i];
    }
    arr3->length = k;
    arr3->size = 10; // lmao
    return arr3;
}

/* Helper function swap position of two elements in the array */
void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

// /* Function represents user interface */
// int main()
// {
//     // in this list, struct will get the array {2,3,4,5,6}
//     // but not the integer 5 or 10
//     Array arr = {{2, 3, 4, 5, 6}, 10, 5};

//     Append(&arr, 10);

//     Insert(&arr, 0, 10);

//     printf("Deleted element's position is: %d\n", Delete(&arr, -1));

//     printf("Searched element's position is: %d\n", LinearSearch(&arr, 3));

//     printf("Searched element's position is: %d\n", BinarySearchLoop(arr, 5));

//     printf("Searched element's position is: %d\n", BinarySearchRecursion(arr, 5));

//     Set(&arr, 3, 100);

//     printf("Get element at index 3 is: %d\n", Get(arr, 3));

//     printf("Max element is: %d\n", Max(arr));

//     printf("Max element is: %d\n", Min(arr));

//     printf("Sum of all elements is: %d\n", Sum(arr));

//     Display(arr);

//     Reverse(&arr);

//     Display(arr);

//     // SORTED ARRAY
//     Array arr2 = {{2, 3, 5, 6}, 10, 4}; // array, size, length
//     Display(arr2);

//     InsertSort(&arr2, 4);

//     Display(arr2);

//     printf("Array is (1 is sorted, 0 is not sorted): %d\n", isSorted(arr2));

//     Array arr3 = {{-2, 3, 4, -5, 6}, 10, 5}; // array, size, length

//     ReArrange(&arr3);

//     Display(arr3);

//     Array arr4 = {{2, 3, 5, 6}, 10, 4};  // array, size, length
//     Array arr5 = {{2, 6, -5, 6}, 10, 4}; // array, size, length
//     Array *arr6 = Merge(&arr4, &arr5);

//     Display(*arr6);

//     Array *arr7 = Union(&arr4, &arr5);
//     Display(*arr7);

//     Array *arr8 = Intersection(&arr4, &arr5);
//     Display(*arr8);

//     Array *arr9 = Difference(&arr4, &arr5);
//     Display(*arr9);

//     return 0;
// }

/* Menu Driver Program for Array */
int main()
{
    struct Array arr1;
    int ch;
    int x, index;
    printf("Enter Size of the Array");
    scanf("%d", &arr1.size);
    arr1.A = (int *)malloc(arr1.size * sizeof(int)); // create array in heap
    arr1.length = 0;
    do
    {
        printf("Menu\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Sum\n");
        printf("5. Display\n");
        printf("6. Exit\n");

        printf("Enter Your Choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter an element and index: ");
            scanf("%d%d", &x, &index);
            Insert(&arr1, index, x);
            printf("\n");
            break;
        case 2:
            printf("Enter index ");
            scanf("%d", &index);
            x = Delete(&arr1, index);
            printf("Deleted Element is: %d\n", x);
            printf("\n");
            break;
        case 3:
            printf("Enter an element to search: ");
            scanf("%d", &x);
            index = LinearSearch(&arr1, x);
            printf("Element index %d", index);
            printf("\n");
            break;
        case 4:
            printf("Sum if %d\n", Sum(arr1));
            printf("\n");
            break;
        case 5:
            Display(arr1);
            printf("\n");
            break;
        default:
            break;
        }
    } while (ch < 6);

    return 0;
}