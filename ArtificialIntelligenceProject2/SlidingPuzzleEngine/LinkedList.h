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

		int getSize();

		bool isOrdered();


	private:
		LinkedListNodePtr m_pHead = nullptr;
		LinkedListNodePtr m_pTail = nullptr;

		int m_nSize = 0;
		bool m_bOrdered = false;
	};



	inline int LinkedList::getSize()
	{
		return m_nSize;
	}

	inline bool LinkedList::isOrdered()
	{
		return m_bOrdered;
	}
}

