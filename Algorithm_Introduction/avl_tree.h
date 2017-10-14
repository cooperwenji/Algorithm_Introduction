#ifndef AVL_TREE_H
#define AVL_TREE_H

#include<iostream>
#include<iomanip>

//AVL�����
template <typename T>
class AVLTreeNode {
  public:
	T key;                 //�ؼ���
	int height;            //�߶�
	AVLTreeNode* left;     //������
	AVLTreeNode* right;    //������

	AVLTreeNode(T value, AVLTreeNode *l, AVLTreeNode *r):
		key(value),height(0),left(l),right(r) { }
};


//AVL��---�߶���ƽ�����������
/*  ��ѯ�����롢ɾ��������ʱ����۶���O(logn);
 *  ȱ�����ڣ�Ϊ��ά����������ƽ�⣬ÿ�εĲ����ɾ����������Ҫ
 *            Ƶ������ת���ڵ�
*/
template <typename T>
class AVLTree {
  private:
	  AVLTreeNode<T> *mRoot;  //���ڵ�

  public:
	  AVLTree();
	  ~AVLTree();

	  int height();            //get the height of tree  (for the outside use)  
	  int max(int a, int b);   //get the max number between two int

	  void insert(T key);      //insert operation
	  void remove(T key);      //remove operation
	  AVLTreeNode<T>* search(T key);    //search operation (recursive)
	  AVLTreeNode<T>* iterativeSearch(T key); //search operation (non-recursive)
	  void destroy();         //destroy operation

	  void preOrder();  //ǰ�����
	  void inOrder();   //�������
	  void postOrder(); //�������

	  void print();  //print the AVL tree

	  T maximum();  //return the maximum key T;
	  T minimum();  //return the minimum key T;

  private:
	  int height(AVLTreeNode<T> *tree);  //get the height of tree (for the inside use)

	  AVLTreeNode<T>* leftLeftRotation(AVLTreeNode<T>* k2);   //corresponding to the situation of LL
	  AVLTreeNode<T>* leftRightRotation(AVLTreeNode<T>* k2);  //corresponding to the situation of LR
	  AVLTreeNode<T>* rightRightRotation(AVLTreeNode<T>* k2); //corresponding to the situation of RR
	  AVLTreeNode<T>* rightLeftRotation(AVLTreeNode<T>* k2);  //corresponding to the situation of RL

	  //���룺���ڵ�z���뵽AVL����
	  AVLTreeNode<T>* insert(AVLTreeNode<T>* &tree, T key); 
	  
	  //ɾ����ɾ��AVL���еĽ��z�������ر�ɾ���Ľڵ�
	  AVLTreeNode<T>* remove(AVLTreeNode<T>* &tree, AVLTreeNode<T>* z);

	  //��ѯ�����Ҽ�ֵΪkey�Ľڵ㣨�ݹ�ʵ�֣�
	  AVLTreeNode<T>* search(AVLTreeNode<T>* tree, T key) const;
	  //��ѯ�����Ҽ�ֵΪkey�Ľڵ㣨�ǵݹ�ʵ��)
	  AVLTreeNode<T>* iterativeSearch(AVLTreeNode<T>* tree, T key) const;

	  //����AVL��
	  void destroy(AVLTreeNode<T>* &tree);

	  //��������㣺���ظ��ڵ�Ϊtree��AVL���е������
	  AVLTreeNode<T>* maximum(AVLTreeNode<T>* tree);

	  //������С�ڵ㣺���ظ��ڵ�Ϊtree��AVL���е���С�ڵ�
	  AVLTreeNode<T>* minimum(AVLTreeNode<T>* tree);

	  void preOrder(AVLTreeNode<T>* tree) const;   //ǰ�����
	  void inOrder(AVLTreeNode<T>* tree) const;    //�������
	  void postOrder(AVLTreeNode<T>* tree) const;  //�������

	  void print(AVLTreeNode<T> *tree, T key, int direction);//��ӡ��
};

template<typename T>
AVLTree<T>::AVLTree() : mRoot(NULL) {}

template<typename T>
AVLTree<T>::~AVLTree() {
	destroy(mRoot);
}


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

	while (tree != NULL)
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

	return k2;
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
	}
	else if (key < tree->key)  //Ӧ�ý�key���뵽tree�������������
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
	AVLTreeNode<T>* temp = search(mRoot, key);
	if (temp == NULL)
		return;
	mRoot = remove(mRoot, temp);
}

template<typename T>
void AVLTree<T>::destroy(AVLTreeNode<T>* &tree)
{
	if (tree == NULL)
		return;

	if (tree->left != NULL)
		destroy(tree->left);
	if (tree->right != NULL)
		destroy(tree->right);

	delete tree;
}

template<typename T>
void AVLTree<T>::destroy()
{
	return destroy(mRoot);
}

template<typename T>
void AVLTree<T>::preOrder(AVLTreeNode<T>* tree) const
{
	if (tree == NULL)
		return;

	std::cout << tree->key << " ";
	preOrder(tree->left);
	preOrder(tree->right);
}

template<typename T>
void AVLTree<T>::preOrder() {
	preOrder(mRoot);
}

template<typename T>
void AVLTree<T>::inOrder(AVLTreeNode<T>* tree) const
{
	if (tree == NULL)
		return;

	inOrder(tree->left);
	std::cout << tree->key << " ";
	inOrder(tree->right);
}

template<typename T>
void AVLTree<T>::inOrder()
{
	inOrder(mRoot);
}

template<typename T>
void AVLTree<T>::postOrder(AVLTreeNode<T>* tree) const
{
	if (tree == NULL)
		return;

	postOrder(tree->left);
	postOrder(tree->right);
	std::cout << tree->key << " ";
}

template<typename T>
void AVLTree<T>::postOrder()
{
	postOrder(mRoot);
}


template<typename T>
void AVLTree<T>::print(AVLTreeNode<T> *tree, T key, int direction)
{
	if (tree != NULL)
	{
		if (direction == 0)
			std::cout << std::setw(2) << tree->key << " is root" << std::endl;
		else
			std::cout << std::setw(2) << tree->key << " is " << std::setw(2) << key << "'s " << std::setw(12) << (direction == 1 ? "right child" : "left child") << std:endl;

		print(tree->left, tree->key, -1);
		print(tree->right, tree->key, 1);
	}
}

template<typename T>
void AVLTree<T>::print()
{
	if (mRoot != NULL)
		print(mRoot, mRoot->key, 0);
}
#endif // !AVL_TREE_H

