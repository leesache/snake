//
//  Header.h
//  snake
//
//  Created by Рушан Валимханов on 19.02.2024.
//

#ifndef Header_h
#define Header_h
#include "snake.h"


void printBoard (int ** board, int rows, int cols, int snakeLength, struct Snake * Snake_segment, int * food){
    int count = 0;
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            if (Snake_segment[count].snake_x == i && Snake_segment[count].snake_y == j){
                printf("<");
                count++;
                continue;
            }
            if (i == 0 || j == 0 || i == rows - 1 || j == cols - 1){
                printf("*");
            }
            else if (board[i][j] == 1){
                printf("0");
                *food += 1;
            }
            else printf(" ");
        }
        printf("\n");
    }
}

int myRand(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void snakeMovement (char c, struct Snake * Snake_segment, int length){
    for (int i = 0; i < length; i++)
        
    switch (c) {
        case 'w':
            Snake_segment[i].snake_x -= 1;
            break;
        case 'a':
            Snake_segment[i].snake_y -= 1;
            break;
        case 's':
            Snake_segment[i].snake_x += 1;
            break;
        case 'd':
            Snake_segment[i].snake_y += 1;
            break;

        default:
            break;
    }
    
}

#endif /* Header_h */
