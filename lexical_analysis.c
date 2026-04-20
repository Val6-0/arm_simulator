#include "lexical_analysis.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

linked_L *create_cell() {
    linked_L *list = malloc(sizeof(linked_L));
    return list;
}

linked_L *lexical_verification(char *file_name) {
    init_read(file_name);
    char c_char = current_character();
    automaton_state current_state = START;
    linked_L *head = create_cell();
    linked_L *current_cell = head;
    indexed_list value_tab;
    linked_L *new; // used to create new cells
    int i;         // used as a while loop parameter
    int n;         // used to store the direct values
    while (file_state() != 1) {
        switch (current_state) {
        case START:
            switch (c_char) {
            case '#':
                current_state = DIRECT_VALUE;
                break;
            case 'M':
            case 'm':
                current_state = S_M;
                break;
            case 'r':
            case 'R':
                current_state = S_R;
                break;
            case 'A':
            case 'a':
                current_state = S_A;
                break;
            case 'S':
            case 's':
                current_state = S_S;
                break;
            case ',':
                current_cell->cell_data.word_t = COMMA;
                new = create_cell();
                current_cell->next = new;
                current_cell = current_cell->next;
                break;
            case ' ':
            case '\n':
                break;
            default:
                printf("error during the lexical analysis\n");
                exit(0);
            }
            break;
        case DIRECT_VALUE:
            switch (c_char) {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                value_tab.index = 0;
                value_tab.tab[value_tab.index] = c_char - 48;
                value_tab.index++;
                current_state = S_VALUE;
                break;
            default:
                printf("error during the lexical analysis\n");
                exit(0);
            }
            break;
        case S_VALUE:
            switch (c_char) {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                value_tab.tab[value_tab.index] = c_char - 48;
                value_tab.index++;
                break;
            case ' ':
            case '\n':
                n = 0;
                for (i = 0; i < value_tab.index; i++) {
                    n = n * 10 + value_tab.tab[i];
                }
                current_cell->cell_data.val = n;
                current_cell->cell_data.word_t = VALUE;
                new = create_cell();
                current_cell->next = new;
                current_cell = current_cell->next;
                current_state = START;
                break;
            default:
                printf("error during the lexical analysis\n");
                exit(0);
            }
            break;
        case S_R:
            switch (c_char) {
            case '0':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                current_cell->cell_data.word_t = REG;
                current_cell->cell_data.val = c_char - 48;
                new = create_cell();
                current_cell->next = new;
                current_cell = current_cell->next;
                current_state = START;
                break;
            case '1':
                current_state = S_REG;
                break;
            default:
                printf("error during the lexical analysis\n");
                exit(0);
            }
            break;
        case S_REG:
            switch (c_char) {
            case '0':
                current_cell->cell_data.word_t = REG;
                current_cell->cell_data.val = 10;
                new = create_cell();
                current_cell->next = new;
                current_cell = current_cell->next;
                current_state = S_ENDREG;
                break;
            case '1':
                current_cell->cell_data.word_t = REG;
                current_cell->cell_data.val = 11;
                new = create_cell();
                current_cell->next = new;
                current_cell = current_cell->next;
                current_state = S_ENDREG;
                break;
            case '2':
                current_cell->cell_data.word_t = REG;
                current_cell->cell_data.val = 12;
                new = create_cell();
                current_cell->next = new;
                current_cell = current_cell->next;
                current_state = S_ENDREG;
                break;
            case '3':
                current_cell->cell_data.word_t = REG;
                current_cell->cell_data.val = 13;
                new = create_cell();
                current_cell->next = new;
                current_cell = current_cell->next;
                current_state = S_ENDREG;
                break;
            case '4':
                current_cell->cell_data.word_t = REG;
                current_cell->cell_data.val = 14;
                new = create_cell();
                current_cell->next = new;
                current_cell = current_cell->next;
                current_state = S_ENDREG;
                break;
            case '5':
                current_cell->cell_data.word_t = REG;
                current_cell->cell_data.val = 15;
                new = create_cell();
                current_cell->next = new;
                current_cell = current_cell->next;
                current_state = S_ENDREG;
                break;
            case ',':
                current_cell->cell_data.word_t = REG;
                current_cell->cell_data.val = 1;
                new = create_cell();
                current_cell->next = new;
                current_cell = current_cell->next;

                current_cell->cell_data.word_t = COMMA;
                new = create_cell();
                current_cell->next = new;
                current_cell = current_cell->next;
                current_state = START;
                break;
            case ' ':
            case '\n':
                current_cell->cell_data.word_t = REG;
                current_cell->cell_data.val = 1;
                new = create_cell();
                current_cell->next = new;
                current_cell = current_cell->next;
                current_state = START;
                break;
            default:
                printf("error during the lexical analysis\n");
                exit(0);
            }
            break;
        case S_ENDREG:
            switch (c_char) {
            case ' ':
            case '\n':
                current_state = START;
                break;
            case ',':
                current_cell->cell_data.word_t = COMMA;
                new = create_cell();
                current_cell->next = new;
                current_cell = current_cell->next;
                current_state = START;
                break;
            default:
                printf("error during the lexical analysis\n");
                exit(0);
            }
            break;
        case S_M:
            switch (c_char) {
            case 'O':
            case 'o':
                current_state = S_MO;
                break;
            default:
                printf("error during the lexical analysis\n");
                exit(0);
            }
            break;
        case S_MO:
            switch (c_char) {
            case 'V':
            case 'v':
                current_state = S_MOV;
                break;
            default:
                printf("error during the lexical analysis\n");
                exit(0);
            }
            break;
        case S_MOV:
            switch (c_char) {
            case ' ':
            case '\n':
                current_cell->cell_data.word_t = INST;
                current_cell->cell_data.inst = MOV;
                new = create_cell();
                current_cell->next = new;
                current_cell = current_cell->next;
                current_state = START;
                break;
            default:
                printf("error during the lexical analysis\n");
                exit(0);
            }
            break;
        case S_A:
            switch (c_char) {
            case 'D':
            case 'd':
                current_state = S_AD;
                break;
            default:
                printf("error during the lexical analysis\n");
                exit(0);
            }
            break;
        case S_AD:
            switch (c_char) {
            case 'D':
            case 'd':
                current_state = S_ADD;
                break;
            default:
                printf("error during the lexical analysis\n");
                exit(0);
            }
            break;
        case S_ADD:
            switch (c_char) {
            case ' ':
            case '\n':
                current_cell->cell_data.word_t = INST;
                current_cell->cell_data.inst = ADD;
                new = create_cell();
                current_cell->next = new;
                current_cell = current_cell->next;
                current_state = START;
                break;
            default:
                printf("error during the lexical analysis\n");
                exit(0);
            }
            break;
        case S_S:
            switch (c_char) {
            case 'U':
            case 'u':
                current_state = S_SU;
                break;
            default:
                printf("error during the lexical analysis\n");
                exit(0);
            }
            break;
        case S_SU:
            switch (c_char) {
            case 'B':
            case 'b':
                current_state = S_SUB;
                break;
            default:
                printf("error during the lexical analysis\n");
                exit(0);
            }
            break;
        case S_SUB:
            switch (c_char) {
            case ' ':
            case '\n':
                current_cell->cell_data.word_t = INST;
                current_cell->cell_data.inst = SUB;
                new = create_cell();
                current_cell->next = new;
                current_cell = current_cell->next;
                current_state = START;
                break;
            default:
                printf("error during the lexical analysis\n");
                exit(0);
            }
            break;

        default:
            printf("error during the lexical analysis\n");
            exit(0);
        }
        next();
        c_char = current_character();
    }
    current_cell->cell_data.word_t = END_LIST;
    return head;
}
