/**
 * @file reversing_words_in_a_sentence_without_libraries.c
 * @author Vikrant (vikrant_ap@hotmail.com)
 * @date 2026-09-20
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#include <stdio.h>

void reverse_segment(char* start, char* end) {
    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

void reverse_words(char* str) {
    if (!str || *str == '\0') { return; }

    //
    // Find the end of the string to reverse the whole thing
    //
    char* end = str;
    while (*end != '\0') { end++; }
    end--; // Step back to the last actual character before '\0'

    reverse_segment(str, end);

    //
    // Scan through the reversed string and reverse each word individually
    //
    char* word_start = str;
    char* current = str;

    while (*current != '\0') {
        //
        // If we find a space, it marks the end of the current word
        //
        if (*current == ' ') {
            reverse_segment(word_start, current - 1);
            word_start = current + 1; // Set start point for the next word
        }
        current++;
    }

    //
    // Don't forget to reverse the very last word of the sentence
    //
    reverse_segment(word_start, current - 1);
}

int main() {
    //
    // Must use a mutable array (char[]), not a string literal (char*)
    //
    char sentence[] = "Quick brown fox jumps over the dog";

    printf("Input: \"%s\"\n", sentence);
    reverse_words(sentence);
    printf("Reversed: \"%s\"\n", sentence);

    return 0;
}
