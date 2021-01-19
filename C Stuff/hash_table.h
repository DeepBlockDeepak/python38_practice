#ifndef HASH_H
#define HASH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>


#define TABLESIZE 10
#define MAX_NAME 256
#define BUG "*******BUG********"

//When a Node is deleted, give it this sentinel value, rather than NULL, so that search times are reduced
#define DELETED_NODE (struct person_t*)(0xFFFFFFFFFFFFFFFFUL)

struct person_t{
    char name[MAX_NAME];
    int age;
    //add other stuff later
};


/**
 * @brief   Array of pointers to 'people' structs
 *          *Use pointers because of space!
 *              -You don't need space for the full table unless the table is filled
 *          *
 */

void init_hash_table(struct person_t **hash_table){
    for (int i = 0; i < TABLESIZE; i++){
        *(hash_table + i) = NULL;
    }
}

void print_hash_table(struct person_t **table){
    printf("\n\t{\n");
    for(int i = 0; i < TABLESIZE; i++){

        if(!(*(table + i)) || table[i] == DELETED_NODE){
            printf("\t%d\t---\n", i);
        }
        else{
            printf("\t%d\t%s\t%d\n",i, (*(*(table + i))).name, table[i]->age);
        }
        
        /*//For simply pretty printing the entire array
        printf(i == TABLESIZE - 1 ? "%s : %d}\n\n" :
        "%s : %d,",
        (**table).name, &(*table)->age);
        */
    }
    
    printf("\t}\n");

}


//returns a ghetto hashing value for an inputted char
unsigned int hash(char *name){
    int length = strnlen(name, MAX_NAME);
    unsigned int hash_value = 0;

    for (int i = 0; i < length; i++){
        hash_value += *(name + i);
        hash_value = (hash_value *  name[i]) % TABLESIZE;
    }
    return hash_value;
    
}


//It is possible to use 'bool' for the function return type, while returning falses or trues, but it's not needed
void insert_person_hash_table(struct person_t *person ,struct person_t **table){

    if(!(person)){
        return;
    }

    int index = hash(person->name);

    for(int i = 0; i < TABLESIZE; i++){
        //make sure to keep 'try_index' in bounds with modulo 
        int try_index = (index + i) % TABLESIZE;
        //if the index/hash is not already taken in the hash_table, insert the person here
        //This will allow a repeated hash index to still insert... potentially
        if(table[try_index] == NULL || table[try_index] == DELETED_NODE){
            table[try_index] = person;
            return;
        }
    }

    return;

}

void delete_person_hash_table(struct person_t *person, struct person_t **table){
   
    if(!person){
        printf("That is not a valid person_t struct\n");
        return;
    }
    //compute the hash index
    int index = hash(person->name);

    //search the table for the index associated with the name and NULLify
    for(int i = 0; i < TABLESIZE; i++){

        int try_index = (index + i) % TABLESIZE;
        
        if(table[try_index] == DELETED_NODE){
            continue;
        }
        if (table[try_index] == NULL){
            return;
        }

        if(table[try_index]->name == person->name){
            table[try_index] = DELETED_NODE;    //DELETED_NODE is the sentinel value
            return;
        }
    }
    
    //printf("Person not found in the array\n");
    return;
}



//find a person in the table by their name
struct person_t* find_person(char* name, struct person_t **table){
    
    //Starting index in the hash table where the person could be located
    int index = hash(name);

    //search every person_node starting with the index provided by the hash.... go forward until a NULL pointer is met
    for (int i = 0; i < TABLESIZE; i++){
        //modulo keeps the value of the try_index within bounds of the hash table's possible indeces
        int try_index = (index + i) % TABLESIZE;
        
        //Finding the deleted node address doesn't indicate anything. Continue the search
        if(table[try_index] == DELETED_NODE){
            continue;
        }

        //if the encountered Node is NULL, that means this node was never inserted into the table, so stop searching
        if(table[try_index] == NULL){
            return NULL;//return NULL;
        }
        
        //I'm not sure that the first condition is required in the IF statement
        if(table[try_index] && strncmp(table[try_index]->name, name, MAX_NAME) == 0){
        //if(table[try_index]->name == name){
            return table[try_index];
        }

    }
    //printf("%s was not found in the table\n", name);
    return NULL;
}



#endif