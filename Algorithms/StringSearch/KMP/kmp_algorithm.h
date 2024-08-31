#include <string>
#ifndef KMP_ALGORITHM_H
#define KMP_ALGORITHM_H

int kmp_search(std::string txt, std::string pat);

void lps_algorithm(std::string pat, int lps[]);

#endif