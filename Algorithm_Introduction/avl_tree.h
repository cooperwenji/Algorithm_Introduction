#ifndef AVL_TREE_H
#define AVL_TREE_H

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
template <typename T>
class AVLTree {
  private:
	  AVLTreeNode<T> *mRoot;  //根节点

  public:
	  AVLTree();
	  ~AVLTree();

};


#endif // !AVL_TREE_H

