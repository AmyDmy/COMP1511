// cs_pacman
//
// This program was written by Minyu Deng (z5495891)
// 18.10.2023
//
// TODO: Description of program

#include <math.h>
#include <stdio.h>

// Provided constants
#define NUM_ROWS 8
#define NUM_COLS 10
#define NUM_FLOORS 5

#define TRUE 1
#define FALSE 0



// TODO: put your constants here 

// Provided enums
enum entity {
    EMPTY_ENTITY,
    WALL,
    DOT,
    APPLE,
    BANANA,
    POWER_UP,
    STAIRCASE_UP,
    STAIRCASE_DOWN,
};

enum direction {
    UP,
    LEFT,
    DOWN,
    RIGHT
};

enum power_dir {
    up,
    left,
    right,
    down
};
// Provided structs
struct enemy {
    enum direction move_direction;
    char direction;
    int is_present;
    // You will need to add more to this struct in stage 3
    int row;
    int col;
    int floor;
    int move_count;
    int count_1;
    int count_2;
    int count_3;
    int count_4;
    int count_5;
    int wall;
    enum power_dir power_dir;
};

struct tile {
    enum entity entity;
    struct enemy enemy;
    
};

// TODO: Put your structs here 
struct pacman {
    int row;
    int col;
};
struct power_up {
    int row;
    int col;
};
////////////////////////////////////////////////////////////////////////////////
////////////////////////  YOUR FUNCTION PROTOTYPE  /////////////////////////////
////////////////////////////////////////////////////////////////////////////////

// I write command before the function which I want to describe. 

// print the dot
// the side effect is it will cover the staircase up /down
// in the different floor
void print_dot (struct tile map[NUM_ROWS][NUM_COLS]);
// when input is W what will happen
void w_is_input (
    char input,
    struct tile map[NUM_ROWS][NUM_COLS],
    int *wall_count
);
// when input is A or B what will happen
void a_b_is_input (
    char input,
    struct tile map[NUM_ROWS][NUM_COLS],
    int *apple_count,
    int *banana_count
);
// when input is G what will happen
void g_is_input (
    char input,
    int *g_count,
    struct tile map[NUM_FLOORS][NUM_ROWS][NUM_COLS],
    struct enemy enemy[5],
    int i
);
// when input is P what will happen
void p_is_input (
    char input,
    struct tile map[NUM_ROWS][NUM_COLS],
    int *power_points
);
// when input is F what will happen
void f_is_input (
    char input,
    struct tile map[NUM_FLOORS][NUM_ROWS][NUM_COLS],
    int *floor,
    int *fcount,
    struct power_up *power_up
);
// Want to know whether the WALL is greater than the edge
void is_over(int *start_row, int *start_col, int *end_row, int *end_col);
// To find is the WALL is horizontal or vertical
void is_h_or_v (int start_row, int start_col, int end_row, int end_col);
// print the WALL
void print_wall (
    int start_row, 
    int start_col, 
    int end_row, 
    int end_col,
    struct tile map[NUM_ROWS][NUM_COLS]
);
// When the order is 'w''a''s''d', what pacman do.
void move_character (
    char character,
    struct pacman *pacman,
    struct tile map[NUM_ROWS][NUM_COLS],
    int *points,
    int *i
);
// if pacman meets the staircase_up / down, the floor will add 
void floorup (
    int *i, 
    struct tile map[NUM_ROWS][NUM_COLS],
    struct pacman *pacman
);
// the effect of when pacman meet apple or banana or power_up
void meet_features (
    struct tile map[NUM_ROWS][NUM_COLS],
    struct pacman pacman,
    int *power_exist,
    int *points
);
// when pacman move, the placement it have moved will replace by empty,
// except the staircase up / down.
void where_empty (
    char character,
    struct tile map[NUM_ROWS][NUM_COLS],
    struct pacman pacman
);
// Count the points when pacman meet dot and power_up
void dot_pu_points (
    int *points, 
    struct tile map[NUM_ROWS][NUM_COLS], 
    struct pacman *pacman
);
// The effect when pacman meet apple
void apple_effect (
    struct tile map[NUM_ROWS][NUM_COLS],
    int *points,
    struct pacman pacman
);
// The effect when pacman meet apple
void banana_effect (
    struct tile map[NUM_ROWS][NUM_COLS],
    int *points,
    struct pacman pacman
);
// The effect of banana in direction down
void banana_effect_down (
    int count,
    struct tile map[NUM_ROWS][NUM_COLS],
    int *points,
    struct pacman pacman
);
// The effect of banana in direction right
void banana_effect_right (
    int count,
    struct tile map[NUM_ROWS][NUM_COLS],
    int *points,
    struct pacman pacman
);
// The effect of banana in direction left
void banana_effect_left (
    int count,
    struct tile map[NUM_ROWS][NUM_COLS],
    int *points,
    struct pacman pacman
);
// When pacman eat banana, the banana effect is to clean the row
// and col. And when cleaning if meet the wall, it will stop
void is_wall_stop (
    int *count,
    int row,
    int col,
    struct pacman pacman, 
    struct tile map[NUM_ROWS][NUM_COLS]
);
// To clean the road and count points because of banana effect
void inside_for (
    int row,
    int col,
    struct pacman pacman, 
    struct tile map[NUM_ROWS][NUM_COLS],
    int *points
);
// ghost move to left
void ghost_move_to_left (
    struct enemy enemy[2],
    struct tile map[NUM_FLOORS][NUM_ROWS][NUM_COLS],
    int i,
    int g_count
);
// The function inside the 'ghost move to left' function in order to
// avoid over nesting.
void left_inside (
    struct tile map[NUM_FLOORS][NUM_ROWS][NUM_COLS],
    struct enemy enemy[5],
    int i,
    int g_count
);
// ghost move to down
void ghost_move_to_down (
    struct enemy enemy[2],
    struct tile map[NUM_FLOORS][NUM_ROWS][NUM_COLS],
    int i,
    int g_count
);
// The function inside the 'ghost move to down' function in order to
// avoid over nesting.
void down_inside (
    struct tile map[NUM_FLOORS][NUM_ROWS][NUM_COLS],
    struct enemy enemy[5],
    int i,
    int g_count
);
// ghost move to right
void ghost_move_to_right (
    struct enemy enemy[2],
    struct tile map[NUM_FLOORS][NUM_ROWS][NUM_COLS],
    int i,
    int g_count
);
// The function inside the 'ghost move to right' function in order to
// avoid over nesting.
void right_inside (
    struct tile map[NUM_FLOORS][NUM_ROWS][NUM_COLS],
    struct enemy enemy[5],
    int i,
    int g_count

);
// ghost move to up
void ghost_move_to_up (
    struct enemy enemy[2],
    struct tile map[NUM_FLOORS][NUM_ROWS][NUM_COLS],
    int i,
    int g_count
);
// The function inside the 'ghost move to right' function in order to
// avoid over nesting.
void up_inside (
    struct tile map[NUM_FLOORS][NUM_ROWS][NUM_COLS],
    struct enemy enemy[5],
    int i,
    int g_count

);
// When pacman meet the ghost, print Game over.
int is_hit (
    struct enemy enemy[5], 
    struct pacman pacman,
    int g_count, 
    int *points, 
    int power_exist
);
// When pacman eat the power up, pacman meet the ghost and eat it, 
// and get points. 
void runaway_ismeet (
    struct enemy enemy[5],
    struct pacman pacman,
    struct tile map[NUM_ROWS][NUM_COLS],
    int g_count,
    int *points,
    int *ghost_run_count
);
// To rearrange the order in struct enemy, the top-left is enemy[0] and 
// so on 
void ghost_order (struct enemy enemy[5], int g_count);
// There are two case to show how ghost move by whether pacman eat the power up.
void ghost_movement (
    int *power_exist,
    int *power_total_move,
    int *power_count,
    int g_count,
    int ghost_move[5],
    struct enemy enemy[5],
    struct tile map[NUM_FLOORS][NUM_ROWS][NUM_COLS],
    struct pacman pacman,
    int i,
    struct power_up power_up
);
// It is the function when pacman do not eat the power up.
void move_of_ghost (
    struct enemy enemy[5],
    int g_count,
    struct tile map[NUM_FLOORS][NUM_ROWS][NUM_COLS],
    int i,
    int ghost_move[5]
);
// The function inside the 'ghost_order' function in order to
// avoid over nesting.
void ghost_order_inside (struct enemy enemy[5], int g_count, int i, int j);
// when ghost move up to 10/8/6/4/2, it will change it direction 90 degrees.
void change_dir (
    struct enemy enemy[5],
    int g_count,
    struct tile map[NUM_FLOORS][NUM_ROWS][NUM_COLS],
    int i,
    int ghost_move[5]
);
// The function inside the 'is_still_run' function in order to
// avoid over nesting.
void runaway (
    struct enemy enemy[5],
    struct tile map[NUM_FLOORS][NUM_ROWS][NUM_COLS],
    int g_count,
    struct pacman pacman,
    int i,
    struct power_up power_up
);
// calculate the distance from pacman to ghost.
void calculate_d (
    double *distance_1,
    double *distance_2,
    double *distance_3,
    double *distance_4,
    int *up_dir,
    int *right_dir,
    int *left_dir,
    int *down_dir,
    int j,
    struct enemy enemy[5],
    struct tile map[NUM_FLOORS][NUM_ROWS][NUM_COLS],
    int g_count,
    int row,
    int col
);
// The function inside the 'runaway' function in order to
// avoid over nesting.
void runaway_inside (
    struct enemy enemy[5],
    struct tile map[NUM_FLOORS][NUM_ROWS][NUM_COLS],
    double *distance_1,
    double *distance_2,
    double *distance_3,
    double *distance_4,
    int* up_dir,
    int* right_dir,
    int* left_dir,
    int* down_dir,
    int j
);
// The movement of ghost when pacman do not eat power up
void ghost_normal_move (
    struct enemy enemy[5],
    struct tile map[NUM_FLOORS][NUM_ROWS][NUM_COLS],
    int g_count,
    int ghost_move[5]
);
// when power up is eaten, the movement of ghost
void is_still_run (
    int *power_total_move,
    int *power_exist,
    int *power_count,
    int g_count,
    struct enemy enemy[5],
    struct tile map[NUM_FLOORS][NUM_ROWS][NUM_COLS],
    struct pacman pacman,
    int i,
    struct power_up power_up
);
////////////////////////////////////////////////////////////////////////////////
////////////////////// PROVIDED FUNCTION PROTOTYPE  ////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void initialise_map(struct tile map[NUM_FLOORS][NUM_ROWS][NUM_COLS]);
void print_map(
    struct tile map[NUM_ROWS][NUM_COLS],
    int pacman_row,
    int pacman_col
);


