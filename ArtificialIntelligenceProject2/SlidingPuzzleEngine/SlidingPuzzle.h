#pragma once
namespace {
#include "SlidingPuzzleEngine.h"
#include "PuzzleBlock.h"
}

#include "Direction.h"

namespace SlidingPuzzleSpace {
	class SlidingPuzzle sealed
	{
		/* Constructor / Destructor */
	public:
		SLIDINGPUZZLE_API SlidingPuzzle(int height, int width);
		SLIDINGPUZZLE_API ~SlidingPuzzle();

		/* Operations */
		SLIDINGPUZZLE_API void initPuzzle();
		SLIDINGPUZZLE_API void initPuzzle(int* idArr);
		SLIDINGPUZZLE_API void initGoal();
		SLIDINGPUZZLE_API void initGoal(int* idArr);
		SLIDINGPUZZLE_API void moveBlock(int x, int y, Direction dir);
		SLIDINGPUZZLE_API bool isSolved();

		/* Accessor */
		SLIDINGPUZZLE_API int getSize();

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

