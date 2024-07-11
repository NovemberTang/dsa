#include <stdio.h> //for printf()
#include "arrayUtils.h"

void findMinFromIndex(int current_idx, int *arr, int arr_len)
{
    int current_min_idx = current_idx;
    int current_min_value = arr[current_idx];
    int i;
    for (i = current_idx; i < arr_len; i++)
    {
        if (arr[i] < current_min_value)
        {
            current_min_value = arr[i];
            current_min_idx = i;
            printf("New minimum found: %d at position %d\n", current_min_value, current_min_idx);
        }
    }
    // swap the two values around
    int tmp = arr[current_idx];
    arr[current_idx] = current_min_value;
    arr[current_min_idx] = tmp;
    printf("\n");
}

void selectionSort(int *arr, int arr_len)
{

    int current_idx;

    for (current_idx = 0; current_idx < arr_len; current_idx++)
    {

        findMinFromIndex(current_idx, arr, arr_len);
    }

    printArray(arr, arr_len);
}

void mergeSortedArrays(int *xs, int x_len, int *ys, int y_len)
{
    int z_idx = 0;
    int zs[x_len + y_len];

    int x_idx = 0;
    int y_idx = 0;

    // while ((x_mem + 1 > x_idx) && (y_mem + 1 > y_idx))
    while (z_idx < x_len + y_len)
    {
        if (x_idx >= x_len && y_idx >= y_len)
        {
            printf("Reached the end of both arrays. Terminating.\n");
            break;
        }
        else if (x_idx >= x_len)
        {
            printf("Reached the end of x array. Merging the rest of y array.\n");
            while (y_idx < y_len)
            {
                zs[z_idx] = ys[y_idx];
                z_idx++;
                y_idx++;
            }
            printArray(zs, x_len + y_len);
            break;
        }
        else if (y_idx >= y_len)
        {
            printf("Reached the end of y array. Merging the rest of x array.\n");
            while (x_idx < x_len)
            {
                zs[z_idx] = xs[x_idx];
                z_idx++;
                x_idx++;
            }
            break;
        }
        else if (xs[x_idx] <= ys[y_idx] && x_idx < x_len) // e.g. x = 1 , y = 2, merge x.
        {
            int x = xs[x_idx];
            printf("Adding element %d, value %d  from xs to merged array\n", x_idx, x);
            zs[z_idx] = x;
            printf("Element %d: %d\n", z_idx, zs[z_idx]);
            z_idx++;
            x_idx++;
            printf("%d\n\n", x_idx);
        }
        else // if (xs[x_idx] > ys[y_idx] && y_idx < y_len) // e.g. x=2, y = 1, merge y.
        {
            int y = ys[y_idx];
            printf("Adding element %d, value %d from ys to merged array\n", y_idx, y);
            zs[z_idx] = y;
            printf("Element %d: %d\n", z_idx, zs[z_idx]);
            z_idx++;
            y_idx++;
            printf("y_mem: %d\n", y_len);
            printf("y_idx: %d\n\n", y_idx);
        }
    }
    printf("x index: %d. y index: %d\n", x_idx, y_idx);

    printf("Terminating.\nx_idx: %d, x_mem: %d\ny_idx: %d, y_mem: %d\n", x_idx, x_len, y_idx, y_len);
    printArray(zs, x_len + y_len);
}
