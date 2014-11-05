OPENGLLIB= -lGL
GLEWLIB= -lGLEW
GLFWLIB = -lglfw3 -lX11 -lXxf86vm -lpthread -lXi -lXrandr -lGLU
LIBS=$(OPENGLLIB) $(GLEWLIB) $(GLFWLIB)
LDFLAGS=-L/usr/local/lib 
CPPFLAGS=-I/usr/local/include

BIN=transformers
SRCS=bmp.cpp drawing.cpp gl_framework.cpp robot.cpp texture.cpp transformer.cpp transformer_display.cpp world.cpp light.cpp animation.cpp
INCLUDES=bmp.hpp drawing.hpp gl_framework.hpp texture.hpp transformer.hpp world.hpp light.hpp animation.hpp


all: $(BIN)


$(BIN): $(SRCS) $(INCLUDES)
	g++ $(CPPFLAGS) $(SRCS) -o $(BIN) $(LDFLAGS) $(LIBS)

clean:
	rm -f $(BIN)
	rm -f *.o
	rm -f *~


