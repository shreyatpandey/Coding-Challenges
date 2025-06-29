# Function Pointer Examples in C

This document provides practical examples for each major usage of function pointers in C programming.

## 1. Callback Mechanisms

Function pointers enable callback functionality, allowing functions to be passed as arguments.

```c
#include <stdio.h>

// Callback function type
typedef void (*Callback)(int result);

// Functions that can be used as callbacks
void success_callback(int result) {
    printf("Operation successful! Result: %d\n", result);
}

void error_callback(int result) {
    printf("Operation failed! Error code: %d\n", result);
}

// Function that accepts a callback
void perform_operation(int x, int y, Callback callback) {
    int result = x + y;
    if (result > 0) {
        callback(result);  // Call success callback
    } else {
        callback(-1);      // Call error callback
    }
}

int main() {
    perform_operation(5, 3, success_callback);
    perform_operation(-5, -3, error_callback);
    return 0;
}
```

## 2. Polymorphism and Runtime Execution

Function pointers allow runtime decision making for which function to execute.

```c
#include <stdio.h>

// Different shape drawing functions
void draw_circle() { printf("Drawing a circle\n"); }
void draw_square() { printf("Drawing a square\n"); }
void draw_triangle() { printf("Drawing a triangle\n"); }

// Function pointer type
typedef void (*DrawFunction)();

// Runtime shape selection
void draw_shape(int shape_type) {
    DrawFunction shapes[] = {draw_circle, draw_square, draw_triangle};
    
    if (shape_type >= 0 && shape_type < 3) {
        shapes[shape_type]();  // Runtime function selection
    }
}

int main() {
    int user_choice = 1;  // Could come from user input
    draw_shape(user_choice);
    return 0;
}
```

## 3. Function Arrays

Organize related functions in arrays for easy iteration and calling.

```c
#include <stdio.h>

// Menu option functions
void option1() { printf("Executing Option 1\n"); }
void option2() { printf("Executing Option 2\n"); }
void option3() { printf("Executing Option 3\n"); }
void option4() { printf("Executing Option 4\n"); }

// Function pointer array
typedef void (*MenuFunction)();
MenuFunction menu_options[] = {option1, option2, option3, option4};

int main() {
    int choice = 2;  // User selects option 3 (0-indexed)
    int num_options = sizeof(menu_options) / sizeof(menu_options[0]);
    
    if (choice >= 0 && choice < num_options) {
        menu_options[choice]();
    }
    
    return 0;
}
```

## 4. State Machines (Simple Example)

Function pointers make state machine implementation clean and efficient.

```c
#include <stdio.h>

typedef enum { IDLE, ACTIVE, SLEEPING } State;
typedef enum { WAKE_UP, WORK, REST } Event;

// State handler function type
typedef State (*StateHandler)(Event event);

// State handler functions
State idle_handler(Event event) {
    printf("State: IDLE, ");
    switch (event) {
        case WAKE_UP: printf("Event: WAKE_UP -> ACTIVE\n"); return ACTIVE;
        case WORK: printf("Event: WORK -> ACTIVE\n"); return ACTIVE;
        default: printf("Event ignored\n"); return IDLE;
    }
}

State active_handler(Event event) {
    printf("State: ACTIVE, ");
    switch (event) {
        case REST: printf("Event: REST -> SLEEPING\n"); return SLEEPING;
        default: printf("Event ignored\n"); return ACTIVE;
    }
}

State sleeping_handler(Event event) {
    printf("State: SLEEPING, ");
    switch (event) {
        case WAKE_UP: printf("Event: WAKE_UP -> IDLE\n"); return IDLE;
        default: printf("Event ignored\n"); return SLEEPING;
    }
}

int main() {
    StateHandler handlers[] = {idle_handler, active_handler, sleeping_handler};
    State current_state = IDLE;
    
    current_state = handlers[current_state](WAKE_UP);
    current_state = handlers[current_state](REST);
    current_state = handlers[current_state](WAKE_UP);
    
    return 0;
}
```

## 5. Event Handling Systems

Function pointers enable flexible event handling in embedded or GUI systems.

