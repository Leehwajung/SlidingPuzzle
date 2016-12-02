#pragma once
#include "Node.h"

namespace SlidingPuzzleSpace
{
	/* 노드에 대한 포인터들을 가지는 연결리스트 */
	class LinkedList
	{
	private:
		/* Data Structure */

		// Open, Closed의 연결 리스트의 노드에 대한 구조체 정의
		struct LinkedListNode
		{
			NodePtr nodePtr;
			LinkedListNode* next;
		};

		// Open, Closed의 연결 리스트의 포인터
		typedef LinkedListNode* LinkedListNodePtr;


	public:
		/* Constructor / Destructor */

		// Constructor
		// 사후 조건: ordered가 true이면 정렬된 리스트, false이면 정렬되지 않은 리스트가 생성됨.
		LinkedList(bool ordered);

		// Destructor
		~LinkedList();


		/* Operations */

		// 노드 넣기
		// 사후 조건: 노드가, 정렬된 리스트이면 적당한 순차적 위치에, 정렬되지 않은 리스트이면 헤드에 들어감.
		void put(NodePtr node);

		// 첫 번째 노드 가져오기
		// 사후 조건: 첫 번째 노드를 가져오고 리스트에서 제거함.
		NodePtr removeFirst();

		// 마지막 노드 가져오기
		// 사후 조건: 마지막 노드를 가져옴. (리스트에서 제거하지 않음.)
		NodePtr getLast();

		// 리스트의 크기 (길이)
		int getSize();

		// 정렬된 리스트인가
		bool isOrdered();


	private:
		/* Attributes */
		LinkedListNodePtr m_pHead = nullptr;	// 첫 번째 노드
		LinkedListNodePtr m_pTail = nullptr;	// 마지막 노드
		int m_nSize = 0;						// 리스트의 크기 (길이)
		bool m_bOrdered = false;				// 정렬된 리스트 여부
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

