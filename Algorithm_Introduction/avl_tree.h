#ifndef AVL_TREE_H
#define AVL_TREE_H

#include<iostream>

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

};


#endif // !AVL_TREE_H

