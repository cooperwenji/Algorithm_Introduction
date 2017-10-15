#ifndef BST_TREE
#define BST_TREE
#include<iostream>

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
BSTree<T>::BSTree():mRoot(NULL){}

template<typename T>
BSTree<T>::~BSTree() {
	destroy(mRoot);
}

/*
* ǰ�����
*/
 template<typename T>
 void BSTree<T>::preOrder(BSTNode<T>* tree) const
 {
	 if (tree == NULL)
		 return;

	 std::cout << tree->key << " ";
	 preOrder(tree->left);
	 preOrder(tree->right);
 }

 template<typename T>
 void BSTree<T>::preOrder()
 {
	 preOrder(mRoot);
 }

 /*
 * �������
 */
 template<typename T>
 void BSTree<T>::inOrder(BSTNode<T>* tree) const
 {
	 if (tree == NULL)
		 return;

	 inOrder(tree->left);
	 std::cout << tree->key << " ";
	 inOrder(tree->right);
 }

 template<typename T>
 void BSTree<T>::inOrder()
 {
	 inOrder(mRoot);
 }

 /*
 *  �������
 */
 template<typename T>
 void BSTree<T>::postOrder(BSTNode<T>* tree) const
 {
	 if (tree == NULL)
		 return;

	 postOrder(tree->left);
	 postOrder(tree->right);
	 std::cout << tree->key << " ";
 }

 template<typename T>
 void BSTree<T>::postOrder()
 {
	 postOrder(mRoot);
 }

 //��ѯ����
 template<typename T>
 BSTNode<T>* BSTree<T>::search(BSTNode<T>* x, T key) const
 {
	 if (x == NULL || x->key == key)
		 return x;

	 if (key < x->key)
		 return search(x->left, key);
	 else
		 return search(x->right, key);
 }

 template<typename T>
 BSTNode<T>* BSTree<T>::search(T key)
 {
	 return search(mRoot, key);
 }

 template<typename T>
 BSTNode<T>* BSTree<T>::iterativeSearch(BSTNode<T> *tree, T key) const
 {
	 if (tree == NULL)
		 return tree;

	 while (tree!=NULL)
	 {
		 if (key < tree->key)
			 tree = tree->left;
		 else if (key > tree->key)
			 tree = tree->right;
		 else
			 return tree;
	 }

	 return tree;
 }

 template<typename T>
 BSTNode<T>* BSTree<T>::iterativeSearch(T key)
 {
	 return iterativeSearch(mRoot, key);
 }

 //��Сֵ
 template<typename T>
 BSTNode<T>* BSTree<T>::minimum(BSTNode<T>* tree)
 {
	 if (tree == NULL)
		 return tree;

	 while (tree->left != NULL)
		 tree = tree->left;
	 return tree;
 }

 template<typename T>
 T BSTree<T>::minimum()
 {
	 BSTNode<T>* p = minimum(mRoot);
	 return p->key;
 }

 //���ֵ
 template<typename T>
 BSTNode<T>* BSTree<T>::maximum(BSTNode<T>* tree)
 {
	 if (tree == NULL)
		 return tree;

	 while (tree->right != NULL)
		 tree = tree->right;
	 return tree;
 }

 template<typename T>
 T BSTree<T>::maximum()
 {
	 BSTNode<T> *p = maximum(mRoot);
	 return p->key;
 }

 //����
 template<typename T>
 void BSTree<T>::insert(BSTNode<T>* &tree, BSTNode<T> *z)
 {
	 /*
	 if (tree == NULL)
	 {
		 tree = z;
		 return;
	 }
	 else if (tree->key == z->key)
	 {
		 std::cout << "Error: insert the exist key into the tree " << std::endl;
		 return;
	 }
		
	 BSTNode<T>* p = tree;
	 while (1)
	 {
		 if ((z->key < p->key) && (p->left == NULL))
		 {
			 p->left = z;
			 z->parent = p;
			 break;
		 }
		 else if ((z->key > p->key) && (p->right == NULL))
		 {
			 p->right = z;
			 z->parent = p;
			 break;
		 }
		 else if (z->key < p->key)
			 p = p->left;
		 else
			 p = p->right;
	 }*/
	 BSTNode<T>* y = NULL;
	 BSTNode<T>* x = tree;

	 while (x != NULL)
	 {
		 y = x;
		 if (z->key < y->key)
			 x = y->left;
		 else
			 x = y->right;
	 }

	 z->parent = y;
	 if (y == NULL)
		 tree = z;
	 else if (z->key < y->key)
		 y->left = z;
	 else
		 y->right = z;
 }

 template<typename T>
 void BSTree<T>::insert(T key)
 {
	 BSTNode<T>* p = new BSTNode<T>(key, NULL, NULL, NULL);
	 insert(mRoot, p);
 }

#endif // !BST_TREE

