#include <stdio.h>

#define LEN 10

enum direction{ HORIZ, VERT};
struct coord {
    int row;
    int col;
};

struct game {
    // has the enemy tried to hit this position
    int board[LEN][LEN];
};

struct ship {
    // has the ship been sunk
    int sunk;
    // how long is the ship
    int length;
    //
    enum direction dir;
    struct coord start_pos;
};

void initialise_board(int board[LEN][LEN], struct ship ship_1) {
    //we initialise all positions to 0
    for (int row = 0; row < LEN; row++) {
     for (int col = 0; col < LEN; col++) {
        // 0 is not his
        board[row][col] = 0;
     }
    }
// initialise ships data
if (ship_1.dir == HORIZ) {

    for (int col = ship_1.start_pos.col; 
        col < ship_1.start_pos.col + ship_1.length; col++){
        board[ship_1.start_pos.row][col] = 1;
    }
}
if (ship_1.dir == VERT) {
    
}
}



void print_board(int board[LEN][LEN], struct ship ship_1) {
    for (int row = 0; row < LEN; row++) {
     for (int col = 0; col < LEN; col++) {
        // 0 is not his
        printf("%d ", board[row][col]);
        }
        printf("\n");
    }
}

int main(void) {
    // initialise the game;
    struct game my_game;
    struct ship carrier;
    carrier.length = 5;
    carrier.dir = HORIZ;
    carrier.start_pos.col = 1;
    carrier.start_pos.row = 1;
    initialise_board(my_game.board, carrier);
    print_board(my_game.board, carrier);

    // create a ship


    return 0;
}