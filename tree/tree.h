#pragma once
typedef int  tree_info_type;

typedef struct Tree
{
    tree_info_type info;
    struct Tree* left, * right;
}*tree_ptr;
tree_ptr Build_Tree(int PL, int IL, int size);
tree_ptr Tree_Build(tree_ptr lchild, tree_ptr rchild, tree_info_type x);