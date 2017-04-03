all: funnygames mixedfractions dicegame
	
funnygames: src/funnygames.cpp
	g++ -o bin/funnygames -O3 -std=c++11 src/funnygames.cpp

mixedfractions: src/mixedfractions.cpp
	g++ -o bin/mixedfractions -O3 -std=c++11 src/mixedfractions.cpp

dicegame: src/dicegame.cpp
	g++ -o bin/dicegame -O3 -std=c++11 src/dicegame.cpp