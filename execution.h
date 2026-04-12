#ifndef __EXECUTION__
#define __EXECUTION__

#include "environment.h"
#include "lexical_analysis.h"

void execution(linked_L *list, environment *ENV);
// Execute the ARM script stored in list using ENV
// between each instruction, displays the environment in the shell

#endif