#include "avl_tree.h"
template<typename T>
AVLTree<T>::AVLTree<T>():mRoot(NULL){}


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

	//update the height of tree
	k2->height = max(height(k2->left), height(k2->right)) + 1;
	k1->height = max(height(k1->left), k2->height) + 1;

	return k1;
}

template<typename T>
AVLTreeNode<T>* AVLTree<T>::rightRightRotation(AVLTreeNode<T> *k1)
{
	AVLTreeNode<T>* k2 = k1->right;
	k1->right = k2->left;
	k2->left = k1;

	//update the height of tree
	k1->height = max(height(k1->left), height(k1->right)) + 1;
	k2->height = max(height(k2->right), k1->height) + 1;
}

template<typename T>
AVLTreeNode<T>* AVLTree<T>::leftRightRotation(AVLTreeNode<T> *k3)
{
	k3->left = rightRightRotation(k3->left);
	return leftLeftRotation(k3);
}

template<typename T>
AVLTreeNode<T>* AVLTree<T>::rightLeftRotation(AVLTreeNode<T> *k1)
{
	k1->right = leftLeftRotation(k1->right);
	return rightRightRotation(k1);
}

template<typename T>
AVLTreeNode<T>* AVLTree<T>::insert(AVLTreeNode<T>* &tree, T key)
{
	if (tree == NULL)
	{
		//�½��ڵ�
		tree = new AVLTreeNode<T>(key, NULL, NULL);
		if (tree == NULL)
		{
			std::cout << "ERROR: create avltree node failed!" << std::endl;
			return NULL;
		}
	}else if(key < tree->key)  //Ӧ�ý�key���뵽tree�������������
	{
		tree->left = insert(tree->left, key);
		//����ڵ����AVL��ʧȥƽ�⣬�������Ӧ�ĵ���
		if (height(tree->left) - height(tree->right) == 2)
		{
			if (key < tree->left->key)
				tree = leftLeftRotation(tree);
			else
				tree = leftRightRotation(tree);
		}
	}
	else if (key > tree->key)
	{
		tree->right = insert(tree->right, key);
		//����ڵ����AVL��ʧȥƽ�⣬�������Ӧ�ĵ���
		if (height(tree->right) - height(tree->left) == 2)
		{
			if (key > tree->right->key)
				tree = rightRightRotation(tree);
			else
				tree = rightLeftRotation(tree);
		}
	}
	else  //key == tree->key
	{
		std::cout << "���ʧ�ܣ� �����������ͬ�Ľڵ�" << std::endl;
	}
	tree->height = max(height(tree->left), height(tree->right)) + 1;

	return tree;
}

template<typename T>
void AVLTree<T>::insert(T key)
{
	insert(mRoot, key);
}

template<typename T>
AVLTreeNode<T>* AVLTree<T>::remove(AVLTreeNode<T>* &tree, AVLTreeNode<T>* z)
{
	//��Ϊ�� ���� û��Ҫɾ���Ľڵ㣬ֱ�ӷ���NULL.
	if (tree == NULL || z == NULL)
		return NULL;



}



