#include "node.h"
#include <stdio.h>

void displayInorder(treenode* root) {
    if (root) {
        displayInorder(root->left);
        printf("%s", root->key);
        displayInorder(root -> right);
    }
}