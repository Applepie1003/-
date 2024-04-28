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
    printf("ã�� Ű ���� �����ϴ�\n");
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
    else printf("�̹� ���� Ű ���� �ֽ��ϴ�.");
    return p;
}

void deleteBTSNode(treenode* root, element key) {
    treenode* p, *parent, *succ, * succ_parent;
    treenode* child;

    parent = NULL;
    p = root;

    // ���� �� ��� Ž��
    while(p != NULL && p->key != key) {
        parent = p; // parent == ������ ���
        if(key < p->key) p = p->left;
        else p = p->right;
    }

    // ������ ��尡 ���� ���
    if (p == NULL) {
        printf("������ ��尡 �����ϴ�.\n");
        return;
    }

    // ������ ��尡 ���� ����� ���
    if((p->left == NULL) && (p->right == NULL)) {
        if(parent != NULL) {
            if (parent->left)
        }
    }

    // ������ ����� �ڽĳ�尡 �ϳ� �� ���
    if ((p->left == NULL) || (p->right == NULL)) {

    }

    // ������ ����� �ڽĳ�尡 �� �� ���
    if ((p->left != NULL) && (p->right != NULL)) {

    }
}




