#include <stdio.h> 
#include <stdlib.h> 

struct node { 
    int data; 
    struct node* left; 
    struct node* right; 
}; 
  
static int height(struct node* node) 
{ 
    if (node == NULL) 
        return 0; 
  
    return 1 + max(height(node->left), height(node->right)); 
} 

bool isBalanced(struct node* root) 
{ 
    int lh;
    int rh;
  
    if (root == NULL) 
        return 1; 
  
    lh = height(root->left); 
    rh = height(root->right); 
  
    /* ?? check this */
    if (abs(lh - rh) <= 1 && isBalanced(root->left) && isBalanced(root->right)) 
        return 1; 
  
    return 0; 
} 
  
  
int main() 
{ 
    if (isBalanced(root)) 
        printf("Tree is balanced"); 
    else
        printf("Tree is not balanced"); 
  
    return 0; 
} 


