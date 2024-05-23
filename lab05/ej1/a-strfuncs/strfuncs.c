#include <stdlib.h>

#include "strfuncs.h"

size_t string_length(const char *str) {
    size_t c=0;
    while(str[c]!='\0')
    {
        c++;
    }   
    return c;
}

char *string_filter(const char *str, char c) {
    // indice para recorrer string original
    unsigned int i = 0;
    // counter para saber la cantidad de letras del nuevo string
    unsigned int counter = 0;

    while(str[i]!='\0')
    {
        if (str[i]!=c) {
            counter++;
        }
        i++;
    }   

    char *new_string = malloc(sizeof(char)*(counter+1)); // +1 para el '/0'
    i = 0;
    unsigned int j = 0;
    while(str[i]!='\0')
    {
        if (str[i]!=c) {
            new_string[j] = str[i];
            j++;
        }
        i++;
    }

    new_string[i] = '\0';

    return new_string;
}

bool string_is_symmetric(const char *str) {
    bool r = true;

    size_t ls = string_length(str);

    for (unsigned int i = 0; i<(ls/2); i++) {
        r = r && str[i] == str[ls-1-i]; // checkeo los elementos en posiciones "opuestas"
    }

    return r;
}