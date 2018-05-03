all: exec

exec: vector.cpp
	g++ -Wall -std=c++11 vector.cpp -o exec

clean:
	rm -rf *.o *~ exec
