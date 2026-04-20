#include "syntax_analysis.h"

#include <stdio.h>
#include <stdlib.h>

void syntax_verification(linked_L *list) {
    while (list->cell_data.word_t != END_LIST) {
        if (list->cell_data.word_t != INST) {
            printf("error during the syntax analysis\n");
            exit(0);
        }
        switch (list->cell_data.inst) {
        case MOV:
            list = list->next;
            if (list->cell_data.word_t != REG) { // MOV dest
                printf("error during the syntax analysis\n");
                exit(0);
            }
            list = list->next;
            if (!(list->cell_data.word_t == COMMA)) { // MOV dest,
                printf("error during the syntax analysis\n");
                exit(0);
            }
            list = list->next;
            if (!(list->cell_data.word_t == REG || // MOV dest, src
                  list->cell_data.word_t == VALUE)) {
                printf("error during the syntax analysis\n");
                exit(0);
            }
            break;
        case ADD:
        case SUB: // the SUB and ADD syntax is the same, the same case is used
                  // to avoid duplicating code
            list = list->next;
            if (list->cell_data.word_t != REG) { // ADD dest
                printf("error during the syntax analysis\n");
                exit(0);
            }
            list = list->next;
            if (!(list->cell_data.word_t == COMMA)) { // ADD dest,
                printf("error during the syntax analysis\n");
                exit(0);
            }
            list = list->next;
            if (list->cell_data.word_t != REG) { // ADD dest, rt
                printf("error during the syntax analysis\n");
                exit(0);
            }
            list = list->next;
            if (!(list->cell_data.word_t == COMMA)) { // ADD dest, rt,
                printf("error during the syntax analysis\n");
                exit(0);
            }
            list = list->next;
            if (!(list->cell_data.word_t == REG ||
                  list->cell_data.word_t == VALUE)) { // ADD dest, rt, rn
                printf("error during the syntax analysis\n");
                exit(0);
            }
            break;
        default:
            printf("error during the syntax analysis\n");
            exit(0);
        }
        list = list->next;
    }
}