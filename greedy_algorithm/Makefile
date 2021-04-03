CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=test_greedy.cpp greedy.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=greedy_algorithm

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@