// BinaryTree.cpp: �ܼ� ���� ���α׷��� �������� �����մϴ�.
//

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <math.h>

#pragma warning(disable:4996)

struct TreeNode
{
    int      key;

    TreeNode* Parents;
    TreeNode* left;
    TreeNode* right;
};

struct Tree
{
    TreeNode* Root;

    bool   bComplete;
    int      m_iSize;
};

//�ʱ�ȭ �ϴ� �Լ�
void init(Tree* target)
{
    target->Root = NULL;
    target->bComplete = true;
    target->m_iSize = 0;
}

//���� ã���� �ϴ� data�� ���� ������ �ľ��ϴ� �Լ�
bool searchNode(Tree* target, int data)
{
    TreeNode* curr = target->Root;

    while (true)
    {
        if (curr->key == data)
        {
            printf("���� �ֽ��ϴ�.\n");
            printf("%d ", curr->key);

            return true;
        }
        if (curr->key < data)
        {
            if (curr->right == NULL)return false;
            curr = curr->right;
        }
        else
        {
            if (curr->left == NULL)return false;
            curr = curr->left;
        }
    }
}

void addNode(Tree* target, int data)
{
    TreeNode* NewNode = (TreeNode*)malloc(sizeof(TreeNode));
    //��Ʈ��尡 ���� ���
    if (target->Root == NULL)
    {
        target->Root = NewNode;
        NewNode->left = NULL;
        NewNode->right = NULL;
        NewNode->Parents = NULL;
        NewNode->key = data;
		printf("inserted %d\n", NewNode->key);

        target->m_iSize++;
        return;
    }

    //������ data�� �̹� �����ϴ� ���
    if (searchNode(target, data))
    {
        printf("�̹� �����ϴ� ���Դϴ�.\n");
        return;
    }

    //���Ե� data�� �ڸ��� �˱����ؼ� ������� Ž���� �ʿ��� ���
    //��Ʈ��尡 �ܸ���尡 �ƴϸ�, �̹� �����ϴ� data�� ���� ���
    NewNode->left = NULL;
    NewNode->right = NULL;
    NewNode->key = data;
    TreeNode* curr = target->Root;

    while (true)
    {
        //data�� �� ū��� �� ������ ����Ʈ������ Ž���ؾ���
        if (curr->key < data)
        {
            if (curr->right == NULL)
            {
                curr->right = NewNode;
                NewNode->Parents = curr;
                target->m_iSize++;
                printf("inserted %d\n", NewNode->key);
                return;
            }
            //���� Ž���� ���� curr�� right�� �����Ѵ�.
            curr = curr->right;
        }
        else
        {
            if (curr->left == NULL)
            {
                curr->left = NewNode;
                NewNode->Parents = curr;
                target->m_iSize++;
                printf("inserted %d\n", NewNode->key);
                return;
            }
            //���� Ž���� ���� curr�� left�� �����Ѵ�.
            curr = curr->left;
        }
    }

}

int deleteNode(Tree* target, int data)
{
    TreeNode* curr1 = target->Root;
    TreeNode* curr2 = NULL;
    TreeNode* par_parent = NULL;
    TreeNode* parent = NULL;
    TreeNode* child = NULL;
    TreeNode* left_temp = NULL;
    int key_return = 0;

    //���� data���� ������ �� ����.
    if (!searchNode(target, data))
    {
        printf("���� ���Դϴ�.\n");
        return 0;
    }

    //Ư�� data������ �̵��Ѵ�.
    while (curr1->key != data)
    {
        //������ ����Ʈ����..
        if (data > curr1->key)
        {
            par_parent = parent;
            parent = curr1;
            curr1 = curr1->right;
        }
        else
        {
            par_parent = parent;
            parent = curr1;
            curr1 = curr1->left;

        }
    }
    //�����Ϸ��� ��尡 �ܸ������ ���
    if (curr1->left == NULL && curr1->right == NULL)
    {
        key_return = curr1->key;
        if (parent->left == curr1)
            parent->left = NULL;
        if (parent->right == curr1)
            parent->right == NULL;
        free(curr1);
        return key_return;
    }

    //�����Ϸ��� ����� �ڽ��� 1���� ���
    if (curr1->left == NULL || curr1->right == NULL)
    {
        child = (child->left == NULL) ? curr1->right : curr1->left;

        if (parent->left == curr1)
            parent->left = child;
        else
            parent->right = child;

        key_return = curr1->key;
        free(curr1);
        return key_return;
    }

    //�����Ϸ��� ����� �ڽ��� 2���� ���
    if (curr1->left != NULL && curr1->right != NULL)
    {
        curr2 = curr1;
        curr2 = curr2->right;

        if (curr2->left == NULL)
        {
            //���������� ��ĭ �̵� �� ���� ��尡 ���� �� 
            left_temp = curr1->left;
            child = curr2;

            if (parent->right == curr1)
            {
                parent->right = child;
                child->left = left_temp;

            }
            else if (parent->left == curr1)
            {
                parent->left = child;
                child->left = left_temp;
            }

            key_return = curr1->key;
            free(curr1);
            return key_return;

        }
        //���������� ��ĭ �̵� �� ���� ��尡 ���� ��
        while (curr2->left != NULL)
        {
            parent = curr2;
            curr2 = curr2->left;
        }

        parent->left = NULL;
        curr1->key = curr2->key;
        free(curr2);
    }

    return 0;
}

int GetNodeWeight(TreeNode* root)
{
    if (root != nullptr)
        return GetNodeWeight(root->left) + GetNodeWeight(root->right);
}

int NodeRealWeight(TreeNode* root)
{
    int Count = GetNodeWeight(root);

    return --Count;
}

void WhoisLagest(TreeNode* root, Tree* T)
{
    int iLeft = NodeRealWeight(root->left);
    int iRight = NodeRealWeight(root->right);

    if (iLeft < iRight)
        T->bComplete = false;
}

void isCompleteTree(TreeNode* root, Tree* target)
{
    if (target->bComplete)
    {
		if (root != NULL)
		{
			isCompleteTree(root->left, target);
			isCompleteTree(root->right, target);
			WhoisLagest(root, target);
		}
    }
}

//���� ��ȸ  
void preorder(TreeNode* root, Tree* target)
{
    if (root != NULL)
    {
        printf("%d ", root->key);
        printf("  ");
        preorder(root->left, target);
        preorder(root->right, target);
    }
}

//���� ��ȸ
void inorder(TreeNode* root)
{
	if (root != NULL)
	{
		inorder(root->left);
		printf("%d ", root->key);
		printf("  ");

		inorder(root->right);
	}
}

//���� ��ȸ
void postorder(TreeNode* root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->key);
        printf("  ");
    }
}

bool isComplete(Tree* target)
{
    if (target->bComplete)
        printf("���� ���� Ʈ���Դϴ�.");
    else
        printf("���� ���� Ʈ���� �ƴմϴ�.");


    return target->bComplete;
}

bool ReadData(Tree* target)
{
	FILE* pFile;

	pFile = fopen("data.txt", "r");

	if (pFile == NULL)
	{
		printf("File Read Error\n");
		return false;
	}


	while (!feof(pFile))
	{
		TreeNode treeStudent = {};

		fscanf(pFile, "%d", &treeStudent.key);
	
		addNode(target, treeStudent.key);
	}
}


int main()
{
    Tree   T;
    init(&T);

    ReadData(&T);

    isCompleteTree(T.Root, &T);
    isComplete(&T);

    return 0;
}