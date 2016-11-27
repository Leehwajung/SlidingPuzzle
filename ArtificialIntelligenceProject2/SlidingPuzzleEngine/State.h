#pragma once

#include "TileBlockRepo.h"

namespace SlidingPuzzleSpace
{
	typedef class State* StatePtr;

	class State
	{
	public:
		/* Constructor / Destructor */

		// Constructor
		// ���� ����: repo�� NOT null
		State(TileBlockRepoPtr repo, TileID* idArr /*= nullptr*/);

		// Destructor
		~State();


		/* Accessors */

		// ���� ����� ����
		int getSize();

		// ������ �ʺ�
		int getWidth();

		// ������ ����
		int getHeight();


	private:
		/* Attributes */
		TileBlockPtr **m_Blocks = nullptr;	// ���� �ִ� ��� 2���� �迭
		StatePtr m_pPred = nullptr;			// �θ� ���� ������


		/* Supports */
		TileBlockPtr *m_BlockArr = nullptr;			// ���� �ִ� ��� 1���� �迭
		TileBlockRepoPtr m_pBlockRepo = nullptr;	// ��ü ��ϵ��� ������� ������ �ִ� �����
	};


	inline int State::getSize()
	{
		return m_pBlockRepo->getSize();
	}

	inline int State::getWidth()
	{
		return m_pBlockRepo->getWidth();
	}

	inline int State::getHeight()
	{
		return m_pBlockRepo->getHeight();
	}
}


