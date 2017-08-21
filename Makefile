
CC = g++
CFLAGXX = -Wall -g3 -std=c++11
OBJS = kmp.o demo.o
INC = .

all : demo

kmp.o: kmp.cpp kmp.h
	${CC} ${CFLAGXX} -c $< -o kmp.o

demo.o: demo.cpp kmp.h demo.h
	${CC} ${CFLAGXX} -c $< -o demo.o

demo: ${OBJS}
	${CC} ${OBJS} -o demo

.PYONY: clean
clean:
	@echo "Removing binary and objects..."
	-rm -rf *.o demo core

