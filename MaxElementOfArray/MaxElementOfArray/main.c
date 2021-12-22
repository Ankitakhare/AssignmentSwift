//
//  main.c
//  MaxElementOfArray
//
//  Created by Balu Naik on 4/26/20.
//  Copyright © 2020 BaluTutorial. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>


/*
  - Find Max value form sorted list
  - If array list is sorted then
  - Element can be at postion 1 or position last
  - Return max value of the list
 */

int getMaxValueFromSortedList(int arr[], int size) {
    
    return arr[0] > arr[size - 1 ] ? arr[0] : arr[size-1];
}

/*
 Enter array size: 10

 Enter 10 values: 10 20 30 40 50 60 70 80 90 100

 Max value of list: 100
 
What is time complexity??   O(1)
 
 */


/*   USE Case 2  Unsorted list
     - Find max value from unsorted list
     - Result can be in any postion
     - We have compare all elements i.e. untill end of the array
 */

int getMaxValueFromUnsortedList(int arr[], int size) {
    int result = arr[0];  // default result is first value
    
    for (int index = 1; index < size - 1; index++) {
        if(arr[index] > result) {
            result = arr[index];
        }
    }
    
    return result;
}
/*
    Enter array size: 10
    Enter 10 values: 50 60 40 70 30 80 100 20 10 90
    Max value of list: 100
 
    What is time complexity??   O(n)
 
 */


int main(int argc, const char * argv[]) {
    
    int arraySize;
    int *arr;
    
    /* Take array size as input from user */
    printf("Enter array size: ");
    scanf("%d",&arraySize);
    
    
    /* Create memory at runtime */
    arr = (int *)calloc(arraySize, sizeof(int)); // Ex: 10 *2B = 20B
    
    /* Read all elements from user */
    printf("\nEnter %d values: ", arraySize);
    for (int index = 0; index < arraySize; index++) {
        scanf("%d",&arr[index]);
    }
    
    //int maxValue = getMaxValueFromSortedList(arr, arraySize);
    int maxValue = getMaxValueFromUnsortedList(arr, arraySize);
    printf("\nMax value of list: %d\n", maxValue);
    
    free(arr);
    arr = NULL;
    return 0;
}
