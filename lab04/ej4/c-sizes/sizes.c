#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "data.h"

void
print_data(data_t d) {
    printf("NOMBRE: %s\n"
           "EDAD  : %d años\n"
           "ALTURA: %d cm\n\n",
           d.name, d.age, d.height);
}

int main(void) {

    data_t messi = {"Leo Messi", 36, 169};
    print_data(messi);

    printf("name-size  : %lu bytes\n"
           "age-size   : %lu bytes\n"
           "height-size: %lu bytes\n"
           "data_t-size: %lu bytes\n", sizeof(messi.name), sizeof(messi.age), sizeof(messi.height), sizeof(messi));

    printf("name-address  : %p\n"
           "age-address   : %p\n"
           "height-address: %p\n"
           "data_t-address: %p\n", (void *) &messi.name, (void *) &messi.age, (void *) &messi.height, (void *) &messi);


    return EXIT_SUCCESS;
}

/*
    a) La suma del tamaño de los campos no coincide con el total, el total dice 40bytes y la suma deberia dar 38bytes.
    b) No, el tamaño del campo name no depende del nombre que contiene ya que name es un arreglo de 30 elementos, y los arreglos ocupan un espacio fijo independientemente de cuales sean sus elementos.
    c) Me resulta algo extraño que la direccion de memoria de age empiece 32 direcciones despues que la de name, y no 30 como tendria que ser segun el tamaño que tiene (30bytes). Esto al parecer se debe a un concepto llamado padding, el cual utilizan las computadoras para hacer que los espacios ocupados en memoria sean multiplos de 4, para asi simplificar las operaciones y ganar eficiencia a cambio de utlilizar mas memoria. 
*/