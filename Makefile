CPPFLAGS = -g -std=c++17 -Wall
CPPFLAGS_RELEASE = -O3 -std=c++17

CPPFILES = $(wildcard src/*.cpp)
LDLIBS = -lSDL2 -lm

all: build

build: $(CPPFILES)
	g++ $(CPPFLAGS) $(CPPFILES) $(LDLIBS) -o main

release: $(CPPFILES)
	g++ $(CPPFLAGS_RELEASE) $(CPPFILES) $(LDLIBS) -o main

clean:
	rm -f main
