#include <stdio.h>
#define MAX_SIZE 20000    // Heap 의 최대 원소 개수 

#pragma warning(disable:4996)


// Heap 노드
typedef struct 
{ 
	int key;    // key
	/* 여기에 데이터 추가 가능 ex) int data */
}element;

// Heap 자료구조 
typedef struct 
{
	element heap[MAX_SIZE];
	int size;
}Heap;


void min_heap_insert(Heap* h, element item) 
{
	int i;
	i = ++(h->size);    // 마지막 위치(마지막 원소의 index+1) 

	/* 루트노드가 아니고, 삽입할 값이 적절한 위치를 찾을 때까지*/
	while ((i != 1) && (item.key < h->heap[i / 2].key)) {
		h->heap[i] = h->heap[i / 2];    // 자식 노드와 부모노드 교환 
		i /= 2;    // 한 레벨 위로 올라감 
	}

	h->heap[i] = item;    // 새로운 노드 삽입     
}

void max_heap_insert(Heap* h, element item) 
{
	int i;
	i = ++(h->size);    // 마지막 위치(마지막 원소의 index+1) 

	/* 루트노드가 아니고, 삽입할 값이 적절한 위치를 찾을 때까지*/
	while ((i != 1) && (item.key > h->heap[i / 2].key)) {
		h->heap[i] = h->heap[i / 2];    // 자식 노드와 부모노드 교환 
		i /= 2;    // 한 레벨 위로 올라감 
	}

	h->heap[i] = item;    // 새로운 노드 삽입     
}

element max_heap_delete(Heap* h) 
{
	int parent, child;
	element item, temp;

	item = h->heap[1];				// 반환할 노드 저장
	temp = h->heap[(h->size)--];    // 마지막 노드 temp 에 저장, 사이즈 1감소
	parent = 1;
	child = 2;

	while (child <= h->size) 
	{
		/* 왼쪽 자식 노드와 오른쪽 자식 노드 중 더 큰 자식 노드*/
		if ((child < h->size) && ((h->heap[child].key) < h->heap[child + 1].key)) 
		{
			child++;    // 오른쪽 자식 노드 선택
		}

		/* 마지막 노드가 자식 노드보다 크면 종료 */
		if (temp.key >= h->heap[child].key) 
		{
			break;
		}

		/* 부모노드와 자식노드 교환 */
		h->heap[parent] = h->heap[child];

		/* 한 레벨 아래로 이동 */
		parent = child;
		child *= 2;
	}

	/* 마지막 노드를 재설정한 위치에 삽입 */
	h->heap[parent] = temp;

	/* 최댓값 노드 반환 */
	return item;

}

element min_heap_delete(Heap* h)
{
	int parent, child;
	element item, temp;

	item = h->heap[1];				// 반환할 노드 저장
	temp = h->heap[(h->size)--];    // 마지막 노드 temp 에 저장, 사이즈 1감소
	parent = 1;
	child = 2;

	while (child <= h->size)
	{
		/* 왼쪽 자식 노드와 오른쪽 자식 노드 중 더 작은 자식 노드*/
		if ((child < h->size) && ((h->heap[child].key) > h->heap[child + 1].key))
		{
			child++;    // 오른쪽 자식 노드 선택
		}

		/* 마지막 노드가 자식 노드보다 작다면 종료 */
		if (temp.key <= h->heap[child].key)
		{
			break;
		}

		/* 부모노드와 자식노드 교환 */
		h->heap[parent] = h->heap[child];

		/* 한 레벨 아래로 이동 */
		parent = child;
		child *= 2;
	}

	/* 마지막 노드를 재설정한 위치에 삽입 */
	h->heap[parent] = temp;

	/* 최솟값 노드 반환 */
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

	printf("최대 힙 반환\n");
	ResultOutput(&max_heap, true);

	printf("\n\n\n\n최소 힙 반환\n");
	ResultOutput(&min_heap, false);


	return 0;
}