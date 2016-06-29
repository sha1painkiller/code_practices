#include<stdio.h>

int transfer_char_to_bits(int *arry, int size)
{
    int i;
    int ret = 0;
    for (i = 0; i < size; i++)
    {
        if (arry[i] == 0 || arry[i] == 1)
        {
            ret += (arry[i] << (size - 1 - i));
            //printf("ret = 0x%08X (%d..%d)\n", ret, i, arry[i]);
        }
        else
        {
            printf("Error: %d element is neither 0 nor 1\n", i);
            return (-1);
        }
    }

    return ret;
}

int main()
{
    int i, ret;
    int input[] = {1, 1, 0, 0, 1, 0, 1, 0,
                   1, 1, 0, 0, 1, 0, 1, 1};
    int arry_size = sizeof(input)/sizeof(int);

    printf("** transfer array to bit representation of a integer **\n");
    printf("input array: ");
    for (i = 0; i < arry_size; i++)
        printf("%d ", input[i]);
    printf("\n");

    ret = transfer_char_to_bits(input, arry_size);
    if (ret == (-1))
        printf("Error: format not accepted! can be only 0 or 1\n");
    else
        printf("result = 0x%08X\n", ret);

    return 0;
}
