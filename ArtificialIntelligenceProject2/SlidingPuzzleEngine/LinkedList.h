#pragma once
#include "State.h"

namespace SlidingPuzzleSpace
{
	/* Open, Closed의 연결 리스트의 포인터 */
	typedef struct LinkedListNode* LinkedListNodePtr;

	/* Open, Closed의 연결 리스트의 노드에 대한 구조체 정의 */
	struct LinkedListNode
	{
		StatePtr statePtr;
		LinkedListNodePtr next;
	};


	/* 노드에 대한 포인터들을 가지는 연결리스트 */
	class LinkedList
	{
	public:
		LinkedList();
		~LinkedList();

	private:
		LinkedListNodePtr m_pHead = nullptr;
	};
}

