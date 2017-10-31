#include"avl_tree.h"
#include"bst_tree.h"
#include"Point.h"

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

//bst_tree test code
/*int i, ilen;
BSTree<int>* tree = new BSTree<int>();

ilen = sizeof(arr) / sizeof(arr[0]);
std::cout << "依次添加： ";
for (int i = 0; i < ilen; i++)
{
	std::cout << arr[i] << "  ";
	tree->insert(arr[i]);
}

std::cout << "\n== 中序遍历： ";
tree->inOrder();*/

//装配线调度问题
void print_assembly_line(int** l, int choose, int index) {
	if (index < 0) return;
	print_assembly_line(l, l[choose][index - 1], index - 1);
	printf("line %d, station %d \n", choose + 1, index + 1);
}

void assemblyLineScheduling()
{	
	//输入数据
	int assembly_line_1[] = { 7, 9, 3, 4, 8, 4 }; //装配线1 各站点权值
	int assembly_line_2[] = { 8, 5, 6, 4, 5, 7 }; //装配线2 各站点权值
	int change_line_1[] = { 2, 3, 1, 3, 4 };      //从装配线1到装配线2 转换权值
	int change_line_2[] = { 2 , 1, 2, 2, 1 };     //从装配线2到装配线1 转换权值
	int in_line_1 = 2;						      //进入装配线1的权值
	int out_line_1 = 3;							  //出去装配线1的权值
	int in_line_2 = 4;                            //进入装配线2的权值
	int out_line_2 = 2;                           //出去装配线2的权值

	int line_len = sizeof(assembly_line_1) / sizeof(int);

	//temp
	int* f[2];
	for (int i = 0; i < 2; i++) f[i] = new int[line_len];
	int* l[2];
	for (int i = 0; i < 2; i++) l[i] = new int[line_len - 1];

	int min_weight;                               //最终最小权值
	int l_final;								  //最终选择的装配线号

	f[0][0] = in_line_1 + assembly_line_1[0];
	f[1][0] = in_line_2 + assembly_line_2[0];
	for (int j = 1; j < line_len; j++) 
	{
		if (f[0][j - 1] + assembly_line_1[j] < f[1][j - 1] + assembly_line_1[j] + change_line_2[j - 1]) {
			f[0][j] = f[0][j - 1] + assembly_line_1[j];
			l[0][j - 1] = 0;
		}
		else {
			f[0][j] = f[1][j - 1] + assembly_line_1[j] + change_line_2[j - 1];
			l[0][j - 1] = 1;
		}
			
		if (f[1][j - 1] + assembly_line_2[j] < f[0][j - 1] + assembly_line_2[j] + change_line_1[j - 1]) {
			f[1][j] = f[1][j - 1] + assembly_line_2[j];
			l[1][j - 1] = 1;
		}
		else {
			f[1][j] = f[0][j - 1] + assembly_line_2[j] + change_line_1[j - 1];
			l[1][j - 1] = 0;
		}		
	}

	//打印信息
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < line_len- 1; j++)
			printf("%d ", l[i][j]);
		printf("\n");
	}

	//最小的路径选择
	if (f[0][line_len - 1] + out_line_1 < f[1][line_len - 1] + out_line_2) {
		min_weight = f[0][line_len - 1] + out_line_1;
		l_final = 0;
	}
	else {
		min_weight = f[1][line_len - 1] + out_line_2;
		l_final = 1;
	}

	print_assembly_line(l, l_final, line_len-1);
}
void temo() {}
int main()
{
	assemblyLineScheduling();
	system("pause");
}