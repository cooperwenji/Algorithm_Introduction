#include"avl_tree.h"
#include"bst_tree.h"
#include"Point.h"

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

//bst_tree test code
/*int i, ilen;
BSTree<int>* tree = new BSTree<int>();

ilen = sizeof(arr) / sizeof(arr[0]);
std::cout << "������ӣ� ";
for (int i = 0; i < ilen; i++)
{
	std::cout << arr[i] << "  ";
	tree->insert(arr[i]);
}

std::cout << "\n== ��������� ";
tree->inOrder();*/

//װ���ߵ�������
void print_assembly_line(int** l, int choose, int index) {
	if (index < 0) return;
	print_assembly_line(l, l[choose][index - 1], index - 1);
	printf("line %d, station %d \n", choose + 1, index + 1);
}

void assemblyLineScheduling()
{	
	//��������
	int assembly_line_1[] = { 7, 9, 3, 4, 8, 4 }; //װ����1 ��վ��Ȩֵ
	int assembly_line_2[] = { 8, 5, 6, 4, 5, 7 }; //װ����2 ��վ��Ȩֵ
	int change_line_1[] = { 2, 3, 1, 3, 4 };      //��װ����1��װ����2 ת��Ȩֵ
	int change_line_2[] = { 2 , 1, 2, 2, 1 };     //��װ����2��װ����1 ת��Ȩֵ
	int in_line_1 = 2;						      //����װ����1��Ȩֵ
	int out_line_1 = 3;							  //��ȥװ����1��Ȩֵ
	int in_line_2 = 4;                            //����װ����2��Ȩֵ
	int out_line_2 = 2;                           //��ȥװ����2��Ȩֵ

	int line_len = sizeof(assembly_line_1) / sizeof(int);

	//temp
	int* f[2];
	for (int i = 0; i < 2; i++) f[i] = new int[line_len];
	int* l[2];
	for (int i = 0; i < 2; i++) l[i] = new int[line_len - 1];

	int min_weight;                               //������СȨֵ
	int l_final;								  //����ѡ���װ���ߺ�

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

	//��ӡ��Ϣ
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < line_len- 1; j++)
			printf("%d ", l[i][j]);
		printf("\n");
	}

	//��С��·��ѡ��
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