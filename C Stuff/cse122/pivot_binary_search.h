/**
 * @file		pivot_binary_search.h
 * 
 * @author		Jordan Medina (jordan.medina@student.nmt.edu)
 * 
 * @brief		Header File, imports the pivot_binary_search_functions.c functions to the main code
 * 
 * @date		2021-01-29
 * 
 * 
 */

#include <stdio.h>
#include <stdlib.h>

#ifndef PIVOT_BINARY_SEARCH_H_
#define PIVOT_BINARY_SEARCH_H_

#define ARRAY_LEN 10



int binary_search(int arr[], int target_val, int min, int max);
void init_array(int arr[]);
void print_array(int arr[]);
int find_pivot_index(int arr[]);



#endif