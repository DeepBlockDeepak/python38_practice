/**
 * @file		pivot_binary_search_functions.c
 * 
 * @author		Jordan Medina (jordan.medina@student.nmt.edu)
 * 
 * @brief		
 * 
 * @date		2021-01-29
 * 
 * 
 */


#include "pivot_binary_search.h"




void init_array(int arr[]){
    
    printf("\nType 10 space-separated integers, representing an ascending ordered, pivoted array:\n");

    for(int i = 0; i < ARRAY_LEN; i++){
        scanf("%d ", (arr + i));
    }
}

void print_array(int arr[]){

    printf("[");
    for(int i = 0; i < ARRAY_LEN; i++){

        printf(
            i == ARRAY_LEN - 1  ? "%d]\n"
                                : "%d, ",
                                arr[i]
        );
    }

}



int find_pivot_index(int arr[]){

    int pivot_index;
    int i = 0;

    //search the array until i is at the pivot
    while (*(arr + i) <= *(arr + i + 1)){
        i++;
    }

    //i is now the beginning of the second-half of the pivot
    pivot_index = i++;

    return pivot_index;

}








int binary_search(int arr[], int target_val, int min, int max){

    //IF statement serves to separate the recursive steps from the BASE case (when no target_val is found in the array)
    if(max >= min){

    
        //need to find the middle value which is the average 
        int middle = (max + min)/2;
        //printf("Min = %d\nMax = %d\n", min, max);

        //set up the base case, in which the program terminates upon finding the target_val
        if(arr[middle] == target_val){
            //in the case where we find exactly where target_val is indexed in the arr[]
            return middle;
        }

        //recrusive step; when the target_val could be in the "min-branch"
        //else if's required to stop the call stack from going into the different IF statements during the pop-off stage
        else if(arr[middle] > target_val){

            binary_search(arr, target_val, min, middle - 1);

        }

        //recursive step; when target_val could be in the "larger-branch". 
        else if(arr[middle] < target_val){

            binary_search(arr, target_val, middle + 1, max);
        }
    }

    //base case when the target_val is not in the arr[]
    else{
        return -1;
    }

}
