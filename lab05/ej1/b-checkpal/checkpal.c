#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "strfuncs.h"

#define MAX_LENGTH 20

#define SIZEOF_ARRAY(s) (sizeof(s) / sizeof(*s))


int main(void) {
    char user_input[MAX_LENGTH];
    char ignore_chars[] = {' ', '?', '!', ',', '-', '.'};
    char *filtered=NULL;


    printf("Ingrese un texto (no más de %d símbolos) para verificar palíndromo: \n", MAX_LENGTH);
    // utilizo fgets para escribir string de file a user_input
    filtered = fgets(user_input, MAX_LENGTH, stdin);
    if (filtered==NULL) {
        fprintf(stderr, "Something went wrong with fgets.\n");
        exit(EXIT_FAILURE);
    }
    filtered = string_filter(filtered, ignore_chars[0]);
    
    for (unsigned int i=0; i < SIZEOF_ARRAY(ignore_chars); i++) {
        filtered = string_filter(filtered, ignore_chars[i]);
    }

    filtered = string_filter(filtered, '\n');

    printf("El texto:\n\n"
            "\"%s\" \n\n"
            "%s un palíndromo.\n\n", user_input, string_is_symmetric(filtered) ? "Es": "NO es");
    
    // libero memoria
    free(filtered);
    
    return EXIT_SUCCESS;
}

