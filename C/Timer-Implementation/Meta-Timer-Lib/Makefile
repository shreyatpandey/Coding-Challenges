# Makefile for Single Hardware Timer Implementation

CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g
DEBUG_FLAGS = -DDEBUG

# Target executables
TARGET = single_hw_timer_test
TARGET_DEBUG = single_hw_timer_test_debug

# Source files
SOURCES = single_hw_timer.c single_hw_timer_example.c
OBJECTS = $(SOURCES:.c=.o)
DEBUG_OBJECTS = $(SOURCES:.c=_debug.o)

# Header files
HEADERS = single_hw_timer.h

# Default target
all: $(TARGET)

# Build with debug output
debug: $(TARGET_DEBUG)

# Build release version
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^
	@echo "Build complete: $(TARGET)"

# Build debug version
$(TARGET_DEBUG): $(DEBUG_OBJECTS)
	$(CC) $(CFLAGS) $(DEBUG_FLAGS) -o $@ $^
	@echo "Debug build complete: $(TARGET_DEBUG)"

# Compile release object files
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Compile debug object files
%_debug.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) $(DEBUG_FLAGS) -c $< -o $@

# Run the test
run: $(TARGET)
	./$(TARGET)

# Run the debug version
run-debug: $(TARGET_DEBUG)
	./$(TARGET_DEBUG)

# Clean build artifacts
clean:
	rm -f $(OBJECTS) $(DEBUG_OBJECTS) $(TARGET) $(TARGET_DEBUG)
	@echo "Clean complete"

# Rebuild everything
rebuild: clean all

# Show help
help:
	@echo "Available targets:"
	@echo "  all        - Build release version (default)"
	@echo "  debug      - Build debug version with verbose output"
	@echo "  run        - Build and run release version"
	@echo "  run-debug  - Build and run debug version"
	@echo "  clean      - Remove all build artifacts"
	@echo "  rebuild    - Clean and rebuild"
	@echo "  help       - Show this help message"

.PHONY: all debug run run-debug clean rebuild help
