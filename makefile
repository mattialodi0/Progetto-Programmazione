OBJS	= main.o Time.o Room.o Projectile.o Hero.o Game.o Enemy.o Drawable.o Character.o Board.o Artifact.o Drunk.o Chaser.o GeneralTemplate.o
SOURCE	= main.cpp Time.cpp Room.cpp Projectile.cpp Hero.cpp Game.cpp Enemy.cpp Drawable.cpp Character.cpp Board.cpp Artifact.cpp Drunk.cpp Chaser.cpp GeneralTemplate.cpp
HEADER	= Direction.hpp Time.hpp Room.hpp Projectile.hpp Hero.hpp Game.hpp Enemy.hpp Drawable.hpp Character.hpp Board.hpp Artifact.hpp Drunk.hpp Chaser.hpp GeneralTemplate.hpp Door.hpp Wall.hpp
OUT	= game
CC	 = g++
FLAGS	 = -g -c 
LFLAGS	 = -lncurses

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp 

Time.o: Time.cpp
	$(CC) $(FLAGS) Time.cpp 

Room.o: Room.cpp
	$(CC) $(FLAGS) Room.cpp 

Projectile.o: Projectile.cpp
	$(CC) $(FLAGS) Projectile.cpp 

Hero.o: Hero.cpp
	$(CC) $(FLAGS) Hero.cpp 

Game.o: Game.cpp
	$(CC) $(FLAGS) Game.cpp 

Enemy.o: Enemy.cpp
	$(CC) $(FLAGS) Enemy.cpp 

Drawable.o: Drawable.cpp
	$(CC) $(FLAGS) Drawable.cpp 

Character.o: Character.cpp
	$(CC) $(FLAGS) Character.cpp 

Board.o: Board.cpp
	$(CC) $(FLAGS) Board.cpp 

Artifact.o: Artifact.cpp
	$(CC) $(FLAGS) Artifact.cpp 

Drunk.o: Drunk.cpp
	$(CC) $(FLAGS) Drunk.cpp 

Chaser.o: Chaser.cpp
	$(CC) $(FLAGS) Chaser.cpp 

GeneralTemplate.o: GeneralTemplate.cpp
	$(CC) $(FLAGS) GeneralTemplate.cpp 


clean:
	rm -f $(OBJS) $(OUT)