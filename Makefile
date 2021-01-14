all: main test
	g++ ./src/main.cpp
	a.out
	@echo "All done!"
		
main: ./src/main.cpp ./include/example.hpp
	g++ -g -Wall -I ./include/ ./src/main.cpp -o ./bin/main

test: ./src/main.cpp
	./bin/main test
	
	
clean:
	rm -rf ./bin/*
