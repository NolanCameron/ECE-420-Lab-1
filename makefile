CC = gcc
CFLAGS = -Wall -Werror -Wvla -lpthread -ggdb3 -lm
DEPS = main.h lab1_IO.h timer.h
OBJ = main.o lab1_IO.o

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
	
.PHONY: matrixgen
matrixgen: matrixgen.o
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: memtest
memtest: main
	valgrind --tool=memcheck --leak-check=yes ./main 1

.PHONY: threadtest
threadtest: main
	valgrind --tool=helgrind ./main

.PHONY: clean
clean:
	rm -f *.o main matrixgen data_input
