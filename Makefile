# The CC variable sets C compiler
CC = g++

# The CFLAGS variable sets compile flags for gcc:
CFLAGS = -g -Wall -O0
#  -g        compile with debug information
#  -Wall     give verbose compiler warnings
#  -On       optimization level

# The LDFLAGS variable sets flags for linker
DFLAGS = 

# Files that are part of the project
SOURCES = main.cpp line.cpp
OBJECTS = $(SOURCES:.c=.o)
TARGET = main.out

$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

.PHONY: clean

clean:
	@rm -f $(TARGET) $(OBJECTS) core