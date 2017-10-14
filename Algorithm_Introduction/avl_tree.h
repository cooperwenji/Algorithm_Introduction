#ifndef AVL_TREE_H
#define AVL_TREE_H

#include<iostream>
#include<iomanip>

//AVL树结点
template <typename T>
class AVLTreeNode {
  public:
	T key;                 //关键字
	int height;            //高度
	AVLTreeNode* left;     //左子树
	AVLTreeNode* right;    //右子树

	AVLTreeNode(T value, AVLTreeNode *l, AVLTreeNode *r):
		key(value),height(0),left(l),right(r) { }
};


//AVL树---高度自平衡二叉搜索树
/*  查询、插入、删除操作的时间代价都是O(logn);
 *  缺点在于：为了维持搜索树的平衡，每次的插入或删除操作都需要
 *            频繁的旋转树节点
*/
template <typename T>
class AVLTree {
  private:
	  AVLTreeNode<T> *mRoot;  //根节点

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

	  void preOrder();  //前序遍历
	  void inOrder();   //中序遍历
	  void postOrder(); //后序遍历

	  void print();  //print the AVL tree

	  T maximum();  //return the maximum key T;
	  T minimum();  //return the minimum key T;

  private:
	  int height(AVLTreeNode<T> *tree);  //get the height of tree (for the inside use)

	  AVLTreeNode<T>* leftLeftRotation(AVLTreeNode<T>* k2);   //corresponding to the situation of LL
	  AVLTreeNode<T>* leftRightRotation(AVLTreeNode<T>* k2);  //corresponding to the situation of LR
	  AVLTreeNode<T>* rightRightRotation(AVLTreeNode<T>* k2); //corresponding to the situation of RR
	  AVLTreeNode<T>* rightLeftRotation(AVLTreeNode<T>* k2);  //corresponding to the situation of RL

	  //插入：将节点z插入到AVL树中
	  AVLTreeNode<T>* insert(AVLTreeNode<T>* &tree, T key); 
	  
	  //删除：删除AVL树中的结点z，并返回被删除的节点
	  AVLTreeNode<T>* remove(AVLTreeNode<T>* &tree, AVLTreeNode<T>* z);

	  //查询：查找键值为key的节点（递归实现）
	  AVLTreeNode<T>* search(AVLTreeNode<T>* tree, T key) const;
	  //查询：查找键值为key的节点（非递归实现)
	  AVLTreeNode<T>* iterativeSearch(AVLTreeNode<T>* tree, T key) const;

	  //销毁AVL树
	  void destroy(AVLTreeNode<T>* &tree);

	  //查找最大结点：返回根节点为tree的AVL树中的最大结点
	  AVLTreeNode<T>* maximum(AVLTreeNode<T>* tree);

	  //查找最小节点：返回根节点为tree的AVL树中的最小节点
	  AVLTreeNode<T>* minimum(AVLTreeNode<T>* tree);

	  void preOrder(AVLTreeNode<T>* tree) const;   //前序遍历
	  void inOrder(AVLTreeNode<T>* tree) const;    //中序遍历
	  void postOrder(AVLTreeNode<T>* tree) const;  //后序遍历

	  void print(AVLTreeNode<T> *tree, T key, int direction);//打印树
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
*  查找最大结点：返回根节点为tree的AVL树的最大结点
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
*  查找最小结点：返回根节点为tree的AVL树的最小结点
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

// (递归实现) 查询：查找键值为key的节点
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

// (非递归实现) 查询：查找键值为key的节点
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
		//新建节点
		tree = new AVLTreeNode<T>(key, NULL, NULL);
		if (tree == NULL)
		{
			std::cout << "ERROR: create avltree node failed!" << std::endl;
			return NULL;
		}
	}
	else if (key < tree->key)  //应该将key插入到tree的左子树的情况
	{
		tree->left = insert(tree->left, key);
		//插入节点后，若AVL树失去平衡，则进行相应的调节
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
		//插入节点后，若AVL树失去平衡，则进行相应的调节
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
		std::cout << "添加失败： 不允许添加相同的节点" << std::endl;
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
* 删除结点(z)，返回根节点
*
* 参数说明：
*     tree AVL树的根结点
*     z 待删除的结点
* 返回值：
*     根节点
*/
template<typename T>
AVLTreeNode<T>* AVLTree<T>::remove(AVLTreeNode<T>* &tree, AVLTreeNode<T>* z)
{
	//根为空 或者 没有要删除的节点，直接返回NULL.
	if (tree == NULL || z == NULL)
		return NULL;

	if (z->key < tree->key)   // 待删除的结点在tree的左子树中
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
	else if (z->key > tree->key)  // 待删除的结点在tree的右子树中
	{
		tree->right = remove(tree->right, z);
		if (height(tree->left) - height(tree->right) == 2)
		{
			AVLTreeNode<T>* p = tree->left;
			//删除节点后，若AVL树失去平衡，则进行相应的调节
			if (height(p->left) > height(p->right))
				tree->left = leftLeftRotation(p);
			else
				tree->left = leftRightRotation(p);
		}
	}
	else {   //当删除的结点是当前的结点时
			 //tree的左右孩子都非空
		if (tree->left != NULL && tree->right != NULL)
		{
			// 如果tree的左子树比右子树高；
			// 则(01)找出tree的左子树中的最大节点
			//   (02)将该最大节点的值赋值给tree。
			//   (03)删除该最大节点。
			// 这类似于用"tree的左子树中最大节点"做"tree"的替身；
			// 采用这种方式的好处是：删除"tree的左子树中最大节点"之后，AVL树仍然是平衡的。
			if (height(tree->left) > height(tree->right))
			{
				AVLTreeNode<T>* max = maximum(tree->left);
				tree->key = max->key;
				tree->left = remove(tree->left, max);
			}
			else
			{
				// 如果tree的左子树不比右子树高(即它们相等，或右子树比左子树高1)
				// 则(01)找出tree的右子树中的最小节点
				//   (02)将该最小节点的值赋值给tree。
				//   (03)删除该最小节点。
				// 这类似于用"tree的右子树中最小节点"做"tree"的替身；
				// 采用这种方式的好处是：删除"tree的右子树中最小节点"之后，AVL树仍然是平衡的。
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

