CC = clang++
CFLAGS = -std=c++11 -O3 -lglew -lsfml-system -lsfml-graphics -lsfml-window -lsfml-audio -Wall -Wextra -Werror -fexceptions -framework OpenGL -framework GLUT
# CFLAGS = -std=c++11 -O3 -lsfml-system -lsfml-graphics -lsfml-window -lsfml-audio -Wall -Wextra -Werror -fexceptions -isystem /usr/include -isystem /usr/local/include -isystem /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/../lib/c++/v1 -isystem /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include
SRC = Main.cc Engine.cc Input.cc RenderUtil.cc Mesh.cc Renderable.cc Shader.cc Game.cc Transform.cc Camera.cc Util.cc
OBJS = $(patsubst %.cc,objects/%.o,$(SRC))
# OBJS = Engine.o Ball.o

all: baller

baller: $(OBJS)
	$(CC) $(CFLAGS) $^ -o choochoo

objects/%.o: %.cc
	$(CC) -std=c++11 -O3 -c $< -o $@

# objects/Engine.o: Engine.cc
# 	$(CC) -std=c++11 -O3 -c Engine.cc -o objects/Engine.o
#
# objects/ball.o: Ball.cc
# 	$(CC) -std=c++11 -O3 -c Ball.cc -o objects/ball.o

clean:
	rm objects/* choochoo
