.PHONY: build all clean

all: build run

FLAGS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 

build:
	gcc 3dcube.c -o 3dcube.out $(FLAGS)
	
clean:
	rm -f *.out

run:
	./3dcube.out

