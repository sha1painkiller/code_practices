/* quick sort */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int partition(int *a, int l, int u)
{
    int v,i,j,temp;
    v = a[l];
    i = l;
    j = u + 1;

    do {
        do
            i++;
        while(a[i] < v && i <= u);

        do
            j--;
        while(v < a[j]);

        if(i < j) {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    } while(i < j);

    a[l] = a[j];
    a[j] = v;

    return(j);
}

void quicksort(int *a,int l,int u)
{
    int j;
    if(l < u) {
        j = partition(a, l, u);
        quicksort(a, l, j - 1);
        quicksort(a, j + 1, u);
    }
}

int main()
{
    int n, i;
    printf("Quick Sort practice\n");
    printf("How many elements to be sorted? ");
    if (scanf("%d", &n) != 1) {
        printf("invalid value!\n");
        exit(0);
    }

    int *a = malloc(sizeof(int) * n);

    printf("\nEnter %d elements (space separated): ", n);

    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    quicksort(a, 0, n - 1);
    printf("\nArray after sorting: ");

    for(i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n");
    free(a);

    return 0;
}

