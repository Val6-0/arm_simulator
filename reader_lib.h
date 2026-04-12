#ifndef __READER_LIB__
#define __READER_LIB__

void init_read(char *file_name);
// Open file_name, if the file doesn't exist, exit with 0

void next();
// Read the next character in the file and stores it

char current_character();
// Return the last character read

int file_state();
// Return 1 if the the end of the file has been reached, 0 if not

int line_number();
// Return the current line number

int column_number();
// Return the current column number

void end_read();
// Close the file

#endif