#PROJETO LP1

PROG = driver_vector
CC = g++
CPPFLAGS = -O0 -g -W -Wall -std=c++11 -pedantic
OBJS = driver_vector.o
HEADER = ./include/vector.h
SRC_DIR     = ./src/
BIN_DIR     = ./bin/

$(PROG): $(OBJS)
	$(CC) $(OBJS) -o $(PROG)
	mv *.o $(PROG) $(BIN_DIR)

driver_vector.o: $(HEADER)
	$(CC) $(CPPFLAGS) -c $(SRC_DIR)driver_vector.cpp
clean:
	rm -f $(PROG) 
