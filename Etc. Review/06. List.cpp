#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

typedef struct TreeNode 
{
	int key;
	struct TreeNode* left, * right;

} TreeNode;

// key�� ���� Ž�� Ʈ�� root�� �����Ѵ�.
// key�� �̹� root �ȿ� ������ ���Ե��� �ʴ´�.
void insert_node(TreeNode** root, int key)
{
	// t�� Ž���� ���� �����ʹ�.
	TreeNode* p, * t; // p�� �θ��带 ����Ű�� ������, t�� ������ ������
	TreeNode* n; // n�� ���ο� ���

	t = *root; // ó�� ���۽� ���� ���� root �� ��ü��.
	p = NULL; // root�� �θ���� ����. root ��ü�� ����

	// Ž���� ���� �����Ѵ�.
	while (t)
	{
		if (key == t->key) return;
		p = t; // �θ� ��带 ���� ���� �����Ѵ�. ���ο� ��Ʈ���.
		// ����Ʈ���� ���ο� ��Ʈ��尡 �����ϴ� �Ͱ� ���� ������.

		if (key < p->key) // �θ��� Ű ���� ��
			t = p->left; // ���� ���� �θ��� ���� ����Ʈ���� �ȴ�.
		else
			t = p->right; // ���� ���� �θ��� ������ ����Ʈ���� �ȴ�.
	}
	// key�� Ʈ�� �ȿ� �����Ƿ� ������ �����ϴ�.

	// ���� ���Ե� ��带 �����Ѵ�.
	n = (TreeNode*)malloc(sizeof(TreeNode));
	if (!n) return; // �����Ҵ� �������� ��� return

	// �����͸� �����Ѵ�.
	if (p) // �θ� ��尡 ������ ���
	{
		if (key < p->key)
			p->left = n;
		else
			p->right = n;
	}
	else // �θ� ��尡 ������ ���� ���� ��尡 ��Ʈ��尡 �ȴ�.
		*root = n;
}

// Ʈ���� ���̸� ���Ѵ�.
int get_height(TreeNode* root) 
{

	if (!root)
		return 0;

	else 
	{
		int left_h = get_height(root->left); // ���� ����Ʈ���� ���̸� ��ȯȣ���� ���� ��´�.
		int right_h = get_height(root->right); // ���� ������� ������ ����Ʈ���� ���̸� ��´�.
		return 1 + (left_h > right_h ? left_h : right_h); // �� �� ū ���� 1�� ���� ��ȯ�Ѵ�.
	}
}

// Ʈ���� �����ϴ� ��� ����� ������ ���Ѵ�.
int get_node_count(TreeNode* root) 
{
	if (!root)
		return 0;
	else
		return get_node_count(root->left) + get_node_count(root->right) + 1;
}

// Ʈ���� �����ϴ� �ܸ������ ������ ���Ѵ�.
int get_leaf(TreeNode* root) 
{
	if (!root)
		return 0;

	if (root->left == NULL && root->right == NULL)
		return 1;
	else
		return get_leaf(root->left) + get_leaf(root->right);
}

bool ReadData(TreeNode* target)
{
	FILE* pFile;

	pFile = fopen("data.txt", "r");

	if (pFile == NULL)
	{
		printf("File Open Error\n");
		return false;
	}
	while (!feof(pFile))
	{

	}
}

int main(void)
{

	bool bLoop = ReadData();
	return 0;
}