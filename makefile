game: main.o Game.o Board.o Room.o 
	gcc -o game main.o Game.o Board.o Room.o -lncurses -lstdc++

main.o: main.cpp Game.hpp
	gcc -c main.cpp -lncurses

Game.o: Game.cpp Game.hpp Room.hpp Board.hpp 
	gcc -c Game.cpp -lncurses

Board.o: Board.cpp Board.hpp 
	gcc -c Board.cpp -lncurses

Room.o: Room.cpp Room.hpp RoomTemplates.hpp 
	gcc -c Room.cpp -lncurses

clean:
	rm *.o game