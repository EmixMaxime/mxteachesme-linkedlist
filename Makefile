# Intro and why make ? https://stackoverflow.com/questions/21548464/how-to-write-a-makefile-to-compile-a-simple-c-program
# http://www.firmcodes.com/linux/write-first-makefile-c-source-code-linux-tutorial/

.PHONY: compile tests run cleantmp

# The compilator
CC      = gcc
# flags for the compilator
CFLAGS  = -g

RM_FOLDER  = rm -fR

# Folders config
DIST    = ./dist
SRC     = ./src
HEADERS = ./src
TESTS   = ./tests
TESTS_DIST = ./tests/dist
LINKEDLIST_EXECUTABLE = linkedlist

$(SRC)/%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADERS)

cleantmp:
	@echo "Cleaning .o files"
	rm -rf $(SRC)/*.o

compile: $(SRC)/os/unix/mx_alloc.o $(SRC)/linkedlist.o $(SRC)/main.o
	gcc -o $(DIST)/$(LINKEDLIST_EXECUTABLE) $?
	# $(MAKE) cleantmp

$(TESTS)/%.o: $(TESTS)/%.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADERS)

tests: $(TESTS)/linkedlistTest.o $(SRC)/linkedlist.o
	gcc -o $(TESTS_DIST)/$(LINKEDLIST_EXECUTABLE) $?

run: tests
	./tests/dist/Binary

# leaks:
# 	valgrind --leak-check=yes ./$(EXECUTABLE)
