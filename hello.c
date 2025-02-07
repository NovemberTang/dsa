#include <stdio.h>  //for printf()
#include <stdlib.h> //for malloc() and NULL
#include "arrayUtils.h"
#include "mergeAndSort.h"

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
    return -1; // couldn't find the value.
}

struct ringBuffer
{
    int lastReadAddress;
    int nextWriteAddress;
    int *array;
    int arrayLength;
};

int readRingBuffer(struct ringBuffer *r)
{
    int nextAddress = (r->lastReadAddress + 1) % r->arrayLength;
    printf("Reading value from position %d\n", nextAddress);
    int valueToRead = r->array[nextAddress];
    r->lastReadAddress = nextAddress;
    return valueToRead;
}

void writeRingBuffer(struct ringBuffer *r, int value)
{
    printf("Writing value %d to position %d\n", value, r->nextWriteAddress);
    r->array[r->nextWriteAddress] = value;
    r->nextWriteAddress = (r->nextWriteAddress + 1) % r->arrayLength;
}

int interpolation_search_imp(int value, int* arr, int low_pos, int high_pos){

 int low = arr[low_pos];
 int high = arr[high_pos];
 int mid = low_pos + ((high_pos-low_pos) * (value-low)) / (high-low);

 if(arr[mid]==value)
 {
    printf("%d: %d\n", mid, arr[mid]);
    return arr[mid];
 }
 else if(value < arr[mid]){
    return interpolation_search_imp(value, arr, low_pos, mid-1);
 }
 else { // if(value > arr[mid]){
    return interpolation_search_imp(value, arr,mid+1, high_pos);
 };

}

//SO we don't need to remember to decrement the array size to get the last element
int interpolation_search(int value, int* arr, int arr_size){
    return interpolation_search_imp(value, arr, 0, arr_size-1);
}

//Selection sort ✅
//Insertion sort ✅
//Merge sort ✅
//Bubble sort ✅
//Quick sort

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

int main()
{

    int array[7] = {2,1,6,0, 8, 3, 15};
    printArray(array, 7);
    quick_sort(array, 0, 6);
    printArray(array, 7);
}
