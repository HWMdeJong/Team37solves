all: funnygames
	
funnygames: src/funnygames.cpp
	g++ -o bin/funnygames -O3 -std=c++11 src/funnygames.cpp