#include "kmp_algorithm.h"

/* Longest Prefix Suffix Algorithm
    Essentially KMP Algorithm on the pattern itself
    Check each char to see if it and its suffixes match pattern's prefixes

    Input: pattern
    Output: None (Modifies prefix table)
*/
void lps_algorithm(std::string pat, int lps[]) {
    int pat_length = pat.length();

    // index of pattern and prefix length matching index, respectively
    int i = 1, len = 0;

    // First char always is 0 for lps
    lps[0] = 0;

    // Iterate through pattern
    while (i < pat_length) {
        // If matching, continue to iterate through pattern and current prefix
        // Record longest matching prefix index to lps - always will be len + 1
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else {
            // Go back one on the prefix to see if there's a match
            if (len != 0) {
                len = lps[len - 1];
            }
            // We've exhausted all prefixes and no match, so set lps of this index to 0
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return;
}