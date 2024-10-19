# Makefile for building the writer application

# Define the target executable and source files
SRC_DIR= finder-app
SRC_DIR2 = assignment-autotest/test/assignment2
TARGET1 = $(SRC_DIR)/writer
TARGET2 = $(SRC_DIR2)/writer
SRC = $(SRC_DIR)/writer.c

# Object files
OBJ = $(SRC:.c=.o)

# Compiler and flags
CC = $(CROSS_COMPILE)gcc
CFLAGS = -Wall -Werror -g

# Default target that builds the writer application
all: $(TARGET1) $(TARGET2)

# Rule to build the writer application
$(TARGET1): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)

# Rule to build the second writer application
$(TARGET2): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)

# Rule to compile .c files into .o files
$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up target: remove writer and object files
clean:
	rm -f $(TARGET1) $(TARGET2) $(OBJ)

# Enable cross-compilation if CROSS_COMPILE is specified
.PHONY: all clean
