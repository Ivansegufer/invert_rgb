#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define INLINE 'i'
#define MULTIPLE 'm'
#define FILE_TAS 'f'

char* split_flags(char *argument, int position) {
    char *flags;

    int len = strlen(argument);
    flags = malloc(sizeof(char) * len - 1);

    for(int i = 1; i < len; i++)
        flags[i - 1] = argument[i];   

    return flags;
}

bool validate_flags(char *flags) {
    int len = strlen(flags);
    bool flags_valids = true; 

    for (int i = 0; i < len; i++) {
        if(!((flags[i] == INLINE) || (flags[i] == MULTIPLE) || (flags[i] == FILE_TAS))) {
            flags_valids = false; 
            break;
        }
    }

    return flags_valids;
}
