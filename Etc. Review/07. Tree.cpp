// BinaryTree.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
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

//초기화 하는 함수
void init(Tree* target)
{
    target->Root = NULL;
    target->bComplete = true;
    target->m_iSize = 0;
}

//단지 찾고자 하는 data의 존재 유무만 파악하는 함수
bool searchNode(Tree* target, int data)
{
    TreeNode* curr = target->Root;

    while (true)
    {
        if (curr->key == data)
        {
            printf("값이 있습니다.\n");
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
    //루트노드가 없는 경우
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

    //삽입할 data가 이미 존재하는 경우
    if (searchNode(target, data))
    {
        printf("이미 존재하는 값입니다.\n");
        return;
    }

    //삽입될 data의 자리를 알기위해서 어느정도 탐색이 필요한 경우
    //루트노드가 단말노드가 아니며, 이미 존재하는 data도 없는 경우
    NewNode->left = NULL;
    NewNode->right = NULL;
    NewNode->key = data;
    TreeNode* curr = target->Root;

    while (true)
    {
        //data가 더 큰경우 즉 오른쪽 서브트리에서 탐색해야함
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
            //다음 탐색을 위해 curr의 right를 설정한다.
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
            //다음 탐색을 위해 curr의 left를 설정한다.
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

    //없는 data값을 삭제할 순 없다.
    if (!searchNode(target, data))
    {
        printf("없는 값입니다.\n");
        return 0;
    }

    //특정 data값까지 이동한다.
    while (curr1->key != data)
    {
        //오른족 서브트리로..
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
    //삭제하려는 노드가 단말노드일 경우
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

    //삭제하려는 노드의 자식이 1개일 경우
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

    //삭제하려는 노드의 자식이 2개일 경우
    if (curr1->left != NULL && curr1->right != NULL)
    {
        curr2 = curr1;
        curr2 = curr2->right;

        if (curr2->left == NULL)
        {
            //오른쪽으로 한칸 이동 후 왼쪽 노드가 없을 때 
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
        //오른쪽으로 한칸 이동 후 왼쪽 노드가 있을 때
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

//전위 순회  
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

//중위 순회
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

//후위 순회
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
        printf("완전 이진 트리입니다.");
    else
        printf("완전 이진 트리가 아닙니다.");


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