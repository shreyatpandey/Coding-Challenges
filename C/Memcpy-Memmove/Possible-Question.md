# Google Embedded Software Engineer Interview Question: Safe Memory Operations

As a Google interviewer for an Embedded Software Engineer role, I would structure the interview around this code to test your understanding of pointers, memory layout, and defensive programming.

Here is how I would formulate the question, progressing from basic to advanced:

### Phase 1: The Basic Implementation
**"Imagine we are bringing up a new bare-metal board and don't have the standard C library available yet. I need you to implement a function, `custom_memcpy`, that copies `n` bytes from a source address to a destination address."**

*   **What I'm looking for:**
    *   Correct function signature (`void*`, `const void*`, `size_t`).
    *   Casting `void*` to `char*` or `uint8_t*` for byte-wise arithmetic.
    *   Handling `NULL` pointers or `n=0`.

### Phase 2: The "Gotcha" (Overlap)
**"Great. Now, suppose I have a buffer containing the string `ABCDE`. I call your function like this: `custom_memcpy(buffer + 1, buffer, 3)`. What will the buffer contain after this operation?"**

*   **The Trap:** If they implemented a simple forward loop (`for i=0 to n`), the result will be corrupted (e.g., `AAAAA` instead of `AABCE`) because the write to `dest[0]` overwrites `src[1]`.
*   **The Question:** "How would you modify your function to handle this overlapping scenario safely? This is essentially asking you to implement `memmove`."

### Phase 3: The Implementation (Logic Check)
**"Walk me through the logic. When do you need to copy forwards (0 to n), and when do you need to copy backwards (n to 0)?"**

*   **Expected Answer:**
    *   If `dest < src` (or no overlap): Copy **Forward** (low to high).
    *   If `dest > src` (and overlaps): Copy **Backward** (high to low) to preserve data before it gets overwritten.
    *   *Reference to your code:* This matches the logic in your `safe_memmove` function:
        ```c
        if (d > s && d < s + n) {
            // Copy backwards
        } else {
            // Copy forwards
        }
        ```

### Phase 4: Embedded Optimization & Safety (Bonus)
**"Your implementation copies byte-by-byte. On a 32-bit ARM Cortex-M processor, this might be inefficient for large copies. How would you optimize this?"**

*   **Expected Answer:**
    *   Check if `src` and `dest` are aligned (e.g., 4-byte aligned).
    *   Copy 4 bytes (32 bits) at a time using `uint32_t*` pointers, then handle the remaining bytes.
    *   *Self-Correction:* "However, we must be careful with alignment faults if the hardware doesn't support unaligned access."

### Summary of the Interview Question
"Write a thread-safe, robust memory copy function that handles overlapping memory regions correctly. Explain the conditions under which a forward copy vs. a backward copy is required, and discuss how you would optimize it for a specific processor architecture."
