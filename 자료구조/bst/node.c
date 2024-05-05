#include <stdio.h>
#include "node.h"
// 이진 트리 탐색 트리를 중위 순회 하면서 출력을 하는 연산
void displayInorder(treeNode* root) {
    if(root) {
        displayInorder(root->left);
        printf("%c", root->key);
        displayInorder(root->right);
    }
}

