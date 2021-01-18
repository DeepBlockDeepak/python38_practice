#include "hash_table.h"


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

    struct person_t jacob = {.name = "Jacob", .age = 256};
    struct person_t kate = {.name = "Kate", .age = 27};
    struct person_t mpho = {.name = "Mpho", .age = 14};
    struct person_t sarah = {.name = "Sarah", .age = 54};
    struct person_t edna = {.name = "Edna", .age = 15};
    struct person_t maren = {.name = "Maren", .age = 25};
    struct person_t eliza = {.name = "Eliza", .age = 34};
    struct person_t robert = {.name = "Robert", .age = 1};
    struct person_t jane = {.name = "Jane", .age = 75};

    struct person_t bilbo = {.name = "Bilbo", .age = 122};


    insert_person_hash_table(&jacob, hash_table);
    insert_person_hash_table(&kate, hash_table);
    insert_person_hash_table(&mpho, hash_table);
    insert_person_hash_table(&sarah, hash_table);
    insert_person_hash_table(&edna, hash_table);
    insert_person_hash_table(&maren, hash_table);
    insert_person_hash_table(&eliza, hash_table);
    insert_person_hash_table(&robert, hash_table);
    insert_person_hash_table(&jane, hash_table);


    printf("\n-----People Inserted in Hash Table-----\n");
    print_hash_table(hash_table);


    //USING DELETE TO DELETE A PERSON STRUCT FROM THE ARRAY OF POINTERS AND CONFIRMING THE REMOVAL WITH FIND_PERSON()
    delete_person_hash_table(&mpho, hash_table);
    printf("----DELETED MPHO FROM TABLE---\n");
    print_hash_table(hash_table);


    if (!find_person(bilbo.name, hash_table)){
        printf("could not find %s in the table\n", bilbo.name);
    }
    
    /*
    printf(
    find_person((&mpho)->name, hash_table) ? "%s found in the array\n" : 
    "Didn't find %s\n",
    (&mpho)->name
    );
    


    
    printf("\n\nJacob => %u\n", hash(jacob.name));
    printf("Kate => %u\n", hash(kate.name));
    printf("Sara => %u\n", hash(sarah.name));
    printf("Mpho => %u\n", hash(mpho.name));
    printf("Edna => %u\n", hash(edna.name));
    printf("Robert => %u\n", hash(robert.name));
    printf("Jane => %u\n", hash(jane.name));
    printf("Maren => %u\n", hash(maren.name));
    printf("Eliza => %u\n", hash(eliza.name));
    */


    return 0;
}