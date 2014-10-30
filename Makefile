CC = clang++
CFLAGS = -std=c++11 -O3 -lsfml-system -lsfml-graphics -lsfml-window -lsfml-audio -Wall -Wextra -Werror -fexceptions
# CFLAGS = -std=c++11 -O3 -lsfml-system -lsfml-graphics -lsfml-window -lsfml-audio -Wall -Wextra -Werror -fexceptions -isystem /usr/include -isystem /usr/local/include -isystem /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/../lib/c++/v1 -isystem /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include
SRC = baller_main.cc Ball.cc
OBJS = $(patsubst %.cc,objects/%.o,$(SRC))
# OBJS = baller_main.o Ball.o

all: baller

baller: $(OBJS)
	$(CC) $(CFLAGS) $^ -o main_baller

objects/%.o: %.cc
	$(CC) -std=c++11 -O3 -c $< -o $@

# objects/baller_main.o: baller_main.cc
# 	$(CC) -std=c++11 -O3 -c baller_main.cc -o objects/baller_main.o
#
# objects/ball.o: Ball.cc
# 	$(CC) -std=c++11 -O3 -c Ball.cc -o objects/ball.o

clean:
	rm objects/* main_baller
