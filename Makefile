CC = clang++
CFLAGS = -std=c++11 -O3 -lsfml-system -lsfml-graphics -lsfml-window -lsfml-audio -Wall -Wextra -Werror -fexceptions
# CFLAGS = -std=c++11 -O3 -lsfml-system -lsfml-graphics -lsfml-window -lsfml-audio -Wall -Wextra -Werror -fexceptions -isystem /usr/include -isystem /usr/local/include -isystem /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/../lib/c++/v1 -isystem /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include
OBJS = main_baller.o

all: baller

baller: objects/$(OBJS) Ball.hh
	$(CC) $(CFLAGS) -o main_baller objects/$(OBJS)

objects/main_baller.o: baller_main.cc
	$(CC) -std=c++11 -O3 -c baller_main.cc -o objects/main_baller.o

# objects/ball.o: Ball.hh
# 	$(CC) -c Ball.hh -o objects/ball.o

clean:
	rm objects/* main_baller