int main(void) {
    // initialise all struct
    struct tile map[NUM_FLOORS][NUM_ROWS][NUM_COLS];
    initialise_map(map);
    struct pacman pacman;
    struct power_up power_up;
    struct enemy enemy[5] = {0};
    printf("Welcome to cs_pacman!\n");

    // TODO: Start Stage 1.1 here
    
    printf("Enter Pacman's starting coordinates: ");
    scanf(" %d %d", &pacman.row, &pacman.col);
    print_map(map[0], pacman.row, pacman.col);
    
    // Stage 1.2
    printf("Create the level: \n");
    char input;
    int wall_count = 0;
    int apple_count = 0;
    int banana_count = 0;
    int g_count = 0;
    int power_points = 0;
    int power_exist = 0;
    int power_count = 0;
    int ghost_move[5] = {10, 8, 6, 4, 2};
    char character;
    int points = 0;
    int power_total_move = 0;
    int ghost_run_count = 0;
    int floor = 0;
    int fcount = 0;
    scanf(" %c", &input);
    // to scan all level's feature
    for (int i = 0; i <= floor; i++) {
        print_dot (map[i]);
        
        while (input != 'S' && fcount == 0) {           
            w_is_input(input, map[i], &wall_count);
            a_b_is_input(input, map[i], &apple_count, &banana_count);
            g_is_input(input, &g_count, map, enemy, i);
            p_is_input(input, map[i], &power_points);
            f_is_input(input, map, &floor, &fcount, &power_up);
            scanf(" %c", &input);
        }
        fcount = 0;
    }
    print_map(map[0], pacman.row, pacman.col);
    // stage 2
    int i = 0;
    printf("Enter command: ");
    while (scanf(" %c", &character) == TRUE) {
        // scan 'wasd'
        move_character (character, &pacman, map[i], &points, &i);
        meet_features (map[i], pacman, &power_exist, &points);
        where_empty (character, map[i], pacman);
        // jugde whether to meet
        if ((is_hit(enemy, pacman, g_count, &points, power_exist)) == 0) {
            return 0;
        }
        runaway_ismeet (enemy ,pacman, map[i], g_count,
        &points, &ghost_run_count);
        //stage 3.1
        // count the points to know whether win the game
        if (points == (80 - apple_count - banana_count - wall_count
            - power_points - floor) * 10 + (apple_count * 20) 
            + (banana_count * 20) + (power_points * 50) + 
            (ghost_run_count * 100)) {
            printf("Game won! You got %d points.\n", points);
            return 0;
        }
        //3.2 3.3
        // about movement of ghost
        ghost_order (enemy, g_count);
        if (character == 'w' || character == 'a' 
            || character == 's' || character == 'd') {
            ghost_movement (&power_exist, &power_total_move, &power_count, 
            g_count, ghost_move, enemy, map, pacman, i, power_up);   
        }
        if ((is_hit(enemy, pacman, g_count, &points, power_exist)) == 0) {    
            return 0;
        } 
        print_map(map[i], pacman.row, pacman.col);        
        printf("Enter command: ");
    }
    return 0;
}

