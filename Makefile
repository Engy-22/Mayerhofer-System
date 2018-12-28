mayerhofer_rankings: main.o Season.o Team.o Game.o
	g++ -g -Wall -Werror -std=c++11 -o mayerhofer_rankings main.o Season.o Team.o Game.o

main.o: main.cpp Season.h
	g++ -g -Wall -Werror -c -std=c++11 main.cpp Season.h

Season.o: Season.cpp Season.h Game.h
	g++ -g -Wall -Werror -c -std=c++11 Season.cpp Season.h Game.h

Team.o: Team.cpp Team.h Game.h
	g++ -g -Wall -Werror -c -std=c++11 Team.cpp Team.h Game.h

Game.o: Game.cpp Game.h
	g++ -g -Wall -Werror -c -std=c++11 Game.cpp Game.h

clean:
	rm -rf *.o *.gch mayerhofer_rankings
