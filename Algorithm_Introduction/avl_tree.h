#ifndef AVL_TREE_H
#define AVL_TREE_H

#include<iostream>

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


	  //查找最大结点：返回根节点为tree的AVL树中的最大结点
	  AVLTreeNode<T>* maximum(AVLTreeNode<T>* tree);

	  //查找最小节点：返回根节点为tree的AVL树中的最小节点
	  AVLTreeNode<T>* minimum(AVLTreeNode<T>* tree);


};


#endif // !AVL_TREE_H

