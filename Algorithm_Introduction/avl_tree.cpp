#include "avl_tree.h"

template<typename T>
int AVLTree<T>::height(AVLTreeNode<T>* tree)
{
	if (tree != NULL) return tree->height;
	return 0;
}

template<typename T>
int AVLTree<T>::height()
{
	return height(mRoot);
}

template<typename T>
int AVLTree<T>::max(int a, int b)
{
	return a > b ? a : b;
}


template<typename T>
AVLTreeNode<T>* AVLTree<T>::leftLeftRotation(AVLTreeNode<T>* k2) 
{
	AVLTreeNode<T>* k1 = k2->left;
	k2->left = k1->right;
	k1->right = k2; 

	//更新高度

}

