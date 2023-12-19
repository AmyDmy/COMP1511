// stellar_information.c
//
// This program simulates a star system in space
//
// Written by Minyu Deng z5495891
// on TODAYS-DATE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CONVERSION_CONSTANT 9.461e12
#define LIGHT_SPEED 299792.458

// TODO: TASK 1
struct star {
    char name[50];
    double distance;
    char spectral_type;
    double total_distance;
};
void print_star_information(struct star *star);
void input_star_information(struct star *star);
double time_travel(struct star *star);

int main() {
    // TODO: TASK 2
    struct star star;
    struct star *star_ptr = &star;
    input_star_information(star_ptr);
    time_travel(star_ptr);
    print_star_information(star_ptr);

    return 0;
}

// Takes in the stars information
void input_star_information(struct star *star) {
    // TODO: TASK 3
    printf("Enter the star's name: ");
    fgets(star->name, 50, stdin);
    printf("Enter the star's distance from Earth (in light-years): ");
    scanf(" %lf", &star->distance);
    printf("Enter the star's spectral type: ");
    scanf(" %c", &star->spectral_type);

}

// Estimate travel time from Earth to the star based on star's distance
double time_travel(struct star *star) {
    // TODO: TASK 4
    double distance1 = star->distance * CONVERSION_CONSTANT;
    star->total_distance = distance1 / LIGHT_SPEED;
    return star->total_distance;
}

// Prints the stars information
void print_star_information(struct star *star) {
    // TODO: TASK 5
    printf("\n");
    printf("Star's Information:\n");
    printf("Name: %s", star->name);
    printf("Distance: %lf light-years\n", star->distance);
    printf("Spectral Type: %c\n", star->spectral_type);
    printf("Estimated travel time from Earth: %.2lf seconds\n", star->total_distance);
}
