/**
 * @file evaluating_string_interleaving.c
 * @author Vikrant (vikrant_ap@hotmail.com)
 * @date 2026-09-25
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool is_interleave(const char *s1, const char *s2, const char *s3) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int len3 = strlen(s3);

    //
    // Lengths must match exactly
    //
    if (len1 + len2 != len3) { return false; }

    //
    // Ensure s2 is the shorter string to minimize space to O(min(len1, len2))
    //
    if (len2 > len1) { return is_interleave(s2, s1, s3); }

    bool *dp = calloc(len2 + 1, sizeof(bool));
    dp[0] = true;

    //
    // Initialize first row (using only characters from s2)
    //
    for (int j = 1; j <= len2; ++j) {
        dp[j] = dp[j - 1] && (s2[j - 1] == s3[j - 1]);
    }

    //
    // Fill the DP table row by row
    //
    for (int i = 1; i <= len1; ++i) {
        //
        // Update first column (using only characters from s1)
        //
        dp[0] = dp[0] && (s1[i - 1] == s3[i - 1]);

        for (int j = 1; j <= len2; ++j) {
            char target = s3[i + j - 1];
            bool match_s1 = dp[j] && (s1[i - 1] == target);
            bool match_s2 = dp[j - 1] && (s2[j - 1] == target);
            dp[j] = match_s1 || match_s2;
        }
    }

    bool result = dp[len2];
    free(dp);
    return result;
}

int main() {
    const char *s1 = "xyz";
    const char *s2 = "789";
    const char *s3 = "x7y8z9";

    printf("s1: \"%s\", s2: \"%s\", Interleaved: \"%s\"\n", s1, s2, s3);
    printf("O/P: %s\n", is_interleave(s1, s2, s3) ? "True" : "False");

    return 0;
}
