#include <stdio.h>
#include <stdlib.h>

#include "environment.h"
#include "execution.h"
#include "lexical_analysis.h"
#include "reader_lib.h"
#include "syntax_analysis.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("error, use : ./main xxxxx.s\n");
        return 1;
    }
    linked_L *list = lexical_verification(argv[1]);
    syntax_verification(list);
    environment *ENV = init_env();
    execution(list, ENV);
    return 0;
}
