#include"avl_tree.h"
#include"bst_tree.h"

static int arr[] = { 3, 2, 1, 4, 5, 6, 7, 16, 15, 14, 13, 12,11,10,8,9 };

//avl_tree  test code
/*
int i, ilen;
AVLTree<int>* tree = new AVLTree<int>();

ilen = sizeof(arr) / sizeof(arr[0]);
std::cout << "依次添加： ";
for (int i = 0; i < ilen; i++)
{
	std::cout << arr[i] << "  ";
	tree->insert(arr[i]);
}

std::cout << "\n== 前序遍历： ";
tree->preOrder();

std::cout << "\n== 中序遍历： ";
tree->inOrder();

std::cout << "\n== 后序遍历： ";
tree->postOrder();
std::cout << std::endl;

std::cout << "==高度: " << tree->height() << std::endl;
std::cout << "==最小值" << tree->minimum() << std::endl;
std::cout << "==最大值" << tree->maximum() << std::endl;

tree->remove(8);
std::cout << "\n== 删除根节点：" << "8";
std::cout << "\n==高度： " << tree->height();
std::cout << "\n==中序遍历： ";
tree->inOrder();

tree->destroy();*/



int main()
{
	int i, ilen;
	BSTree<int>* tree = new BSTree<int>();

	ilen = sizeof(arr) / sizeof(arr[0]);
	std::cout << "依次添加： ";
	for (int i = 0; i < ilen; i++)
	{
		std::cout << arr[i] << "  ";
		tree->insert(arr[i]);
	}

	std::cout << "\n== 中序遍历： ";
	tree->inOrder();

	system("pause");
}