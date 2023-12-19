// Program name
//
// This program was written by Minyu Deng z5495891
// on 1/11/2023
//
// TODO: Description of program


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

////////////////////////////////////////////////////////////////////////////////
///////////////////////////      Constants       ///////////////////////////////
////////////////////////////////////////////////////////////////////////////////

// Provided constants
#define MAX_STR_LEN 20
#define HELP_COMMAND '?'

// Provided enums
// This enum only has to be used in Stage 3.1 onwards
enum attempt_type {FIRST_GO, SUCCESS, FAIL, INVALID_TYPE};

// TODO: Your #defines/enums can go here:

////////////////////////////////////////////////////////////////////////////////
//////////////////////////  USER DEFINED TYPES  ////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

// TODO: Any additional structs you want to add can go here:

// Provided structs

// Represents a single climbing route in the logbook
struct route {
    // The name of the climbing route
    char name[MAX_STR_LEN];
    // The difficulty of the route
    int difficulty;
    // The length of the route in metres
    int length;
    // A pointer to the next `struct route` in the logbook 
    struct route *next;
    struct attempt *attempts;
};

// Represents the logbook that contains info on each climbing route
struct logbook {
    // A pointer to the first `struct route` in the list
    struct route *routes;
    int attempts_count;
};

struct attempt {
    char climber[MAX_STR_LEN];
    enum attempt_type type;
    int rating;
    struct attempt *next;
    int attempt_num;
};

struct leaderbd {
    char climber[MAX_STR_LEN];
    int go_first_fl;
    int success_count;
    int total_count;
    struct leaderbd *next;
};
// add a attempts_count to struct logbook - stores how many attempts there have been
// add a attempt_no to struct attempt - stores which attempt it is (when it was added)
// attempts_count can start at 0
// when you add an attempt, increment attempts_count
// then, set the new_attempt->attempt_no = logbook->attempts_count
// every attempt will show when it was added
// 
 
////////////////////////////////////////////////////////////////////////////////
////////////////////// PROVIDED FUNCTION PROTOTYPE  ////////////////////////////
////////////////////////////////////////////////////////////////////////////////

void print_usage(void); 
void print_one_route(int position, struct route *route);
void scan_string(char string[MAX_STR_LEN]);
enum attempt_type scan_attempt_type();
void print_one_attempt(
    char climber[MAX_STR_LEN], 
    enum attempt_type type, 
    int rating
);

// Additional provided function prototypes
// You won't need to use these functions!
// We use them just to implement some of the provided helper functions.
int scan_token(char *buffer, int buffer_size);
enum attempt_type string_to_type(char *type_str);
void type_to_string(char *buf, enum attempt_type type);

////////////////////////////////////////////////////////////////////////////////
////////////////////////  YOUR FUNCTION PROTOTYPE  /////////////////////////////
////////////////////////////////////////////////////////////////////////////////

struct logbook *create_logbook();
struct route *create_route(
    char name[MAX_STR_LEN], 
    int difficulty, 
    int length
);

// TODO: Put your function prototypes here
// The function is used to free the logbook
void free_logbook(struct logbook *logbook);
// The function is used to find whether there is error with difficulty and length
struct route *is_wrong_or_not (struct logbook *logbook);
// Find if there is same name with exist route.
int same_name (struct route *current, struct route *new_route); 
// Appending the route to the logbook
struct route *append_route (struct logbook *logbook);
// print the route in logbook
struct route *print (struct logbook *logbook);
// The funtion is for stage 2.1 to Filter routes by difficulty.
struct route *fliter (struct logbook *logbook);
// The function is to search the route's name whether it exist in the logbook
int search_name(struct logbook *logbook, char name[MAX_STR_LEN]);
// inserting a new route to the logbook
struct route *insert (struct logbook *logbook);
// Changing length of all routes between 2 named routes
struct route *change_length (struct logbook *logbook);
// Testing inside the function change_route to find
// whether it is vaild length change
int test_is_greater (struct route *start_route, int length_change, char name[MAX_STR_LEN]);
// Swap 2 named routes
struct route *swap (struct logbook *logbook);
// add a new attempt
struct route *add_attempt (struct logbook *logbook);
// it is inside the add_attempt function to avoid too much lines.
struct route *inside_add_attempt (
    struct logbook *logbook, 
    struct attempt *new_attempt,
    char climber[MAX_STR_LEN],
    struct route *current
);
// print the attempt
struct route *print_attempt (struct logbook *logbook);
// remove a route and free memory
struct route *remove_route (struct logbook *logbook);
// remove a attempt and free memory
struct route *remove_attempt (struct logbook *logbook); 
// Duplicate all the attempts of another climber
struct route *duplicate (struct logbook *logbook);
// the function is inside the duplicate to avoid too much lines
struct route *inside_duplicate (
    struct logbook *logbook, 
    struct attempt *new_attempt,
    char climber[MAX_STR_LEN],
    struct route *current

);
// find is the attempt's type is first go or not
struct route *is_first_go (
    struct logbook *logbook,
    struct route *current, 
    char climber_1[MAX_STR_LEN],
    struct attempt *new_attempt
);
// combines 2 routes into 1, keeping all the attempts 
// of each route under the new 'combined' route
struct route *combine (struct logbook *logbook);
// free the route that we do not need
struct route *free_route (struct route *new_route, struct logbook *logbook);
// creat a new route which is the combine route
struct route *create_new_route(struct route *keep_route, struct route *remove_route);
// check whether there is the route that exist in the logbook
int is_route1_exist (
    struct logbook *logbook,
    char route_1[MAX_STR_LEN]
);
// free the route after combine
struct route *free_remove_route (struct logbook *logbook, struct route *remove_route);
// find the attempt's type which is first_go
struct route *find_first_go (struct route *new_route);
// create a new attempt
struct attempt *create_attempt(
    char climber[MAX_STR_LEN], 
    int rating,
    int type,
    struct attempt *next
);
// insert new attempt to the tail to make a linked list
struct attempt *insert_at_tail(
    char climber[MAX_STR_LEN], 
    int rating,
    int type, 
    struct attempt *new_attempt
);
// find the maximum num of two route then find the most recently
int max_num (struct attempt *attempt_current, int num);
// find the route name that we need to remove
struct route *find_remove_route (char route[MAX_STR_LEN], struct logbook *logbook);
// find the most recently route between two route
struct route *recent_route (
    struct logbook *logbook,
    char route_1[MAX_STR_LEN],
    char route_2[MAX_STR_LEN]
);
void sort_ldb(struct leaderbd *leaderboard_current);
struct route *leaderboard (struct logbook *logbook);
void add_in_ldb (
    struct route *need, 
    struct attempt *current,
    struct attempt *new_attempt
);
struct attempt *travel_lead (struct attempt *current);
struct route *lead_route (struct logbook *logbook, char route[MAX_STR_LEN]);
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