////////////////////////////////////////////////////////////////////////////////
/////////////////////////////  YOUR FUNCTIONS //////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

// TODO: Put your functions here

///////////////////////////////////////////////////////////////////////////////
/////////////////////////// PROVIDED FUNCTIONS  ///////////////////////////////
///////////////////////////////////////////////////////////////////////////////

void initialise_map(struct tile map[NUM_FLOORS][NUM_ROWS][NUM_COLS]) {
    for (int floor = 0; floor < NUM_FLOORS; floor++) {
        for (int row = 0; row < NUM_ROWS; row++) {
            for (int col = 0; col < NUM_COLS; col++) {
                map[floor][row][col].entity = EMPTY_ENTITY;
                map[floor][row][col].enemy.move_direction = LEFT;
                map[floor][row][col].enemy.is_present = FALSE;
            }
        }
    }
}
void initialise_enemy(struct enemy enemy[5]) {
    for (int i = 0; i < 5; i++) { 
        enemy[i].floor = 0;
        enemy[i].row = 0;
        enemy[i].col = 0;
        enemy[i].count_1 = 0;
        enemy[i].count_2 = 0;
        enemy[i].count_3 = 0;
        enemy[i].count_4 = 0;
        enemy[i].count_5 = 0;
        enemy[i].move_count = 0;
        enemy[i].wall = 0;
        enemy[i].power_dir = 0;
    }
}

void print_map(
    struct tile map[NUM_ROWS][NUM_COLS],
    int pacman_row,
    int pacman_col
) {
    for (int i = 0; i < NUM_COLS; i++) {
        printf("----");
    }
    printf("-\n");
    for (int row = 0; row < NUM_ROWS; row++) {
        printf("|");
        for (int col = 0; col < NUM_COLS; col++) {
            if (map[row][col].entity == WALL) {
                printf("|||");
            } else if (row == pacman_row && col == pacman_col) {
                printf("^_^");
            } else if (map[row][col].enemy.is_present == TRUE) {
                printf("O_O");
            } else if (map[row][col].entity == DOT) {
                printf(" . ");
            } else if (map[row][col].entity == APPLE) {
                printf(" a ");
            } else if (map[row][col].entity == BANANA) {
                printf(" b ");
            } else if (map[row][col].entity == POWER_UP) {
                printf("<o>");
            } else if (map[row][col].entity == STAIRCASE_UP) {
                printf("__/");
            } else if (map[row][col].entity == STAIRCASE_DOWN) {
                printf("\\__");
            } else {
                printf("   ");
            }

            printf("|");
        }
        printf("\n");
        for (int i = 0; i < NUM_COLS; i++) {
            printf("----");
        }
        printf("-\n");
    }
}

void print_dot (struct tile map[NUM_ROWS][NUM_COLS]) {
    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_COLS; j++) {
            if (map[i][j].entity != STAIRCASE_DOWN && 
            map[i][j].entity != STAIRCASE_UP) {
                map[i][j].entity = DOT;
            }
            
        }
    }

}
void w_is_input (
    char input,
    struct tile map[NUM_ROWS][NUM_COLS],
    int *wall_count
) {
    if (input == 'W') {
        int start_col;
        int start_row;
        int end_col;
        int end_row;
        scanf(" %d %d %d %d", &start_row, &start_col, &end_row, &end_col);
        is_h_or_v (start_row, start_col, end_row, end_col);
        print_wall (start_row, start_col, end_row, end_col, map);
        if ((end_row - start_row) == 0) {
            *wall_count = (end_col - start_col + 1);
        } else if ((end_col - start_col) == 0) {
            *wall_count = (end_row - start_row + 1);
        }
    }   
}
void a_b_is_input (
    char input,
    struct tile map[NUM_ROWS][NUM_COLS],
    int *apple_count,
    int *banana_count
) {
    int apple_col;
    int apple_row;
    int banana_row;
    int banana_col;
    if (input == 'A') {
        scanf(" %d %d", &apple_row, &apple_col);
        map[apple_row][apple_col].entity = APPLE;
        apple_count++;
    }
    if (input == 'B') {
        scanf(" %d %d", &banana_row, &banana_col);
        map[banana_row][banana_col].entity = BANANA;
        banana_count++;
    }
}
void g_is_input (
    char input,
    int *g_count,
    struct tile map[NUM_FLOORS][NUM_ROWS][NUM_COLS],
    struct enemy enemy[5],
    int i
) {
    if (input == 'G') {
        scanf(" %d %d %c", &enemy[*g_count].row, 
        &enemy[*g_count].col, &enemy[*g_count].direction);
        enemy[*g_count].floor = i;
        map[enemy[*g_count].floor][enemy[*g_count].row]
        [enemy[*g_count].col].enemy.is_present = TRUE;
        if (enemy[*g_count].direction == 'l') {
            map[enemy[*g_count].floor][enemy[*g_count].row]
            [enemy[*g_count].col].enemy.move_direction = LEFT;
        } else if (enemy[*g_count].direction == 'r') {
            map[enemy[*g_count].floor][enemy[*g_count].row]
            [enemy[*g_count].col].enemy.move_direction = RIGHT;
        } else if (enemy[*g_count].direction == 'u') {
            map[enemy[*g_count].floor][enemy[*g_count].row]
            [enemy[*g_count].col].enemy.move_direction = UP;
        } else if (enemy[*g_count].direction == 'd') {
            map[enemy[*g_count].floor][enemy[*g_count].row]
            [enemy[*g_count].col].enemy.move_direction = DOWN;
        }
        *g_count = *g_count + 1;
    } 
}
void p_is_input (
    char input,
    struct tile map[NUM_ROWS][NUM_COLS],
    int *power_points
) {
    int power_row;
    int power_col;
    if (input == 'P') {
        scanf(" %d %d", &power_row, &power_col);
        map[power_row][power_col].entity = POWER_UP;
        *power_points = *power_points + 1;
    }
}
void f_is_input (
    char input,
    struct tile map[NUM_FLOORS][NUM_ROWS][NUM_COLS],
    int *floor,
    int *fcount,
    struct power_up *power_up
) {
    int floor_row;
    int floor_col;
    if (input == 'F') {
        scanf(" %d %d", &floor_row, &floor_col);
        map[*floor][floor_row][floor_col].entity = STAIRCASE_UP;
        
        map[*floor + 1][floor_row][floor_col].entity = STAIRCASE_DOWN;
        *floor = *floor + 1;
        *fcount = *fcount + 1;
        power_up->row = floor_row;
        power_up->col = floor_col;
    }
}
void is_over(int *start_row, int *start_col, int *end_row, int *end_col) {
    if (*start_row < 0) {
        *start_row = 0;
    } else if (*start_row > (NUM_ROWS - 1)) {
        *start_row = (NUM_ROWS - 1);
    }
    if (*end_row > (NUM_ROWS - 1)) {
        *end_row = (NUM_ROWS - 1);
    } else if (*end_row < 0) {
        *end_row = 0;
    }
    if (*start_col < 0) {
        *start_col = 0;
    } else if (*start_col > (NUM_COLS - 1)) {
        *start_col = (NUM_COLS - 1);
    } 
    if (*end_col > (NUM_COLS - 1)) {
        *end_col = (NUM_COLS - 1);
    } else if (*end_col < 0) {
        *end_col = 0;
    }
   
}

