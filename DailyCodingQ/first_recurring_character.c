/*  
    Given a string, return the first recurring character in it, or null if there is no recurring character.
    Ex: Given the string 'acbbac', return 'b'
    Given the string 'abcdef', return null
    
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int recurring_or_not();

int main(){
    
    if (!(recurring_or_not())){
        printf("No reoccuring characters were found.\n");
    }


    return 0;
}

int recurring_or_not(){

    char input_string[256];

    char *dictionary = calloc(26, sizeof(char));

    printf("Enter a some string\n");
    fgets(input_string, 256 + 1, stdin);

    printf("lenght of string = %d\n", strlen(input_string));

    int i = 0;
    for(i; i < strlen(input_string); i++){
        if (*(dictionary + (input_string[i] - 'a')) > 0){
            printf("First recuring character is %c\n", *(input_string + i));
            return 1;
        }

        else{
            (*(dictionary + (input_string[i] - 'a')))++;
        }

    }
    return 0;

}