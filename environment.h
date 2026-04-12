#ifndef __ENVIRONMENT__
#define __ENVIRONMENT__

#include <inttypes.h>

typedef struct { // the struct that holds the environment through the execution
                 // of the ARM32 program
    uint32_t reg_array[16]; // array containing the values of the registers
} environment;

void disp_env(environment *ENV);
// display the current environment in the terminal

environment *init_env();
// initialize the environment with 0 as a default value in each register

#endif
