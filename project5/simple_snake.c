// A simpler version of the famous Snake game!
//
// Written by Rory Golledge (z5308772) on 3/3/23
// Modified by Minyu Deng (z5495891
//

#include <stdio.h>

#define SIZE 8

enum land {
    NOT_VISITED,
    VISITED,
    SNAKE,
    APPLE
};

void initialise_map(enum land map[SIZE][SIZE]);
void print_map(enum land map[SIZE][SIZE]);

int main(void) {
    enum land map[SIZE][SIZE];
    initialise_map(map);
    printf("Welcome to Snake!\n");

    // TODO: Complete the program
    int apple_x;
    int apple_y;
    int snake_y;
    int snake_x;
    printf("Please enter apple location: ");
    scanf("%d %d", &apple_x, &apple_y);
    map[apple_x][apple_y] = APPLE;
    printf("Please enter snake location: ");
    scanf("%d %d", &snake_x, &snake_y);
    map[snake_x][snake_y] = SNAKE;
    print_map(map);
    
    while (map[snake_x][snake_y] != map[apple_x][apple_y]) {
        char dir;
        scanf(" %c", &dir);
        if (dir == 'r') {
            map[snake_x][snake_y + 1] = SNAKE;
            map[snake_x][snake_y] = VISITED;
            snake_y++; 
        } else if (dir == 'l') {
            map[snake_x][snake_y - 1] = SNAKE;
            map[snake_x][snake_y] = VISITED;
            snake_y--;
        } else if (dir == 'u') {
            map[snake_x - 1][snake_y] = SNAKE;
            map[snake_x][snake_y] = VISITED;
            snake_x--;
        } else if (dir == 'd') {
            map[snake_x + 1][snake_y] = SNAKE;
            map[snake_x][snake_y] = VISITED;
            snake_x++;
        }
        print_map(map);
    }
    printf("Chomp!\n");



    return 0;
}

/**
 * Initialises the given `map` such that all tiles are `NOT_VISITED`
 * 
 * Parameters:
 *     map - The map to initialise
 * 
 * Returns:
 *     Nothing
 */
void initialise_map(enum land map[SIZE][SIZE]) {
    for (int row = 0; row < SIZE; ++row) {
        for (int col = 0; col < SIZE; ++col) {
            map[row][col] = NOT_VISITED;
        }
    }
}

/**
 * Prints the given `map` such that all enum values are printed as nice
 * characters.
 * 
 * Parameters:
 *     map - The map to print out
 * 
 * Returns:
 *     Nothing
 */
void print_map(enum land map[SIZE][SIZE]) {
    for (int row = 0; row < SIZE; ++row) {
        for (int col = 0; col < SIZE; ++col) {
            if (map[row][col] == NOT_VISITED) {
                printf(". ");
            } else if (map[row][col] == VISITED) {
                printf("- ");
            } else if (map[row][col] == SNAKE) {
                printf("S ");
            } else if (map[row][col] == APPLE) {
                printf("A ");
            }
        }
        printf("\n");
    }
}
