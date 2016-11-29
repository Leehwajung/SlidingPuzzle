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
		LinkedListNodePtr &curr = m_pHead;
		if (m_bOrdered) {
			for (; curr != nullptr; curr = curr->next) {
				if (curr->nodePtr->getFhat() > node->getFhat()) {
					break;
				}
			}
		}

		LinkedListNodePtr newListNode = new LinkedListNode;
		newListNode->nodePtr = node;

		if (curr) {
			newListNode->next = curr;
		}
		else {
			m_pTail = newListNode;
		}
		curr = newListNode;
	}

	NodePtr LinkedList::removeFirst()
	{
		NodePtr dst = m_pHead->nodePtr;
		LinkedListNodePtr next = m_pHead->next;
		delete m_pHead;
		m_pHead = next;
		return dst;
	}
}
