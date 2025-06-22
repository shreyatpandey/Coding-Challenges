# Makefile for Safe Memory Operations

CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -O2
TARGET = safe_memory_operations
SOURCE = safe_memory_operations.c

# Default target
all: $(TARGET)

# Build the executable
$(TARGET): $(SOURCE)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCE)

# Clean build artifacts
clean:
	rm -f $(TARGET)

# Run the program
run: $(TARGET)
	./$(TARGET)

# Debug build
debug: CFLAGS += -g -DDEBUG
debug: $(TARGET)

# Help target
help:
	@echo "Available targets:"
	@echo "  all     - Build the program (default)"
	@echo "  clean   - Remove build artifacts"
	@echo "  run     - Build and run the program"
	@echo "  debug   - Build with debug symbols"
	@echo "  help    - Show this help message"

.PHONY: all clean run debug help
