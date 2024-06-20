#include <stdio.h>

int myfunction(char *string)
{
    printf("%s", string);
    for (int i = 0; i < 7; i++)
    {
        printf("%x\n", (string + i));
        printf("%c\n", *(string + i));
    }
    return 0;
}

void insertAtBeginning(int *arr, int size, int elem, int elemCount)
{
    int i;
    if (elemCount >= size)
    {
        printf("Array is full bro\n");
        return;
    }

    for (i = elemCount - 1; i >= 0; i--)
    {
        printf("%d\n", arr[i]);
        arr[i + 1] = arr[i];
    }
    printf(" \n");
    arr[0] = elem;
    printf("%d\n", arr[0]);
    printf("%d\n", arr[1]);
}

// TODO insert at position

void insertIntoPosition(int *arr, int ins_idx, int mem_size, int arr_size, int value)
{

    if (arr_size >= mem_size)
    {
        printf("Array is full bro\n");
        return;
    }

    int i;

    for (i = arr_size - 1; i >= ins_idx; i--)
    {
        printf("%d\n", arr[i]);
        arr[i + 1] = arr[i];
    }
    arr[ins_idx] = value;

    printf(" \n");
    i = 0;
    for (i; i <= arr_size; i++)
    {
        printf("%d\n", arr[i]);
    };
}

// TODO insert at end

int main()
{
    // printf("hello\n");
    // myfunction("world\n");

    int myLongArray[6] = {2,
                          4,
                          8,
                          10};

    insertIntoPosition(myLongArray, 2, 6, 4, 6);
}