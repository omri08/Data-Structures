#include <stdlib.h>
#include "tree.h"




tree_ptr Tree_Build(tree_ptr lchild, tree_ptr rchild, tree_info_type x)
{
	tree_ptr p;
	p = (tree_ptr)malloc(sizeof(tree_node));
	p->info = x;
	p->left = lchild;
	p->right = rchild;
	return p;
}