int main(void) {
    printf("Welcome to 1511 Climb! \n");
    printf("Log all of your climbing adventures here! \n");
    // STAGE 1.1
    // You should call your `create_logbook()` function here!
    printf("Enter command: ");
    struct logbook *logbook = create_logbook(); 
    // STAGE 1.2
    // TODO: Write your command loop
    //int num_route = 0;
    char character;
    while (scanf(" %c", &character) == 1) {
        if (character == '?') {
            print_usage();
        } else if (character == 'r') {
            logbook->routes = append_route(logbook);
        } else if (character == 'p') {
            logbook->routes = print(logbook);
        } else if (character == 'f') {
            logbook->routes = fliter(logbook);
        } else if (character == 'i') {
            logbook->routes = insert(logbook);
        } else if (character == 'l') {
            logbook->routes = change_length(logbook);
        } else if (character == 's') {
            logbook->routes = swap(logbook);
        } else if (character == 'a') {
            logbook->routes = add_attempt(logbook);
        } else if (character == 'P') {
            logbook->routes = print_attempt(logbook);
        } else if (character == 'R') {
            logbook->routes = remove_route (logbook);
        } else if (character == 'D') {
            logbook->routes = remove_attempt (logbook);
        } else if (character == 'd') {
            logbook->routes = duplicate (logbook);
        } else if (character == 'c') {
            logbook->routes = combine(logbook);
        } else if (character == 'L') {
            logbook->routes = leaderboard(logbook);
        }
        printf("Enter command: ");
    }
    printf("\nGoodbye\n");
    free_logbook(logbook);
    return 0;
}

////////////////////////////////////////////////////////////////////////////////
/////////////////////////////  YOUR FUNCTIONS //////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void free_logbook(struct logbook *logbook) {
    struct route *current = logbook->routes;
    while (current != NULL) {
        struct route *next = current->next;
        struct attempt *remove = current->attempts;
        while (remove != NULL) {
            struct attempt *at_next = remove->next;
            free(remove);
            remove = at_next;
        }
        free(current);
        current = next;
    }
    free(logbook);
}
struct route *is_wrong_or_not (struct logbook *logbook) {
    char name[MAX_STR_LEN] = {0};
    int difficulty;
    int length;
    scan_string(name);
    scanf(" %d", &difficulty);
    scanf(" %d", &length);
    if (difficulty > 39 || difficulty <= 0) {
        printf("ERROR: Route difficulty must be between 1 and 39\n");
        return logbook->routes;
    } else if (length > 60 || length <= 0) {
        printf("ERROR: Route length must be between 1m and 60m\n");
        return logbook->routes;
    } 
    struct route *new_route = create_route(name, difficulty, length);
    return new_route;
}
int same_name (struct route *current, struct route *new_route) {
    if (strcmp(current->name, new_route->name) == 0) {
        printf("ERROR: A route with the name "
        "'%s' already exists in this logbook\n", new_route->name);
        free(new_route);
        return 1;
    }
    return 0;
}
struct route *append_route (struct logbook *logbook) {
    struct route *new_route = is_wrong_or_not(logbook);
    if (new_route == logbook->routes) {
        return logbook->routes;
    }
    if (logbook->routes == NULL) {
        printf("Route '%s' added successfully!\n", new_route->name);
        return new_route;

    } else {
        struct route *current = logbook->routes;
        while (current->next != NULL) {
            if (same_name(current, new_route) == 1) {
                return logbook->routes;
            }
            current = current->next;
        }
        if (same_name(current, new_route) == 1) {
            return logbook->routes;
        }
        current->next = new_route;
    }
    printf("Route '%s' added successfully!\n", new_route->name);
    return logbook->routes;
}

struct route *print (struct logbook *logbook) {
    if (logbook->routes == NULL) {
        printf("There are no routes in this logbook!\n");
        return logbook->routes;
    }
    struct route *current = logbook->routes;
    int i = 1;
    while (current != NULL) {
        print_one_route(i, current);
        current = current->next;
        i++;
    }
    return logbook->routes;
}

struct route *fliter (struct logbook *logbook) {
    int difficulty_max;
    int difficulty_min;
    scanf(" %d", &difficulty_min);
    scanf(" %d", &difficulty_max);
    if (difficulty_min <= 0 || difficulty_min > 39 || difficulty_max <= 0 
    || difficulty_max > 39 || difficulty_min > difficulty_max) {
        printf("ERROR: Difficulty range invalid!\n");
        return logbook->routes;
    }
    printf("Routes between difficulty %d and %d:\n", difficulty_min, difficulty_max);
    struct route *current = logbook->routes;
    int count = 1;
    while (current != NULL) {
        if (current->difficulty <= difficulty_max &&
        current->difficulty >= difficulty_min) {
            print_one_route(count, current);
        }
        current = current->next;
        count++;
    }
    return logbook->routes;
}
int search_name(struct logbook *logbook, char name[MAX_STR_LEN]) {
    struct route *current = logbook->routes;
    int count = 0;
    while (current != NULL) {
        if (strcmp(name, current->name) == 0) {
            count++;
        }
        current = current->next;
    }
    if (count == 0) {
        return 0;
    }
    return 1;
}
struct route *insert (struct logbook *logbook) {
    struct route *new_route = is_wrong_or_not(logbook);
    char name[MAX_STR_LEN];
    scan_string(name);
    if (new_route == logbook->routes) {
        return logbook->routes;
    }
    if (logbook->routes == NULL || search_name(logbook, name) == 0) {
        printf("ERROR: No route with the name '%s' exists in this logbook\n"
        , name);
        free(new_route);
        return logbook->routes;
    }
    struct route *current = logbook->routes;
    struct route *previous = NULL;
    while (current != NULL) {
        if (same_name(current, new_route) == 1) {
            return logbook->routes;
        } 
        if (strcmp(current->name, name) == 0) {
            if (previous != NULL) {
                new_route->next = current;
                previous->next = new_route;
                
            } else {
                new_route->next = current;
                logbook->routes = new_route;
            }
        } 
        previous = current;
        current = current->next;
    }
    printf("Route '%s' inserted successfully!\n", new_route->name);
    return logbook->routes;
}
struct route *change_length (struct logbook *logbook) {
    char start[MAX_STR_LEN];
    char end[MAX_STR_LEN];
    int length_change;
    scan_string(start);
    scan_string(end);
    scanf(" %d", &length_change);
    struct route *start_route = NULL;
    struct route *end_route = NULL;
    struct route *current = logbook->routes;
    int test = 0;
    while (current != NULL) {
        if ((strcmp(current->name, start) == 0 || 
        strcmp(current->name, end) == 0) && test == 0) {
            start_route = current;
            test = 1;
        } else if (strcmp(current->name, end) == 0 || strcmp(current->name, start) == 0) {
            end_route = current;
        } 
        current = current->next;
    }
    if (start_route == NULL) {
        printf("ERROR: No route with the name '%s' exists in this logbook\n", start);
        return logbook->routes;
    }
    if (test_is_greater(start_route, length_change, end) == 1) {
        return logbook->routes;
    }
    if (strcmp(end, start) != 0) {
        if (end_route == NULL) {
            printf("ERROR: No route with the name '%s' exists in this logbook\n", end);
            return logbook->routes;
        }
        while (start_route != end_route->next) {
            start_route->length = start_route->length + length_change;
            printf("Length of '%s' updated from %dm to %dm\n", 
            start_route->name, start_route->length - length_change, start_route->length);
            start_route = start_route->next;
        }
    } else {
        start_route->length = start_route->length + length_change;
        printf("Length of '%s' updated from %dm to %dm\n", 
        start_route->name, start_route->length - length_change, start_route->length);
    }
    return logbook->routes;
}

