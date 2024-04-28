#pragma once

typedef char element;

typedef struct treenode {
    element key;
    struct treenode* left;
    struct treenode* right;
} treenode;

void displayInorder(treenode* root);