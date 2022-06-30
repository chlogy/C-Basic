#include <stdio.h>
#define MAX_SIZE 20000    // Heap �� �ִ� ���� ���� 

#pragma warning(disable:4996)


// Heap ���
typedef struct 
{ 
	int key;    // key
	/* ���⿡ ������ �߰� ���� ex) int data */
}element;

// Heap �ڷᱸ�� 
typedef struct 
{
	element heap[MAX_SIZE];
	int size;
}Heap;


void min_heap_insert(Heap* h, element item) 
{
	int i;
	i = ++(h->size);    // ������ ��ġ(������ ������ index+1) 

	/* ��Ʈ��尡 �ƴϰ�, ������ ���� ������ ��ġ�� ã�� ������*/
	while ((i != 1) && (item.key < h->heap[i / 2].key)) {
		h->heap[i] = h->heap[i / 2];    // �ڽ� ���� �θ��� ��ȯ 
		i /= 2;    // �� ���� ���� �ö� 
	}

	h->heap[i] = item;    // ���ο� ��� ����     
}

void max_heap_insert(Heap* h, element item) 
{
	int i;
	i = ++(h->size);    // ������ ��ġ(������ ������ index+1) 

	/* ��Ʈ��尡 �ƴϰ�, ������ ���� ������ ��ġ�� ã�� ������*/
	while ((i != 1) && (item.key > h->heap[i / 2].key)) {
		h->heap[i] = h->heap[i / 2];    // �ڽ� ���� �θ��� ��ȯ 
		i /= 2;    // �� ���� ���� �ö� 
	}

	h->heap[i] = item;    // ���ο� ��� ����     
}

element max_heap_delete(Heap* h) 
{
	int parent, child;
	element item, temp;

	item = h->heap[1];				// ��ȯ�� ��� ����
	temp = h->heap[(h->size)--];    // ������ ��� temp �� ����, ������ 1����
	parent = 1;
	child = 2;

	while (child <= h->size) 
	{
		/* ���� �ڽ� ���� ������ �ڽ� ��� �� �� ū �ڽ� ���*/
		if ((child < h->size) && ((h->heap[child].key) < h->heap[child + 1].key)) 
		{
			child++;    // ������ �ڽ� ��� ����
		}

		/* ������ ��尡 �ڽ� ��庸�� ũ�� ���� */
		if (temp.key >= h->heap[child].key) 
		{
			break;
		}

		/* �θ���� �ڽĳ�� ��ȯ */
		h->heap[parent] = h->heap[child];

		/* �� ���� �Ʒ��� �̵� */
		parent = child;
		child *= 2;
	}

	/* ������ ��带 �缳���� ��ġ�� ���� */
	h->heap[parent] = temp;

	/* �ִ� ��� ��ȯ */
	return item;

}

element min_heap_delete(Heap* h)
{
	int parent, child;
	element item, temp;

	item = h->heap[1];				// ��ȯ�� ��� ����
	temp = h->heap[(h->size)--];    // ������ ��� temp �� ����, ������ 1����
	parent = 1;
	child = 2;

	while (child <= h->size)
	{
		/* ���� �ڽ� ���� ������ �ڽ� ��� �� �� ���� �ڽ� ���*/
		if ((child < h->size) && ((h->heap[child].key) > h->heap[child + 1].key))
		{
			child++;    // ������ �ڽ� ��� ����
		}

		/* ������ ��尡 �ڽ� ��庸�� �۴ٸ� ���� */
		if (temp.key <= h->heap[child].key)
		{
			break;
		}

		/* �θ���� �ڽĳ�� ��ȯ */
		h->heap[parent] = h->heap[child];

		/* �� ���� �Ʒ��� �̵� */
		parent = child;
		child *= 2;
	}

	/* ������ ��带 �缳���� ��ġ�� ���� */
	h->heap[parent] = temp;

	/* �ּڰ� ��� ��ȯ */
	return item;

}

void ReadData(Heap* target, bool isMaxHeap)
{
	FILE* pFile;

	pFile = fopen("data.txt", "r");

	if (pFile == NULL)
	{
		printf("File Open Error\n");
		return;
	}


	while (!feof(pFile))
	{
		Heap tElement = {};
		
		element item;

		fscanf(pFile, "%d", &item.key);

		if (isMaxHeap)
			max_heap_insert(target, item);
		else
			min_heap_insert(target, item);
	}

	fclose(pFile);
}

void Initialize_Heap(Heap*	_Target)
{
	for (int i = 0; i < MAX_SIZE; i++)
	{
		_Target->heap->key = 0;
	}
	_Target->size = 0;
}

void ResultOutput(Heap* _Target, bool isAscending)
{
	element Curitem = {};
	element Previtem = {};
	int iCount = 0;

	for (int i = 0; i < _Target->size; i++)
	{
		if (isAscending)		
			Curitem = max_heap_delete(_Target);
		else
			Curitem = min_heap_delete(_Target);

		if (Curitem.key != Previtem.key)
		{
			printf("%d ", Curitem.key);
			iCount++;
		}

		Previtem = Curitem;

		if (iCount == 5)
			return;
	}
}

int main() 
{
	Heap max_heap;
	Initialize_Heap(&max_heap);

	Heap min_heap;
	Initialize_Heap(&min_heap);

	ReadData(&max_heap, true);
	ReadData(&min_heap, false);

	printf("�ִ� �� ��ȯ\n");
	ResultOutput(&max_heap, true);

	printf("\n\n\n\n�ּ� �� ��ȯ\n");
	ResultOutput(&min_heap, false);


	return 0;
}