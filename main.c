#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "manager/app_manager.h"

void flag_handler(char *flags, int argc) {

}

int main(int argc, char **argv) {
    printf("---------- RGB INVERT ----------\n");
    
    struct APP *app = malloc(sizeof(struct APP));
    char *flags;

    init_app(app, argc, argv);
    flags = get_flags(app);

    if(flags[0] == '-') {
        printf("Invalid flag, try again with -i, -m, -f");
        return 1;
    }

    free(app);
    free(flags);
    return 0;
}
