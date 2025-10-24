# Embedded Software Engineer, Cellular

## Round 1
### Interviewer: Richard Zhuang

### Questions

#### Background Questions
- General background discussion

#### Cellular / WiFi Questions
1. What happens when there is a Data SIM card instead of Voice based SIM card?
2. How is the Access Point information stored in home network? If you move outside your home network and do not want it to connect to other Access Point except home access point, what should be the scenario in this case?

#### Behavioral Question
- What is an important lesson you have learned in the last 5 years working in a tech company?

#### Coding/Technical Questions

**Q1:** Write C program for finding decimal result when the values are given in binary in the form of linked list?
- Had to run test cases

```c
typedef struct Node {
   int data;
   struct Node *next;
} SingleLinkListNode;

long binaryResult(SingleLinkListNode *binary) {
   /* To Do */
}
```

**Q2:** Implement customary malloc given a heap memory

```c
#define HEAP_SIZE 32 * 1024
extern unsigned char heap[HEAP_SIZE];

void *own_malloc(size_t size) {
   if (size > HEAP_SIZE) {
       return NULL;
   }
   /* To Do */
}

void own_free(void *ptr) {
   /* To Do */
}
```

## Round 2
### Interviewer: Samuel Ahn

### Questions

#### Resume-based Questions
- Asked about my open source contribution to wpa_supplicant, hostapd
- How much of the driver code have you written?

#### Coding Question
**Topic:** Open ended question about netlink operation

```c
struct frame {
   void *frame;
   size_t buffer_len;
};

struct packet {
   uint32_t dest_port;
   uint32_t source_addr;
   uint32_t dest_addr;
};

int read_offset;
int write_offset;
struct frame *ring_buffer_frame[1024];

void frame_written_callback(void);

/*
 * Do declaration as provided in init() function
 */
void initialize_packet(struct frame **ring_buffer, int size, int *read_off, int *write_off, void (*callback)(void));

void init() {
   initialize_packet(ring_buffer_frame, 1024, &read_offset, &write_offset, frame_written_callback);
}

/*
 * dest_port: Dest port at which packet is received
 * buf: buffer to read packet from
 * buf_len: length of the buffer
 * return: return the size of the bytes copied
 */
int read_packet_from_frame(uint32_t dest_port, void *buf, size_t buf_len) {
   /* It is given that frame would have at least one packet */
   /* To Do */
   /* I had tried to implement something similar to this */
    if (!buf || buf_len == 0) return 0;

    int idx = read_offset;
    int end = write_offset;

    // If empty
    if (idx == end) return 0;

    while (idx != end) {
        struct frame *f = ring_buffer_frame[idx];
        if (f && f->frame && f->buffer_len >= sizeof(struct packet)) {
            struct packet *hdr = (struct packet *)f->frame;
            if (hdr->dest_port == dest_port) {
                size_t payload_len = f->buffer_len - sizeof(struct packet);
                size_t to_copy = payload_len < buf_len ? payload_len : buf_len;
                memcpy(buf, (char *)f->frame + sizeof(struct packet), to_copy);

                // Advance read_offset to one past the consumed frame.
                // This will drop frames between original read_offset and idx.
                read_offset = (idx + 1) % RING_SIZE;
                return (int)to_copy;
            }
        }
        idx = (idx + 1) % RING_SIZE;
    }
    return 0; // no matching packet found
}
```

## Round 3
### Interviewer : Rui Ma [EM]

### Questions
 - Give detail about important Wifi 7 feature

#### Coding Question
```C
  Merge Two Sorted Link List
```
```C++
   Use Template parameter to merge two sorted linked list
   /*To Do*/
   template<typename T>
   class Node {
      /* To Do*/
   }

   /*To Do*/
   template<typename K>
   Node<k>* mergeTwoSortedLinkList (Node<K>* head1, Node<K>* head2, Compare())
   {
      /* To Do */
   }

   /* To Do */
   template<typename K>
   void printList(Node<K>* head)


   int main ()
   {
      /* Give Some Values */

      return 0;
   }
```

## Round 4
### Interviewer : David Ng

### Question
 - Discussing about position , what product they are doing, team heirarchy
 - How much experience I have in BL apart from BL Wifi Coex?