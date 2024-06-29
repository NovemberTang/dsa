#include <stdio.h> //for printf()
#include "insertAndDelete.h"
#include "arrayUtils.h"

int findIndex(int *arr, int value, int arr_len)
{
    int i;
    for (i = 0; i < arr_len; i++)
    {
        if (arr[i] == value)
        {
            printf("Found value %d at position %d\n", value, i);
            return i;
        }
    }
    printf("Couldn't find value %d in array\n", value);
    return -1;
}

void *mergeSortedArrays(int *xs, int x_mem, int *ys, int y_mem)
{
    int z_idx = 0;
    int zs[x_mem + y_mem];

    int x_idx = 0;
    int y_idx = 0;

    // while ((x_mem + 1 > x_idx) && (y_mem + 1 > y_idx))
    while (z_idx < x_mem + y_mem)
    {
        if (xs[x_idx] <= ys[y_idx] && xs[x_idx] != 0) // e.g. x = 1 , y = 2, merge x.
        {
            int x = xs[x_idx];
            printf("Adding element %d, value %d  from xs to merged array\n", x_idx, x);
            zs[z_idx] = x;
            printf("Element %d: %d\n", z_idx, zs[z_idx]);
            z_idx++;
            x_idx++;
            printf("%d\n\n", x_idx);
        }
        else if (xs[x_idx] > ys[y_idx] && ys[y_idx] != 0) // e.g. x=2, y = 1, merge y.
        {
            int y = ys[y_idx];
            printf("Adding element %d, value %d from ys to merged array\n", y_idx, y);
            zs[z_idx] = y;
            printf("Element %d: %d\n", z_idx, zs[z_idx]);
            z_idx++;
            y_idx++;
            printf("y_mem: %d\n", y_mem);
            printf("y_idx: %d\n\n", y_idx);
        }
        else if (xs[x_idx] != ys[x_idx] && (xs[x_idx] == 0 || ys[y_idx] == 0)) // one of them is equal to zero, add the other.
        {
            printf("One element is zero, adding the other\n");
            int x_is_zero = xs[x_idx] == 0;
            int z = x_is_zero ? ys[y_idx] : xs[x_idx];
            char *chosen_array = x_is_zero ? "ys" : "xs";
            int chosen_elem = x_is_zero ? y_idx : x_idx;
            printf("Adding element %d, value %d from %s to array\n\n", chosen_elem, z, chosen_array);
            zs[z_idx] = z;
            z_idx++;
            x_is_zero ? y_idx++ : x_idx++;
        }
        else // both of them are equal to 0, terminate the loop.
        {
            break;
        }
    }
    printf("x index: %d. y index: %d\n", x_idx, y_idx);

    printf("Terminating.\nx_idx: %d, x_mem: %d\ny_idx: %d, y_mem: %d\n", x_idx, x_mem, y_idx, y_mem);
    printArray(zs, x_mem + y_mem);
}

int main()
{

    int myLongArray[10] = {2,
                           4,
                           8,
                           10};

    int myShortArray[3] = {5};

    mergeSortedArrays(myLongArray, 4, myShortArray, 1);
}
