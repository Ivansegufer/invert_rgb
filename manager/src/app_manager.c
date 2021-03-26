#include "../../lib/rgb.h"
#include "../../util/flag_tool.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct APP {
    struct RGB *rgb;
    int arguments_count;
    char **arguments;
};

void init_app(struct APP *app, int argc, char **argv) {
    app -> rgb = malloc(sizeof(struct RGB));
    app -> arguments_count = argc;
    app -> arguments = argv;
}

void generate_default_flag(char *flags) {
    flags = malloc(sizeof(char) * 2);
    flags[0] = '-';
}

char* get_flags(struct APP *app) {
    char *flags;

    for(int i = 0; i < app -> arguments_count; i++) {
        if(app -> arguments[i][0] == '-') {
            flags = split_flags(app -> arguments[i], i);

            if(!validate_flags(flags)) {
                free(flags);
                generate_default_flag(flags);
            }

            break;
        }
        else if(i == app -> arguments_count - 1)
            generate_default_flag(flags);
    } 

    return flags;
}

int* get_rgb_inline(char **argv) {
    int *colors = malloc(sizeof(int) * 3);

    colors[0] = atoi(argv[2]);
    colors[1] = atoi(argv[3]);
    colors[2] = atoi(argv[4]);

    return colors;
}
