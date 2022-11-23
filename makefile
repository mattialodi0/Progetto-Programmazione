game: main.o Time.o Room.o Projectile.o Hero.o Game.o Enemy.o Drawable.o Character.o Board.o Artifact.o Drunk.o Chaser.o GeneralTemplate.o
	g++ -o game main.o Time.o Room.o Projectile.o Hero.o Game.o Enemy.o Drawable.o Character.o Board.o Artifact.o Drunk.o Chaser.o GeneralTemplate.o -lncurses -lstdc++

main.o: main.cpp Game.hpp
	g++ -c main.cpp -lncurses

Game.o: Game.cpp Game.hpp Room.hpp Artifact.hpp
	g++ -c Game.cpp -lncurses

Room.o: Room.cpp Room.hpp Hero.hpp GeneralTemplate.hpp
	g++ -c Room.cpp -lncurses

Time.o: Time.cpp Time.hpp
	g++ -c Time.cpp

Projectile.o: Projectile.cpp Projectile.hpp Character.hpp
	g++ -c Projectile.cpp

Hero.o: Hero.cpp Hero.hpp Character.hpp
	g++ -c Hero.cpp -lncurses

Enemy.o: Enemy.cpp Enemy.hpp Projectile.hpp
	g++: -c Enemy.cpp -lncurses

Drawable.o: Drawable.cpp Drawable.hpp 
	g++ -c Drawable.cpp -lncurses

Character.o: Character.cpp Character.hpp Direction.hpp Board.hpp
	g++ -c Character.cpp -lncurses

Board.o: Board.cpp Board.hpp Drawable.hpp Time.hpp
	g++ -c Board.cpp -lncurses

Artifact.o: Artifact.cpp Artifact.hpp Board.hpp
	g++ -c Artifact.cpp

Drunk.o: Drunk.cpp Drunk.hpp Hero.hpp Enemy.hpp
	g++ -c Drunk.cpp

Chaser.o: Chaser.cpp Chaser.hpp Hero.hpp Enemy.hpp
	g++ -c Chaser.cpp

GeneralTemplate.o: GeneralTemplate.cpp GeneralTemplate.hpp Board.hpp Chaser.hpp Drunk.hpp room_objects/Door.hpp room_objects/Wall.hpp
	g++ -c GeneralTemplate.cpp

clean:
	rm *.o game