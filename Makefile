CPPFLAGS = -g -std=c++17 -Wall
CPPFILES = $(wildcard src/*.cpp)
LDLIBS = -lSDL2 -lm

all: build

build: $(CPPFILES)
	g++ $(CPPFLAGS) $(CPPFILES) $(LDLIBS) -o main

clean:
	rm -f main
