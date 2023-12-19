#include <stdio.h>
enum direction {
    UP,
    LEFT,
    DOWN,
    RIGHT
};

int main(void) {

    int i = direction.UP

 
    return 0;
}
void pacman_move (
    struct tile map[NUM_ROWS][NUM_COLS],
    struct pacman pacman,
    int *points,
    char character,
    int i
) {
    if (character == 'w' || character == 'a') {
        if (map[pacman.row][pacman.col].entity == WALL) {
            i = i + 1;
        }
    } else if (character == 's' || character == 'd') {
        if (map[pacman.row][pacman.col].entity == WALL) {
            i = i - 1;
        }       
    }
    if (map[pacman.row][pacman.col].entity == DOT) {
        *points = *points + 10;
    }

}
void ghost_move_to_left (
    struct enemy *enemy,
    struct tile map[NUM_ROWS][NUM_COLS],
) {
    map[*enemy.row][*enemy.col].enemy.is_present = FALSE;
    *enemy.col--;
    if (*enemy.col == -1) {
        *enemy.col = 9;
    }
    map[*enemy.row][*enemy.col].enemy.is_present = TRUE;  
}
void distance (
    int j,
    struct enemy enemy[5],
    struct pacman pacman
) {
    enemy[j].distance = sqrt((pacman.row - enemy[j].row)^2 + (pacman.col - enemy[j].col)^2)
}
void compare_d (int disatance, int distance_x) {
    if (distance_x >= disatance) {
        distance = distance_x;n
    }
}