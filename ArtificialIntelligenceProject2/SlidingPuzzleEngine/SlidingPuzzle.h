#pragma once

#include "PuzzleBlock.h"
#include "Direction.h"

namespace SlidingPuzzleSpace
{
	class SlidingPuzzle sealed
	{
		/* Constructor / Destructor */
	public:
		SlidingPuzzle(int height, int width);
		~SlidingPuzzle();

		/* Operations */
		void initPuzzle();
		void initPuzzle(int* idArr);
		void initGoal();
		void initGoal(int* idArr);
		void moveBlock(int x, int y, Direction dir);
		bool isSolved();

		/* Accessor */
		int getSize();

		/* Attributes */
	private:
		PuzzleBlock **m_Blocks = nullptr;	// 섞여 있는 블록 배열
		PuzzleBlock **m_Goal = nullptr;		// 목표 배열
		int m_Width;
		int m_Height;

		/* Support */
		PuzzleBlock *m_BlockRepo = nullptr;	// 전체 블록들을 순서대로 가지고 있는 저장소
	};
}
