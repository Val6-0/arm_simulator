#include "environment.h"

#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

void disp_env(environment *ENV) {
    printf("current environment :\n\n");
    for (int i = 0; i < 16; i++) {
        printf("r%d : %" PRIu32 "\n", i, ENV->reg_array[i]);
    }
    printf("\n");
}

environment *init_env() {
    environment *ENV = calloc(1, sizeof(environment));
    return ENV;
}