void is_h_or_v (int start_row, int start_col, int end_row, int end_col) {
    if (start_row != end_row && start_col != end_col) {
        printf("Given wall is not horizontal or vertical!\n");
        return;
    }
}

void print_wall (
    int start_row, 
    int start_col, 
    int end_row, 
    int end_col,
    struct tile map[NUM_ROWS][NUM_COLS]
) {
    if ((start_row == end_row) && (start_row >= 0) 
        && (start_row <= (NUM_ROWS - 1))) {
        is_over(&start_row, &start_col, &end_row, &end_col);
        while (start_col <= end_col) {
            map[start_row][start_col].entity = WALL;
            start_col++;
        }
    } else if ((start_col == end_col) && (start_col >= 0)
        && (start_col <= (NUM_COLS - 1))) {
        is_over(&start_row, &start_col, &end_row, &end_col);
        while (start_row <= end_row) {
            map[start_row][start_col].entity = WALL;
            start_row++;
        }
    }
}
void dot_pu_points (
    int *points, 
    struct tile map[NUM_ROWS][NUM_COLS], 
    struct pacman *pacman
) {
    if (map[pacman->row][pacman->col].entity == DOT) {
        *points = *points + 10;
    }
    if (map[pacman->row][pacman->col].entity == POWER_UP) {
        *points = *points + 50;
    }
}
void move_character (
    char character,
    struct pacman *pacman,
    struct tile map[NUM_ROWS][NUM_COLS],
    int *points,
    int *i
) {
    if (character == 'w') {
        pacman->row = pacman->row - 1;
        if (pacman->row < 0) {
            pacman->row = (NUM_ROWS - 1);
        }
        if (map[pacman->row][pacman->col].entity == WALL) {
            pacman->row = pacman->row + 1;
        }
        floorup(i, map, pacman);
        dot_pu_points(points, map, pacman);
    } else if (character == 's') {
        pacman->row = pacman->row + 1;
        if (pacman->row == 8) {
            pacman->row = 0;
        }
        if (map[pacman->row][pacman->col].entity == WALL) {
            pacman->row = pacman->row - 1;
        }
        floorup(i, map, pacman);

        dot_pu_points(points, map, pacman);
    } else if (character == 'd') {
        pacman->col = pacman->col + 1;
        if (pacman->col == NUM_COLS) {
            pacman->col = 0;
        }
        if (map[pacman->row][pacman->col].entity == WALL) {
            pacman->col = pacman->col - 1;
        }
        floorup(i, map, pacman);

        dot_pu_points(points, map, pacman);
    } else if (character == 'a') {
        pacman->col = pacman->col - 1;
        if (pacman->col == -1) {
            pacman->col = (NUM_COLS - 1);
        }
        if (map[pacman->row][pacman->col].entity == WALL) {
            pacman->col = pacman->col + 1;
        } 
        
        floorup(i, map, pacman);
        dot_pu_points(points, map, pacman);
    } else if (character == 'p') {
        printf("You have %d points!\n", *points);
    }
}
void floorup (
    int *i, 
    struct tile map[NUM_ROWS][NUM_COLS],
    struct pacman *pacman
) {
    if (map[pacman->row][pacman->col].entity == STAIRCASE_UP) {
        *i = *i + 1;
    }
    if (map[pacman->row][pacman->col].entity == STAIRCASE_DOWN) {
        *i = *i - 1;
    }
}
void meet_features (
    struct tile map[NUM_ROWS][NUM_COLS],
    struct pacman pacman,
    int *power_exist,
    int *points
) {
    if (map[pacman.row][pacman.col].entity == APPLE) {
        apple_effect (map, points, pacman);
    }
    if (map[pacman.row][pacman.col].entity == BANANA) {
        banana_effect (map, points, pacman);
    }
    if (map[pacman.row][pacman.col].entity == POWER_UP) {
        *power_exist = *power_exist + 1;
    }
}
void where_empty (
    char character,
    struct tile map[NUM_ROWS][NUM_COLS],
    struct pacman pacman
) {
    if (character == 'w' || character == 'a' 
        || character == 's' || character == 'd') {
        if (map[pacman.row][pacman.col].entity != STAIRCASE_UP &&
        map[pacman.row][pacman.col].entity != STAIRCASE_DOWN) {
            map[pacman.row][pacman.col].entity = EMPTY_ENTITY;
        }
    }
}
//void movement_and_points()
void apple_effect (
    struct tile map[NUM_ROWS][NUM_COLS],
    int *points,
    struct pacman pacman
) { 
    int apple_limit_row = pacman.row + 2;
    int apple_limit_col = pacman.col + 2;            
    for (int i = (pacman.row - 2); i <= apple_limit_row; i++) {
        if (i < 0) {
            i = 0;
        }
        if (apple_limit_row > (NUM_ROWS - 1)) {
            apple_limit_row = (NUM_ROWS - 1);

        }
        for (int j = (pacman.col - 2); j <= apple_limit_col; j++) {
            
            if (j < 0) {
                j = 0;
            }
            if (apple_limit_col > (NUM_COLS - 1)) {
                apple_limit_col = (NUM_COLS - 1);
            }
            
            if (map[i][j].entity == WALL) {
                map[i][j].entity = EMPTY_ENTITY;
            } else if (map[i][j].entity == DOT) {
                map[i][j].entity = EMPTY_ENTITY;
                *points = *points + 10;
            } else if (map[i][j].entity == APPLE) {
                map[i][j].entity = EMPTY_ENTITY;
                *points = *points + 20;
            } else if (map[i][j].entity == BANANA) {
            
                map[i][j].entity = EMPTY_ENTITY;
                *points = *points + 20;
                
            } else {

            }
        }
    } 
    
}
void banana_effect (
    struct tile map[NUM_ROWS][NUM_COLS],
    int *points,
    struct pacman pacman
) {
    *points = *points + 20;
    int count = 0;
    banana_effect_down(count, map, points, pacman);
    count = 0;
    banana_effect_right(count, map, points, pacman);
    count = 0;
    banana_effect_left(count, map, points, pacman);
    count = 0;
    while (count != -1) {
        for (int i = (pacman.row - 1); i >= 0; i--) {
            if (count == 0) {
                is_wall_stop (&count, i, pacman.col, pacman, map);
                inside_for(i, pacman.col, pacman, map, points);
            }
        }
        count = -1;
    }
}
void banana_effect_down (
    int count,
    struct tile map[NUM_ROWS][NUM_COLS],
    int *points,
    struct pacman pacman
) {
    while (count != -1) {
        for (int i = (pacman.row + 1); i < NUM_ROWS; i++) {
            if (count == 0) {
                is_wall_stop (&count, i, pacman.col, pacman, map);          
                inside_for(i, pacman.col, pacman, map, points);  
            }
        }
        count = -1;
    }
}
void banana_effect_right (
    int count,
    struct tile map[NUM_ROWS][NUM_COLS],
    int *points,
    struct pacman pacman
) {
    while (count != -1) {
        for (int i = (pacman.col + 1); i < NUM_COLS; i++) {
            if (count == 0) {
                is_wall_stop(&count, pacman.row, i, pacman, map);   
                inside_for(pacman.row, i, pacman, map, points);
            }
        }
        count = -1;
    }
}
void banana_effect_left (
    int count,
    struct tile map[NUM_ROWS][NUM_COLS],
    int *points,
    struct pacman pacman
) {
    while (count != -1) {
        for (int i = (pacman.col - 1); i >= 0; i--) {
            if (count == 0) {
                is_wall_stop(&count, pacman.row, i, pacman, map);
                inside_for(pacman.row, i, pacman, map, points);
            }
        }
        count = -1;
    }
}
void is_wall_stop (
    int *count,
    int row,
    int col,
    struct pacman pacman, 
    struct tile map[NUM_ROWS][NUM_COLS]
) {
    if (map[row][col].entity == WALL) {
        *count = -1;
    } else if (map[row][col].entity != WALL) {
        *count = 0;
    }
     
}
void inside_for (
    int row,
    int col,
    struct pacman pacman, 
    struct tile map[NUM_ROWS][NUM_COLS],
    int *points
    
) {
    if (map[row][col].entity == DOT) {
        map[row][col].entity = EMPTY_ENTITY;
        *points = *points + 10;
    } else if (map[row][col].entity == APPLE) {
        map[row][col].entity = EMPTY_ENTITY;
        *points = *points + 20;
    } else if (map[row][col].entity == BANANA) {
        map[row][col].entity = EMPTY_ENTITY;
        *points = *points + 20;
    } else {

    }
}

