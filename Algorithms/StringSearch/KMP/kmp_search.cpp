#include "kmp_algorithm.h"

/* 
    KMP Search Algorithm
    Searches for first occurrence of a string (can be modified to find multiple)
    If we partially match a string, we can check if potential pattern match is contained within
    Otherwise, skip the chars that we've matched with

    Inputs: a text to search in and a pattern to find
    Output: the index of occurrence. If none found, returns -1
*/
int kmp_search(std::string txt, std::string pat) {
    int txt_length = txt.length();
    int pat_length = pat.length();

    // Prefix array, aka. 'longest prefix suffix'
    // Defined further within lps.cpp
    int lps[pat_length];

    lps_algorithm(pat, lps);

    // Iterate through the text
    int i = 0, j = 0;
    while (i < txt_length) {
        // If we get a matching char, go to next char of both text and pattern strings
        if (txt[i] == pat[j]) {
                i++;
                j++;
                
                // If pattern has fully been iterated through, we're done
                // To find multiple occurrences, save i-j to a vector and set j = lps[j-1]
                if (j == pat_length)
                    return i - j;
        }
        else {
            // This implies we had some matching chars before failure
            // Check to see if previously matched chars can be the start of a new search
            if (j != 0) {
                j = lps[j - 1];
            }
            // We've hit the end of the road on our prefix table and should move on
            else {
                i++;
            }
        }
    }
    // If program hasn't exited, it will reach this, implying no match
    return -1;
}
