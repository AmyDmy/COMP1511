//z5495891
// Written 5/10/2023
// By Minyu Deng
//
// points
//

#include <stdio.h>

#define MAX_POINTS 10

struct point {
    // TODO: fill this in so that the struct can hold an x and y position
    //
    // i.e. This struct should contain:
    //      the x-coordinate and y-coordinate (doubles).
    double x;
    double y;
};

// Prints a point out.
void print_point(int point_no, double x, double y);

int main(void) {
    // TODO: Declare an array of points of size MAX_POINTS
    struct point shape[MAX_POINTS] = {};
    int point_no;
    double x;
    double y;
    printf("How many points in the shape? ");
    // TODO: scan in number of points in the shape
    scanf("%d", &point_no);

    printf("Enter points:\n");
    // TODO: scan in the details of each point into the array
    scanf("%lf %lf", &x, &y);
    int i = 0;
    while (i < point_no) {
        shape[i].x = x;
        shape[i].y = y;
        scanf("%lf %lf", &x, &y);
        i++;
    }
    printf("\nShape Points:\n");
    // TODO: print all the points
    int k = 1;
    while (k <= point_no){

        print_point(k, shape[k-1].x, shape[k-1].y);
        k++;
    }
    return 0;
}

//  Prints a single point in the correct format.
//
// Parameters:
// - `point_no` -- The point number
// - `x`        -- The x-coordinate of the point
// - `y`        -- The y-coordinate of the point
//
// Returns: nothing.
void print_point(int point_no, double x, double y) {
    printf("%2d: x = %.3lf, y = %.3lf\n", point_no, x, y);
}
