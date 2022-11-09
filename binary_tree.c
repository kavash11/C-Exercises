#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    char *name;
    char *tea;
    struct node *right;
    struct node *left;
};
typedef struct node node;

/******************The binary tree***********************
 * The following is an illustration of the binary tree
 * I *highly* recommend you test your algorithm on.
 ********************************************************
 *                        Nicholas
 *                        /      \
 *                     Mark      Parker
 *                    /          /     \
 *                Swaleh     Soroush   Other Mark
 *                                 \
 *                                 Ana
 *                                 /
 *                             Bassel
 *
 *
 * (where "/" indicates a left branch, 
 *    and "\" indicates a right branch)
 *
 */ 

int depth(struct node *root) {
    if (root!=NULL) {
        int deep = depth(root->left);
        int depth1 = depth(root->right);
        if (deep > depth1) {
            return (deep+1);
        }
        else {
            return(depth1 + 1);
        }
    }
    else {
        int depth2 = 0;
        return(depth2);
    }
}

void check (node *root, char *name, int *count, int *true) {
    if (root == NULL) {
            return;
    }
    *count += 1;
    if (strcmp(name, root -> name) == 0) {
        *true = 1;
        return;
    }
    check (root -> left, name, count, true);
    if (*true == 1) {
        return;
    }
    check (root -> right, name, count, true);
}


int dfs (node *root, char *name) {
    int count = 0;
    int true = 0;
    check(root, name, &count, &true);
    if (true == 0) {
        return -1;
    }
    return count;
}
    

int main() {
    //Testing code ^_^
    node *root = malloc(sizeof(node));
    root->name = "Nicholas";
    root->tea = "Orange Pekoe with Lemon";
    root->left = malloc(sizeof(node));
    root->left->left = malloc(sizeof(node));
    root->left->right = NULL;
    root->left->left->left = NULL;
    root->left->left->right = NULL;
    root->right = malloc(sizeof(node));
    root->right->left = malloc(sizeof(node));
    root->right->right = malloc(sizeof(node));
    root->right->right->left = NULL;
    root->right->right->right = NULL;
    root->right->left->left = NULL;
    root->right->left->right = malloc(sizeof(node));
    root->right->left->right->left = malloc(sizeof(node));
    root->right->left->right->right = NULL;
    root->right->left->right->left->left = NULL;
    root->right->left->right->left->right = NULL;
    
    root->left->name = "Mark";
    root->left->tea = "Green";
    
    root->right->left->name = "Soroush";
    root->right->left->tea = "Oolong";
    
    root->right->name = "Parker";
    root->right->tea = "Rooibos";
    
    root->right->right->name = "Other Mark";
    root->right->right->tea = "Sencha";
    
    root->left->left->name = "Swaleh";
    root->left->left->tea = "White";
    
    root->right->left->right->name = "Ana";
    root->right->left->right->tea = "Hibiscus";
    
    root->right->left->right->left->name = "Bassel";
    root->right->left->right->left->tea = "Matcha";
    
    printf("The depth of the tree is: %d\n", depth(root));
    // expected result is 5.
    
    printf("Depth First Search for : Nicholas\n");
    printf("result: %d\n", dfs(root, "Nicholas"));
    // expected result is 1
    
    printf("Depth First Search for : Other Mark\n");
    printf("result: %d\n", dfs(root, "Other Mark"));
    // expected result is 8
    
    printf("Depth First Search for : Parker\n");
    printf("result: %d\n", dfs(root, "Parker"));
    // expected result is 4
    
    printf("Depth First Search for : Julius Ceasar\n");
    printf("result: %d\n", dfs(root, "Julius Ceasar"));
    // expected result is -1
    
    free(root->right->left->right->left);
    free(root->right->left->right);
    free(root->right->left);
    free(root->right->right);
    free(root->right);
    free(root->left->left);
    free(root->left);
    free(root);
}