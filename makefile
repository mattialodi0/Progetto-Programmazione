all: main run clean

main: 
	g++ ./src/*.cpp -w -lncursesw -lm -I./include/ -o main.out

run:
	./main.out

clean:
	rm main.out
