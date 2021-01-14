#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


#define TABLESIZE 10
#define MAX_NAME 256


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

        if(!(*(table + i))){
            printf("\t%d\t---\n", i);
        }else{
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

bool insert_hash_table(struct person_t *person ,struct person_t **table){

    if(!(person)){
        return false;
    }

    int index = hash(person->name);

    //if the element already exists in the table, i.e. it is not NULL
    if(table[index]){
        return false;
    }

    //if the element in the table is NULL, assign it a pointer to the person structure
    table[index] = person;
    return true;
}

//find a person in the table by their name
struct person_t* find_person(char* name, struct person_t **table){
    int index = hash(name);
    if((table[index]) && strncmp(name, table[index]->name, MAX_NAME) == 0){
        return table[index];
    }
    else{
        return NULL;
    }

}

int main(){

    struct person_t* hash_table[TABLESIZE];

    init_hash_table(&hash_table);

    printf("-----THE INITAL, NULL TABLE-----\n");
    print_hash_table(&hash_table);


    struct person_t jacob = {.name = "Jacob", .age = 111};
    struct person_t kate = {.name = "Kate", .age = 99};
    struct person_t mpho = {.name = "Mpho", .age = 99};
    insert_hash_table(&jacob, &hash_table);
    insert_hash_table(&kate, &hash_table);
    insert_hash_table(&mpho, &hash_table);

    print_hash_table(&hash_table);
    
    printf(
    find_person(&mpho, &hash_table) ? "Found this jackass %s\n" : 
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