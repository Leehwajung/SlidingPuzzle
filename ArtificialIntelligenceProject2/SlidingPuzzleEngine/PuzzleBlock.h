#pragma once

namespace SlidingPuzzleSpace
{
	class PuzzleBlock sealed
	{
	public :
		/* Constructor */
		// Constructor
		PuzzleBlock();

		/* Accessor */
		// 퍼즐 블록 번호
		int getID();

	private:
		/* Attribute */
		int m_ID;	// 퍼즐 블록 번호

		/* Support */
		static int m_NextID;	// 퍼즐 블록 번호를 부여하기 위한 인자
	};

	inline int PuzzleBlock::getID()
	{
		return m_ID;
	}

	typedef PuzzleBlock* PuzzleBlockPtr;
}
