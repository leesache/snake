//
//  main.c
//  snake
//
//  Created by Рушан Валимханов on 19.02.2024.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Header.h"
#include "snake.h"

int main(int argc, const char * argv[]) {
    int rows = 10, cols = 20, initial_length = 1;;
    time_t t;
    // snake initialization
    Snake_segment *snake_body = malloc(initial_length * sizeof(Snake_segment));
    snake_body[0].snake_x = rows / 2; //
    snake_body[0].snake_y = cols / 2; // starting point of snake
    
    int ** board_matrix = malloc(rows * sizeof(int*)); //allocating memory
    for (int i = 0; i < rows; i++){
        board_matrix[i] = malloc(cols * sizeof(int));
    }
    for (int i = 0; i < rows; i++){ // initialization of matrix with nulls
        for (int j = 0; j < cols; j++){
            board_matrix[i][j] = 0;
        }
    }
    srand((unsigned) time(&t)); //rand seed
    
    
    int row = myRand(1, rows - 2);
    int col = myRand(1, rows - 2);
    board_matrix[row][col] = 1;
    

    printBoard(board_matrix, rows, cols, initial_length, snake_body);
    printf("%d and %d", snake_body[0].snake_x, snake_body[0].snake_y);
}


