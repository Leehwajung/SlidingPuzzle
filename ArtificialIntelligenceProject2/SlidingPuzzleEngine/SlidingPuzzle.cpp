#include "pch.h"
#include "SlidingPuzzle.h"

namespace SlidingPuzzleSpace
{
	SlidingPuzzle::SlidingPuzzle(int height, int width)
	{
		m_BlockRepo = new TileBlockRepo(height, width);

		m_CurrState = new State(*m_BlockRepo);
		m_Goal = new State(*m_BlockRepo);
	}

	SlidingPuzzle::~SlidingPuzzle()
	{
		deleteStates();
		deleteGoal();
		if (m_BlockRepo) {
			delete m_BlockRepo;
		}
	}

	bool SlidingPuzzle::moveBlock(Direction movingTargetPos)
	{
		m_CurrState = new State(*m_CurrState, movingTargetPos);
		if (m_CurrState->equalsPred()) {
			StatePtr deleteDst = m_CurrState;
			m_CurrState = m_CurrState->getPred();
			delete deleteDst;
			return false;
		}
		return true;
	}

	void SlidingPuzzle::deleteStates()
	{
		for (StatePtr pred = m_CurrState, curr = nullptr; pred;) {
			curr = pred;
			pred = curr->getPred();
			delete curr;
		}
	}
}
