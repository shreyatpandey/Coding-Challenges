// Similar type was asked to me in Facebook Embedded Question
//git-link:- https://github.com/goToMain/c-utils/blob/master/include/utils/circbuf.h

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>

/* Definition of struct*/
typedef struct {
    uint8_t * const buffer;
    int head;
    int tail;
    const int maxlen;
} circ_bbuf_t;

/* Push data into circular buffer*/
int circ_bbuf_push(circ_bbuf_t *c, uint8_t data)
{
    int next;

    next = c->head + 1;  // next is where head will point to after this write.
    if (next >= c->maxlen)
        next = 0;

    if (next == c->tail)  // if the head + 1 == tail, circular buffer is full
        return -1;

    c->buffer[c->head] = data;  // Load data and then move
    c->head = next;             // head to next data offset.
    return 0;  // return success to indicate successful push.
}

/* Pop Data from circular buffer*/
int circ_bbuf_pop(circ_bbuf_t *c, uint8_t *data)
{
    int next;

    if (c->head == c->tail)  // if the head == tail, we don't have any data
        return -1;

    next = c->tail + 1;  // next is where tail will point to after this read.
    if(next >= c->maxlen)
        next = 0;

    *data = c->buffer[c->tail];  // Read data and then move
    c->tail = next;              // tail to next offset.
    return 0;  // return success to indicate successful push.
}

