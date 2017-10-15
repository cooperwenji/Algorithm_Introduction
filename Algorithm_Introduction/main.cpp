#include"avl_tree.h"
#include"bst_tree.h"

static int arr[] = { 3, 2, 1, 4, 5, 6, 7, 16, 15, 14, 13, 12,11,10,8,9 };

//avl_tree  test code
/*
int i, ilen;
AVLTree<int>* tree = new AVLTree<int>();

ilen = sizeof(arr) / sizeof(arr[0]);
std::cout << "������ӣ� ";
for (int i = 0; i < ilen; i++)
{
	std::cout << arr[i] << "  ";
	tree->insert(arr[i]);
}

std::cout << "\n== ǰ������� ";
tree->preOrder();

std::cout << "\n== ��������� ";
tree->inOrder();

std::cout << "\n== ��������� ";
tree->postOrder();
std::cout << std::endl;

std::cout << "==�߶�: " << tree->height() << std::endl;
std::cout << "==��Сֵ" << tree->minimum() << std::endl;
std::cout << "==���ֵ" << tree->maximum() << std::endl;

tree->remove(8);
std::cout << "\n== ɾ�����ڵ㣺" << "8";
std::cout << "\n==�߶ȣ� " << tree->height();
std::cout << "\n==��������� ";
tree->inOrder();

tree->destroy();*/



int main()
{
	int i, ilen;
	BSTree<int>* tree = new BSTree<int>();

	ilen = sizeof(arr) / sizeof(arr[0]);
	std::cout << "������ӣ� ";
	for (int i = 0; i < ilen; i++)
	{
		std::cout << arr[i] << "  ";
		tree->insert(arr[i]);
	}

	std::cout << "\n== ��������� ";
	tree->inOrder();

	system("pause");
}