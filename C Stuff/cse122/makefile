CC = gcc
CFLAGS = -g -Wall
OBJFLAGS = -g -Wall -c
MATHLIB = -lm

targets = pivot_binary_search_main
clean_targets = bin_search

all : $(targets)

#creates the object file, pivot_binary_search_functions.o, necessary for compilation with pivot_binary_search_main.c
#Functions imported from pivot_binary_search_functions.c -> pivot_binary_search.h -> driver code: pivot_binary_search_main.c
pivot_binary_search_functions : pivot_binary_search_functions.c pivot_binary_search.h
	$(CC) $(OBJFLAGS) $@.c

pivot_binary_search_main : pivot_binary_search_main.c pivot_binary_search_functions.o pivot_binary_search.h
	$(CC) $(CFLAGS) $@.c pivot_binary_search_functions.o -o bin_search

#clears the object files and executables from the directory.
clean : 
	rm *.o $(clean_targets)

