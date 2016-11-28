#pragma once
#include "State.h"

namespace SlidingPuzzleSpace
{
	/* Open, Closed�� ���� ����Ʈ�� ������ */
	typedef struct LinkedListNode* LinkedListNodePtr;

	/* Open, Closed�� ���� ����Ʈ�� ��忡 ���� ����ü ���� */
	struct LinkedListNode
	{
		StatePtr statePtr;
		LinkedListNodePtr next;
	};


	/* ��忡 ���� �����͵��� ������ ���Ḯ��Ʈ */
	class LinkedList
	{
	public:
		LinkedList();
		~LinkedList();

	private:
		LinkedListNodePtr m_pHead = nullptr;
	};
}

