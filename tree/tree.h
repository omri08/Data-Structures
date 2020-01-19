#pragma once
typedef int  tree_info_type;

typedef struct Tree
{
    tree_info_type info;
    struct Tree* left, * right;
}tree_ptr;

void printInOrder(tree_ptr* node);
tree_ptr* Tree_Build(tree_ptr* lchild, tree_ptr* rchild, tree_info_type x);