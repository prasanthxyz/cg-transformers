OPENGLLIB= -lGL
GLEWLIB= -lGLEW
GLFWLIB = -lglfw3 -lX11 -lXxf86vm -lpthread -lXi -lXrandr
GLUTLIB =-lglut -lGLU -lGL
LIBS=$(OPENGLLIB) $(GLEWLIB) $(GLFWLIB) $(GLUTLIB)
LDFLAGS=-L/usr/local/lib 
CPPFLAGS=-I/usr/local/include

BIN=transformers
SRCS=robot.cpp transformer.cpp gl_framework.cpp display.cpp loadBmpTexture.cpp cube.cpp vertex.cpp
INCLUDES=transformer.hpp gl_framework.hpp display.hpp loadBmpTexture.hpp cube.hpp vertex.hpp


all: $(BIN)


$(BIN): $(SRCS) $(INCLUDES)
	g++ $(CPPFLAGS) $(SRCS) -o $(BIN) $(LDFLAGS) $(LIBS)

clean:
	rm -f $(BIN)
	rm -f *.o
	rm -f *~


