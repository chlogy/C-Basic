/*
* �ۼ���:20184426������
* �ۼ���:2021.09.29
* ���α׷���:����Ʈ���� �̿��� ������� ���α׷�
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

#pragma warning(disable:4996)


#define MAX_WORD_SIZE 100
#define MAX_MEANING_SIZE 200

//������ ����
struct element
{
	char word[MAX_WORD_SIZE];  //Ű�ʵ�
	char meaning[MAX_MEANING_SIZE];

};

//����� ����
struct TreeNode 
{
	element key;
	struct TreeNode* left, * right;
};

//���� e1 < e2 �̸� -1 ��ȯ
//���� e1 == e2 �̸� 0 ��ȯ
//���� e1 > e2 �̸� 1 ��ȯ
int compare(element e1, element e2)
{
	return strcmp(e1.word, e2.word);
}

//���� Ž�� Ʈ�� ��� �Լ�
void display(TreeNode* p)
{
	if (p != NULL) 
	{
		printf(" ");
		display(p->left);
		printf("%s:%s", p->key.word, p->key.meaning);
		display(p->right);
		printf(" ");
	}
}

//���� Ž�� Ʈ�� Ž�� �Լ�
void search(TreeNode* root, element key)
{
	TreeNode* p = root;

	while (p != NULL)
	{
		if (compare(key, p->key) == 0)
			break;
		else if (compare(key, p->key) < 0)
			p = p->left;
		else if (compare(key, p->key) > 0)
			p = p->right;
	}

	if (p != NULL)
		printf("�ǹ�:%s\n", p->key.meaning);
}

TreeNode* new_node(element item)
{
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));

	temp->key = item;
	temp->left = temp->right = NULL;

	return temp;
}

TreeNode* insert_node(TreeNode* node, element key)
{
	//Ʈ���� �����̸� ���ο� ��带 ��ȯ�Ѵ�.
	if (node == NULL) return new_node(key);

	//�׷��� ������ ��ȯ������ Ʈ���� ��������.
	if (compare(key, node->key) < 0)
		node->left = insert_node(node->left, key);

	else if (compare(key, node->key) > 0)
		node->right = insert_node(node->right, key);

	//��Ʈ �����͸� ��ȯ�Ѵ�.
	return node;
}

TreeNode* min_value_node(TreeNode* node)
{
	TreeNode* current = node;

	//�� ���� �ܸ� ��带 ã���� ������
	while (current->left != NULL)
		current = current->left;

	return current;
}

//���� Ž�� Ʈ���� Ű�� �־����� Ű�� ����� ��带 �����ϰ� ���ο� ��Ʈ ��带 ��ȯ�Ѵ�.
TreeNode* delete_node(TreeNode* root, element key)
{
	if (root == NULL) return root;

	//���� Ű�� ��Ʈ���� ������ ���� ���� Ʈ���� �ִ� ����
	if (compare(key, root->key) < 0)
		root->left = delete_node(root->left, key);

	//���� Ű�� ��Ʈ���� ũ�� ������ ���� Ʈ���� �ִ� ����
	else if (compare(key, root->key) > 0)
		root->right = delete_node(root->right, key);

	//Ű�� ��Ʈ�� ������ �� ��带 �����ϸ� ��
	else
	{
		//ù ��°�� �� ��° ���
		if (root->left == NULL)
		{
			TreeNode* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL)
		{
			TreeNode* temp = root->left;
			free(root);
			return temp;
		}

		//����° ���
		TreeNode* temp = min_value_node(root->right);

		//���� ��ȸ�� �İ� ��带 �����Ѵ�.
		root->key = temp->key;

		//���� ��ȸ�� �İ� ��带 �����Ѵ�.
		root->right = delete_node(root->right, temp->key);
	}
	return root;
}

void help()
{
	printf("\n**** i : �Է�, d : ����, s : Ž��, p : ���, q : ���� ****: ");
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
		TreeNode tElement = {};
		char ch;

		fscanf(pFile, "%c", &ch);

		switch (ch)
		{
		case 'i':
			fscanf(pFile, "%s %s", tElement.key.word, tElement.key.meaning);

			printf("%c\n", ch);
			printf("�ܾ�:%s\n", tElement.key.word);
			printf("�ǹ�:%s\n", tElement.key.meaning);
			target = insert_node(target, tElement.key);
			printf("\n");
			break;
		case 's':
			fscanf(pFile, "%s", tElement.key.word);

			printf("%c\n", ch);
			printf("�ܾ�:%s\n", tElement.key.word);
			search(target, tElement.key);
			printf("\n");
			break;
		case 'd':
			fscanf(pFile, "%s", tElement.key.word);

			printf("%c\n", ch);
			printf("�ܾ�:%s\n", tElement.key.word);
			target = delete_node(target, tElement.key);
			printf("\n");
			break;
		case 'p':
			printf("%c\n", ch);
			display(target);
			printf("\n");
			break;
		case 'q':
			printf("%c\n", ch);
			printf("\n");

			fclose(pFile);
			return false;
		}

	}

	fclose(pFile);

	return true;
}



//���� Ž�� Ʈ���� ����ϴ� ���� ���� ���α׷�
int main(void)
{
	char command;
	element e;

	TreeNode* root = NULL;
	TreeNode* tmp;

	bool bLoop = ReadData(root);

	do 
	{
		help();
		command = getchar();
		getchar(); //����Ű ����

		switch (command)
		{
		case 'i':
			printf("�ܾ�:");
			gets_s(e.word);
			printf("�ǹ�:");
			gets_s(e.meaning);
			root = insert_node(root, e);
			break;

		case 'd':
			printf("�ܾ�:");
			gets_s(e.word);
			root = delete_node(root, e);
			break;

		case 'p':
			display(root);
			printf("\n");
			break;

		case 's':
			printf("�ܾ�:");
			gets_s(e.word);
			search(root, e);
			break;

		case 'q':
			bLoop = false;
		}
	} while (bLoop);


	return 0;
}