#include <stdio.h>
#include <stdlib.h>

int currentLine, currentCol, currentChar;
FILE* file;

void next() {
    if (!feof(file)) {
        currentChar = fgetc(file);
        if (currentChar != '\n') {
            currentCol++;
        } else {
            currentCol = 1;
            currentLine++;
        }
    } else {
        currentChar = EOF;
    }
}

void init_read(char* file_name) {
    file = fopen(file_name, "r");
    if (file == NULL) {
        printf("error, given file isn't recognized\n");
        exit(0);
    }
    currentLine = 1;
    currentCol = 0;
    next();
}

char current_character() { return currentChar; }

int file_state() { return currentChar == EOF; }

int line_number() { return currentLine; }

int column_number() { return currentCol; }

void end_read() { fclose(file); }