int test_is_greater (
    struct route *start_route, 
    int length_change, 
    char name[MAX_STR_LEN]
) {
    int count = 0;
    while (start_route != NULL && count == 0) {
        if (strcmp(start_route->name, name) == 0) {
            count = 1;
        }
        int new_length = start_route->length + length_change;
        if (new_length <= 0 || new_length > 60) {
            printf("ERROR: Invalid length change! No route lengths have been changed\n");
            return 1;
        }
        start_route = start_route->next;
    }
    return 0;
}
struct route *swap (struct logbook *logbook) {
    char start[MAX_STR_LEN];
    char end[MAX_STR_LEN];
    int length_change;
    scan_string(start);
    scan_string(end);
    scanf(" %d", &length_change);
    struct route *start_route = NULL;
    struct route *end_route = NULL;
    struct route *current = logbook->routes;
    if (strcmp(end, start) == 0) {
        printf("ERROR: Cannot swap '%s' with itself\n", start);
        return logbook->routes;
    } else {
        int test = 0;
        while (current != NULL) {
            if ((strcmp(current->name, start) == 0 || 
            strcmp(current->name, end) == 0) && test == 0) {
                start_route = current;
                test = 1;
            } else if (strcmp(current->name, end) == 0 
                || strcmp(current->name, start) == 0) {
                end_route = current;
            } 
            current = current->next;
        }
    }
    if (start_route == NULL) {
        printf("ERROR: No route with the name '%s' exists in this logbook\n", start);
        return logbook->routes;
    }
    if (end_route == NULL) {
        printf("ERROR: No route with the name '%s' exists in this logbook\n", end);
        return logbook->routes;
    }
    struct route *previous = NULL;
    struct route *end_route_next = NULL;
    current = logbook->routes;
    while (current != NULL) {
        if (current == start_route) {
            end_route_next = end_route->next;
            if (current->next == end_route) {
                end_route->next = start_route; 
            } else {
                end_route->next = start_route->next; 
            }
            if (previous != NULL) {
                previous->next = end_route;
            } else {
                logbook->routes = end_route;
            }
        } else if (current == end_route) {
            previous->next = start_route;
            start_route->next = end_route_next;
            printf("'%s' swapped positions with '%s'!\n", start, end);
            return logbook->routes;   
        } 
        previous = current;
        current = current->next;
    }
    printf("'%s' swapped positions with '%s'!\n", start, end);
    return logbook->routes;   
}

struct route *add_attempt (struct logbook *logbook) {
    struct attempt *new_attempt = malloc(sizeof(struct attempt));
    char climber[MAX_STR_LEN] = {0};
    char route[MAX_STR_LEN] = {0};
    scan_string(climber);
    strcpy(new_attempt->climber, climber);
    new_attempt->type = scan_attempt_type();
    int rating;
    scanf(" %d", &rating);
    new_attempt->rating = rating;
    scan_string(route);
    
