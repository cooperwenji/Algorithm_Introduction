#ifndef AVL_TREE_H
#define AVL_TREE_H

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
template <typename T>
class AVLTree {
  private:
	  AVLTreeNode<T> *mRoot;  //���ڵ�

  public:
	  AVLTree();
	  ~AVLTree();

};


#endif // !AVL_TREE_H

