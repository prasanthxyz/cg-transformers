OPENGLLIB= -lGL
GLEWLIB= -lGLEW
GLFWLIB = -lglfw3 -lX11 -lXxf86vm -lpthread -lXi -lXrandr
GLUTLIB =-lglut -lGLU -lGL
LIBS=$(OPENGLLIB) $(GLEWLIB) $(GLFWLIB) $(GLUTLIB)
LDFLAGS=-L/usr/local/lib 
CPPFLAGS=-I/usr/local/include

BIN=transformers
SRCS=robot.cpp transformer.cpp 



all: $(BIN)


$(BIN): $(SRCS) $(INCLUDES)
	g++ $(CPPFLAGS) $(SRCS) -o $(BIN) $(LDFLAGS) $(LIBS)

clean:
	rm -f $(BIN)
	rm -f *.o
	rm -f *~


