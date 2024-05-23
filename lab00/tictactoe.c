#include <stdlib.h>  /* exit() y EXIT_FAILURE */
#include <stdio.h>   /* printf(), scanf()     */
#include <stdbool.h> /* Tipo bool             */

#include <assert.h>  /* assert() */

#define CELL_MAX (4 * 4 - 1)

void print_sep(int length) {
    printf("\t ");
    for (int i=0; i < length;i++) printf("................");
    printf("\n");

}

void print_board(char board[4][4])
{
    int cell = 0;

    print_sep(4);
    for (int row = 0; row < 4; ++row) {
        for (int column = 0; column < 4; ++column) {
            printf("\t | %d: %c ", cell, board[row][column]);
            ++cell;
        }
        printf("\t | \n");
        print_sep(4);
    }
}

char get_winner(char board[4][4]) {
    char winner = '-';

    unsigned int i = 0;
    unsigned int j = 0;

    // filas
    while (i < 4 && winner == '-') {
        bool row_winner = true;
        
        while (j < 4 && row_winner) {
            row_winner = row_winner && board[i][0] == board[i][j] && board[i][j] != '-';
            j += 1;
        }
        j=0;

        if (row_winner) {
            winner = board[i][j];
        }
        else {
            i += 1;
        }
    }
    
    i=0;
    j=0;

    // columnas
    while (j < 4 && winner == '-') {
        bool col_winner = true;
        while (i < 4) {
            col_winner = col_winner && board[0][j] == board[i][j] && board[i][j] != '-';
            i += 1;
        }
        i=0;

        if (col_winner) {
            winner = board[i][j];
        }
        else {
            j += 1;
        }
    }
    
    // diagonal izq -> j = i 
    i=0;
    j=0;
    bool diag_winner = true;
    while (i<4 && j<4 && winner == '-') {
        diag_winner = diag_winner && board[i][j] == board[0][0] && board[i][j] != '-';

        i+=1;
        j+=1;
    }
    
    if (diag_winner) {
        winner = board[0][0];
    }
    else {
        diag_winner = true;
    }
    
    // diagonal derecha -> j = i^-1
    i=0;
    j=3;
    
    while (i<4 && j!=0 && winner == '-') {
        diag_winner = diag_winner && board[i][j] == board[0][3] && board[i][j] != '-';

        i+=1;
        j-=1;
    }

    return winner;
}

bool has_free_cell(char board[4][4])
{
    bool free_cell=false;
    unsigned int i = 0;
    unsigned int j = 0;

    while (i<4 && !free_cell) {
        while (j<4 && !free_cell) {
            free_cell = free_cell || board[i][j] == '-'; 
            j+=1;
        }
        j=0;
        i+=1;
    }

    return free_cell;
}

int main(void)
{
    printf("TicTacToe Completo :)\n");

    char board[4][4] = {
        { '-', '-', '-', '-'},
        { '-', '-', '-', '-'},
        { '-', '-', '-', '-'},
        { '-', '-', '-', '-'}
    };

    char turn = 'X';
    char winner = '-';
    
    int cell = 0;
    while (winner == '-' && has_free_cell(board)) {
        print_board(board);
        printf("\nTurno %c - Elija posición (número del 0 al %d): ", turn,
               CELL_MAX);
        int scanf_result = scanf("%d", &cell);
        if (scanf_result <= 0) {
            printf("Error al leer un número desde teclado\n");
            exit(EXIT_FAILURE);
        }
        if (cell >= 0 && cell <= CELL_MAX) {
            int row = cell / 4;
            int colum = cell % 4;
            if (board[row][colum] == '-') {
                board[row][colum] = turn;
                turn = turn == 'X' ? 'O' : 'X';
                winner = get_winner(board);
            } else {
                printf("\nCelda ocupada!\n");
            }
        } else {
            printf("\nCelda inválida!\n");
        }
    }
    print_board(board);
    if (winner == '-') {
        printf("Empate!\n");
    } else {
        printf("Ganó %c\n", winner);
    }
    return 0;
}