    if (new_attempt->type == INVALID_TYPE) {
        printf("ERROR: Attempt type invalid\n");
        free(new_attempt);
        return logbook->routes;
    }
    if (new_attempt->rating < 0 || new_attempt->rating > 3) {
        printf("ERROR: Rating must be between 0 and 3\n");
        return logbook->routes;
    }
    new_attempt->next = NULL;
    struct route *current = logbook->routes;
    while (current != NULL && strcmp(current->name, route)) {
        current = current->next;
    }
    if (current == NULL) {
        printf("ERROR: No route with the name '%s' exists in this logbook\n", route);
        free(new_attempt);
        return logbook->routes;
    }
    if (current->attempts == NULL) {
        current->attempts = new_attempt;
        new_attempt->attempt_num = logbook->attempts_count;
        logbook->attempts_count++;
    } else {
        struct attempt *attempt_current = current->attempts;
        while (attempt_current != NULL) {
            if ((strcmp(climber, attempt_current->climber) == 0)
                && new_attempt->type == FIRST_GO) {
                printf("ERROR: %s has already attempted '%s' - "
                "they can't get it on their first go!\n", climber, route);
                free(new_attempt);
                return logbook->routes;
            }
            attempt_current = attempt_current->next;
        }
        logbook->routes = inside_add_attempt(logbook, 
        new_attempt, climber, current);
        new_attempt->attempt_num = logbook->attempts_count;
        logbook->attempts_count++;
    }
    
    
    printf("Logged attempt of '%s' by %s\n", route, climber);
    return logbook->routes;
}
struct route *inside_add_attempt (
    struct logbook *logbook, 
    struct attempt *new_attempt,
    char climber[MAX_STR_LEN],
    struct route *current

) {
    struct attempt *attempt_current = current->attempts;
    struct attempt *prev_attempt = NULL;
    while (attempt_current != NULL) {
        char str1 = tolower(new_attempt->climber[0]);
        char str2 = tolower(attempt_current->climber[0]);
        if ((str2 > str1) && prev_attempt != NULL) {
            prev_attempt->next = new_attempt;
            new_attempt->next = attempt_current;
            return logbook->routes;
        } else if ((str2 > str1) && prev_attempt == NULL) {
            new_attempt->next = attempt_current;
            current->attempts = new_attempt;
            return logbook->routes;
        } else {
            if ((strcmp(attempt_current->climber, climber) == 0)
                 && prev_attempt != NULL) {
                prev_attempt->next = new_attempt;
                new_attempt->next = attempt_current;
                return logbook->routes;

            } else if (strcmp(attempt_current->climber, climber) == 0) {
                current->attempts = new_attempt;
                new_attempt->next = attempt_current;
                return logbook->routes;

            } else {
                prev_attempt = attempt_current;
                attempt_current = attempt_current->next;
            }
            
        }
    }
    prev_attempt->next = new_attempt;
    return logbook->routes;
}
struct route *print_attempt (struct logbook *logbook) {
    if (logbook->routes == NULL) {
        printf("There are no routes in this logbook!\n");
        return logbook->routes;
    }
    struct route *current = logbook->routes;
    int count = 1;
    while (current != NULL) {
        struct attempt *attempt_current = current->attempts;
        if (attempt_current == NULL) {
            printf("Route #%d: %s\nDifficulty: "
            "%d | Length: %dm | Avg rating: "
            "0.0/3.0\n", count, current->name, current->difficulty
            , current->length);
        } else {
            double avg_rating = 0.0;
            int num_people = 0;
            while (attempt_current != NULL) {
                avg_rating = avg_rating + attempt_current->rating;
                attempt_current = attempt_current->next;
                num_people++;
            }
            avg_rating = avg_rating / num_people;
            printf("Route #%d: %s\nDifficulty: "
            "%d | Length: %dm | Avg rating: "
            "%.1lf/3.0\n", count, current->name, current->difficulty
            , current->length, avg_rating);
            attempt_current = current->attempts;
            while (attempt_current != NULL) {
                print_one_attempt(attempt_current->climber,
                attempt_current->type, attempt_current->rating);
                attempt_current = attempt_current->next;
            }
        }
        current = current->next;
        count++;
    }
    return logbook->routes;
}
struct route *remove_route (struct logbook *logbook) {
    struct route *current = logbook->routes;
    struct route *previous = NULL;
    char rm_route[MAX_STR_LEN];
    scan_string(rm_route);
    while (current != NULL) {
        if ((strcmp(current->name, rm_route) == 0) && previous != NULL) {
            previous->next = current->next;
            struct attempt *attempt_current = current->attempts;
            while (attempt_current != NULL) {
                struct attempt *remove = attempt_current;
                attempt_current = attempt_current->next;
                free(remove);
            }
            free(current);
            printf("Removed route '%s' from logbook\n", rm_route);
            return logbook->routes;
        } else if ((strcmp(current->name, rm_route) == 0) && previous == NULL) {
            logbook->routes = current->next;
            struct attempt *attempt_current = current->attempts;
            while (attempt_current != NULL) {
                struct attempt *remove = attempt_current;
                attempt_current = attempt_current->next;
                free(remove);
            }
            free(current);
            printf("Removed route '%s' from logbook\n", rm_route);
            return logbook->routes;
        }
        previous = current;
        current = current->next;
    }
    printf("ERROR: No route with the name '%s' exists in this logbook\n", rm_route);
    return logbook->routes;
}
struct route *remove_attempt (struct logbook *logbook) {
    int count = 0;
    char climber[MAX_STR_LEN];
    scan_string(climber);
    struct route *current = logbook->routes;
    while (current != NULL) {
        struct attempt *attempt_current = current->attempts;
        struct attempt *prev_attempt = NULL;
        while (attempt_current != NULL) {
            if (strcmp(climber, attempt_current->climber) == 0 && prev_attempt != NULL) {
                struct attempt *remove = attempt_current;
                attempt_current = attempt_current->next;
                prev_attempt->next = attempt_current;
                free(remove);
                count++;
            } else if (strcmp(climber, attempt_current->climber) == 0) {
                struct attempt *remove = attempt_current;
                attempt_current = attempt_current->next;
                current->attempts = attempt_current;
                free(remove);
                count++;
            } else {
                prev_attempt = attempt_current;
                attempt_current = attempt_current->next;
            }
        }
        current = current->next;
    }
    if (count == 0) {
        printf("ERROR: %s has not logged any attempts\n", climber);
        return logbook->routes;
    }
    printf("Deleted %d attempt(s) logged by %s\n", count, climber);
    return logbook->routes;
}
struct route *duplicate (struct logbook *logbook) {
    char climber_1[MAX_STR_LEN];
    char climber_2[MAX_STR_LEN];
    scan_string(climber_1);
    scan_string(climber_2);
    if (strcmp(climber_1, climber_2) == 0) {
        printf("ERROR: Cannot duplicate attempts made by the same climber\n");
        return logbook->routes;
    }
    int count = 0;
    struct route *current = logbook->routes;
    while (current != NULL) {
        count = 0;
        struct attempt *attempt_current = current->attempts;
        while (attempt_current != NULL) {
            if (strcmp(climber_2, attempt_current->climber) == 0) {
                struct attempt *new_attempt = malloc(sizeof(struct attempt));
                new_attempt->type = attempt_current->type;
                new_attempt->rating = attempt_current->rating;
                logbook->routes = is_first_go(logbook, 
                current, climber_1, new_attempt);
                strcpy(new_attempt->climber, climber_1);
                new_attempt->attempt_num = logbook->attempts_count;
                logbook->attempts_count++;
                new_attempt->next = NULL;
                logbook->routes = inside_duplicate(logbook,
                new_attempt, climber_1, current);
                count++;
            } 
            attempt_current = attempt_current->next;
        }
        current = current->next;
    }
    if (count == 0) {
        printf("ERROR: %s has not logged any attempts\n", climber_2);
    }
    return logbook->routes;
}
struct route *is_first_go (
    struct logbook *logbook,
    struct route *current, 
    char climber_1[MAX_STR_LEN],
    struct attempt *new_attempt
) {
    struct attempt *attempt_current = current->attempts;
    int test = 0;
    while (attempt_current != NULL) {
        if (strcmp(attempt_current->climber, climber_1) == 0) {
            test = 1;
        }
        attempt_current = attempt_current->next;
    }

    if (new_attempt->type == FIRST_GO && test == 1) {
        new_attempt->type = SUCCESS;
    }
    return logbook->routes;
    
}
struct route *inside_duplicate (
    struct logbook *logbook, 
    struct attempt *new_attempt,
    char climber[MAX_STR_LEN],
    struct route *current

) {
    struct attempt *attempt_current = current->attempts;
    struct attempt *prev_attempt = NULL;
    while (attempt_current != NULL) {
        char str1 = tolower(new_attempt->climber[0]);
        char str2 = tolower(attempt_current->climber[0]);
        if ((str2 > str1) && prev_attempt != NULL) {
            prev_attempt->next = new_attempt;
            new_attempt->next = attempt_current;
            printf("Logged attempt of '%s' by %s\n", current->name, climber);
            return logbook->routes;
        } else if ((str2 > str1) && prev_attempt == NULL) {
            new_attempt->next = attempt_current;
            current->attempts = new_attempt;
            printf("Logged attempt of '%s' by %s\n", current->name, climber);
            return logbook->routes;
        } else {
            if ((strcmp(attempt_current->climber, climber) == 0 && 
            prev_attempt == NULL && strcmp(attempt_current->next->climber, 
            attempt_current->climber) != 0)) {
                new_attempt->next = attempt_current;
                current->attempts = new_attempt;
                printf("Logged attempt of '%s' by %s\n", current->name, climber);
                return logbook->routes;
            } else if (strcmp(attempt_current->climber, climber) == 0 && 
                (attempt_current->next == NULL) && prev_attempt != NULL) {
                prev_attempt->next = new_attempt;
                new_attempt->next = attempt_current;
                printf("Logged attempt of '%s' by %s\n", current->name, climber);
                return logbook->routes;  
            } else if ((strcmp(attempt_current->climber, climber) == 0 && strcmp(
                attempt_current->next->climber, attempt_current->climber) != 0)
                 && prev_attempt != NULL) {
                prev_attempt->next = new_attempt;
                new_attempt->next = attempt_current;
                printf("Logged attempt of '%s' by %s\n", current->name, climber);
                return logbook->routes;
            } else {
                prev_attempt = attempt_current;
                attempt_current = attempt_current->next;
            }
        }
    }
    printf("Logged attempt of '%s' by %s\n", current->name, climber);
    prev_attempt->next = new_attempt;
    return logbook->routes;
}

