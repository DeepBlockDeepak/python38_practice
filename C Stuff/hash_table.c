#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define TABLESIZE 10
#define MAX_NAME 256


struct hash_table_t{
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
struct hash_table_t* hash_table[TABLESIZE];


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

int main(){

    printf("Jacob => %u\n", hash("Jacob"));
    printf("Natalie => %u\n", hash("Natalie"));
    printf("Sara => %u\n", hash("Sara"));
    printf("Mpho => %u\n", hash("Mpho"));
    printf("Tebogo => %u\n", hash("Tebogo"));
    printf("Ron => %u\n", hash("Ron"));
    printf("Jane => %u\n", hash("Jane"));
    printf("Maren => %u\n", hash("Maren"));
    printf("Bill => %u\n", hash("Bill"));



    return 0;
}