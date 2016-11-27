#include "pch.h"
#include "State.h"

namespace SlidingPuzzleSpace
{
	State::State(TileBlockRepoPtr repo, TileID* idArr = nullptr)
		: m_pBlockRepo(repo)
	{
		int size = getSize();
		m_BlockArr = new TileBlockPtr[size];
		m_Blocks = new TileBlockPtr*[size];

		for (int i = 0; i < getHeight(); i++) {
			m_Blocks[i] = &m_BlockArr[i * getWidth()];
		}

		if (idArr) {
			for (int i = 0; i < getSize(); i++) {
				m_BlockArr[i] = (*m_pBlockRepo)[idArr[i]];
			}
		}
		else {
			for (int i = 0; i < size; i++) {
				m_BlockArr[i] = (*m_pBlockRepo)[i];
			}
		}
	}

	State::~State()
	{
		if (m_Blocks) {
			delete[] m_Blocks;
		}
		if (m_BlockArr) {
			delete[] m_BlockArr;
		}
	}
}
