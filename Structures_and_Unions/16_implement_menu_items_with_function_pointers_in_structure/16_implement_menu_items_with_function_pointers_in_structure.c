/**
 * @file menu_item_function_pointer.c
 * @author Vikrant (vikrant_ap@hotmail.com)
 * @date 2026-08-30
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#include <stdio.h>
#include <string.h>

//
// Define a function poitner type that takes no arguments and returns void
//
typedef void (*MenuAction)();

//
// Define the structure representing a menu item
//
typedef struct {
    char name[30];     // Name of the menu option
    MenuAction action; // Pointer to the function to execute
} MenuItem;

//
// Define the action functions
//
void executeOption1() {
    printf("O/P: \"Option1 Executed\"\n");
}

void executeOption2() {
    printf("O/P: \"Option2 Executed\"\n");
}

void executeOption3() {
    printf("O/P: \"Option3 Executed\"\n");
}

int main() {
    //
    // Create an array of MenuItem structures (navigation menu)
    // 
    MenuItem menu[] = {
        { "Option1", executeOption1 },
        { "Option2", executeOption2 },
        { "Option3", executeOption3 }
    };
    int menu_size = sizeof(menu) / sizeof(menu[0]);

    //
    // Simulating user input selection
    // 
    char user_input[] = "Option2";
    printf("I/P: Select: \"%s\"\n", user_input);

    // 
    // Search for the selected menu item and execute its associated function
    // 
    int found = 0;
    for (int i = 0; i < menu_size; ++i) {
        if (strcmp(menu[i].name, user_input) == 0) {
            menu[i].action(); // Invoke the function pointer
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Error: Menu item not found.\n");
    }

    return 0;
}
