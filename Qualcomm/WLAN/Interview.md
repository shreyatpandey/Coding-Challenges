# Qualcomm WLAN Interview

## Interviewer: Vamsi Krishna

### Q1: Code Analysis

**Question:** What does this code do?

**Version 1:**
```c
void func() 
{
    int *p = 0;
    printf("%d", &p);
    printf("%d", p);
    printf("%d", *p); 
}
```

**Version 2:**
```c
void func() 
{
    int *p;
    p = 0;
    printf("%d", &p);
    printf("%d", p);
    printf("%d", *p);
}
```

**Version 3:**
```c
void func() 
{
    int *p;
    p = NULL;
    printf("%d", &p);
    printf("%d", p);
    printf("%d", *p);
}
```

**Review:** Look up for issue with "int *p = 0". It's one of a unique cases

### Q2: Struct and Compiler Architecture

**Question:** 
```c
struct 
{
    unsigned int a;
    signed char b;
    unsigned short c;
};
```

The moment I said 32-bit and 64-bit compiler. Asked me what does 32-bit and 64-bit compiler does?

## Networking Questions

1. **Q1:** What is the use of RTT?
2. **Q2:** Does RTT affect throughput?
3. **Q3:** What is the use of queue in TCP network?
4. **Q4:** What is DHCP commit during IP allocation?

---

## Interviewer: Purshottam Kushwaha

### Behavioral Questions

1. What did you work on in Qualcomm?
2. More detail on the role of Qualcomm.

### Technical Questions

**Q1:** What is the use of volatile and non volatile variable?

**Q2:** What is variable argument in C? Any known example or library that uses variable argument

**Q3:** What are stacks and queues?

**Q4:** Implement queue using stacks

### Q5: OS Based Questions

1. What is basic difference between mutex and semaphore?
2. If you are streaming video application like youtube and phone comes in, which one would you use out of those two?
3. What is a page fault?
4. What is thrashing?

**Q6: Puzzle**
There are 3 ants on the edge of triangle. What are the chance that they are going to collide?

**Q7:** Find the intersection of two link list

### Q8: Code Debugging

**Question:** Find all the errors in this program

```c
struct connect_params
{
    char *ssid;
    char *password;
    int valid;
}

int returnValue(struct connect_params *params)
{
    if (params->valid && params->ssid)
    {
        //do something
    }
    free(params);
    return 0;
}
```
