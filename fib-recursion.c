#include <stdio.h>

int fib_recursion(int in) {
    if (in == 0)
        return 0;
    if (in == 2 || in == 1)
        return 1;
    return fib_recursion(in - 1) + fib_recursion(in - 2);

}

int main(void) {
    int input = 30;
    int output = 0;

    printf("input: %d\n\r", input);
    output = fib_recursion(input);
    printf("\n\routput: %d\n\r", output);

    return 0;
}

