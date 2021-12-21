#include <stdio.h>
#define SIZE 10

// hash function
int hash(int key)
{
    return key % SIZE;
}

// linear probing
int linear_probing(int H[], int key)
{
    int index = hash(key);
    int i = 0;
    while (H[(index + i) % SIZE] != 0) // if the slot has been occupy, then move to the next slot
    {
        i++;
    }
    return (index + i) % SIZE; // return the index that is empty
}

// linear probing
int quadratic_probing(int H[], int key)
{
    int index = hash(key);
    int i = 0;
    while (H[(index + i*i) % SIZE] != 0) // if the slot has been occupy, then move to the next slot
    {
        i++;
    }
    return (index + i*i) % SIZE; // return the index that is empty
}


// linear probing insert
void Insert(int H[], int key)
{
    int index = hash(key);
    if (H[index] != 0)
    {
        index = linear_probing(H, key); // get the slot that is empty
    }
    H[index] = key; // fill out the key to the HT
}

// search
int Search(int H[], int key)
{
    int index = hash(key);
    int i = 0;
    while (H[(index + i) % SIZE] != key)
    {
        i++;
    }
    return (index + i) % SIZE;
}

// user interface
int main()
{
    int HT[SIZE];

    for (int i = 0; i < SIZE; i++)
    {
        HT[i] = 0;
    }

    Insert(HT, 12);
    Insert(HT, 25);
    Insert(HT, 35);
    Insert(HT, 26);

    printf("\nKey found at %d\n", Search(HT, 35));

    return 0;
}