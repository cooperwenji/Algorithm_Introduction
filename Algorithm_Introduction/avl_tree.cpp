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

/*
*  ��������㣺���ظ��ڵ�Ϊtree��AVL���������
*/
template<typename T>
AVLTreeNode<T>* AVLTree<T>::maximum(AVLTreeNode<T>* tree)
{
	if (tree == NULL)
		return NULL;
	while (tree->right != NULL)
		tree = tree->right;
	return tree;
}

template<typename T>
T AVLTree<T>::maximum()
{
	AVLTreeNode<T> *p = maximum(mRoot);
	if (p != NULL)
		return p->key;
	return (T)NULL;
}

/*
*  ������С��㣺���ظ��ڵ�Ϊtree��AVL������С���
*/
template<typename T>
AVLTreeNode<T>* AVLTree<T>::minimum(AVLTreeNode<T>* tree)
{
	if (tree == NULL)
		return NULL;
	while (tree->left != NULL)
		tree = tree->left;
	return tree;
}

template<typename T>
T AVLTree<T>::minimum()
{
	AVLTreeNode<T>* p = minimum(mRoot);
	if (p != NULL)
		return p->key;
	return (T)NULL;
}

// (�ݹ�ʵ��) ��ѯ�����Ҽ�ֵΪkey�Ľڵ�
template<typename T>
AVLTreeNode<T>* AVLTree<T>::search(AVLTreeNode<T>* tree, T key) const 
{
	if (tree == NULL || tree->key == key)
		return tree;
	
	if (key < tree->key)
		return search(tree->left, key);
	else
		return search(tree->right, key);
}

template<typename T>
AVLTreeNode<T>* AVLTree<T>::search(T key)
{
	return search(mRoot, key);
}

// (�ǵݹ�ʵ��) ��ѯ�����Ҽ�ֵΪkey�Ľڵ�
template<typename T>
AVLTreeNode<T>* AVLTree<T>::iterativeSearch(AVLTreeNode<T>* tree, T key) const
{
	if (tree == NULL)
		return tree;

	while (tree !=NULL)
	{
		if (key > tree->key)
			tree = tree->right;
		else if (key < tree->key)
			tree = tree->left;
		else
			return tree;
	}
	return NULL;
}

template<typename T>
AVLTreeNode<T>* AVLTree<T>::iterativeSearch(T key)
{
	return iterativeSearch(mRoot, key);
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

/*
* ɾ�����(z)�����ظ��ڵ�
*
* ����˵����
*     tree AVL���ĸ����
*     z ��ɾ���Ľ��
* ����ֵ��
*     ���ڵ�
*/
template<typename T>
AVLTreeNode<T>* AVLTree<T>::remove(AVLTreeNode<T>* &tree, AVLTreeNode<T>* z)
{
	//��Ϊ�� ���� û��Ҫɾ���Ľڵ㣬ֱ�ӷ���NULL.
	if (tree == NULL || z == NULL)
		return NULL;

	if (z->key < tree->key)   // ��ɾ���Ľ����tree����������
	{
		tree->left = remove(tree->left, z);
		if (height(tree->right) - height(tree->left) == 2)
		{
			AVLTreeNode<T>* p = tree->right;
			if (height(p->left) > height(p->right))
				tree->right = rightLeftRotation(p);
			else
				tree->right = rightRightRotation(p);
		}
	}
	else if (z->key > tree->key)  // ��ɾ���Ľ����tree����������
	{
		tree->right = remove(tree->right, z);
		if (height(tree->left) - height(tree->right) == 2)
		{
			AVLTreeNode<T>* p = tree->left;
			//ɾ���ڵ����AVL��ʧȥƽ�⣬�������Ӧ�ĵ���
			if (height(p->left) > height(p->right))
				tree->left = leftLeftRotation(p);
			else
				tree->left = leftRightRotation(p);
		}
	}
	else {   //��ɾ���Ľ���ǵ�ǰ�Ľ��ʱ
		//tree�����Һ��Ӷ��ǿ�
		if (tree->left != NULL && tree->right != NULL)
		{
			// ���tree�����������������ߣ�
			// ��(01)�ҳ�tree���������е����ڵ�
			//   (02)�������ڵ��ֵ��ֵ��tree��
			//   (03)ɾ�������ڵ㡣
			// ����������"tree�������������ڵ�"��"tree"������
			// �������ַ�ʽ�ĺô��ǣ�ɾ��"tree�������������ڵ�"֮��AVL����Ȼ��ƽ��ġ�
			if (height(tree->left) > height(tree->right))
			{
				AVLTreeNode<T>* max = maximum(tree->left);
				tree->key = max->key;
				tree->left = remove(tree->left, max);
			}
			else
			{
			// ���tree��������������������(��������ȣ�������������������1)
		    // ��(01)�ҳ�tree���������е���С�ڵ�
			//   (02)������С�ڵ��ֵ��ֵ��tree��
			//   (03)ɾ������С�ڵ㡣
			// ����������"tree������������С�ڵ�"��"tree"������
			// �������ַ�ʽ�ĺô��ǣ�ɾ��"tree������������С�ڵ�"֮��AVL����Ȼ��ƽ��ġ�
				AVLTreeNode<T>* min = minimum(tree->right);
				tree->key = min->key;
				tree->right = remove(tree->right, min);
			}
		}
		else
		{
			AVLTreeNode<T>* tmp = tree;
			tree = (tree->left != NULL) ? tree->left : tree->right;
			delete tmp;
		}
	}
	return tree;
}

template<typename T>
void AVLTree<T>::remove(T key)
{
	AVLTreeNode<T>* temp = search(mRoot,key);
	if (temp == NULL)
		return;
	mRoot = remove(mRoot, temp);
}