struct route *combine (struct logbook *logbook) {
    char route_1[MAX_STR_LEN];
    char route_2[MAX_STR_LEN];
    scan_string(route_1);
    scan_string(route_2);
    if (strcmp(route_1, route_2) == 0) {
        printf("ERROR: Cannot combine '%s' with itself\n", route_1);
        return logbook->routes;
    }
    if (is_route1_exist(logbook, route_1) == 0) {
        return logbook->routes;
    }
    if (is_route1_exist(logbook, route_2) == 0) {
        return logbook->routes;
    }   
    struct route *keep_route = recent_route(logbook, route_1, route_2);
    struct route *remove_route = NULL;
    if (strcmp(keep_route->name, route_1) == 0) {
        remove_route = find_remove_route(route_2, logbook);
    } else {
        remove_route = find_remove_route(route_1, logbook);
    }
    if (keep_route->length + remove_route->length > 60) {
        printf("ERROR: Combined route cannot be longer than 60m\n");
        return logbook->routes;
    }
    struct route *new_route = create_new_route(keep_route, remove_route);
    logbook->routes = free_route(new_route, logbook);
    logbook->routes = free_remove_route(logbook, remove_route);
    new_route = find_first_go(new_route);
    printf("Successfully combined routes '%s' and '%s'\n", route_1, route_2);
    return logbook->routes;
}
struct route *free_route (struct route *new_route, struct logbook *logbook) {
    struct route *now = logbook->routes;
    struct route *previous = NULL;
    int count = 0;
    while (now != NULL && count == 0) {
        if (strcmp(now->name, new_route->name) == 0 && previous != NULL) {
            previous->next = new_route;
            new_route->next = now->next;
            struct attempt *remove = now->attempts;
            while (remove != NULL) {
                struct attempt *at_next = remove->next;
                free(remove);
                remove = at_next;
            }
            free(now);
            count = 1;
        } else if (strcmp(now->name, new_route->name) == 0 && previous == NULL) {
            logbook->routes = new_route;
            new_route->next = now->next;
            struct attempt *remove = now->attempts;
            while (remove != NULL) {
                struct attempt *at_next = remove->next;
                free(remove);
                remove = at_next;
            }
            free(now);
            count = 1;
        }
        else {
            previous = now;
            now = now->next;
        }
    }
    return logbook->routes;
}
    
