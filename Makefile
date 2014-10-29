CC = clang++
CFLAGS = -std=c++11 -O3 -lsfml-system -lsfml-graphics -lsfml-window -lsfml-audio

all: baller

baller: 
	$(CC) $(CFLAGS) -o main_baller baller_main.cpp
