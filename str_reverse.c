#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int str_reverse(char *arry)
{
    size_t size = strlen(arry);
    char tmp;
    int i;

    for (i = 0; i < size/2; i++)
    {
        //swap
        tmp = arry[i];
        arry[i] = arry[size-i-1];
        arry[size-i-1] = tmp;
    }
    return 0;
}

int word_reverse(char *arry)
{
    char *ptr = arry;
    char *tmp_ptr;
    char *local_arry = malloc(strlen(arry) + 1);
    char *tmp = local_arry;

    // advance ptr to the end of this string
    ptr += strlen(arry);
    // start search a space char
    while (ptr != arry)
    {
        if (*ptr == ' ')
        {
            tmp_ptr = ptr++;
            //collect the word
            while (*ptr != 0)
                *tmp++ = *ptr++;

            *tmp++ = ' ';
            ptr = tmp_ptr;
            *tmp_ptr = 0;
        }
        ptr--;
    }
    //add last word
    while (*ptr != 0)
        *tmp++ = *ptr++;
    *tmp = 0;

    //copy back to original array
    strcpy(arry, local_arry);   

    free(local_arry);
    return 0;
}

#define TEST_STR "abc def ghi jkl mno pqr stu vwx yz"
int main()
{
    char *inss = (char *)malloc(strlen(TEST_STR) + 1);
    strcpy(inss, TEST_STR);
    printf("original: %s\n", inss);
    //str_reverse(inss);
    word_reverse(inss);
    printf("modified: %s\n", inss);
    free(inss);
    return 0;
}

