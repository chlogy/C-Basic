/*
	Linked List : 자료구조의 한 종류. 자료구조란 데이터를 관리하는 방버을 말한다.

				  링크드 리스트는 데이터 목록을 연결시켜서 접근할 수 있는 구조를 말한다.
				  링크드 리스트는 데이터를 저장하기 위한 노드라는 것이 존재한다. 각 노드의 특징은
				  다음 노드를 알 수 있다. (다음 노드의 메모리 주소를 저장하기 때문에)

				  리스트는 선형 구조로 되어있다. 그래서 배열처럼 특정 요소에 바로 접근이 불가능하다.
				  무조건 앞에서부터 차례대로 타고 들어가야 한다.

				  노드를 새로 추가할 때는 노드를 생성하고 마지막 노드에 연결만 해주면 되기 때문에
				  개수의 제한이 없다.

	각 자료구조의 특징

	Stack : 후입선출 자료형. LIFO
	Queue : 선입선출 자료형. FIFO

	Dynamic Array (동적배열)
	장점 : 인덱스 접근 방식이라 특정 인덱스를 알고있다면 접근의 속도가 빠르고 일정하다.		속도:O(1) (특정 인덱스를 알고있다면)
																						속도:O(N) (모른다면)
	단점 :	1.  사용하기 전에 배열의 크기를 지정해야하고 지정한 크기로 고정.
				만약 기존의 크기를 넘어서 데이터를 저장하려면 더 큰 크기의 배열을 새로 할당받아서 사용.
				이 과정에서 기존 데이터를 복사해야함. 그러므로 시간이 비교적 오래걸림.

			2.	삽입 / 삭제가 번거롭다.
				배열의 중간 원소를 삽입 / 삭제를 할 경우 나머지 원소들
				배열의 중간 원소를 삽입 / 삭제를 할 경우 나머지 원소들의 연속적인 순서를 맞추기 위해서
				삽입 / 삭제가 일어난 곳으로부터 뒤의 모든 데이터들은 모두 한칸씩 밀거나 당겨야 한다.
				원소들을 모두 옮기는데 드는 시간 복잡도 : O(N)

			3.	메모리를 한 덩어리로 차지하므로, 배열의 크기가 클 경우 배열 전체를 위한 메모리를 할당받지 못하는 경우도 생길 수 있다.
				자세한 검색 키워드 : Memory Segmentation



	Linked List
	장점 :	1.	개수의 제한이 없다.
			2.	삽입 / 삭제가 쉽다. 해당 항목(노드) 생성 후 그 노드의 주소를 연결만 시켜주면 되기 때문이다.
			3.	배열처럼 메모리 단편화에 대한 걱정을 하지 않아도 된다.

	단점 :	1.	항목에 대한 접근이 오래걸린다.
				첫 항목부터 순차적으로 접근하므로 최대 O(N)의 시간이 걸린다.
			2.	물리적으로 인접한 메모리에 위치해 있지 않다. 접근 시간과 캐싱에 유리함.
			3.	추가적인 참조 포인터를 위한 메모리 공간이 낭비되기 때문에 오버헤드가 일어난다.


	이진탐색트리
	장점 :	탐색의 속도를 개선할 수 있다. O(log₂N)
	단점 :	1. 추가 / 삭제가 복잡하다.
			2. 한쪽으로 치우친 이진트리가 될 경우 속도가 O(n)에 가까워진다.


	그래프
	각 노드가 지정되고 이동하는 가중치가 주어질 때 출발지에서 도착지까지가는 비용을 계산하는데 용이하다.
*/

#include <iostream>

using namespace std;

struct __tagDynamicArray
{
	int* pArray = nullptr;
	int		iArraySize;
	int		iCount;

	void push_back(int _x)
	{
		if (!pArray)
		{
			iArraySize = 2;
			pArray = new int[iArraySize];
		}

		if (iArraySize == iCount)
		{
			iArraySize *= 2;
			int* pCreateArray = new int[iArraySize];

			memcpy(pCreateArray, pArray, sizeof(int) * iCount);
			delete pArray;

			pArray = pCreateArray;
		}

		pArray[iCount] = _x;
		++iCount;
	}

	void Clear()
	{
		delete[] pArray;
	}
};

int main()
{
	__tagDynamicArray	tArray = {};

	for (int i = 0; i < 1000; i++)
	{
		tArray.push_back(i);
	}

	for (int i = 0; i < 1000; i++)
	{
		cout << tArray.pArray[i] << endl;
	}

	tArray.Clear();

	return 0;
}