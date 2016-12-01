#include "pch.h"
#include "LinkedList.h"

namespace SlidingPuzzleSpace
{
	LinkedList::LinkedList(bool ordered)
		: m_bOrdered(ordered)
	{
	}

	LinkedList::~LinkedList()
	{
		for (LinkedListNodePtr next = m_pHead, curr = nullptr; next;) {
			curr = next;
			next = curr->next;
			delete curr;
		}
	}

	void LinkedList::put(NodePtr node)
	{
		m_nSize++;

		LinkedListNodePtr newListNode = new LinkedListNode();
		newListNode->nodePtr = node;

		if (!m_pHead || !m_pTail) {
			m_pHead = m_pTail = newListNode;
			return;
		}

		if (m_bOrdered) {
			LinkedListNodePtr curr = m_pHead;
			LinkedListNodePtr prev = nullptr;
			for (; curr != nullptr; curr = curr->next) {
				if (curr->nodePtr->getFhat() > node->getFhat()) {
					break;
				}
				prev = curr;
			}

			newListNode->next = curr;
			prev->next = newListNode;
			if (!curr) {
				m_pTail = prev;
			}
		}
		else {
			//newListNode->next = nullptr;
			//m_pTail->next = newListNode;
			//m_pTail = newListNode;

			// 리스트의 헤드에서부터 밀어 넣음
			newListNode->next = m_pHead;
			m_pHead = newListNode;
		}




		//LinkedListNodePtr &curr = m_pHead;
		//if (m_bOrdered) {
		//	for (; curr != nullptr; curr = curr->next) {
		//		if (curr->nodePtr->getFhat() > node->getFhat()) {
		//			break;
		//		}
		//	}
		//}

		//LinkedListNodePtr newListNode = new LinkedListNode;
		//newListNode->nodePtr = node;

		//if (curr) {
		//	newListNode->next = curr;
		//}
		//else {
		//	m_pTail = newListNode;
		//}
		//curr = newListNode;
	}

	NodePtr LinkedList::removeFirst()
	{
		m_nSize--;

		NodePtr dst = m_pHead->nodePtr;
		LinkedListNodePtr next = m_pHead->next;
		delete m_pHead;
		m_pHead = next;
		return dst;
	}

	NodePtr LinkedList::getLast()
	{
		return m_pTail->nodePtr;
	}
}
