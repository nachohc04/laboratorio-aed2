#include <stdlib.h>
#include <stdio.h>
#include "helpers.h"

#define MAX_SIZE 1000

static void dump(char a[], unsigned int length) {
    printf("\"");
    for (unsigned int j=0u; j < length; j++) {
        printf("%c", a[j]);
    }
    printf("\"");
    printf("\n\n");
}

int main(int argc, char *argv[]) {
    unsigned int indexes[MAX_SIZE];
    char letters[MAX_SIZE];
    
    char sorted[MAX_SIZE]; 
    
    if (argc<2) {
        printf("Error, debe ingresar un archivo de entrada\n");
        exit(EXIT_FAILURE);
    }

    unsigned int length = data_from_file(argv[1], indexes, letters, MAX_SIZE);
    
    reconstruct(letters, indexes, sorted, length);

    dump(sorted, length);

    return EXIT_SUCCESS;
}

