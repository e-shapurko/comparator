#include <iostream>
#include <cstring>
#include "pars.h"


using namespace std;

int main()
{
//    char word1[] = "mississippi";
//    char word2[] = "mis*is*p*.";
//    char word1[] = "aab";
//    char word2[] = "c*a*b";
//    char word1[] = "ab";
//    char word2[] = ".*";
//    char word1[] = "aa";
//    char word2[] = "a*";
    char word1[] = "aa";
    char word2[] = "a";
    std::cout << equal(word2, word1) << std::endl;
    return 0;
}
