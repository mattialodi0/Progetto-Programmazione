game: main.o Game.o Room.o 
	g++ -o game main.o Game.o Room.o -lncurses -lstdc++

main.o: main.cpp Game.hpp Board.hpp Drawable.hpp
	g++ -c main.cpp -lncurses

Game.o: Game.cpp Game.hpp Room.hpp Board.hpp Hero.hpp
	g++ -c Game.cpp -lncurses

Room.o: Room.cpp Room.hpp RoomTemplates.hpp
	g++ -c Room.cpp -lncurses

clean:
	rm *.o game