void ghost_move_to_left (
    struct enemy enemy[5],
    struct tile map[NUM_FLOORS][NUM_ROWS][NUM_COLS],
    int i,
    int g_count
) {
    map[enemy[i].floor][enemy[i].row][enemy[i].col].enemy.is_present = FALSE;
    enemy[i].col--;
    if (enemy[i].col == -1) {
        enemy[i].col = 9;
    }
    if (map[enemy[i].floor][enemy[i].row][enemy[i].col].entity == WALL) {
        enemy[i].col++;
        enemy[i].wall++;
    }
    if (map[enemy[i].floor][enemy[i].row][enemy[i].col].entity 
        == STAIRCASE_UP) {
        enemy[i].floor = enemy[i].floor + 1;
        map[enemy[i].floor][enemy[i].row][enemy[i].col].enemy.is_present
        = TRUE;
    } else if (map[enemy[i].floor][enemy[i].row][enemy[i].col].entity 
        == STAIRCASE_DOWN) {
        enemy[i].floor = enemy[i].floor - 1;
        map[enemy[i].floor][enemy[i].row][enemy[i].col].enemy.is_present 
        = TRUE;
    } else {
        if ((enemy[i].floor == enemy[i + 1].floor) && ((i + 1) <= g_count)) {
            left_inside (map, enemy, i, g_count);
                
            map[enemy[i].floor][enemy[i].row][enemy[i].col].enemy.is_present
            = TRUE;
        }  
        map[enemy[i].floor][enemy[i].row][enemy[i].col].enemy.is_present = TRUE;
    }
}
void left_inside (
    struct tile map[NUM_FLOORS][NUM_ROWS][NUM_COLS],
    struct enemy enemy[5],
    int i,
    int g_count
) {
    if (i + 1 < g_count) {
        if (i == 0) {
            if (enemy[i].row == enemy[i + 1].row 
                && enemy[i].col == enemy[i + 1].col) {
                enemy[i].col++;
                enemy[i].wall++;
            }
        } else if (i > 0) {
            if ((enemy[i].row == enemy[i + 1].row 
                && enemy[i].col == enemy[i + 1].col) || 
                (enemy[i].row == enemy[i - 1].row 
                && enemy[i].col == enemy[i - 1].col )) {
                enemy[i].col++;
                enemy[i].wall++; 
            }
        }
    } else if (i + 1 == g_count && i != 0) {
        if (enemy[i].row == enemy[i - 1].row 
            && enemy[i].col == enemy[i - 1].col ) {
            enemy[i].col++;
            enemy[i].wall++;            
        }
    }
}
void ghost_move_to_down (
    struct enemy enemy[5],
    struct tile map[NUM_FLOORS][NUM_ROWS][NUM_COLS],
    int i,
    int g_count
) {
    map[enemy[i].floor][enemy[i].row][enemy[i].col].enemy.is_present = FALSE;
    enemy[i].row++;
    if (enemy[i].row == 8) {
        enemy[i].row = 0;
    }
    if (map[enemy[i].floor][enemy[i].row][enemy[i].col].entity == WALL) {
        enemy[i].row--;
        enemy[i].wall++;
    }
    if (map[enemy[i].floor][enemy[i].row][enemy[i].col].entity == 
        STAIRCASE_UP) {
        enemy[i].floor = enemy[i].floor + 1;
        map[enemy[i].floor][enemy[i].row][enemy[i].col].enemy.is_present = TRUE;
    } else if (map[enemy[i].floor][enemy[i].row][enemy[i].col].entity 
        == STAIRCASE_DOWN) {
        enemy[i].floor = enemy[i].floor - 1;
        map[enemy[i].floor][enemy[i].row][enemy[i].col].enemy.is_present = TRUE;
    } else {
        if ((enemy[i].floor == enemy[i + 1].floor) && ((i + 1) <= g_count)) {
            down_inside (map, enemy, i, g_count);
            map[enemy[i].floor][enemy[i].row][enemy[i].col].enemy.is_present
            = TRUE;
        }
        map[enemy[i].floor][enemy[i].row][enemy[i].col].enemy.is_present = TRUE;
    }
}
void down_inside (
    struct tile map[NUM_FLOORS][NUM_ROWS][NUM_COLS],
    struct enemy enemy[5],
    int i,
    int g_count

) {
    if (i + 1 < g_count) {
        if (i == 0) {
            if (enemy[i].row == enemy[i + 1].row 
                && enemy[i].col == enemy[i + 1].col) {
                enemy[i].row--;
                enemy[i].wall++;
            }
        } else if (i > 0) {
            if ((enemy[i].row == enemy[i + 1].row 
                && enemy[i].col == enemy[i + 1].col) || 
                (enemy[i].row == enemy[i - 1].row 
                && enemy[i].col == enemy[i - 1].col )) {
                enemy[i].row--;
                enemy[i].wall++; 
            }
        }
    } else if (i + 1 == g_count && i != 0) {
        if (enemy[i].row == enemy[i - 1].row 
            && enemy[i].col == enemy[i - 1].col ) {
            enemy[i].row--;
            enemy[i].wall++;
        }
    }
}
void ghost_move_to_up (
    struct enemy enemy[5],
    struct tile map[NUM_FLOORS][NUM_ROWS][NUM_COLS],
    int i,
    int g_count
) {
    map[enemy[i].floor][enemy[i].row][enemy[i].col].enemy.is_present = FALSE;
    enemy[i].row--;
    if (enemy[i].row == -1) {
        enemy[i].row = 7;
    }
    if (map[enemy[i].floor][enemy[i].row][enemy[i].col].entity == WALL) {
        enemy[i].row++;
        enemy[i].wall++;
    }
    if (map[enemy[i].floor][enemy[i].row][enemy[i].col].entity == 
        STAIRCASE_UP) {
        enemy[i].floor = enemy[i].floor + 1;
        map[enemy[i].floor][enemy[i].row][enemy[i].col].enemy.is_present = TRUE;
    } else if (map[enemy[i].floor][enemy[i].row][enemy[i].col].entity 
        == STAIRCASE_DOWN) {
        enemy[i].floor = enemy[i].floor - 1;
        map[enemy[i].floor][enemy[i].row][enemy[i].col].enemy.is_present = TRUE;
    } else {
        if ((enemy[i].floor == enemy[i + 1].floor) && ((i + 1) <= g_count)) {
            up_inside (map, enemy, i, g_count);
            map[enemy[i].floor][enemy[i].row][enemy[i].col].enemy.is_present 
            = TRUE;
        }
        map[enemy[i].floor][enemy[i].row][enemy[i].col].enemy.is_present = TRUE;
    }
}
void up_inside (
    struct tile map[NUM_FLOORS][NUM_ROWS][NUM_COLS],
    struct enemy enemy[5],
    int i,
    int g_count

) {
    if (i + 1 < g_count) {
        if (i == 0) {
            if (enemy[i].row == enemy[i + 1].row 
                && enemy[i].col == enemy[i + 1].col) {
                enemy[i].row++;
                enemy[i].wall++;
            }
        } else if (i > 0) {
            if ((enemy[i].row == enemy[i + 1].row 
                && enemy[i].col == enemy[i + 1].col) || 
                (enemy[i].row == enemy[i - 1].row 
                && enemy[i].col == enemy[i - 1].col )) {
                enemy[i].row++;
                enemy[i].wall++; 
            }
        }
    } else if (i + 1 == g_count && i != 0) {
        if (enemy[i].row == enemy[i - 1].row 
            && enemy[i].col == enemy[i - 1].col ) {
            enemy[i].row++;
            enemy[i].wall++;
        }
    }
}
void ghost_move_to_right (
    struct enemy enemy[5],
    struct tile map[NUM_FLOORS][NUM_ROWS][NUM_COLS],
    int i,
    int g_count
) {
    map[enemy[i].floor][enemy[i].row][enemy[i].col].enemy.is_present = FALSE;
    enemy[i].col++;
    if (enemy[i].col == 10) {
        enemy[i].col = 0;
    }
    if (map[enemy[i].floor][enemy[i].row][enemy[i].col].entity == WALL) {
        enemy[i].col--;
        enemy[i].wall++;
    }
    if (map[enemy[i].floor][enemy[i].row][enemy[i].col].entity 
        == STAIRCASE_UP) {
        enemy[i].floor = enemy[i].floor + 1;
        map[enemy[i].floor][enemy[i].row][enemy[i].col].enemy.is_present = TRUE;
    } else if (map[enemy[i].floor][enemy[i].row][enemy[i].col].entity 
        == STAIRCASE_DOWN) {
        enemy[i].floor = enemy[i].floor - 1;
        map[enemy[i].floor][enemy[i].row][enemy[i].col].enemy.is_present = TRUE;
    } else {
        if ((enemy[i].floor == enemy[i + 1].floor) && ((i + 1) <= g_count)) {
            
            right_inside (map, enemy, i, g_count);
            map[enemy[i].floor][enemy[i].row][enemy[i].col].enemy.is_present 
            = TRUE;
        }  
        map[enemy[i].floor][enemy[i].row][enemy[i].col].enemy.is_present = TRUE;
    }
}
void right_inside (
    struct tile map[NUM_FLOORS][NUM_ROWS][NUM_COLS],
    struct enemy enemy[5],
    int i,
    int g_count

) {
    if (i + 1 < g_count) {
        if (i == 0) {
            if (enemy[i].row == enemy[i + 1].row 
                && enemy[i].col == enemy[i + 1].col) {
                enemy[i].col--;
                enemy[i].wall++;
            }
        } else if (i > 0) {
            if ((enemy[i].row == enemy[i + 1].row 
                && enemy[i].col == enemy[i + 1].col) ||
                (enemy[i].row == enemy[i - 1].row 
                && enemy[i].col == enemy[i - 1].col )) {
                enemy[i].col--;
                enemy[i].wall++; 
            }
        }
    } else if (i + 1 == g_count && i != 0) {
        if (enemy[i].row == enemy[i - 1].row 
            && enemy[i].col == enemy[i - 1].col ) {
            enemy[i].col--;
            enemy[i].wall++;
        }
    }
}
int is_hit (
    struct enemy enemy[5], 
    struct pacman pacman,
    int g_count, 
    int *points, 
    int power_exist
) {
    for (int i = 0; i < g_count; i++) {
        if (power_exist == 0) {
            if (enemy[i].row == pacman.row && enemy[i].col == pacman.col) {
                printf("Game over! You got %d points.\n", *points);
                return 0;
            }
        }
    }
    return 1;
}
void runaway_ismeet (
    struct enemy enemy[5],
    struct pacman pacman,
    struct tile map[NUM_ROWS][NUM_COLS],
    int g_count,
    int *points,
    int *ghost_run_count
) {
    for (int i = 0; i < g_count; i++) {
        if (enemy[i].row == pacman.row && enemy[i].col == pacman.col) {
            *points = *points + 100;
            *ghost_run_count = *ghost_run_count + 1;
            map[enemy[i].row][enemy[i].col].enemy.is_present = FALSE;
            enemy[i].row = 0; 
            enemy[i].col = 0;
        }
    }
}
void ghost_order (struct enemy enemy[5], int g_count) {
    for (int i = 0; i < (g_count - 2); i++) {
        for (int j = 1; (i + j) < g_count; j++ ) {
            if (enemy[i].row >= enemy[i + j].row) {
                ghost_order_inside (enemy, g_count, i, j);
            } 
        }
    }
}
void ghost_movement (
    int *power_exist,
    int *power_total_move,
    int *power_count,
    int g_count,
    int ghost_move[5],
    struct enemy enemy[5],
    struct tile map[NUM_FLOORS][NUM_ROWS][NUM_COLS],
    struct pacman pacman,
    int i,
    struct power_up power_up
) {
    if (*power_exist == 0) {
        ghost_normal_move(enemy, map, g_count, ghost_move);     
    } else {
        is_still_run (power_total_move, power_exist, power_count,
        g_count, enemy, map, pacman, i, power_up);
    }
}
void is_still_run (
    int *power_total_move,
    int *power_exist,
    int *power_count,
    int g_count,
    struct enemy enemy[5],
    struct tile map[NUM_FLOORS][NUM_ROWS][NUM_COLS],
    struct pacman pacman,
    int i,
    struct power_up power_up
) {
    *power_total_move = *power_exist * 10;
    if (*power_count < *power_total_move) {
        runaway (enemy, map, g_count, pacman, i, power_up);
        *power_count = *power_count + 1;
    }
    if (*power_count == *power_total_move) {
        *power_exist = 0;
    }
}
void ghost_normal_move (
    struct enemy enemy[5],
    struct tile map[NUM_FLOORS][NUM_ROWS][NUM_COLS],
    int g_count,
    int ghost_move[5]
) {
    for (int i = 0; i < g_count; i++) {
        if (map[enemy[i].floor][enemy[i].row][enemy[i].col].enemy.is_present 
            == TRUE) {
            move_of_ghost(enemy, g_count, map, i, ghost_move);
            change_dir (enemy, g_count, map, i, ghost_move);
        }
    }
}
void move_of_ghost (
    struct enemy enemy[5],
    int g_count,
    struct tile map[NUM_FLOORS][NUM_ROWS][NUM_COLS],
    int i,
    int ghost_move[5]
) {
    if (map[enemy[i].floor][enemy[i].row][enemy[i].col].enemy.move_direction 
        == LEFT) {
        if (enemy[i].count_1 <= ghost_move[enemy[i].move_count]) {
            ghost_move_to_left(enemy, map, i, g_count);
            enemy[i].count_1++;
            enemy[i].count_5++; 
            map[enemy[i].floor][enemy[i].row][enemy[i].col].enemy.move_direction
            = LEFT;      
        }
    } else if (map[enemy[i].floor][enemy[i].row]
        [enemy[i].col].enemy.move_direction == DOWN) {
        if (enemy[i].count_2 <= ghost_move[enemy[i].move_count]) {
            ghost_move_to_down(enemy, map, i, g_count);
            enemy[i].count_2++;
            enemy[i].count_5++;
            map[enemy[i].floor][enemy[i].row]
            [enemy[i].col].enemy.move_direction = DOWN;
        }
    } else if (map[enemy[i].floor][enemy[i].row]
        [enemy[i].col].enemy.move_direction == RIGHT) {
        if (enemy[i].count_3 <= ghost_move[enemy[i].move_count]) {
            ghost_move_to_right(enemy, map, i, g_count);
            enemy[i].count_3++;
            enemy[i].count_5++;
            map[enemy[i].floor][enemy[i].row]
            [enemy[i].col].enemy.move_direction = RIGHT;
        }
    } else if (map[enemy[i].floor][enemy[i].row]
        [enemy[i].col].enemy.move_direction == UP) {
        if (enemy[i].count_4 <= ghost_move[enemy[i].move_count]) {
            ghost_move_to_up(enemy, map, i, g_count);
            enemy[i].count_4++;
            enemy[i].count_5++;
            map[enemy[i].floor][enemy[i].row]
            [enemy[i].col].enemy.move_direction = UP;
        }
    }
    
}
void ghost_order_inside (struct enemy enemy[5], int g_count, int i, int j) {
    if (enemy[i].col >= enemy[i + j].col) {
        enemy[g_count].row = enemy[i].row;
        enemy[g_count].col = enemy[i].col;
        enemy[g_count].floor = enemy[i].floor;
        enemy[i].row = enemy[i + j].row;
        enemy[i].col = enemy[i + j].col;
        enemy[i].floor = enemy[i + j].floor;
        enemy[i + j].row = enemy[g_count].row;
        enemy[i + j].col = enemy[g_count].col;
        enemy[i + j].floor = enemy[g_count].floor;
    }
}
void change_dir (
    struct enemy enemy[5],
    int g_count,
    struct tile map[NUM_FLOORS][NUM_ROWS][NUM_COLS],
    int i,
    int ghost_move[5]
) {
    if (enemy[i].count_5 == ghost_move[enemy[i].move_count] 
        || enemy[i].wall == 1) {
        map[enemy[i].floor][enemy[i].row]
        [enemy[i].col].enemy.move_direction++;
        if (map[enemy[i].floor][enemy[i].row]
            [enemy[i].col].enemy.move_direction == 4) {
            map[enemy[i].floor][enemy[i].row]
            [enemy[i].col].enemy.move_direction = 0;
        }
        enemy[i].count_5 = 0;
        enemy[i].move_count++;
        if (enemy[i].move_count == 4) {
            enemy[i].count_1 = 0;
            enemy[i].count_2 = 0;
            enemy[i].count_3 = 0;
            enemy[i].count_4 = 0;
        }
        if (enemy[i].move_count == 5) {
            enemy[i].move_count = 0;  
        }
        if (enemy[i].wall == 1) {
            enemy[i].wall = 0;
        }
    }
}
void runaway (
    struct enemy enemy[5],
    struct tile map[NUM_FLOORS][NUM_ROWS][NUM_COLS],
    int g_count,
    struct pacman pacman,
    int i,
    struct power_up power_up
) {


    for (int j = 0; j < g_count; j++) {
        if (map[enemy[j].floor][enemy[j].row]
            [enemy[j].col].enemy.is_present == TRUE) {
            map[enemy[j].floor][enemy[j].row]
            [enemy[j].col].enemy.is_present = FALSE;
            double distance_1 = 0;
            double distance_2 = 0;
            double distance_3 = 0;
            double distance_4 = 0;
            int up_dir = 0;
            int right_dir = 0;
            int left_dir = 0;
            int down_dir = 0;
            if (enemy[j].floor == i) {
                calculate_d (&distance_1, &distance_2, &distance_3, 
                &distance_4, &up_dir, &right_dir, &left_dir, &down_dir, 
                j, enemy, map, g_count, pacman.row, pacman.col);
                runaway_inside (enemy, map, &distance_1, &distance_2, 
                &distance_3, &distance_4, &up_dir, &right_dir,
                &left_dir, &down_dir, j);
                map[enemy[j].floor][enemy[j].row]
                [enemy[j].col].enemy.is_present = TRUE;
            } else {
                calculate_d (&distance_1, &distance_2, &distance_3, 
                &distance_4, &up_dir, &right_dir, 
                &left_dir, &down_dir, j, enemy, map, g_count, 
                power_up.row, power_up.col);
                runaway_inside (enemy, map, &distance_1, &distance_2, 
                &distance_3, &distance_4, &up_dir, &right_dir,
                &left_dir, &down_dir, j);
                map[enemy[j].floor][enemy[j].row]
                [enemy[j].col].enemy.is_present = TRUE;
            }
        }
    }
}
void calculate_d (
    double *distance_1,
    double *distance_2,
    double *distance_3,
    double *distance_4,
    int *up_dir,
    int *right_dir,
    int *left_dir,
    int *down_dir,
    int j,
    struct enemy enemy[5],
    struct tile map[NUM_FLOORS][NUM_ROWS][NUM_COLS],
    int g_count,
    int row,
    int col

) {
    *up_dir = enemy[j].row - 1;
    if (*up_dir == -1) {
        *up_dir = 7;
    }
    *distance_1 = sqrt(pow((row - *up_dir), 2) 
    + pow((col - enemy[j].col), 2));
    if (map[enemy[j].floor][*up_dir][enemy[j].col].entity == WALL) {
        *distance_1 = 0;
    }       

    *left_dir = enemy[j].col - 1;
    if (*left_dir == -1) {
        *left_dir = 9;
    }
    *distance_2 = sqrt(pow((row - enemy[j].row), 2) 
    + pow((col - *left_dir), 2));
    if (map[enemy[j].floor][enemy[j].row][*left_dir].entity == WALL) {
        *distance_2 = 0;
    } 

    *right_dir = enemy[j].col + 1;
    if (*right_dir == 10) {
        *right_dir = 0;
    }
    *distance_3 = sqrt(pow((row - enemy[j].row), 2) 
    + pow((col - *right_dir), 2));
    if (map[enemy[j].floor][enemy[j].row][*right_dir].entity == WALL) {
        *distance_3 = 0;
    } 

    *down_dir = enemy[j].row + 1;
    if (*down_dir == 8) {
        *down_dir = 0;
    }
    *distance_4 = sqrt(pow((row - *down_dir), 2) 
    + pow((col - enemy[j].col), 2));
    if (map[enemy[j].floor][*down_dir][enemy[j].col].entity == WALL) {
        *distance_4 = 0;
    }
    // printf("d1 row= %f\n", pow((row - *up_dir), 2) );
    // printf("d1 col= %f\n", pow((col - enemy[j].col), 2));
    // printf("d4 row= %f\n", pow((row - *down_dir), 2) );
    // printf("d4 col= %f\n", pow((col - enemy[j].col), 2));
}
void runaway_inside (
    struct enemy enemy[5],
    struct tile map[NUM_FLOORS][NUM_ROWS][NUM_COLS],
    double *distance_1,
    double *distance_2,
    double *distance_3,
    double *distance_4,
    int *up_dir,
    int *right_dir,
    int *left_dir,
    int *down_dir,
    int j
) {
    if (*distance_1 >= *distance_4) {
        if ((*distance_1 >= *distance_3) && (*distance_1 >= *distance_2)) {
            map[enemy[j].floor][*up_dir][enemy[j].col].enemy.move_direction = map
            [enemy[j].floor][enemy[j].row][enemy[j].col].enemy.move_direction;
            enemy[j].row = *up_dir;
        } else if (*distance_3 > *distance_2) {
            map[enemy[j].floor][enemy[j].row][*right_dir].enemy.move_direction = map
                [enemy[j].floor][enemy[j].row][enemy[j].col].enemy.move_direction;
            enemy[j].col = *right_dir;
        } else if (*distance_2 > *distance_1) {
            map[enemy[j].floor][enemy[j].row][*left_dir].enemy.move_direction = map
            [enemy[j].floor][enemy[j].row][enemy[j].col].enemy.move_direction;
            enemy[j].col = *left_dir; 
        } else if (*distance_3 > *distance_1) {
            map[enemy[j].floor][enemy[j].row][*right_dir].enemy.move_direction = map
            [enemy[j].floor][enemy[j].row][enemy[j].col].enemy.move_direction;
            enemy[j].col = *right_dir;
        }
    } else if (*distance_1 <= *distance_4) {
        if ((*distance_4 > *distance_3) && (*distance_4 > *distance_2)) {   
            map[enemy[j].floor][*down_dir][enemy[j].col].enemy.move_direction = map
            [enemy[j].floor][enemy[j].row][enemy[j].col].enemy.move_direction;
            enemy[j].row = *down_dir;     
        } else if (*distance_3 >= *distance_2 && *distance_3 != 0) {
            map[enemy[j].floor][enemy[j].row][*right_dir].enemy.move_direction = map
            [enemy[j].floor][enemy[j].row][enemy[j].col].enemy.move_direction;
            enemy[j].col = *right_dir;
        } else if (*distance_2 >= *distance_4 && *distance_2 != 0) {
            map[enemy[j].floor][enemy[j].row][*left_dir].enemy.move_direction = map
            [enemy[j].floor][enemy[j].row][enemy[j].col].enemy.move_direction;
            enemy[j].col = *left_dir;
        } else if (*distance_3 >= *distance_4 && *distance_3 != 0) {
            map[enemy[j].floor][enemy[j].row][*right_dir].enemy.move_direction = map
            [enemy[j].floor][enemy[j].row][enemy[j].col].enemy.move_direction;
            enemy[j].col = *right_dir;
        }
    }
}

