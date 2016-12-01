#include "pch.h"
#include "SlidingPuzzle.h"

namespace SlidingPuzzleSpace
{
	SlidingPuzzle::SlidingPuzzle(int height, int width)
	{
		m_BlockRepo = new TileBlockRepo(height, width);

		m_Goal = new State(*m_BlockRepo);
		m_CurrNode = new Node(*m_BlockRepo, *m_Goal);
	}

	SlidingPuzzle::~SlidingPuzzle()
	{
		deleteNodes();
		deleteGoal();
		if (m_BlockRepo) {
			delete m_BlockRepo;
		}
	}

	bool SlidingPuzzle::moveBlock(Direction movingTargetPos)
	{
		NodePtr newNode = new Node(*m_CurrNode, movingTargetPos, *m_Goal);
		if (newNode->equalsPred()) {
			delete newNode;
			return false;
		}
		m_CurrNode = newNode;
		return true;
	}

	bool SlidingPuzzle::moveBlock(NodePtr movedNode)
	{
		if (!movedNode) {
			return false;
		}
		//if (m_CurrNode != movedNode->getPred()) {
		//	return false;
		//}
		if (movedNode->equalsPred()) {
			return false;
		}
		m_CurrNode = movedNode;
		return true;
	}

	void SlidingPuzzle::deleteNodes()
	{
		for (NodePtr pred = m_CurrNode, curr = nullptr; pred;) {
			curr = pred;
			pred = (Node*) curr->getPred();
			delete curr;
		}
	}
}
