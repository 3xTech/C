# Define the compiler
CC = gcc

# Define the flags
CFLAGS = -Wall

# Define the target executable
TARGET = hello

# Define the source files
SOURCES = hello.c

# Default rule to build the target
all: $(TARGET)

$(TARGET): $(SOURCES)
    $(CC) $(CFLAGS) -o $(TARGET) $(SOURCES)

# Clean rule to remove compiled files
clean:
    rm -f $(TARGET)
