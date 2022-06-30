#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

typedef struct TreeNode 
{
	int key;
	struct TreeNode* left, * right;

} TreeNode;

// key를 이진 탐색 트리 root에 삽입한다.
// key가 이미 root 안에 있으면 삽입되지 않는다.
void insert_node(TreeNode** root, int key)
{
	// t는 탐색을 위한 포인터다.
	TreeNode* p, * t; // p는 부모노드를 가리키는 포인터, t는 현재노드 포인터
	TreeNode* n; // n은 새로운 노드

	t = *root; // 처음 시작시 현재 노드는 root 그 자체다.
	p = NULL; // root의 부모노드는 없다. root 자체가 시초

	// 탐색을 먼저 수행한다.
	while (t)
	{
		if (key == t->key) return;
		p = t; // 부모 노드를 현재 노드로 설정한다. 새로운 루트노드.
		// 서브트리의 새로운 루트노드가 등장하는 것과 같은 원리다.

		if (key < p->key) // 부모의 키 값과 비교
			t = p->left; // 현재 노드는 부모의 왼쪽 서브트리가 된다.
		else
			t = p->right; // 현재 노드는 부모의 오른쪽 서브트리가 된다.
	}
	// key가 트리 안에 없으므로 삽입이 가능하다.

	// 새로 삽입될 노드를 생성한다.
	n = (TreeNode*)malloc(sizeof(TreeNode));
	if (!n) return; // 동적할당 실패했을 경우 return

	// 데이터를 복사한다.
	if (p) // 부모 노드가 존재할 경우
	{
		if (key < p->key)
			p->left = n;
		else
			p->right = n;
	}
	else // 부모 노드가 없으니 새로 생긴 노드가 루트노드가 된다.
		*root = n;
}

// 트리의 높이를 구한다.
int get_height(TreeNode* root) 
{

	if (!root)
		return 0;

	else 
	{
		int left_h = get_height(root->left); // 왼쪽 서브트리의 높이를 순환호출을 통해 얻는다.
		int right_h = get_height(root->right); // 같은 방법으로 오른쪽 서브트리의 높이를 얻는다.
		return 1 + (left_h > right_h ? left_h : right_h); // 둘 중 큰 값에 1을 더해 반환한다.
	}
}

// 트리에 존재하는 모든 노드의 갯수를 구한다.
int get_node_count(TreeNode* root) 
{
	if (!root)
		return 0;
	else
		return get_node_count(root->left) + get_node_count(root->right) + 1;
}

// 트리에 존재하는 단말노드의 갯수를 구한다.
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