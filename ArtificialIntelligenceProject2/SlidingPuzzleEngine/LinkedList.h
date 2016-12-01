#pragma once
#include "Node.h"

namespace SlidingPuzzleSpace
{
	/* 노드에 대한 포인터들을 가지는 연결리스트 */
	class LinkedList
	{
	private:
		/* Node */

		// Open, Closed의 연결 리스트의 노드에 대한 구조체 정의
		struct LinkedListNode
		{
			NodePtr nodePtr;
			LinkedListNode* next;
		};

		// Open, Closed의 연결 리스트의 포인터
		typedef LinkedListNode* LinkedListNodePtr;


	public:
		LinkedList(bool ordered);
		~LinkedList();

		void put(NodePtr node);

		NodePtr removeFirst();

		NodePtr getLast();

		bool isOrdered();


	private:
		LinkedListNodePtr m_pHead = nullptr;
		LinkedListNodePtr m_pTail = nullptr;

		bool m_bOrdered = false;
	};



	inline bool LinkedList::isOrdered()
	{
		return m_bOrdered;
	}
}

