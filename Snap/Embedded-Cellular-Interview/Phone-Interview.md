# Embedded Cellular Interview

## Interview Details
- **Interviewer Name:** JJ Robertson
- **Total Time:** 1 hour

## Questions
### Initial Confirmation
- Made him confirm with C as the choice of programming language, he was fine with that.
- Sample question was to ask about the queue which is thread-safe and has synchronization.

### Follow-Up Questions
1. I told him if circular queue was what he was looking for.
   - Interviewer was fine with that.
2. What type of data type he was looking for?
   - Interviewer answered with `uint64_t`.

## Interactive Session
1. What are the possible issues of race conditions (referred to producer and consumer)?
2. How does semaphore signal?
3. In producer, how can we assure that there are no race conditions being observed?
   - Here the order of `sem_wait` and `pthread_mutex_lock` was important.
   - These conditions are taken into consideration:
     1. When the queue is empty.
     2. When the queue is full.

## Code Template
```c
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/* Thread Purpose */
OS_MutexInit(mutex *m);
OS_MutexGive(mutex *m);
OS_MutexTake(mutex *m);

/* Semaphore Purpose */
OS_SemInit(sem *s, size_t initial_count);
OS_SemWait(sem *s);
OS_SemPost(sem *s);

/* To Do: Fill in the member variable of queue */
typedef struct {

} queue_t;

/* To Do */
typedef void init(queue_t *q, size_t capacity) {

}

/* To Do */
void enReceive(queue_t *q, int value) {

}

/* To Do */
int deleteElement(queue_t *q) {

}

int main () {
    queue_t q[];
    init(&q, 64);

}
```
