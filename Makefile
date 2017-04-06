all: funnygames mixedfractions dicegame convex
	
funnygames: src/funnygames.cpp
	g++ -o bin/funnygames -O3 -std=c++11 src/funnygames.cpp

mixedfractions: src/mixedfractions.cpp
	g++ -o bin/mixedfractions -O3 -std=c++11 src/mixedfractions.cpp

dicegame: src/dicegame.cpp
	g++ -o bin/dicegame -O3 -std=c++11 src/dicegame.cpp

convex: src/convex.cpp
	g++ -o bin/convex -O3 -std=c++11 src/convex.cpp