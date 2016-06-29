#include<stdio.h>

int transfer_char_to_bits(int *arry, int size)
{
    int i;
    int ret = 0;
    for (i = 0; i < size; i++)
    {
        ret += (arry[i] << (size - 1 - i));
        //printf("ret = 0x%08X (%d..%d)\n", ret, i, arry[i]);
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
    printf("result = 0x%08X\n", ret);

    return 0;
}
