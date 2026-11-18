/**
 * @file minimizing_palindromic_partitions.c
 * @author Vikrant (vikrant_ap@hotmail.com)
 * @date 2026-09-23
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min_cut(const char *str) {
    int len = strlen(str);
    if (len <= 1) { return 0; }

    //
    // dp[i] stores the minimum cuts needed for prefix s[0...i]
    //
    int *dp = malloc(len * sizeof(int));

    //
    // Worst case: every character is cut individually (i cuts for index i)
    //
    for (int i = 0; i < len; ++i) {
        dp[i] = i;
    }

    for (int center = 0; center < len; ++center) {
        //
        // 1. Odd-length palindromes centered at 'center'
        //
        int left = center;
        int right = center;
        while (left >= 0 && right < len && str[left] == str[right]) {
            int new_cuts = (left == 0) ? 0 : (dp[left - 1] + 1);
            if (new_cuts < dp[right]) { dp[right] = new_cuts; }
            left--;
            right++;
        }

        //
        // 2. Even-length palindromes centered between 'center' and 'center + 1'
        //
        left = center;
        right = center + 1;
        while (left >= 0 && right < len && str[left] == str[right]) {
            int new_cuts = (left == 0) ? 0 : (dp[left - 1] + 1);
            if (new_cuts < dp[right]) { dp[right] = new_cuts; }
            left--;
            right++;
        }
    }

    int result = dp[len - 1];
    free(dp);
    return result;
}

int main() {
    const char *str = "kjfhgadskjfghfhfjjjjhjjhdjfhdk";
    printf("I/P: \"%s\"\n", str);
    printf("O/P: %d\n", min_cut(str));

    return 0;
}
