#include <stdio.h>

static int isPerfectSquare(int num) {
    int l = num, r = 0;
    int mid;
    
    while (l >= r) {
        mid = (l + r) >> 1;
        if (num > mid * mid) {
            r = mid + 1;
        } else if (num < mid * mid) {
            l = mid - 1;
        }
        else
            return 1;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    int input, output;
    if (argc != 2)
        return 0;
    input = atoi(argv[1]);
    output = isPerfectSquare(input);
    printf("input %d is perfect square? %s\n", input, output ? "true" : "false");
    return 0;
}
