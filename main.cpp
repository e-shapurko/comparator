#include <iostream>
#include <cstring>


using namespace std;

bool equal(char *whatFind, char * whereFind)
{
    if (*whatFind == '\0' && *whereFind == '\0')
        return true;
    if ((*(whatFind + 1) == '*') && (*(whatFind + 2) != '\0'))
    {
        if (*(whatFind + 1) == '*' && *(whereFind + 1) != '\0')
            if (*whatFind == *whereFind || *whatFind == '.')
                return equal(whatFind, whereFind+1);
            else
                return equal(whatFind+2, whereFind);
        else if (*(whatFind + 1) == '*' && *(whereFind + 1) == '\0')
        {
            if (*whatFind == *whereFind)
                return equal(whatFind, whereFind+1);
            else
                return equal(whatFind+2, whereFind);
        }
    }
    else if ((*(whatFind + 1) == '*') && (*(whatFind + 2) == '\0'))
    {
        if ((*whatFind == *whereFind || *whatFind == '.')&& *(whereFind + 1) != '\0')
            return equal(whatFind, whereFind+1);
        if ((*whatFind == *whereFind || *whatFind == '.')&& *(whereFind + 1) == '\0')
            return true;
        else if (*whatFind != *whereFind && *(whereFind + 1) == '\0')
            return false;
    }
    else if (*whatFind == '.' || *whatFind == *whereFind)
        return equal(whatFind+1, whereFind+1);
    return false;
}

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
