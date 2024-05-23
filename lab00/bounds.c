#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define ARRAY_SIZE 4

void pedirArreglo(unsigned int length, int arr[]) {
    unsigned int i = 0;
    while (i<length) {
        printf("ingrese un valor entero para el %d-esimo elemento: ", i+1);
        scanf("%d", &arr[i]);
        i = i+1;
    }
}

struct bound_data {
    bool is_upperbound;
    bool is_lowerbound;
    bool exists;
    unsigned int where;
};

struct bound_data check_bound(int value, int arr[], unsigned int length) {
    struct bound_data res;
    res.is_upperbound = true;
    res.is_lowerbound = true;
    res.exists = false;

    unsigned int i = 0;
    while (i<length) {
        res.is_upperbound = arr[i] <= value && res.is_upperbound;

        res.is_lowerbound = arr[i] >= value && res.is_lowerbound;

        if (arr[i] == value){
            res.exists = true;
            res.where = i;
        }

        i=i+1;
    }
    return res;
}

int main(void) {
    int a[ARRAY_SIZE];
    int value;

    printf("Ingrese un valor entero: ");
    scanf("%d", &value);

    pedirArreglo(ARRAY_SIZE,a);

    struct bound_data result = check_bound(value, a, ARRAY_SIZE);

    // Me fijo si es cs, ci, min o max
    if (result.is_lowerbound) {
        if (result.exists) {
            // resultados para min
            printf("%d es minimo\n", value);
            printf("Se encuentra en la posicion %d del arreglo", result.where);
        }
        else {
            // resultados para ci
            printf("%d es cota inferior\n", value);
            printf("Se encuentra en la posicion %d del arreglo", result.where);
        }
    }
    else if (result.is_upperbound) {
        if (result.exists) {
            // resultados para max
            printf("%d es maximo\n", value);
            printf("Se encuentra en la posicion %d del arreglo", result.where);
        }
        else {
            // resultados para cs
            printf("%d es cota superior\n", value);
            printf("Se encuentra en la posicion %d del arreglo", result.where);
        }
    }

    return EXIT_SUCCESS;
}

