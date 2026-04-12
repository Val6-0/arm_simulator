#include "execution.h"

#include <stdio.h>
#include <stdlib.h>

#include "environment.h"

void execution(linked_L *list, environment *ENV) {
    int reg_mem;
    while (list->cell_data.word_t != END_LIST) {
        switch (list->cell_data.inst) {
        case MOV:
            list = list->next;
            reg_mem = list->cell_data.val;
            list = list->next;
            list = list->next;
            switch (list->cell_data.word_t) {
            case REG:
                ENV->reg_array[reg_mem] = ENV->reg_array[list->cell_data.val];
                break;
            case VALUE:
                ENV->reg_array[reg_mem] = list->cell_data.val;
                break;
            default:
                printf("error during execution (shouldn't be possible)\n");
                exit(0);
                break;
            }
            list = list->next;
            break;
        default:
            printf("error during execution (shouldn't be possible)\n");
            exit(0);
            break;
        }
        disp_env(ENV);
    }
}