struct route *create_new_route(struct route *keep_route, struct route *remove_route) {
    struct attempt *current_1 = keep_route->attempts;
    struct attempt *current_2 = remove_route->attempts;
    int difficulty_max = 0;
    if (keep_route->difficulty >= remove_route->difficulty) {
        difficulty_max = keep_route->difficulty;
    } else {
        difficulty_max = remove_route->difficulty;
    }
    struct route *new_route = create_route(keep_route->name, 
    difficulty_max, keep_route->length + remove_route->length);
    struct attempt *new_attempt = new_route->attempts;
    while (current_2 != NULL && current_1 != NULL) {
        char str1 = tolower(current_1->climber[0]);
        char str2 = tolower(current_2->climber[0]);
        if (str2 > str1) {
            new_attempt = insert_at_tail(current_1->climber, 
            current_1->rating, current_1->type, new_attempt);
            current_1 = current_1->next;
        } else if (str2 < str1) {
            new_attempt = insert_at_tail(current_2->climber, 
            current_2->rating, current_2->type, new_attempt);
            current_2 = current_2->next;
        } else {
            while (current_2 != NULL && (strcmp(current_2->climber, 
            remove_route->attempts->climber) == 0
             || strcmp(current_2->climber, current_1->climber) == 0)) {
                new_attempt = insert_at_tail(current_2->climber, 
                current_2->rating, current_2->type, new_attempt);
                current_2 = current_2->next;
            }
            while (strcmp(current_1->climber, keep_route->attempts->climber) == 0) {
                new_attempt = insert_at_tail(current_1->climber, 
                current_1->rating, current_1->type, new_attempt);
                current_1 = current_1->next;
            }
        }
    }
    while (current_1 != NULL) {
        new_attempt = insert_at_tail(current_1->climber, 
        current_1->rating, current_1->type, new_attempt);
        current_1 = current_1->next; 
    }
    while (current_2 != NULL) {
        new_attempt = insert_at_tail(current_2->climber, 
        current_2->rating, current_2->type, new_attempt);
        current_2 = current_2->next;
    }
    new_route->attempts = new_attempt;
    return new_route;
}
int is_route1_exist (
    struct logbook *logbook,
    char route_1[MAX_STR_LEN]
) {
    struct route *current = logbook->routes;
    while (current != NULL) {
        if (strcmp(current->name, route_1) == 0) {
            return 1;
        }
        current = current->next;
    }
    printf("ERROR: No route with the name '%s' exists in this logbook\n", 
    route_1);
    return 0;
}
struct route *free_remove_route (struct logbook *logbook, struct route *remove_route) {
    struct route *now = logbook->routes;
    struct route *previous = NULL;
    while (now != NULL) {
        struct route *next = now->next;
        if (strcmp(now->name, remove_route->name) == 0) {
            if (previous == NULL) {
                logbook->routes = next;
            } else {
                previous->next = next; 
            }
            struct attempt *remove = now->attempts;
            while (remove != NULL) {
                struct attempt *at_next = remove->next;
                free(remove);
                remove = at_next;
            }
            free(now);
            if (previous == NULL) {
                now = logbook->routes;
            } else {
                now = next;
            }
            return logbook->routes;
        } else {
            previous = now;
            now = now->next;
        }
    }
    return logbook->routes;
}
struct route *find_first_go (struct route *new_route) {
    struct attempt *current = new_route->attempts;
    struct attempt *previous = NULL;
    while (current != NULL) {
        if (previous != NULL && previous->type == FIRST_GO) {
            if (strcmp(current->climber, previous->climber) == 0) {
                previous->type = SUCCESS;
            }
        }
        previous = current;
        current = current->next;
    }
    return new_route;
}
struct attempt *create_attempt(
    char climber[MAX_STR_LEN], 
    int rating,
    int type,
    struct attempt *next
) {
    struct attempt *new_attempt = malloc(sizeof(struct attempt));
    strcpy(new_attempt->climber, climber);
    new_attempt->type = type;
    new_attempt->rating = rating;
    new_attempt->next = next;
    new_attempt->attempt_num = 0;
    return new_attempt;
}
struct attempt *insert_at_tail(
    char climber[MAX_STR_LEN], 
    int rating,
    int type, 
    struct attempt *new_attempt
) {
    struct attempt *current = new_attempt;
    if (new_attempt == NULL) {
        new_attempt = create_attempt(climber, rating, type, NULL);
        return new_attempt;
    }
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = create_attempt(climber, rating, type, NULL);
    return new_attempt;
}


