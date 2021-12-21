#include <iostream>
using namespace std;

/* Class for array */
class Array
{
private:
    int *A;
    int size;
    int length; // length <= size
    void swap(int *x, int *y);

public:
    // Default constructor
    Array()
    {
        size = 10;
        length = 0;
        A = new int[size];
    }
    // Paramemter constructor
    Array(int sz)
    {
        size = sz;
        length = 0;
        A = new int[size];
    }
    // destructor
    ~Array()
    {
        delete[] A;
    }
    // Functions declaration
    void Display();
    void Append(int x);
    void Insert(int index, int x);
    int Delete(int index);
    int LinearSearch(int key);
    int BinarySearchLoop(int key);
    int BinarySearchRecursion(int key);
    int Get(int index);
    void Set(int index, int x);
    int Max();
    int Min();
    int Sum();
    void Reverse();
    void InsertSort(int x);
    int isSorted();
    void ReArrange();
    Array *Merge(Array *arr2);
    Array *Union(Array *arr2);
    Array *Intersection(Array *arr2);
    Array *Difference(Array *arr2);
};

/* Function displays all element in the array */
void Array::Display()
{
    cout << "Elements in the array are: " << endl;
    for (int i = 0; i < length; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

/* Function appends an element into the array at the end of the array */
void Array::Append(int x)
{
    if (length < size)
    {                    // if still able to add element
        A[length++] = x; // add at the end of the array
    }
}

/* Function inserts an element into the array at specific index */
void Array::Insert(int index, int x)
{
    if (index >= 0 && index <= length)
    {
        // shift all the element behind the index
        for (int i = length; i > index; i--)
        {
            A[i] = A[i - 1];
        }
        A[index] = x;
        length++;
    }
    else
    {
        cout << "Please enter the valid index for Insert().\n";
    }
}

/* Function deletes an element into the array at specific index */
int Array::Delete(int index)
{
    if (index >= 0 && index <= length - 1)
    {
        int x = A[index];
        // move all element backward to delete
        for (int i = index; i < length - 1; i++)
        {
            A[i] = A[i + 1];
        }
        length--;
        return x;
    }
    cout << "Please enter the valid index for Delete().\n";
    return -1;
}

/* Function does linear search for an element in the array and return index */
int Array::LinearSearch(int key)
{
    for (int i = 0; i < length; i++)
    {
        if (key == A[i])
        {
            swap(&A[i], &A[0]); // transposition
            return i;
        }
    }
    cout << "Not able to find the index of the element.\n";
    return -1;
}

/* Function does binary search for an element in the array and return index */
int Array::BinarySearchLoop(int key)
{
    int pos_low = 0;
    int pos_high = length - 1;
    while (pos_low <= pos_high)
    {
        int pos_mid = (pos_low + pos_high) / 2;
        if (key == A[pos_mid])
        {
            return pos_mid;
        }
        else if (key > A[pos_mid])
        {
            pos_low = pos_mid + 1;
        }
        else
        {
            pos_high = pos_mid - 1;
        }
    }
    cout << "Not able to find the index of the element.\n";
    return -1;
}

/* Function does binary search for an element in the array and return index */
int Array::BinarySearchRecursion(int key)
{
    static int pos_low = 0;
    static int pos_high = length - 1;
    while (pos_low <= pos_high)
    {
        int pos_mid = (pos_low + pos_high) / 2;
        if (key == A[pos_mid])
        {
            return pos_mid;
        }
        else if (key > A[pos_mid])
        {
            pos_low = pos_mid + 1;
            return BinarySearchRecursion(key);
        }
        else
        {
            pos_high = pos_mid - 1;
            return BinarySearchRecursion(key);
        }
    }
    cout << "Not able to find the index of the element.\n";
    return -1;
}

/* Function gets the value in the array at the specific index */
int Array::Get(int index)
{
    if (index >= 0 && index < length)
    {
        return A[index];
    }
    cout << "Not able to find the index of the element.\n";
    return -1;
}

/* Function sets the value in the array at the specific index */
void Array::Set(int index, int x)
{
    if (index >= 0 && index < length)
    {
        A[index] = x;
    }
    else
    {
        cout << "Not able to find the index of the element.\n";
    }
}

/* Function finds the max value stored in the array */
int Array::Max()
{
    int max = A[0];
    for (int i = 0; i < length; i++)
    {
        if (A[i] >= max)
        {
            max = A[i];
        }
    }
    return max;
}

/* Function finds the min value stored in the array */
int Array::Min()
{
    int min = A[0];
    for (int i = 0; i < length; i++)
    {
        if (A[i] <= min)
        {
            min = A[i];
        }
    }
    return min;
}

/* Function finds the sum of all values in the array */
int Array::Sum()
{
    int sum = 0;
    for (int i = 0; i < length; i++)
    {
        sum += A[i];
    }
    return sum;
}

/* Function reverses the array */
void Array::Reverse()
{
    int i, j;
    for (i = 0, j = length - 1; i < j; i++, j--)
    {
        int temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }
}

/* Function insert an element in a sorted array */
void Array::InsertSort(int x)
{
    int pos_end = length - 1;
    if (length == size)
    {
        return; // when the array is full
    }
    // compare the number value from the back and backtrack to front
    while (pos_end >= 0 && A[pos_end] > x)
    {
        A[pos_end + 1] = A[pos_end];
        pos_end--;
    }
    A[pos_end + 1] = x;
    length++;
}

/* Function check if the array is sorted or not */
int Array::isSorted()
{
    for (int i = 0; i < length - 1; i++)
    {
        // if there is an element larger than the next element
        if (A[i] > A[i + 1])
        {
            return 0;
        }
    }
    return 1;
}

/* Function that move the negative to the left side and positive to the right side if any */
void Array::ReArrange()
{
    int i, j;
    i = 0;
    j = length - 1;

    while (i < j)
    {
        while (A[i] < 0)
        {
            i++;
        }
        while (A[j] >= 0)
        {
            j--;
        }
        if (i < j)
        {
            swap(&A[i], &A[j]);
        }
    }
}
/* Function combines two sorted lists in to one sorted list */
Array *Array::Merge(Array *arr2)
{
    int i = 0;
    int j = 0;
    int k = 0;
    Array *arr3 = (Array *)malloc(sizeof(Array)); // create in heap
    arr3->length = length + arr2->length;         // make sure to set length, else there will be garbage values

    // copy and SORT the new array
    while (i < length && j < arr2->length)
    {
        if (A[i] < arr2->A[j])
        {
            arr3->A[k++] = A[i++];
        }
        else
        {
            arr3->A[k++] = arr2->A[j++];
        }
    }
    // Copy the remaining of the two arrays
    for (; i < length; i++)
    {
        arr3->A[k++] = A[i];
    }
    for (; j < arr2->length; j++)
    {
        arr3->A[k++] = arr2->A[j];
    }
    return arr3;
}

/* Function finds the union two sorted lists in to one sorted list */
Array *Array::Union(Array *arr2)
{
    int i = 0;
    int j = 0;
    int k = 0;
    Array *arr3 = (Array *)malloc(sizeof(Array)); // create in heap

    // copy and SORT the new array
    while (i < length && j < arr2->length)
    {
        if (A[i] < arr2->A[j])
        {
            arr3->A[k++] = A[i++];
        }
        else if (A[i] > arr2->A[j])
        {
            arr3->A[k++] = arr2->A[j++];
        }
        else // copy 1 element and increase both i and j
        {
            arr3->A[k++] = A[i++];
            j++;
        }
    }
    // Copy the remaining of the two arrays
    for (; i < length; i++)
    {
        arr3->A[k++] = A[i];
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
Array *Array::Intersection(Array *arr2)
{
    int i = 0;
    int j = 0;
    int k = 0;
    Array *arr3 = (Array *)malloc(sizeof(Array)); // create in heap

    // copy and SORT the new array
    while (i < length && j < arr2->length)
    {
        if (A[i] < arr2->A[j])
        {
            i++;
        }
        else if (A[i] > arr2->A[j])
        {
            j++;
        }
        else // copy 1 element and increase both i and j
        {
            arr3->A[k++] = A[i++];
            j++;
        }
    }
    arr3->length = k;
    arr3->size = 10; // lmao
    return arr3;
}

/* Function find the difference of two sorted lists in to one sorted list. Note that take the values from the first values ONLY */
Array *Array::Difference(Array *arr2)
{
    int i = 0;
    int j = 0;
    int k = 0;
    Array *arr3 = (Array *)malloc(sizeof(Array)); // create in heap

    // copy and SORT the new array
    while (i < length && j < arr2->length)
    {
        if (A[i] < arr2->A[j])
        {
            arr3->A[k++] = A[i++];
        }
        else if (A[i] > arr2->A[j]) // we don't
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
    for (; i < length; i++)
    {
        arr3->A[k++] = A[i];
    }
    arr3->length = k;
    arr3->size = 10; // lmao
    return arr3;
}

/* Helper function swap position of two elements in the array */
void Array::swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

/* Menu Driver Program for Array */
int main()
{
    Array *arr1;
    int ch, sz;
    int x, index;

    cout << "Enter Size of the Array";
    cin >> sz;
    arr1 = new Array(sz);

    do
    {
        cout << "Menu\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Search\n";
        cout << "4. Sum\n";
        cout << "5. Display\n";
        cout << "6. Exit\n";

        cout << "Enter Your Choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "Enter an element and index: ";
            cin >> x >> index;
            arr1->Insert(index, x);
            cout << endl;
            break;
        case 2:
            cout << "Enter index ";
            cin >> index;
            x = arr1->Delete(index);
            cout << "Deleted Element is: " << x << endl;
            cout << endl;
            break;
        case 3:
            cout << "Enter an element to search: ";
            cin >> x;
            index = arr1->LinearSearch(x);
            cout << "Element index " << index;
            cout << endl;
            break;
        case 4:
            cout << "Sum is " << arr1->Sum() << endl;
            cout << endl;
            break;
        case 5:
            arr1->Display();
            cout << endl;
            break;
        default:
            break;
        }
    } while (ch < 6);

    return 0;
}