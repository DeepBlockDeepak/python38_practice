#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int hasPalindromeAnagram(char* str, size_t len) {
    char letters[26];
    
    for (int i = 0; i < 26; i++) {
        letters[i] = 0;
    }

    for (int i = 0; i < len; i++) {
        letters[*(str + i) - 'a']++;
    }

    int evens = 0;
    for (int i = 0; i < 26; i++) {
        if ((letters[i] % 2 == 0) && (letters[i] != 0)) {
            evens++;
        }
    }

    return (evens >= len/2);
}

int main() {
    char *s1 = (char *) calloc(256, sizeof(char));
    char *s2 = (char *) calloc(256, sizeof(char));
    strcpy(s1, "carrace");
    strcpy(s2, "bb");
    
    int r1 = hasPalindromeAnagram(s1, 7);
    int r2 = hasPalindromeAnagram(s2, 5);
    
    printf("%s: %s\n", s1, r1 == 1 ? "ok" : "false");
    printf("%s: %s\n", s2, r2 == 1 ? "ok" : "false");
}