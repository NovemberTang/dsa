#include <stdio.h> //for printf()
#include "insertAndDelete.h"

int main()
{

    int myLongArray[10] = {2,
                           4,
                           8,
                           10};

    int arr_size = 4;

    insertAtBeginning(myLongArray, 10, 6, &arr_size);
    // insertAtBeginning mutated myLongArray, its length is now 5,
    // which is reflected in insertAtEnd

    insertAtEnd(myLongArray, 10, &arr_size, 12);

    deleteFromBeginning(myLongArray, &arr_size);

    deleteFromEnd(myLongArray, &arr_size);

    deleteFromPosition(myLongArray, &arr_size, 1);
}