struct route *recent_route (
    struct logbook *logbook,
    char route_1[MAX_STR_LEN],
    char route_2[MAX_STR_LEN]
) {
    int num1 = 0;
    int num2 = 0;
    struct route *current = logbook->routes;
    struct route *route_1_route = NULL;
    struct route *route_2_route = NULL;
    while (current != NULL) {
        if (strcmp(current->name, route_1) == 0) {
            route_1_route = current;
            struct attempt *attempt_current = current->attempts;
            while (attempt_current != NULL) {
                num1 = max_num(attempt_current, num1);
                attempt_current = attempt_current->next;
            }
        } 
        if (strcmp(current->name, route_2) == 0) {
            route_2_route = current;
            struct attempt *attempt_current = current->attempts;
            while (attempt_current != NULL) {
                num2 = max_num(attempt_current, num2);
                attempt_current = attempt_current->next;
            }
        }
        current = current->next;
    }
    if (num1 > num2) {
        return route_1_route;
    } else if (num1 < num2) {
        return route_2_route;
    }
    return NULL;
}
int max_num (struct attempt *attempt_current, int num) {
    if (attempt_current->attempt_num > num) {
        num = attempt_current->attempt_num;
        return num;
    }
    return num;
}
struct route *find_remove_route (char route[MAX_STR_LEN], struct logbook *logbook) {
    struct route *current = logbook->routes;
    while (current != NULL) {
        if (strcmp(current->name, route) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}
struct leaderbd *create_group(struct route *new_route) {
    struct attempt *current = new_route->attempts;
    struct leaderbd *leaderboard_current = NULL;
    // int head_fl = 0;
    int fl = 0;
    while (current != NULL) {
        if (leaderboard_current != NULL && fl == 0) {
            if (current->next != NULL && strcmp(
                current->next->climber, current->climber) == 0) fl = 0;
            else fl = 1;
            if (current->type == SUCCESS || current->type == FIRST_GO) {
                if (current->type == FIRST_GO) {
                    leaderboard_current->go_first_fl = 1;
                }
                leaderboard_current->success_count++;
            }
            leaderboard_current->total_count++;
        }
        else if (leaderboard_current == NULL || fl == 1) {
            // fl = 0;
            struct leaderbd *new_leaderboard = malloc(sizeof(struct leaderbd));
            strcpy(new_leaderboard->climber, current->climber);
            if (current->type == SUCCESS || current->type == FIRST_GO) {
                if (current->type == FIRST_GO) {
                    new_leaderboard->go_first_fl = 1;
                }
                new_leaderboard->success_count = 1;
            }
            else{
                new_leaderboard->success_count = 0;
            }
            new_leaderboard->total_count = 1;
            new_leaderboard->next = leaderboard_current;
            leaderboard_current = new_leaderboard;
            if (current->next != NULL && strcmp(current->next->climber, 
            current->climber) == 0) fl = 0;
            // printf("%s",leaderboard_current->climber);
        }
        current = current->next;
    }
    return leaderboard_current;
}

void sort_ldb(struct leaderbd *leaderboard_current) {
    int swapped;
    struct leaderbd *ptr1;
    struct leaderbd *lptr = NULL;

    if (leaderboard_current == NULL)
        return;

    swapped = 1;
    while (swapped) {
        swapped = 0;
        ptr1 = leaderboard_current;

        while (ptr1->next != lptr) {
            if (ptr1->go_first_fl < ptr1->next->go_first_fl) {
                // Swap go_first_fl
                int temp_go_first_fl = ptr1->go_first_fl;
                ptr1->go_first_fl = ptr1->next->go_first_fl;
                ptr1->next->go_first_fl = temp_go_first_fl;

                // Swap success_count
                int temp_success_count = ptr1->success_count;
                ptr1->success_count = ptr1->next->success_count;
                ptr1->next->success_count = temp_success_count;

                // Swap total_count
                int temp_total_count = ptr1->total_count;
                ptr1->total_count = ptr1->next->total_count;
                ptr1->next->total_count = temp_total_count;

                // Swap climber
                char temp_climber[MAX_STR_LEN];
                strcpy(temp_climber, ptr1->climber);
                strcpy(ptr1->climber, ptr1->next->climber);
                strcpy(ptr1->next->climber, temp_climber);

                swapped = 1;
            } else if (ptr1->go_first_fl == ptr1->next->go_first_fl) {
                if (ptr1->success_count < ptr1->next->success_count) {
                    // Swap success_count
                    int temp_success_count = ptr1->success_count;
                    ptr1->success_count = ptr1->next->success_count;
                    ptr1->next->success_count = temp_success_count;

                    // Swap total_count
                    int temp_total_count = ptr1->total_count;
                    ptr1->total_count = ptr1->next->total_count;
                    ptr1->next->total_count = temp_total_count;

                    // Swap climber
                    char temp_climber[MAX_STR_LEN];
                    strcpy(temp_climber, ptr1->climber);
                    strcpy(ptr1->climber, ptr1->next->climber);
                    strcpy(ptr1->next->climber, temp_climber);

                    swapped = 1;
                } else if (ptr1->success_count == ptr1->next->success_count) {
                    if (ptr1->total_count < ptr1->next->total_count) {
                        // Swap total_count
                        int temp_total_count = ptr1->total_count;
                        ptr1->total_count = ptr1->next->total_count;
                        ptr1->next->total_count = temp_total_count;

                        // Swap climber
                        char temp_climber[MAX_STR_LEN];
                        strcpy(temp_climber, ptr1->climber);
                        strcpy(ptr1->climber, ptr1->next->climber);
                        strcpy(ptr1->next->climber, temp_climber);

                        swapped = 1;
                    } else if (ptr1->total_count == ptr1->next->total_count) {
                        if (strcmp(ptr1->climber, ptr1->next->climber) > 0) {
                            // Swap climber
                            char temp_climber[MAX_STR_LEN];
                            strcpy(temp_climber, ptr1->climber);
                            strcpy(ptr1->climber, ptr1->next->climber);
                            strcpy(ptr1->next->climber, temp_climber);

                            swapped = 1;
                        }
                    }
                }
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
    
    return;
}


void print_ldb(struct leaderbd *new_route) {
    struct leaderbd *current = new_route;
    int rank = 1;
    while (current != NULL) {
        printf("     #%d %s\n", rank, current->climber);
        if (current->go_first_fl == 1) {
            printf("        First go attempt!\n");
        }
        printf("        Successful attempts: %d\n", current->success_count);
        printf("        Total attempts: %d\n\n", current->total_count);
        rank++;
        current = current->next;
    }
    return;
}


struct route *leaderboard(struct logbook *logbook) {
    char route[MAX_STR_LEN];
    scan_string(route);
    if (lead_route(logbook, route) == NULL) {
        printf("No route with the name '%s' exists in this logbook\n", route);
        return logbook->routes;
    }
    struct route *need = lead_route(logbook, route);
    if(need->attempts == NULL){
        printf("No attempts have been logged for the route '%s'\n", route);
        return logbook->routes;
    }
    struct attempt *current = need->attempts;
    current = travel_lead(current);
    struct route *new_route = create_route(route, 0, 0);
    struct attempt *new_attempt = new_route->attempts;
    while (current != NULL) {
        new_attempt = create_attempt(current->climber, current->rating, 
        current->type, NULL);
        add_in_ldb(need, current, new_attempt);
        current = travel_lead(current->next);
    }
    
    printf("'%s' Leaderboard\n", need->name);
    struct leaderbd *out = create_group(need);
    sort_ldb(out);

    // print
    print_ldb(out);

    return logbook->routes;
}


void add_in_ldb(
    struct route *need, 
    struct attempt *current, 
    struct attempt *new_attempt
) {
    struct attempt *attempt_current = need->attempts;
    while (attempt_current != NULL) {
        if (strcmp(attempt_current->climber, current->climber) == 0) {
            new_attempt = insert_at_tail(attempt_current->climber, 
            attempt_current->rating, attempt_current->type, new_attempt);
        }
        attempt_current = attempt_current->next;
    }
}

struct attempt *travel_lead(struct attempt *current) {
    while (current != NULL) {
        if (current->type == FIRST_GO) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

struct route *lead_route(struct logbook *logbook, char route[MAX_STR_LEN]) {
    struct route *current = logbook->routes;
    while (current != NULL) {
        if (strcmp(current->name, route) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Allocate memory for a new struct logbook and return a pointer to it
//
// Parameters:
//      None
// 
// Returns:
//      new_logbook - a pointer to the newly created struct logbook
struct logbook *create_logbook() {
    struct logbook *new_logbook = malloc(sizeof(struct logbook));
    new_logbook->routes = NULL;
    new_logbook->attempts_count = 1;
    return new_logbook;
}


// STAGE 1.1
// TODO: what does this function do?
//
// Parameters:
//      TODO
// 
// Returns:
//      TODO
struct route *create_route(
    char name[MAX_STR_LEN], 
    int difficulty, 
    int length
) {
    // STAGE 1.1
    // TODO: malloc, initialise and return a new route
    struct route *new_route = malloc(sizeof(struct route));
    ///strlen(name);
    strcpy(new_route->name, name);
    new_route->difficulty = difficulty;
    new_route->length = length;
    new_route->next = NULL;
    new_route->attempts = NULL;
    // hint: you will have to replace NULL in this return statement.
    return new_route;
}

// TODO: Put your functions here

////////////////////////////////////////////////////////////////////////////////
///////////////////////////  PROVIDED FUNCTIONS  ///////////////////////////////
////////////////////////////////////////////////////////////////////////////////

// Prints the 1511 Climb usage instructions,
// displaying the different commands and their arguments.
//
// Parameters:
//      None
// 
// Returns: 
//      None
void print_usage(void) {
    printf(
        "=====================[     1511 Climb     ]=====================\n"
        "      ===============[     Usage Info     ]===============      \n"
        "  r [name] [difficulty] [length]                                \n"
        "    Append a climbing route to the end of the logbook           \n"
        "  p                                                             \n"
        "    Print out all the climbing routes in the logbook            \n"
        "                                                                \n"
        "  f [difficulty_min] [difficulty_max]                           \n"
        "    Filter routes by difficulty                                 \n"
        "  i [name] [difficulty] [length] [route_to_insert_before]       \n"
        "    Insert a climbing route into the logbook before             \n"
        "    `route_to_insert_before`                                    \n"
        "  l [route_1] [route_2] [length_change]                         \n"
        "    Change length of all routes between `route_1` and `route_2` \n"
        "  s [route_1] [route_2]                                         \n"
        "    Swap 2 routes                                               \n"
        "                                                                \n"
        "  a [climber] [attempt_type] [rating] [route]                   \n"
        "    Add an attempt of `route` by `climber`                      \n"
        "  P                                                             \n"
        "    Print out all the routes and attempts in the logbook        \n"
        "  R [route]                                                     \n"
        "    Remove a route and all associated attempts                  \n"
        "  D [climber]                                                   \n"
        "    Delete all attempts by `climber`                            \n"
        "  d [climber_1] [climber_2]                                     \n"
        "    Duplicate all of `climber_2`s attempts for `climber_1`      \n"
        "                                                                \n"
        "  c [route_1] [route_2]                                         \n"
        "    Combine 2 routes                                            \n"
        "  L [route]                                                     \n"
        "    Print the climber leaderboard for `route`                   \n"
        "                                                                \n"
        "  ?                                                             \n"
        "    Show help                                                   \n"
        "================================================================\n"
    );
}

// Prints a single route, displaying its position in the logbook, name, grade 
// and length. 
//
// Parameters:
//      position    - The position of the route in the logbook (the first 
//                        route will be route_number 1, second will be 2, etc)
//      route       - A pointer to the struct route to be printed
//
// Returns:   
//      None
void print_one_route(int position, struct route *route) {
    int line_length = MAX_STR_LEN + 2;
    printf("/--------- \\/ ---------\\\n");

    char position_str[MAX_STR_LEN];
    sprintf(position_str, "Route #%d", position);
    int padding = line_length - strlen(position_str);
    printf(
        "|%*s%s%*s|\n", padding / 2, "", position_str, (padding + 1) / 2, ""
    );

    padding = line_length - strlen(route->name);
    printf("|%*s%s%*s|\n", padding / 2, "", route->name, (padding + 1) / 2, "");

    printf("|    Difficulty: %2d    |\n", route->difficulty);
    printf("|    Length (m): %2d    |\n", route->length);
    printf("\\--------- || ---------/\n");
}

// Scans a string into the provided char array, placing a '\0' at the end
// 
// Parameters:
//      string      - a char array of length MAX_STR_LEN to store the string 
//                    that is scanned in
// 
// Returns: 
//      None
// 
// Usage: 
// ```
//      char string[MAX_STR_LEN];
//      scan_string(string);
// ```
void scan_string(char string[MAX_STR_LEN]) {
    scan_token(string, MAX_STR_LEN);
}

// Scans a string and converts it to an enum attempt_type.
//
// Parameters: 
//      None
// 
// Returns:
//      The corresponding attempt_type, if the string was valid,
//      Otherwise, returns INVALID_TYPE.
// 
// Usage: 
// ```
//      enum attempt_type type = scan_attempt_type();
// ```
enum attempt_type scan_attempt_type(void) {
    char type[MAX_STR_LEN];
    scan_token(type, MAX_STR_LEN);
    return string_to_type(type);
}

// Prints a single attempt, displaying the climber name, attempt type and rating
//
// Parameters:
//      climber     - The name of the climber who attempted to climb a route
//      type        - The attempt type that was made (should be either 
//                    FIRST_GO, SUCCESS, or FAIL)
//      rating      - The star rating that the climber gave the route
// 
// Returns: 
//      None
void print_one_attempt(
    char climber[MAX_STR_LEN], 
    enum attempt_type type, 
    int rating
) {
    char type_string[MAX_STR_LEN];
    type_to_string(type_string, type);
    printf("        --> %s\n", type_string);
    printf("            Climber: %s\n", climber);
    printf("            Rating:  ");
    for (int i = 0; i < rating; i++) {
        printf("*");
    }
    printf("\n\n");
}

////////////////////////////////////////////////////////////////////////////////
////////////////////// ADDITIONAL PROVIDED FUNCTIONS ///////////////////////////
////////////////////////////////////////////////////////////////////////////////

// You don't need to use any of these, or understand how they work!
// We use them to implement some of the provided helper functions.

// Scans a single word into `buffer`, ignoring whitespace
// 
// Parameters: 
//      buffer      - the string to store the scanned word
//      buffer_size - the maximum size of string that can be scanned (including 
//                    the null terminator)
// Returns: 
//      The number of chars scanned successfully
int scan_token(char *buffer, int buffer_size) {
    if (buffer_size == 0) {
        return 0;
    }

    char c;
    int i = 0;
    int num_scanned = 0;

    // Consume all leading whitespace
    scanf(" ");

    // Scan in characters until whitespace
    while (i < buffer_size - 1
        && (num_scanned = scanf("%c", &c)) == 1  
        && !isspace(c)) {
        buffer[i++] = c;
    }

    if (i > 0) {
        buffer[i] = '\0';
    }

    return num_scanned;
}

// Converts a string to the corresponding enum attempt_type
//
// Parameters: 
//      type_str    - The string to be converted
// 
// Returns: 
//      The matching enum attempt_type, or `INVALID_TYPE` if `type_str` matches 
//      no valid attempt type
enum attempt_type string_to_type(char *type_str) {
    int len = MAX_STR_LEN;

    if (strncasecmp(type_str, "first_go", len) == 0) {
        return FIRST_GO;
    }
    if (strncasecmp(type_str, "success", len) == 0) {
        return SUCCESS;
    } 
    if (strncasecmp(type_str, "fail", len) == 0) {
        return FAIL;
    } 

    return INVALID_TYPE;
}

// Converts an enum attempt_type to a string
// 
// Parameters:
//      buf         - The string to store the attempt type
//      type        - The enum attempt_type to be converted
// 
// Returns:
//      None
void type_to_string(char *buf, enum attempt_type type) {
    if (type == FIRST_GO) {
        strcpy(buf, "FIRST GO");
    } else if (type == SUCCESS) {
        strcpy(buf, "SUCCESS");
    } else if (type == FAIL) {
        strcpy(buf, "FAIL");
    } else {
        strcpy(buf, "INVALID");
    }
}
