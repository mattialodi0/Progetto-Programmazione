all: main run clean

main: 
	g++ -w ./src/*.cpp -lncursesw -lm -I./include/ -o main.out

run:
	./main.out

clean:
	rm main.out
