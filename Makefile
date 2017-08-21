
CC = g++
CFLAGXX = -Wall -g3 -std=c++11
OBJS = main.o

all : main

main.o: kmp.cpp
	${CC} ${CFLAGXX} -c $< -o main.o

main: ${OBJS}
	${CC} ${OBJS} -o main 

.PYONY: clean
clean:
	@echo "Removing binary and objects..."
	-rm -rf *.o main core

