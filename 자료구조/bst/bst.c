#include <stdio.h>
#include "node.h"
#include "bst.h"
#include <stdlib.h>

treeNode* searchBST(treeNode* root, element x) {
    treeNode* p;
    p = root;
    while (p != NULL) {
        if (x < p->key) p = p->left;
        else if (x == p->key) return p;
        else p = p->right;
    }
    printf("\n 찾는 키가 없습니다!");
    return p;
}

treeNode* insertBSTNode(treeNode* p, element x) {
    if (p == NULL) {
        treeNode* newNode = (treeNode*) malloc(sizeof(treeNode));
        newNode->key = x;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
    else if (x < p->key) p->left = insertBSTNode(p->left, x);
    else if (x > p->right) p->right = insertBSTNode(p->right, x);
    else printf("이미 같은 키가 있습니다!\n");

    return p;
}

void deleteBTSNode(treeNode* root, element key) {
    treeNode* p, * parent, * succ, * succ_parent;
    treeNode* child; // 자식 노드

    parent = NULL;
    p = root;

    // 삭제할 노드의 위치 찾기
    while ((p != NULL) && (p->key != key)) {
        parent = p; // 찾은 키의 부모
        if (key < p->key) p = p->left;
        else p = p->right;
        // p에는 삭제할 노드의 주소가 초기화됨
    }

    // 삭제할 노드가 없는 경우
    if (p == NULL) {
        printf("찾는 키가 없습니다!");
        return; // deleteBTSNode 함수 종료
    }

    // 노드가 말단 노드인 경우
    if ((p->left == NULL) && (p->right == NULL)) {
        if (parent != NULL) { // 트리에 노드가 두개 이상 일때
            if (parent->left == p) parent->left = NULL;
            else parent->right = NULL;
        } else root = NULL; // 트리에 노드가 하나만 존재할 경우
    }

    // 자식 노드가 한개 일 경우
    else if ((p->left == NULL) || (p->right == NULL) ){
        if (parent->left != NULL) child = p->left;
        else child = p->right;

        // 끈어진 노드 연결
        if (parent != NULL) {
            if (parent->left == p) parent->left = child;
            else parent->right = child;
        }
        else root = child;
    }

    // 자식 노드가 2개 일 경우
    else {
        succ_parent = p;
        succ = p->left;
        while (succ->right != NULL) { // 왼쪽 서브 트리에서 후계자를 찾음
            succ_parent = succ;
            succ = succ->right;
        }
        if (succ_parent->left == NULL) { // 후계자의 왼쪽 노드가 비어 있을때 후계자의 왼쪽 노드를 부모의 왼쪽 노드에 연결
            succ_parent->left = succ->left;
        } else {
            // 후계자 부모 노드의 왼쪽 노드가 있으면 부모에 오른쪽에 후계자의 왼쪽 노드를 연결 시킨다
            succ_parent->right = succ->left;
        }
        p->key = succ->key;
    }
    free(p);
}