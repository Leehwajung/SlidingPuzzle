#pragma once
#include "Node.h"

namespace SlidingPuzzleSpace
{
	/* ��忡 ���� �����͵��� ������ ���Ḯ��Ʈ */
	class LinkedList
	{
	private:
		/* Node */

		// Open, Closed�� ���� ����Ʈ�� ��忡 ���� ����ü ����
		struct LinkedListNode
		{
			NodePtr nodePtr;
			LinkedListNode* next;
		};

		// Open, Closed�� ���� ����Ʈ�� ������
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

