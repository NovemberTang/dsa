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

void placeUnsortedElem(int* arr, int arr_size, int first_unsorted_index){
    for(int i=first_unsorted_index; i>0; i--){
        if(arr[i-1]>arr[i]){
            printf("swapping elements %d and %d\n", i, i-1);
            int tmp = arr[i];
            arr[i]=arr[i-1];
            arr[i-1]=tmp;
            printArray(arr, arr_size);
        }
        else{break;}
    }
}

void insertion_sort(int* arr, int arr_size){
    int last_sorted_index = 0;
    for(;last_sorted_index<arr_size-1; last_sorted_index++){
        int current_index = last_sorted_index+1;

        if(arr[current_index]>=arr[last_sorted_index]){
            printf("last sorted index: %d - array: ", last_sorted_index);
            printArray(arr, arr_size);
            //do nothing
            continue;
        }else{ //arr[current_index]<arr[last_sorted_index]
            placeUnsortedElem(arr,arr_size, current_index);
            printf("last sorted index: %d - array: ", last_sorted_index);
            printArray(arr, arr_size);
        }
    }

    return;

}

void single_pass_swap(int* arr, int unsorted_arr_size, int arr_size){
    for(int idx=1; idx<unsorted_arr_size; idx++){
        if(arr[idx-1]<=arr[idx]){
            printf("elements %d: %d and %d: %d are in the correct order\n", idx-1, arr[idx-1], idx, arr[idx]);
            printArray(arr, arr_size);
        }
        else{
            printf("swapping idx %d: %d and idx %d: %d\n",
                idx-1, arr[idx-1], idx, arr[idx]
            );
            int tmp=arr[idx];
            arr[idx]=arr[idx-1];
            arr[idx-1]= tmp;
            printArray(arr, arr_size);
        }
        printf("\n");
    }

}

void bubble_sort(int* arr, int arr_size){
    printArray(arr, arr_size);
    int unsorted_arr_size=arr_size;
    for(;unsorted_arr_size>0; unsorted_arr_size--){
        if(unsorted_arr_size<2){
            printf("Sorted!\n");
            return;
        }
        printf("%d elements to be sorted.\n", unsorted_arr_size);
        single_pass_swap(arr, unsorted_arr_size, arr_size);
        printf("Position of element %d finalised.\n", unsorted_arr_size-1);
    }
}


void merge(int* arr, int start, int mid, int end){
    int i = start;
    int j = mid+1;
    int k = 0;

    printf("starting new merge between %d and %d\n", start, end);
    int temp[end-start+1];
    while(i<=mid || j <=end){
        printf("i=%d, arr[i]=%d ----- j=%d, arr[j]=%d\n", i, arr[i], j, arr[j]);
        if(i > mid || arr[i]>arr[j]){
            printf("placing arr[j], %d into elem %d of placeholder array\n\n", arr[j], k);
            temp[k] = arr[j];
            j++;
            k++;
        }else if(j>end || arr[i] <= arr[j]){ //if arr[i] <= arr[j]
            printf("placing arr[i], %d into elem %d of placeholder array\n\n", arr[i], k);
            temp[k] = arr[i];
            i++;
            k++;
        } //we could add both, and increment everything if they were equal. But why?
    }

    for(int x=0; x<k; x++){
        arr[x+start]=temp[x];
    }
}

//counter should always be 0 at the beginning
void merge_sort(int* arr, int start, int end, int counter){

    if(start<end){
        counter ++;
        int mid = (start+end)/2;
        printf("start: %d, middle: %d, end: %d\n", start, mid, end);
        printf("rounds: %d\n\n", counter);
        merge_sort(arr, start, mid, counter);
        merge_sort(arr, mid+1, end, counter);
        merge(arr, start, mid, end);
    }
}

void quick_sort(int* arr, int start, int end){

    printf("start: %d, end: %d\n", start, end);
    if(end<=start){
        return;
    }

    int pos=start;
    printf("pivot: %d\n", arr[pos]);
    int swapped = 0; //Boolean. Initially set to true

    while(swapped==0){
        swapped=1; //Set to false. If we perform a swap, set to true.

        for(int right = end; right>pos; right--){
            if(arr[right]<arr[pos]){
                int a=arr[right];
                int b=arr[pos];
                printf("From right - a: %d, b: %d\n", a, b);
                arr[right]=b;
                arr[pos]=a;
                printArray(arr, end+1);
                pos=right;
                swapped=0; //swapped = true
                break;
            }
        }

        for(int left=start; left<pos; left++){
            if(arr[left]>arr[pos]){
                int a=arr[left];
                int b=arr[pos];
                printf("From left - a: %d, b: %d\n", a, b);
                arr[left]=b;
                arr[pos]=a;
                printArray(arr, end+1);
                pos=left;
                swapped=0; //swapped = true
                break;
            }
        }
        printf("\n");
    }
    quick_sort(arr, start, pos-1);
    quick_sort(arr, pos+1, end);
    }
