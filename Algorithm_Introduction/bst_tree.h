#ifndef BST_TREE
#define BST_TREE

template<typename T>
class BSTNode {
  public:
	  T key;           //关键字
	  BSTNode* left;   //左子树
	  BSTNode* right;  //右子树
	  BSTNode* parent; //父子树

	  BSTNode(T value, BSTNode *l, BSTNode *r, BSTNode* p):key(value),left(l),right(r),parent(p){}
};

/*  BST树====二叉查找树
*
*/

template<typename T>
class BSTree {
  private:
      BSTNode<T>* mRoot;  //根节点

  public:
	  BSTree();
	  ~BSTree();

	  void preOrder();   //前序遍历
	  void inOrder();    //中序遍历
	  void postOrder();  //后序遍历

	  BSTNode<T>* search(T key);  //search(recursive): search the node that value equal key;
	  BSTNode<T>* iterativeSearch(T key);  //search(non-recursive): search the node that value equal key;

	  T minimum();     //return the minimum key T;
	  T maximum();     //return the maximum key T;

	  BSTNode<T>* successor(BSTNode<T> *x);   //找结点x的后继节点
	  BSTNode<T>* predecessor(BSTNode<T> *x); //找结点x的前驱节点

	  void insert(T key); //insert operation: insert the key into the tree
	  void remove(T key); //remove operation: remove the key from the tree

	  void destroy();    //destroy the tree;

	  void print();    //print the tree;

  private:
	  void preOrder(BSTNode<T>* tree) const;  //前序遍历
	  void inOrder(BSTNode<T>* tree) const;   //中序遍历
	  void postOrder(BSTNode<T>* tree) const; //后序遍历

	  BSTNode<T>* search(BSTNode<T>* x, T key) const;  //search(recursive);
	  BSTNode<T>* iterativeSearch(BSTNode<T>* x, T key) const ; //search(non-recursive);

	  BSTNode<T>* minimum(BSTNode<T>* tree); //return the minimum node of the tree;
	  BSTNode<T>* maximum(BSTNode<T>* tree); //return the maximum node of the tree;

	  void insert(BSTNode<T>* &tree, BSTNode<T> *z);   //insert the node z into the tree;
	  BSTNode<T>* remove(BSTNode<T>* &tree, BSTNode<T> *Z); //remove the node z from the tree;

	  void destroy(BSTNode<T>* &tree);  //destroy the tree;

	  void print(BSTNode<T>* tree, T key, int direction);
};

 template<typename T>
 void BSTree<T>::preOrder(BSTNode<T>* tree) const
 {
	 if (tree == NULL)
		 return;
 }

#endif // !BST_TREE

