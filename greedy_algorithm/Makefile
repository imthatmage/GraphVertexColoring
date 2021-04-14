CC=g++
CFLAGS=-c -Wall -O3 -std=c++20
LDFLAGS=
SOURCES=test_with_all_files.cpp greedy.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=greedy_algorithm

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@