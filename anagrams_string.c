#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define CHAR_SIZE 26
int check_anagrams(char *astr, char *bstr)
{
    int size_a = strlen(astr);
    int size_b = strlen(bstr);
    int i;
    int arry_a[CHAR_SIZE] = {0};
    int arry_b[CHAR_SIZE] = {0};
    int ret = 0;

    if (size_a != size_b)
        return -1;

    for (i = 0; i < size_a; i++)
    {
        //process a string
        int posi = tolower(astr[i]) - 'a';
        arry_a[posi]++;
        //process b string
        posi = tolower(bstr[i]) - 'a';
        arry_b[posi]++;
    }
    if ( 0 == memcmp (arry_a, arry_b, CHAR_SIZE))
        return 0;
    else
        return (-1);
}

int main()
{
    int ret = 0;
    char astr[] = {'m', 'a', 'r', 'y', 'y', 0};
    char bstr[] = {'a', 'r', 'm', 'y', 'y', 0};

    printf("input a: %s\n", astr);
    printf("input b: %s\n", bstr);
    ret = check_anagrams(astr, bstr);
    if (ret != 0)
        printf("NOT anagrams\n");
    else
        printf("Anagrams\n");
    
    return 0;
}

