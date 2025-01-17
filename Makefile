# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -g

# Target executable
TARGET = a

# Default rule
all: $(TARGET)

# Build rule
$(TARGET): stack.c
	$(CC) $(CFLAGS) -o $(TARGET) stack.c

# OS-specific commands
ifeq ($(OS),Windows_NT)
    # Windows clean command
    CLEAN_CMD = del /f $(TARGET).exe
else
    # Linux clean command
    CLEAN_CMD = rm -f $(TARGET).exe
endif

# Clean rule
clean:
	$(CLEAN_CMD)