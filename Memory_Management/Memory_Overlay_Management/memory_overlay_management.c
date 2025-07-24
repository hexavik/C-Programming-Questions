#include <stdio.h>
#include <string.h>

enum {
    OVERLAY_SIZE = 1024,
};

typedef enum {
    OVERLAY1 = 1,
    OVERLAY2,
} OVERLAY_NUM;

//
// Fixed size of the dummy memory
//
unsigned char memory[OVERLAY_SIZE] = {0};

//
// Instead of files or programs, we are using strings
//
const char string1[] = "Overlay1 code/data...";
const char string2[] = "Overlay 2 doing other things...";

//
// Function pointer
//
typedef void (*overlay_func_t)(void);

void overlay1_run() {
    printf("Running overlay 1...\n");
    memset(memory, 0, OVERLAY_SIZE);
    memcpy(memory, string1, strlen(string1));
}

void overlay2_run() {
    printf("Running overlay 2...\n");
    memset(memory, 0, OVERLAY_SIZE);
    memcpy(memory, string2, strlen(string2));
}

overlay_func_t overlays[] = {
    NULL,           // index 0 unused
    overlay1_run,   // Overlay 1
    overlay2_run,   // Overlay 2
};

OVERLAY_NUM active_overlay = 0;
overlay_func_t active_func = NULL;

void load_overlay(OVERLAY_NUM overlay_idx) {
    active_overlay = overlay_idx;
    active_func = overlays[overlay_idx];
}

void run_active_overlay() {
    if (active_func) {
        active_func();
    } else {
        printf("No active overlay loaded\n");
    }
}

void print_memory() {
    printf("Memory: ");
    for (int i = 0; i < OVERLAY_SIZE; ++i) {
        printf("%c", memory[i]);
    }
    printf("\n\n");
}

int main() {
    // Try to run active overlay which gives us an error
    run_active_overlay();

    load_overlay(OVERLAY1);
    run_active_overlay();
    print_memory();

    load_overlay(OVERLAY2);
    run_active_overlay();
    print_memory();

    return 0;
}
