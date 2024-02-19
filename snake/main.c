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
    int rows = 5, cols = 10, initial_length = 1, foodCount = 0;
    time_t t;
    char control_button = '\0';
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
    
    if (foodCount < 2){
        int row = myRand(1, rows - 2);
        int col = myRand(1, rows - 2);
        board_matrix[row][col] = 1;
    }

    
    while (control_button != 'q') {
        srand((unsigned) time(&t)); //rand seed
        
        printBoard(board_matrix, rows, cols, initial_length, snake_body, &foodCount);
        scanf("%c", &control_button);
        snakeMovement(control_button, snake_body, initial_length);

        fflush(stdin);
        if (board_matrix[snake_body[0].snake_x][snake_body[0].snake_y] == 1) {
            Snake_segment * snake_body = realloc(snake_body, sizeof(Snake_segment) * initial_length);
            if (snake_body == NULL) {
                return 0;
            }
            else {
                printf("eat\n");
                board_matrix[snake_body[0].snake_x][snake_body[0].snake_y] = 0;
                snake_body[initial_length].snake_x = snake_body[initial_length - 1].snake_x;
                snake_body[initial_length].snake_y = snake_body[initial_length - 1].snake_y;
            }
        }
        printf("Current- %d, x- %d, y- %d\n", board_matrix[snake_body[0].snake_x][snake_body[0].snake_y],snake_body[0].snake_x, snake_body[0].snake_y);
    }
    free(board_matrix);
    free(snake_body);
}


