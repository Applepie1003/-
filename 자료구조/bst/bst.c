#include "node.h"
#include "bst.h"
#include <stdio.h>
#include <stdlib.h>

treenode* searchBTS(treenode* root, element x) {
    treenode* p;
    p = root;
    while (p != NULL) {
        if(x < p->key) p = p->left;
        else if(x == p->key) return p;
        else p = p ->right;
    }
    printf("찾는 키 값이 없습니다\n");
    return p;
}

treenode* insertBTSNode(treenode* p, element x) {
    treenode* newnode;
    if (p == NULL) {
        newnode = (treenode *) malloc(sizeof(treenode));
        newnode->key = x;
        newnode->left = NULL;
        newnode->right = NULL;
    }
    else if(x < p->key) p->left = insertBTSNode(p->left, x);
    else if(x > p->key) p->right = insertBTSNode(p->right, x);
    else printf("이미 같은 키 값이 있습니다.");
    return p;
}

void deleteBTSNode(treenode* root, element key) {
    treenode* p, *parent, *succ, * succ_parent;
    treenode* child;

    parent = NULL;
    p = root;

    // 삭제 할 노드 탐색
    while(p != NULL && p->key != key) {
        parent = p; // parent == 삭제할 노드
        if(key < p->key) p = p->left;
        else p = p->right;
    }

    // 삭제할 노드가 없는 경우
    if (p == NULL) {
        printf("삭제할 노드가 없습니다.\n");
        return;
    }

    // 삭제할 노드가 단일 노드일 경우
    if((p->left == NULL) && (p->right == NULL)) {
        if(parent != NULL) {
            if (parent->left)
        }
    }

    // 삭제할 노드의 자식노드가 하나 일 경우
    if ((p->left == NULL) || (p->right == NULL)) {

    }

    // 삭제할 노드의 자식노드가 둘 일 경우
    if ((p->left != NULL) && (p->right != NULL)) {

    }
}




