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
    struct person_t dilbo = {.name = "Dilbo", .age = 992};

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


    printf("\n-----People Inserted in Hash Table-----\n");
    print_hash_table(hash_table);


    //USING DELETE TO DELETE A PERSON STRUCT FROM THE ARRAY OF POINTERS AND CONFIRMING THE REMOVAL WITH FIND_PERSON()
    //printf("%p == mpho's address\n", &mpho);
    //printf("%p == hash_table's mpho address\n", &hash_table[5]);
    delete_person_hash_table(&mpho, hash_table);
    //printf("%p == mpho's address after the delete_call() from the hash_table\n", &mpho);
    //printf("%p == hash_table's mpho address after the delete()\n", &hash_table[5]);
    printf("----DELETED MPHO FROM TABLE---\n");
    print_hash_table(hash_table);
    

    insert_person_hash_table(&dilbo, hash_table);
    printf("\nReinserted dilbo\n");
    print_hash_table(hash_table);
    

    delete_person_hash_table(&dilbo, hash_table);
    printf("\nDeleted Dilbo\n");
    print_hash_table(hash_table);
    


    if(!find_person(mpho.name, hash_table)){
        printf("HE'S NOT HERE@@!!!\n");
    }
    

    /**
     * @note Why is it the case that modifying the value of an element of hash_table, leaves the original variable untouched?
     *          
     *       For example: When calling delete_person_hash_table(&mpho, hash_table), the table[try_index] = DELETED_NODE assignment, sets 
     *                      pointer to a junk address, DELETED_NODE. However, mpho is still accessible
     * 
     */
    printf("\n***TESTING***\naddress of table[8] == bilbo element = %p\naddress of bilbo the struct= %p\n", hash_table[5], &bilbo);

    /*
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