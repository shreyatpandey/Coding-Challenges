const unsigned char TQuickByteMask[8] =
{
   0x01, 0x02, 0x04, 0x08,
   0x10, 0x20, 0x40, 0x80,
};


/** Set bit in any sized bit mask.
 *
 * @return    none
 *
 * @param     bit    - Bit number.
 * @param     bitmap - Pointer to bitmap.
 */
void TSetBit( short bit, unsigned char *bitmap)
{
    short n, x;

    x = bit / 8;        // Index to byte.
    n = bit % 8;        // Specific bit in byte.

    bitmap[x] |= TQuickByteMask[n];        // Set bit.
}


/** Reset bit in any sized mask.
 *
 * @return  None
 *
 * @param   bit    - Bit number.
 * @param   bitmap - Pointer to bitmap.
 */
void TResetBit( short bit, unsigned char *bitmap)
{
    short n, x;

    x = bit / 8;        // Index to byte.
    n = bit % 8;        // Specific bit in byte.

    bitmap[x] &= (~TQuickByteMask[n]);    // Reset bit.
}


/** Toggle bit in any sized bit mask.
 *
 * @return   none
 *
 * @param   bit    - Bit number.
 * @param   bitmap - Pointer to bitmap.
 */
void TToggleBit( short bit, unsigned char *bitmap)
{
    short n, x;

    x = bit / 8;        // Index to byte.
    n = bit % 8;        // Specific bit in byte.

    bitmap[x] ^= TQuickByteMask[n];        // Toggle bit.
}


/** Checks specified bit.
 *
 * @return  1 if bit set else 0.
 *
 * @param   bit    - Bit number.
 * @param   bitmap - Pointer to bitmap.
 */
short TIsBitSet( short bit, const unsigned char *bitmap)
{
    short n, x;

    x = bit / 8;    // Index to byte.
    n = bit % 8;    // Specific bit in byte.

    // Test bit (logigal AND).
    if (bitmap[x] & TQuickByteMask[n])
        return 1;

    return 0;
}


/** Checks specified bit.
 *
 * @return  1 if bit reset else 0.
 *
 * @param   bit    - Bit number.
 * @param   bitmap - Pointer to bitmap.
 */
short TIsBitReset( short bit, const unsigned char *bitmap)
{
    return TIsBitSet(bit, bitmap) ^ 1;
}


/** Count number of bits set in a bitmap.
 *
 * @return   Number of bits set.
 *
 * @param    bitmap - Pointer to bitmap.
 * @param    size   - Bitmap size (in bits).
 *
 * @note    Not very efficient in terms of execution speed. If you are doing
 *        some computationally intense stuff you may need a more complex
 *        implementation which would be faster (especially for big bitmaps).
 *        See (http://graphics.stanford.edu/~seander/bithacks.html).
 */
int TCountBits( const unsigned char *bitmap, int size)
{
    int i, count = 0;

    for (i=0; i<size; i++)
        if (TIsBitSet(i, bitmap))
            count++;

    return count;
}
