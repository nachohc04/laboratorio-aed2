#include <stdio.h>
#include <stdbool.h>

struct row_data {
    char winner;
    bool hay_row_winner;
};

struct column_data {
    char winner;
    bool hay_column_winner;
};

struct row_data row(char board[3][3]) {

    // res
    struct row_data res;
    res.winner = '-';
    // aux
    char possible_winner;
    // bool d_w = true; // diagonal winner
    
    // FILAS
    // me fijo si hay 3 iguales en las filas
    res.hay_row_winner = true; // row winner

    unsigned int i = 0;
    unsigned int j = 0;
    
    while (i<3) {
        // seteo como posible ganador al jugador de la primera columna
        possible_winner = board[i][0];

        // verifico si efectivamente es ganador, viendo si el resto de los lugares tambien estan ocupados por el
        while (j<3) {
            res.hay_row_winner = res.hay_row_winner && possible_winner == board[i][j];
            j = j+1;
        }
        j = 0; // reseteo el indice para columnas

        if (res.hay_row_winner) {
            res.winner = board[i][j];
            i=3; // ya hay ganador
        }
        else if (!res.hay_row_winner && i==2) {
            i=3; // no hay ganador pero estamos en la ultima fila y no queremos resetear hay_row_winner ni setear res.winner
        }
        else {
            i = i+1; // no hay ganador, voy a la siguiente fila
            res.hay_row_winner = true; // reseteo el auxiliar para hay_row_winner
        }
    }

    return res; 
}

struct column_data column(char board[3][3]) {

    // res
    struct column_data res;
    res.winner = '-';
    // aux
    char possible_winner;
    // bool d_w = true; // diagonal winner
    
    // FILAS
    // me fijo si hay 3 iguales en las filas
    res.hay_column_winner = true; // column winner

    unsigned int i = 0;
    unsigned int j = 0;
    
    while (j<3) {
        // seteo como posible ganador al jugador de la primera columna
        possible_winner = board[0][j];

        // verifico si efectivamente es ganador, viendo si el resto de los lugares tambien estan ocupados por el
        while (i<3) {
            res.hay_column_winner = res.hay_column_winner && possible_winner == board[i][j];
            i = i+1;
        }
        i = 0; // reseteo el indice para columnas

        if (res.hay_column_winner) {
            res.winner = board[i][j];
            j=3; // ya hay ganador
        }
        else if (!res.hay_column_winner && j==2) {
            j=3; // no hay ganador pero estamos en la ultima fila y no queremos resetear hay_column_winner ni setear res.winner
        }
        else {
            j = j+1; // no hay ganador, voy a la siguiente fila
            res.hay_column_winner = true; // reseteo el auxiliar para hay_column_winner
        }
    }

    return res; 
}


// Diagonales TODO

int main(void) {
    char board[3][3] = {
        {'X','X','0'},
        {'0','X','X'},
        {'0','X','0'}
    };
    
    // struct row_data res = row(board);

    struct column_data res = column(board);

    // if (res.hay_row_winner) {
    //     printf("GAME OVER\n");
    //     printf("El ganador es %c", res.winner);
    // }
    // else {
    //     printf("No hay ganador aun.");
    // }

    if (res.hay_column_winner) {
        printf("GAME OVER\n");
        printf("El ganador es %c", res.winner);
    }
    else {
        printf("No hay ganador aun.");
    }

    return 1;
}