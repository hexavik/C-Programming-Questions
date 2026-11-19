#include <stddef.h>
#include <stdio.h>
#include <string.h>

char most_frequent_character(const char *str) {
    char result;
    int freq[256] = { 0 };
    int max_freq = 0;

    for (int i = 0; str[i] != '\0'; ++i) {
        unsigned char current = (unsigned char)str[i];
        freq[current]++;

        //
        // Update max frequency
        //
        if (freq[current] > max_freq) {
            max_freq = freq[current];
            result = (char)current;
        }
    }

    return result;
}

int main() {
    const char *str = "programming";
    printf("I/P: \"%s\"\n", str);
    printf("Most frequent character: %c\n",
        most_frequent_character(str));

    return 0;
}
