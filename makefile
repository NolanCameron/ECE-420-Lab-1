CC = gcc
CFLAGS = -Wall -Werror -Wvla -lpthread -ggdb3
DEPS = main.h lab1_IO.h timer.h
OBJ = main.o matrixgen.o lab1_IO.o

main: main.o
	$(CC) -o $@ $^ $(CFLAGS)
	
.PHONY: matrixgen
matrixgen: matrixgen.o
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: memtest
memtest: main
	valgrind --tool=memcheck --leak-check=yes ./main

.PHONY: threadtest
threadtest: main
	valgrind --tool=helgrind ./main

.PHONY: clean
clean:
	rm -f *.o main matrixgen data_input
