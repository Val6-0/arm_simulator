CC = clang
CFLAGS = -g -Wall -O0

all : main

main.o : main.c reader_lib.h
	$(CC) $(CFLAGS) -c $^

reader_lib.o : reader_lib.c reader_lib.h
	$(CC) $(CFLAGS) -c $^

lexical_analysis.o : lexical_analysis.c lexical_analysis.h reader_lib.h
	$(CC) $(CFLAGS) -c $^

syntax_analysis.o : syntax_analysis.c syntax_analysis.h lexical_analysis.h
	$(CC) $(CFLAGS) -c $^

environment.o : environment.c environment.h
	$(CC) $(CFLAGS) -c $^

execution.o : execution.c execution.h environment.h
	$(CC) $(CFLAGS) -c $^

main : main.o reader_lib.o lexical_analysis.o syntax_analysis.o execution.o environment.o
	$(CC) $(CFLAGS) -o $@ $^

clean :
	rm -f *.o
	rm -f main
	rm -f *.h.gch

test :
	./main test_files/test.s

debug : 
	gdb --args ./main test_files/test.s
