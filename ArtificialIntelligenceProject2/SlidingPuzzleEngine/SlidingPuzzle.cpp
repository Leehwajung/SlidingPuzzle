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
		m_CurrNode = new Node(*m_CurrNode, movingTargetPos, *m_Goal);
		if (m_CurrNode->equalsPred()) {
			NodePtr deleteDst = m_CurrNode;
			m_CurrNode = (Node*) m_CurrNode->getPred();
			delete deleteDst;
			return false;
		}
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
