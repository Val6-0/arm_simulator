#ifndef __LEXICAL__
#define __LEXICAL__

#include <inttypes.h>

#include "reader_lib.h"

typedef enum { // different word types
    INST,      // instruction
    REG,       // register, r1 is stored as 1
    VALUE,     // direct value, #10 is stored as 10
    END_LIST   // used to specify the end of the linked list
} word_type;

typedef enum {
    START,
    DIRECT_VALUE,
    S_VALUE,
    S_R,
    S_REG,
    S_ENDREG,
    S_M,
    S_MO,
    S_MOV
} automaton_state;

typedef enum { // different instructions types
    MOV
} inst_type; // for all instructions syntax, refer to the readme

typedef struct {
    int index;
    int tab[1000];
} indexed_list;

typedef struct {
    word_type word_t; // the type of word stored in the cell
    inst_type inst;   // used only if word_t is INST, if so stores the
                      // instruction type
    uint32_t val;     // used only if word_t is VALUE or REG, if so
                      // stores the corresponding value
} cell;

typedef struct list {  // whole ARM script stored as a linked list
    struct list *next; // pointer to the next linked list cell
    cell cell_data;    // the data corresponding to this specific cell
} linked_L;

linked_L *create_cell();
// create a new linked list cell, with no initialized values, then returns the
// adress of said cell

linked_L *lexical_verification(char *file_name);
// read the ARM32 program and applies the lexical verification
// if a lexical error is detected, print an error message then exit with code 0
// if the lexical verification is succesful, a linked list containing the
// program is returned

#endif