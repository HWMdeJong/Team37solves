all: cargame
	
funnygames: src/funnygames.cpp
	g++ -o bin/funnygames -O3 -std=c++11 src/funnygames.cpp

mixedfractions: src/mixedfractions.cpp
	g++ -o bin/mixedfractions -O3 -std=c++11 src/mixedfractions.cpp

dicegame: src/dicegame.cpp
	g++ -o bin/dicegame -O3 -std=c++11 src/dicegame.cpp

convex: src/convex.cpp
	g++ -o bin/convex -O3 -std=c++11 src/convex.cpp

anti11: src/anti11.cpp
	g++ -o bin/anti11 -O3 -std=c++11 src/anti11.cpp

anti11hard: src/anti11hard.cpp
	g++ -o bin/anti11hard -O3 -std=c++11 src/anti11hard.cpp

frogger: src/frogger.cpp
	g++ -o bin/frogger -O3 -Wall -std=c++11 src/frogger.cpp

cargame: src/cargame.cpp
	g++ -o bin/cargame -O3 -std=c++11 src/cargame.cpp