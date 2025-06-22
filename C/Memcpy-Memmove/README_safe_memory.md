# Safe Memory Operations in C

This program implements safe versions of `memcpy` and `memmove` functions that handle overlapping source and destination memory regions correctly.

## Features

### 1. Safe memcpy (`safe_memcpy`)
- Detects overlapping memory regions using pointer arithmetic
- Automatically falls back to `safe_memmove` when overlap is detected
- Provides warnings when overlap is encountered
- Returns NULL-safe (handles NULL pointers gracefully)

### 2. Safe memmove (`safe_memmove`) 
- Handles overlapping memory regions by choosing the correct copy direction
- Forward overlap: Copies from end to beginning to avoid corruption
- Backward overlap: Copies from beginning to end
- Null-safe and handles edge cases

## Key Implementation Details

### Overlap Detection
```c
// Check for overlap using pointer arithmetic
uintptr_t dest_start = (uintptr_t)dest;
uintptr_t dest_end = dest_start + n - 1;
uintptr_t src_start = (uintptr_t)src;
uintptr_t src_end = src_start + n - 1;

// Ranges overlap if one starts before the other ends
if ((dest_start <= src_end) && (src_start <= dest_end)) {
    // Handle overlap
}
```

### Copy Direction Logic
- **Forward overlap** (dest > src): Copy backwards (end to beginning)
- **Backward overlap** (dest < src): Copy forwards (beginning to end)
- **No overlap**: Copy in any direction (forwards chosen)

## Test Cases Included

1. **No Overlap**: Standard memory copy between separate buffers
2. **Forward Overlap**: Destination ahead of source in memory
3. **Backward Overlap**: Destination before source in memory  
4. **Edge Cases**: NULL pointers, zero size, same source/destination
5. **Performance Test**: Comparison with standard library functions

## Compilation and Usage

### Using GCC directly:
```bash
gcc -Wall -Wextra -std=c99 -o safe_memory_operations safe_memory_operations.c
./safe_memory_operations
```

### Using the provided Makefile:
```bash
make          # Build the program
make run      # Build and run
make debug    # Build with debug symbols
make clean    # Clean build artifacts
```

## Sample Output

The program demonstrates various scenarios:

```
=== Testing Overlap Scenarios ===

Test 1: No overlap
Source: 48 65 6C 6C 6F 20 57 6F 72 6C 64 21 
Destination: 48 65 6C 6C 6F 20 57 6F 72 6C 64 21 
Result: Hello World!

Test 2: Forward overlap (destination ahead of source)
WARNING: Overlapping memory regions detected in memcpy!
Source: 0x... to 0x..., Destination: 0x... to 0x...
Using memmove for safe operation...
```

## Safety Features

- **Null Pointer Protection**: Handles NULL source/destination pointers
- **Zero Size Protection**: Safely handles zero-byte operations
- **Overlap Detection**: Automatically detects and handles memory overlaps
- **Warning System**: Alerts users when potentially unsafe operations are detected

## Performance Considerations

The safe implementations include additional overlap checking overhead:
- Typical overhead: ~5-10x for small copies due to safety checks
- Overhead decreases for larger copies as the actual copying dominates
- Critical for correctness in systems programming where memory safety is paramount

## Use Cases

- System programming where memory safety is critical
- Embedded systems with limited debugging capabilities
- Educational purposes to understand memory operations
- Defensive programming in production code
- Memory-mapped I/O operations where overlap might occur

## Educational Value

This implementation demonstrates:
- Pointer arithmetic and memory layout understanding
- Overlap detection algorithms
- Safe memory manipulation techniques
- Edge case handling in C programming
- Performance vs safety trade-offs
