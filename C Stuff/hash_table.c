#include "hash_table.h"


/**
 * @brief       CREATE SOME PERSON STRUCTS.... INSERT THEM INTO AN ARRAY OF STRUCT POINTERS     
 */

int main(){

    struct person_t* hash_table[TABLESIZE];

    /**
     * @bug     Originally passed '&hash_table' as argument; code compiled but with warning:
     *               "hash_table.h:27:41: note: expected ‘struct person_t **’ but argument is of type ‘struct person_t * (*)[10]’"
     *          
     *          Updated to just 'hash_table' as the argument
     * 
     *          ----WHY does the code compile either way? C is usually too finnicky to allow this
     * 
     */
    init_hash_table(hash_table);

    //Declare a bunch of person_t struct nodes.... initialized so that each .next attribute is NULL
    struct person_t jacob = {.name = "Jacob", .age = 256, .next = NULL};
    struct person_t kate = {.name = "Kate", .age = 27, .next = NULL};
    struct person_t mpho = {.name = "Mpho", .age = 14, .next = NULL};
    struct person_t sarah = {.name = "Sarah", .age = 54, .next = NULL};
    struct person_t edna = {.name = "Edna", .age = 15, .next = NULL};
    struct person_t maren = {.name = "Maren", .age = 25, .next = NULL};
    struct person_t eliza = {.name = "Eliza", .age = 34, .next = NULL};
    struct person_t robert = {.name = "Robert", .age = 1, .next = NULL};
    struct person_t jane = {.name = "Jane", .age = 75, .next = NULL};

    struct person_t bilbo = {.name = "Bilbo", .age = 122, .next = NULL};
    //struct person_t dilbo = {.name = "Dilbo", .age = 992, .next = NULL};

    insert_person_hash_table(&jacob, hash_table);
    insert_person_hash_table(&kate, hash_table);
    insert_person_hash_table(&mpho, hash_table);
    insert_person_hash_table(&sarah, hash_table);
    insert_person_hash_table(&edna, hash_table);
    insert_person_hash_table(&maren, hash_table);
    insert_person_hash_table(&eliza, hash_table);
    insert_person_hash_table(&robert, hash_table);
    insert_person_hash_table(&jane, hash_table);
    insert_person_hash_table(&bilbo, hash_table);

    /**
     * @bug     HOW DO YOU PASS A PERSON STRUCT POINTER TO THE INSERTION_CHAINING() FUNCTION WITHOUT MODIFYING THE ORIGINAL PERSON STRUCT????
     * 
     */
    
    
    printf("\n-----People Inserted in Hash Table-----\n");
    print_hash_table(hash_table);

    printf(
        find_person(mpho.name, hash_table) ? "%s is in the table\n": "%s is not here\n", mpho.name
    );


    printf("\nTrying to demonstrate the readdition of Jane with the External Chaining Idea\n");
    insert_head_external_chaining_method(&jane, hash_table);
    insert_head_external_chaining_method(&jane, hash_table);
    insert_head_external_chaining_method(&jane, hash_table);
    insert_tail_external_chaining(&jane, hash_table);
    print_hash_table(hash_table);
    
    printf("\nDeleting the Robert Jane... Hopefully it deletes the linked list.\n");
    delete_person_hash_table(&robert, hash_table);
    insert_head_external_chaining_method(&robert, hash_table);
    delete_person_hash_table(&edna, hash_table);
    insert_head_external_chaining_method(&edna, hash_table);
    //delete_person_hash_table(&jane, hash_table);
    print_hash_table(hash_table);


    printf("\nPerson => hash(person.name)\n");
    printf("Jacob =>\t%u\n", hash(jacob.name));
    printf("Kate => \t%u\n", hash(kate.name));
    printf("Sara => \t%u\n", hash(sarah.name));
    printf("Mpho => \t%u\n", hash(mpho.name));
    printf("Edna => \t%u\n", hash(edna.name));
    printf("Robert => \t%u\n", hash(robert.name));
    printf("Jane => \t%u\n", hash(jane.name));
    printf("Maren => \t%u\n", hash(maren.name));
    printf("Eliza => \t%u\n", hash(eliza.name));
    /**/


    return 0;
}