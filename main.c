#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "lib/rgb.h"

int* get_rgb_inline(char **argv) {

    int *colors = malloc(sizeof(int) * 3);
    colors[0] = atoi(argv[2]);
    colors[1] = atoi(argv[3]);
    colors[2] = atoi(argv[4]);

    return colors;
}

int main(int argc, char **argv) {
    // Main header
    printf("---------- RGB INVERT ----------\n");

    /*
     * Here declare pointers to use in HEAP memory
     * 1.- Declare pointer of struct RGB (rgb library)
    */
    struct RGB *rgb = malloc(sizeof(struct RGB));
    int *colors;

    /*
     * Here declare variables to use in STACK memory
     * 1.- Get de first flag to use in switch
    */
    char flag = argv[1][1]; 

    switch (flag) {
        case 'i':
            if(argc == 5) {
                colors = get_rgb_inline(argv);
                bool was_set = rgb_set(rgb, colors[0], colors[1], colors[2]);
                if(was_set) {
                   rgb_invert(rgb);
                   printf(
                           "R: %i\nG: %i\nB: %i\n", 
                           rgb -> r,
                           rgb -> g,
                           rgb -> b
                         );
                }
                else printf("The arguments are invalids");
                free(colors);
            }
            else printf("The numbers of arguments are invalids");
            break;
        default:
            printf("No recognized the parameters");
            break;
    }
    
    free(rgb);
}
