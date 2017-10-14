#ifndef BST_TREE
#define BST_TREE

template<typename T>
class BSTNode {
  public:
	  T key;           //�ؼ���
	  BSTNode* left;   //������
	  BSTNode* right;  //������
	  BSTNode* parent; //������

	  BSTNode(T value, BSTNode *l, BSTNode *r, BSTNode* p):key(value),left(l),right(r),parent(p){}
};

/*  BST��====���������
*
*/

template<typename T>
class BSTree {
  private:
      BSTNode<T>* mRoot;  //���ڵ�

  public:
	  BSTree();
	  ~BSTree();

	  void preOrder();   //ǰ�����
	  void inOrder();    //�������
	  void postOrder();  //�������

	  BSTNode<T>* search(T key);  //search(recursive): search the node that value equal key;
	  BSTNode<T>* iterativeSearch(T key);  //search(non-recursive): search the node that value equal key;

	  T minimum();     //return the minimum key T;
	  T maximum();     //return the maximum key T;

	  BSTNode<T>* successor(BSTNode<T> *x);   //�ҽ��x�ĺ�̽ڵ�
	  BSTNode<T>* predecessor(BSTNode<T> *x); //�ҽ��x��ǰ���ڵ�

	  void insert(T key); //insert operation: insert the key into the tree
	  void remove(T key); //remove operation: remove the key from the tree

	  void destroy();    //destroy the tree;

	  void print();    //print the tree;

  private:
	  void preOrder(BSTNode<T>* tree) const;  //ǰ�����
	  void inOrder(BSTNode<T>* tree) const;   //�������
	  void postOrder(BSTNode<T>* tree) const; //�������

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

