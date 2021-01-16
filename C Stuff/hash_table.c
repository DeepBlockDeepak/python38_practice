#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "hash_table.h"


int main(){

    struct person_t* hash_table[TABLESIZE];

    init_hash_table(&hash_table);

    printf("-----THE INITAL, NULL TABLE-----\n");
    print_hash_table(&hash_table);


    struct person_t jacob = {.name = "Jacob", .age = 256};
    struct person_t kate = {.name = "Kate", .age = 27};
    struct person_t mpho = {.name = "Mpho", .age = 14};
    struct person_t sarah = {.name = "Sarah", .age = 54};
    struct person_t edna = {.name = "Edna", .age = 15};
    struct person_t maren = {.name = "Maren", .age = 25};
    struct person_t eliza = {.name = "Eliza", .age = 34};
    struct person_t robert = {.name = "Robert", .age = 1};
    struct person_t jane = {.name = "Jane", .age = 75};


    insert_person_hash_table(&jacob, &hash_table);
    insert_person_hash_table(&kate, &hash_table);
    insert_person_hash_table(&mpho, &hash_table);
    insert_person_hash_table(&sarah, &hash_table);
    insert_person_hash_table(&edna, &hash_table);
    insert_person_hash_table(&maren, &hash_table);
    insert_person_hash_table(&eliza, &hash_table);
    insert_person_hash_table(&robert, &hash_table);
    insert_person_hash_table(&jane, &hash_table);

    print_hash_table(&hash_table);
    
    printf(
    find_person(&mpho, &hash_table) ? "%s found in the array\n" : 
    "Didn't find that person\n",
    (find_person(&mpho, &hash_table))->name
    );

    /*
    printf("\n\nJacob => %u\n", hash("Jacob"));
    printf("Natalie => %u\n", hash("Natalie"));
    printf("Sara => %u\n", hash("Sara"));
    printf("Mpho => %u\n", hash("Mpho"));
    printf("Tebogo => %u\n", hash("Tebogo"));
    printf("Ron => %u\n", hash("Ron"));
    printf("Jane => %u\n", hash("Jane"));
    printf("Maren => %u\n", hash("Maren"));
    printf("Bill => %u\n", hash("Bill"));
    */


    return 0;
}