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

int main()
{
    // printf("hello\n");
    // myfunction("world\n");

    int myArray[5] = {5, 4, 3};

    insertAtBeginning(myArray, 5, 2, 3);

    insertAtBeginning(myArray, 2, 2, 3);
}