```c
#include <stdio.h>

// Event handler function type
typedef void (*EventHandler)(int data);

// Different event handlers
void button_click_handler(int button_id) {
    printf("Button %d clicked!\n", button_id);
}

void timer_expire_handler(int timer_id) {
    printf("Timer %d expired!\n", timer_id);
}

void sensor_data_handler(int sensor_value) {
    printf("Sensor reading: %d\n", sensor_value);
}

// Event registration structure
typedef struct {
    int event_type;
    EventHandler handler;
} EventRegistration;

// Event system
EventRegistration events[] = {
    {1, button_click_handler},
    {2, timer_expire_handler},
    {3, sensor_data_handler}
};

void trigger_event(int event_type, int data) {
    int num_events = sizeof(events) / sizeof(events[0]);
    for (int i = 0; i < num_events; i++) {
        if (events[i].event_type == event_type) {
            events[i].handler(data);
            break;
        }
    }
}

int main() {
    trigger_event(1, 5);    // Button 5 clicked
    trigger_event(2, 10);   // Timer 10 expired
    trigger_event(3, 75);   // Sensor value 75
    return 0;
}
```

## 6. Algorithm Flexibility

Pass different comparison or processing functions to make algorithms flexible.

```c
#include <stdio.h>

// Comparison function types
typedef int (*CompareFunction)(int a, int b);

// Different comparison functions
int ascending(int a, int b) { return a > b; }
int descending(int a, int b) { return a < b; }

// Generic bubble sort using function pointer for comparison
void bubble_sort(int arr[], int n, CompareFunction compare) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (compare(arr[j], arr[j+1])) {
                // Swap elements
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int numbers[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(numbers) / sizeof(numbers[0]);
    
    printf("Original: ");
    print_array(numbers, n);
    
    bubble_sort(numbers, n, ascending);
    printf("Ascending: ");
    print_array(numbers, n);
    
    bubble_sort(numbers, n, descending);
    printf("Descending: ");
    print_array(numbers, n);
    
    return 0;
}
```

## 7. Plugin Architecture (Simple Example)

Function pointers enable dynamic function loading and plugin systems.

```c
#include <stdio.h>

// Plugin interface
typedef struct {
    char* name;
    void (*initialize)();
    void (*execute)();
    void (*cleanup)();
} Plugin;

// Plugin 1 functions
void audio_init() { printf("Audio plugin initialized\n"); }
void audio_execute() { printf("Playing audio...\n"); }
void audio_cleanup() { printf("Audio plugin cleaned up\n"); }

// Plugin 2 functions
void video_init() { printf("Video plugin initialized\n"); }
void video_execute() { printf("Playing video...\n"); }
void video_cleanup() { printf("Video plugin cleaned up\n"); }

// Plugin registry
Plugin plugins[] = {
    {"Audio Plugin", audio_init, audio_execute, audio_cleanup},
    {"Video Plugin", video_init, video_execute, video_cleanup}
};

void run_plugin(int plugin_id) {
    int num_plugins = sizeof(plugins) / sizeof(plugins[0]);
    if (plugin_id >= 0 && plugin_id < num_plugins) {
        Plugin* p = &plugins[plugin_id];
        printf("\n--- Running %s ---\n", p->name);
        p->initialize();
        p->execute();
        p->cleanup();
    }
}

int main() {
    run_plugin(0);  // Run audio plugin
    run_plugin(1);  // Run video plugin
    return 0;
}
```

## 8. Menu Systems

Function pointers make menu systems clean and maintainable.

```c
#include <stdio.h>

// Menu action functions
void new_file() { printf("Creating new file...\n"); }
void open_file() { printf("Opening file...\n"); }
void save_file() { printf("Saving file...\n"); }
void exit_program() { printf("Exiting program...\n"); }

// Menu item structure
typedef struct {
    char* description;
    void (*action)();
} MenuItem;

// Menu definition
MenuItem main_menu[] = {
    {"1. New File", new_file},
    {"2. Open File", open_file},
    {"3. Save File", save_file},
    {"4. Exit", exit_program}
};

void display_menu() {
    int num_items = sizeof(main_menu) / sizeof(main_menu[0]);
    printf("\n=== Main Menu ===\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s\n", main_menu[i].description);
    }
    printf("Select option: ");
}

void execute_menu_choice(int choice) {
    int num_items = sizeof(main_menu) / sizeof(main_menu[0]);
    if (choice >= 1 && choice <= num_items) {
        main_menu[choice - 1].action();
    } else {
        printf("Invalid choice!\n");
    }
}

int main() {
    display_menu();
    
    // Simulate user choices
    execute_menu_choice(1);  // New File
    execute_menu_choice(3);  // Save File
    execute_menu_choice(4);  // Exit
    
    return 0;
}
```

## Summary

Function pointers in C provide:

- **Flexibility**: Runtime function selection
- **Modularity**: Clean separation of concerns
- **Reusability**: Same framework works with different functions
- **Polymorphism**: Object-oriented-like behavior in C
- **Efficiency**: Avoid large switch statements
- **Extensibility**: Easy to add new functionality

These examples demonstrate how function pointers make C code more maintainable, flexible, and powerful while keeping it efficient and readable.
