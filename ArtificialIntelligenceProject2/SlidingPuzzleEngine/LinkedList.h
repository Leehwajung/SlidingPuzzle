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

