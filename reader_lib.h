#ifndef __READER_LIB__
#define __READER_LIB__

void init_read(char* file_name);
// begin the reading of file_name
// if the file name isn't correct, exit with 0

void next();
// read the next character in the file and stores it

char current_character();
// return the last character read

int file_state();
// return 1 if the the end of the file has been reached, 0 if not

int line_number();
// return the current line number

int column_number();
// return the current column number

void end_read();
// stop the reading of the file

#endif