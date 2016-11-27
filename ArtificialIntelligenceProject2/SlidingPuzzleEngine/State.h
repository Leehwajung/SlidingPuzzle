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
		// 사전 조건: repo는 NOT null
		State(TileBlockRepoPtr repo, TileID* idArr /*= nullptr*/);

		// Destructor
		~State();


		/* Accessors */

		// 퍼즐 블록의 개수
		int getSize();

		// 퍼즐의 너비
		int getWidth();

		// 퍼즐의 높이
		int getHeight();


	private:
		/* Attributes */
		TileBlockPtr **m_Blocks = nullptr;	// 섞여 있는 블록 2차원 배열
		StatePtr m_pPred = nullptr;			// 부모에 대한 포인터


		/* Supports */
		TileBlockPtr *m_BlockArr = nullptr;			// 섞여 있는 블록 1차원 배열
		TileBlockRepoPtr m_pBlockRepo = nullptr;	// 전체 블록들을 순서대로 가지고 있는 저장소
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


