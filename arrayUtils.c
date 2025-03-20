#include <stdio.h>  //for printf()
#include <stdlib.h> //for exit()

void arrayIsFullBro(int arr_size, int mem_size)
{
    if (arr_size >= mem_size)
    {
        printf("Array is full bro\n");
        exit(1);
    }
}

void printArray(int *arr, int arraySize)
{
    int i;
    for (i = 0; i < arraySize; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

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

void twoDimArraySum(int arr1[3][3], int arr2[3][3])
{
    int resultArray[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            resultArray[i][j] = arr1[i][j] + arr2[i][j];
        }
        printArray(resultArray[i], 3);
    }
}

void transpose(int arr[3][3])
{
    int resultArray[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            resultArray[i][j] = arr[j][i];
        }
        printArray(resultArray[i], 3);
    }
}

void print3dArray(int arr[2][2][2])
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printArray(arr[i][j], 2);
        }
    }
}

int sequential_search(int val, int *arr, int arraySize){
    for(int i=0;i<arraySize;i++){
        if(arr[i]==val)
        return i;
    }
    printf("%d not found in array\n", val);
    return -1;
}

int binary_search(int val, int *arr, int start_pos, int end_pos){
    int mid = (start_pos+end_pos)/2;
    if(arr[mid] == val){
        printf("position %d is correct\n", mid);
        return mid;
    }
    else if(mid == start_pos){
        printf("Nope.");
        return -1;
    }
    else if(val < arr[mid]){
        printf("position %d is too high. trying again\n", mid);
        return binary_search(val, arr, start_pos, mid);
    }
    else if(val > arr[mid]){
        printf("position %d is too low. trying again\n", mid);
        return binary_search(val, arr, mid, end_pos);
    }
    printf("Something weird went wrong. I can't help you.\n");
    return -1;
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

   //So we don't need to remember to decrement the array size to get the last element
   int interpolation_search(int value, int* arr, int arr_size){
       return interpolation_search_imp(value, arr, 0, arr_size-1);
   }
