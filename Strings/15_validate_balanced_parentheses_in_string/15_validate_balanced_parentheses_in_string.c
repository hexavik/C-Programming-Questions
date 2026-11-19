/**
 * @file validating_balanced_parentheses_in_a_string.c
 * @author Vikrant (vikrant_ap@hotmail.com)
 * @date 2026-09-20
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#include <stddef.h>
#include <stdio.h>

bool is_balanced(const char* str) {
    if (!str) { return false; }

    //
    // Estimate max stack size based on string length to save memory safely
    // (A stack can never grow larger than the length of the string)
    //
    size_t len = 0;
    while (str[len] != '\0') { len++; }

    char stack[len];
    int top = -1; // Index of the top element (-1 means empty stack)

    for (size_t i = 0; str[i] != '\0'; ++i) {
        char ch = str[i];

        //
        // If it's an opening bracket, push it to the stack
        //
        if (ch == '(' || ch == '{' || ch == '[') { stack[++top] = ch; }

        //
        // If it's a closing bracket, validate and pop
        //
        else if (ch == ')' || ch == '}' || ch == ']') {
            //
            // If stack is empty, there's no matching opening bracket
            //
            if (top == -1) { return false; }

            char open = stack[top--]; // Pop the top element

            //
            // Check if the opening bracket matches the current closing bracket
            //
            if ((ch == ')' && open != '(') ||
                (ch == '}' && open != '{') ||
                (ch == ']' && open != '[')) { return false; }
        }
        //
        // Non-bracket character (like letters or spaces) are simply ignored
    }

    //
    // If the stack is empty, everything was balaneced correctly
    //
    return (top == -1);
}

int main() {
    const char* str1 = "()[{}]";
    const char* str2 = "([)]";      // Incorrect nesting
    const char* str3 = "((";        // Unclosed brackets
    const char* str4 = "a(b[c]d)e"; // Mixing text and brackets

    printf("Input: \"%s\" → Output: %s\n",
        str1, is_balanced(str1) ? "True" : "False");
    printf("Input: \"%s\" → Output: %s\n",
        str2, is_balanced(str2) ? "True" : "False");
    printf("Input: \"%s\" → Output: %s\n",
        str3, is_balanced(str3) ? "True" : "False");
    printf("Input: \"%s\" → Output: %s\n",
        str4, is_balanced(str4) ? "True" : "False");

    return 0;
}
