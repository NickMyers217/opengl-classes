CC = g++
FLAGS = -std=c++11 -pedantic -Wall
LIBS = -lSDL2 -lGL -lGLEW
SOURCEPATH = ./src/
SOURCES = \
		  $(SOURCEPATH)main.cpp \
		  $(SOURCEPATH)game.cpp \
		  $(SOURCEPATH)screen.cpp \
		  $(SOURCEPATH)shader.cpp \
		  $(SOURCEPATH)mesh.cpp
EXECUTABLE = opengl

all:
	$(CC) $(FLAGS) $(SOURCES) -o $(EXECUTABLE) $(LIBS)

clean:
	rm $(EXECUTABLE)
