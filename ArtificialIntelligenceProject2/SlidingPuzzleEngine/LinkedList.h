#pragma once
#include "Node.h"

namespace SlidingPuzzleSpace
{
	/* ��忡 ���� �����͵��� ������ ���Ḯ��Ʈ */
	class LinkedList
	{
	private:
		/* Data Structure */

		// Open, Closed�� ���� ����Ʈ�� ��忡 ���� ����ü ����
		struct LinkedListNode
		{
			NodePtr nodePtr;
			LinkedListNode* next;
		};

		// Open, Closed�� ���� ����Ʈ�� ������
		typedef LinkedListNode* LinkedListNodePtr;


	public:
		/* Constructor / Destructor */

		// Constructor
		// ���� ����: ordered�� true�̸� ���ĵ� ����Ʈ, false�̸� ���ĵ��� ���� ����Ʈ�� ������.
		LinkedList(bool ordered);

		// Destructor
		~LinkedList();


		/* Operations */

		// ��� �ֱ�
		// ���� ����: ��尡, ���ĵ� ����Ʈ�̸� ������ ������ ��ġ��, ���ĵ��� ���� ����Ʈ�̸� ��忡 ��.
		void put(NodePtr node);

		// ù ��° ��� ��������
		// ���� ����: ù ��° ��带 �������� ����Ʈ���� ������.
		NodePtr removeFirst();

		// ������ ��� ��������
		// ���� ����: ������ ��带 ������. (����Ʈ���� �������� ����.)
		NodePtr getLast();

		// ����Ʈ�� ũ�� (����)
		int getSize();

		// ���ĵ� ����Ʈ�ΰ�
		bool isOrdered();


	private:
		/* Attributes */
		LinkedListNodePtr m_pHead = nullptr;	// ù ��° ���
		LinkedListNodePtr m_pTail = nullptr;	// ������ ���
		int m_nSize = 0;						// ����Ʈ�� ũ�� (����)
		bool m_bOrdered = false;				// ���ĵ� ����Ʈ ����
	};



	inline NodePtr LinkedList::getLast()
	{
		return m_pTail->nodePtr;
	}

	inline int LinkedList::getSize()
	{
		return m_nSize;
	}

	inline bool LinkedList::isOrdered()
	{
		return m_bOrdered;
	}
}

