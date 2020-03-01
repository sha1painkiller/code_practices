/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

//define the struct of a Node
typedef struct Node {
    int value;
    struct Node* next;
} Node;

//flipping the singly list
Node* reverse_linkedlist(Node* list) {
    if (list == NULL) return NULL;
    
    Node *current, *next;
    
    current = list;
    next = list->next;
    current->next = NULL;
    list = next;
    
    while (list != NULL) {
        next = list->next;
        list->next = current;
        current = list;
        list = next;
    }
    return current;
}

#define LEN_OF_LIST 20
int main()
{
    int i;
    Node* tmp;
    Node* prev = NULL;
    Node* list;
    
    list = malloc(sizeof(Node));
    list->value = 0;
    prev = list;
    for (i = 1; i < LEN_OF_LIST; i++) {
        tmp = malloc(sizeof(Node));
        tmp->value = i;
        tmp->next = NULL;
        if (prev != NULL) {
            prev->next = tmp;
            prev = prev->next;
        }
    }
    
    tmp = list;
    printf("original : ");
    while (tmp != NULL) {
        printf("%d -> ", tmp->value);
        tmp = tmp->next;
    }
    printf ("NULL\n");
    
    tmp = reverse_linkedlist(list);
    printf("reversed : ");
    while (tmp != NULL) {
        printf("%d -> ", tmp->value);
        tmp = tmp->next;
    }
    printf ("NULL\n");
    return 0;
}

