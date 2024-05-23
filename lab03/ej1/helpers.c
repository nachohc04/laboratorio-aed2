#include "helpers.h"
#include <stdio.h>
#include <stdlib.h>

unsigned int data_from_file(const char *path, unsigned int indexes[], char letters[], unsigned int max_size) {
    FILE *file = fopen(path, "r");
    if (file==NULL) {
        printf("Error al abrir el archivo\n");
    }

    unsigned int i = 0u;
    
    while (!feof(file) && i < max_size) {
        fscanf(file, " %u -> * %c *", &indexes[i], &letters[i]);
        i++;
    } 
    
    clearerr(file);
    fclose(file);
    
    return i-1;
}

void reconstruct(char letters[], unsigned int indexes[], char sorted[], unsigned int length) {
    for (unsigned int i = 0u; i<length; i++) {
        // verifico que index este entre 0 y length del archivo
        if (indexes[i]<length){
            sorted[indexes[i]] = letters[i];
        } else {
            printf("Error, formato de indice invalido\n");
            exit(EXIT_FAILURE);
        }
    }
}
