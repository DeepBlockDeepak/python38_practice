/**
 * @file		pivot_binary_search_main.c
 * 
 * @author		Jordan Medina (jordan.medina@student.nmt.edu)
 * 
 * @brief		
 * 
 * @date		2021-01-25
 * 
 * 
 */

#include "pivot_binary_search.h"


int main(){

    //int test_array[] = {4, 5, 6, 7, 0, 1, 2};
    int test_array[ARRAY_LEN];
    int target_val;
    int target_index

    init_array(test_array);
    printf("\nThe test array is:\n");
    print_array(test_array);

    //@BUG  CHANGE THE FOLLOWING TO USE SSCANF INSTEAD.... SCAN INTO A BUF ARRAY AND THEN INTO A CHAR ARRAY
    printf("What target would you like to find in the array?\n");
    scanf("%d", &target_val);

    int pivot_index = find_pivot_index(test_array);


    if(target_val < test_array[0]){
        target_index = binary_search(test_array, target_val, pivot_index, ARRAY_LEN -1);
    }

    if(target_val > test_array[ARRAY_LEN -1]){
        target_index = binary_search(test_array, target_val, 0, pivot_index -1);
    }





    printf(
        target_index > 0    ?   "Target was found at index %d.\n\n"
                            :   "Target was not in the array.\n\n"
                            ,   target_index
    );
    //printf(target_index > 0 ? "Target was found at index %d.\n\n" : "Target was not in the array\n\n", target_index);
    
    
    return 0;
}