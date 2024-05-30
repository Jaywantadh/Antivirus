# Define variables
CC = gcc
CFLAGS = -I/usr/local/include
LDFLAGS = -L/usr/local/lib -lyara

# Define the final target
engine: engine.o
    $(CC) -o $@ $^ $(LDFLAGS)

# Define how to compile the object file
engine.o: engine.c
    $(CC) -c $< $(CFLAGS)

# Define the clean target
clean:
    rm -f engine engine.o
