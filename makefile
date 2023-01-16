binaries = main.o Time.o Room.o Projectile.o Hero.o Game.o Enemy.o Drawable.o Character.o Board.o Artifact.o Drunk.o Chaser.o Coward.o Boom.o Shooter.o Flyer.o Stalker.o GeneralTemplate.o Menu.o Menu_playing.o


game: $(binaries)
	g++ -o game $(binaries) -lncurses

main.o: main.cpp Game.hpp
	g++ -c main.cpp -lncurses

Game.o: Game.cpp Game.hpp 
	g++ -c Game.cpp -lncurses

Room.o: Room.cpp Room.hpp Hero.hpp 
	g++ -c Room.cpp -lncurses

Time.o: Time.cpp Time.hpp
	g++ -c Time.cpp

Projectile.o: Projectile.cpp Projectile.hpp
	g++ -c Projectile.cpp

Hero.o: Hero.cpp Hero.hpp Character.hpp
	g++ -c Hero.cpp -lncurses

Drawable.o: Drawable.cpp Drawable.hpp 
	g++ -c Drawable.cpp -lncurses

Character.o: Character.cpp Character.hpp 
	g++ -c Character.cpp -lncurses

Board.o: Board.cpp Board.hpp 
	g++ -c Board.cpp -lncurses

Enemy.o: Enemy.cpp Enemy.hpp
	g++ -c Enemy.cpp 

Artifact.o: Artifact.cpp Artifact.hpp 
	g++ -c Artifact.cpp

Drunk.o: Drunk.cpp Drunk.hpp 
	g++ -c Drunk.cpp

Chaser.o: Chaser.cpp Chaser.hpp 
	g++ -c Chaser.cpp

Coward.o: Coward.cpp Coward.hpp 
	g++ -c Coward.cpp

Boom.o: Boom.cpp Boom.hpp
	g++ -c Boom.cpp

Shooter.o: Shooter.cpp Shooter.hpp
	g++ -c Shooter.cpp

Flyer.o: Flyer.cpp Flyer.hpp
	g++ -c Flyer.cpp

Stalker.o: Stalker.cpp Stalker.hpp
	g++ -c Stalker.cpp

GeneralTemplate.o: GeneralTemplate.cpp GeneralTemplate.hpp 
	g++ -Iroom_objects -c GeneralTemplate.cpp

Menu.o: Menu.cpp Menu.hpp
	g++ -c Menu.cpp

Menu_playing.o: Menu_playing.cpp Menu_playing.hpp
	g++ -c Menu_playing.cpp



.PHONY: clean

clean:
	rm -f $(binaries) *.o
	echo clean done