#pragma once
#include "node.h"

treenode* searchBTS(treenode* root, element x); // 노드 탐색
treenode* insertBTSNode(treenode* p, element x); // 노드 삽입
void deleteBTSNode(treenode* root, element key); // 노드 삭제